# DFRobot_AS7341

您是否在寻找一款简单又强大的语音录放模块？看这里！
这款语音录放模块支持arduino、AT指令、板载按键和AD按键四种控制方式。通过板载按键即使在没有微控制器的情况下也能进行录放音。
模块支持多段语音录制，并且模块搭载了16MB的存储空间，可以录制大约40分钟的声音。通过USB线您可以很容易的将模块中的录音拷贝到电脑上。
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary
1.记录语音<br>
2.播放语音


## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods
```C++
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
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
ESP32        |      √       |              |             | 
ESP8266        |      √       |              |             | 
M0        |      √       |              |             | 


## History

- Date 2020-11-26
- Version V1.0


## Credits

Written by fengli(li.feng@dfrobot.com), 2020.11.26 (Welcome to our [website](https://www.dfrobot.com/))





