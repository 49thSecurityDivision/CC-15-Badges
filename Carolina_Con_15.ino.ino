#include "LedControl.h"

#define DATA 8
#define CLK 7
#define LOAD 6
 
LedControl lc=LedControl(DATA, CLK, LOAD, 1);
 
void setup() {
     lc.shutdown(0,false);
     lc.setIntensity(0,0);
     lc.clearDisplay(0);
     testpattern(100);
}
 
void clear() {
     lc.clearDisplay(0);
}
 
void clear(unsigned long dt) {
     delay(dt);
     lc.clearDisplay(0);
}
 
void setl(int x, int y, bool power) {
     lc.setLed(0, x, 4-y, power);
}
 
void setl(int z, bool power) {
     lc.setLed(0, z%4, z/4, power);
}
 
void setx(int x, bool power) {
     for (int y=0;y<4;y++) {
         setl(x, y, power);
     }
}
 
void sety(int y, bool power) {
     for (int x=0;x<4;x++) {
         setl(x, y, power);
     }
}
 
void testpattern(unsigned int d) {
  for (int i=0;i<4;i++) {
    sety(i, true);
    delay(d);
  }
}
 
void pattern0(unsigned int d) {
     boolean value;
     for (int i=0;i<68;i++) {
         value = ((i%8) < 4) || (i>64);
         if ( (i%2) + (i%3) % 2 == 0 ) {
        setx(i%4, value);
     } else {
       sety(i%4, value);
     }
     delay(d);
     }
 
}
 
void pattern1(unsigned int d) {
    for (int i=0;i<128;i++) {
        setl( (i-(i%16)) + ((i%16) + (i%12)), (i%8>4) );
        delay(d);      
    }
}


void patternC(unsigned int d) {
  for (int i=0;i<10;i++) {
    sety(0, true);
    sety(3, true);
    setx(0, true);
    clear(50);
  }
}

void patternAll(unsigned int d) {
  for(int ii=0;ii<10;ii++) {
    setx(0,true);
    setx(1,true);
    setx(2,true);
    setx(3,true);
    clear(50);
  }
}
 
unsigned int dt = 80;

void loop() {
     clear(dt);
     pattern0(dt);
}
