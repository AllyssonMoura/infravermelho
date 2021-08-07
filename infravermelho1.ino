#include <IRremote.h>

IRrecv receptor(5);
decode_results resultado;

void setup(){
  Serial.begin(9600);
  receptor.enableIRIn();
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
}

void loop(){
  if(receptor.decode(&resultado)){
    if(resultado.value == 16580863){
      digitalWrite(6, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
    }
    if(resultado.value == 16597183){
      digitalWrite(6, LOW);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
    }
    if(resultado.value == 16582903){
      digitalWrite(6, HIGH);
    }
    if(resultado.value == 16591063){
      digitalWrite(6, LOW);
    }
    if(resultado.value == 16615543){
      digitalWrite(4, HIGH);
    }
    if(resultado.value == 16623703){
      digitalWrite(4, LOW);
    }
    if(resultado.value == 16599223){
      digitalWrite(3, HIGH);
    }
    if(resultado.value == 16607383){
      digitalWrite(3, LOW);
    }
    Serial.println(resultado.value);
    receptor.resume();
    delay(100);
  }
}