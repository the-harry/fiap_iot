# Aula 5 - Decisões e controles de repetição no C++.

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

## Desafio

### User history

Você está fazendo um treinamento com o senior do time para se aprimorar em python, ele te passou alguns desafios para fazer durante as próximas semanas, nessa semana você tem que fazer um código que manipule algumas estruturas de dados.


### Tasklist

* [ ]
* [ ]
* [ ]
