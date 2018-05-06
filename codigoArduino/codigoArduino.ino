#include <morse.h>

#define PIN_STATUS  13
#define PIN_SPEAKER 3

String nombre = "Manuel";

LEDMorseSender LED(PIN_STATUS, 10);
SpeakerMorseSender buzzer(
  PIN_SPEAKER,
  880,  // tone frequency
  110,  // carrier frequency
  20.5);  // wpm

void setup()
{
  Serial.begin(9600);
  LED.setup();
  LED.setMessage(String("a"));

  buzzer.setup();
  buzzer.setMessage(String("a"));
}

void loop()
{

  if (Serial.available()) {
    String nuevoMensaje = Serial.readString();
    LED.setMessage(nuevoMensaje);
    buzzer.setMessage(nuevoMensaje);
    Serial.println("Enviando mensaje: " + nuevoMensaje);
    Serial.end();
    Serial.begin(9600);
  }
  if (!LED.continueSending())
  {
    LED.startSending();
  }
  if (!buzzer.continueSending())
  {
    buzzer.startSending();
  }
}
