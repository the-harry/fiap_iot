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

`Diagrama de blocos`, ou em ingles `Sequential function chart(SFC)` eh uma linguagem de programacao grafica com todas as operacoes que precisamos para considera-la turing complete. A ideia consiste em criar o desenho para o fluxo de uma funcao, ou um pedaco de codigo do nosso programa. A ideia geral eh que baseados em uma `entrada` faremos um `processamento` e teremos uma `saida`. E descrevemos as etapas representadas por desenhos que sao ligados por fios. O diagrama de blocos nao tem simbolos para algumas coisas que queremos fazer como ler e escrever em sensores. Entao para os proximos exemplos usaremos o simbolo de entrada manual para representar a leitura de sensores e saida em impressora para representar a algum output que nao seja em telas.

Confira a imagem a seguir com os principáis símbolos:

![diagrama](../../img/1sem/02/diagrama_blocos.png)


Podemos representar nosso problema da laranja de varias maneiras, um exemplo bem simples seria:

![diagrama_laranja1](../../img/1sem/02/diagrama_laranja1.png)

Porem se formos analisar aqui para esse algoritimo funcionar de fato precisamos adicionar varias outras etapas, isso tem o nome de `granularidade`, quanto mais granular nosso sistema for, maior sera sua capacidade de lidar com diferentes eventos e problemas, no exemplo anterior poderiamos adicionar mais granularidade descrevendo melhor como comprariamos laranjas, como iriamos de casa ate o mercado? Como escolheriamos as laranjas? Todos esses passos afetariam nosso algoritimo.

Para ilustrar melhor vamos ver como ficara o diagrama de blocos do projeto pet feeder, a ideia inicial eh bem simples se detectarmos movimento perto do dispositivo ativaremos um motor que abrira o mecanismo para liberar uma quantidade de racao de um compartimento e depois fechara o motor apos algum tempo aberta.

![diagrama_pet_feeder](../../img/1sem/02/diagrama_pet_feeder.png)

Claro que isso eh apenas um prototipo, entao essa ideia deve ser melhorada, seria legal ter outros tipos de validacoes e monitoramentos mas vamos comecar de uma maneira simples e depois evoluimos a ideia. Quem sabe podemos colocar um intervalo de tempo minimo entre as alimentacoes para evitar alarmes falsos e resolver outros problemas que apareceram.

## Desafio

### User history

Seu time começará a projetar um protótipo de uma solução para automatizar hortas domésticas, você deve se reunír com seu grupo e planejar como será a lógica desse projeto. Os requesitos sao:

* A solução deve medir umidade do solo, luminosidade, temperatura e umidade do ar.

* Caso o solo esteja muito seco devemos irriga-lo

* Porem nao podemos ativar a irrigacao caso esteja com um nivel de luminosidade muito alta, o que queimaria nossas plantas


### Tasklist

* [ ] Fazer diagrama de blocos para problema descrito acima descutindo a melhor solucao com seu squad.
