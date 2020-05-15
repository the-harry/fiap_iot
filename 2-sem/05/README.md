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

## Desafio

### User story

Você está fazendo um treinamento com o senior do time para se aprimorar em python, ele te passou alguns desafios para fazer durante as próximas semanas, nessa semana você tem que fazer um código que manipule algumas estruturas de dados.


### Tasklist

* [ ]
* [ ]
* [ ]
