# Aula 1 - Integrando nosso gadget.

## Conteúdo

### Retro do semestre passado

No ultimo semestre, aprendemos como criar um dispositivo fisico utilizando placas de desenvolvimento como arduino, esp8266, sensores e atuadores. Com o objetivo principal de coletar metricas, claro que em alguma situacoes nos apenas queriamos ativar algum LED ou motor, porem o "ouro do IOT" como muitos dizem, sao as metricas coletadas por sensores.

### O que faremos esse semestre

Esse semestre levaremos nosso dispositivo a outro patamar, faremos Integraçoes com outras tecnologias e serviços, para que possamos principalmente analisar esses dados, armazena-los de uma maneira integra e com precisao temporal, e geracao de alertas, como email, SMS, mensagem no slack, etc.

Temos diversas ferramentas quando nos referimos a IOT, e com isso existem varias stacks que podem ser criadas, porem aqui tentaremos criar uma infraestrutura baseada em containers, onde teremos um servico para receber dados, um servico para o banco onde esses dados serao persistidos, e um servico que consumira esses dados para gerar graficos e alertas.

![Arquitetura](../../img/2sem/01/arquitetura.png)

Na parte responsavel por receber os dados, veremos algumas alternativas para fazer isso, como receber os dados via porta serial, ou por HTTP ou outro protocolo. A ideia eh ilustrar como podemos fazer a mesma coisa de varias maneiras diferentes.

### Cloud VS Fog VS Edge

### CORRIGIR ESSA PARTE

Quando lidamos com o processamento de metricas, existem algumas abordagens arquiteturais que podemos tomar, a mais simples e conhecida eh enviar os dados dos sensores diretamente para a cloud, para que essas metricas sejam processadas todas la. O problema dessa abordagem, eh a quantia absurda de trafego de rede que vamos ter que lidar, possiveis gargalos no servidor, segurança tambem se torna um risco, uma vez que transitamos mais dados pela WAN.
Em resposta a isso, nasceram duas abordagens que procuram trazer esse processamento de dados para mais perto dos sensores, esses modelos sao o FOG e o EDGE.

Entao a chave aqui, eh entender onde que vamos processar nossos dados, e essa escolha vai impactar em como sua arquitetura sera definida. Quando nos referimos a edge e fog, sabemos que a ideia eh trazer o processamento mais perto da coleta de metricas, porem o que diferencia um do outro?

Quando falamos de edge computing, temos sensores conectados diretamente no dispositivo que fara o processamento das metricas, a ideia eh que ele atue como um filtro, processando as metricas e informando o cloud apenas coisas que sao relevantes, dessa forma trazendo mais seguranca, ja que nao vamos ter mais tantos dados transitando de maneira crua, podemos tratar eles no edge e enviar para o cloud.
Podemos exemplificar esse modelo da seguinte forma:

* Ex1 - Um ESP32/8266 coleta metricas, filtra, e em casos de alertas ele envia um request para uma API.

* Ex2 - Um arduino uno coleta metricas, envia por serial para um raspberry, que por vez processa as metricas e em casos de alertas ele envia um request para uma API.

Observem que em ambos os casos, temos os sensores diretamente ligados nos dispositivos intermediarios. Porem voce deve estar se perguntando, o que acontece quando nao consigo ligar o sensor diretamente nele?

Bem, nesse caso, podemos fazer uma Fog Network, a ideia de fog, sao dispositivos na mesma LAN trocando metricas, realizando essa filtragem e o armazenamento de algumas metricas relevantes.
A vantagem de usar uma rede fog, eh que podemos estar fisicamente mais distantes e ainda ter essa conexão. Um exemplo de protocolo muito utilizado para fog eh o LoraWan.

Esse cenario de fog poderiamos descrever algo como:

* Ex1:

    * A - Device A coleta metricas de temperatura, caso a temperatura passe de 50 graus ele chama outro dispositivo na rede que verifica o nivel de CO2.

    * B - Device B mede os niveis de CO2, caso ele receba um request do device A, ele compara as metricas e verifica se tem muito CO2 e muito calor, o que poderia indicar um incendio, caso seja, ele atua o device C.

    * C - O device C controla os sprinklers do predio, ele recebe um aviso de incendio e os ativa.

Com essa abordagem garantimos uma resposta rapida, com baixa latencia, ja que essas metricas nao tiveram nem que sair de minha rede para poder ser processada, em um exemplo como no descrito acima, essa pequena diferenca de nanosegundos no processamento pode salvar ou nao uma vida.


### O que vamos precisar?

Nao se preocupe caso voce nao tenha um rasp, mas se possivel tenha uma maquina com linux, faca um dualboot ou uma maquina virtual com alguma distribuicao mais amigavel como debian, ou ubuntu, pois usaremos alguns recursos que estarão apenas disponiveis nesse SO.

Tambem precisamos ajustar nossos projetos para enviar as metricas da maneira correta para recebermos do outro lado, mas isso vai variar dependendo da tecnica que formos usar, a primeira implementacao nossa sera enviando dados pela porta serial, ja que fizemos bastante isso semestre passado.

Versao atualizada do pet feeder:

https://github.com/the-harry/pet_feeder/tree/v_2


Versao atualizada do smart garden:

https://github.com/the-harry/smart_garden/tree/v_2


## Referências e recursos úteis

[InfluxDB](https://www.influxdata.com/)
[Grafana](https://grafana.com/)
[Docker](https://www.docker.com/)
[rfc 7231 - protocolo HTTP](https://tools.ietf.org/html/rfc7231)
[MQTT](https://mqtt.org/)
[Raspberry](https://www.raspberrypi.org/)
[OpenFog Reference Architecture for Fog Computing](https://www.iiconsortium.org/pdf/OpenFog_Reference_Architecture_2_09_17.pdf)
[Fog definition](https://internetofthingsagenda.techtarget.com/definition/fog-computing-fogging)
