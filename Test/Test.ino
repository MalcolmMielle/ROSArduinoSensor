#include <Wire.h>
#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>
ros::NodeHandle  nh;

sensor_msgs::Range imu_msg;
ros::Publisher pub_imu( "/imu", &imu_msg);
char frameid[] = "/imu";

void setup() {  
Serial.begin(57600);
  
nh.initNode();
nh.advertise(pub_imu);
imu_msg.header.frame_id =  frameid;
imu_msg.header.stamp=nh.now();
}


void loop() {

pub_imu.publish(&imu_msg);
nh.spinOnce();
}
