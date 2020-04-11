## Aula 9 - Projetos com alimentação externa.

## Conteúdo

Nessa aula falaremos um pouco sobre projetos com alimentação externa e daremos uma Introdução ao esp8266, que usaremos no projeto da tranca.

REFERENCIA


RELES E TRANSISTORES

NO E NC


### Implementando no esp8266

Pinagem no esp

snipet:

```cpp
#define RELE 2

void abre() {
  Serial.println("Abrindo");
  digitalWrite(RELE, HIGH);
}

void fecha() {
  Serial.println("Fechando");
  digitalWrite(RELE, LOW);
}

void setup() {
  pinMode(RELE, OUTPUT);
  digitalWrite(RELE, LOW);
  Serial.begin(9600);
}

void loop() {
  abre();
  delay(1000);

  fecha();
  delay(1000);
}
```

## Desafio

### User history

Para finalizar o projeto da horta voce deve implementar a solenoide que irrigara de fato nosso jardim, ative a solenoide utilizando um rele ligado a uma fonte de 12v.

### Tasklist

* [ ] Implementar rele no projeto.

* [ ] Refatorar codigo e revisar com o grupo.

* [ ] Abrir pull request no github com as alteracoes de hoje para o professor revisar.


## Referências e recursos úteis

[]()
