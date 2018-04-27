// Include the correct display library
// For a connection via I2C using Wire include
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
#include <time.h>
#include <chrono>


// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, D1, D2);
float progress = 0;

using namespace std::chrono;
int sec;
int count;
#define DEMO_DURATION 3000
void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();


  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  
  drawVimond();
  display.display();
}

void drawVimond() {
    
    
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_16);
 
    //void drawProgressBar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t progress);

}

void drawIO() {
  lefthand();
}

void lefthand(){
}


void loop() {
  if (progress <= 126) {
    display.clear();
    display.drawString(0, 10, "Vimond IO mini");
    display.drawString(0, 26, "loading..");
    display.drawProgressBar(0,48,127,8,int(progress));
    display.display(); 
    
  }
    
  if (progress > 127 ) {
    display.clear();
    display.drawRect(0,0,20,64);
    
    for(int i = 0; i < 64; i += 9) {
      // assets
      display.drawLine(0,i,17,i);
      display.drawLine(0,i-2,8,i-2);
      display.drawLine(14,i-2,16,i-2);
      
    }

    //source and player
    display.drawRect(19,0,54,30);
    display.fillRect(19,29,54,6);
    display.drawRect(74,0,54,30);
    display.fillRect(74,29,54,6);

    // noise 
    for(int iy = 1;iy<29;iy++) {
        for (int ix = 20; ix < 19+54;ix++ ) {
          if(rand() % 2 == 1) {
            
            display.setPixel(ix,iy);
          }
        }
      }
    

    //timeline
    
    // tools
    display.drawRect(19,36,6,64-36);
      int icon = 2;
      
      for (int i = 0; i < 11; i+=3) {
        display.fillRect(21,38+(i*icon),2,2);
        }
    
    //timeline
    for (int i = 0; i < 4; i++) {
      display.drawHorizontalLine(26, 38+(i*8), 128-9-6-21);
      }

   // scrubber

   display.drawVerticalLine()
   

    //audiometer
    display.drawRect(128-9,36,9,64-36);
    // graphs
    display.fillRect(128-7,34,3,sin(progress));
    display.display();
  }
  progress += 1;

}

