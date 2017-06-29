/*

Programmer : leafspace
Last edit : 2017-5-11
Contact me :
    Phone number : 18852923073
    E-mail : 18852923073@163.com
*/

本项目功能：
    Linux Project 运行在树莓派3B+的Ubuntu mate内，需要通过连接网络、麦克风来实现录音并识别语音的功能。识别完成后将数据通过socket直接传输进入Web端。
    Web Project 在创建时创建Socket服务器端，每当后台服务器收到从客户端发来的消息，就将数据写入数据库。界面通过Ajax控制。