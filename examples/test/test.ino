#include <DFRobot_RP.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial1(2, 3);  //RX  TX

DFRobot_RP rp;

void setup(){
  Serial.begin(115200);
  Serial1.begin(115200);
  while(!rp.begin(Serial1)){
    Serial.println("Init failed, please check the wire connection！");
    delay(1000);
  }
  Serial.print("setLED = ");
  Serial.println(rp.setLED(true));
  Serial.print("setPrompt = ");
  Serial.println(rp.setPrompt(true));
  Serial.print("setVol = ");
  Serial.println(rp.setVol(10));
  Serial.print("getVol = ");
  Serial.println(rp.getVol());
  Serial.print("switchFunction = ");
  Serial.println(rp.switchFunction(rp.MUSIC));
  delay(3000);
  Serial.print("setPlayMode = ");
   Serial.println(rp.setPlayMode(rp.ALLCYCLE));
  Serial.print("getPlayMode = ");
   Serial.println(rp.getPlayMode());
  Serial.print("start = ");
  Serial.println(rp.start());
  delay(3000);
  Serial.print("next = ");
  Serial.println(rp.next());
  delay(10000);
  Serial.print("last = ");
  Serial.println(rp.last());
  delay(10000);

  rp.playSpecFile("/DF_REC/FILE0049.MP3");
  delay(3000);

  rp.playSpecFile(15);
  delay(3000);
  Serial.print("start = ");
  Serial.println(rp.delCurFile());
  Serial.print("switchFunction = ");
  Serial.println(rp.switchFunction(rp.RECORD));
  delay(3000);
  Serial.print("start = ");
  Serial.println(rp.start());
  delay(10000);
  Serial.print("saveRec = ");
  Serial.println(rp.saveRec());
  //Whether the file name needs to be returned
  Serial.print("switchFunction = ");
  Serial.println(rp.switchFunction(rp.UFDISK));
}

void loop(){
}
