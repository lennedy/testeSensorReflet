int a,b,c;
int tempoAtual=0;
int tempoAnt=0;

void setup() 
{
Serial.begin(9600);
pinMode(6,OUTPUT);
}

void loop() {
  digitalWrite(6,HIGH);       // Ligando o LED
  delayMicroseconds(1000);     //espera
  a = analogRead(A3);           //lendo do photodiode(pin A3) :ruido+sinal
  digitalWrite(6,LOW);        //Desligando o LED
  delayMicroseconds(1000);     //espera
  b = analogRead(A3);           // novamente lendo o photodiode :ruido
  c = b - a;                      //calculando a diferença:[ (ruido+sinal)-(ruido)] apenas o sinal
  
  tempoAtual = millis();
  if ( (tempoAtual - tempoAnt) > 1000){
    tempoAnt = tempoAtual;
    printDados();
  }
}

void printDados(){

  Serial.print(a);         //ruido+sinal
  Serial.print("\t");
  Serial.print(b);         //ruido
  Serial.print("\t");
  Serial.println(c);         // sinal sem ruido

}
