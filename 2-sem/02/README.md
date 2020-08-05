# Aula 2 - Configuração inicial do rasp e comandos Linux básicos.

## Conteúdo

Nessa aula veremos a configuração inicial do raspberry pi, além de alguns comandos bastante úteis para nosso estudo.

Após instalar a ISO no sdcard, abra-o no seu computador e crie um arquivo em branco com o nome `ssh` (sem extensão). Este arquivo irá habilitar o ssh. Na sequência, crie outro arquivo chamado `wpa_supplicant.conf` e utilize o modelo abaixo com sua rede wifi:

```
country=BR
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1

network={
  scan_ssid=1
  ssid="NOME_DA_REDE"
  psk="SENHA_DA_REDE"
}
```

Agora vamos ligá-lo e acessá-lo, com um teclado e um monitor diretamente ligados no rasp. Após se logar com o usuário padrão `pi:raspberry`, conecte-se à internet (via cabo ou wifi) e abra um terminal.

Nós poderíamos fazer tudo por aqui, mas, por comodidade, vamos apenas pegar o endereço de ip e habilitar o ssh para nos conectarmos remotamente. Para começar, digite o comando `ip a` para verificar seu ip.

Caso tenha se conectado por wifi à interface associada, seu ip será algo como wlp6s0 ou wlan0. Se a conexão acontecer por cabo, então teremos algo como enp12s0 ou eth0.

Atenção: anote esse ip.

Agora que temos o endereço de ip e habilitamos o ssh, poderemos nos conectar assim daqui para frente, sem a necessidade de plugar mil coisas no rasp. Supondo que seu ip seja 192.168.0.13, digite no seu pc/note:

`sudo systemctl enable ssh`

- OBS: Caso utilize o Linux, é bem provável que ele já tenha ssh, mas, se você usar o Windows, ~~deveria usar o Linux~~ pode usar o Putty:

`ssh pi@192.168.0.13`

Após colocar a senha, você já estará logado e poderemos assim continuar a configuração. Digite o comando [sudo raspi-config](https://www.raspberrypi.org/documentation/configuration/raspi-config.md) para que possamos configurar o nosso terminal.

A maior parte das opções disponíveis nessa ferramenta são possíveis de se configurar "na mão", porém o raspi-config nos provê uma interface mais facilitada para isso. Você pode navegar no menu que abrirá usando as setas, o ENTER e o ESC. Dispomos então das seguintes opções:

```
│        1 Change User Password     Alterar senha do usuário
│        2 Network Options          Configurações de rede
│        3 Boot Options             Configurações de boot
│        4 Localisation Options     Configurações regionais de data, hora e idioma
│        5 Interfacing Options      Configurações de interfaces e periféricos
│        6 Overclock                O nome já diz...
│        7 Advanced Options         Configurações avançadas
│        8 Update                   Faz um update
│        9 About raspi-config       Mostra uma ajuda sobre o raspi-config
```

Ao iniciar seu raspi pela primeira vez, é interessante alterar a senha (ou criar outro usuário), configurar o acesso à rede, colocar os locales corretos (caso não estejam), mudar o hostname e fazer um update.

Vamos relembrar alguns comandos de Linux que nos ajudarão no dia-a-dia:

OBS: Comandos com o prefixo `$` podem ser rodados por usuários normais, enquanto comandos prefixados com `#` devem ser executados como root.

* Navegar entre pastas (dica: aperte TAB para ver os caminhos disponíveis de sua pasta atual):

`$ cd /caminho/x`

* Verificar o endereço IP, MAC e outras informações de interfaces:
  `$ ip a`

* Virar root:
  `$ sudo -i`

* Atualizar source lists e pacotes:
  `# apt update && apt upgrade`

* Conexão por SSH por senha:
  `$ ssh user@host_ou_ip`

* Gerenciar serviços:

  - Verificar o status:
    `# systemctl status nome_do_serviço`

  - Iniciar o serviço:
    `# systemctl start nome_do_serviço`

  - Parar o serviço:    
    `# systemctl stop nome_do_serviço`

  - Habilitar o serviço na inicialização do sistema operacional:
    `# systemctl enable nome_do_serviço`

  - Desabilitar o serviço na inicialização do sistema operacional:
    `# systemctl disable nome_do_serviço`

* Caso queira ver processos associados a alguma porta, utilize o ss:
  `# ss -tupln`

* Não sabe o que certo comando faz? Dê uma olhada no manual:
`$ man nome_do_comando`

## Outras features do rasp

O Raspberry já vem com algumas outras ferramentas bem legais, como bluetooth, conexões para displays e câmera, além dos 40 GPIOs (general-purpose input/output) disponíveis para conectar sensores e módulos.

Um ponto bacana disso é poder usar python no lugar de C++, o que em muitos casos, porém, não será preciso, uma vez que, quando se tratar de coisas consideradas mais simples, na maioria das vezes um arduino já poderá resolver seu problema.

![GPIO](../../img/2sem/02/gpio.jpg)

## Desafio

### User story

Na segunda semana você foi incubido de configurar o raspberry junto com a Jane, para prosseguir com a fase de desenvolvimento.

### Tasklist

* [ ] Configurar o hostname

* [ ] Alterar o boot para iniciar com o CLI pedindo logins

* [ ] Atualizar o sistema

* [ ] Alterar a senha

* [ ] Configurar locales (data, hora, teclado)

## Referências e recursos úteis

[Pagina oficial do Raspberry pi](https://www.raspberrypi.org/)

[Download Raspian image](https://www.raspberrypi.org/downloads/)

[Documentação sobre GPIO](https://www.raspberrypi.org/documentation/usage/gpio/)

[raspi-config](https://www.raspberrypi.org/documentation/configuration/raspi-config.md)
