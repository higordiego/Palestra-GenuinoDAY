#include <VirtualWire.h>

const int ledPin = 13;
char Valor_CharMsg[4]; 

int estado;
void setup() {
  Serial.begin(9600);   
  pinMode(ledPin,OUTPUT);
  //Pino ligado ao pino DATA do transmissor RF
  vw_set_tx_pin(2);
  //Velocidade de comunicacao (bits por segundo)
  vw_setup(5000);
  Serial.println("Trasmissao modulo RF - Acione o botao...");   
}

void loop() {


      estado = 0;    
      itoa(estado,Valor_CharMsg,10);
      //Liga o led da porta 13 para indicar envio dos dados
      digitalWrite(13, true);
      //Envio dos dados
      vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg));
      //Aguarda envio dos dados
      vw_wait_tx();
      //Desliga o led da porta 13 ao final da transmissao
      digitalWrite(13, false);
      Serial.print("Valor enviado: ");
      Serial.println(Valor_CharMsg);
      delay(9000);

    
      estado = 1;
      itoa(estado,Valor_CharMsg,10);
      //Liga o led da porta 13 para indicar envio dos dados
      digitalWrite(13, true);
      //Envio dos dados
      vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg));
      //Aguarda envio dos dados
      vw_wait_tx();
      //Desliga o led da porta 13 ao final da transmissao
      digitalWrite(13, false);
      Serial.print("Valor enviado: ");
      Serial.println(Valor_CharMsg);
    delay(9000);
}
