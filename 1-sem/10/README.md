## Aula 10 - Arrays e estruturas de dados.

## Conteúdo

Nessa aula vamos falar um pouco sobre as estruturas de dados e algumas construções especificas do C/CPP. Mas afinal, o que é uma estrutura de dados?

Uma estrutura de dados, como o próprio nome já diz, é uma maneira de organizar informações de forma estruturada. Os principais tipos de dados em C/CPP são:

* Stack: Uma pilha (ou stack) coloca um item em cima do outro, além de utilizar o algoritmo `FILO` (first in, last out), ou seja, para tirarmos o primeiro item da pilha, teríamos que tirar os outros antes.

* Queues: Uma fila, diferentemente de uma pilha, trabalha com a ideia de `FIFO` (first in, first out), ou seja, o primeiro a entrar na fila será sempre o primeiro a sair dela.

* Linked lists: As listas ligadas funcionam como caixas conectadas, que apenas reconhecem a caixa à sua frente, ou seja, cada item da lista contém um valor e um ponteiro (que guardará apenas um endereço na memória, sendo no caso o endereço do próximo item). O último item deve apontar para NULL, indicando assim o final da lista, mas podendo também apontar para o primeiro (tornando esta uma lista circular).

Existem ainda diversos outros tipos de estruturas de dados, sendo alguns deles não implementados em C/CPP  (mas que podem ser feitos “na mão”), ou que exista ainda alguma lib para implementar (como é o caso de hashing tables, grafos, arvores binárias, etc). Nessa aula, focaremos em arrays e matrizes, além de falarmos também um pouco sobre structs.

### Arrays

Uma array (ou vetor, como é chamado em português), é uma estrutura que guarda uma cadeia de itens, ou seja, uma variável que guarda vários valores. Esses valores são armazenados em índices diferentes.

Para declarar uma array, utilizamos a seguinte sintaxe:

```cpp
tipo nome[tamanho];
```

Imagine agora uma lista de números, contendo 5 itens. Essa lista poderá ser declarada assim:

```cpp
int numeros[5] = {10, 20, 30, 40, 50};
```

Ou até mesmo dessa forma:

```cpp
int numeros[] = {10, 20, 30, 40, 50};
```

Neste exemplo, como colocamos um número exato de itens na inicialização, ele já entende que são 5.

Para acessar o número 10, temos que pegar o primeiro índice da array, que sempre começará em 0.

```cpp
numero[0];
```

Podemos também mudar qualquer elemento da array, conforme mostrado a seguir:

```cpp
numero[0] = 100;
Serial.println(numero);
// > 100
```

Dicas úteis quando mexer com arrays:

* Lembre-se de que elas sempre começarão no índice 0.

* O índice -1 pegará o último item da array.

* Caso queira saber o tamanho de uma array, use o método sizeof(array).

### Matrizes

Matrizes são arrays bidimensionais, ou seja, vetores de vetores. Usaremos este tipo de estrutura de dados para implementar nosso teclado, que nada mais é do que uma matriz. Por isso o nome: teclado matricial.

Declaramos uma matriz informando o número de linhas e colunas:

```CPP
char matriz[qtd_linhas][qtd_colunas] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
```

Para acessar o número 5, do exemplo acima, precisaremos ir até a segunda linha e a segunda coluna.

```cpp
matriz[1][1];
```

### Structs

Os structs são construções do C, que permitem que você crie suas próprias estruturas de dados, contendo vários outros tipos dentro.

Imagine que queiramos armazenar informações sobre uma pessoa: não podemos guardar nome e idade na mesma variável, pois são informações de tipos diferentes.

Sendo assim, vamos usar um struct para isso:

```CPP
typedef struct // define um novo tipo que vamos criar agora
{
    String nome; // define o atributo nome
    int idade;    // define o atributo idade
} Pessoa; // Define o nome do novo tipo, como pessoa
```

Aos que já programam em alguma linguagem orientada a objetos, devem ter percebido como isso se parece com uma classe. É como se pudéssemos criar uma classe simples (sem alguns recursos que uma classe de fato tem).

Podemos agora manipular nossa estrutura nova assim:

```CPP
Pessoa Fulano;

Fulano.nome = "Fulano Cicrano";
Fulano.idade = 42;

Fulano.idade
// 42

Fulano.nome
// Fulano Cicrano
```

### Na prática

Para implementar esse teclado, possuímos várias possibilidades diferentes: podemos usar uma lib ou podemos implementar toda a lógica “na mão”. Para simplificar, usaremos a lib Keypad.

Caso não usássemos a lib Keypad, poderíamos iterar todos os itens da matriz e ver qual linha e qual coluna estão apertadas, assim como usar um monte de if's com várias combinações, ou ainda o que seria a solução mais correta: usar um interruptor (que criará uma ação que interrompe o processamento atual e inicia uma nova rotina). É importante saber, porém, que essa maneira seria um pouquinho mais complicada de realizar, então vamos nos ater à matriz por enquanto.

Imagem do teclado:

![Teclado matricial](../../img/1sem/10/teclado.png)


## Desafio

### User story

Altere o código, aprendido na aula de hoje, para ler uma senha de 4 dígitos e comparar com uma senha padrão 1234. O programa deve autorizar ou não o acesso.

### Tasklist

* [ ] Escrever programa para validar a senha digitada no teclado pelo usuário.

* [ ] Caso esteja autorizado, abra a solenoide da fechadura.

## Referências e recursos úteis

[Linked list](https://en.wikipedia.org/wiki/Linked_list)
[Tutorial de arrays multidimensionais](https://www.tutorialspoint.com/arduino/arduino_multi_dimensional_arrays.htm)
[Structs](http://www.cplusplus.com/doc/tutorial/structures/)
[Explicação de todas estruturas de dados](https://www.geeksforgeeks.org/data-structures/)
[Tutorial keypad matricial](https://www.arduinoecia.com.br/teclado-matricial-membrana-4x3-arduino/)
