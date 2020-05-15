# Aula 12 - Time series databases, Introdução ao influx.

## Conteúdo

Existem vários tipos de bancos de dados, temos bancos de dados relacionais, que tem tabelas com relacionamentos, temos bancos não relacionais, que são bancos para documentos ou coisas sem uma estrutura muito bem definida, entre outros. Mas um tipo muito interessante são os bancos de dados temporais(Time series databases). Como o nome já diz eles são bancos de dados que está relacionado ao tempo, oferecem a possibilidade de armazenar informações históricas a respeito de um determinado objeto que nele está sendo mantido.
Esse tipo de banco de dados é muito interessante para IOT, pois podemos armazenar todas as mudanças de estado de alguma coisa e depois manipular esses dados da maneira que quisermos, seja para montar tabelas, gráficos, ou apenas fazer queries.
Hoje vamos falar sobre o InfluxDB, porém existem outras alternativas, como o Graphite, TimescaleDB e o OpenTSDB.

Para escrever no InfluxDB usamos um protocolo chamado `Line Protocol`, que é um protocolo baseado em texto para escrever um ponto no influx. Quando falo um ponto e não um registro é porque em um banco temporal as coisas são chamas um pouco diferentes, abaixo tem um glossário explicando melhor esses termos:

* `Database` - O nome do banco mesmo, até aqui tudo normal.

* `Data Point`(ponto) - Um registro no banco, essa associação com ponto fica mais facil de lembrar se imaginar que um gráfico é formado por vários pontos

* `Field`(campo) - É apenas um campo onde um valor é armazenado para poder ser acessado posteriormente

* `Tag`(marcação) - Uma tag funciona quase como um campo, porém são campos que geralmente são usados em queries, eles funcionam QUASE como um index em um banco de dados relacional.

* `Measurements` - É uma estrutura de dados do InfluxDB baseado em string para representar dados armazenados em campos associados. Exemplo, podemos ter uma serie de medições de um sensor de movimento.

* `Series` - É um agrupamento de medições pelo conjunto das tag_set(as tags presentes em um ponto) e field_set(as fields presentes em um ponto)

Esses são os principais que vocês devem saber. Mas caso queiram ver todos tem um link [aqui](https://docs.influxdata.com/influxdb/v1.7/concepts/glossary/).

Instale o influx na sua máquina ou suba um container. Para iniciar o console digite `influx`, para começar a primeira coisa vai ser criar um novo banco.

Para isso podemos usar o comando `CREATE DATABASE teste` onde teste é o nome do banco.

Para ver os bancos disponíveis usamos `SHOW DATABASES`

E para escolher o banco que vamos usar `USE teste`

Agora podemos começar a inserir data points no nosso banco. Como falamos anteriormente eles usam o line protocol para escrever no banco, esse protocolo segue a seguinte estrutura:

`<measurement>[,<tag-key>=<tag-value>...] <field-key>=<field-value>[,<field2-key>=<field2-value>...] [unix-nano-timestamp]`

Primeiro temos o nome da medição, seguido por uma virgula sem espaço vem as tags, sempre colocando a chave e o valor da tag. Depois temos um espaço o valor da medição(chave e valor) e por último um timestamp no formato unix-nano. Para inserir no banco colocamos o prefixo INSERT e o payload:

`INSERT cpu,host=serverA,region=us_west value=0.64`

Podemos ver nosso registro de algumas formas:

`SELECT "host", "region", "value" FROM "cpu"`

`SHOW MEASUREMENTS`

`SHOW SERIES`

Também podemos usar o curl para fazer requisições HTTP para a API do influx:

`curl -G 'http://localhost:8086/query?pretty=true' --data-urlencode "db=teste" --data-urlencode "q=SELECT \"host\" FROM \"region\", \"value\" FROM \"cpu\"`

Lembrando que o influxdb possui libs para várias linguagem, o que facilita a insersão de datapoints no dia-a-dia dentro de nossas aplicações, mas caso não queira usar a lib a API é uma alternativa.

## Desafio

### User story

Seu time deseja iniciar uma monitoração na aplicação que foi desenvolvida até agora, a ideia é primeiro criar um banco para armazenar essas informações, foi feito uma votação e o time decidiu usar o influx. Nessa etapa do projeto você deve criar um serviço do influx com docker-compose e deixar o ambiente pronto para as próximas etapas.

### Tasklist

* [ ] Criar docker

* [ ] Criar banco de dados `metrics`

* [ ] Fazer um insert de um datapoint

* [ ] Consultar o datapoint

Atenção: As duas últimas partes são essenciais para garantir que tudo funcione devidamente.
