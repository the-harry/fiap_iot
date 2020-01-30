# Aula 7 - Funções e retornos.

## Conteúdo
Funcoes servem para separar nosso codigo e dar mais significado aos trecos de codigos, isso sem contar que nos ajuda a ter um codigo menos repetitivo(DRY - Dont Repeat Yourself). Claro que poderiamos fazer instrucao por instrucao as repetindo infinitamente, mas isso provavelmente ficaria muito pesado, demorado, e faria um inferno a vida da proxima pessoa que pegasse para cuidar do projeto.
O ato de declarar uma funcao eh bem parecido com o de declarar uma variavel, colocamos o tipo da funcao, seguido de um nome e dentro fazemos nosso codigo. Talvez voce esteja se perguntando, mas o que seria esse tipo da funcao? A ideia eh que uma funcao execute uma quantidade finita de passos e retorne algum valor, o tipo do retorno da funcao eh o que usamos como base para declarar seu tipo, por exemplo, imagine que temos uma funcao que recebe dois numeros inteiros, os soma e retorna o valor. Podemos declarar essa funcao assim:

```
int soma(int a, int b) {
  return a + b;
}
```

No caso acima a pegamos a e b, e retonamos o resultado, sempre que colocamos a palavra return no meio de uma funcao ela sai dessa funcao e nao executa as linhas abaixo. Por exemplo:

```
int soma(int a, int b) {
  return a + b;

  return a - b;
}
```

O codigo acima teria o mesmo resultado do primeiro, porque nao eh possivel chegar no segundo return uma vez que a funcao foi terminada. E para chamarmos nossa funcao apos ser declarada eh so fazer isso:

```
soma(3, 6);

> 9
```

Porem nem toda funcao tem um retorno, muitas funcoes, como o proprio setup e loop que sao declaras com um void na frente e nao possuem a palavra return dentro dela, funcoes void, funcoes sem retorno, servem para executar algo dentro dela mas sem retornar nada. Imagine que temos uma funcao que desliga um motor:

```
void desliga() {
  digitalWrite(MOTOR_PIN, LOW);
}
```

Essa funcao nao precisa me retornar nada, apenas desligar um motor, entao nesses casos podemos usar o void.

Uma observacao importante quando falamos de funcoes, sao os escopos, ou namespaces, ao declarar uma variavel dentro de uma funcao ela so existira la, caso tente chama-la de fora recebera um erro falando que ela nao existe, apenas variaveis globais podem ser chamadas em qualquer lugar, uma variavel global eh declarada fora da funcao, geralemtne no inicio do codigo.
Mas evitem colocar tudo como variaveis globais pois isso nao eh muito bacana, ja que eh mais facil alterar algo que nao deveria ser alterado, sempre que possivel use funcoes, e deixe exposto apenas variaveis que realmente sao usadas em varios lugares.


## Desafio

### User history



### Tasklist

* [ ]
* [ ]
* [ ]
