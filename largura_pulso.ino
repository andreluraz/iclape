// definindo variaveis
#define pino 2

void setup() {
  // put your setup code here, to run once:
  pinMode(pino, INPUT);
  Serial.begin(9600); // "ativando" o monitor serial
}
void loop() {
  // put your main code here, to run repeatedly
  Serial.println(pulseIn(pino, HIGH,100000000)); // espera um pulso alto por 100 s
}
