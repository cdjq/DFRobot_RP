#include <DFRobot_RP.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial1(2, 3);  //RX  TX

DFRobot_RP rp;
void setup(void){
  Serial.begin(115200);
  Serial1.begin(115200);
  while(!rp.begin(Serial1)){
    Serial.println("初始化失败，请检查接线！");
    delay(1000);
  }
  /*设置音量为20*/
  rp.setVol(20);
  Serial.print("VOL:");
  /*获取音量*/
  Serial.println(rp.getVol());
  /*进入音乐模式*/
  rp.switchFunction(rp.MUSIC);
  /*等待提示音播放完*/
  delay(2000);
  /*设置播放模式为全部循环*/
  rp.setPlayMode(rp.ALLCYCLE);
  Serial.print("PlayMode:");
  /*获取播放模式*/
  Serial.println(rp.getPlayMode());
}

void loop(){
  /*开始播放*/
  rp.start();
  delay(3000);
  /*暂停播放*/
  rp.pause();
  delay(3000);
  /*播放下一曲*/
  rp.next();
  delay(3000);
  /*播放上一曲*/
  rp.last();
  delay(3000);
  /*播放录音文件夹下指定编号文件(FILE0000)一次*/
  rp.playSpecFile(1);
  while(1);
  /*删除正在播放的文件*/
  //rp.delCurFile();
}