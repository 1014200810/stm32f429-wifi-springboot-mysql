/*
Navicat MySQL Data Transfer

Source Server         : glh
Source Server Version : 80017
Source Host           : localhost:3306
Source Database       : test

Target Server Type    : MYSQL
Target Server Version : 80017
File Encoding         : 65001

Date: 2020-06-26 16:13:10
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for allSensor_data
-- ----------------------------
DROP TABLE IF EXISTS `allSensor_data`;
CREATE TABLE `allSensor_data` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `people` varchar(20) DEFAULT NULL COMMENT 'people',
  `dist` varchar(20) DEFAULT NULL COMMENT 'dist',
  `light` varchar(20) DEFAULT NULL COMMENT 'light',
  `temp` varchar(20) DEFAULT NULL COMMENT 'temp',
  `hum` varchar(20) DEFAULT NULL COMMENT 'hum',
  `ip` varchar(20) DEFAULT NULL COMMENT 'ip',
  `time` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '采集时间',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

-- ----------------------------
-- Records of allSensor_data
-- ----------------------------