# Aula 11 - Usando o docker na infraestrutura.

## Conteúdo

Quando vamos montar a infraestrutura de um projeto muitas vezes é comum usar várias máquinas para rodar diferentes serviços, é consideirado uma boa prática não rodar tudo na mesma máquina. Para fazer isso podemos usar várias abordagens, podemos ter várias máquinas físicas, ou virtuais, porém essas abordagens podem custar caro, e não são tão flexiveis para criar um ambiente de desenvolvimento/teste ou até mesmo para produção. Hoje vamos falar um pouco sobre o docker e como usar nos nossos projetos.
O docker é uma tecnologia de containerização, com ele é possível usarmos imagens prontas ou criarmos a nossa imagem personalizada. Uma imagem nada mais é do que um sistema operacional com algumas instruções específicas para fazer algo, quando construirmos nossa imagem isso ficará mais claro. Primeiro [instale o docker](https://docs.docker.com/install/), e vamos testar se ele funciona rodando a imagem do hello-world:

`docker run hello-world`

O comando run fala para executar a imagem hello-world, quando uma imagem é executada ela vira um container. Imagine a imagem como uma receita de bolo, e o container como o bolo propriamente dito.
Agora vamos ver um exemplo diferente, vamos supor que eu queira subir um container para rodar uma aplicação em ruby, porém eu preciso criar um volume local para poder acessar os arquivos de dentro do container, e também preciso que a porta 80 na minha máquina escute a aplicação que dentro do container roda na porta 3000. Esse comando ficaria algo assim:

`docker run -it --rm -p80:3000 ruby:2.6 bash` ** CORRIGIR **

O problema é que quanto mais coisas adicionamos maior isso fica, mas tem algo que pode nos ajudar. O docker-compose, com ele podemos criar "receitas" para executar os containers, e depois podemos gerencia-los mais facilmente.
No arquivo `docker-compose.yml` nessa pasta temos um exemplo de como subir um container para uma site com um banco de dados.

Com o arquivo pronto só precisamos fazer um build:

`docker-compose build`

E depois subir o projeto:

`docker-compose up`

Da mesma forma caso queira para os serviços:

`docker-compose down`

Obs: Caso queira usar o docker dentro do rasp é possível, porém ele fica limitado a rodar apenas imagens feitas para a arquitetura ARM, caso alguma imagem não seja baseada em ARM você mesmo pode recriá-la usando ARM como base.


## Desafio

### User story

Você foi designado a criar a arquitetura do seu projeto em docker. Para isso Jane vai te passou uma lista de requesitos que precisam ser atendidos para esse projeto. Pegue o projeto que você tem até agora e suba-o no docker.


### Tasklist

* [ ] Criar Dockerfile para a aplicação.

* [ ] Criar docker-compose para a aplicação.

* [ ] Subir e testar o projeto.
