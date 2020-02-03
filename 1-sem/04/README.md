# Aula 4 - Arduino getting started.


## Estrutura básica do sketch arduino
Um sketch é um arquivo do arduino com a extenção `.ino`, ele pode conter código
de `C` e `C++`. Esse código deve ficar dentro de uma pasta com o mesmo nome.
Para fazer um programa para o arduino precisamos obrigatoriamente de duas funções:

setup e loop.

Estrutura básica:

```
void setup() {
  // aqui fica a configuração inicial, configurações gerais, etc
}

void loop() {
  // aqui fica a lógica principal do seu programa que será executado em loops,
  // ao iniciar o código, ele passa uma vez pelo setup e faz a configuração inicial,
  // depois disso ele fica nesse loop até que seja desligado.
}
```

## Variáveis e tipos no C
Uma variável é basicamente uma caixa onde você pode guardar informações temporariamente, ao finalizar a execução do código as informações são perdidas. Para atribuir um valor a uma variavel é só escolher um nome(de preferência que faça sentido no contexto, vai te ajudar a longo prazo) e atribuir um valor que seja do tipo correto.

O `C` segue estilo de linguagem de programação tipada, o que significa que ao declarar uma variável ou função temos que falar de qual tipo ela é, pode ser um número inteiro ou real, uma string(texto), boleano(verdadeiro ou falso) entre outros.
Por exemplo, para declarar a variável idade nós fazemos: `int idade = 27;` Ou seja, no exemplo anterior como a idade é um número inteiro não podemos simplesmente atribuir uma string `ìdade = 'vinte e sete';` isso causaria um erro, pois você tentou colocar uma string em uma variável que aceita apenas inteiros. Mas para permitir uma manipulação dos dados existem métodos para fazer uma conversão de tipos.

Sem contar variáveis tradicionais como as citadas anteriormente, também temos constantes, que podem ser definidas de duas maneiras, podemos declará-la usando `const` ou `define`. O const é uma váriavel normal que não pode ser alterada:
`const int idade = 27;`

Já o define ele feito geralmente no topo do arquivo, e ele é parseado pelo preprocessador antes de ser compilado, e ele troca o nome da definição pelo código em si. O que acaba sendo um pouco mais performático, mas não oferece tantos ganhos assim.

```
define IDADE 27

Serial.println(IDADE)
```

Esse código antes de ser compilado ele troca todas as ocorrências de IDADE por 27, que se torna:

```
define IDADE 27

Serial.println(27)
```


## Funções especiais do arduino
O arduino usa algumas funções especiais que não são usadas em C ou C++ puros,
essas funções são para coisas específicas do arduino, algumas bem comuns que podemos citar são:

* `pinMode` - configura um pino do arduino como input ou output
* `digitalWrite` - envia um sinal para um pino
* `delay` - faz o programa parar por alguns microsegundos
* `analogRead` - lê o valor de um pino analôgico
* `digitalRead` - lê o valor de um pino digital
* `Serial.println` - imprime algum valor na porta serial

Caso queira ver mais métodos disponíveis dê uma olhada [aqui](https://www.arduino.cc/reference/pt/#functions).

# Desafio

### User history

ALGO comm leds

### Tasklist

* [ ]
