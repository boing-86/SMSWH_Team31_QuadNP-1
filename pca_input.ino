
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ros.h>
#include <std_msgs/Int32.h>

Adafruit_PWMServoDriver pwm=Adafruit_PWMServoDriver();
ros::NodeHandle  nh;
int servo, throttle, rx, ry;

void pwm_cb(const std_msgs::Int32& cmd_msg){
  servo = cmd_msg.data; //set servo angle, should be from 0-180
  throttle = 65;
  rx = constrain(map(servo,0,180,150,600),150,600);
  ry = constrain(map(throttle,0,180,150,600),150,600);
  pwm.setPWM(0,0,rx); //pca9685
  pwm.setPWM(1,0,ry); //pca9685
}

ros::Subscriber<std_msgs::Int32> sub("/poffice_cmd", pwm_cb);

void setup(){
  Serial.begin(57600);
  pwm.begin();
  pwm.setPWMFreq(51);
  nh.initNode();
  nh.subscribe(sub);

  //done setting
  rx = constrain(map(80,0,180,150,600),150,600);
  ry = constrain(map(65,0,180,150,600),150,600);
  pwm.setPWM(0,0,rx); //pca9685
  pwm.setPWM(1,0,ry);
  delay(1000);
  rx = constrain(map(80,0,180,150,600),150,600);
  ry = constrain(map(0,0,180,150,600),150,600);
  pwm.setPWM(0,0,rx); //pca9685
  pwm.setPWM(1,0,ry);
}

void loop(){
  if(Serial.available()){
    nh.spinOnce();
    delay(1);
  }
}
