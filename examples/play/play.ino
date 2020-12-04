#include <DFRobot_RP.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial1(2, 3);  //RX  TX

DFRobot_RP rp;
void setup(void){
  Serial.begin(115200);
  Serial1.begin(115200);
  while(!rp.begin(Serial1)){
    Serial.println("Init failed, please check the wire connection!");
    delay(1000);
  }
  /*Set volume to 20*/
  rp.setVol(20);
  Serial.print("VOL:");
  /*Get volume*/
  Serial.println(rp.getVol());
  /*Enter music mode*/
  rp.switchFunction(rp.MUSIC);
  /*Wait for the end of prompt tone*/
  delay(2000);
  /*Set playback mode to "repeat all"*/
  rp.setPlayMode(rp.ALLCYCLE);
  Serial.print("PlayMode:");
  /*Get playback mode*/
  Serial.println(rp.getPlayMode());
}

void loop(){
  /*Start*/
  rp.start();
  delay(3000);
  /*Pause*/
  rp.pause();
  delay(3000);
  /*Next*/
  rp.next();
  delay(3000);
  /*Last*/
  rp.last();
  delay(3000);
  /*Play the specific file(FILE0000) in recording files once*/
  rp.playSpecFile(1);
  while(1);
  /*Delete the currently-playing file*/
  //rp.delCurFile();
}
