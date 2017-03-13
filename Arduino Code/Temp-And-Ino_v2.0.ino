
#include <SoftwareSerial.h>   //Software Serial Port 
#define RxD 2 // Connect to bluetooth BT_TX
#define TxD 3 // Connect to bluetooth BT_RX

SoftwareSerial blueToothSerial(RxD,TxD);


void setup()
{
        Serial.begin(9600);
        pinMode(RxD, INPUT);
        pinMode(TxD, OUTPUT);
        setupBlueToothConnection();
        pinMode(8,OUTPUT); // Right1
        pinMode(9,OUTPUT); //Right2
        pinMode(10, OUTPUT); //Left1
        pinMode(11,OUTPUT); //Left2
        //pinMode(ledPin,OUTPUT);
}
void loop()
{
        if(blueToothSerial.available())
        {
          int x= blueToothSerial.read();
              Serial.println(x);
          // a= blueToothSerial.read();
              
              if(x==98){
                //Serial.println("Forward");
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(3000); //3sec
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  
  //Forward
  if(x==102){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(3000); //3sec
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
    
  //Right
  if(x==108){
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    delay(500); //.5sec
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  
  //Left
  if(x==114){
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    delay(500); //0.5sec
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
}
  if(x==115){
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
}
        }       
}

void setupBlueToothConnection()
{
  blueToothSerial.begin(38400); //Set BluetoothBee BaudRate to default baud rate 38400
  blueToothSerial.print("\r\n+STWMOD=0\r\n"); //set the bluetooth work in slave mode
  blueToothSerial.print("\r\n+STNA=Temp-And-Ino\r\n"); //set the bluetooth name as "Temp-And-Ino"
  blueToothSerial.print("\r\n+STPIN=0000\r\n");//Set SLAVE pincode"0000"
  blueToothSerial.print("\r\n+STOAUT=1\r\n"); // Permit Paired device to connect me
  //blueToothSerial.print("\r\n+STAUTO=0\r\n"); // Auto-connection should be forbidden here
  delay(2000); // This delay is required.
  blueToothSerial.print("\r\n+INQ=1\r\n"); //make the slave bluetooth inquirable 
  Serial.println("The slave bluetooth is inquirable!");
  delay(2000); // This delay is required.
  Serial.println("2 seconds passed");
  blueToothSerial.flush();
}
