# Aula 4 - Arduino getting started.

## Estrutura básica do sketch arduino
Um sketch é um arquivo do arduino com a extenção `.ino`, ele eh basicamente um `C++` com algumas funções proprias. O sketch deve ficar dentro de uma pasta com o mesmo nome do arquino .ino.
Um sketch sempre vai ter duas funcoes iniciais, `setup` e `loop`. No momento de execucao do programa ele comecara a ler o codigo de cima e fara a funcao setup uma vez no inicio, e depois a funcao loop eh chamada a seguir onde ficara executando os codigos dentro da funcao como um loop infinito ate que haja uma interrupcao.

Estrutura básica:

```cpp
void setup() {
  // aqui fica a configuração inicial, configurações gerais, etc
}

void loop() {
  // aqui fica a lógica principal do seu programa que será executado em loops,
  // ao iniciar o código, ele passa uma vez pelo setup e faz a configuração inicial,
  // depois disso ele fica nesse loop até que seja desligado ou haja uma interrupcao.
}
```

## Tipos no C/C++
Esse void na frente do nome da funcao eh o tipo da funcao, em C/C++ temos que declarar os tipos das funcoes e variaveis, ou seja, eh uma `linguagem fortemente tipada`. Os `tipos primitivos` como sao chamados definem com que tipo de dado estamos lidando. No C temos os seguintes tipos:

* `void`: significa a ausencia de um tipo, eh um tipo sem tipo, na pratica usamos esse tipo apenas para declarar funcoes, nao podemos declarar variaveis com ele. E as funcoes do tipo void basicamente quer dizer que ele faz algumas coisas dentro daquele pedaco de codigo mas nao retorna nenhum valor, caso retornasse a funcao deve ser do tipo do retorno. Mas nao se preocupe muito com isso ainda, porque na aula de funcoes ficara mais claro.

* `char`: Esse tipo armazena apenas um caracter alfanumerico, esse tipo eh muito usado para criar vetores de caracteres para criar texto, porem no C++ tem uma biblioteca `string` que facilita um pouco quando temos que lidar com textos e palavras.

* `int`: Representa os numeros inteiros e pode ir de -32768 até +32767,

* `float`: Representa os numeros reais, ocupa 4 bytes de memoria.

* `double`: Representa os reais assim como o float, porem esse ocupa 8 bytes de memoria, o que nos permite ter mais casas decimais e ter mais precisao.

O C++ implementa esses tipos e alguns outros que deixarei na referencia desse texto, mas um tipo muito importante que ele implementa eh o `boolean`. Um valor boleano representa verdadeiro ou falso, (`true` e `false`) sendo o true equivalente a 1, e false igual a 0.

## Variáveis
Uma variável é basicamente uma caixa onde você pode guardar informações temporariamente, ao finalizar a execução do código as informações são perdidas. Para atribuir um valor a uma variavel é só escolher um nome(de preferência que faça sentido no contexto, vai te ajudar a longo prazo) e atribuir um valor que seja do tipo correto.

O `C/C++` segue estilo de linguagem de programação tipada, o que significa que ao declarar uma variável ou função temos que falar de qual tipo ela é, pode ser um número inteiro ou real, uma string(texto), boleano(verdadeiro ou falso) entre outros.
Por exemplo, para declarar a variável idade nós fazemos: `int idade = 27;` Ou seja, no exemplo anterior como a idade é um número inteiro não podemos simplesmente atribuir uma string `ìdade = 'vinte e sete';` isso causaria um erro, pois você tentou colocar uma string em uma variável que aceita apenas inteiros. Mas para permitir uma manipulação dos dados existem métodos para fazer uma conversão de tipos, caso ela seja possivel.

Sem contar variáveis tradicionais como as citadas anteriormente, também temos constantes, que podem ser definidas de duas maneiras, podemos declará-la usando `const` ou `define`. O const é uma váriavel normal que não pode ser alterada:
`const int idade = 27;`

Já o define ele feito geralmente no topo do arquivo, e ele é parseado pelo preprocessador antes de ser compilado, e ele troca o nome da definição pelo código em si. O que acaba sendo um pouco mais performático, mas não oferece tantos ganhos assim. O importante eh lembrar que constantes nao mudam de valor durante a execucao do programa.

```cpp
define IDADE 27

Serial.println(IDADE)
```

Esse código antes de ser compilado ele troca todas as ocorrências de IDADE por 27, que se torna:

```cpp
define IDADE 27

Serial.println(27)
```

Diferente do const que eh tratado como uma variavel convencionam, porem que nao pode ser alterada:

```cpp
int const idade = 27;

Serial.println(idade)
```

## Funções especiais do arduino
O arduino usa algumas funções especiais que não são usadas em C ou C++ puros,
essas funções são para coisas específicas do arduino, algumas bem comuns que podemos citar são:

* `pinMode` - configura um pino do arduino como INPUT ou OUTPUT
* `digitalWrite` - envia um sinal para um pino digital (1 ou 0)
* `delay` - faz o programa parar por alguns microsegundos
* `analogRead` - lê o valor de um pino analôgico (0~1023)
* `digitalRead` - lê o valor de um pino digital(0 ou 1)
* `Serial.print` - imprime algum valor na porta serial sem quebra de linha `\n`
* `Serial.println` - imprime algum valor na porta serial com quebra de linha `\n`

Caso queira ver mais métodos disponíveis dê uma olhada [aqui](https://www.arduino.cc/reference/pt/#functions).

Exemplo para fazer um led piscar:

```cpp
/*
  Use barra e asterisco para fazer comentários com mais de uma linha
  mas sempre se lembre, um código bem escrito muitas vezes não precisa
  de comentários.
  Lembrem sempre de dar nomes que façam sentido as coisas durante seu código,
  e evite linhas muito longas por dificultar para ler o código.
*/

// Use duas barras para fazer um comentário de uma linha

// define o led como sendo o pino 9
#define LED 9

// A função setup que faz a configuração inicial antes do loop principal
void setup() {
  pinMode(LED, OUTPUT); // Inicializa o LED como um pino de saida(OUTPUT)
}

// Função principal que faz um loop infinito
void loop() {
  if (digitalRead(LED) == HIGH) {   // verifica a leitura do sensor, caso esteja ligado o led ele entra na linha abaixo
    digitalWrite(LED, LOW);    // desliga o led
  } else {
    digitalWrite(LED, HIGH);   // liga o led
  }

  delay(1000);                 // espera um segundo e comeca novamente
}
```

## Conexao serial e baudrate

Quando queremos usar a comunicacao serial do arduino usando metodos da classe `Serial` precisamos definir no setup qual sera seu baudrate. Baudrate eh uma unidade de medida que representa o numero de pulsos por segundo, ou seja, o numero de bits por segundo. Com ele definimos qual sera a nossa velocidade de transmicao, porem nao podemos escolher esses valores arbitrariamente, temos que saber qual a velocidade da nossa placa, existem alguns valores padroes: 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 28800, 31250, 38400, 57600, e 115200.

Porem sempre consulte mais informacoes sobre o modelo de sua placa. Nas aulas usaremos o arduino uno que opera com 9600 baud. Caso escolha errado eh bem provavel que tenha problemas para enviar e receber dados.

Podemos transmitir dados facilmente usando o comando `Serial.println("minha transmicao");`. E também podemos ler informacoes que chegam via serial usando o comando `Serial.read();` para ler um caracter ou `Serial.readString();` para ler uma string.

Exemplo de comunicacao serial no arduino:

```cpp
void setup() {
  Serial.begin(9600);          // inicia a comunicacao serial com 9600 baud
}

void loop() {
  if (Serial.available() > 0) {   // caso tenha algo vindo na serial
    char caractere;               // declara uma variavel tipo char para guardar o caracter que esta chegando
    caractere = Serial.read();    //atribui o valor lido pela serial a variavel caractere
    if (caractere != '\n') {      // verifica se o caractere que chegou nao eh uma quebra de linha, ela pode ser um \n ou \r
      Serial.println(caractere);  // caso seja memso um caractere ele  o imprime no serial, devolvendo o que mandamos a ele
    }
  }
  delay(1000); // espera um segundo e comeca novamente
}
```

## IO - Entendendo os sensores e atuadores

Temos diversos sensores, mas eles se dividem em alguns tipos basicos, porem cada um com suas particularidades, eles sempre serao `analôgicos ou digitais`, lembrando que os digitais medem 0 e 1, e os analôgicos 0~1023. Alguns sensores funcionam usando apenas os comandos do arduino, porem alguns dependem de alguma lib para funcionar corretamente.
Ao importar uma lib no topo do codigo eh criado um objeto que representa aquela lib para podemos utilizar o sensor, como eh o caso do `DHT11`.
Um sensor serve para pegar metricas sobre alguma coisa, enquanto os atuadores fazem algo de fato, basicamente o sensor eh o INPUT, e o atuador o OUTPUT.

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

Analôgico:

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

### User history

Fazer um algoritimo que ao receber a letra `H` na porta serial ligue o led e se receber `L` desligue o led.

* [ ] Diagrama de blocos

* [ ] Codigo arduino

BONUS:

* [ ] Alterar a logica do algoritimo para que apenas inverta o estado do led a cada caracter que chegue na porta serial, desconsideirando claro `\n`.


## Referências e recursos úteis

[Baudrates suportados](https://www.arduino.cc/en/Reference/SoftwareSerialBegin)

[Funcoes do arduino](https://www.arduino.cc/reference/pt/#functions)

[Documentacao sobre o Serial.read()](https://www.arduino.cc/reference/en/language/functions/communication/serial/read/)

[Documentacao dos tipos, olhar sessao Data Types](https://www.arduino.cc/reference/en/#variables)
