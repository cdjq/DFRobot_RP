#include <DFRobot_RP.h>

DFRobot_RP rp;
void setup(void){
  Serial.begin(115200);
  rp.begin();
  /*设置音量为20*/
  rp.setVol(20);
  Serial.print("VOL:");
  /*获取音量*/
  Serial.println(rp.getVol());
  /*进入音乐模式*/
  rp.switchFunction(rp.MUSIC);
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
  /*播放指定路径文件*/
  rp.playSpecFile("/DF_REC/FILE0000.MP3");
  delay(3000);
  /*播放第1个文件，此顺序是物理顺序，也就是写入到设备的先后顺序*/
  //rp.playSpecFile(1);
  //delay(3000);
  /*删除正在播放的文件*/
  //rp.delCurFile();
}