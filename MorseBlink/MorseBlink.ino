/************************************************************************
*                              Morse Decode                             *
*             Author: Bohan Shi           Version: 0.9.5                *
*             Features:                                                 *
*             - Decode Morse code and turn into LED blink               *
*             - Ignore ponctuations and additional spaces               *
*             - Use space to divide words                               *
*             - Accept one line input at a time                         *
*             - Continue Operation                                      *
*             - Add new characters like number by add its ASCII code in *
*               the switch case and enter morse code.                   *
*               (blinkunit(0);  is a ".") (blinkunit(0);  is a "-")     *
************************************************************************/

const int speed = 1;                  //set blink speed(real world is about 3 to 5)
bool decodeBlink(int charInt,bool haveSpace);             //decode the input and blink
void blinkunit(int morsein);          //function of a unit blink(define"."blink and "-"blink)
void blink(int charInt);              //determine the morse code of the letter

void setup() {                
  pinMode(13, OUTPUT);               //set pin mode
  Serial.begin(9600);    
}

void loop() {
  char comdata;
  int charInt;
  bool haveSpace = 1;                  //A switch to mesrure is there already a space between two words
  
  while (Serial.available() > 0)      
  {
      comdata = char(Serial.read());     //Read a char from Serial
      charInt = (int)comdata;             //Turn char to ASCII number just for convenient
      
      haveSpace = decodeBlink(charInt,haveSpace);    //Call decode and blink function
  }
}


/************************************************************************
*                      function of a decode and blink                   *
*             decode the input            ignore ponctuations           *
*                             divide words                              *
*          If using for other projects: add a bool value: haveSpace     *
************************************************************************/

bool decodeBlink(int charInt,bool haveSpace){
    if(65<=charInt&&charInt<=90){          //uppercase letter is available
          blink(charInt);
          haveSpace = 0;               //set swithch to false(no space yet)
          delay(2000/speed);                 //additional delay between letters
       }else if(97<=charInt&&charInt<=122){  //lowercase letter is available
          charInt = charInt-32;              //turn lowercase letter to uppercase
          blink(charInt);
          haveSpace = 0;               //set swithch to false(no space yet)
          delay(2000/speed);
       }else if(charInt == 32){
          if(haveSpace == 0){          //if there is not a space between two words already
             digitalWrite(13, LOW);    // turn the LED off
             delay(5000/speed);               // wait for 4 second
          }
              haveSpace = 1;          //set switch to true
       }
      return haveSpace;
  }


/************************************************************************
*       function of a unit blink(define"."blink and "-"blink)           *
*             0 is "." blink            1 is "-" blink                  *
************************************************************************/

void blinkunit(int morsein){
    if(morsein == 0){
         digitalWrite(13, HIGH);   // turn the LED on
         delay(1000/speed);               // wait for 1 second
      }else if(morsein == 1){
         digitalWrite(13, HIGH);   // turn the LED on
         delay(3000/speed);               // wait for 3 second
      }
     digitalWrite(13, LOW);        // turn the LED off
     delay(1000/speed);                   // wait for 1 second
 }

/************************************************************************
*      function include the morse code of all letters in uppercase      *
*                          A to Z            65 to 90                   *
*      Optional Not Added: 0 to 9            48 to 57                   *
*                          Add if you need                              *
************************************************************************/

 void blink(int charInt){
      switch (charInt){
        case 65: //A
         blinkunit(0);
         blinkunit(1);
         break;
        case 66: //B
         blinkunit(1);
         blinkunit(0);
         blinkunit(0);
         blinkunit(0);
         break;
        case 67: //C
         blinkunit(1);
         blinkunit(0);
         blinkunit(1);
         blinkunit(0);
         break;
        case 68: //D
         blinkunit(1);
         blinkunit(0);
         blinkunit(0);
         break;
        case 69: //E
         blinkunit(0);
         break;
        case 70: //F
         blinkunit(0);
         blinkunit(0);
         blinkunit(1);
         blinkunit(0);
         break;
        case 71: //G
         blinkunit(1);
         blinkunit(1);
         blinkunit(0);
         break;
        case 72: //H
         blinkunit(0);
         blinkunit(0);
         blinkunit(0);
         blinkunit(0);
         break;
        case 73: //I
         blinkunit(0);
         blinkunit(0);
         break;
        case 74: //J
         blinkunit(0);
         blinkunit(1);
         blinkunit(1);
         blinkunit(1);
         break;
        case 75: //K
         blinkunit(1);
         blinkunit(0);
         blinkunit(1);
         break;
        case 76: //L
         blinkunit(0);
         blinkunit(1);
         blinkunit(0);
         blinkunit(0);
         break;
        case 77: //M
         blinkunit(1);
         blinkunit(1);
         break;
        case 78: //N
         blinkunit(1);
         blinkunit(0);
         break;
        case 79: //O
         blinkunit(1);
         blinkunit(1);
         blinkunit(1);
         break;
        case 80: //P
         blinkunit(0);
         blinkunit(1);
         blinkunit(1);
         blinkunit(0);
         break;
        case 81: //Q
         blinkunit(1);
         blinkunit(1);
         blinkunit(0);
         blinkunit(1);
         break;
        case 82: //R
         blinkunit(0);
         blinkunit(1);
         blinkunit(0);
         break;
        case 83: //S
         blinkunit(0);
         blinkunit(0);
         blinkunit(0);
         break;
        case 84: //T
         blinkunit(1);
         break;
        case 85: //U
         blinkunit(0);
         blinkunit(0);
         blinkunit(1);
         break;
        case 86: //V
         blinkunit(0);
         blinkunit(0);
         blinkunit(0);
         blinkunit(1);
         break;
        case 87: //W
         blinkunit(0);
         blinkunit(1);
         blinkunit(1);
         break;
        case 88: //X
         blinkunit(1);
         blinkunit(0);
         blinkunit(0);
         blinkunit(1);
         break;
        case 89: //Y
         blinkunit(1);
         blinkunit(0);
         blinkunit(1);
         blinkunit(1);
         break;
        case 90: //Z
         blinkunit(1);
         blinkunit(1);
         blinkunit(0);
         blinkunit(0);
         break;
        default:
          break;
      }
 }
