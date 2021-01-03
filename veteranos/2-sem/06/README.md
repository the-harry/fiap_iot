# Aula 6 - Criando uma API.

## Conteúdo

Nessa aula criaremos uma simples API usando python com a lib Flask.

Nosso objetivo eh criar um endpoint que receba metricas do nosso projeto do petfeeder. Temos alguns frameworks para fazer isso em python, mas os principais sao o Flask e o Django, porem o Flask eh mais usado para sites e API's menores, enquanto com o Django podemos fazer coisas mais robustas. Entao no nosso caso vamos de Flask, focando apenas na parte de API.

Primeiro vamos instalar o Flask em nossa maquina:

```bash
pip3 install flask
```

Crie um arquivo chamado `api`, sem extencao.

Podemos fazer um hello world assim:

```python
# adicionamos o interpretador para usar o python
#!/usr/bin/env python3

# importamos a lib que acabamos de instalar
from flask import Flask

# cria um objeto da API
api = Flask(__name__)

# define uma rota /
@api.route('/')
# define a acao index para essa rota
def index():
    return "Hello World!"

# se o arquivo for executado ele inicia a api
if __name__ == '__main__':
  # a opcao debug mostra mais detalhes mas nao deve ser usado em producao
    api.run(debug=True)
```

Vamos iniciar nossa API rodando o comando:

```bash
./api
```

Voce deve ver um log parecido com esse:

```bash
* Serving Flask app "api" (lazy loading)
* Environment: production
  WARNING: This is a development server. Do not use it in a production deployment.
  Use a production WSGI server instead.
* Debug mode: on
* Running on http://127.0.0.1:3000/ (Press CTRL+C to quit)
* Restarting with stat
* Debugger is active!
* Debugger PIN: 299-267-956
```

Podemos chamar nossa API usando o curl, por padrao ele roda na porta 5000:

```bash
curl http://127.0.0.1:5000
```

Podemos evoluir um pouco esse exemplo, vamos deixar essa rota do hello world para ser um keep alive da nossa API, e vamos criar um endpoint que receba um post com as metricas. Tambem vamos mudar a porta para a 3000:

```python
#!/usr/bin/env python3

# importamos o request tambem para poder pegar os parametros que estao chegando
from flask import Flask, request
# e importamos o logging tambem
import logging

api = Flask(__name__)

@api.route('/', methods=['GET'])
def index():
  # essa rota apenas responde que a api esta ok
    return 'API is up!'

# dentro do nosso escopo versionado vamos criar uma rota  que receba um post
@api.route('/api/v1/metric', methods=['POST'])
def create():
    # salva os parametros enviados no request ja em formato json(pre-parseado)
    data = request.get_json()
    # logamos oque recebemos
    logging.warning("Recebi o nome %s" % data['name'])

    #respondemos o request com o nome enviado e retornamos o status 201
    return data['name'], 201

if __name__ == '__main__':
    # mudamos a porta padrao para 3000
    api.run(debug=True, port=3000)
```

Salve e reinicie a aplicacao.

Podemos chamar nossa api da seguinte maneira:

```bash
curl -H "Content-Type: application/json" \                                                                        
     -d '{"name": "foobar"}' \                                                                                         
     http://127.0.0.1:3000/api/v1/metric -v
```

Agora vamos adaptar essa API para receber nossas metricas do petfeeder, temos que receber a metrica de presenca e logar ela junto com um timestamp. Depois vamos salvar isso em um banco, mas vamos deixar essa parte redondinha ja! ;)

```python
#!/usr/bin/env python3

from flask import Flask, request
import logging
# importa a lib de tempo
import time

api = Flask(__name__)

@api.route('/', methods=['GET'])
def index():
    return 'API is up!'

@api.route('/api/v1/metric', methods=['POST'])
def create():
    data = request.get_json()
    # pega o timestamp atual
    timestamp = time.strftime("%x %X", time.gmtime())

    # reduzimos o nivel do log para info e adicionamos o timestamp
    logging.info("%s %s" % (data['presence'], timestamp))

    # retornamos uma mensagem de sucesso generica
    return 'Metric created', 201

if __name__ == '__main__':
    api.run(debug=True, port=3000)
```

Salve e reinicie a aplicacao, agora podemos chamar nossa API:

```bash
curl -H "Content-Type: application/json" \
     -d '{"presence": "true"}' \
     http://127.0.0.1:3000/api/v1/metric -v
```

## Desafio

Criar API para receber as metricas do [smartgarden](https://github.com/the-harry/smart_garden).


### Referências e recursos úteis

[Doc Flask API](https://flask.palletsprojects.com/en/1.1.x/api/)

[Usando Logs](https://docs.python.org/pt-br/dev/howto/logging.html)

[Python time](https://docs.python.org/3/library/time.html)
