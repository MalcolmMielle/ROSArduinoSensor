/*void affiche(){
  /* Print Data 
    Serial.print("\n");
 
  Serial.print(accXangle);Serial.print(";");
  Serial.print(accYangle);Serial.print(";");
  Serial.print(0);Serial.print(";");
  
  Serial.print(gyroXangle);Serial.print(";");
  Serial.print(gyroYangle);Serial.print(";");
  Serial.print(gyroZangle);Serial.print(";");
  
  //Roll
  
  
  Serial.print(kalAngleX);Serial.print(";");
  Serial.print(kalAngleY);Serial.print(";");
  Serial.print(gyroZangle);Serial.print(";");
  //Serial.print("\t\t");
  
  Serial.print(compAngleX);Serial.print(";");
  Serial.print(compAngleY); Serial.print(";");
  Serial.print(gyroZangle);Serial.print(";");
  //Pitch
  
  //Magneto et temp et pression
  Serial.print(compass.getHead());Serial.print(";");
  Serial.print(bmp.readTemperature());Serial.print(";");
  Serial.print(bmp.readPressure());Serial.print(";");
  
  
  Serial.print('e');
}*/

void writeData(){
  //Rotationnal velocity in rad.s and acceleration in m.s-2 !!!!
  imu_msg.header.stamp = nh.now();
  
  //Orientation from Kalmen filter or complementary one
  //double kx, ky, kz, kw;
  //double cx, cy, cz, cw;
  //Euler2Quat(kalAngleX, kalAngleY, compass.getHead(), kx, ky, kz, kw);
  //Euler2Quat(compAngleX, compAngleY, compass.getHead(), cx, cy, cz, cw);
  
  //Linear acceleration from accelerometer.
  imu_msg.linear_acceleration.x=0;
  imu_msg.linear_acceleration.y=0;
  imu_msg.linear_acceleration.z=0;
  
  //angular velocity from gyro
  imu_msg.angular_velocity.x=0;
  imu_msg.angular_velocity.y=0;
  imu_msg.angular_velocity.z=0;
  
  imu_msg.orientation.x=0;
  imu_msg.orientation.y=0;
  imu_msg.orientation.z=0;
  imu_msg.orientation.w=0;
  
  /*Linear acceleration from accelerometer.
  imu_msg.linear_acceleration.x=accel.x;
  imu_msg.linear_acceleration.y=accel.y;
  imu_msg.linear_acceleration.z=accel.z;
  
  //angular velocity from gyro
  imu_msg.angular_velocity.x=gyroXrate;
  imu_msg.angular_velocity.y=gyroYrate;
  imu_msg.angular_velocity.z=gyroZrate;*/
  
}


void blinking(){
    if(flag==0){
    digitalWrite(PIN, HIGH);
   flag=1;
  }
  else{
   digitalWrite(PIN, LOW);
   flag=0;
  }
}
