#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;

#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

int typeSelect = 6;// select type . See bellow

String type[]={ "GyroAng and Ang",// select 0
                "GyroAng and Acc",// select 1
                "GyroAng and Gyro",// select 2
                "AccAng and Acc",// select 3
                "AccAng & Gyro",// select 4
                "AccAng and Ang",// select 5
                "Angle and Temp"// select 6
              };
              
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  // initialize the LCD, 
  //lcd.begin();
  // Turn on the blacklight and print a message.
  lcd.backlight();    
}

void loop() {
  mpu6050.update();

  if(millis() - timer > 1000){
    
    Serial.println("=======================================================");
    Serial.print("temp : ");Serial.println(mpu6050.getTemp());
    Serial.print("accX : ");Serial.print(mpu6050.getAccX());
    Serial.print("  accY : ");Serial.print(mpu6050.getAccY());
    Serial.print("  accZ : ");Serial.println(mpu6050.getAccZ());
  
    Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
    Serial.print("  gyroY : ");Serial.print(mpu6050.getGyroY());
    Serial.print("  gyroZ : ");Serial.println(mpu6050.getGyroZ());
  
    Serial.print("accAngleX : "); Serial.print(mpu6050.getAccAngleX());
    Serial.print("  accAngleY : ");Serial.println(mpu6050.getAccAngleY());
  
    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
    Serial.print("  gyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
    Serial.print("  gyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    
    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    Serial.print("  angleY : ");Serial.print(mpu6050.getAngleY());
    Serial.print("  angleZ : ");Serial.println(mpu6050.getAngleZ());
    Serial.println("=======================================================");
    timer = millis();
                        
     
  }// if
  lcd.clear();// clearn previous values from screen
  switch (typeSelect)
  {
    
  case 0:// display GyroAngle and Angle
   lcdDisplay(mpu6050.getGyroAngleX(),mpu6050.getGyroAngleY(),mpu6050.getGyroAngleZ(), 
             mpu6050.getAngleX(),mpu6050.getAngleY(),mpu6050.getAngleZ()                                
            );
   break;

  case 1:// display GyroAngle and Acceleration value
   lcdDisplay(mpu6050.getAngleX(),mpu6050.getAngleY(),mpu6050.getAngleZ(), 
             mpu6050.getAccX(),mpu6050.getAccY(),mpu6050.getAccZ()                                
            );
   break;  

  case 2:// display GyroAngle and Gyroscope value
   lcdDisplay(mpu6050.getAngleX(),mpu6050.getAngleY(),mpu6050.getAngleZ(), 
            mpu6050.getGyroX(),mpu6050.getGyroY(),mpu6050.getGyroZ()                                
            );
   break;

  case 3:// display Acceleration Angle and Acceleration value
   lcdDisplay(mpu6050.getAccAngleX(),mpu6050.getAccAngleY(),0.0, 
           mpu6050.getAccX(),mpu6050.getAccY(),mpu6050.getAccZ()                                
            );
   break; 

  case 4:// display Acceleration Angle and Gyro value
   lcdDisplay(mpu6050.getAccAngleX(),mpu6050.getAccAngleY(), 0.0, 
              mpu6050.getGyroX(),mpu6050.getGyroY(),mpu6050.getGyroZ()                                 
            );
   break;
   
  case 5:// display Acceleration Angle and Angle
   lcdDisplay(mpu6050.getAccAngleX(),mpu6050.getAccAngleY(), 0.0, 
           mpu6050.getAngleX(),mpu6050.getAngleY(),mpu6050.getAngleZ()                                   
            );
   break; 
   
  case 6:// display angle and Temperature
   lcdDisplay(mpu6050.getAngleX(),mpu6050.getAngleY(),mpu6050.getAngleZ(), 
           mpu6050.getTemp(), 0.0, 0.0                                 
            );
   break;                      
  }// switch end
    delay(100);
}
void lcdDisplay(float x, float y, float z, float x1, float y1, float z1)
{
   // Robojax.com MPU6050 Demo with LCD2004-I2C Display
   lcd.setCursor (0,0); //
   lcd.print(type[typeSelect]);  
   lcd.setCursor (17,0); //
   String dis = "("+String(typeSelect)+")";
   lcd.print(dis);    

    if(typeSelect !=6){
   lcd.setCursor (0,1); //character zero, line 1
   lcd.print("X:");
   lcd.setCursor (2,1); //
   lcd.print(x);  
   /////////////////////
   lcd.setCursor (10,1); //character zero, line 1
   lcd.print("X1:");
   lcd.setCursor (13,1); //
   lcd.print(x1);       
   
   lcd.setCursor (0,2); //character zero, line 2
   lcd.print("Y:");
   lcd.setCursor (2,2); //
   lcd.print(y);
   ////////////////////////
   lcd.setCursor (10,2); //character zero, line 1
   lcd.print("Y1:");
   lcd.setCursor (13,2); //
   lcd.print(y1);   
   

   lcd.setCursor (0,3); //character zero, line 3
   lcd.print("Z:");
   lcd.setCursor (2,3); //
   lcd.print(z);   
   //////////////////////
   lcd.setCursor (10,3); //character zero, line 3
   lcd.print("Z1:");
   lcd.setCursor (13,3); //
   lcd.print(z1);   
    }else{
   lcd.setCursor (0,1); //character zero, line 1
   lcd.print("X:");
   lcd.setCursor (2,1); //
   lcd.print(x);  
   /////////////////////
   lcd.setCursor (10,1); //character zero, line 1
   lcd.print("TMP: ");
   lcd.setCursor (15,1); //
   lcd.print(x1);       
   
   lcd.setCursor (0,2); //character zero, line 2
   lcd.print("Y:");
   lcd.setCursor (2,2); //
   lcd.print(y); 
   

   lcd.setCursor (0,3); //character zero, line 3
   lcd.print("Z:");
   lcd.setCursor (2,3); //
   lcd.print(z);   

  
    }
 
}
