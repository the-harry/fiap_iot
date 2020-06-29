# Aula 3 - Python 101.

## Conteúdo

O Python oferece uma maneira fácil e amigavel de interagir com seu código. Python é uma linguagem `interpretada`, o que significa que não precisamos compilar nosso código e ele pode ser feito orientado a objetos, o que torna mais fácil reaproveitar código. Os arquivos tem a extenção `.py` e podem ser rodados como scripts ou como programas mais complexos. Python é bastante usado para análise de grandes volumes de dados entre outras aplicações, e o grande número de biblíotecas existentes é incontavel.

Listarei abaixo algumas caracteristicas da sintaxe que devemos nos lembrar do dia a dia:

* O código é organizado por blocos de identação, por isso não fechamos ifs, loops, etc.

* Houve uma quebra de compatibilidade entre a versão 2 e 3. Cuidado para não usar sintaxe antiga(a menos que precise).

Para instalar o python no windows ou mac vá na página de [downloads](https://www.python.org/downloads/) e siga as instruções para sua plataforma e versão escolhida do python, caso use linux procure informações específicas de como instalar na sua distro.

Ao instalar o python você poderá usar o IDLE(REPL, shell do python) ou escrever em um arquivo e depois executá-lo chamando `python meu_codigo.py` ou caso você coloque na primeira linha do arquivo qual deve ser o interpretador ele pode ser executado literalmente como um script, e.g. na primeira linha do seu código tem `#!/usr/bin/python` isso diz que o interpretador padrão desse código será o python localizado em /usr/bin. Logo podemos rodar esse código assim: `./meu_codigo.py`

Com o python instalado vamos escolher um editor para fazermos nosso código, eu recomendo o Atom, algumas outras alternativas legais também são o PyCharm, VsCode, mas caso queira usar o Vim ou qualquer outro editor fique a vontade, apenas use um que você se sinta melhor. Abra um novo arquivo e o salve como `intro.py` e vamos começar.

Bem, vamos começar como todos outros tutoriais de programação, fazendo um hello world. Para fazer isso é bem simples, podemos fazer assim:

`print("Hello World!")`

Para fazer comentários no código usamos #:

`# Sempre é bom dar um espaço do '#' antes de fazer o comentário.`

As variáveis no python são bem simples, elas tem que começar com uma letra, podem ter números, hífens, underline, mas não podem começar com números. Basicamente quando é um valor numérico declaramos:

```python
age = 18
```

Caso seja uma string:

```python
name = 'Jhon Doe'
```

Caso queira juntar uma variável com uma string você pode fazer o seguinte:

```python
name = 'Jhon Doe'

work = 'Programmer'

print("%s is a %s" % (name, work))
```

Que vai imprimir: `Jhon Doe is a Programmer`.

Temos estrururas de dados mais complexas. Esses são dois dos cinco principais tipos, que são numeros, strings, listas, tuplas e dicionários. Porém vamos deixar para falar delas na próxima aula um a um.

Também temos os operadores aritméticos como `+`, `-`, `*` e `/`. Porém temos alguns outros que também são bem interessantes:

* `%` - Módulo, retorna o resto de uma divisão.

* `**` - Eleva um número ao quadrado.

* `//` - Floor, divide um número e arredonda para baixo.

Sempre se lembre quando for fazer operações que a ordem de precedencia importa, use parenteses para isolar as operações. Por exemplo, `1 + 2 - 3 * 2` é diferente de `(1 + 2 - 3) * 2`.

O python conta com vários métodos úteis como sort, reverse, len. Entre outros.

Quando se programa em qualquer linguagem é imprecendivel o uso de bicliotecas, ou libs, para que não precisemos implementar toda a lógica na mão. Uma lib nada mais é do que um pedaço de código que faz alguma coisa útil e pode ser reaproveitado em outros sistemas.
Nessa aula veremos um pouco mais como as libs funcionam no python, como utilizá-las no nosso projeto e falaremos de algumas libs interessantes.
As libs se comportam como pacotes do linux, precisamos de um gerenciador de pacotes para poder de fato instalar alguma coisa. O gerenciador de pacotes do python é o `pip`(python 2.x) ou `pip3`(python 3.x).

Para instalar a lib certifique-se que já tenha o python3.6 instalado, e atualize o pip:

`sudo pip3 install --upgrade pi`

Após isso podemos instalar a lib que queremos.

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



# Aula 5 - Decisões e controles de repetição no python.

## Conteúdo

Antes de falarmos de tomadas de decisões precisamos entender os operadores logicos do python, como eles vamos fazer comparações para saber o que fazer. Segue abaixo uma lista dos principais operadores:

* `==` igualdade

* `!=` diferente

* `<` menor

* `>` maior

* `<=` menor ou igual

* `>=` maior ou igual

* `not` nega uma condição

* `and` as duas condições tem que ser verdadeiras para retornar true

* `or` uma das duas condições tem que ser verdadeiras para retornar true

Tomar decisões no python é muito fácil, já que usamos basicamente if elif else, por não ter switch case e if ternários(em uma linha) não tem uma sintaxe muito diferente do normal.

```
idade = 19

if(idade > 18):
    print("Você pode dirigir.")
elif(idade > 90):
    print("Você deveria ir de uber.")
else:
    print("Você ainda não pode dirigir.")
```

Caso queira fazer um ternário é possivel fazer assim:

```
eh_legal = True
status = "legal" if eh_legal else "chatao"

> 'legal'
```

Muitas vezes temos uma coleção de itens, por exemplo em uma lista e queremos iterar(passar um por um), temos basicamente dois tipos de loops, o for e o while. O for usamos quando sabemos o número de itens que vamos iterar, quando isso pode variar ou não sabemos ao certo a quantia usamos o while.

Imagine que você tem uma lista com preços, e quer multiplicar cada item por dois e adicionar em outra lista:

```
list = [1, 2, 3, 4, 5]
new_list = []

for x in list:
    new_list.append(x * 2)

print(new_list)

> [2, 4, 6, 8, 10]
```

Também podemos iterar sobre um intervalo, podemos falar pra começar um loop no indice 0 e iterar 10 vezes.

```
for x in range(0, 10):
    print(x)
>0
1
2
3
4
5
6
7
8
9
```

Como dissemos antes, podemos usar o while quando não sabemos ao certo o numero de itens em uma coleção na qual iteraremos, ou quando queremos usar um contador externo para fazer esse controle para iterar sobre um bloco. Por exemplo:

```
count = 0

while(count < 10):
    print(count)
    count += 1

>0
1
2
3
4
5
6
7
8
9
```

Nesse caso iniciamos o contador com 0, e incrementamos esse valor a cada volta. Observer que a expressão `count += 1` é a mesma coisa que dizer `count = count + 1`, as outras quatro operações básicas funcionam dessa maneira abreviada.

Também temos dois recursos bem interessantes para loops tanto para while quanto para for loops, que são o break e o continue, o break serve para interromper um loop antes de seu final, no exemplo a seguir temos uma lista de cores, e no loop abaixo eu quero que quando a cor for verde para que o loop seja interrompido. Se a cor não for verde ela será exibida na tela.

```
cores = ['azul', 'rosa', 'verde', 'amarelo']

for cor in cores:
    if cor == 'verde':
        break
    else:
        print(cor)

> azul
rosa
```

Agora imagine que caso a cor seja rosa você quer apenas pular essa iteração mas não o loop todo, você pode usar o continue para isso:

```
cores = ['azul', 'rosa', 'verde', 'amarelo']

for cor in cores:
    if cor == 'rosa':
        continue
    else:
        print(cor)

> azul
verde
amarelo
```

# Aula 6 - Funções no python.

## Conteúdo

Conforme um projeto cresce, seu código vai ficando cada vez menos compreensivel, uma solução para isso é quebrar nosso código em funções, em python funções não tem tipo,

basicao

if name == mainbabla

falar sobre chamada de funções de import

refatoração

## Desafio

### User story

Você está fazendo um treinamento com o senior do time para se aprimorar em python, ele te passou alguns desafios para fazer durante as próximas semanas, nessa semana você tem que fazer um código que


### Tasklist

* [ ] Faça um programa que receba um nome e imprima ele ao contrário.

* [ ] Dados dois números A e B, faça as operações apresentadas na aula e imprima o resultado de cada uma.

* [ ] Faça um programa que receba uma frase e conte quantos caracteres ela tem.
