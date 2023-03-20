#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(false);

  // initialize the LCD, 
  //lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.clear();
   lcd.setCursor (0,0); //
   lcd.print("Robojax MPU-6050"); 
   lcd.setCursor (0,0); //   
 
   lcd.print("Please Wait - 3");  
   lcd.setCursor (0,1); // 
   delay(1000);        
   lcd.print("Please Wait - 2");  
   delay(1000); 
   lcd.setCursor (0,1); //      
   lcd.print("Please Wait - 1");  
   delay(1000);       
}

void loop() {

  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("  angleZ : ");
  Serial.println(mpu6050.getAngleZ());
  
  lcd.clear();// clearn previous values from screen
   lcdDisplay(
            mpu6050.getAngleX(), // send angle X
            mpu6050.getAngleY(), // send angle Y
            mpu6050.getAngleZ()  // send angle Z
            );                       
   delay(100);

}
void lcdDisplay(float x, float y, float z)
{
   // Robojax.com MPU6050 Demo with LCD2004-I2C Display
   lcd.setCursor (0,0); //
   lcd.print("Robojax MPU-6050");  
 
   lcd.setCursor (0,0); //character zero, line 1
   lcd.print("X:");
   lcd.setCursor (2,0); //
   lcd.print(x); 
   delay(1000);  
   
   lcd.setCursor (0,1); //character zero, line 2
   lcd.print("Y:");
   lcd.setCursor (2,1); //
   lcd.print(y);
   delay(1000);

   lcd.setCursor (0,3); //character zero, line 3
   lcd.print("Angle Z:");
   lcd.setCursor (9,3); //
   lcd.print(z);   
 
}
