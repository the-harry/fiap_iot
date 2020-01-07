# Aula 10 - APIs e requests http.

## Conteúdo

Atualmente com essa onda de micro-serviços é impossivel não se falar de API's REST. Quando criamos uma comunicação por protocolo HTTP isso nos traz muitas vantagens, como por exemplo saber que todas nossas aplicações vão seguir um padrão para se comunicar, isso também facilita para ter um ambiente com muitas linguagens diferentes.
Quando falamos de requisições HTTP, tudo é baseado em algumas RFC's, como a [RFC7231](https://tools.ietf.org/html/rfc7231). Para definir o padrão de comunicação foi criado uma coisa chamada verbos, verbos nos dizem qual tipo de ação está sendo feita.
Você provavelmente já ouviu falar do GET ou POST, porém temos vários outros verbos também, mas os principais são:

* GET - Verbo usado para requisitar um recurso

* POST - Verbo usado para enviar um recurso

* DELETE - Verbo usado para apagar um recurso

* PUT - Verbo usado para editar vários atributos de um recurso de uma vez

* PATCH - Verbo usado para editar apenas um atributo de um recurso

Agora que entendemos os verbos temos que entender um pouco sobre endpoints, eles são caminhos na nossa aplicação e cada caminho tem um verbo associado a ele. Por exemplo, podemos pegar a posição atual do ISS(International Space Station) fazendo uma requisição GET para http://api.open-notify.org/iss-now.json.

Agora a parte importante, como fazer essas requisições? Caso seja uma requisição GET é só colocar no navegador o link que ele deve funcionar, porém quando usamos outros verbos isso não é possível. Podemos usar o Postman ou o Curl. Para que vocês se habituem melhor eu recomendo fortemente que usem o Curl.

Para fazer uma requisição GET com curl só precisamos fazer:

`curl http://api.open-notify.org/iss-now.json`

Caso queira fazer um POST ficaria algo assim:

`curl -d "name=fulado&senha=123" http://foo.bar/api/v1/user/new`

Cada requisição que você faz vai te retornar um [código http](https://developer.mozilla.org/pt-BR/docs/Web/HTTP/Status), esse código vai indicar sucesso ou falha, também é possível que venha um corpo na requisição com algum dado ou mensagem. Mas muitas requisições retornarão apenas um código.

## Desafio

### User history

Seu time está estudando a implementação de algumas API's e gostaria que você fizesse alguns testes com o curl mesmo para ver se essas API's atendem o que vocês precisam. Entre as necessidades temos um validador de CNPJ que deve consultar as informaçõoes dessa empresa, validações e consultas de CEP, e envio de SMS.

### Tasklist

* [ ] Testar a API de consultas a [CNPJ](https://receitaws.com.br/api)

* [ ] Testar a API de [CEP](https://viacep.com.br/)

* [ ] Testar a API de envio de SMS do [Twilio](https://www.twilio.com/)
