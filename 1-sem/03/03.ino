/*
  Use barra e asterisco para fazer comentários com mais de uma linha
  mas sempre se lembre, um código bem escrito muitas vezes não precisa
  de comentários.
  Lembrem sempre de dar nomes que façam sentido as coisas durante seu código,
  e evite linhas muito longas por dificultar para ler o código.
*/

// Use duas barras para fazer um comentário de uma linha

// A função setup que faz a configuração inicial antes do loop principal
void setup() {
  // Inicializa o LED_BUILTIN do Arduino como um pino de saida(OUTPUT)
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);   // liga o led
}

// Função principal que faz um loop infinito
void loop() {
  if (LED_BUILTIN == HIGH) {
    digitalWrite(LED_BUILTIN, LOW);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);   // liga o led
  }    // desliga o led

  delay(1000);                       // espera um segundo
}
