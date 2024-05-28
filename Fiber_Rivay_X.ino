#include <Arduino.h>
#include <U8x8lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8X8_SH1106_128X32_VISIONOX_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE); 

void setup(void){
  pinMode(A6,INPUT);
  u8x8.begin();
  u8x8.setFont(u8x8_font_8x13B_1x2_f);
  u8x8.setCursor(1, 1);
  u8x8.print("Fiber Rivay X");
  delay(5000);
  u8x8.setCursor(1, 1);
  u8x8.print("             ");

}


void loop(void){
  int pos=analogRead(A6);
  int pos1= map(pos,0,1025,0,101);
    u8x8.refreshDisplay();
    u8x8.setFont(u8x8_font_courB24_3x4_n);

    if(pos1 < 100){
    u8x8.setCursor(4, 0);
    u8x8.print(pos1);
    u8x8.setCursor(9, 0);
    u8x8.print(" ");
    u8x8.refreshDisplay();
    delay(300);
    }
   else if(pos1 == 100){
    u8x8.setCursor(4, 0);
    u8x8.print("100");
    delay(300);
   }
   if(pos1 >= 10){
  u8x8.setCursor(5, 0);
  u8x8.print("  ");

   }
}

