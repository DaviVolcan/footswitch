#include <Arduino.h>

#include "Keyboard.h"



const int pinoBotao = 2; // Pino de entrada para o botão (pullup)
bool estadoBotaoAnterior = HIGH; // Estado anterior do botão

void setup() {
  pinMode(pinoBotao, INPUT_PULLUP); // Configura o pino do botão como entrada pullup
  Keyboard.begin(); // Inicia a emulação de teclado
}

void loop() {
  bool estadoBotaoAtual = digitalRead(pinoBotao); // Lê o estado atual do botão

  // Verifica se houve mudança de estado do botão
  if (estadoBotaoAtual != estadoBotaoAnterior) {
    if (estadoBotaoAtual == LOW) {
      Keyboard.press(KEY_LEFT_CTRL); // Segura a tecla "Ctrl"
      Keyboard.press(KEY_LEFT_ALT); // Segura a tecla "Ctrl"
    } else {
      Keyboard.release(KEY_LEFT_CTRL); // Solta a tecla "Ctrl"
      Keyboard.release(KEY_LEFT_ALT); // Solta a tecla "Ctrl"
    }

    estadoBotaoAnterior = estadoBotaoAtual; // Atualiza o estado anterior do botão
  }

  delay(20); // Pequeno delay para evitar leituras falsas ou "bounce"
}


