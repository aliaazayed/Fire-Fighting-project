int flame_sensor_pin1 = 9;       // initializing pin 4 as the LEFT sensor output pin
int flame_sensor_pin2 = 8;       // initializing pin 4 as the RIGHT  sensor output pin
int flame_sensor_pin3 = 10  ;       // initializing pin 4 as the FORWARD sensor output pin
int buzzer_pin = 13;             // initializing pin 8 as the buzzer pin
int led_pin = 12;                // initializing the pin 2 as the led pin

int lm1=2;
int lm2=3;
int rm1=4;
int rm2=5;

 
int flame_pin = 0;           // state of sensor
 
void playMelody(void) ;
int flame_sensor_detect (void) ;
void setup()
{
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
  
  pinMode(led_pin, OUTPUT);             // declaring led pin as output pin
  pinMode(flame_sensor_pin1, INPUT);     // declaring sensor pin as input pin for Arduino
  pinMode(flame_sensor_pin2, INPUT);     // declaring sensor pin as input pin for Arduino
  pinMode(flame_sensor_pin3, INPUT);     // declaring sensor pin as input pin for Arduino
  pinMode(buzzer_pin, OUTPUT);          // declaring buzzer pin as output pin
  Serial.begin(9600);                   // setting baud rate at 9600
  
  digitalWrite(lm1, LOW);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, LOW);
  digitalWrite(rm2, LOW);
}
 
 
void loop()
{
    flame_pin = flame_sensor_detect () ;
  if (flame_pin == 1)
  {
    flame_pin = 0 ;
    digitalWrite(lm1, LOW);
        digitalWrite(lm2, LOW);
        digitalWrite(rm1, HIGH);
        digitalWrite(rm2, LOW);
        
        Serial.println("FLAME1, FLAME1, FLAME1");
        digitalWrite(led_pin, HIGH);                      // if state is high, then turn high the led
        playMelody();                                     // play a melody on the buzzer
  }
  else if (flame_pin == 2)
  {
    flame_pin = 0 ;
        digitalWrite(lm1, LOW);
        digitalWrite(lm2, HIGH);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        
        Serial.println("FLAME2, FLAME2, FLAME2");
        digitalWrite(led_pin, HIGH);                      // if state is high, then turn high the led
        playMelody();                                     // play a melody on the buzzer
  }
  else if (flame_pin == 3)
  {
    flame_pin = 0 ;
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH );
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
        
        Serial.println("FLAME3, FLAME3, FLAME3");
        digitalWrite(led_pin, HIGH);                      // if state is high, then turn high the led
        playMelody();                                     // play a melody on the buzzer
  }
  else 
  {
    Serial.println("no flame");
        digitalWrite(led_pin, LOW);                       // otherwise turn it low
        noTone(buzzer_pin);                               // stop playing any tone
  }
  delay (100);
  digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
}
 
 
void playMelody(void)
{
  // Play a simple melody: C4, E4, G4, C5
  tone(buzzer_pin, 262, 200);             // C4
  delay(200);
  tone(buzzer_pin, 330, 200);             // E4
  delay(200);
  tone(buzzer_pin, 392, 200);             // G4
  delay(200);
  tone(buzzer_pin, 523, 200);             // C5
  delay(200);
}

int flame_sensor_detect (void)
{
  if (digitalRead(flame_sensor_pin1))
    return 1 ;
  else if (digitalRead(flame_sensor_pin2))
    return 2 ;
  else if (digitalRead(flame_sensor_pin3))
    return 3 ;
  else 
    return 0 ;
}

