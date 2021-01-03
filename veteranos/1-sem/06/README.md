# Aula 6 - Controle de Repetição - Loops For e While.

## Conteúdo

Muitas vezes queremos que nosso código execute algumas ações repetitivas, porém sem precisar escrever o mesmo comando várias vezes seguidas. Para isso, temos à disposição controles de repetição, estando estes disponíveis em três opções: while, for e do while. Todos eles possuem a função de repetir as instruções desejadas até que uma condição seja atingida e, caso o loop não seja interrompido, acaba-se criando um loop infinito.
Vamos iniciar entendendo o loop for:

## For loops

Geralmente, utilizamos o for quando sabemos exatamente o número de ciclos que temos a realizar. Declaramos o loop for informando um contador que, ao acabar o loop, esse valor se perderá. Neste caso, uma condição para que esse loop se repita, até que ela seja verdadeira, precisa por último que incrementemos ou decrementemos o loop, utilizando os operadores `++` ou `--`.
Este loop possui a seguinte estrutura:

```cpp
for (inicialização; condição; incremento) {
  // bloco de código(s);
}
```

Exemplo:

```cpp
for(int i = 0; i < 10; i++) {
  Serial.print(i);
}

> 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
```

Podemos, por exemplo, controlar o brilho de um LED com PWM(utilizando o valor do loop):

```cpp
int PWMpin = 10;

void setup() {

}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(PWMpin, i);
    delay(10);
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(PWMpin, i);
    delay(10);
  }
}
```

Agora vamos calcular um algoritimo mais complicado para treinar um pouco.

## While loops

O while pode ser feito de duas maneiras e, similarmente ao loop for, executará uma ação até que a condição pare de ser verdadeira. Na primeira forma de usarmos o loop while, porém, utilizamos um contador externo que, sendo declarado antes de começar o loop, fará com que o valor não se perca após sua finalização, nos trazendo assim a diferença do loop for. A primeira maneira segue a seguinte estrutura:

```cpp
while (condicao) {
  // bloco de código
}
```

Segue um exemplo da implementação de contar os 10 primeiros números, começando do 0:

```cpp
int count = 0;

while(count < 10) {
  Serial.print(count);
  count++;
}

> 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
```

Acima replicamos o exemplo do for, porém usando o while. Caso você queira fazer uma contagem decrescente, podemos simplesmente fazer:

```cpp
int count = 9;

while(count > 0) {
  Serial.print(count);
  count--;
}
```

Repare que, desta vez, usamos o operador `--`, que seria a mesma coisa que escrever: `count = count -1;`.
Podemos também modificar o exemplo do PWM, para que possa funcionar com um loop while:

```cpp
int PWMpin = 10;

void setup() {

}

void loop() {
  int counter = 0;

  while (counter <= 255) {
    analogWrite(PWMpin, counter);
    counter++;
    delay(10);
  }

  while (counter >= 0) {
    analogWrite(PWMpin, counter);
    counter--;
    delay(10);
  }
}
```

## Do while loops

A segunda maneira de fazer loops while é usando o `do ... while` loop. O tipo de loop while que vimos anteriormente testa a condição no início da execução e, sendo assim, caso a primeira condição seja falsa, ele nunca conseguirá executar aquele bloco de códigos. Já no caso do do while, é possível checar a condição apenas no final do bloco. Logo, o código em questão será executado ao menos uma vez. Este tipo de loop tem a seguinte estrutura:

```cpp
do {
  // bloco de código
} while (condicao);
```

Podemos também reescrever abaixo o exemplo do LED, dessa vez usando essa estrutura:

```cpp
int PWMpin = 10;

void setup() {

}

void loop() {
  int counter = 0;

  do {
    analogWrite(PWMpin, counter);
    counter++;
    delay(10);
  } while (counter <= 255);

  do {
    analogWrite(PWMpin, counter);
    counter--;
    delay(10);
  } while (counter >= 0);
}
```

É importante lembrar que você somente deve utilizar esse tipo de loops, caso precise que o código seja executado ao menos uma vez, independente de ser atingida (ou não) a condição desejada.

## Loops infinitos

Um loop infinito é uma variação de loop que nunca conseguirá atingir a condição anteriormente estipulada. Sendo assim, apesar de ser comum geralmente evitarmos esse tipo de loop, ele também poderá ser criado caso haja algum motivo para tal. Vou listar abaixo algumas maneiras de fazer isso:

Usando o loop `for` apenas com `;`:

```cpp
for (;;) {
   // bloco de código;
}
```

Usando o `while`:

```cpp
while(1) {
   // bloco de código;
}
```

Usando `do...while`:

```cpp
do {
   bloco de código;
}
while(1);
```

De forma geral, serão muito raros os casos em que este tipo de loop precisará ser utilizado, mas, mesmo assim, é importante não nos esquecermos de que eles existem.


## Manipulação de loops

Dispomos também de recursos que nos permitem sair manualmente de um loop ou mesmo pular apenas uma de suas iterações, sendo esses recursos muito interessantes quando queremos interromper o código em uma condição especial, ou até mesmo pular uma das iterações do loop sem que seja preciso interromper as próximas.

* `break`: Já vimos esse comando no switch case, mas podemos também usá-lo de forma semelhante nos loops vistos hoje, conforme segue abaixo:

```cpp
for(int i = 0; i < 10; i++) {
  if(i == 7) {
    break;
  }
  Serial.print(i);
}

> 0, 1, 2, 3, 4, 5, 6
```

* `continue`: O continue simplesmente pulará a iteração:

```cpp
for(int i = 0; i < 10; i++) {
  if(i == 7) {
    continue;
  }
  Serial.print(i);
}

> 0, 1, 2, 3, 4, 5, 6, 8, 9
```

Observe que, com o break, o loop foi realmente interrompido, enquanto com o continue ele pulou apenas a iteração, mas continuou o loop até o final.


## Motores

Existem vários tipos de motores, sendo que os mais conhecidos são os motores de passo, servo e DC. No projeto petfeeder, usaremos um motor servo para abrir a porta e alimentar o pet. Mas, primeiramente, vamos entender melhor cada um dos tipos citados:

* `Motor DC`: sendo o motor mais conhecido, o motor DC é usado em diversas aplicações, como máquinas de lavar roupas e furadeiras. Eles possuem uma velocidade muito alta, porém não nos permitem controlar com exatidão a posição do motor.

* `Servo motor`: o servo motor tem a capacidade de ir para uma posição específica em relação às suas coordenadas.

* `Motor de passo`: apesar de podermos controlar sua posição, como no caso do servo motor, este possui mais precisão, além da maneira de usá-lo ser também um pouco diferente.

Por enquanto, vamos nos preocupar com o servo motor: usaremos em nosso projeto o motor sg90 e, para controlá-lo, deveremos indicar em qual posição ele deve ir. Porém, é importante ressaltar que devemos andar posição por posição, pois, caso contrário, ele poderá fazer um movimento muito brusco e danificar alguma coisa.


## Desafio

### User story

Essa semana seu time está começando outro projeto em paralelo. Essa solução tem como objetivo alimentar animais domésticos, que possuem donos que ficam muito tempo fora de casa, ou mesmo em casos em que precisem viajar. O responsável pelo hardware criou um protótipo para isso, sendo que a ideia é usar um motor servo para abrir e fechar uma porta para liberar comida.
Para que o motor seja ativado, será necessário o uso de um sensor de presença PIR.

### Tasklist

* [ ] Desenvolver uma solução para abrir e fechar o motor ao detectar movimento no sensor PIR. (considere a angulação máxima possível do motor como sendo 180°)


## Referências e recursos úteis

[for](https://www.arduino.cc/reference/en/language/structure/control-structure/for/)

[while](https://www.arduino.cc/reference/en/language/structure/control-structure/while/)

[do while](https://www.arduino.cc/reference/en/language/structure/control-structure/dowhile/)
