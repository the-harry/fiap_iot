# Aula 1

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

## Funções
Uma função é uma maneira de juntar trechos de códigos que façam sentido juntos e
 dar um nome a isso. Imagine como uma função em matemática, que recebe uma entrada
e retorna algo na saida, porém em programação nem sempre essa função vai ter uma
entrada ou saida.
Primeiro vamos entender como saber o tipo da nossa função, uma função é declarada
falando o `tipo nomeDaFuncao() { ... }`, o tipo fala qual será o tipo do retorno dela,
os mais comuns são tipo int(inteiro), float ou double(real), entre outros.
Essa função também pode não ter retorno e ter o tipo `void`, onde ela só faz alguma coisa
dentro da função mas não retorna nenhum valor.
Para fazer o retorno de algum valor é usado a palavra `return`. Exemplo:

```
int calcular() {
  int a = 1;
  int b = 2;

  return a + b;
}
```

Para executar essa função basta chama-la no código usando `calcular();` e nos retornará o valor 3.

As funções também podem ter argumentos, que é basicamente receber um valor, imagine que
queremos usar o exemplo acima para calcular outros valores, podemos reber os valores de
`a` e `b` e calcular eles dentro da função:

```
int calcular(int a, int b) {
  return a + b;
}
```

Para executar essa função basta chama-la no código usando `calcular(4, 2);` e nos retornará o valor 2.

## Variáveis e tipos no C
Uma variável é basicamente uma caixa onde você pode guardar informações
temporariamente, ao finalizar a execução do código as informações são perdidas.
Para atribuir um valor a uma variavel é só escolher um nome(de preferência que
  faça sentido no contexto, vai te ajudar a longo prazo) e atribuir um valor,

O `C` segue estilo de linguagem de programação tipada, o que significa que ao
declarar uma variável ou função temos que falar de qual tipo ela é, pode ser um
número inteiro ou real, uma string(texto), entre outros.
Por exemplo, para declarar a variável idade nós fazemos: `int idade = 27;`

## Decisões lógicas (if else elseif)
Muitas vezes queremos tomar ações baseadas em decisões, para isso podemos usar o `if`,
por exemplo, imagine que temos a variável `idade` e queremos ver se a pessoa pode beber,
para isso podemos fazer algo assim:
```
if(idade > 17) {
  print('pode beber!');
} else {
  print('you shall not pass!');
}
```
- Importante: repare que não precisamos especificar o tipo da váriavel que estamos
 comparando, só colocamos o tipo em definições(para criar a variável ou função).

 Ou seja, ele verifica se a pessoa é maior de idade e fala se pode ou não beber.
 O `else` é um senão, caso a condição do if seja falsa ele irá executar o que estiver no else.
Também temos o `elseif`, onde podemos colocar mais condições no if:
```
if(idade < 18) {
  print('não pode beber!');
} elseif(idade > 18 && idade < 60) {
  print('Póbebe');
} else {
  print('Voce ja deveria ter parado de beber');
}
```
Nesse caso se for uma pessoa com mais de 60 anos cai no else. Observem também o
operador `&&` ele é equivalente ao `AND` lógico, onde a condição é verdadeira se
as duas partes forem verdadeiras. Em contra-ponto a esse operador temos o `||` que
representa o operador lógico `OR`, nele a condição é verdadeira quando uma das
condições forem verdadeiras.

Para fazer essas comparações lógicas você pode usar qualquer um [desses operadores](https://www.geeksforgeeks.org/operators-c-c/).

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

TODO ...
