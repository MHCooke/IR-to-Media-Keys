/*  Based on hashDecode.ino example.

    Modified by Matthew Cooke
    This will only work on boards with a built in USB controller, this
    has been tested on a 32u4/'Pro Micro'.
*/

// We only want the raw hash since the remote is an unknown protocol.
#include <IRLibDecodeBase.h>
#include <IRLib_HashRaw.h>
#include <IRLibCombo.h>
#include <HID-Project.h>

// Now declare an instance of that decoder.
IRdecode myDecoder;

// Include a receiver either this or IRLibRecvPCI or IRLibRecvLoop
#include <IRLibRecv.h>
IRrecv myReceiver(2);    //create a receiver on pin number 2

void setup() {
  myReceiver.enableIRIn(); // Start the receiver

  Consumer.begin();
}

void loop() {
  if (myReceiver.getResults()) {
    myDecoder.decode();
    switch (myDecoder.value) {
      case 0x70E026C7:
        // Stop
        Consumer.write(MEDIA_STOP);
        break;

      case 0x91EE57C7:
        // Pause / Play
        Consumer.write(MEDIA_PLAY_PAUSE);
        break;

      case 0x7211819F:
        // Skip forwards
        Consumer.write(MEDIA_NEXT);
        break;

      case 0x6048D163:
        // Skip backwards
        Consumer.write(MEDIA_PREV);
        break;
    }
    myReceiver.enableIRIn();
  }
}
