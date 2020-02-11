# Aula 3 - Eletronica basica.

## ELETRONICA VS ELETRICA

Nessa aula falaremos um pouco sobre eletronica basica, mas primeiro vamos entender a diferenca entre eletronica e eletrica. Quando nos referimos a eletronica falamos de circuitos de baixa tensao geralmente, como microcontroladores, celulares, dispositivos eletronicos pequenos entre outros. Ja eletrica geralmente lida com tensoes mais altas, como as que tem nas tomadas, fios de poste, microondas, etc. Porem muitas regras se aplicam para ambos os campos de estudo, mas nosso enfoque aqui sera na parte eletronica.

Quando falamos de uma fonte de alimentacao eletrica temos duas opcoes `VCA` e `VCC`, VCA significa voltagem em corrente alternada e VCC voltagem em corrente contínua, o tipo de corrente alternada foi proposta pelo brilhando Nikola Tesla apos trabalhar um periodo com Thomas Edison para criar uma solucao que fosse capaz de levar energia para as cidades, na epoca tinha apenas a corrente continua de Edison, que nao era eficiente em termos de ser transportada para lugares afastados, o que precisaria de pelo menos uma usina a cada kilometro para cobrir todo o USA, pois havia muita perda de energia. Tesla criou entao a corrente alternada, que eh super efetiva para transportar energia em longas distancias, que eh o padrao que usamos ate hoje em dia na maior parte do mundo. Porem essa energia muitas vezes ao chegar a seus dispositivo eh convertida para corrente continua. Esse episodio da historia foi conhecido como a guerra das correntes.

A diferenca cientifica entre os dois tipos de correte sao como os eletrons se movem dentro do material condutor, na corrente continua eles se movem simultaneamente na mesma direcao, de forma continua. Enquanto na corrente alternada ele se move em varias direcoes, para frente e para traz, o que faz is eletrons sofrerem menos resistencia e poderem enviar mais energia com menos perda e cabos mais finos.

## Lei de Ohm

A lei de Ohm define como algumas grandezas eletricas se comportam,


* `Tensao`:

* `Amperagem`:

* `Resistencia`:


## PWM

Quando queremos controlar a tensao de um circuito podemos fazer isso de algumas maneiras, as principais solucoes seriam colocar um potenciometro, que nada mais eh do que uma resistencia de valor variavel, que seria uma solucao analogica, ou podemos usar o PWM, que seria a maneira digital de fazer isso, Pulse width modulation, ou pulso por tamanho de modulacao eh uma tecnica que usamos para simular esse comportamento do potenciometro de maneira digital. Imagine que voce queira enviar uma tensao de 4v, porem ao enviar um sinal digital HIGH, voce envia 5v. A solucao eh enviar em 1s 80% do tempo HIGH, e 20% do tempo LOW, se calcularmos 80% de 5, chegaremos ao resultado 4. A ideia de controlar o tempo dos ciclos nos ajuda quando precisamos controlar a tensao de algum circuito mas nao queremos adicionar um potenciometro.
O potenciometro eh bom para quando temos algo que consome mais energia, como uma linha de leds, ou ate mesmo um ventilador. Porem para coisas menores, e principalmente quando sao alimentadas por baterias, nossa preferencia eh usar PWM, pois como temos menos resistencia, menos energia eh perdida durante o caminho.

## Multimetro

Uma ferramenta muito importante de aprendermos a usar eh o multimetro, ele nos ajudara a entender alguns cenarios e nos dar a seguranca que precisamos para fazer nossos projetos sem medo de queima-los por falta de medicoes. O multimetro tem dois fios que sao chamados de pontas de teste, a preta deve ser conectada a entrada COM, que representa o terra. E o vermelho deve ser conectado ao que tem um simbolo de OHM, para medirmos a tensao, o outro conector eh para quando queremos medir a corrente em um circuito.

# Desafio

### User history

Seu squad esta fazendo estudos sobre eletronica nessa semana e voce recebeu alguns resistores, uma fonte e um arduino, foi pedido para que voce analisasse os valores dos componentes utilizando um multimetro.

### Tasklist

* [ ] Medir a tensao de alimentacao da placa

* [ ] Medir a tensao de alimentacao do pino no meio da placa

* [ ] Medir a resistencia dos dois resistores apresentados

* [ ] Verificar a continuidade de um circuito

* [ ] Medir a corrente
