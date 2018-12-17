int a,b,c;
void setup() 
{
Serial.begin(9600);
pinMode(6,OUTPUT);
}

void loop() {
digitalWrite(6,HIGH);       // Turning ON LED
delayMicroseconds(1000);     //wait
a=analogRead(A3);           //take reading from photodiode(pin A3) :noise+signal
digitalWrite(6,LOW);        //turn Off LED
delayMicroseconds(1000);     //wait
b=analogRead(A3);           // again take reading from photodiode :noise
c=b - a;                      //taking differnce:[ (noise+signal)-(noise)] just signal



Serial.print(a);         //noise+signal
Serial.print("\t");
Serial.print(b);         //noise
Serial.print("\t");
Serial.println(c);         // denoised signal

}