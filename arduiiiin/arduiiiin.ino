#include "SD.h"
#define SD_ChipSelectPin 4
#include "TMRpcm.h"
#include "SPI.h"
#include <avr/wdt.h>
TMRpcm tmrpcm;

// defines pins numbers
const int trigPin = 8;
const int echoPin = 10;
const int speaker = 9;

// defines variables
long duration;
int distance;


void setup(){

    tmrpcm.speakerPin = 9;
  wdt_disable(); //always good to disable it, if it was left 'on' or you need init time


pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
//pinMode(speaker, OUTPUT);
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600);

}

void loop() {

// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.println(distance);

while(distance<10){
SD.begin(4);
tmrpcm.setVolume(5);
tmrpcm.play("3.wav");
tmrpcm.play("hi3.wav");
tmrpcm.play("hi2.wav");
delay(10000);

} 
  wdt_enable(WDTO_8S);
}



//this makes sure the WDT is reset immediately when entering the
//function, but we can still benefit from a real 'delay'.
//upon leaving the function, we reset it again.
//i realize timing will be loose, you can always do something with
//millies() if you need strict timing.
//you might also need to adjust the '1000' if you WDT is shorter
//
void wdt_delay(unsigned long msec){
wdt_reset();

while(msec > 1000) {
wdt_reset();
delay(1000);
msec -= 1000;
}
delay(msec);
wdt_reset();
}
//
////to reload the board, you only have to delay > WDT
////another option is to set the WDT very short, and do a short delay
//
void wdt_reload() {
delay(8001);
}
