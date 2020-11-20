#include <ros.h>
#include <std_msgs/Int8.h>

ros::NodeHandle nh;

void lMotorCb( const std_msgs::Int8& speed_msg){
  if(speed_msg.data > 0){
    digitalWrite(4, HIGH);
  }
  else{
    digitalWrite(4, LOW);
  }
  analogWrite(5, abs(speed_msg.data));
}

void rMotorCb( const std_msgs::Int8& speed_msg){
  if(speed_msg.data > 0){
    digitalWrite(7, HIGH);
  }
  else{
    digitalWrite(7, LOW);
  }
  analogWrite(6, abs(speed_msg.data));
}

ros::Subscriber<std_msgs::Int8> lSub("/diff_drive/left_motor_speed", &lMotorCb );
ros::Subscriber<std_msgs::Int8> rSub("/diff_drive/right_motor_speed", &rMotorCb );

void setup()
{
  nh.initNode();
  nh.subscribe(lSub);
  nh.subscribe(rSub);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  analogWrite(5, 0);
  analogWrite(6, 0);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}
