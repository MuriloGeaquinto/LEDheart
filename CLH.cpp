// Definição dos pinos
#define L0 13
#define L1 12
#define L2 11
#define L3 10
#define L4 9
#define L5 8
#define L6 7
#define L7 6
#define L8 5
#define L9 4
#define L10 3
#define L11 2
#define L12 A0
#define L13 A1

// Array com todos os pinos para facilitar o setup
const int todosPinos[] = {L0, L1, L2, L3, L4, L5, L6, L7, L8, L9, L10, L11, L12, L13};
const int numPinos = 14;

const int delayPadrao = 620;  
const int delayRapido = 150;
const int delayPausa = 700;

void setup() {
  // Inicializa todos os pinos como saída
  for (int i = 0; i < numPinos; i++) {
    pinMode(todosPinos[i], OUTPUT);
    digitalWrite(todosPinos[i], LOW); // Inicia todos desligados
  }
}

void loop() {
  // Piscar todos os LEDs em sequência (efeito de corrida)
  for (int i = 0; i < numPinos; i++) {
    digitalWrite(todosPinos[i], HIGH);
    delay(delayRapido);
    digitalWrite(todosPinos[i], LOW);
  }
  
  // Piscar todos juntos 5 vezes
  for (int vez = 0; vez < 5; vez++) {
    // Liga todos
    for (int i = 0; i < numPinos; i++) {
      digitalWrite(todosPinos[i], HIGH);
    }
    delay(delayPadrao);
    
    // Desliga todos
    for (int i = 0; i < numPinos; i++) {
      digitalWrite(todosPinos[i], LOW);
    }
    delay(delayPadrao);
  }
  
  // Efeito corrida inverso (acende do L13 para o L0)
  for (int i = numPinos - 1; i >= 0; i--) {
    digitalWrite(todosPinos[i], HIGH);
    delay(delayRapido);
    digitalWrite(todosPinos[i], LOW);
  }
  
  delay(delayPausa); // Pausa entre os ciclos
}
