# Aula 1 - Arduino, tipos, instalação da IDE

## Conteúdo

Nesse semestre faremos alguns projetos com arduino, um arduino não é simplesmente um micro-controlador, ele é uma placa de desenvolvimento que tem um micro-controlador e algumas outras peças que facilitam nosso trabalho, para programar micro-controladores "na mão" é bem mais complexo, e o arduino facilita isso para nós.
O Arduino pode ser alimentado por uma fonte de 9v ou um cabo serial-usb(bro tip: muitas impressoras usam esse cabo). A fonte geralmente é usada quando o projeto está em funcionamento mesmo(ou baterias...) e o cabo serial é usado para transferência de dados. O Arduino usa C++ como linguagem padrão, mas existem alternativas(mais sombrias, diga-se de passagem), porém foquem no C++!
O arduino tem alguns pinos(a quantidade muda de acordo com o modelo), esses pinos servem para fazer conexões baseadas em input e output. Temos os pinos analógicos, que são prefixados com um A maiusculo, ex: `A1`, onde seus valores variam de 0 a 1023, temos também pinos digitais, que são representados apenas por números, ex: `13`, e os pinos prefixados com `~` são pinos PWM, que simula um sinal analógico. Também temos os pinos de alimentação como `3.3v`, `5v` e `GND`(Ground) entre [outros](https://www.arduino.cc/en/reference/board).

Temos uma gama enorme de modelos dispoíveis, entre eles muitos que não são da empresa Arduino propriamente dito. Abaixo vou listar alguns modelos e citar algumas caracteristicas:

* Arduino Uno - O mais conhecido de todos, ele é um modelo bem simples e barato, e muito indicado para quem está começando, porém não tem muitos recursos especiais mas tem uma quantia razoavel de pinos.

* Arduino Mega - Um dos maiores modelos, com mais de 70 pinos dispoíveis, esse modelo é muito usado em impressoras 3D, cortadoras a laser e CNC's.

* Arduino mini / pro micro - Esses dois modelos são bem conhecidos pelo seu tamanho, são bem pequenos e geralemnte usados para projetos mais discretos, como o Rubber Ducky, teclados mecânicos, etc.

* Esp32 / Esp8266 - Esses modelos não são da empresa Arduino, eles se destacam por seu tamanho pequeno e pela quantidade enorme de recursos que já vem embutidas e não precisam ser compradas a parte, como o módulo de wifi, bluetooth, 520 KiB SRAM de memória(o que é mais que alguns arduinos), porém o upload do código para a placa é um pouco mais chatinho e algumas coisas funcionam um pouco diferente de arduinos convencionais, então sempre que usar um ESP verifique se a lib que tu usará suporta o seu dispositivo.

Um termo muito comum também de se ouvir é `SHIELDS`, shields são módulos que se conectam ao arduino para fazer algo como abaixar a tensão de um circuito, controlar um motor, etc.

Agora que já entendemos o básico do funcionamento do arduino vamos falar um pouco sobre a IDE(Integrated Development Environment) do Arduino. Primeiro instale ela em sua máquina, caso use linux algo como `sudo apt install arduino` resolve seu problema, caso use windows ou mac acesse [esse link](https://www.arduino.cc/en/main/software) e faça o download.

Para nós as principais funções são:

* File -> Examples: Possui diversos exemplos para se inspirar.

* Sketch -> Add library: Instalar uma lib na sua máquina.

* Tools -> Board: Para escolher qual placa você está usando.

* Tools -> Serial Port: Escolhe a porta usb do computador que está ligado a porta serial do arduino, no linux o padrão de nomenclatura para esse dispositivo é algo assim: `dev/ttyACM0`, e para windows `COM1`.

* Tools -> Auto Format: Identa seu código corretamente.

* Botão verify: Compila seu código para saber se tem algum erro mas não envia para a placa.

* Botão upload: Compila seu código e envia para a placa.


## Desafio

### User history

Jhon Doe criou uma startup voltada para monitoramento doméstico e você foi contratado por ele essa semana e hoje é seu primeiro dia(Parabéns! ;), e ele e seu time projetaram uma solução para monitorar jardins, solução na qual você os ajudará a criar. A sua ideia é criar algo que seja escalavel conforme a necessidade do cliente para prover um GAAS(Garde As A Service) onde seriam oferecidos serviços desde monitoração do solo, luz, humidade, entre outros.
A empresa ainda é pequena e temos poucos funcionários, apenas o que precisamos para fazer o trabalho sair. Temos o Jhon Doe que cuida da parte do negócio, temos o Fulano Foo, que cuida do código, e a Jane Doe, que cuida da infra e hardware. A ideia é que no início você aprenda um pouco com cada um e posteriormente escolha seu destino, jovem padawan. Sempre lembrando que independente do caminho que decidir trilhar, você deve pelo menos entender os outros assuntos para se tonar um jedi.

Você acabou de chegar na empresa, te deram um computador novo e você tem que configurá-lo. Instale o arduino e faça uma pesquisa sobre modelos de arduino, shields e sensores.

### Tasklist

* [ ] Instalação IDE

* [ ] Pesquisa dispositivos
