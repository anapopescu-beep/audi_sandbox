 /*  
Modified on Nov 16, 2020
Modified by MehranMaleki from Arduino Examples
Home
*/

/*                                                                                                                                 
 * For this example, connect your X9C103P (or the like) as follows:
 * 1 - INC - Arduino pin 2
 * 2 - U/D - Arduino pin 3
 * 3 - VH  - 5V
 * 4 - VSS - GND
 * 5 - VW  - Output: Arduino pin A0 for analogRead
 * 6 - VL  - GND
 * 7 - CS  - Arduino pin 4
 * 8 - VCC - 5V
 */


#include <DigiPotX9Cxxx.h>

int digitalVCC = 8;

int FA_incPin = 6;
int FA_udPin = 5;
int FA_csPin = 7;

int BF_incPin = 3;
int BF_udPin = 2;
int BF_csPin = 4;

//DigiPot pot(FA_incPin, FA_udPin, FA_csPin); //FA - left
DigiPot pot(BF_incPin, BF_udPin, BF_csPin); //BF - right

const unsigned int MAX_MESSAGE_LENGTH = 20;

void setup() 
{
 Serial.begin(9600);
 pinMode(digitalVCC, OUTPUT);
 digitalWrite(digitalVCC, HIGH);
 
 pinMode(FA_incPin, OUTPUT);
 pinMode(FA_udPin, OUTPUT);
 pinMode(FA_csPin, OUTPUT);
 
 pinMode(BF_incPin, OUTPUT);
 pinMode(BF_udPin, OUTPUT);
 pinMode(BF_csPin, OUTPUT);
}

void loop() 
{ 
 int resistanceValue = 0;
 //Check to see if anything is available in the serial receive buffer
 while(Serial.available() > 0)
 {
   //pot.set(0);
   //Create a place to hold the incoming message
   static char message[MAX_MESSAGE_LENGTH];
   static unsigned int message_pos = 0;

   //Read the next available byte in the serial receive buffer
   char inByte = Serial.read();

   //Message coming in (check not terminating character) and guard for over message size
   if ( inByte != '\n' && (message_pos < MAX_MESSAGE_LENGTH - 1) )
   {
     //Add the incoming byte to our message
     message[message_pos] = inByte;
     message_pos++;
   }
   //Full message received...
   
   else
   {
     //Add null character to string
     message[message_pos] = '\0';
     String msgString = String(message);
     if (msgString.equals("reset"))
     {
      //set pins
      pot.set(100);
     }
     else if (msgString.equals("left"))
     {
      pot._incPin = FA_incPin;
      pot._udPin = FA_udPin;
      pot._csPin = FA_csPin;  
      pot._currentValue = DIGIPOT_UNKNOWN;
      digitalWrite(pot._csPin, HIGH);
     }
     else if (msgString.equals("right"))
     {
      pot._incPin = BF_incPin;
      pot._udPin = BF_udPin;
      pot._csPin = BF_csPin;  
      pot._currentValue = DIGIPOT_UNKNOWN;
      digitalWrite(pot._csPin, HIGH);
     }
     else 
     {
      resistanceValue = atoi(message);
      pot.set(resistanceValue);
     }
      //Reset for the next message
      message_pos = 0;    
   }
 }
}
