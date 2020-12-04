#include <DFRobot_RP.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial1(2, 3);  //RX  TX

DFRobot_RP rp;

String RECFileName;  //Recording file name 

void setup(void){
  Serial.begin(115200);
  Serial1.begin(115200);
  while(!rp.begin(Serial1)){
    Serial.println("Init failed, please check the wire connection!");
    delay(1000);
  }
  /*Set baud rate, power-down data save，need to power down and restart*/
  //rp.setBaudRate(115200);
  /*Open LED prompt, power-down save*/
  //rp.setLED(true);
  /*Open voice prompt, power-down save*/
  //rp.setPrompt(true);
  
  /*Enter Recording mode */
  rp.switchFunction(rp.RECORD);
  /*Wait for the end of prompt tone/
  delay(2000);
  /*Start recording*/
  rp.start();
  /*Pause*/
  //rp.pause();
  delay(5000);
  /*Save*/
  RECFileName = rp.saveRec();
}

void loop(){
  Serial.println(RECFileName);
  delay(1000);
}
