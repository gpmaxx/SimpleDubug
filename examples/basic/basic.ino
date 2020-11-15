#include <Arduino.h>

#define DEBUG_SERIAL Serial  // comment out to not print debug
#include "Debug.h"

void setup() {

  dBegin(115200);
  // put your setup code here, to run once:

  dPrint("hello world\n");
  dPrint(F("hello world 2\n"));
  dPrintln(F("hello world 3"));
  dPrintf(F("hello world %d\n"),4);

  dFlush();  // flush the Serial output 

  dTrace(1); // uses flush to help trace crashes
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
