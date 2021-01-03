# Aula 5 - Protocolo HTTP.

## Conteúdo

Repositorio da aula em: https://github.com/the-harry/trabalho_restful

## Conceitos basicos

### RECURSOS

Quando acessamos um link, buscamos por um recurso. Esse recurso pode ser uma pagina web, uma musica, ou qualquer outro tipo de arquivo ou dado. Cada recurso eh identificado por um URI(Uniform Resource Identifier), a URL que conhecemos, eh um tipo de URI.
Quando trabalhamos com APIs temos sempre essa ideia de lidar com recursos, no nosso exemplo, os recursos serao trabalhos, mas poderiam ser qualquer coisa.

[Mais informacoes sobre a estrutura de um recurso aqui](https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Identifying_resources_on_the_Web)

### ENDPOINTS

Um endpoint eh o estagio final de uma URL, o caminho dentro do host aonde o recuso esta localizado. Exemplo:

`http://foobar:4242/path/to/resource/1`

Nesse caso mostrado acima temos o protocolo `http`, o host `foobar`, na porta `4242`, e o endpoint eh `/path/to/resource`, enquanto `1` eh o identificador desse recurso.

Quando falamos de REST, queremos que nossos endpoints sejam semanticos,

### Versionamento de API

Uma boa pratica quando construimos APIs REST eh versionar nossa api, isolando os recursos dentro de namespaces especificos. O link acima poderia ser reescrito assim:

`http://foobar:4242/api/v1/path/to/resource/1`

Dessa maneira quando atualizarmos nossa API nao quebramos a compatibilidade com todos os servicos integrados nela, ja que podemos manter a v1 e v2 funcionando em paralelo por um tempo ate que todos migrem para a nova versao e a antiga seja descontinuada.

### Formatos de dados

Os dois principais formatos usados em APIs sao [JSON](https://www.json.org/json-en.html) e [XML](https://www.w3.org/XML/), o XML eh o mais antigo, ele trabalha com tags e eh mais dificil de trabalhar, o JSON eh o formato mais recente e facil de mexer que tem sido mais utilizado no lugar do XML, sempre de preferencia a usar JSON se possivel.

O XML trabalha com a ideia de tags que sao definidas pelo usuario:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<root>
   <element>
      <nome>Chafundifórnio</nome>
      <amigo_de>Espiriquidiberto</amigo_de>
   </element>
</root>
```

Enquanto o JSON trabalha com objetos de javascript:

```json
[
  {
    "nome": "Chafundifórnio",
    "amigo_de": "Espiriquidiberto"
  }
]
```

~~falai, bem mais bonito, ne? ;)~~

### VERBOS

Quando queremos exercer alguma acao sobre um recurso usamos verbos para indicar do que se trata essa acao. Abaixo estao os principais verbos:

* GET - Verbo usado para requisitar um recurso

* POST - Verbo usado para enviar/criar um recurso

* DELETE - Verbo usado para apagar um recurso

* PATCH - Verbo usado para editar apenas um atributo de um recurso

* PUT - Verbo usado para editar apenas um recurso inteiro

Sempre que for editar de preferencia ao PATCH por ser mais seguro que o PUT, ja que o ele atualiza todos atributos de um recurso ele pode acabar editando coisas que nao deveriam.

Tambem temos outros metodos menos conhecidos, a secao 4.3 da rfc7231 mostra todos os verbos com mais detalhes caso queira [dar uma olhada](https://tools.ietf.org/html/rfc7231#section-4.3).

### REQUEST

Um request eh uma solicitacao a um recurso, ela eh feita usando um verbo e um endpoint. Ela pode ou nao ter parametros adicionais, esses parametros vao no `body` da requisição, e tambem temos os `headers` que como o nome diz sao cabecalios com algumas informacoes sobre esse request, como por exemplo o formato que deve ser enviado(json/xml).


### CODIGOS HTTP

Quando fazemos uma requsicao, o protocolo nos responde com um codigo informando o que esta acontecendo. Esses codigos vao de 1xx ate 5xx.
Cada centena representa uma familia de codigos:

* 1XX - Informativo

Os codigos da familia 100 sao pouco notados e conhecidos ja que eles sao codigos que ocorrem "por debaixo dos panos".
Alguns exemplos sao os codigos:

- 100: Continuar

- 101: Mudando protocolo

* 2XX - Sucesso

A familia do 200 representa alguns tipos de sucesso, por exemplo.

- 200: Ok (Ao acessar uma pagina qualquer por exemplo temos esse status)

- 201: Created (Ao criar um recurso novo, por exemplo enviar um trabalho :))

* 3XX - Redirecionamento

Assim como a familia do 100, os codigos da familia 300 tambem nao sao muito vistos, ja que sao codigos intermediarios, muitas vezes acontecem alguns redirecionamentos ate o request acabar, ou ate mesmo um recurso nao estar mais disponivel.
Alguns exemplos sao:

- 301: moved

- 302: found

* 4XX - Erros do cliente

Essa deve ser a familia mais conhecida dos codigos HTTP, ela indica erro do cliente, por exemplo quando voce acessa uma pagina que nao existe e recebe um 404.
Alguns exemplos dessa familia sao:

- 401: not authorized (quando alguem nao esta autenticado para fazer alguma acao)

- 404: not found (quando o recurso nao eh encontrado)

- 422: unprocessable entitie (quando uma entidade nao eh processavel geralmente os argumentos enviados nao sao validos.)

* 5XX - Erros do servidor

Esses sao os erros que acontecem no backend, eles podem representar um erro interno do servidor ou algo externo a aplicacao:

- 500: internal_server_error (Erro interno generico)

- 502: bad_gateway (quando um servidor de origem enviou uma resposta inválida para outro servidor)

- 503: service_unavailable (quando o servidor não está pronto para lidar com a requisição)

A lista com todos os codigos se encontram no capitulo 6 da [rfc7231](https://tools.ietf.org/html/rfc7231#section-6)

### AUTH

Algumas API sao publicas e nao precisamos nos autenticar, porem em APIs privadas precisamos nos autenticar para fazer as requisicoes. Quando falamos de autenticacao temos diversas maneiras de fazer isso, entre elas:

- HTTP BASIC AUTH

- JWT

- SECRET KEY

- Oauth

- Oauth2

- CAS

Temos outros padroes mais e menos robustos, porem esses sao os mais conhecidos. Sempre leia a documentacao da API que voce deseja usar para entender como se autenticar nela.

Caso queria entender um pouco mais sobre os tipos de autenticacao confira esse [link aqui](http://restcookbook.com/Basics/loggingin/).

### RATE LIMIT

Algumas APIs implementam o que eh chamado de rate limit, isso que alguem envie muitas requisicoes para voce em um curto espaco de tempo, isso pode acontecer por varios motivos, entre eles erro de algum programador enquanto testa a API, ou um atacante querendo derrubar o site. Ja que cada request gasta um pouco de banda do seu servidor e bem, quando ela acabar seu site simplesmente vai parar de atender todos requests. `¯\_(ツ)_/¯`

Quando uma API implementar rate limit voce provavelmente rebera um header informando um numero de requests ainda disponiveis, geralmente esse limite eh dado por minuto, ou seja, se voce fez um request e recebeu o header `RateLimit: 9`, na janela de 1min voce ainda pode fazer 9 requests. Mas essa janela de tempo pode variar dependendo como foi a implementacao.

## Manipuplando trabalhos na API

- AUTENTICACAO:

  Nesse projeto usamos uma autenticacao simples usando um token repesentado por seu primeiro nome seguido de dois pontos e seu rm. Entao lembre-se de colocar esse header em todas as requisicoes.

  `Authorization: Token nome:rm`

- CRIAR TRABALHO:

  Primeiramente vamos criar um novo trabalho, aqui temos algumas opcoes de como enviar esse request, voce pode usar algum programa com interface grafica como o postman se se sentir mais a vontade. Porem aqui nos exemplos usaremos o Curl, ele eh conhecido por ser o canivete suico do protocolo HTTP.

  ```bash
  curl -H "Content-Type: application/json" \
       -H "Authorization: Token zezinho:666" \
       -d '{"trabalho":{"title":"NAC","url":"localhost"}}' \
       http://localhost/api/v1/trabalho -v
  ```

  Antes de prosseguirmos nossa explicacao vamos entender melhor o que esse comando esta fazendo, quando enviamos um request com o curl, sempre que virmos uma flag `-H` significa que estamos passando um header para essa requisição, isso tambem pode ser escrito da maneira mais longa `--header`. O primeiro header que passamos indica que nossa solicitacao sera do tipo JSON, para que a aplicacao saiba com o que esta lidando, o segundo, nos autenticamos com o `nome:rm`.

  A flag `-d` eh a forma curta para `--data`, quando passamos essa flag significa que estamos enviando dados em uma requisição, entao por padrao o curl ja muda o verbo do nosso request para um tipo POST.
  Quando nao passamos essa flag normalmente ele tenta fazer um GET por padrao, existe tambem a flag `-X` para mudar o verbo de um request, mas no caso do exemplo acima o `-d` ja infere que nosso request eh um POST e nao precisamos usar o modificado `-X VERBO`.

  E observem a sintaxe para o corpo do request, ele se inicia em aspas simples, com o json dentro usando aspas duplas para cada chave e valor.

  As barras invertidas `\` sao apenas para fazer a quebra de linha para o comando ficar mais legivel.

  E por fim temos nossa URI e a flag `-v`, que significa que queremos que esse comando seja verboso, sem isso nos executaremos o comando e podemos nao ter nenhum output, ja que o linux tende a mostrar apenas erros, esse modo verboso nos mostra detalhes importantes sobre o request feito e sua resposta e codigo HTTP.

  Se tudo deu certo, o comando acima vai te retornar o status `201` informando que um trabalho foi criado, e um corpo informando o id do trabalho:

  `{"trabalho_id":1}`


- ENTENDENDO OS ERROS:

    Caso voce faca algo errado a API vai tentar te indicar isso, por exemplo se voce enviar um POST sem parametros:

    ```bash
    curl -H "Content-Type: application/json" \
         -H "Authorization: Token zezinho:666" \
         -d '{}' \
         http://localhost/api/v1/trabalho -v
    ```

    Nesse caso ele te retorna um codigo 422 com o seguinte corpo `{"error":"unprocessable_entity","message":"Missing params."}`.

- VER TRABALHOS ENVIADOS:

  Agora sim, entendemos como criar um projeto, vamos ver se conseguimos consulta-lo, nesse caso nao queremos mais usar o verbo POST, ja que nao estamos enviando, e sim buscando informacoes. Para isso podemos indicar no endpoint da aplicacao que queremos ver o trabalho X, em uma API restfull isso acaba virando um padrao de `recurso/:id`.

  ```bash
  curl -H "Content-Type: application/json" \
       -H "Authorization: Token zezinho:666" \
       http://localhost/api/v1/trabalho/1 -v
  ```

  Observem que utilizei o ID recebido quando criei o trabalho. Voce recebera um codigo 200 em caso de sucesso junto com as informacoes desse trabalho:

  `{"id":1,"title":"NAC","url":"localhost","aluno_id":1,"created_at":"2020-08-09T13:45:16.347Z","updated_at":"2020-08-09T13:45:16.347Z"}`

  Caso voce tente procurar um trabalho que nao existe a API vai te retornar um 404:

  ```bash
  curl -H "Content-Type: application/json" \
       -H "Authorization: Token zezinho:666" \
       http://localhost/api/v1/trabalho/42 -v
  ```

  `{"error":"not_found","message":"Registro nao encontrado."}`

  Outras duas coisas que podem acontecer eh receber um 401 ou 403. Mesmo eles sendo parecidos significam coisas diferentes, podemos dizer que o 401 tem mais a ver com autenticacao, enquanto o 403 com autorizacao, observem esses exemplos:

  ```bash
  curl -H "Content-Type: application/json" \
       http://localhost/api/v1/trabalho/1 -v
  ```

  Isso te retorna um 401 Unauthorized com a seguinte mensagem: `HTTP Token: Access denied.`, ou seja, voce nao esta autenticado.


  Porem imagine que a Luluzinha tente ver o trabalho do Zezinho, ela estaria autenticada, mas nao autorizada para ver esse recurso:

  ```bash
  curl -H "Content-Type: application/json" \
       -H "Authorization: Token luluzinha:999" \
       http://localhost/api/v1/trabalho/1 -v
  ```

  O que vai te retornar 403 Forbidden com o body: `{"message":"Nem pense nisso!"}`

- VER TODOS TRABALHOS:

  Como o rest implementa endpoints semanticos, quando queremos ver todos os trabalho usamos o endpoint `/api/v1/trabalhos`, que retornara todos os trabalhos, essa convencao de plural e singular indica se estamos lidando apenas com um recurso, ou uma colecao deles, entao sempre preste atencao nesses detalhes.

  Primeiro vamos criar outro trabalho, apenas para ver a diferenca em relacao ao mostrar apenas um resultado.

  ```bash
  curl -H "Content-Type: application/json" \
       -H "Authorization: Token zezinho:666" \
       -d '{"trabalho":{"title":"outra NAC","url":"localhost"}}' \
       http://localhost/api/v1/trabalho -v
  ```

  Agora podemos ver todos nosso trabalhos com o seguinte request:

  ```bash
  curl -H "Content-Type: application/json" \
       -H "Authorization: Token zezinho:666" \
       http://localhost/api/v1/trabalhos -v
  ```

  Isso vai te retornar um 200 OK e uma array com seus trabalhos:

  OBS: Ele nao vai vir bonito assim, mas voce pode copiar o json e [formata-lo](https://jsonformatter.curiousconcept.com) para ler melhor.

  ```json
  [
   {
      "id":1,
      "title":"NAC",
      "url":"localhost",
      "aluno_id":1,
      "created_at":"2020-08-09T13:45:16.347Z",
      "updated_at":"2020-08-09T13:45:16.347Z"
   },
   {
      "id":2,
      "title":"outra NAC",
      "url":"localhost",
      "aluno_id":1,
      "created_at":"2020-08-09T14:02:16.393Z",
      "updated_at":"2020-08-09T14:02:16.393Z"
   }
 ]
  ```

  Agora que vimos que temos dois trabalhos, vamos editar o primeiro para que seja o que vai de fato valer para a nota, e vamos apagar o outro.
  Mas antes de mais nada vamos falar sobre a diferenca entre os verbos disponiveis para editar um recurso, temos o PUT e o PATCH:

- EDITAR COM PUT:

  ```bash
  curl -X PUT \
       -H "Content-Type: application/json" \
       -H "Authorization: Token zezinho:666" \
       -d '{"title":"foobar"}' \
       http://localhost/api/v1/trabalho/2 -v
  ```

  Se formos ver ele atualizou corretamente o campo title, porem esse metodo eh menos recomendado, ja que ele nao eh tao seguro, observem a definicao no site do mozzila:

  [The HTTP PUT request method creates a new resource or replaces a representation of the target resource with the request payload.](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/PUT)

  Ou seja, ele atualiza o objeto completo, o que pode ser meio inseguro dependendo de como a API foi feita, pois voce pode acabar apagando algum campo, isso nao vai acontecer nessa API, fiquem tranquilos! ;)

- EDITAR COM PATCH

  Agora para editar parcialmente um recurso podemos usar o PATCH, sempre que possivel de preferencia a esse verbo, a nao ser que tenha um motivo para usar o PUT.

  Segundo a definicao no site do mozzila:

  [The HTTP PATCH request method applies partial modifications to a resource.](https://developer.mozilla.org/en-US/docs/Web/HTTP/Methods/PATCH)

  ```bash
  curl -X PATCH \
       -H "Content-Type: application/json" \
       -H "Authorization: Token zezinho:666" \
       -d '{"url":"github.com/foo/bar"}' \
       http://localhost/api/v1/trabalho/2 -v
  ```

  Agora podemos conferir nosso recurso e validar que as alteracoes feitas foram persistidas de fato:

  ```bash
  curl -H "Content-Type: application/json" \
       -H "Authorization: Token zezinho:666" \
       http://localhost/api/v1/trabalho/2 -v
  ```

  `{"id":2,"title":"foobar","url":"github.com/foo/bar","aluno_id":1,"created_at":"2020-08-09T14:02:16.393Z","updated_at":"2020-08-09T17:10:24.033Z"}`

- DELETE

  Finalmente, vamos destruir esse segundo registro usando o verbo DELETE:

  ```bash
  curl -X DELETE \
       -H "Content-Type: application/json" \
       -H "Authorization: Token zezinho:666" \
       http://localhost/api/v1/trabalho/2 -v
  ```


### Entrega da atividade

* [ ] Atualize o primeiro recurso com o titulo do trabalho (ex: NAC X) e a url do github onde seu projeto se encontra.


### Referências e recursos úteis

Temos algumas RFCs para especificacoes do protocolo HTTP, porem a 7231 define a semantica do protocolo. Vale a pena dar uma olhada caso queira mais detalhes.

[RFC 2616 - original](https://tools.ietf.org/html/rfc2616)

[RFC 7231 - atualiza a 2616](https://tools.ietf.org/html/rfc7231)

[Curl cheat sheet](https://devhints.io/curl)

[Rest Cookbook](http://restcookbook.com)

[Explicacao da mozilla sobre recursos](https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/Identifying_resources_on_the_Web)

[JSON](https://www.json.org/json-en.html)

[XML](https://www.w3.org/XML/)
