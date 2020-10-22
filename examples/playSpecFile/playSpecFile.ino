#include <DFRobot_RP.h>

DFRobot_RP rp;
void setup(void){
  Serial.begin(115200);
  while(!Serial);
  rp.begin();
  rp.playSpecFile(1);
  rp.playSpecFile("/DF_REC/FILE0000.MP3");
}

void loop(){




}