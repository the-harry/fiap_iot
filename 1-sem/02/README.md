# Aula 2 - Introdução a logica de programação

## Logica de programação

O primeiro passo para aprender a programar eh desenvolver um pensamento logico, todos os dias usamos logica mesmo sem perceber, quando voce toma qualquer decisao, voce pensa sobre aquilo e procura achar a melhor solucao, correto? Eh exatamente esse processo que faremos para criar nossos programas. Sempre que temos que fazer algo passamos basicamente por duas etapas:

- Descobrir o que precisamos Fazer

- Criar uma maneira de fazer

Para programar eh a mesma ideia, primeiro precisamos entender o problema para procurar uma solucao. E uma caracteristica muito interessante, eh que quando se trata de logica temos varias maneiras de fazer a mesma coisa, o que nos da varias possibilidades diferente de respostas, e nao uma verdade absoluta, porem nem toda solucao eh correta.
Quando resolvemos um problema podemos faze-lo de varias maneiras, podemos fazer uma solucao rapida que pode nao ser tao boa mas resolve nosso problema, podemos ter a solucao "ideial" para o que precisamos, mas ela pode ser mais demorada... E nem sempre o segundo jeito eh melhor, claro que quanto mais clara, limpa e performatica for a solucao eh melhor, mas muitas vezes nao temos o tempo necessario.

Muitas pessoas colocam os carros na frente dos bois quando estao aprendendo a programar, e ja pulam direto para alguma linguagem de programacao, comecam a ler os manuais e entender a sintaxe dos comandos, mas isso eh como construir um predio de cima para baixo, todas as linguagens de programacoes que sao consideradas `turing complete` usam a mesma base logica porem a maneira de se escrever eh um pouco diferente entre elas.
O termo vem do nome do matematico e pioneiro em logica de programacao Alan Turing que inventou a maquina de turing, que era capaz de resolver problemas matematicos caso voce soubesse a programar. A ideia basica eh que essas linguagens devem oferecer recursos como controles condicionais, e de repeticao, devem ser capaz de ler algum tipo de dado armazenado, como variaveis.
Por exemplo, C, C++, Ruby, Python, Perl, Clojure entre muitas sao turing complete, porem outras linguagem de marcacao como HTML e MARKDOWN(linguagem que esse documento foi escrito) nao sao turing complete, pois nao nos oferencem esses recursos.


## Algoritimos

Não podemos falar de programação sem falar de algoritimos, um algoritimo nada mais é do que uma sequência finita de regras e operações. Para nós muitas vezes algumas coisas simples do nosso dia-a-dia se tornam automáticas, e acabamos esquecendo de todos os passos necessarios mas sabemos intuitivamente o que temos que fazer, podemos ate alegar ser "algo implícito", porém um computador não tem esse raciocínio, ele simplesmente faz o que lhe é ordenado, por isso quando comecarmos a desenvolver temos sempre que pensar da maneira mais detalhada possivel. Então é importante que os nossos algoritimos sejam bem planejados, e que cubram o maior número de casos possíveis, caso seja viável.

Imagine que você quer um suco de laranja, o que você faria? Cada passo até chegar no produto final seria uma etapa do seu algoritimo, em programação lógica é a coisa mais importante de todas, entendendo a lógica se entende quase todas as linguagens de programação, entendendo a lógica sintaxe será o menor dos seus problemas.

## Diagrama de blocos

Diagrama de blocos, é uma maneira que nos ajuda a modelar nossos sistemas(na verdade várias coisas que podem ser representadas por fluxos). UML é uma linguagem de blocos que nos ajuda a fazer o desenho de uma solução.
Como falamos anteriormente é muito importante projetar nosso código antes de faze-lo, para que não criemos nenhum Frankstein. Com UML podemos fazer isso facilmente.

Confira a imagem a seguir com os principáis símbolos:

![diagrama](../../img/1sem/02/diagrama_blocos.png)


exemplo do suco de laranja


## Desafio

### User history

Seu time começará a projetar um protótipo de uma solução para automatizar hortas domésticas, você deve se reunír com seu grupo e planejar como será a lógica desse projeto. Os únicos requesitos pedidos foram:

* A solução deve monitorar luminosidade, temperatura, umidade do solo

* Deve automatizar a irrigação


### Tasklist

* [ ] Fazer UML para problema descrito acima.
