#include <Servo.h>
 
// Define o número de servos
#define SERVOS 2
 
// Cria os objetos servo
Servo myservo[SERVOS];  
 
// Conecta os servos aos pinos pwm do arduino
int servo_pins[SERVOS] = {3,5}; 
 
// Pinos analógicos onde as saídas WRX e WRY serão conectadas
int joystick[SERVOS] = {A0,A1}; 
 
// Variável para a leitura dos pinos analógicos
int joystick_val[SERVOS]; 

// Pino da saída SW
int swpin = 2;

void sw (){
  int swstate = digitalRead(swpin);
  if(swstate==HIGH){
    // Coloque o que você quer aqui
  }
}

void setup() {
   
  for(int i = 0; i < SERVOS; i++) {
     
    // Conecta os servos ao objeto servo
    myservo[i].attach(servo_pins[i]);  
  }
}
  
void loop() {  
 
 // chama a função do SW
 sw();

  // For para controlar os servos
  for(int i = 0; i < SERVOS; i++) {
    // Lê o valor dos potenciômetros do joystick (entre 0 e 1023)
    joystick_val[i] = analogRead(joystick[i]); 
 
    // Escala o valor de 0 a 1023 para 0 a 180
    joystick_val[i] = map(joystick_val[i], 0, 1023, 0, 180);
 
    // Atualiza a posição dos servos
    myservo[i].write(joystick_val[i]);  
     
    // delay de 15ms para movimentar o servo
    delay(15);  
  }  
}      
