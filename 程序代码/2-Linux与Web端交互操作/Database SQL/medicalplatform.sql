/*
Navicat MySQL Data Transfer

Source Server         : MySQL
Source Server Version : 50612
Source Host           : 192.168.198.129:3306
Source Database       : medicalplatform

Target Server Type    : MYSQL
Target Server Version : 50612
File Encoding         : 65001

Date: 2017-05-11 21:44:19
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for information
-- ----------------------------
DROP TABLE IF EXISTS `information`;
CREATE TABLE `information` (
  `id` int(255) NOT NULL AUTO_INCREMENT,
  `information` varchar(255) NOT NULL,
  `time` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of information
-- ----------------------------
