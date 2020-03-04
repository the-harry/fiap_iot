# Aula 7 - Funções e retornos.


## Conteúdo

## Declarar e chamar funcoes

Funcoes sao um bloco de codigo que eh executado quando chamado, primeiro declaramos uma funcao e colocamos seu conteudo, e posteriormente fazemos a chamada de fato.
Funcoes servem para separar nosso codigo e dar mais significado aos trecos de codigos, isso sem contar que nos ajuda a ter um codigo menos repetitivo(DRY - Dont Repeat Yourself). Claro que poderiamos fazer instrucao por instrucao as repetindo infinitamente, mas isso provavelmente ficaria muito pesado, demorado, e faria um inferno a vida da proxima pessoa que pegasse para cuidar do projeto.
O ato de declarar uma funcao eh bem parecido com o de declarar uma variavel, colocamos o tipo da funcao, seguido de um nome e dentro fazemos nosso codigo. Talvez voce esteja se perguntando, mas o que seria esse tipo da funcao? A ideia eh que uma funcao execute uma quantidade finita de passos e retorne algum valor, o tipo do retorno da funcao eh o que usamos como base para declarar seu tipo, por exemplo, imagine que temos uma funcao que recebe dois numeros inteiros, os soma e retorna o valor. Podemos declarar essa funcao assim:

```cpp
int soma(int a, int b) {
  return a + b;
}
```

Podemos chamar a funcao acima da seguinte maneira:

```cpp
soma(1, 2);
```

O que me retornaria 3.

Uma funcao pode ou nao receber argumentos, que sao variaveis que serao usadas dentro da funcao e depois destruidas, no exemplo acima a e b sao argumentos. Poderiamos escrever a mesma funcao sem argumentos caso tenhamos todos os valores dentro dela:

```cpp
int soma() {
  a = 1;
  b = 2;

  return a + b;
}
```

No caso para chamar essa funcao seria:

```cpp
soma();
```
O que tambem nos retornaria 3. Reparem que sem os argumentos nossas funcoes ficam bem mais "engessadas", se quisessemos calcular outros valores teriamos que modificar a funcao, o que nao eh muito pratico.

No caso acima a pegamos a e b, e retonamos o resultado, sempre que colocamos a palavra return no meio de uma funcao ela sai dessa funcao e nao executa as linhas abaixo. Por exemplo:

```cpp
int soma(int a, int b) {
  return a + b;

  return a - b;
}
```

O codigo acima teria o mesmo resultado do primeiro, porque nao eh possivel chegar no segundo return uma vez que a funcao foi terminada. E para chamarmos nossa funcao apos ser declarada eh so fazer isso:

```cpp
soma(3, 6);

> 9
```

Poderiamos fazer a mesma coisa para somar numeros reais:

```cpp
float soma(float a, float b) {
  return a + b;
}
```

No caso usamos float mas poderiamos ter usado double tambem.

Porem nem toda funcao tem um retorno, muitas funcoes, como o proprio setup e loop que sao declaras com um void na frente e nao possuem a palavra return dentro dela, funcoes void, ou funcoes sem retorno, servem para executar um bloco de codigo dentro dela mas sem retornar nada. Imagine que temos uma funcao que desliga um motor:

```cpp
void desliga() {
  digitalWrite(MOTOR_PIN, LOW);
}
```

Essa funcao nao precisa me retornar nada, apenas desligar um motor, entao nesses casos podemos usar o void.

Outro recurso interessante no C++ eh o `Function Overload`, que nos permite criar a mesma funcao com mais de um tipo diferente. Imagine que temos dois metodos, um para somar inteiros, e outro para somar reais, ficaria algo assim:

```cpp
int somaInt(int a, int b) {
  return a + b;
}

float somaFloat(float a, float b) {
  return a + b;
}
```

A chamada ficaria assim:

```cpp
somaInt(3, 3);

somaFloat(3.3, 3.3);
```

Para fazer essas contas seriam chamadas diferentes, logo teriamos que saber com que tipo de numero estamos lidando para poder fazer a conta. Mas gracas ao `Function Overload` podemos declarar a mesma funcao com dois tipos diferentes e fazer a mesma chamada:

```cpp
int soma(int a, int b) {
  return a + b;
}

float soma(float a, float b) {
  return a + b;
}
```

A chamada ficaria assim:

```cpp
soma(3, 3);

soma(3.3, 3.3);
```


## Escopos

Uma observacao importante quando falamos de funcoes, sao os escopos, ou namespaces, ao declarar uma variavel dentro de uma funcao ela so existira la, caso tente chama-la de fora recebera um erro falando que ela nao existe, apenas variaveis globais podem ser chamadas em qualquer lugar, uma variavel global eh declarada fora da funcao, geralemtne no inicio do codigo.
Mas evitem colocar tudo como variaveis globais pois isso nao eh muito bacana, ja que eh mais facil alterar algo que nao deveria ser alterado e sem contar um monte de memoria disperdicada que armazenara informacoes que nao sao mais uteis, sempre que possivel use funcoes, e deixe exposto apenas variaveis que realmente sao usadas em varios lugares.
Apenas use variaveis globais caso va usar a mesma variavel ou constante em varios lugares, porem sempre que possivel prefira passar os valores necessarios por argumentos.


## Desafio

### User history

Seu squad fez recentemente um POC para o projeto petfeeder, como daremos continuidade ao projeto eh importante fazer um codigo mais limpo e legivel, junte-se com seu squad e quebre seu codigo em mais funcoes, aproveite tambem esse tempo para testar seu codigo e ir fazendo melhorias e consertando bugs.

### Tasklist

* [ ] Quebrar codigo em funcoes
* [ ] Melhorar codigo inicial
Bonus:
* [ ] Use outro mecanismo de intervalo sem ser o delay para evitar bugs com o tempo
* [ ] Repita os mesmos passos para o projeto da horta

## Referências e recursos úteis

[Explicação amigavel sobre funcoes W3C](https://www.w3schools.com/cpp/cpp_functions.asp)

[Continuacao do W3C sobre argumentos de funcoes](https://www.w3schools.com/cpp/cpp_function_param.asp)

[Explicacao sobre Function Overloading](https://www.w3schools.com/cpp/cpp_function_overloading.asp)

[Manual CPP funcoes(nao tao amigavel)](http://www.cplusplus.com/doc/tutorial/functions/)
