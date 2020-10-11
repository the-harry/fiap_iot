# Aula 7 - Usando o docker no projeto.

## Conteúdo

## Introducao

Quando vamos montar a infraestrutura de um projeto muitas vezes é comum usar várias máquinas para rodar diferentes serviços, é consideirado uma boa prática não rodar tudo na mesma máquina. Para fazer isso podemos usar várias abordagens, podemos ter várias máquinas físicas, ou virtuais, porém essas abordagens podem custar caro, e não são tão flexiveis para criar um ambiente de desenvolvimento/teste ou até mesmo para produção. Hoje vamos falar um pouco sobre o docker e como usar nos nossos projetos.

O docker é uma tecnologia de containerização, com ele é possível usarmos imagens prontas ou criarmos a nossa imagem personalizada. Uma imagem nada mais é do que um sistema operacional com algumas instruções específicas para fazer algo, quando construirmos nossa imagem isso ficará mais claro.

O docker resolve tambem um grande problema que temos de configuracao de ambiente, que causa aquele velho problema de "na minha maquina roda...", o docker isola as dependencias de uma maquina de uma maneira que o projeto possa ser rodado em qualquer sistema, ou seja que ele se torne agnostico ao ambiente, o que eh super importante, ja que gastaremos menos tempo configurando as coisas e podemos nos focar em fazer a solucao propriamente dita.

Ele tambem se diferencia das maquinas virtuais tradicionais por aproveitar melhor alguns recursos da maquina host, por exemplo, em uma maquina virtual eh preciso subir todas as camadas que uma maquina precisaria para funcionar e um intermediario chamado hypervisor faz a comunicacao entre o host e a VM, enquanto com o docker ele usa o kernel da maquina host, o que faz ele ter que criar menos camadas para rodar nosso container, e nao precisamos desse intermediario, uma vez que eles podem se comunicar direto com o kernel do host.

![Containers VS VMs](../../img/2sem/07/container_vs_vm.jpg)

## Instalacao

Primeiro [instale o docker](https://docs.docker.com/install/), ele sera a base de tudo.

Apos instalar o docker, instale o [docker-compose](https://docs.docker.com/compose/install/), usaremos ele daqui a pouco tambem.


Antes de mais nada vamos rodando a imagem hello-world para ver se nossa instalacao funciona corretamente:

`docker run hello-world`

Se tudo estiver certo ele vai baixar essa imagem na sua maquina e aparecer uma mensagem com um texto: `Hello from Docker!`

O comando run fala para executar a imagem hello-world, como nao temos essa imagem localmente, o docker vai procura-la no [docker-hub](https://hub.docker.com/), que eh o repositorio das imagens do docker. Quando uma imagem é executada ela vira um container. Imagine a imagem como uma receita de bolo, e o container como o bolo propriamente dito.


## Conceitos do docker

Quando nos referimos a containers precisamos entender o que alguns termos significam para entender melhor o funcionamento dessa tecnologia:

* `Dockerfile` - Arquivo que cria uma imagem, essa imagem apos ser construida pode ser usada localmente ou ate se salva no docker-hub.

* `Imagem` - Se trata de um Dockerfile que foi construido, com uma imagem pronta podemos criar containers a partir dela, e as imagens geralmente tem uma tag, essa tag sempre eh representada apos o nome da imagem, por exemplo, se quisermos usar o python3.6 podemos usar a imagem python, passando a tag 3.6: `python:3.6`. Uma imagem nao precisa necessariamente ter sido construida na sua maquina, ao tentar usar uma imagem que nao temos localmente ele ira buscar no docker-hub.

 * `Containers` - Quando uma imagem eh instanciada ela se cria um container, que seria a nossa maquina de fato funcionando.

![Etapas](../../img/2sem/07/docker_cicle.png)


## Rodando nossa API

Nessa aula nosso objetivo eh dockerizar a nossa API feita na ultima aula, mas antes de comecar com exemplos mais avancados vamos primeiro rodar um container de python em nossa maquina, para isso podemos rodar o seguinte comando:

`docker run -it --rm python:3.7.3`

Apos baixar a imagem ele deve abrir um shell para voce. Nesse comando passamos duas flags a mais, o -it, que diz para rodar esse container de maneira iterativa, senao ele apenas executaria o comando e sairia sem deixar interagir com o console. E o --rm apaga esse container apos sua execucao. Eh bem comum ouvir a palavra `efêmero`, quando nos falamos de container, quando dizemos que os container sao efêmeros quer dizer que eles sao temporarios, podemos matar eles a qualquer hora e instanciar outro sem problemas, diferente de uma maquina, que nao podemos simplesmente jogar pela janela cada vez que rodar um programa.

No comando anterior caimos dentro de um shell do python, mas caso queira acessar o console do container, podemos passar mais um comando apos a imagem, esse comando sera executado ao abrir o container, no caso o proprio bash que eh o terminal:

`docker run -it --rm python:3.7.3 bash`

Agora que ja conseguimos subir um container simples, vamos criar uma imagem para usar na nossa aplicação, dessa forma ja teremos todas as coisas nescessarias dentro da nossa imagem.

## Criando nossa imagem

A primeira coisa eh criar um arquivo `Dockerfile`, (importante: A primeira letra deve ser maiuscula). E dentro dele vamos montar a receita para construir nossa imagem.
O Dockerfile usa comandos em letras maiusculas, veja o exemplo:


```dockerfile
# Dentro do Dockerfile todas as palavras chaves são em letras maiusculas

# Começamos com o FROM, para falar qual imagem usaremos de base para nossa imagem.

FROM python:3.7.3

# WORKDIR é a pasta em que sua aplicação vai rodar, ela eh a home da aplicação.

WORKDIR /api

# aqui copiamos os arquivos da nossa máquina para o container

COPY server server

# Quando queremos rodar algum comando usamos o RUN, aqui atualizamos o pip e
# instalamos os requesitos da aplicação

RUN pip3 install --upgrade pip && pip3 install flask
```

Agora podemos fazer um build da nossa imagem e dar uma tag para identificar ela com o comando:

`docker build . -t pet_feeder_api`

OU criando uma versao específica dessa tag:

`docker build . -t pet_feeder_api:1.0.0`

OBS: O ponto indica a pasta atual, poderia ser outro lugar.

Voce pode verificar se esta tudo funcionando acessando o container e tentando inicar o servico na mao(Isso tambem poderia ter sido feito usando o CMD, mas vamos rodar nosso comando no compose mais para frente, entao nao se preocupe muito com isso agora).

`docker run -it --rm pet_feeder_api bash`

Lembrando que se voce nao passar `:versao` ele vai pegar sempre a `latest`, a mais recente!

O arquivo copiado estara no container e devemos conseguir iniciar a api rodando:

`./server`

Porem ainda nao vamos conseguir usar a API, porque nao mapeamos nenhuma porta, entao o nosso container nao sabe que deve deixar passar trafego ali. Outro problema que vamos ter aqui, eh que para um ambiente de desenvolvimento onde vamos mexer nos arquivos e querer ver as diferencas teremos que fazer um build a cada mudanca, ja que o arquivo foi copiado uma vez so. Entao para ganhar mais facilidade nesse controle todo podemos usar o docker-compose!

## Orquestrando servicos com o docker-compose

Depois de instalar o docker-compose, vamos criar um arquivo chamado `docker-compose.yml`, nele falaremos como nossos containers devem subir, com quais argumentos, e todas as outras opcoes que tambem teriamos com o docker puro.

```yml
# primeiro falamos qual a versão do docker compose usado nesse arquivo
version: '3.7'

# nesse bloco colocamos todos os serviços que vamos subir
# lembrando que um servico roda apenas um comando e tem uma responsabilidade
services:
  # Primeiro dê um nome ao serviço, e começe a detlhar ele dentro do bloco
  # aqui criamos o container que rodará o banco de dados da aplicação
  api:
    # Escolha uma imagem pronta colocando o nome:versão, caso não coloque a
    # versão ele sempre pegará a última disponível
    # image: minha_imagem:1.2.3

    # Falamos para o docker buildar a imagem que criamos que se encontra
    # nessa pasta("." significa nesse diretório), ja que vamos usar a imagem que fizemos
    build: .
    # O restart always nem sempre é necessário, em caso de falha ele reinicia o
    # serviço, isso pode nos ajudar caso o banco ainda não esteja preparado para
    # ser acessado.
    restart: always
    # Um volume faz uma ponte entre uma pasta na sua máquina local e no container
    # nesse exemplo falo que a pasta em que estamos será mapeada para o diretório
    # /api dentro do container. Que eh nosso WORKDIR
    # Agora como colocamos essa parte aqui podemos tirar da imagem a parte de
    # copiar os arquivos.
    volumes:
      - .:/api
    # cada serviço deve ter apenas uma tarefa, o command é a tarefa que esse
    # container tem que fazer. No caso iniciar o servidor.
    command: ./server
    # A parte das portas é interessante, reparou que no outro serviço não tinha
    # esse bloco das portas? Aqui vai uma regra importante:
    # * Entre os containers todas as portas que são usadas são acessiveis.
    # * Porém para acessar de fora, seja seu localhost ou a internet, você
    # precisa fazer um mapeamento de porta, esse mapeamento sempre começa com a
    # porta da máquina local:container, no caso abaixo temos a porta 3000 do
    # container que está rodando o servidor do rails sendo mapeada para a porta
    # 80 do localhost(nossa máquina host).
    ports:
      - 80:3000
```

Ou seja, nossos arquivos sem comentarios ficam assim:

* `Dockerfile`:

```docker
FROM python:3.7.3

WORKDIR /api

RUN pip3 install --upgrade pip && pip3 install flask
```

* `docker-compose.yml`:

```yml
version: '3.7'

services:
  api:
    build: .
    restart: always
    volumes:
      - .:/api
    command: ./server
    ports:
      - 80:3000
```

Agora podemos buildar o container com:

`docker-compose build`

E subir a API com o comando:

`docker-compose up`

Da mesma forma caso queira parar os servicos use:

`docker-compose down`

Com a API rodando em um terminal abra outra janela e chame a API, mas dessa vez usando a porta 80, como mapeamos no compose:

```bash
curl -H "Content-Type: application/json" \
    -d '{"presence": "true"}' \
    http://127.0.0.1/api/v1/metric -v
```

## E o que mais?

Agora que entendemos o basico do docker, recomendo que estudem um pouco mais sobre seus comandos. Uma [cola bem bacana se encontra nesse link](https://www.docker.com/sites/default/files/d8/2019-09/docker-cheat-sheet.pdf).

Tentem dockerizar algum projeto que voce tenha feito recentemente, isso sempre ajuda a explorar e entender melhor a tecnologia.

E nao para por ai, tem mais coisas quando nos referimos a containers, temos tambem clusters com o swarm, o Kubernets tambem, que tem um papel importante na orquestacao de containers e muito mais!


## Referências e recursos úteis

[Docker install](https://docs.docker.com/get-docker/)

[docker-compose install](https://docs.docker.com/compose/install/)

[Docs](https://docs.docker.com/)

[Docker cheat sheet](https://www.docker.com/sites/default/files/d8/2019-09/docker-cheat-sheet.pdf)

[Imagem do docker](https://medium.com/platformer-blog/practical-guide-on-writing-a-dockerfile-for-your-application-89376f88b3b5)
