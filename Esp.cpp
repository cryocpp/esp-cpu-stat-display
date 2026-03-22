#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1315_128X64_NONAME_1_SW_I2C screen(U8G2_R0,/* SCK serial clock */ 22, /*sda Serial data */ 21, /* reset=*/ U8X8_PIN_NONE); 
void updatescreen(const char* updatepercent){
  screen.firstPage(); 
  do {
    screen.setFont(u8g2_font_ncenB14_tr);
    screen.drawStr(10,20,"CPU USAGE:"); 
    screen.drawStr(10,40,updatepercent); 
  } while ( screen.nextPage() );   
}
void setup() {
  screen.begin(); 
  Serial.begin(9600); 
}

void loop() {
  if(Serial.available()){ 
    String cpupercentage = Serial.readStringUntil('\n');  
    const char* letsgo = cpupercentage.c_str(); 
    updatescreen(letsgo);
  }
}
