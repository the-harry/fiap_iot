# Aula 5 - Operações lógicas - if, else, else if.

## Conteúdo

Antes de falarmos de tomadas de decisões precisamos entender os operadores logicos em C/CPP, como eles vamos fazer comparações para saber o que fazer. Temos três tipos de operadores, os operadores unários, os binários, e o ternário. Segue abaixo uma lista dos principais operadores com uma explicação de cada tipo:

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

Agora que já sabemos fazer comparações e montar operações lógicas podemos de fato tomar decisões, para isso usamos o `if`, no caso abaixo criamos uma condição que toma uma decisão baseado na idade do indivíduo.

```
int idade = Serial.readln();

if(idade > 18) {
    Serial.println("Você pode dirigir.");
} else if(idade > 90) {
    Serial.println("Você deveria ir de uber.");
} else {
    Serial.println("Você ainda não pode dirigir.");
}
```

Como falamos anteriormente também temos ternários, que são operadores para fazer um if e else simples em uma linha.

```
idade > 18 ? Serial.println("Você pode dirigir."); : Serial.println("Você ainda não pode dirigir.");
```

Ternários sempre seguem esse padrão de:

`condição` ? `oque_acontece_quando_verdade` : `senão_faz_isso`

Também temos o switch case, que escolhe a partir de uma série de opções qual deve ser feita em cada caso:

```

```
## Desafio

### User history

Você está fazendo um treinamento com o senior do time para se aprimorar em python, ele te passou alguns desafios para fazer durante as próximas semanas, nessa semana você tem que fazer um código que manipule algumas estruturas de dados.


### Tasklist

* [ ]
* [ ]
* [ ]
