# Aula 8 - Destrinchando o git.

## Conteúdo

## Introdução

Assim que os programas começaram a ser escritos, seus criadores se depararam com uma incógnita: como controlar versões dos códigos?

Imagine que você está trabalhando com uma equipe no desenvolvendo de algo. Sua equipe, contando com você, é composta por 10 integrantes e, diariamente, todos os membros precisam mexer no mesmo código fonte. Para lidar com esse controle de versões entre os códigos, foram criados os Sistemas de Controle de Versão (em inglês Version Control Systems). Esses sistemas fazem parte de uma ideia maior, ou seja, do `Gerenciamento de Configurações de Software` (`Software Configuration Management` ou `SCM`), que aborda uma área de estudos da engenharia de software com a tarefa de rastrear e controlar mudanças em um software.

Talvez você mesmo já tenha feito, em algum momento de sua vida, um controle de versões com um esquema de criação de pastas, como: `projeto1, projeto2, projeto3, projetoagoravai`. Os sistemas de controle de versão nos livram exatamente disso, pois através deles podemos misturar diferentes versões de códigos, fazer rollbacks (ou seja, voltar alguma mudança), entre muitas outras funções bastante úteis que essas ferramentas podem nos disponibilizar. Antigamente os projetos eram gerenciados em pacotes tarball, ou seja, basicamente tratavam da criação de um arquivo, compactado com o código daquela versão.


## A história dos sistemas de controle de versão

Apesar de hoje existirem diversos sistemas de controle de versão, atualmente o mercado utiliza o git como padrão. Porém, é importante lembrar que nem sempre foi assim: há algum tempo, era comum empresas usarem o svn e o mercurial, mas, por serem mais difíceis de se utilizar (tanto que existia uma profissão específica para o controlador de versão, cujo trabalho era fazer commits e releases o dia todo), seu uso foi ficando cada vez mais ofuscado pela maior simplicidade do git.

O git foi desenvolvido por Linus Torvalds, criador e mantedor do Kernel Linux, em um ato de revolta, pois segundo ele todas as ferramentas da época eram horríveis. Neste contexto, ele conseguia ainda se contentar com uma empresa chamada BitKeeper, que também é uma ferramenta de controle de versão, porém com a diferença de se tratar de uma solução proprietária. No início, ela permitia uso grátis para projetos opensource, mas depois decidiram passar a cobrar. A resposta do Linus para isso, na época, foi: "Eu faço algo melhor que isso em 2 semanas!". E sim, ele fez.

O principal diferencial do git (aquele que matou seus concorrentes), foi o fato de ele funcionar como um sistema distribuído, e não como um centralizado. Isso significa que cada máquina com uma cópia do repositório se torna algo próximo a um servidor, ao invés de dispor de um servidor onde todo controle deve ser concentrado. Essa característica gerou mais segurança para se trabalhar porque, mesmo que você estrague tudo que tem em sua máquina, ainda assim será possível resgatar, em uma outra máquina qualquer, o que nela existia anteriormente.

## Git o que?

Vocês já conhecem o github e, provavelmente, já devem também ter ouvido falar do gitlab, do bitbucket, ou de outros sites similares. Apesar de todos eles serem interfaces gráficas para a ferramenta git, a forma como funcionam é um pouco diferente.

Em nossas aulas iremos usar o `github`, porém o `gitlab` é bastante utilizado no mercado de trabalho. Outras opções (como `bitbucket` por exemplo) não são tão utilizadas atualmente, apesar de, há algum tempo, ter havido certa concorrência entre eles. Isso se dava pelo fato do github, inicialmente, cobrar para criar repositórios privados, enquanto os concorrentes não cobravam, o que atualmente não acontece mais e acabou por enfraquecer a concorrência.

## Uso básico

Certo, entendemos que vamos usar a ferramenta git com o github para gerenciar as mudanças de nosso projeto. Sendo assim, a primeira coisa que temos a fazer é instalar o git em nossa máquina. Caso você utilize o Linux, apenas use seu gerenciador de pacotes preferido e o instale, usando o apt: `sudo apt install git`. Caso utilize o Windows, será preciso instalar o  [gitbash](https://git-scm.com/download/win), pois além de nos fornecer o git, também nos disponibiliza alguns comandos do Linux, que nos permitem trabalhar mais facilmente.

#### Glossário:

* branch: Trata-se de uma ramificação do seu projeto, ou seja, uma versão criada a partir de outra branch. A principal branch é chamada de master. É possível imaginá-la como o tronco de nossa árvore, onde as outras branches seriam os galhos.

* remote: É o endereço do nosso repositório remoto, como o próprio nome já diz. Ele possui uma url e um apelido, sendo o mais comum de vermos o `origin` (nome dado automaticamente para o primeiro remote).

* commit: Representa uma alteração no código que entra para a árvore do nosso projeto.

* clone: `git clone git@github.com:matheusam/fiap_iot.git` baixa um projeto.

* status: `git status` mostrao status atual dos arquivos. Quando um arquivo sofre uma alteracao ele ficará vermelho, depois disso você pode commitar essa mudança adicionando o arquivo aos arquivos rastreados daquele commit ou descartar as alterações.

* add: `git add file.c` adiciona um arquivo as mudanças que vamos commitar.

* commit: `git commit -m "Mensagem do commit."` para fazer um commit você precisa escrever uma mensagem sobre o'que foi feito, procure ser breve e claro.

* push: `git push origin master` Envia suas alterações da branch master para o remote.

* pull: `git pull origin master` Atualiza a sua branch master, o pull na verdade eh a união do comando `fetch` que busca as alterações e traz para sua máquina, e o `merge`, que aplica as alterações.


## Na pratica

Para praticar o que vimos hoje, criarei um projeto para acendermos um LED quando apertarmos um push button. Depois disso, vocês desenvolverão o mesmo sistema no projeto da horta, para que, quando o botão for pressionado, a irrigação possa ser ativada manualmente.

Primeiramente, vamos entender melhor um push button:

Ao apertarmos o botão, o contato se fecha e passa a energia de A para D ou de B para C.

![Button](../../img/1sem/08/button.png)

Geralmente se utilizam resistores junto aos push buttons, evitando assim que ruídos o ativem sem querer. Podemos usar um módulo de arduino que faz isso, seguindo o seguinte esquema:

![Push Button Module](../../img/1sem/08/pb_module.png)

Vamos começar nosso código apenas acendendo o LED, posteriormente implementando o botão:

```cpp
// botao.ino
#define LED 13

void setup() {
  digitalWrite(LED, HIGH);
}

void loop() {
  delay(1000);
}
```

Acesse o github e crie uma conta, caso ainda não a tenha.

Instale o git na sua máquina.

Crie um projeto no github. Ao criar esse projeto sem arquivos, ele irá te mostrar um bloco de comandos, como os que seguem abaixo:

```bash
# inicia um repositório git
git init
# adiciona o arquivo readme para ser commitado, acrescentando os arquivos que precisar
git add botao.ino
# primeiro commit do projeto
git commit -m "first commit"
# Adiciona o remote, lembrando que só será preciso executar esse comando na primeira vez
git remote add origin git@github.com:seu_user/nome_do_projeto.git
# envia as mudanças para o servidor. O -u só precisa ser usado também na primeira vez, para sincronizar
git push -u origin master
```

Com isso, o código do nosso repositório local já estará no github. Agora é o momento de implementarmos o botão e, para isso, vamos criar uma branch, fazer o trabalho lá e depois abrir um PR a partir dela.

Antes de começarmos a nossa nova feature, vamos criar uma nova branch. A maneira mais fácil de fazer isso é usando o comando checkout com a flag b:

`git checkout -b nova_branch`

O checkout muda de branchs, passando o argumento -b e criando a branch (caso ainda não exista). É importante entender que uma branch será criada a partir da branch em que você está e, caso você esteja na master, a `nova_branch` será uma cópia da master naquele instante. Caso você rode esse comando a partir da `branch_do_zezinho`, a `nova_branch` puxará o histórico do Zezinho, e não o que de fato há na master. Então é importante ter cuidado com isso.

Nosso código atualizado ficará basicamente assim:

```cpp
// botao.ino
#define LED 13
#define BUTTON 8

void setup() {
  pinMode(BUTTON, OUTPUT);
}

void loop() {
  digitalWrite(LED, digitalRead(BUTTON));
  delay(1000);
}
```

Salve tudo para podermos adicionar as mudanças e fazer um commit:

```
git add botao.ino
git commit -m "Botao ativa irrigacao manual"

# nessa hora é importante fazer o push, apontando para a branch que você criou, só que no remote
git push origin nova_branch
```

Com isso, o remote terá a sua branch com os seus commits. Ao abrir a interface gráfica, você verá que foi commitado na nova_branch e que ele já te dará a opção de abrir um PR/MR. Nesse momento, você indicará com qual branch quer mergear (que geralmente será a branch que originou a sua). No nosso caso em específico, estamos falando da master.

Após aberto o MR/PR, outras pessoas devem revisar o seu código antes de ser mergeado e, sendo assim, caso algum erro seja posteriormente detectado, a responsabilidade por isso será compartilhada.

Sempre esperem o code review!

## Boas práticas para gerenciar seu projeto

Quando estamos versionando um sistema para valer, não podemos commitar tudo na master, seria horrível ter 20 pessoas trabalhando na mesma branch. Então uma maneira de não ter tantos conflitos no código, é que cada um crie uma branch para fazer uma nova feature no projeto. Dessa maneira garantimos que o código que está na master sempre será um código estável.

Para fazer isso pegamos a branch e criamos um MR(Merge request) ou PR(Pull request), ambos são essencialmente a mesma coisa, porém no gitlab se chama MR e no github PR. Um pull request eh feito pela interface web. Nele você mostra as alterações daquela branch em forma de [diff](https://en.wikipedia.org/wiki/Diff), e geralmente também se escreve um resumo explicando.

Algumas outras boas práticas no git envolvem:

* `Commits pequenos`: Faca commits pequenos e constantes, sempre tente fazer com que um commit tenha apenas um objetivo, para que a granularidade das alterações seja maior.

* `Escreva mensagens de commits claras`: Ao escrever o commit seja breve e claro, não seja genérico se possível. Uma regrinha legal tambem eh a [50/72](https://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html), basicamente a mensagem nao pode passar de 50 caracteres, caso precise mais que isso, pule uma linha e continue, porem a primeira linha ainda tem que respeitar os 50 caracters, e a segunda parte apos o espaco nao pode passar de 72 caracters:

```
Alguma mensagem de commit que respeite 50 colunas

Após pular uma linha você pode escrever uma mensagem mais comprida.
```

* `Evite alterar a história já escrita`: Evite alterar a história do projeto se possível.

* `Não committe arquivos gerados`: Arquivos do seu editor de texto ou qualquer coisa assim devem ser ignorados pelo arquivo `.gitignore`

* `Nunca commite na master`: Nunca commite na master, sempre puxe uma branch e mergeie usando PR/MR.

## Desafio

### User story

Seu time fez dois projetos até agora, organize seus projetos no github com seu time, configure o acesso de todos os membros, e escreva um README.md para cada projeto. Nas próximas aulas a cada melhoria nos projetos vamos commit-las no git. Lembre-se de salvar tudo, usaremos esses projetos no semestre que vem também!
Aproveite esse tempo para melhorar alguma coisa no código e treinar trabalhar com branchs e PRs.

### Tasklist

* [ ] Criar conta no github caso não tenha ainda e configure-a.

* [ ] Criar repositório do projeto horta e subir os códigos.

* [ ] Abrir um Pull Request com o código da implementação do push button para irrigar a horta.

* [ ] Criar repositório do projeto petfeeder e subir os códigos.

* [ ] Criar um readme para cada projeto(petfeeder e horta). [Algumas dicas pra escrever um README top!](https://medium.com/@meakaakka/a-beginners-guide-to-writing-a-kickass-readme-7ac01da88ab3)

* [ ] Criar o projeto tranca com apenas um readme inicialmente.


## Referências e recursos úteis

[Palestra do Linus Torvalds no google sobre o git](https://www.youtube.com/watch?v=4XpnKHJAok8)

[Git cheat sheet](https://github.github.com/training-kit/downloads/pt_BR/github-git-cheat-sheet/)

[Documentacao completa do git](https://git-scm.com/doc)

[Comparacao dos sistemas de controle de versao](https://biz30.timedoctor.com/git-mecurial-and-cvs-comparison-of-svn-software/)

[Boas praticas no git](https://deepsource.io/blog/git-best-practices/)

[Gitbash download](https://git-scm.com/download/win)
