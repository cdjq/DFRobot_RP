#include <DFRobot_RP.h>

DFRobot_RP rp;

String RECFileName;  //录音文件名

void setup(void){
  Serial.begin(115200);
  rp.begin();
  /*设置波特率，掉电保存，需掉电重启*/
  //rp.setBaudRate(115200);
  /*打开LED提示，掉电保存*/
  //rp.setLED(true);
  /*打开语音提示，掉电保存*/
  //rp.setPrompt(true);
  
  /*进入录音模式*/
  rp.switchFunction(rp.RECORD);
  delay(2000);
  /*开始录音*/
  rp.start();
  /*暂停录音*/
  //rp.pause();
  delay(5000);
  /*保存录音*/
  RECFileName = rp.saveRec();
}

void loop(){
  Serial.println(RECFileName);
  delay(1000);
}