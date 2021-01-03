# Aula 4 - Arduino getting started.

## Estrutura básica do sketch arduino

Um sketch é um arquivo do arduino com a extensão `.ino`, que funciona basicamente como um `C++`, porém com algumas funções próprias. É importante saber que o sketch deve ficar dentro de uma pasta que contenha o mesmo nome do arquino .ino. Este sketch sempre apresentará duas funções iniciais, sendo elas: `setup e loop`. No momento de execução do programa, o código começará a ser lido por ele de cima, fazendo assim a função setup uma vez no início do processo. Na sequência, a função loop é ativada e permanecerá executando os códigos dentro da função (como um loop infinito), até que haja uma interrupção.

Estrutura básica:

```cpp
void setup() {
  // aqui fica a configuração inicial, as configurações gerais, etc.
}

void loop() {
  // aqui fica a lógica principal do seu programa, que será executado em loops
  // ao iniciar o código, este passará uma vez pelo setup, fazendo assim a configuração inicial
  // depois disso, permanecerá nesse loop até que seja desligado ou haja uma interrupção.
}
```


## Tipos no C/C++

O void que aparece na frente do nome da função significa o tipo da função que será exercida, ou seja, em C/C++ temos que declarar os tipos das funções e das variáveis, o que caracteriza uma `linguagem fortemente tipada`. Os `tipos primitivos`, como são chamados, definem com que categoria de dado estamos lidando. No C, exemplo que está sendo utilizado, podemos observar os seguintes tipos:

* `void`: significa a ausência de um tipo, ou seja, é um tipo sem tipo. Na prática, usamos esse tipo apenas para declarar funções e não podemos declarar variáveis com ele. As funções do tipo void nos informam, basicamente, que ele age de algumas formas dentro daquele pedaço de código, mas não retorna nenhum valor. Caso retornasse qualquer valor, é importante entender que a função deve ser do tipo do retorno. Parece complexo, mas não há necessidade de se preocupar muito com isso neste momento, porque na aula de funções tudo ficará mais claro.

* `char`: Esse tipo armazena apenas um caractere alfanumérico. O char é muito usado para criar vetores de caracteres para a criação de textos, porém, no caso do C++, há uma biblioteca `String` que busca facilitar o desenvolvimento de textos e palavras.

* `int`: Representa os números inteiros, podendo ir de -32768 a +32767.

* `float`: Representa os números reais, ocupando 4 bytes de memória.

* `double`: Representa os números reais, assim como o float, porém ocupando 8 bytes de memória, o que nos permite ter mais casas decimais e mais precisão.

O C++ implementa estes e alguns outros tipos que deixarei na referência deste texto. mas um de grande importância que ele implementa, e ainda não citado anteriormente, é o boolean. Um valor boleano representa verdadeiro ou falso (true e false), sendo true equivalente a 1, e false igual a 0.


## Variáveis

Uma variável é, basicamente, uma caixa onde você pode guardar informações temporariamente e, ao finalizar a execução do código, perde-las completamente. Para atribuir um valor a uma variável, basta escolher um nome (de preferência que faça sentido com o contexto, para que isso também possa te ajudar a longo prazo) e atribuir um valor que seja do tipo correto.

O `C/C++` segue o estilo de linguagem de programação tipada, o que significa que, ao declarar uma variável ou função, temos que falar de qual tipo ela é, podendo ser: um número inteiro ou real, uma string (texto),um boleano (verdadeiro ou falso), entre outros. Por exemplo, para declarar a variável idade nós fazemos: `int idade = 27;`.

No exemplo anterior, como a idade é um número inteiro, não podemos simplesmente atribuir uma string ìdade = 'vinte e sete'. Isso causaria um erro, pois você tentou colocar uma string em uma variável que aceitará apenas números inteiros. Apesar disso, para permitir a manipulação dos dados, existem métodos para fazer uma conversão de tipos (caso esta seja possível).

Além das variáveis tradicionais, como as citadas anteriormente, temos também constantes, que podem ser definidas de duas maneiras: podemos declará-la usando `const` ou `#define`. O const, por exemplo, é uma variável normal que não pode ser alterada (`int const idade = 27;`).

Já o #define é feito geralmente no topo do arquivo, sendo parseado pelo pré processador antes de ser compilado e, dessa forma, troca-se o nome da definição pelo código em si. Apesar do desenvolvimento um pouco mais performático, este processo não oferece tantos ganhos assim.

O mais importante é se lembrar de que constantes não mudam de valor durante a execução do programa.

```cpp
define IDADE 27

Serial.println(IDADE)
```

Esse código, antes de ser compilado, troca todas as ocorrências de IDADE por 27, resultando em:

```cpp
define IDADE 27

Serial.println(27)
```

Diferente do const (que é tratado como uma variável convencional), este porém não pode ser alterado:

```cpp
int const idade = 27;

Serial.println(idade)
```

## Funções especiais do arduino

O arduino utiliza algumas funções especiais que não são usadas em C ou C++ puros, pois tais funções servem para situações específicas do arduino, sendo algumas delas bem comuns, como as que seguem citadas abaixo:

* `pinMode` - configura um pino do arduino como INPUT ou OUTPUT
* `digitalWrite` - envia um sinal para um pino digital (1 ou 0)
* `delay` - faz o programa parar por alguns microssegundos
* `analogRead` - lê o valor de um pino analógico (0~1023)
* `digitalRead` - lê o valor de um pino digital (0 ou 1)
* `Serial.print` - imprime algum valor na porta serial sem quebra de linha `\n`
* `Serial.println` - imprime algum valor na porta serial com quebra de linha `\n`

Caso queira ver mais métodos disponíveis, dê uma olhada [aqui](https://www.arduino.cc/reference/pt/#functions).

Exemplo para fazer um LED piscar:

```cpp
/*
  Use barra e asterisco para fazer comentários com mais de uma linha, mas
  sempre se lembrando de que um código bem escrito muitas vezes não precisa
  de comentários.
  Lembre-se sempre de dar nomes (que façam sentido) às coisas durante seu
  código, evitando linhas muito longas para não dificultar a leitura do código.
*/

// Use duas barras para fazer um comentário de uma linha.

// define o LED como sendo o pino 9
#define LED 9

// A função setup que faz a configuração inicial antes do loop principal
void setup() {
  pinMode(LED, OUTPUT); // Inicializa o LED como um pino de saida(OUTPUT)
}

// Função principal que faz um loop infinito
void loop() {
  if (digitalRead(LED) == HIGH) {   // verifica a leitura do sensor e, caso esteja ligado, o LED ele entra na linha abaixo.
    digitalWrite(LED, LOW);    // desliga o LED
  } else {
    digitalWrite(LED, HIGH);   // liga o LED
  }

  delay(1000);                 // espera um segundo e começa novamente
}
```

## Conexao serial e baudrate

Quando queremos usar a comunicação serial do arduino utilizando métodos da classe Serial, precisamos primeiramente definir no setup qual será seu baudrate.

O baudrate é uma unidade de medida, que representa o número de pulsos por segundo, ou seja, o número de bits por segundo, sendo possível com ele definirmos qual será a nossa velocidade de transmissão. Entretanto, é importante saber que não podemos escolher esses valores arbitrariamente, pois temos primeiro que saber a velocidade da nossa placa. Para esta velocidade, existem alguns valores padrão: `300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 38400, 57600, e 115200`.

É essencial que você sempre se aprofunde mais sobre as informações do modelo de sua placa. Nas aulas usaremos o arduino uno, que opera com 9600 baud. Caso faça a escolha errada da placa, é bem provável que você tenha problemas para enviar e receber dados.

Podemos nos valer dos códigos a seguir para facilmente executarmos diversos comandos de transmissão de dados, como: o comando `Serial.println("minha transmissão");` para ler informações que chegam via serial, o comando `Serial.read();` para  ler um caractere ou o comando `Serial.readString();` para ler uma string.

Segue exemplo de comunicação serial no arduino:

```cpp
void setup() {
  Serial.begin(9600);          // inicia a comunicação serial com 9600 baud
}

void loop() {
  if (Serial.available() > 0) {   // caso tenha algo vindo na serial
    char caractere;               // declara uma variável tipo char, para guardar o caractere que está chegando
    caractere = Serial.read();    ////atribui ao valor lido pela serial à variável caractere
    if (caractere != '\n') {      // verifica se o caractere que chegou não é uma quebra de linha, lembrando que ela pode ser um `\n ou \r`
      Serial.println(caractere);  // caso seja mesmo um caractere, ele o imprime no serial, devolvendo assim o que mandamos a ele
    }
  }
  delay(1000); // espera um segundo e recomeça o processo
}
```

## IO - Entendendo os sensores e atuadores

Atualmente temos diversos tipos de sensores, que se dividem em alguns subtipos básicos, tendo cada um deles as suas particularidades. Estes sensores sempre serão `analógicos ou digitais` (lembrando que os digitais medem 0 e 1, e os analógicos 0~1023). Alguns sensores funcionam usando apenas os comandos do arduino, enquanto outros dependem de alguma lib para funcionar corretamente.

Ao importar uma lib no topo do código, é criado um objeto que representa aquela lib para podemos utilizar o sensor, como é o caso do `DHT11`. Um sensor serve para pegar métricas sobre alguma situação, enquanto os atuadores fazem algo de fato. Basicamente, é possível dizer que o sensor é o INPUT e o atuador o OUTPUT.

Digital:

```cpp
#define SENSOR_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  int umidade = digitalRead(SENSOR_PIN);
  Serial.println(umidade);

  delay(1000);
}
```

Analógico:

```cpp
#define SENSOR_PIN A0

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  int umidade = analogRead(SENSOR_PIN);
  Serial.println(umidade);

  delay(1000);
}
```

Usando lib(DHT11):

```cpp
#include "DHT.h"

#define DHTPIN A0
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float umidade = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("Erro ao ler sensor!");
  } else  {
    Serial.print("Umidade: ");
    Serial.print(umidade);
    Serial.print("  Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" *C");
  }
}
```

# Desafio

### User story

Desenvolver um algoritmo que, ao receber a letra `H` na porta serial, ligue o LED e, caso receba o `L`, desligue o LED.

* [ ] Diagrama de blocos

* [ ] Codigo arduino

BONUS:

* [ ] Alterar a lógica do algoritmo, para que este apenas inverta o estado do LED a cada caractere que chegue na porta serial, desconsiderando claro `\n`. Faça esse exercício sem usar `if`'s.


## Referências e recursos úteis

[Baudrates suportados](https://www.arduino.cc/en/Reference/SoftwareSerialBegin)

[Funções do arduino](https://www.arduino.cc/reference/pt/#functions)

[Documentação sobre o Serial.read()](https://www.arduino.cc/reference/en/language/functions/communication/serial/read/)

[Documentação dos tipos, olhar sessão Data Types](https://www.arduino.cc/reference/en/#variables)
