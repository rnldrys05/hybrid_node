#include"msgscript.h"

int temp_pin = A0;            // Pin for LM35 output
char ron[] = "09339916003";
char gia[] = "09065538187";
char minnie[] = "09175468192";
char france[] = "09178484825";
char jerome[] = "09177453456";
unsigned int temp_val = 0;

void setup() {
  Serial.begin(38400);
  initGSM();
}

void loop() {
  char temp_buffer[128];
  serial_measure();
  const_temp_warning(temp_val,temp_buffer);
  delay(5000);
  send_msg(ron,temp_buffer);
  delay(5000);
}

void serial_measure(){
  temp_val = analogRead(temp_pin);     // Measure LM35 temp @ pinA0
  temp_val = temp_val*50000/1023;      // Convert Digital to Analog(Temp)
}
