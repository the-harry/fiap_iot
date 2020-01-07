# Aula 5 - Decisões e controles de repetição no python.

## Conteúdo

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

Como dissemos antes, podemos usar o while quando não sabemos ao certo o numero de itens em uma coleção na qual iteraremos, ou quando queremos usar um contador externo para fazer esse controle.




while break continue




## Desafio

### User history

Você está fazendo um treinamento com o senior do time para se aprimorar em python, ele te passou alguns desafios para fazer durante as próximas semanas, nessa semana você tem que fazer um código que manipule algumas estruturas de dados.


### Tasklist

* [ ]
* [ ]
* [ ]
