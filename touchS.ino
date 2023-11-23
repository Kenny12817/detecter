#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;

std_msgs::UInt16 int_msg;
ros::Publisher detecter("detecter", &int_msg);

int analogPin = A0; 
double val = 0;

void setup()
{
  nh.initNode();
  nh.advertise(detecter);
  Serial.begin(9600);


}

void loop() {
  val = analogRead(analogPin);  
  Serial.println(val);  
  int_msg.data = val;
  detecter.publish( &int_msg );
  delay(50);
}