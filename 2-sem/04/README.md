# Aula 4 - Integração Arduino e Rasp, comunicação serial.

## Conteúdo

Nessa aula exploraremos um pouco mais sobre as libs do python, especialmente a `pyserial`, que usaremos para realizar a comunicação do nosso device com um rasp/computador, dessa maneira podemos tirar vantagem da facilidade oferecida pelo python para realizar algumas tarefas que seriam mais complicadas de fazer no proprio dispositivo.

Para comecar, precisamos primeiramente atualizar um pouco os nossos projetos para preparar eles para usar essa tecnica, como receberemos e enviaremos dados importantes pelo serial eh importante que tiremos qualquer `Serial.print` que o codigo tenha com fins de debug. Apenas enviaremos pela porta serial dados que sejam semanticamente importantes para nosso codigo.

Nessa aula usaremos o projeto do PetFeeder para explorar esse conceito, as alteracoes feitas no device se encontram nas referencias abaixo.

A primeira mudanca foi tirar a alimentacao automatica por deteccao de movimento(~~foi descoberto com testes que os gatos tendem a se tornarem mais malandros e comecarem a frequentar o dispositivo com mais frequencia~~). Agora ele apenas ativara quando enviarmos o comando `open` pela porta serial.
E ele apenas verifica se o gato esta proximo ou nao para metrificar quantas vezes o pet vai procurar comida. Caso esteja presente ele imprime 1 na porta serial, caso nao esteja ele imprime 0.

A partir desse ponto, nossa responsabilidade eh ler essas metricas e conseguir enviar a string open via porta serial.

## pyserial

Primeiramente vamos instalar a lib em nossa maquina:

```bash
pip3 install pyserial
```

Para usarmos a lib, basicamente precisamos criar uma conexão e enviar ou receber dados. O snippet abaixo faz isso de maneira bem simples:

```python
# importa a lib pyserial
import serial

# Declara aonde esta a porta que vamos usar, podemos achar isso usando a IDE do arduino
port = '/dev/ttyUSB0'

# Aqui vai o mesmo baud rate usado no dispositivo
baud = 9600

# usamos o seguinte comando para criar uma conexao, caso ela falhe voce recebera uma exception
connection = serial.Serial(port, baud)

# Para lermos a serial usamos o readline, mas ele vem como byte, voce vera algo como:
# b'0\r\n'
connection.readline()

# Para pegarmos apenas o valor, temos que remover as quebras de linha com o rstrip e colocar no encoding correto para converter o tipo de bytes para string.

connection.readline().decode('utf-8').rstrip()

# Para enviarmos dados via serial usamos o comando write, se quisermos enviar a palavra open, temos que usar o .encode para transformar a string em bytes para fazer o envio. Sem isso voce tera um erro TypeError: unicode strings are not supported, please encode to bytes
connection.write('open'.encode())
```

Essa eh a base para o que faremos hoje, vamos montar um programa que leia o serial e alimente o pet de acordo com as medicoes, vamos tentar usar alguns conceitos de progracao orientada a objetos para deixar nosso codigo mais reaproveitavel.

## Desafio

A primeira coisa que precisamos agora sao logs, implemente um mecanismo de log usando alguma lib que faca isso e remova todos os prints do projeto.
Fora isso, precisamos implementar alguma logica no arquivo main.py para que possamos alimentar os pets, a ideia eh que em caso de menos de uma hora, o gato passar 5 vezes proximo ao sensor devemos alimenta-lo.
Esse desafio se torna interessante pois isso era uma coisa que nao poderiamos fazer no arduino sem ter um modulo de tempo, ja que ele por si so nao consegue calcular o tempo.

### Tasklist

* [ ] Implementar logs no sistema

* [ ] Criar politica de alimentacao para o gato


## Referências e recursos úteis

[pyserial docs](https://pythonhosted.org/pyserial/)

[PetFeeder v2](https://github.com/the-harry/pet_feeder/tree/v2.0.1).
