# Aula 3 - Análise estrutural do sketch usando o blink.

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



### Tasklist

* [ ] 
