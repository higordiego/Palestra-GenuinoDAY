#include <VirtualWire.h>

//Define pino led
int led = 4; 


int valor_recebido_RF;
char recebido_RF_char[4]; 

void setup() {
  pinMode(led, OUTPUT);

  digitalWrite(led, LOW);
  //Pino ligado ao pino DATA do receptor RF
  vw_set_rx_pin(2);
  //Velocidade de comunicacao (bits por segundo)
  vw_setup(5000); 
  //Inicia a recepcao  
  vw_rx_start();
  Serial.println("Recepcao modulo RF - Aguardando...");
  Serial.begin(9600);
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    if (vw_get_message(buf, &buflen)) {
    int i;
        for (i = 0; i < buflen; i++){            
          recebido_RF_char[i] = char(buf[i]);
       }
       recebido_RF_char[buflen] = '\0';
       valor_recebido_RF = atoi(recebido_RF_char);
         
    
       Serial.print("Recebido: ");
       Serial.print(valor_recebido_RF);
    
       if (valor_recebido_RF == 1){
         digitalWrite(led, LOW);
         Serial.println(" -  Led apagado !");
       }
        if (valor_recebido_RF == 0){
         digitalWrite(led, HIGH);
         Serial.println(" - Led aceso !");

       }
    }
}
