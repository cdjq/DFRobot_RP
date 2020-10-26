#include <DFRobot_RP.h>


DFRobot_RP::DFRobot_RP(){

}

bool DFRobot_RP::begin(Stream &s){
   sPacket_t cmd;
   _s = &s;
   cmd = pack();
   
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }
}

uint8_t DFRobot_RP::getVol(){
   String vol = "";
   sPacket_t cmd;
   cmd = pack("VOL","?");
   writeATCommand(cmd.str,cmd.length);
   String str = readAck(12);
   vol += str[7];
   if(str[8] != 0X5D)
         vol += str[8];
   return (uint8_t)atoi(vol.c_str());
}

bool DFRobot_RP::setVol(uint8_t vol){
   sPacket_t cmd;
   cmd = pack("VOL",String(vol));
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }
}

DFRobot_RP::ePlayMode_t DFRobot_RP::getPlayMode(){

   String playMode = "";
   sPacket_t cmd;
   cmd = pack("PLAYMODE","?");
   writeATCommand(cmd.str,cmd.length);
   String str = readAck(13);
   playMode = str[10];
   //Serial.println(str);
   if(str[11] == '\r'  && str[12] == '\n')
     return (ePlayMode_t)atoi(playMode.c_str());
   else 
     return ERROR;

}
bool DFRobot_RP::setBaudRate(uint32_t baud){
   sPacket_t cmd;
   cmd = pack("BAUDRATE",String(baud));
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }
}
bool DFRobot_RP::switchFunction(eFunction_t function){
   sPacket_t cmd;
   cmd = pack("FUNCTION",String(function));
   curFunction = function;
   writeATCommand(cmd.str,cmd.length);
   pauseFlag = 0;
   if(readAck() == "OK\r\n"){
    delay(1300);
    return true;
   } else{
    return false;
   }
}
bool DFRobot_RP::setPlayMode(ePlayMode_t mode){
   if(curFunction != MUSIC) return false;
   sPacket_t cmd;
   cmd = pack("PLAYMODE",String(mode));
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }
}
bool DFRobot_RP::setLED(bool on){

   sPacket_t cmd;
   String mode;
   if(on == true )
     mode = "ON";
   else 
     mode = "OFF";
   cmd = pack("LED",mode);
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }

}
bool DFRobot_RP::setPrompt(bool on){
   sPacket_t cmd;
   String mode;
   if(on == true )
     mode = "ON";
   else 
     mode = "OFF";
   cmd = pack("PROMPT",mode);
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }
}

bool DFRobot_RP::next(){
   if(curFunction != MUSIC) return false;
   sPacket_t cmd;
   cmd = pack("PLAY","NEXT");
   writeATCommand(cmd.str,cmd.length);
   pauseFlag = 1;
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }
}


bool DFRobot_RP::last(){
   if(curFunction != MUSIC) return false;
   sPacket_t cmd;
   cmd = pack("PLAY","LAST");
   writeATCommand(cmd.str,cmd.length);
   pauseFlag = 1;
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }
}
bool DFRobot_RP::start(){
   sPacket_t cmd;
   if(curFunction == MUSIC){
     cmd = pack("PLAY","PP");
   }else if(curFunction == RECORD){
     cmd = pack("REC","RP");
   }else{
      return false;
   }

   if(pauseFlag == 1) return false;
   pauseFlag = 1;
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }
}

bool DFRobot_RP::pause(){
   sPacket_t cmd;
   if(curFunction = MUSIC){
     cmd = pack("PLAY","PAUSE");
   }else if(curFunction = RECORD){
     cmd = pack("REC","PAUSE");
   }else{
      return false;
   }
   if(pauseFlag == 0) return false;
   pauseFlag = 0;
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }
}

String DFRobot_RP::saveRec(){
   if(curFunction != RECORD) return "error";
   sPacket_t cmd;
   cmd = pack("REC","SAVE");
   writeATCommand(cmd.str,cmd.length);
   pauseFlag = 0;
   String str = readAck(22);
   if(str != "error"){
    return str;
   } else{
    return "error";
   }
}

bool DFRobot_RP::delCurFile(){
   if(curFunction != MUSIC) return false;
   sPacket_t cmd;
   
   cmd = pack("DEL");
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return true;
   } else{
    return false;
   }

}
void DFRobot_RP::playSpecFile(String str){
   if(curFunction != MUSIC) return false;
   sPacket_t cmd;
   cmd = pack("PLAYFILE",str);
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return ;
   } else{
    return ;
   }
}
void DFRobot_RP::playSpecFile(int16_t num){
   if(curFunction != MUSIC) return false;
   sPacket_t cmd;
   cmd = pack("PLAYFILE",String(num));
   writeATCommand(cmd.str,cmd.length);
   if(readAck() == "OK\r\n"){
    return ;
   } else{
    return ;
   }


}
DFRobot_RP::sPacket_t DFRobot_RP::pack(String cmd ,String para){
  sPacket_t pack;
  atCmd = "";
  atCmd += "AT";
  if(cmd != " "){
   atCmd += "+";
   atCmd += cmd;
  }
 
  if(para != " "){
   atCmd += "=";
   atCmd += para;
  }
  atCmd += "\r\n";
  pack.str = atCmd;
  pack.length = atCmd.length();
  return pack;
}
void DFRobot_RP::writeATCommand(String command,uint8_t length){
   uint8_t data[40];
   //Serial.print(command);
    while(_s->available()) {
         _s->read();
    }
   for(uint8_t i=0;i<length;i++)
      data[i] = command[i];
   _s->write(data,length);
}



String DFRobot_RP::readAck(uint8_t len){

  String str="                           ";
  size_t offset = 0,left = len;
  long long curr = millis();
  while(left) {
    if(_s->available()) {
       str[offset]= _s->read();
      left--;
	  offset++;
    }
    if(millis() - curr > 1000) {
      return "error";
      break;
    }
  }
   str[len]=0;
  return str;
}




