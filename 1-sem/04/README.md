# Aula 4 - Variáveis, constantes e definições.

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


# Desafio

### User history

ALGO comm leds

### Tasklist

* [ ]
