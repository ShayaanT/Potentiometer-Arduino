//Shayaan Tanvir
//11 - 10 - 2020
//potentiometer timer with lcd
#include <Wire.h>

#include <LiquidCrystal_I2C.h>




LiquidCrystal_I2C lcd(0x27,16,2);
long last_change;
long last_value;
long timer_value;
int _1_i;
void setup()
{
lcd.init();
lcd.backlight();
pinMode(A1, INPUT);
pinMode(A4, INPUT);
pinMode(A5, INPUT);
pinMode( 5 , INPUT);
pinMode( 5 , INPUT);
}
 
void loop()
{
while(millis() - last_change < 6000)//you can change the time whatever you want if the potentiometer does not be turn, then the code will continue
{timer_value = map(analogRead(A1), 0, 1023, 1, 62);
if(timer_value != last_value){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Countdown for:");// the first title showed(answer will various)
lcd.setCursor(3,1);
lcd.print("sec");
lcd.setCursor(0,1);
lcd.print(timer_value);
last_value = timer_value;
last_change = millis();
}
delay(10);
}
lcd.clear();
   lcd.print("start in 5 sec..");
   delay(5000);// you can change the time for different second
long target = last_change + (timer_value * 30 * 60);
while(millis() < target){
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Time left:");
lcd.setCursor(3,1);
lcd.print("sec");
lcd.setCursor(0, 1);
lcd.print((target - millis()) / 30 / 40);
delay(50);
lcd.clear();
lcd.print("Time's up");
lcd.setCursor(0, 1);}
for(int a = 0; a < 5; a++){
//tone(8, 440, 1000);
delay(5000);
//noTone(8);
//delay(700);
}            
lcd.setBacklight(LOW);// you can change if you do not want the LCD monitor to black scre
lcd.clear();
while(1);
}
