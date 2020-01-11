# Aula 4 - Estrutura de dados no python.

## Conteúdo

Agora que já sabemos a sintaxe básica do python, outra coisa muito importante de entender são as estruturas de dados. Segundo a Wikipedia:

```
Uma estrutura de dados, em ciência da computação, é uma coleção tanto de valores quanto de operações. É uma implementação concreta de um tipo abstrato de dado ou um tipo de dado básico ou primitivo.
```

Em python temos algumas estruturas diferentes, já vimos sobre strings que são basicamente uma sequencia imutavel de caracteres, agora falaremos sobre listas, tuplas, dicionários. Existem outras estruturas como conjuntos(sets e frozensets) e algumas outras disponíveis nos módulos `collections` e `heapq`, porém eles não serão nosso foco.

##### Listas

Uma lista em python se comporta como uma array, ou um vetor. Declaramos uma lista usando `[]`, exemplo:

`list = [1, 2, 3, 4, 5]`

A cada item dessa lista é atribuido um index, que é a posição dele nessa lista. Por exemplo, o número 1 está no index 0, e o número 5 no index 4. Caso queira acessar um index para retornar um valor é possível fazer assim:

`list[0]`

O que nos retorna 1.

`> 1`

Caso queira mudar o primeiro item podemos fazer o seguinte:

```
list[0] = 'a'

> ['a', 2, 3, 4, 5]
```

Também podemos acessar um intervalo dentro de uma lista:

```
list[0:2]

> ['a', 2, 3]
```

Outros métodos importantes:

* append - Insere um novo itém no final de uma lista.

```
list.append(6)

> ['a', 2, 3, 4, 5, 6]
```

* insert - insere um item na lista em uma posição específica. insert(index, item)

```
list.insert(2, 'z')

> ['a', 2, 'z', 3, 4, 5, 6]
```

* index - retorna a posição de um elemento na lista.

```
list.index('a')

> 0
```

Também temos outros métodos como count, remove, pop, sort e reverse e muitos outros. Confira a [documentação](https://docs.python.org/3/tutorial/datastructures.html) para mais informações.

##### Tuplas

Uma tupla se parece bastante com uma lista, porém ela é imutavel, e é declarada com `()`. Uma tupla não pode ter seus valores alterados uma vez criados, para fazer a manipulação desse tipo de dados(caso precise) uma técnicia é transformar a tupla em lista, editar e converter novamente para tupla, mesmo isso não sendo comum ainda é possível.
Tuplas também são mais performáticas que listas, por serem estáticas.

```
tupla = (1, 2, 4, 4)

(1, 2, 4, 4)
```

Os métodos index, count e a maneira de acessar a tupla é igual em listas:

```
# contar quantos 4's tem a tupla
tupla.count(4)

> 2

tupla.index(2)

> 1

tupla[3]

> 4
```

##### Dicionários

Um dicionário funciona um pouco diferente de tuplas e listas, nós a declaramos usando `{}` e ele sempre deve ser composto por uma chave e um valor. Podemos fazer um dicionário para armazenar idade de pessoas assim:

`pessoa = {'nome': 'Jhon Doe', 'idade': 89}`

E para acessar o valor de uma chave é só fazer:

```
pessoa['nome']

> 'Jhon Doe'

pessoa['idade']

> 89
```

Você também pode pedir as chaves ou valores de um dicionário:

```
pessoa.keys()

> dict_keys(['nome', 'idade'])

pessoa.values()

> dict_values(['Jhon Doe', 89])
```

Caso queira criar uma nova chave é só atribuir o valor:

```
pessoa['signo'] = 'Aries'

> {'nome': 'Jhon Doe', 'idade': 89, 'signo': 'Aries'}
```

Lembrando que essas estruturas podem e devem ser misturadas em exemplos reais.

## Desafio

### User history

Você está fazendo um treinamento com o senior do time para se aprimorar em python, ele te passou alguns desafios para fazer durante as próximas semanas, nessa semana você tem que fazer um código que manipule algumas estruturas de dados.


### Tasklist

* [ ]
* [ ]
* [ ]
