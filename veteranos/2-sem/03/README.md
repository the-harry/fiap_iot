# Aula 3 - Python 101.

## Conteúdo

### Sobre o Python

O Python oferece uma maneira fácil e amigável de interagir com o seu código. A função do Python trata-se de uma linguagem interpretada, o que significa que, com ele, não precisaremos compilar nosso código e ele poderá ser feito orientado a objetos, o que tornará mais fácil o processo de reaproveitamento do código posteriormente. Estes arquivos possuem a extensão .py e podem ser rodados como scripts ou como programas mais complexos.

O Python é bastante usado para análise de grandes volumes de dados, entre outras aplicações, uma vez que o grande número de bibliotecas existentes é incontável.

Listarei abaixo algumas características da sintaxe que devemos nos lembrar no dia a dia:

* O código é organizado por blocos de identação, por isso não fechamos ifs, loops, etc.

* Houve uma quebra de compatibilidade entre as versões 2 e 3. Cuidado para não utilizar a sintaxe antiga (a menos que seja preciso).

Para instalar o Python no Windows ou Mac, vá na página de downloads e siga as instruções para sua plataforma e versão escolhida do Python. Caso utilize o Linux, procure informações específicas de como instalar na sua distro.

Ao instalar o Python, você poderá usar o IDLE (REPL, shell do python) ou escrever em um arquivo e depois executá-lo com o nome `python meu_codigo.py`. Caso você coloque na primeira linha do arquivo qual será o interpretador, ele poderá ser executado literalmente como um script, e.g.

Se, por exemplo, a primeira linha do seu código possui `#!/usr/bin/python`, isso quer dizer que o interpretador padrão desse código será o python localizado em /usr/bin. Logo, podemos rodar esse código assim: `./meu_codigo.py`

Com o Python instalado, o próximo passo será escolher um editor para fazermos nosso código (eu recomendo o Atom, além de outras alternativas interessantes serem o PyCharm e o VsCode), mas, caso você prefira utilizar o Vim ou qualquer outro editor, fique à vontade! É importante que você faça a sua escolha visando sempre aquele em que você se sinta melhor em trabalhar.

Abra um novo arquivo, salve-o como `intro.py` e vamos começar.

Obs: Apenas por curiosidade, o nome Python foi escolhido fazendo referência à comedia britânica dos anos 70, [Monty Python](https://docs.python.org/2/faq/general.html#why-is-it-called-python).


### Gerenciador de pacotes

Quando se programa em qualquer linguagem, é imprescindível o uso de bibliotecas (ou libs), para que não precisemos implementar toda a lógica na mão. Uma lib nada mais é do que um pedaço de código que possui uma função útil e que pode ser reaproveitado em outros sistemas.

#### pip e pip3

Como as libs se comportam como pacotes do Linux, precisamos de um gerenciador de pacotes para poder de fato instalar algo. O gerenciador de pacotes do python é o `pip` (python 2.x) ou `pip3` (python 3.x).


Para instalar a lib, certifique-se de que já tenha o python3.x instalado, para depois atualizar o pip:

`sudo pip3 install --upgrade pi`

Após isso, podemos instalar a lib que quisermos, seguindo o comando abaixo:

`pip3 install nome_do_pacote`

Obs: Você pode procurar pacotes em [pypi.org](https://pypi.org/).

Após instalá-los em sua máquina, você precisará importá-los em seu código:

```python
import foo
```

Será possível também verem este comando de maneiras um pouco diferentes, como por exemplo:

```python
from foo import bar
```

Mas não se preocupe com isso agora, pois geralmente as libs explicam como funcionará a importação delas nos docs.


#### Gerenciando dependências

Conforme vamos colocando libs no nosso projeto, elas criam as nossas dependências, o que é importante para controlarmos a versão dos pacotes usados no projeto. A importância desse controle se dá pelo fato de poder acontecer de uma outra pessoa tentar rodar seu projeto, instalando nele uma versão errada de alguma dessas dependências, fazendo com que o projeto se torne não utilizável. Para evitar essas e outras dores de cabeça, sempre que houver uma nova lib no seu projeto, adicione-a ao seu arquivo `requirements.txt` (onde são guardadas essas referências).

Felizmente, você não precisará verificar lib por lib, uma vez que podemos utilizar o seguinte comando para atualizar esse arquivo:

`pip3 freeze > requirements.txt`

Quando quisermos instalar as dependências em outra máquina, poderemos simplesmente rodar:

`pip3 install -r requirements.txt`


### Bases

Bem, vamos começar como todos os outros tutoriais de programação: fazendo um “hello world”. Para fazer isso é bem simples, conforme segue abaixo:

`print("Hello World!")`

Para fazermos comentários no código, usamos #:

`# Sempre é bom dar um espaço do '#' antes de fazer o comentário.`

As variáveis no Python são bem simples, pois elas têm que começar com uma letra (podendo também ter números, hifens e underlines). É importante lembrar que elas não podem começar com números.

Basicamente, quando se trata de um valor numérico, declaramos:


```python
age = 18
```

Caso seja uma string:

```python
name = 'Jhon Doe'
```

Caso queira juntar uma variável com uma string você poderá fazer o seguinte:

```python
name = 'Jhon Doe'

work = 'Programmer'

print("%s is a %s" % (name, work))
```

Que irá imprimir: `Jhon Doe is a Programmer`.

Temos outras estruturas de dados mais complexas. Esses são dois dos cinco principais tipos, que são: números, strings, listas, tuplas e dicionários. Porém, vamos deixar para falar delas em um outro momento mais adiante.


### Operadores

#### Aritméticos

Dispomos de operadores chamados aritméticos, como `+`, `-`, `*` e `/`. Porém temos alguns outros que também são bem interessantes:

* `%` - Módulo, que retorna o resto de uma divisão.

* `**` - Eleva um número ao quadrado.

* `//` - Floor, divide um número e arredonda para baixo.

Sempre se lembre quando for fazer operações que a ordem de precedencia importa, use parenteses para isolar as operações. Por exemplo, `1 + 2 - 3 * 2` é diferente de `(1 + 2 - 3) * 2`.

#### Logicos

Antes de falarmos de tomadas de decisões, precisamos entender os operadores lógicos do Python e como eles nos ajudarão a fazer comparações, para assim sabermos o que fazer. Segue abaixo uma lista dos principais operadores:

* `==` igualdade

* `!=` diferente

* `<` menor

* `>` maior

* `<=` menor ou igual

* `>=` maior ou igual

* `not` nega uma condição

* `and` as duas condições tem que ser verdadeiras para retornar true

* `or` uma das duas condições tem que ser verdadeiras para retornar true


### Decisões e controles de repetição no python.

Tomar decisões no python é muito fácil, já que usamos basicamente `if`, `elif` e `else`, por não ter switch case e if ternários(em uma linha) não tem uma sintaxe muito diferente do normal.

```python
idade = 19

if(idade > 18):
    print("Você pode dirigir.")
elif(idade > 90):
    print("Você deveria ir de uber.")
else:
    print("Você ainda não pode dirigir.")
```

Caso queira fazer um ternário é possivel fazer assim:

```python
eh_legal = True
status = "legal" if eh_legal else "chatao"

> 'legal'
```

Muitas vezes temos uma coleção de itens, por exemplo em uma lista e queremos iterar(passar um por um), temos basicamente dois tipos de loops, o for e o while. O for usamos quando sabemos o número de itens que vamos iterar, quando isso pode variar ou não sabemos ao certo a quantia usamos o while.

Imagine que você tem uma lista com preços, e quer multiplicar cada item por dois e adicionar em outra lista:

```python
list = [1, 2, 3, 4, 5]
new_list = []

for x in list:
    new_list.append(x * 2)

print(new_list)

> [2, 4, 6, 8, 10]
```

Também podemos iterar sobre um intervalo, podemos falar pra começar um loop no indice 0 e iterar 10 vezes.

```python
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

```python
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

### continue & break

Também temos dois recursos bem interessantes para loops tanto para while quanto para for loops, que são o break e o continue, o break serve para interromper um loop antes de seu final, no exemplo a seguir temos uma lista de cores, e no loop abaixo eu quero que quando a cor for verde para que o loop seja interrompido. Se a cor não for verde ela será exibida na tela.

```python
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

```python
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

### TIME TO CODE

* [ ] Escreva um programa que itere de 1 ate 42, para multiplos de tres imprima "Fizz" ao invez do numero, e para multiplos de cinco, imprima "Buzz". Para numeros que sao multiplos de tres e cinco imprima "FizzBuzz".


### Funções no python.

Conforme um projeto cresce, seu código vai ficando cada vez menos compreensivel, uma solução para isso é quebrar nosso código em funções, em python funções não tem tipo como no C++.

Definicao basica:

```python
def funcao():
  print("Funcao exemplo")

funcao()
```

Podemos tambem passar argumentos e retornar valores:

```python
def soma(a, b):
  return a + b

soma(3, 6)
```

Podemos passar varios tipos de argumentos, para mais detalhes [confira esse link](https://www.w3schools.com/python/python_functions.asp).

Lembre-se sempre de usar as funcoes para isolar trechos logicos do seu codigo, isso facilita a manutenibilidade do projeto.

### TIME TO CODE

* [ ] Faca uma calculadora que saiba fazer raiz quadrada de um numero, e tambem exponencia-lo.

### Estrutura de dados no python.

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

```python
list[0] = 'a'

> ['a', 2, 3, 4, 5]
```

Também podemos acessar um intervalo dentro de uma lista:

```python
list[0:2]

> ['a', 2, 3]
```

Outros métodos importantes:

* append - Insere um novo itém no final de uma lista.

```python
list.append(6)

> ['a', 2, 3, 4, 5, 6]
```

* insert - insere um item na lista em uma posição específica. insert(index, item)

```python
list.insert(2, 'z')

> ['a', 2, 'z', 3, 4, 5, 6]
```

* index - retorna a posição de um elemento na lista.

```python
list.index('a')

> 0
```

Também temos outros métodos como count, remove, pop, sort e reverse e muitos outros. Confira a [documentação](https://docs.python.org/3/tutorial/datastructures.html) para mais informações.

##### Tuplas

Uma tupla se parece bastante com uma lista, porém ela é imutavel, e é declarada com `()`. Uma tupla não pode ter seus valores alterados uma vez criados, para fazer a manipulação desse tipo de dados(caso precise) uma técnicia é transformar a tupla em lista, editar e converter novamente para tupla, mesmo isso não sendo comum ainda é possível.
Tuplas também são mais performáticas que listas, por serem estáticas.

```python
tupla = (1, 2, 4, 4)

(1, 2, 4, 4)
```

Os métodos index, count e a maneira de acessar a tupla é igual em listas:

```python
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

```python
pessoa.keys()

> dict_keys(['nome', 'idade'])

pessoa.values()

> dict_values(['Jhon Doe', 89])
```

Caso queira criar uma nova chave é só atribuir o valor:

```python
pessoa['signo'] = 'Aries'

> {'nome': 'Jhon Doe', 'idade': 89, 'signo': 'Aries'}
```

Lembrando que essas estruturas podem e devem ser misturadas em exemplos reais.


### TIME TO CODE

* [ ] Faca uma funcao boleana que indique se a chave `foo` existe em um dicionário.

- [foo: bar, rab: fu] - deve retornar True

- [fu: bar, rab: foo] - deve retornar False


### Facilidades do python

Muitas pessoas amam o python pela facilidade em criar as coisas, temos diversas libs para nos ajudar, mas tambem temos diversos metodos da propria linguagem que nos ajudam a ordenar coisas, lidar com estruturas de dados e muitas outras coisas, lembre-se sempre de procurar se existe algum metodo para fazer oque voce precisa, muitas vezes acabamos implementando coisas que ja existem.


### Python para scripts

Python eh uma linguagem orientada a objetos, porem podemos utiliza-la para rodar scripts de maneira estrutural, para isso precisamos apenas no topo do arquivo informar para o sistema operacional qual interpretador ele deve usar:

```python
#!/usr/bin/env python3

print("Hello World!")
```

Isso diz para usar o interpretador do python3 para rodar esse arquivo, dessa maneira nosso arquivo nao precisa se quer ter externcao.
Podemos salvar esse codigo com o nome `script` e dar permissao para ele ser executado:

`chmod +x script`

E podemos executa-lo simplesmente rodando:

`./script`

OBS: voces ainda vao se deparar com um codigo assim algumas vezes:

```python
if __name__ == '__main__':
  faz_alguma_coisa()
```

Esse if compara a variavel especial `__name__`, essa variavel retorna main caso o codigo seja o arquivo principal(`main`), se ele nao for o arquivo principal, ou seja foi importado como um modulo, o codigo desse if nao sera executado. Isso garante que a chamada principal daquele arquivo so vai ser executada quando realmente chamarmos, e nao no momento da importacao do arquivo.


## Referências e recursos úteis

[Download Python](https://www.python.org/downloads/)
[Python em 43 minutos com Derek Banas](https://www.youtube.com/watch?v=N4mEzFDjqtA)
[Tutorial de python do W3schools](https://www.w3schools.com/python/)
[Porque Python se chama assim](https://docs.python.org/2/faq/general.html#why-is-it-called-python)
