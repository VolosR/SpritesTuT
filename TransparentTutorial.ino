#include <TFT_eSPI.h> 
#include "arrow.h"
#include "city.h"
TFT_eSPI tft = TFT_eSPI(); 
TFT_eSprite arrowSprite= TFT_eSprite(&tft);
TFT_eSprite background= TFT_eSprite(&tft);
TFT_eSprite txtSprite= TFT_eSprite(&tft);

int x=20;
void setup() {
 tft.init();
 tft.setRotation(1);
 tft.setSwapBytes(true);
 

 background.createSprite(320,170);
 background.setSwapBytes(true);
 arrowSprite.createSprite(96,96);
 txtSprite.createSprite(80,80);
 txtSprite.setTextColor(TFT_WHITE,TFT_BLACK);
 //arrowSprite.setSwapBytes(true);

}

void loop() {
 background.pushImage(0,0,320,170,city);
 
 txtSprite.fillSprite(TFT_BLACK);
 txtSprite.drawString(String(x),0,0,6);

 arrowSprite.pushImage(0,0,96,96,arrow);
 arrowSprite.pushToSprite(&background,x,40,TFT_BLACK); 
 txtSprite.pushToSprite(&background,200,30,TFT_BLACK); 
 
 background.pushSprite(0,0);
 x++;

 if(x>330)
 x=-100;

}
