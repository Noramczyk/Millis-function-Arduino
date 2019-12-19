  /*                                            
   *                                             
    Electro #2 :  4  2  : Electro #1      | X     0| Signal1      |X    0| Signal3
               :  3  1  :                 | 0     X|              |0    X|
               :
    Electro# 4 :  8  6  : Electro #3      |0      X| Signal2      |0    X| Signal4
               :  7  5  :                 |X      0|              |X    0|

               
  */

//  ************************************

#include <Console.h>

int Mod1_C = 93;
int Mod1_CounterC = 117;
int Mod2_C = 58;
int Mod2_CounterC = 76;

// *************************************

unsigned long DUR1;                             // Timed intervals between states
unsigned long DUR2;
unsigned long DUR3;
unsigned long DUR4;

long Data1 = 500;                               // Time to take Data without duplicates
long Data2 = 550;
long Data3 = 500;
long Data4 = 550;

unsigned long StartInt1;                        // Start and end variables for time intervals
unsigned long EndInt1;
unsigned long StartInt2;
unsigned long EndInt2;
unsigned long StartInt3;
unsigned long EndInt3;
unsigned long StartInt4;
unsigned long EndInt4;
  
/*#define signal1 A0
#define signal2 A1
#define signal3 A2
#define signal4 A4*/

#define Sensor_Pin1 6                                                 
#define Sensor_Pin2 7
#define Sensor_Pin3 8
#define Sensor_Pin4 9

#define Sensor_Pin5 10
#define Sensor_Pin6 11
#define Sensor_Pin7 12
#define Sensor_Pin8 13

#define P1 2
#define P2 3
#define P3 4
#define P4 5

int sensorState1 = 0;
int sensorState2 = 0;
int sensorState3 = 0;
int sensorState4 = 0;

int sensorState5 = 0;
int sensorState6 = 0;
int sensorState7 = 0;
int sensorState8 = 0;
    
  
class ELECTRO
{
    int MAG;
    long eventTime1;
    long OffTime1;
    
    unsigned long previousTime1;                  // Outer Loop for tigger times
    unsigned long previousTime2;
    unsigned long previousTime3;
    unsigned long previousTime4;

    unsigned long PrevData1;                     // Inner loop for data
    unsigned long PrevData2;
    unsigned long PrevData3;
    unsigned long PrevData4;
    
    public:
    
      ELECTRO(int Elec, long Trig, long OFF)
        {
        
         MAG = Elec;
         eventTime1 = Trig;
         OffTime1 = OFF;
         
         pinMode(MAG, OUTPUT);
         
         previousTime1 = 0;
         previousTime2 = 0;
         previousTime3 = 0;
         previousTime4 = 0;
        
        }

          void Electro1()
            {
      
            sensorState1 = digitalRead(Sensor_Pin1);
            sensorState2 = digitalRead(Sensor_Pin2);
          
            unsigned long currentTime = millis();
            unsigned long DataTime = millis();
            
              if((sensorState1 == LOW) && (sensorState2 == HIGH) && ( currentTime - previousTime1 >= eventTime1))      // STATE #1
                  {
                  sensorState1 = HIGH; 
                  previousTime1 = currentTime; 
                  digitalWrite(MAG, sensorState1);
                 // digitalWrite(signal1, sensorState1); 

                        StartInt1 = millis();
                                  
                  }
      
              if ((sensorState2 == LOW) && (sensorState1 == HIGH) && (currentTime - previousTime1 >= OffTime1))       // STATE #2
                  {
                  sensorState2 = LOW; 
                  previousTime1 = currentTime;    
                  digitalWrite(MAG, sensorState2);
                  //digitalWrite(signal2, sensorState2);     


                   unsigned long DataTime2 = millis();
                      
                      if(DataTime2 - PrevData2 >= Data2)
                      {
                         PrevData2 = DataTime2;
                             
                             EndInt2 = millis();
                             DUR2 = (EndInt2 - StartInt2);
      
                              Console.print("\t");
                              Console.print("Duration #2: ");
                              Console.println(DUR2);
                              EndInt2 = 0;
                             
                      }
          
                               if (DUR2 > 800)                                
                                 {
                                  Mod2_C = Mod2_C - 5;
                                  Console.print("Mod2_C: ");
                                  Console.print(Mod2_C);
                                  Console.println(" ");                       // Slow down model #2 CCW
                                          
                                 }
                                 
                                else
                                 {
                                  Console.print("Mod2_C: ");
                                  Console.print(Mod2_C);
                                  Console.print(" ");
                                  
                                 }
                      
                     }
            
            }
      
          void Electro2()
            {
      
            sensorState3 = digitalRead(Sensor_Pin3);
            sensorState4 = digitalRead(Sensor_Pin4);
          
            unsigned long currentTime = millis();
            
              if((sensorState3 == LOW) && (sensorState4 == HIGH) && ( currentTime - previousTime2 >= eventTime1))      // STATE #3
                  {
                  sensorState3 = HIGH; 
                  previousTime2 = currentTime; 
                  digitalWrite(MAG, sensorState3);
                 // digitalWrite(signal2, sensorState3); 

                      StartInt2 = millis();  
                                                                   
                  }
      
              if ((sensorState4 == LOW) && (sensorState3 == HIGH) &&  (currentTime - previousTime2 >= OffTime1))        // STATE #4
                  {
                  sensorState3 = LOW; 
                  previousTime2 = currentTime; 
                  digitalWrite(MAG, sensorState3);
                  //digitalWrite(signal1, sensorState3); 

                     unsigned long DataTime1 = millis();
                     
                     if(DataTime1 - PrevData1 >= Data1)
                      {
                       PrevData1 = DataTime1;
                       
                           EndInt1 = millis();
                           DUR1 = (EndInt1 - StartInt1);
                           
                            Console.print("Duration #1: ");
                            Console.print(DUR1);
                            EndInt1 = 0;
                      }


                           if (DUR1 > 800)                                
                                 {
                                  Mod2_CounterC = Mod2_CounterC - 5;
                                  Console.print("Mod2_CounterC: ");
                                  Console.print(Mod2_CounterC);
                                  Console.println(" ");                       // Slow down model #2 CC
                                          
                                 }
                                else
                                {
                                  Console.print("Mod2_CounterC: ");
                                  Console.print(Mod2_CounterC);
                                  Console.print(" ");
                                  
                                }
                                    
                                  
                  }      
            }
            
          void Electro3()
            {
      
            sensorState5 = digitalRead(Sensor_Pin5);
            sensorState6 = digitalRead(Sensor_Pin6);
          
            unsigned long currentTime = millis();
            
              if((sensorState5 == LOW) && (sensorState6 == HIGH) && ( currentTime - previousTime3 >= eventTime1))      // STATE #5
                  {
                      sensorState5 = HIGH; 
                      previousTime3 = currentTime;    
                      digitalWrite(MAG, sensorState5);
                      //digitalWrite(signal3, sensorState5);  

                            StartInt3 = millis();

                                   Console.print("Mod2_C Pulse = ");           // Passed Pulsed value from Electro1
                                    Console.print(Mod2_C);
                                    Console.print(" ");
                                    Mod2_C = 58;
                  
                                     
                                  
                  }
      
              if ((sensorState6 == LOW) && (sensorState5 == HIGH) && (currentTime - previousTime3 >= OffTime1))       // STATE #6
                  {
                      sensorState6 = LOW; 
                      previousTime3 = currentTime;    
                      digitalWrite(MAG, sensorState6);
                      //digitalWrite(signal4, sensorState6);   


                      unsigned long DataTime4 = millis();
                      
                      if(DataTime4 - PrevData4 >= Data4)
                      {
                         PrevData4 = DataTime4;
                             
                             EndInt4 = millis();
                             DUR4 = (EndInt4 - StartInt4);
      
                              Console.print("\t");
                              Console.print("Duration #4: ");
                              Console.println(DUR4);
                              EndInt4 = 0;
                      }
                  }

                 
            
            }
      
          void Electro4()
            {
      
            sensorState7 = digitalRead(Sensor_Pin7);
            sensorState8 = digitalRead(Sensor_Pin8);
          
            unsigned long currentTime = millis();
            
              if ((sensorState7 == LOW) && (sensorState8 == HIGH) && ( currentTime - previousTime4 >= eventTime1))      // STATE #7
                  {
                  sensorState7 = HIGH; 
                  previousTime4 = currentTime; 
                  digitalWrite(MAG, sensorState7);
                  //digitalWrite(signal4, sensorState7);

                        StartInt4 = millis();

                               Console.print("Mod2_CounterC Pulse = ");           // Passed Pulsed value from Electro1
                               Console.print(Mod2_CounterC);
                               Console.print(" ");
                               Mod2_CounterC = 76;
                                  
                  }
      
              if ((sensorState8 == LOW) && (sensorState7 = HIGH) && (currentTime - previousTime4 >= OffTime1))          // STATE #8
                  {
                  sensorState8 = LOW; 
                  previousTime4 = currentTime;    
                  digitalWrite(MAG, sensorState8); 
                  //digitalWrite(signal3, sensorState8);

                      unsigned long DataTime3 = millis();
                      
                      if(DataTime3 - PrevData3 >= Data3)
                      {
                         PrevData3 = DataTime3;
                             
                             EndInt3 = millis();
                             DUR3 = (EndInt3 - StartInt3);
      
                              Console.print("\t\t");
                              Console.print("Duration #3: ");
                              Console.print(DUR3);
                              EndInt3 = 0;

                        }
                  }
            
            }


 
};

   ELECTRO State1(P1, 85, 85);                  // MODIFY (Make these variables to be modified)(67,90)
   ELECTRO State2(P2, 100, 115);
   ELECTRO State3(P3, Mod2_C, Mod2_C);
   ELECTRO State4(P4, Mod2_CounterC, Mod2_CounterC);
    

void setup() 
  {

  Bridge.begin();
  Console.begin();
  Serial.begin(9600);

   while (!Console);
  
     // wait for Console port to connect.
  
    Console.println("You're connected to the Console!!!!");
  
  
    pinMode(Sensor_Pin1, INPUT);
    digitalWrite(Sensor_Pin1, HIGH);
    pinMode(Sensor_Pin2, INPUT);
    digitalWrite(Sensor_Pin2, HIGH);
    pinMode(Sensor_Pin3, INPUT);
    digitalWrite(Sensor_Pin3, HIGH);
    pinMode(Sensor_Pin4, INPUT);
    digitalWrite(Sensor_Pin4, HIGH);
    
    pinMode(Sensor_Pin5, INPUT);
    digitalWrite(Sensor_Pin5, HIGH);
    pinMode(Sensor_Pin6, INPUT);
    digitalWrite(Sensor_Pin6, HIGH);
    pinMode(Sensor_Pin7, INPUT);
    digitalWrite(Sensor_Pin7, HIGH);
    pinMode(Sensor_Pin8, INPUT);
    digitalWrite(Sensor_Pin8, HIGH);

   /* pinMode(signal1, OUTPUT);
    pinMode(signal2, OUTPUT);
    pinMode(signal3, OUTPUT);
    pinMode(signal4, OUTPUT);*/

    


    ElectroStart();                   //  Start Function Call

    
   }

void loop() 
{

    State1.Electro1();
    State2.Electro2();
    State3.Electro3();
    State4.Electro4();

       
    
}

void ElectroStart()
{
  
  delay(5000);            // Start UP
  
}

