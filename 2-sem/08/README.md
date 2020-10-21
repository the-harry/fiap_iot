# Aula 8 - Time series databases, Introdução ao InfluxDB.

## Conteúdo

## Introdução

Existem vários tipos de bancos de dados, temos bancos de dados relacionais, que tem tabelas com relacionamentos, temos bancos não relacionais, que são bancos para documentos ou coisas sem uma estrutura muito bem definida, entre outros. Mas um tipo muito interessante são os bancos de dados temporais(Time series databases). Como o nome já diz eles são bancos de dados que está relacionado ao tempo, oferecem a possibilidade de armazenar informações históricas a respeito de um determinado objeto que nele está sendo mantido.
Esse tipo de banco de dados é muito interessante para IOT, pois podemos armazenar todas as mudanças de estado de alguma coisa e depois manipular esses dados da maneira que quisermos, seja para montar tabelas, gráficos, ou apenas fazer queries.
Hoje vamos falar sobre o InfluxDB, porém existem outras alternativas, como o Graphite, TimescaleDB e o OpenTSDB.

Para escrever no InfluxDB usamos um protocolo chamado `Line Protocol`, que é um protocolo baseado em texto para escrever um ponto no influx. Quando falo um ponto e não um registro é porque em um banco temporal as coisas são chamas um pouco diferentes, abaixo tem um glossário explicando melhor esses termos:

* `Database` - O nome do banco mesmo, até aqui tudo normal.

* `Data Point`(ponto) - Um registro no banco, essa associação com ponto fica mais facil de lembrar se imaginar que um gráfico é formado por vários pontos

* `Field`(campo) - É apenas um campo onde um valor é armazenado para poder ser acessado posteriormente

* `Tag`(marcação) - Uma tag funciona quase como um campo, porém são campos que geralmente são usados em queries, eles funcionam QUASE como um index em um banco de dados relacional.

* `Measurements` - É uma estrutura de dados do InfluxDB baseado em string para representar dados armazenados em campos associados. Exemplo, podemos ter uma serie de medições de um sensor de movimento. Tambem podemos dizer que um measurement eh um valor de um data point.

* `Series` - É um agrupamento de medições pelo conjunto das tag_set(as tags presentes em um ponto) e field_set(as fields presentes em um ponto)

Esses são os principais que vocês devem saber. Mas caso queiram ver todos tem um link [aqui](https://docs.influxdata.com/influxdb/v1.7/concepts/glossary/).

Instale o influx na sua máquina ou suba um container. Nessa aula usaremos o docker-compose para nos ajudara a subir o container do influxdb, olhe o arquivo nessa pasta para mais detalhes.

## Console

Primeiro acesse o container: `docker-compose exec influxdb bash`

Para iniciar o console digite `influx`, para começar a primeira coisa vai ser criar um novo banco.

Para isso podemos usar o comando `CREATE DATABASE pet_feeder` onde teste é o nome do banco.

Para ver os bancos disponíveis usamos `SHOW DATABASES`

E para escolher o banco que vamos usar `USE pet_feeder`

Agora podemos começar a inserir data points no nosso banco. Como falamos anteriormente eles usam o line protocol para escrever no banco, esse protocolo segue a seguinte estrutura:

`<measurement>[,<tag-key>=<tag-value>...] <field-key>=<field-value>[,<field2-key>=<field2-value>...] [unix-nano-timestamp]`

Primeiro temos o nome da medição, seguido por uma virgula sem espaço vem as tags, sempre colocando a chave e o valor da tag. Depois temos um espaço o valor da medição(chave e valor) e por último um timestamp no formato unix-nano. Para inserir no banco colocamos o prefixo INSERT e o payload:

Um exemplo que consta nos docs:
`INSERT cpu,host=serverA,region=us_west value=0.64`

Trazendo mais para nosso contexto:

`INSERT pet,name=miau presence=false`

Podemos ver nosso registro de algumas formas:

`SELECT "host", "region", "value" FROM "cpu"`

E

`SELECT "name", "presence" FROM "pet"`

Tambem podemos ver nossas medicoes:

`SHOW MEASUREMENTS`

Ou as series persistidas:

`SHOW SERIES`

## API HTTP

Também podemos usar o curl para fazer requisições HTTP para a API do influx, um detalhe importante, observe que voce vai conseguir fazer as requisições da sua maquina apenas porque no docker-compose mapeamos a porta 8086 do container para a porta 8086 do host, caso isso nao tivesse feito voce ainda poderia se comunicar com esse container mandando as requisições de dentro de outro container, por exemplo o `api`, ja que entre os containers as portas sao acessiveis.
Tendo isso em mente vamos rodar os comandos na nossa maquina mesmo, podemos replicar o select feito acima da seguinte maneira:

`curl -G 'http://localhost:8086/query?pretty=true' --data-urlencode "db=pet_feeder" --data-urlencode "q=SELECT presence FROM pet"`

Isso acaba facilitando bastante a manipulacao de dados, ja que nao precisamos fazer tudo diretamente do terminal e tambem permite que esse banco seja usado com qualquer linguagem.

## Outros clientes

Lembrando que o influxdb possui libs para várias linguagem, o que facilita a insersão de datapoints no dia-a-dia dentro de nossas aplicações, mas caso não queira usar a lib a API é uma alternativa. Mas geralmente sempre eh uma opcao melhor usar a lib da sua linguagem, caso queiram ver as linguagens com libs disponíveis de uma olhada nesse link:

https://docs.influxdata.com/influxdb/v1.8/tools/api_client_libraries/

## Integrando na nossa API

Agora que subimos nosso container com o influxdb, criamos nosso banco e brincamos um pouco com ele, vamos fazer de fato a integracao de nossa API. Ate agora estavamos apenas logando as metricas que chegavam, vamos comecar a inserir elas no influx para que possamos utiliza-las depois no grafana.
Primeira coisa, vamos instalar a lib do influxdb para python:

```
pip3 install influxdb
pip3 install --upgrade influxdb
```

No caso eu rodei esse comando na minha maquina e fiz um arquivo de requirements.txt, entao a partir de agora vamos fazer a instalacao das dependencias por la no nosso Dockerfile e entao precisamos apenas dar um build.

Com isso podemos alterar nosso codigo adicionando a lib, criando um payload e escrevendo esse ponto:

```python
#!/usr/bin/env python3

from influxdb import InfluxDBClient
from flask import Flask, request
import logging
import datetime

logging.basicConfig(level=logging.INFO)

api = Flask(__name__)

@api.route('/api/v1/metric', methods=['POST'])
def create():
    incoming_data = request.get_json()
    presence = incoming_data['presence']
    logging.info(presence)

    payload = [
        {
            "measurement": "pet_feeder",
            "tags": {
                "name": "miau"
            },
            "time": datetime.datetime.utcnow().isoformat(),
            "fields": {
                "presence": int(presence)
            }
        }
    ]

    influx_client = InfluxDBClient('influxdb', 8086, database='pet_feeder')
    influx_client.write_points(payload)

    return 'Metric created', 201

if __name__ == '__main__':
    api.run(debug=True, host='0.0.0.0', port=3000)

```

Agora podemos chamar nossa API:

```bash
curl -H "Content-Type: application/json" \
    -d '{"presence": "1"}' \
    http://127.0.0.1/api/v1/metric -v
```

Faca isso algumas vezes para criar algumas metricas, para consultar elas podemos usar qualquer um dos metodos que vimos ate agora, mas como ja estamos no terminal podemos usar o curl:

Para ver todas as metricas podemos usar a seguinte query:

`curl -G 'http://localhost:8086/query?pretty=true' --data-urlencode "db=pet_feeder" --data-urlencode "q=SELECT * FROM pet_feeder"`

Para pegar apenas o primeiro podemos fazer um LIMIT:

`curl -G 'http://localhost:8086/query?pretty=true' --data-urlencode "db=pet_feeder" --data-urlencode "q=SELECT * FROM pet_feeder LIMIT 1"`

Agora o proximo passo vai ser mostrar esses dados em um dashboard no grafana!


## Referências e recursos úteis

[Clientes influxdb](https://docs.influxdata.com/influxdb/v1.8/tools/api_client_libraries/)

[Glossário](https://docs.influxdata.com/influxdb/v1.7/concepts/glossary)

[Docs oficiais](https://docs.influxdata.com/)

[Imagens do influx no docker hub](https://hub.docker.com/_/influxdb)
