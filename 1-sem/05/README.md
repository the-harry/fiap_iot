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

Também temos o switch case, que escolhe a partir de uma série de opções qual deve ser feita em cada caso.
A palavra-chave break interrompe o comando switch, e é tipicamente usada no final de cada case. Sem um comando break, o comando switch irá continuar a executar as expressões seguintes (desnecessariamente) até encontrar um break, ou até o final do comando switch ser alcançado.

```
switch (var) {
  case valor1:
    // comando(s)
    break;
  case valor2:
    // comando(s)
    break;
  default:
    // comando(s)
    break;
}
```

## Desafio

### User history

Seu time está iniciando um novo projeto para monitorar e automatizar hortas e jardins domésticos. Após o levantamento de requesitos, foi definido que o projeto deverá medir a umidade do solo, umidade do ar, temperatura e luminosidade. E essa solução também tem que ser capaz de irrigar automaticamente o jardim quando necessário.
Para a primeira parte do projeto vamos implementar o sensor higrômetro para medir a umidade do solo e acender alguns leds para representar as faixas de medição.

Após a base ser criada, seu time ficou responsável por refatorar esse código para que ele não precise mais de leds externos, mude o código para que caso o solo esteja seco que ele ascenda o led builtin, e imprima no console serial cada medição coletada junto com o nível umidade.

### Tasklist

* [ ] Exibir nível de Umidade
* [ ] Acender LED_BUILTIN se estiver seco
* [ ] Mostrar medição

Tente explorar outras maneiras de fazer o mesmo código.
