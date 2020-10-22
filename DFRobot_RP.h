#ifndef DFROBOT_RP_H
#define DFROBOT_RP_H
//#include <SoftwareSerial.h>
#include <Arduino.h>
#include <string.h>
#if ((defined ESP_PLATFORM) || (defined ARDUINO_SAM_ZERO))
#else
  #include <SoftwareSerial.h>
#endif
//extern Stream *dbg;
class DFRobot_RP
{
public:

  typedef enum{
    MUSIC = 1,
    RECORD,
    UFDISK,
  }eFunction_t;
  typedef struct{
   String str;
   uint8_t length;
  }sPacket_t;
  
  typedef enum{
    SINGLECYCLE = 1,
    ALLCYCLE,
    SINGLE,
    ERROR,
  }ePlayMode_t;



  DFRobot_RP();
  //~DFRobot_RP();
  bool begin();
  bool setBaudRate(uint32_t baud);
  bool setPlayMode(ePlayMode_t mode);
  bool setLED(bool on);
  bool setPrompt(bool on);
  bool setVol(uint8_t vol);
  bool switchFunction(eFunction_t function);
  //bool operation( );
  bool next();
  bool last();
  bool start();
  bool pause();
  bool saveRec();
  bool delCurFile();
  bool playSpecFile(String str);//通过输入完整路径
  bool playSpecFile(int16_t num);//通过输入文件编号
  uint8_t getVol();
  ePlayMode_t getPlayMode();
private:
  sPacket_t pack(String cmd = " ",String para = " " );
  Stream *_s = NULL;
  void writeATCommand(String command,uint8_t length);
  String readAck(uint8_t len = 4);
  eFunction_t curFunction;
  String atCmd;
  
  uint8_t pauseFlag;
  
};

#endif
