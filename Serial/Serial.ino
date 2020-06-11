/*  Based on hashDecode.ino example.
 *  
 *  Modified by Matthew Cooke
 */
 
// We only want the raw hash since the remote is an unknown protocol.
#include <IRLibDecodeBase.h> 
#include <IRLib_HashRaw.h>  
#include <IRLibCombo.h>   

// Now declare an instance of that decoder.
IRdecode myDecoder;

// Include a receiver either this or IRLibRecvPCI or IRLibRecvLoop
#include <IRLibRecv.h> 
IRrecv myReceiver(2);    //create a receiver on pin number 2

// Variables
bool pause_toggle = 0; // 0 = play, 1 = pause

void setup() {
  Serial.begin(9600);
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println("Receiver ready");
}

void loop() {
  if(myReceiver.getResults()) {
    myDecoder.decode();
    switch (myDecoder.value) {
      case 0x70E026C7:
        // Stop
        Serial.println("Stop");
        break;

      case 0x91EE57C7:
        // Pause / Play
        pause_toggle = !pause_toggle;
        // Serial.println(pause_toggle ? "Pause" : "Play");
        Serial.println("Pause/Play");
        break;

      case 0x7211819F:
        // Skip forwards
        Serial.println(">>");
        break;

      case 0x6048D163:
      // Skip backwards
      Serial.println("<<");
      break;
    }
    myReceiver.enableIRIn(); 
  }
}
