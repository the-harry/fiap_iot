# Aula 8 - Destrinchando o git.

## Conteúdo

## Introducao

Assim que os programas comecaram a ser escritos surgiu um problema, como controlar versoes dos codigos? Imagine que voce esta trabalhando com uma equipe desenvolvendo qualquer coisa, sua equipe tem 10 integrantes contando com voce e diariamente os 10 mexem no mesmo codigo fonte. Para lidar com esse controle de versao entre os codigos foi criado os sistemas de controle de versao, ou em ingles version control systems, eles fazem parte de uma ideia maior que eh o `gerenciamento de configuracoes de software`, `software configuration management`, ou `SCM`, que eh uma area de estudo da engenharia de software com a tarefa de rastrear e controlar mudancas em um software.
Talvez voce mesmo ja tenha feito um controle de versao com algum esquema de criar pastas `projeto1`, `projeto2`, `projeto3`,`projetoagoravai`, e os sistemas de controle de versao nos livram disso. Com eles podemos misturar versoes diferentes de codigos, fazer rollbacks(voltar alguma mudanca), entre muitas outras ferramentas uteis que essas ferramentas nos disponibilizam.
Antigamente os projetos eram gerenciados em pacotes tarball, que era basicamente criar um arquivo compactado com o codigo daquela versao.  

##  Historia dos sistemas de controle de versão

Existem varios sistemas de controle de versao, porem atualmente o mercado usa o git como padrao. Mas nem sempre foi assim, antes era comum empresas usarem o `svn`, `mercurial`, porem eles eram mais dificeis de usar, tanto que existia uma profissao para o controlador de versao, cujo trabalho era fazer commits e releases o dia todo.
O git foi criado em um ato de revolta do Linus Torvalds, criador e mantedor do kernel linux, pois segundo ele todas as ferramentas da epoca eram horriveis, mas ele conseguia ainda se contentar com uma empresa chamada `BitKeeper`, que tambem eh uma ferramenta de controle de versao, porem eh uma solucao proprietaria. No inicio ela permitia uso gratis para projetos opensource, mas depois quis cobrar. A resposta do Linus na epoca, foi: "Eu faco algo melhor que isso em 2 semanas!", e ele fez.

O principal do git que foi o que matou seu concorrentes, foi o fato de ele trabalhar com um sistema distribuido ao invez de um centralizado, o que significa que cada maquina com uma copia do repositorio se torna como se fosse um servidor, ao invez de ter um servidor centralizado onde todo controle deve ser feito la. Isso da mais seguranca para trabalhar, ja que mesmo que voce estrague tudo que tem em sua maquina ainda eh possivel puxar o que existe em outra maquina qualquer.

## Git o que?

Voces ja conhecem o `github` e provavelmente ja deve ter ouvido falar do `gitlab`, `bitbucket`, entre outros sites similares, todos eles sao interfaces graficas para a ferramenta git. Porem eles funcionam um pouco diferentes. Nas nossas aulas vamos usar o github, porem o gitlab eh muito utilizado no mercado de trabalho. Outras opcoes como bitbucket nao sao muito utilizadas atualmente, antes ainda havia uma certa concorrencia pelo fato do github cobrar para criar repositorios privados, enquanto os concorrentes nao cobravam, porem atualmente eles nao cobram mais, o que enfraqueceu os concorrentes.

## Uso basico

Certo, entendemos que vamos usar a ferramenta git com o github para gerenciar as mudancas de nosso projeto, primeira coisa que temos que fazer eh instalar o git na nossa maquina, caso use linux apenas use seu gerenciador de pacotes preferido e o instale, usando o apt: `sudo apt install git`.
Caso use windows eh preciso instalar o (gitbash)[]

glossario:
branchs
remote
commit

clone
status
commit
push
pull

## Na pratica

Vou criar um repositorio novo para fazermos alguns testes na pratica para deixar esse fluxo de trabalho mais claro. Faremos um projeto que lera uma tecla digitada no teclado matricial e imprimira na porta serial esse valor. Primeiro vamos realizar a conexao dos fios, o teclado matricial funciona como uma matriz como o proprio nome diz, os quatro primeiros fios da esquerda representam as linhas e os tres ultimos as colunas. Ao pressionar um botao ele nos retorna um valor da matriz.

!wiring

Primeiro vou criar uma pasta para guardar o projeto chamado `demo_keyboard`, gosto de criar uma pasta chamada `workspace` dentro da home do usuario, e dentro dela colocar meus projetos:

```bash
mkdir demo_keyboard

cd demo_keyboard

echo "Demo Keyboard" > README.md
```

Apos criar a pasta do projeto e um README com as informacoes dele podemos comecar a desenvolver. Existem 3 solucoes principais para lidar com esses teclados matriciais, vamos comecar com a mais dificil e ir facilitando, a ideia eh controlarmos a versao do nosso codigo durante o processo, entao antes de comecar com o codigo principal vamos iniciar o repositorio e commitar essas alteracoes, para isso crie um repositorio no github e siga as instruções para fazer o primeiro commit:

```bash
git init
git add README.md
git commit -m "first commit"
git remote add origin git@github.com:matheusam/demo_keyboard.git
git push -u origin master
```

Apos fazer isso seu projeto ja estara no github, vamos a primeira solucao. Crie um arquivo chamado `demo_keyboard.ino`:

```bash
touch demo_keyboard.ino
```

A primeira solucao consiste em verificar linah por linha e coluna por coluna usando varios if's para achar qual botao foi apertado, tambem eh utilizado um conceito chamado interrupt, um interruptor em C/CPP eh uma maneira de parar o processamento atual para realizar outra tarefa que chegou, por exemplo um botao pressionado. Porem nao se preocupem com interruptores ainda.

```cpp

```

Etapas:
Baixar e instalar o git
Criar chave ssh
clonar o projeto
fazer as alteracoes e enviar para o remote
atualizar seu projeto local

git clone endereco@repositorio.git - baixa o projeto

git status - verifica status das alteracoes no projeto atual

git add nome_arquivo - comeca rastrear as mudancas do nome_arquivo
git add . - Adionar todos arquivos daquela pasta

git commit -m "mensagem do commit" - Um commit eh um conjunto de alteracoes que foram adiionadas, ao fazer esse comando ele pegara todas as alteracoes adicionadas no passo anterior e criar um conjunto de alteracoes

git push origin master - o comando push envia seu commit local para o repositorio remoto, os proximos argumentos depois do push sao o remote(99% das vezes sera origin) e a branch (que no nosso caso eh a master que eh a principal)



git pull origin master - Traz as alteracoes da branch master no repositorio remoto para a sua branch local, caso tenham mudancas no mesmo lugar, o git vai reclamar falando que tem um conflito, escolha qual das alteracoes deve permanecer

O git pull eh a combinacao de dois comandos, o fetch e o merge. O git fetch traz as alteracoes mas nao as aplica no seu codigo, o merge eh o cara que junta tudo, quando damos um pull ele busca as alteracoes e ja aplica para nos.


## Boas praticas para gerenciar seu projeto

branchs
MR/PR

## Desafio

### User history

Seu time fez dois projetos ate agora, organize seus projetos no github com seu time, configure o acesso de todos os membros, e escreva um README.md para cada projeto. Nas proximas aulas a cada melhoria nos projetos vamos commita-las no git. Lembre-se de salvar tudo, usaremos esses projetos no semestre que vem tambem!
Aproveite esse tempo para melhorar alguma coisa no codigo e treinar trabalhar com branchs e PRs.

### Tasklist

* [ ] Criar conta no github caso nao tenha ainda e configura-la.

* [ ] Criar repositorio do projeto petfeeder e subir os codigos.

* [ ] Criar repositorio do projeto horta e subir os codigos.

* [ ] Criar um readme para cada projeto.

* [ ] Criar o projeto tranca com um readme inicialmente

* [ ] Abrir um Pull Request com o codigo da implementacao da autenticacao por teclado para que possamos revisa-lo


## Referências e recursos úteis

[Palestra do Linus Torvalds no google sobre o git](https://www.youtube.com/watch?v=4XpnKHJAok8)

[Git cheat sheet](https://github.github.com/training-kit/downloads/pt_BR/github-git-cheat-sheet/)

[Documentacao completa do git](https://git-scm.com/doc)

[Comparacao dos sistemas de controle de versao](https://biz30.timedoctor.com/git-mecurial-and-cvs-comparison-of-svn-software/)

[Boas praticas no git](https://deepsource.io/blog/git-best-practices/)
