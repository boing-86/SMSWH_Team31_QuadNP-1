#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ros.h>
#include <std_msgs/Int32.h>

Adafruit_PWMServoDriver pwm=Adafruit_PWMServoDriver();
ros::NodeHandle  nh;
int servo, throttle, rx, ry;

void pwm_cb(const std_msgs::Int32& cmd_msg){
  servo = cmd_msg.data; //set servo angle, should be from 0-180
  Serial.println(servo);
  throttle = 78;
  rx = constrain(map(servo,0,180,150,600),150,600);
  ry = constrain(map(throttle,0,180,150,600),150,600);
  pwm.setPWM(0,0,rx); //pca9685
  pwm.setPWM(1,0,ry); //pca9685
}

ros::Subscriber<std_msgs::Int32> sub("/poffice_cmd", pwm_cb);
//ros::Subscriber<morai_msgs::Poffice> pof("/poffic_cmd", pwm_cb);

void setup(){
  Serial.begin(115200);
  throttle = 60;
  ry = constrain(map(throttle,0,180,150,600),150,600);
  pwm.setPWM(1,0,ry); //pca9685
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  pwm.begin();
  pwm.setPWMFreq(51);
  nh.subscribe(sub);
  ry = constrain(map(throttle,0,180,150,600),150,600);
  pwm.setPWM(1,0,ry);
}


void loop(){
    nh.spinOnce();
    delay(1);
}
