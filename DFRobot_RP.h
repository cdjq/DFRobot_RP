#ifndef DFROBOT_RP_H
#define DFROBOT_RP_H

#include <Arduino.h>
#include <string.h>

//extern Stream *dbg;
class DFRobot_RP
{
public:

  typedef enum{
    MUSIC = 1,  //音乐模式
    RECORD,     //录音模式
    UFDISK,     //从机模式
  }eFunction_t;
  
  typedef struct{
   String str;
   uint8_t length;
  }sPacket_t;
  
  typedef enum{
    SINGLECYCLE = 1,  //单曲循环
    ALLCYCLE,         //全部循环
    SINGLE,           //单曲播放一次
    ERROR,
  }ePlayMode_t;



  DFRobot_RP();
  //~DFRobot_RP();
  bool begin(Stream &s);
  
  /**
   * @brief 设置波特率(需断电重启，掉电保存)
   * @param 9600,19200,38400,57600,115200
   * @return true or false
   */
  bool setBaudRate(uint32_t baud);

  /**
   * @brief 设置播放模式
   * @param ePlayMode_t:SINGLECYCLE,ALLCYCLE,SINGLE
   * @return true or false
   */
  bool setPlayMode(ePlayMode_t mode);

  /**
   * @brief 设置指示灯(掉电保存)
   * @param true or false
   * @return true or false
   */
  bool setLED(bool on);
  
  /**
   * @brief 设置提示音(掉电保存)
   * @param true or false
   * @return true or false
   */
  bool setPrompt(bool on);
  
  /**
   * @brief 设置音量
   * @param vol:0-30
   * @return true or false
  */
  bool setVol(uint8_t vol);
  
  /**
   * @brief 设置工作模式
   * @param eFunction_t:MUSIC,RECORD,UFDISK
   * @return true or false
   */
  bool switchFunction(eFunction_t function);
  
  //bool operation( );
  /**
   * @brief 下一曲
   * @return true or false
   */
  bool next();
  
  /**
   * @brief 上一曲
   * @return true or false
   */
  bool last();
  
  /**
   * @brief 播放(在音乐模式下) or 录音(在录音模式下)
   * @return true or false
   */
  bool start();
  
  /**
   * @brief 暂停播放(在音乐模式下) or 暂停录音(在录音模式下)
   * @return true or false
   */
  bool pause();
  
  /**
   * @brief 保存录音
   * @return true or false
   */
  String saveRec();

  /**
   * @brief 删除当前播放文件
   * @return true or false
   */
  bool delCurFile();
  
  /**
   * @brief 播放指定路径文件一次
   * @param 指定路径
   */
  void playSpecFile(String str);
  
  /**
   * @brief 播放指定编号文件一次(仅对默认文件名有效)，如果没有则播放第一个文件
   * @param 文件名编号：0-999
   */
  void playSpecFile(int16_t num);

  /**
   * @brief 获取音量
   * @return vol
   */
  uint8_t getVol();

  /**
   * @brief 获取播放模式
   * @return ePlayMode_t
   */
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
