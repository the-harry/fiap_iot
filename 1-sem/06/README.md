# Aula 6 - Controle de repetição - Loops for e while.

## Conteúdo

Muitas vezes queremos que nosso código faça algumas ações repetitivas, e não faz muito sentido escrever a mesma coisa 10x seguidas. Para isso temos controles de repetições, temos três opções disponíveis, while, for e do while. Todos eles servem para repitir algumas instruções até que uma condição seja atingida, caso isso não aconteça você acaba criando um loop infinito.
Vamos começar entendendo o loop for, ele tem a seguinte estrutura:

Geralmente usamos o for quando sabemos exatamente o numero de ciclos que temos que realizar, declaramos o loop for informando um contador que ao acabar o loop esse valor se perde, um a condição para que esse loop se repita ate que ela seja verdadeira, e por ultimo incrementamos ou decrementamos o loop usando os operadores `++` ou `--`.

Exemplo:

```
for(int i = 0; i < 10; i++) {
  Serial.print(i);
}

> 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
```

E temos o loop while, que pode ser feito de duas maneiras, similarmente ao loop for, ele realizara algo ate que a condição pare de ser verdadeira. Mas no loop while usamos um contador externo, que eh declarado antes de comecar o loop, e apos sua finalizacao o valor nao se perde. A maneira mais tradicional segue a seguinte estrutura:

```
int cont = 0 

while(count < 10) {
  Serial.print(i);
  count++;
}
```

Acima replicamos o exemplo do for porem usando o while. Caso queira fazer uma contagem ao contrario podemos simplesmente fazer:

```
int cont = 9

while(count > 0) {
  Serial.print(i);
  count--;
}
```

Repare que dessa vez usamos o operador `--`, que seria a mesma coisa que escrever `count = count -1;`.

## Desafio

### User history

Essa semana seu time está começando outro projeto em paralelo. Essa solução tem como objetivo alimentar animais domésticos que tem donos que ficam muito tempo fora de casa ou até mesmo em casos de viagem. O responsável pelo hardware criou um protótipo para isso, a ideia é usar um motor servo para abrir e fechar uma porta para liberar comida, porém ainda não foi decidido como o motor será acionado.


### Tasklist

* [ ] Refatorar o código para funcionar outro tipo de loop.
