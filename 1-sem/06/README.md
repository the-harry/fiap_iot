# Aula 6 - Controle de repetição - Loops for e while.

## Conteúdo

Muitas vezes queremos que nosso código faça algumas ações repetitivas, e não faz muito sentido escrever a mesma coisa 10x seguidas. Para isso temos controles de repetições, temos três opções disponíveis, while, for e do while. Todos eles servem para repitir algumas instruções até que uma condição seja atingida, caso o loop não seja interrompido você acaba criando um loop infinito. Vamos começar entendendo o loop for:

## For loops

Geralmente usamos o for quando sabemos exatamente o numero de ciclos que temos que realizar, declaramos o loop for informando um contador que ao acabar o loop esse valor se perde, um a condição para que esse loop se repita ate que ela seja verdadeira, e por ultimo incrementamos ou decrementamos o loop usando os operadores `++` ou `--`. Ele tem a seguinte estrutura:

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

Podemos por exemplo controlar o brilho de um led com PWM usando o valor do loop:

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

O while, pode ser feito de duas maneiras, similarmente ao loop for, ele realizara algo ate que a condição pare de ser verdadeira. Mas no loop while usamos um contador externo, que eh declarado antes de comecar o loop, e apos sua finalizacao o valor nao se perde. A primeira maneira segue a seguinte estrutura:

```cpp
while (condicao) {
  // bloco de codigo
}
```

Exemplo da implementacao de contar os 10 primeiros numeros comecando do 0:

```cpp
int count = 0;

while(count < 10) {
  Serial.print(count);
  count++;
}

> 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
```

Acima replicamos o exemplo do for porem usando o while. Caso queira fazer uma contagem ao contrario podemos simplesmente fazer:

```cpp
int count = 9;

while(count > 0) {
  Serial.print(count);
  count--;
}
```

Repare que dessa vez usamos o operador `--`, que seria a mesma coisa que escrever `count = count -1;`.

Tambem podemos modificar o exemplo do pwm para funcionar com um loop while:

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

A segunda maneira de fazer loops while eh usando o  `do ... while` loop, o while que vimos anteriormente ele testa a condição no inicio da execucao, entao caso a primeira condição seja falsa ele nunca executa aquele bloco de codigo, porem o do while checa a condição apenas no final do bloco, logo o codigo eh executado pelo menos uma vez. Ele tem a seguinte estrutura:

```cpp
do {
  // bloco de codigo
} while (condicao);
```

Podemos tambem reescrever o exemplo do led abaixo usando essa estrutura:

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

Porem apenas use esse tipo de loops caso precise que o codigo seja executado pelo menos uma vez independente ou nao de atingir a condicao desejada.

## Loops infinitos

Um loop infinito eh um loop que nunca vai atingir a condicao estipulada, geralmente evitamos esses tipos de loops, porem eles tambem podem ser criados caso queria por algum motivo. Vou listar abaixo algumas maneiras de se fazer isso:

Usando o loop for apenas com `;`:

```cpp
for (;;) {
   // bloco de codigo;
}
```

Usando o while:

```cpp
while(1) {
   // bloco de codigo;
}
```

Usando do while:

```cpp
do {
   bloco de codigo;
}
while(1);
```

No geral voce nao vai usar isso, mas eh importante saber que existe.


## Manipulacao de loops

Tambem temos recursos para sair manualmente de um loop ou pular apenas uma iteracao dele, esses recursos podem ser muito interessantes quando queremos interromper o codigo em uma condicao especial ou ate mesmo pular uma das iteracoes do loop sem interromper as proximas.

* `break`: Ja vimos esse comando no switch case, mas podemos usa-lo de forma semelhante nos loops vistos hoje.

```cpp
for(int i = 0; i < 10; i++) {
  if(i == 7) {
    break;
  }
  Serial.print(i);
}

> 0, 1, 2, 3, 4, 5, 6
```

* `continue`: O continue simplesmente pula a iteracao:

```cpp
for(int i = 0; i < 10; i++) {
  if(i == 7) {
    continue;
  }
  Serial.print(i);
}

> 0, 1, 2, 3, 4, 5, 6, 8, 9
```

Observe que com o break o loop eh realmente interrompido, enquanto com o continue ele pula apenas a iteracao mas continua o loop ate o final.


## Motores

Existem varios tipos de motores, os mais conhecidos sao os motores de passo, servo e dc. No projeto petfeeder usaremos um motor servo para abrir a porta e alimentar o pet. Mas vamos entender melhor cada tipo:

* `Motor DC`: Eh o motor mais conhecido, usado em diversas aplicacoes como maquinas de lavar roupas e furadeiras, eles tem uma velocidade muito alta, porem nao nos permite controlar com exatidao a posicao do motor.

* `Servo motor`: O servo motor tem a capacidade de ir para uma posicao especifica, em relacao a suas coordenadas.

* `Motor de passo`: O motor de passo podemos controlar sua posicao como o servo motor, porem ele tem mais precisao e a maneira de usa-lo eh um pouco diferente.

Por enquanto vamos nos preocupar com o servo motor, usaremos o motor `sg90`, para controla-lo devemos indicar em qual posicao ele deve ir, porem devemos andar posicao por posicao, caso contrario ele pode fazer um movimento muito brusco e danificar alguma coisa.


## Desafio

### User history

Essa semana seu time está começando outro projeto em paralelo. Essa solução tem como objetivo alimentar animais domésticos que tem donos que ficam muito tempo fora de casa ou até mesmo em casos de viagem. O responsável pelo hardware criou um protótipo para isso, a ideia é usar um motor servo para abrir e fechar uma porta para liberar comida, para ativar a o motor sera usado um sensor de presenca PIR.


### Tasklist

* [ ] Desenvolver solução para abrir e fechar o motor ao detectar movimento no sensor PIR. (considere a angulacao maxima possivel do motor sendo 180°)


## Referências e recursos úteis

[for](https://www.arduino.cc/reference/en/language/structure/control-structure/for/)

[while](https://www.arduino.cc/reference/en/language/structure/control-structure/while/)

[do while](https://www.arduino.cc/reference/en/language/structure/control-structure/dowhile/)
