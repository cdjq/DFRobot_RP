#include <DFRobot_RP.h>

DFRobot_RP rp;
void setup(void){
    Serial.begin(115200);
  while(!Serial);
  rp.begin();
  rp.setBaudRate(115200);
 
  rp.setLED(true);
  rp.setPrompt(true);
  rp.setVol(10);
  Serial.println(rp.getVol());
  rp.switchFunction(rp.MUSIC);
   rp.setPlayMode(rp.ALLCYCLE);
  rp.start();
  delay(3000);
  rp.next();
  delay(3000);
  rp.last();
  delay(3000);
  
  rp.delCurFile();
  
  rp.switchFunction(rp.RECORD);
  rp.start();
  delay(3000);
  rp.saveRec();
  //需不需要返回文件名。
  
  rp.playSpecFile("/DF_REC/FILE0013.MP3");
  delay(3000);
  rp.playSpecFile(13);
  delay(3000);
 
  Serial.println(rp.getPlayMode());
  
  rp.switchFunction(rp.UFDISK);
}

void loop(){
}