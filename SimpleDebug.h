// Simple Debug Library

// Created:   gpmaxx   2020-02-08
// Modified:  gpmaxx   2020-11-14 - added dTrace, renamed

#ifndef SIMPLE_DEBUG_H
#define SIMPLE_DEBUG_H

	#ifdef SIMPLEDEBUG_SERIAL

				
		#define dPrint(...) SIMPLEDEBUG_SERIAL.print(__VA_ARGS__)
		#define dPrintln(...) SIMPLEDEBUG_SERIAL.println(__VA_ARGS__)
		#define dBegin(...) SIMPLEDEBUG_SERIAL.begin(__VA_ARGS__)
                
 
void dPrintf(const char *format, ...) {
  char buf[80];
  va_list ap;
  va_start(ap,format);
  vsnprintf(buf, sizeof(buf), (const char *)format, ap);
  SIMPLEDEBUG_SERIAL.print(buf);
  va_end(ap);
}

void dPrintf(const __FlashStringHelper *format, ...) {
  char buf[80];
  va_list ap;
  va_start(ap,format);
  vsnprintf_P(buf, sizeof(buf), (const char *)format, ap);
  SIMPLEDEBUG_SERIAL.print(buf);
}

void dFlush() {
  SIMPLEDEBUG_SERIAL.flush();
}

void dTrace(const uint8_t x) {
  dPrintf(F("-----%d-----\n"),x);
  dFlush();
}

	#else
		#define dPrint(...)
		#define dPrintln(...)
		#define dBegin(...)
		#define dPrintf(...)
		#define dFlush()
		#define dTrace(...)
	#endif

#endif
