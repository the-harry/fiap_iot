# Aula 8 - Destrinchando o git.

## Conteúdo

clone
status
commit
push
pull

branchs
MR/PR

gitlab/github/bitbucket


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

## Desafio

### User history


### Tasklist

* [ ]
