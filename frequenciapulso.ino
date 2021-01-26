// incluindo biblioteca Chrono (cronometro)
#include <Chrono.h>
#include <LightChrono.h>
// definindo variaveis
#define pino 2

volatile unsigned long tempos[3] = {0,0}; // criando lista que guardara os tempos de pulsos consecutivos
volatile int cont = 0; //variavel auxiliar que sera utilizada na funcao regtempo
volatile unsigned long tempoT; // variavel que guardara a diferenca de tempo entre pulsos
volatile int contador; // variavel que guarda o indice do pulso, ou seja, em qual pulso esta
Chrono crono(Chrono::MICROS); // iniciando cronometro, que conta o tempo em microssegundos

void setup() {
  // put your setup code here, to run once:
  pinMode(pino, INPUT);
  Serial.begin(9600); // "ativando" o monitor serial
  attachInterrupt(digitalPinToInterrupt(pino), regtempo, RISING);
  contador = 0;
}
void loop() {
   // put your main code here, to run repeatedly
    if (tempos[1] > tempos[0]){
      tempoT = tempos[1] - tempos[0];
      Serial.println(1000000./tempoT); //printando a frequencia]
      Serial.println(contador);
      contador +=1; // 
    }
    else{
      tempoT = tempos[0] - tempos[1];
      Serial.println(1000000./tempoT);
      Serial.println(contador);
      contador +=1;
    }
}
void regtempo(){
    tempos[cont] = crono.elapsed(); // guardando o tempo que o cronometro contou nesse momento
    cont += 1; // a variavel cont serve para limitar o indice do array tempos, que nao pode passar de 1
    if (cont >1){ // pois esse array contem apenas 2 espaços. Logo, os indices devem ficar limitados em 0 e 1
    cont = 0;
    }
    else {}
}
