#include <VirtualWire.h>
#include <AESLib.h>

//Define pino led
int led = 4; 

int valor_recebido_RF;
char recebido_RF_char[4]; 

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  vw_set_rx_pin(2);
  vw_setup(5000); 
  vw_rx_start();
  Serial.println("Recepcao modulo RF - Aguardando...");
  Serial.begin(9600);
}

void loop(){
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  uint8_t key[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
  if (vw_get_message(buf, &buflen)) {
    int i;
    for (i = 0; i < buflen; i++){            
      recebido_RF_char[i] = char(buf[i]);
    }
    recebido_RF_char[buflen] = '\0';
    aes256_dec_single(key, valor_recebido_RF_char);
    valor_recebido_RF = atoi(recebido_RF_char);    
    
    if (valor_recebido_RF == 0){
     digitalWrite(led, HIGH);
     Serial.println(" - Led aceso !");
   }
   if (valor_recebido_RF == 1){
     digitalWrite(led, LOW);
     Serial.println(" - Led apagado !");
   }
 }
}
