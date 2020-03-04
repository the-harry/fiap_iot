# Aula 5 - Operações lógicas - if, else, else if.

## Conteúdo

## Operadores

Antes de falarmos de tomadas de decisões precisamos entender os operadores logicos em C/CPP, com eles vamos fazer comparações para saber o que fazer. Temos três tipos de operadores, os operadores unários, os binários, e o ternário. Segue abaixo uma lista dos principais operadores com uma explicação de cada tipo:

- `Unários` são operadores que só precisam de um elemento, exemplo `int a = 0; a++;`. Quando falarmos de controles de repetição isso ficará mais claro.

  * `++` Incrementa valor

  * `--` Decrementa valor

- `Binários` São operadores que dependem de dois elementos, esses operadores também tem suas subcategorias: aritméticos, relacionais, lógicos, de atribuição ou bitwise.

  - Operadores `Aritméticos` servem para realizar cálculos: `+, -, *, /, %`

  - Operadores `Relacionais` servem para realizar comparações: `<, <=, >, >=, ==, !=`

  - Operadores `Lógicos` servem para combinar operações lógicas, temos o `&&` que representa o AND, o `||` representa o OR, e o `!` significa negação.

  - Operadores de `Atribuição` como o nome já diz servem para atribuir valores, o mais conhecido é o `=`, porém também temos: `+=, -=, *=, /=, %=`, eles são apenas atalhos para casos como esse: `a = a + 1;`, isso pode ser reescrito como `a += 1;`

  - Operadores `Bitwise` transformam uma operação a nível de bits para realizar os cálculos, eles são muito mais performáticos e quase tudo que é calculado em computadores acaba virando uma operação bitwise. `&, |, ^, <<, >>, ~`

- `Ternário` é um tipo especial de operadores que nos permitem tomar decisões em apenas uma linha. Isso ficará mais claro ao final da aula.


## IF, ELSE, ELSE IF

Agora que já sabemos fazer comparações e montar operações lógicas podemos de fato tomar decisões, para isso usamos o `if`, no caso abaixo criamos uma condição que toma uma decisão baseado na idade do indivíduo.

```cpp
if(idade > 18) {
    Serial.println("Você pode dirigir.");
} else if(idade > 90) {
    Serial.println("Você deveria ir de uber.");
} else {
    Serial.println("Você ainda não pode dirigir.");
}
```

Podemos tambem usar operadores diferentes para compor uma condição, exemplos:

Para entrar na montnha russa precisamos ter no minimo 10 anos e 150cm de altura.

```cpp
if(altura > 150 && idade > 10) {
  Serial.println("Pode entrar na montanha russa.");
}
```

Ou podemos falar que caso um retorno seja 1 ou 0 ele eh um valor boleano.

```CPP
if(numero == 1 || numero == 0) {
  Serial.println("Valor boleano.");
}
```


## Ternários

Como falamos anteriormente também temos ternários, que são operadores para fazer um if e else simples em uma linha. Ele eh utilizado para representar condicoes em apenas uma linha. Nao use ternarios caso precise de mais de uma condição.

```cpp
idade > 18 ? Serial.println("Você pode dirigir.") : Serial.println("Você ainda não pode dirigir.");
```

Ternários sempre seguem o seguinte padrao:

`condição` ? `oque_acontece_quando_verdade` : `oque_acontece_quando_falso;`


## Switch case

Também temos o switch case, que escolhe a partir de uma série de opções qual deve ser feita em cada caso.
A palavra-chave break interrompe o comando switch, e é tipicamente usada no final de cada case. Sem um comando break, o comando switch irá continuar a executar as expressões seguintes (desnecessariamente) até encontrar um break, ou até o final do comando switch ser alcançado.

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

## Desafio

### User history

Seu time está iniciando um novo projeto para monitorar e automatizar hortas e jardins domésticos. Após o levantamento de requesitos, foi definido que o projeto deverá medir a umidade do solo, umidade do ar, temperatura e luminosidade. E essa solução também tem que ser capaz de irrigar automaticamente o jardim quando necessário.
Para a primeira parte do projeto vamos implementar os sensores descritos acima usando o codigo de exemplo apresentado como base, queremos armazenar os valores das medicoes e verificar se deve irrigar a horta ou nao baseado na umidade do solo e no nivel de luminosidade. Entao peguem o diagrama feito na aula 2 e vamos coloca-lo em pratica!

### Tasklist

* [ ] Medir sensores e imprimir as medicoes via serial
* [ ] Acender o led verde quando for o momento de fazer a irrigacao
* [ ] Antes de validar a umidade do solo leve em consideracao a luminosidade antes de ativar a irrigacao
* [ ] Quando o solo estiver seco mas nao puder realizar a irrigacao por causa da luminosidade acenda o led vermelho

Tambem tente explorar outras maneiras de fazer o mesmo código.


## Referências e recursos úteis

[Operadores usados no arduino](https://www.arduino.cc/reference/pt/#structure)

[Operadores ternarios](https://www.tutorialspoint.com/arduino/arduino_conditional_operator.htm)

[Switch case](https://www.arduino.cc/reference/pt/language/structure/control-structure/switchcase/)
