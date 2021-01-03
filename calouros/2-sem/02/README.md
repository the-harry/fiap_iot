# Aula 2 - Configuração inicial do rasp e comandos Linux básicos.

## Conteúdo

Nessa aula veremos a configuração inicial do raspberry pi, além de alguns comandos bastante úteis para nosso estudo.

Após [baixar](https://www.raspberrypi.org/downloads/raspberry-pi-os/) a ISO, grave ela no sdcard, para isso use o comando `dd`, caso o sdcard nao esteja formatado, tu pode formata-lo usando alguma ferramenta como gparted e depois fazer o seguinte para copiar a imagem:

Primeiro localizamos onde esta montado nosso SDcard usando o comando `lsblk -p` que nos dara um output assim mostrando os dispositivos conectados:

```bash
NAME                  MAJ:MIN RM   SIZE RO TYPE  MOUNTPOINT
sda                     8:0    0 223.6G  0 disk  
├─sda1                  8:1    0   243M  0 part  /boot
└─sda5                  8:5    0 223.3G  0 part  
  └─sda5_crypt        254:0    0 223.3G  0 crypt
    ├─unix--vg-root   254:1    0 215.8G  0 lvm   /
    └─unix--vg-swap_1 254:2    0   7.6G  0 lvm   [SWAP]
sdb                     8:16   0 223.6G  0 disk  
├─sdb1                  8:17   0   500M  0 part  
├─sdb2                  8:18   0 222.5G  0 part  
└─sdb3                  8:19   0   574M  0 part  
mmcblk0               179:0    0  29.7G  0 disk  
```

Discos sda geralmente sao os primarios e sdb secundarios, no caso nosso sdcard eh o dispositivo `mmcblk0`.

Para copiar a imagem que baixamos vamos ate a pasta do arquivo e usamos o seguinte comando para descompactar e gravar a imagem no cartão:

OBS: O troque o nome do arquivo caso precise.

```bash
# descompactar o arquivo
unzip 2020-05-27-raspios-buster-full-armhf.zip

# gravar imagem no dispositivo

sudo dd bs=4M if=2020-05-27-raspios-buster-full-armhf.img of=/dev/mmcblk0 status=progress conv=fsync
```

Abra o SDcard no seu computador:

```bash
# para ver onde ele montou a particao
lsblk -p

NAME                              MAJ:MIN RM   SIZE RO TYPE  MOUNTPOINT
/dev/sda                            8:0    0 223.6G  0 disk
├─/dev/sda1                         8:1    0   243M  0 part  /boot
└─/dev/sda5                         8:5    0 223.3G  0 part
  └─/dev/mapper/sda5_crypt        254:0    0 223.3G  0 crypt
    ├─/dev/mapper/unix--vg-root   254:1    0 215.8G  0 lvm   /
    └─/dev/mapper/unix--vg-swap_1 254:2    0   7.6G  0 lvm   [SWAP]
/dev/sdb                            8:16   0 223.6G  0 disk
├─/dev/sdb1                         8:17   0   500M  0 part
├─/dev/sdb2                         8:18   0 222.5G  0 part
└─/dev/sdb3                         8:19   0   574M  0 part
/dev/mmcblk0                      179:0    0  29.7G  0 disk
├─/dev/mmcblk0p1                  179:1    0   256M  0 part  /media/harry/boot
└─/dev/mmcblk0p2                  179:2    0   6.6G  0 part  /media/harry/rootfs
```

Agora vamos para a particao de boot fazer uns ultimos ajustes:

```bash
cd /media/harry/boot
```

E crie um arquivo em branco com o nome `ssh` (sem extensão). Este arquivo irá habilitar o ssh.

```bash
touch ssh
```

Na sequência, crie outro arquivo chamado `wpa_supplicant.conf` e utilize o modelo abaixo com sua rede wifi:

```bash
vim wpa_supplicant.conf
```

E adicione o seguinte conteudo, coloque o nome e senha da rede:

```bash
country=BR
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1

network={
  scan_ssid=1
  ssid="NOME_DA_REDE"
  psk="SENHA_DA_REDE"
}
```

Quando estiver pronto saia e salve o arquivo, aperte `ESC`, `:wq`, `ENTER`.

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

* [ ] Acessar o raspi por ssh e colocar o nome na lista de presença

## Referências e recursos úteis

[Pagina oficial do Raspberry pi](https://www.raspberrypi.org/)

[Download Raspian image](https://www.raspberrypi.org/downloads/)

[Documentação sobre GPIO](https://www.raspberrypi.org/documentation/usage/gpio/)

[raspi-config](https://www.raspberrypi.org/documentation/configuration/raspi-config.md)
