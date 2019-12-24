# Aula 8 - Libs em python - pip, gpio.

## Conteúdo

Quando se programa em qualquer linguagem é imprecendivel o uso de bicliotecas, ou libs, para que não precisemos implementar toda a lógica na mão. Uma lib nada mais é do que um pedaço de código que faz alguma coisa útil e pode ser reaproveitado em outros sistemas.
Nessa aula veremos um pouco mais como as libs funcionam no python, como utilizá-las no nosso projeto e falaremos de algumas libs interessantes.
As libs se comportam como pacotes do linux, precisamos de um gerenciador de pacotes para poder de fato instalar alguma coisa. O gerenciador de pacotes do python é o `pip`(python 2.x) ou `pip3`(python 3.x).

Para começar vamos instalar a lib `GPIO`(General Purpose Input/Output), ela nos permite interagir com as portas programáveis do raspberry.
Para instalar a lib certifique-se que já tenha o python3.6 instalado, primeiro vamos atualizar o pip:

`sudo pip3 install --upgrade pi`

Após isso podemos instalar a lib que queremos.

`sudo pip3 install gpio`

Bem, agora podemos começar nosso código:


```python
#! /usr/bin/python3

import RPi.GPIO as gpio


```

## Desafio

### User history


### Tasklist

* [ ] Instalar python3 e pip caso não tenha

* [ ] Atualizar o pip

* [ ] Instalar GPIO e testar o ambiente com o led.


Após acabar de configurar o ambiente, poderiamos fazer algo mais legal, que tal mudarmos o código para fazer
