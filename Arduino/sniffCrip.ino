#include <VirtualWire.h>

const int ledPin = 13;
char Valor_CharMsg[4]; 
#include <AESLib.h>

int estado;
void setup() {
  Serial.begin(57600);
  pinMode(ledPin,OUTPUT);
  //Pino ligado ao pino DATA do transmissor RF
  vw_set_tx_pin(2);
  //Velocidade de comunicacao (bits por segundo)
  vw_setup(5000);
  Serial.println("Trasmissao modulo RF - Acione o botao...");   
}

void loop() {
  uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};

  estado = 0;    
  itoa(estado,Valor_CharMsg,10);
  digitalWrite(13, true);
  aes256_enc_single(key, Valor_CharMsg);
  vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg));

  vw_wait_tx();

  digitalWrite(13, false);
  Serial.print("Valor enviado: ");
  Serial.println(Valor_CharMsg);
  delay(1000);



  itoa(estado,Valor_CharMsg,10);

  digitalWrite(13, true);
  aes256_enc_single(key, Valor_CharMsg);

  vw_send((uint8_t *)Valor_CharMsg, strlen(Valor_CharMsg));

  vw_wait_tx();

  digitalWrite(13, false);
  Serial.print("Valor enviado: ");
  Serial.println(Valor_CharMsg);
  delay(1000);
}

