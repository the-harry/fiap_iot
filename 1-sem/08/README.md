# Aula 8 - Destrinchando o git.

## Conteúdo

## Introducao

Assim que os programas comecaram a ser escritos surgiu um problema, como controlar versoes dos codigos? Imagine que voce esta trabalhando com uma equipe desenvolvendo qualquer coisa, sua equipe tem 10 integrantes contando com voce e diariamente os 10 mexem no mesmo codigo fonte. Para lidar com esse controle de versao entre os codigos foi criado os sistemas de controle de versao, ou em ingles version control systems, eles fazem parte de uma ideia maior que eh o `gerenciamento de configuracoes de software`, `software configuration management`, ou `SCM`, que eh uma area de estudo da engenharia de software com a tarefa de rastrear e controlar mudancas em um software.
Talvez voce mesmo ja tenha feito um controle de versao com algum esquema de criar pastas `projeto1`, `projeto2`, `projeto3`,`projetoagoravai`, e os sistemas de controle de versao nos livram disso. Com eles podemos misturar versoes diferentes de codigos, fazer rollbacks(voltar alguma mudanca), entre muitas outras ferramentas uteis que essas ferramentas nos disponibilizam.
Antigamente os projetos eram gerenciados em pacotes tarball, que era basicamente criar um arquivo compactado com o codigo daquela versao.  

##  Historia dos sistemas de controle de versão

Existem varios sistemas de controle de versao, porem atualmente o mercado usa o git como padrao. Mas nem sempre foi assim, antes era comum empresas usarem o `svn`, `mercurial`, porem eles eram mais dificeis de usar, tanto que existia uma profissao para o controlador de versao, cujo trabalho era fazer commits e releases o dia todo.
O git foi criado em um ato de revolta do Linus Torvalds, criador e mantedor do kernel linux, pois segundo ele todas as ferramentas da epoca eram horriveis, mas ele conseguia ainda se contentar com uma empresa chamada `BitKeeper`, que tambem eh uma ferramenta de controle de versao, porem eh uma solucao proprietaria. No inicio ela permitia uso gratis para projetos opensource, mas depois quis cobrar. A resposta do Linus na epoca, foi: "Eu faco algo melhor que isso em 2 semanas!", e ele fez.

O principal do git que foi o que matou seu concorrentes, foi o fato de ele funcionar como um sistema distribuido ao invez de um centralizado, o que significa que cada maquina com uma copia do repositorio se torna como se fosse um servidor, ao invez de ter um servidor centralizado onde todo controle deve ser feito la. Isso da mais seguranca para trabalhar, ja que mesmo que voce estrague tudo que tem em sua maquina ainda eh possivel puxar o que existe em outra maquina qualquer.

## Git o que?

Voces ja conhecem o `github` e provavelmente ja deve ter ouvido falar do `gitlab`, `bitbucket`, entre outros sites similares, todos eles sao interfaces graficas para a ferramenta git. Porem eles funcionam um pouco diferentes. Nas nossas aulas vamos usar o github, porem o gitlab eh muito utilizado no mercado de trabalho. Outras opcoes como bitbucket nao sao muito utilizadas atualmente, antes ainda havia uma certa concorrencia pelo fato do github cobrar para criar repositorios privados, enquanto os concorrentes nao cobravam, porem atualmente eles nao cobram mais, o que enfraqueceu os concorrentes.

## Uso basico

Certo, entendemos que vamos usar a ferramenta git com o github para gerenciar as mudancas de nosso projeto, primeira coisa que temos que fazer eh instalar o git na nossa maquina, caso use linux apenas use seu gerenciador de pacotes preferido e o instale, usando o apt: `sudo apt install git`.
Caso use windows eh preciso instalar o [gitbash](https://git-scm.com/download/win), que fora fornecer o git nos diponibiliza alguns comandos do linux para trabalhar mais facilmente.

#### Glossario:

* branch: Eh uma ramificacao do seu projeto, uma versão criada a partir de outra branch. A principal branch eh a `master`, imagine ela como o tronco da nossa arvore, e as outras branchs como galhos.

* remote: Eh o endereco do nosso repositorio remoto, como o nome diz. Ele tem uma url e um apelido, o mais comum de vermos eh o `origin`, que eh o nome dado automaticamente para o primeiro remote.

* commit: Representa uma alteracao no codigo que entra para a arvore do nosso projeto.

* clone: `git clone git@github.com:matheusam/fiap_iot.git` baixa um projeto.

* status: `git status` mostrao status atual dos arquivos. Quando um arquivo sofre uma alteracao ele ficara vermelho, depois disso voce pode commitar essa mudanca adicionando o arquivo aos arquvios rastreados daquele commit ou descartar as alteracoes.

* add: `git add file.c` adiciona um arquivo as mudancas que vamos commitar.

* commit: `git commit -m "Mensagem do commit."` para fazer um commit voce precisa escrever uma mensagem sobre oque foi feite, procure ser breve e claro.

* push: `git push origin master` Envia suas alteracoes da branch master para o remote.

* pull: `git pull origin master` Atualiza a sua branch master, o pull na verdade eh a uniao do comando `fetch` que busca as alteracoes e traz para sua maquina, e o `merge`, que aplica as alteracoes.


## Na pratica

Para praticar o que vimos hoje, vou criar um projeto para acender um led quando apertarmos um push button. Depois voces farao isso no projeto da horta, para que quando o botao for pressionado ele ative a irrigacao manualmente. Primeiro vamos entender um push button:

Ao apertar o botao o contato se fecha e passa a energia de A para D ou de B para C.

![Button](../../img/1sem/08/button.png)

Geralmente se utilizam resistores juntos aos push buttons, para evitar que ruidos ativem ele sem querer.

Podemos usar um modulo de arduino que faz isso, e segue o seguinte esquema:

![Push Button Module](../../img/1sem/08/pb_module.png)

Vamos comecar nosso codigo apenas acendendo o led, daqui a pouco implementamos o botao:

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

Acesse o github e crie uma conta caso ainda nao tenha.

Instale o git na sua maquina.

Crie um novo projeto no github. Ao criar um projeto sem arquivos ele vai te mostrar um bloco de comandos como os a seguir:

```bash
# inicia um repositorio git
git init
# adiciona o arquivo readme para ser commitado, adicione os arquivos que precisar
git add botao.ino
# primeiro commit do projeto
git commit -m "first commit"
# Adiciona o remote, so eh preciso esse comando a primeira vez
git remote add origin git@github.com:seu_user/nome_do_projeto.git
# envia as mudancas para o servidor, o -u so precisa na primeira vez para sincronizar
git push -u origin master
```

Com isso o codigo do nosso repositorio local ja estara no github. Agora vamos implementar o botao, para isso vamos criar uma branch, fazer o trabalho la e depois abrir um PR a partir dela.
Antes de comecar a nossa nova feature, vamos criar uma nova branch. A maneira mais facil de fazer isso eh usando o comando checkout com a flag b:

`git checkout -b nova_branch`

O checkout muda de branchs, passando o argumento -b ele cria a branch caso nao exista. Importante, a branch eh criada a partir da branch que voce esta, caso esteja na master, a `nova_branch` vai ser uma copia da master naquele instante, se rodar esse comando a partir da `branch_do_zezinho`, a `nova_branch` vai ter a historia do zezinho, e nao o que tem na master. Entao cuidado com isso.

Nosso codigo atualizado fica mais ou menos assim:

```cpp
// botao.ino
#define LED 13
#define BUTTON 8

void setup() {
  pinMode(OUTPUT, BUTTON);
}

void loop() {
  digitalWrite(LED, digitalRead(BUTTON));
  delay(1000);
}
```

Salve e vamos adicionar as mudancas, e fazer um commit:

```
git add botao.ino
git commit -m "Botao ativa irrigacao manual"

# nessa hora eh importante fazer o push apontando para a branch que voce criou, so que no remote
git push origin nova_branch
```

Com isso o remote tera a sua branch com seus commits, ao abrir a interface grafica voce vera que foi commitado na nova_branch e ele ja te da a opcao de abrir um PR/MR. Ness hora voce fala com qual branch quer mergear, geralmente a branch que originou a sua. No nosso caso a master.

Apos o MR/PR ter sido aberto outras pessoas devem revisar seu codigo antes de ser mergeado, assim caso algum erro passe a responsabilidade eh compartilhada. Sempre esperem o code review!


## Boas praticas para gerenciar seu projeto

Quando estamos versionando um sistema para valer, nao podemos commitar tudo na master, seria horrivel ter 20 pessoas trabalhando na mesma branch. Entao uma maneira de nao ter tantos conflitos no codigo, eh que cada um crie uma branch para fazer uma nova feature no projeto. Dessa maneira garantimos que o codigo que esta na master sempre sera um codigo estavel.

Para fazer isso pegamos a branch e criamos um MR(Merge request) ou PR(Pull request), ambos sao essencialmente a mesma coisa, porem no gitlab se chama MR e no github PR. Um pull request eh feito pela interface web. Nele vc mostra as alteracoes daquela branch em forma de [diff](https://en.wikipedia.org/wiki/Diff), e geralmente tambem se escreve um resumo explicando.

Algumas outras boas praticas no git envolvem:

* `Commits pequenos`: Faca commits pequenos e constantes, sempre tente fazer com que um commit tenha apenas um objetivo, para que a granularidade das alteracoes seja maior.

* `Escreva mensagens de commits claras`: Ao escrever o commit seja breve e claro, nao seja generico se possivel. Uma regrinha legal tambem eh a [50/72](https://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html), basicamente a mensagem nao pode passar de 50 caracteres, caso precise mais que isso, pule uma linha e continue, porem a primeira linha ainda tem que respeitar os 50 caracters, e a segunda parte apos o espaco nao pode passar de 72 caracters:

```
Alguma mensagem de commit que respeite 50 colunas

Apos pular uma linha voce pode escrever uma mensagem mais comprida.
```

* `Evite alterar a historia ja escrita`: Evite alterar a historia do projeto se possivel.

* `Nao commite arquivos gerados`: Arquivos do seu editor de texto ou qualquer coisa assim devem ser ignorados pelo arquivo `.gitignore`

* `Nunca commite na master`: Nunca commite na master, sempre puxe uma branch e mergeie usando PR/MR.

## Desafio

### User history

Seu time fez dois projetos ate agora, organize seus projetos no github com seu time, configure o acesso de todos os membros, e escreva um README.md para cada projeto. Nas proximas aulas a cada melhoria nos projetos vamos commita-las no git. Lembre-se de salvar tudo, usaremos esses projetos no semestre que vem tambem!
Aproveite esse tempo para melhorar alguma coisa no codigo e treinar trabalhar com branchs e PRs.

### Tasklist

* [ ] Criar conta no github caso nao tenha ainda e configure-a.

* [ ] Criar repositorio do projeto horta e subir os codigos.

* [ ] Abrir um Pull Request com o codigo da implementacao do push button para irrigar a horta.

* [ ] Criar repositorio do projeto petfeeder e subir os codigos.

* [ ] Criar um readme para cada projeto(petfeeder e horta). [Algumas dicas pra escrever um README top!](https://medium.com/@meakaakka/a-beginners-guide-to-writing-a-kickass-readme-7ac01da88ab3)

* [ ] Criar o projeto tranca com apenas um readme inicialmente.


## Referências e recursos úteis

[Palestra do Linus Torvalds no google sobre o git](https://www.youtube.com/watch?v=4XpnKHJAok8)

[Git cheat sheet](https://github.github.com/training-kit/downloads/pt_BR/github-git-cheat-sheet/)

[Documentacao completa do git](https://git-scm.com/doc)

[Comparacao dos sistemas de controle de versao](https://biz30.timedoctor.com/git-mecurial-and-cvs-comparison-of-svn-software/)

[Boas praticas no git](https://deepsource.io/blog/git-best-practices/)

[Gitbash download](https://git-scm.com/download/win)
