# Aula 7 - Funções e retornos.


## Conteúdo

## Declarar e chamar funções:

As Funções são blocos de códigos, que são executados quando chamados. Primeiramente, declaramos uma função e colocamos seu conteúdo e, num segundo momento, fazemos a chamada de fato. Funções servem para, além de separar nosso código e dar mais significado aos trechos de códigos, nos ajudar a ter uma codificação menos repetitiva (processo chamado DRY, ou seja, Don’t Repeat Yourself).

Claro que poderíamos desenvolver instrução por instrução, as repetindo infinitamente, mas isso provavelmente tornaria o processo muito pesado e demorado, fazendo “um inferno” na vida da próxima pessoa que se disponibilizasse a cuidar do projeto. O ato de declarar uma função é bem parecido com o de declarar uma variável, pois colocaremos o tipo da função, seguido de um nome e, dentro deste, faremos o nosso código.

Talvez você esteja se perguntando: mas o que seria esse tipo da função? A ideia é que uma função execute uma quantidade finita de passos e retorne algum valor, sendo que o tipo do retorno da função é o que utilizaremos como base para declarar seu tipo. Por exemplo: imagine que temos uma função que recebe dois números inteiros, os soma e retorna o valor. Podemos declarar essa função da seguinte forma:

```cpp
int soma(int a, int b) {
  return a + b;
}
```

Podemos chamar a função acima da forma que segue abaixo:

```cpp
soma(1, 2);
```

O que nos retornaria o valor inteiro 3.

Uma função pode ou não receber argumentos, que são variáveis que serão usadas dentro da função e depois destruídas. No exemplo acima, a e b são argumentos. Poderíamos escrever a mesma função sem estes argumentos, caso tenhamos todos os valores dentro dela:

```cpp
int soma() {
  a = 1;
  b = 2;

  return a + b;
}
```

No caso acima, para chamar essa função usaríamos:

```cpp
soma();
```
O que também nos retornaria o valor inteiro 3.

Reparem que, sem os argumentos citados, nossas funções ficam bem mais "engessadas". Caso quiséssemos calcular outros valores, teríamos que modificar a função, o que não seria muito prático.

No caso acima, pegamos a e b e retornamos o resultado, pois, sempre que colocarmos a palavra `return` no meio de uma função, ela sairá da mesma e não executará as linhas abaixo. Por exemplo:

```cpp
int soma(int a, int b) {
  return a + b;

  return a - b;
}
```

O código acima teria o mesmo resultado do primeiro, pois não será possível chegar ao segundo return, uma vez que a função em questão já foi terminada. Neste caso, para chamarmos nossa função após ser declarada, é só fazer isso:

```cpp
soma(3, 6);

> 9
```

Poderíamos utilizar o mesmo processo para somar números reais:

```cpp
float soma(float a, float b) {
  return a + b;
}
```

No caso, usamos o tipo float, mas poderíamos também ter optado pelo double.

É importante destacar que nem toda função tem um retorno. Muitas delas, como o próprio setup e loop (que são declaradas com um void na frente e, dessa forma, não possuem a palavra return dentro dela), funções void, ou mesmo funções sem retorno, servem para executar um bloco de códigos dentro dela, mas sem nos retornar nenhuma informação.

Imagine que temos uma função que desliga um motor:

```cpp
void desliga() {
  digitalWrite(MOTOR_PIN, LOW);
}
```

Essa função não precisa me retornar qualquer informação, visto que aciona apenas o desligamento do motor. Quando se tratar de um caso como este, podemos usar o void.

Outro recurso interessante no C++ é o `Function Overload`, que nos permite criar a mesma função com mais de um tipo diferente. Imagine que temos dois métodos, sendo um para somar inteiros, e outro para somar reais. Pensando nessa vertente, poderíamos desenvolver algo assim:

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

Outra observação importante, quando falamos de funções, são os escopos (ou namespaces). Ao declararmos uma variável dentro de uma função, ela somente existirá lá, caso tente chamá-la de fora. Fazendo isso, você receberá um erro falando que ela não existe, pois apenas variáveis globais podem ser chamadas em qualquer lugar.

Uma variável global é declarada fora da função, ou seja, no início do código. Mas evitem colocar tudo como variáveis globais, pois isso pode não ser  muito interessante, visto que é mais fácil alterar algo que não deveria ser alterado, sem contar a quantidade de memória desperdiçada que armazenaria informações não mais úteis. Sempre que possível faça uso das funções, deixando expostas apenas variáveis que serão realmente utilizadas em diversos lugares. Use as variáveis globais somente caso seja preciso fazer uso da mesma variável ou constante em diversos lugares. Caso seja possível, prefira sempre passar os valores necessários por meio de argumentos.


## Desafio

### User history

Seu squad fez recentemente um POC para o projeto petfeeder, que será a forma como darão continuidade ao projeto. É importante ressaltar que o melhor será desenvolver um código mais limpo e legível. Por isso, junte-se com seu squad e quebre seu código em maior quantidade de funções, aproveitando também esse tempo para testar seu código e ir fazendo melhorias e o ajuste dos bugs.

### Tasklist

* [ ] Quebrar código em funções
* [ ] Melhorar código inicial

Bônus:

* [ ] Use outro mecanismo de intervalo, sem ser o delay, para evitar bugs com o tempo
* [ ] Repita os mesmos passos para o projeto da horta

## Referências e recursos úteis

[Explicação amigável sobre funções W3C](https://www.w3schools.com/cpp/cpp_functions.asp)

[Continuação do W3C sobre argumentos de funções](https://www.w3schools.com/cpp/cpp_function_param.asp)

[Explicação sobre Function Overloading](https://www.w3schools.com/cpp/cpp_function_overloading.asp)

[Manual CPP funções(não tão amigável)](http://www.cplusplus.com/doc/tutorial/functions/)
