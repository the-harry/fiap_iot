# Aula 5 - Operações lógicas - if, else, else if.

## Conteúdo

## Operadores

Antes de falarmos de tomadas de decisões, precisamos primeiramente entender os operadores lógicos em C/CPP, pois será com eles que faremos as devidas comparações para saber o que fazer.

Existem três tipos de operadores, sendo eles: os operadores unários, binários e ternários. Segue abaixo uma lista contendo uma explicação referente a cada tipo de operador, além de seus principais modelos:

- `Unários` são operadores que precisam apenas de um elemento, como por exemplo: `int a = 0; a++;`. No momento de nosso estudo em que falarmos de controles de repetição, este conceito ficará mais claro.

  * `++` Incrementa valor

  * `--` -- Decrementa valor

- `Binários` São operadores que dependem de dois elementos, esses operadores também tem suas subcategorias: aritméticos, relacionais, lógicos, de atribuição ou bitwise.

  - Operadores `Aritméticos` servem para realizar cálculos: `+, -, *, /, %`

  - Operadores `Relacionais` servem para realizar comparações: `<, <=, >, >=, ==, !=`

  - Operadores `Lógicos` servem para combinar operações lógicas, temos o `&&` que representa o AND, o `||` representa o OR, e o `!` significa negação.

  - Operadores de `Atribuição` como o nome já diz servem para atribuir valores, o mais conhecido é o `=`, porém também temos: `+=, -=, *=, /=, %=`, eles são apenas atalhos para casos como esse: `a = a + 1;`, isso pode ser reescrito como `a += 1;`

  - Operadores `Bitwise` transformam uma operação a nível de bits para realizar os cálculos, eles são muito mais performáticos e quase tudo que é calculado em computadores acaba virando uma operação bitwise. `&, |, ^, <<, >>, ~`

- `Ternários` considerados um tipo especial de operador, estes nos permitem tomar decisões em apenas uma linha. Isso ficará mais claro ao final desta aula.


## IF, ELSE, ELSE IF

Agora que já sabemos fazer comparações e montar operações lógicas, será possível de fato tomarmos decisões. Para isso usamos o if, como será
visto no caso abaixo, em que criamos uma condição para a tomada de uma decisão com base na idade do indivíduo:

```cpp
if(idade > 18) {
    Serial.println("Você pode dirigir.");
} else if(idade > 90) {
    Serial.println("Você deveria ir de uber.");
} else {
    Serial.println("Você ainda não pode dirigir.");
}
```

Podemos também usar operadores diferentes para compor uma condição, como veremos nos exemplos a seguir.

Para entrar em uma montanha russa, precisamos ter, no mínimo, 10 anos de idade e 150cm de altura.

```cpp
if(altura > 150 && idade > 10) {
  Serial.println("Pode entrar na montanha russa.");
}
```

Ou podemos falar que, caso um retorno seja 1 ou 0, ele é um valor boleano.

```CPP
if(numero == 1 || numero == 0) {
  Serial.println("Valor boleano.");
}
```

Para treinarmos um pouco este conteúdo, vamos fazer um algoritmo.

Escreva um programa que leia um número, conforme as orientações: caso ele seja um múltiplo de 3, imprima "fizz"; caso seja um múltiplo de 5, imprima "buzz" e, caso não seja um múltiplo de 3 e nem de 5, imprima o próprio número:

```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  int num = 5;

  if(num % 3 == 0) {
    Serial.println("Fizz");
  } else if(num % 5 == 0) {
    Serial.println("Buzz");
  } else {
    Serial.println(num);
  }
}
```

## Ternários

Como falamos anteriormente, temos também os operadores ternários, que trabalham desenvolvendo um if ou um else simples em apenas uma linha. Ele é utilizado, geralmente, para representar condições em apenas uma linha.

Atenção: Não use ternários caso precise de mais de uma condição.

```cpp
idade > 18 ? Serial.println("Você pode dirigir.") : Serial.println("Você ainda não pode dirigir.");
```

Os Ternários sempre seguem o seguinte padrão:

`condição` ? `oque_acontece_quando_verdade` : `oque_acontece_quando_falso;`

Como já mencionado nesta aula, podemos usar apenas duas condições em ternários. Por isso, vamos então alterar um pouco o exemplo anterior:
dessa vez, se for um múltiplo de 3, imprimiremos fiz e, caso não seja, imprimiremos o próprio número:

```cpp
void setup() {
  Serial.begin(9600);
}

void loop() {
  int num = 3;

  num % 3 == 0 ? Serial.println("Fizz") : Serial.println(num);
}
```

Podemos também fazer com que esse código incremente o número, se aproveitando da estrutura do loop e do operador `++`:

```cpp
int num = 3;

void setup() {
  Serial.begin(9600);
}

void loop() {
  num % 3 == 0 ? Serial.println("Fizz") : Serial.println(num);
  num++;
}
```


## Switch case

O switch case, ainda não citado nesta aula, possui a função de escolher, a partir de uma série de opções, qual é mais válida e deverá ser executada em cada caso.

A palavra-chave break interrompe o comando switch, e é tipicamente usada no final de cada case. Sem um comando break, o comando switch irá continuar a executar as expressões seguintes, desnecessariamente, até encontrar um break, ou até o final do comando switch ser alcançado.

```cpp
switch (var) {
  case valor1:
    // comando(s) caso var == valor1
    break;
  case valor2:
    // comando(s) var == valor2
    break;
  default:
    // comando(s) caso nao entre em nenhum outro caso
    break;
}
```

Como, no switch case, esperamos ver vários valores diferentes para uma mesma variável, este exemplo não faria muito sentido para reescrever o fizzbuzz. Porém, imagine que um programa pegue um código http e fale qual é a sua descrição. Poderíamos, a partir daí, desenvolver um raciocínio próximo a isso:

```cpp
int http_status = 200;

void setup() {
  Serial.begin(9600);
}

void loop() {
  switch (http_status) {
  case 100:
    Serial.println("Continue");
    break;
  case 200:
    Serial.println("Ok");
    break;
  case 300:
    Serial.println("Multiple choices");
    break;
  case 400:
    Serial.println("You made something wrong");
    break;
  case 500:
    Serial.println("The developer made something wrong");
    break;
  default:
    Serial.println("Qualquer outro codigo sem ser os listados");
    break;
 }
}
```

## Desafio

### User history

Seu time está iniciando um novo projeto para monitorar e automatizar hortas e jardins domésticos. Após o levantamento dos requisitos, foi definido que o projeto deverá medir a umidade do solo, a umidade do ar, a temperatura e a luminosidade. Essa solução também deve ser capaz de irrigar automaticamente o jardim, quando necessário.

Para a primeira parte do projeto, vamos implementar os sensores descritos acima, utilizando o código de exemplo apresentado como base. Como queremos armazenar os valores das medições e verificar se este mecanismo deve irrigar a horta ou não, baseado na umidade do solo e no nível de luminosidade, então peguem o diagrama desenvolvido na aula 2 e vamos colocá-lo em pratica!

Usaremos um sensor higrômetro para medir a umidade do solo, um sensor LDR para medir a luminosidade e, por último, o DHT11 para medir a temperatura e umidade do ar. Esse sensor precisa da lib DHT11 da Adafruit.

Use as seguintes conexões para esse projeto:

```yaml
LED_GREEN: pino 12,
LED_RED: pino 13,
Higrômetro: pino A1,
LDR: pino A2,
DHT: pino A3
```

### Tasklist

* [ ] Medir sensores e imprimir as medições via serial
* [ ] Acender o LED verde quando for o momento de fazer a irrigação
* [ ] Antes de validar a umidade do solo, leve em consideração a luminosidade do local antes de ativar a irrigação
* [ ] Quando o solo estiver seco, mas não puder realizar a irrigação por conta da luminosidade, acenda o LED vermelho

Tente também explorar outras maneiras de utilizar o mesmo código.


## Referências e recursos úteis

[Operadores usados no arduino](https://www.arduino.cc/reference/pt/#structure)

[Operadores ternarios](https://www.tutorialspoint.com/arduino/arduino_conditional_operator.htm)

[Switch case](https://www.arduino.cc/reference/pt/language/structure/control-structure/switchcase/)
