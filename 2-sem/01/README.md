# Aula 1 - Integrando nosso gadget.

## Conteúdo

### Retro do semestre passado

No ultimo semestre, aprendemos como criar um dispositivo fisico utilizando placas de desenvolvimento como arduino, esp8266, sensores e atuadores. Com o objetivo principal de coletar metricas, claro que em alguma situacoes nos apenas queriamos ativar algum LED ou motor, porem o ouro do IOT como muitos dizem, sao as metricas coletadas por sensores.

### O que faremos esse semestre

Esse semestre levaremos nosso dispositivo a outro patamar, faremos Integraçoes com outras tecnologias e serviços, para que possamos principalmente analisar esses dados, armazena-los de uma maneira integra e com precisao temporal, e geracao de alertas, como email, SMS, mensagem no slack, etc.

Temos diversas ferramentas quando nos referimos a IOT, e com isso existem varias stacks que podem ser criadas, porem aqui tentaremos criar uma infraestrutura baseada em containers, onde teremos um servico para receber dados, um servico para o banco onde esses dados serao persistidos, e um servico que consumira esses dados para gerar graficos e alertas.

![Arquitetura](../../img/2sem/01/arquitetura.png)

Na parte responsavel por receber os dados, veremos algumas alternativas para fazer isso, como receber os dados via porta serial, ou por HTTP ou outro protocolo. A ideia eh ilustrar como podemos fazer a mesma coisa de varias maneiras diferentes.

### Fog VS Edge

Atualmente os dispositivos de borda tem se tornados mais comuns a cada dia, com o crescimento das clouds, surge uma nova nessecidade, a aquitetura tradicional tinha apenas um client e um backend, o client simplesmente jogava a informação para o backend e o mesmo cuidava de todo processamento. Porém em um cenário real de uma aplicação em produção, muitas vezes a cloud acaba sendo onerada pelas requisições cheias de dados "sujos" da internet.
Para solucionar esse problema usamos a arquitetura de dispositivos de borda, aonde colocamos um "intermediário" entre as duas partes. Esse dispositivo pode ter diversas funções, mas o principal é receber os dados de um client e limpar, filtrar, e pre-processá-los para passar para o backend apenas o que realmente importa.

Imagine um caso aonde temos um sensor enviando 100 medições por segundo para a cloud, e lá essas medições são somadas em um perído de 1hr e depois feito uma média. Caso usarmos um dispositivo de borda para fazer esses cálculos e enviar apenas os dados que precisamos para o backend teremos menos tráfego de rede, gastaremos menos poder computacional, e logo gastamos menos dinheiro.

A comunicação entre as partes pode ser feita com diversos protocolos e padrões, entre os principais valem ressaltar o clássico API's HTTP REST, Lora que usa frequencias de rádio, Bluetooth(ou BLE, que é uma versão mais leve), MQTT que é um protocolo de enfileiramento de mensagens, entre outros.

Um dispositivo muito usado para dispositivos de borda é o raspberry pi, ele é um mini-computador, muitas distribuições linux são suportadas nele, porém a imagem mais comum de se utilizar é o [Raspian](https://www.raspberrypi.org/downloads/raspbian/) ele é baseado no Debian, e temos algumas opções na hora da instalação, a versão minimal(CLI), uma versão desktop(GUI), e uma versão de desktop com os "softwares recomendados" que vem alguns softwares proprietários como drivers. Para instalar a imagem você pode usar o comando `dd` no linux ou algum gravador de imagens. O raspberry oferece conexão wifi, Bluetooth, cabeada por RJ-45, e tem 40 pinos GPIO que nos permite conectar várias coisas legais! :) Mas veremos isso com mais detalhes mais a frente.


### O que vamos precisar?

Nao se preocupe caso voce nao tenha um rasp, mas se possivel tenha uma maquina com linux, faca um dualboot ou uma maquina virtual com alguma distribuicao mais amigavel como debian, ou ubuntu, pois usaremos alguns recursos que estarão apenas disponiveis nesse SO.

Tambem precisamos ajustar nossos projetos para enviar as metricas da maneira correta para recebermos do outro lado, mas isso vai variar dependendo da tecnica que formos usar, a primeira implementacao nossa sera enviando dados pela porta serial, ja que fizemos bastante isso semestre passado.

## Desafio

### User story




### Tasklist

* [ ] Redesenhar a implementação da arquitetura usando um dispositivo de borda e pesquisar sobre o modelo;

* [ ] Fazer levantamento de qual protocolo seria melhor para esse projeto junto com o time, e explicar o porquê;

Com essas informações em mãos crie um repositório no github com seu time, os adicione como mantedores do projeto e documente essas informações levantadas no arquivo `README.md` do projeto.


## Referências e recursos úteis

[InfluxDB](https://www.influxdata.com/)
[Grafana](https://grafana.com/)
[Docker](https://www.docker.com/)
[rfc 7231 - protocolo HTTP](https://tools.ietf.org/html/rfc7231)
[MQTT](https://mqtt.org/)
[Raspberry](https://www.raspberrypi.org/)
[OpenFog Reference Architecture for Fog Computing](https://www.iiconsortium.org/pdf/OpenFog_Reference_Architecture_2_09_17.pdf)
[Fog definition](https://internetofthingsagenda.techtarget.com/definition/fog-computing-fogging)
