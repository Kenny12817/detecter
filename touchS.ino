#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;

std_msgs::UInt16 int_msg;
ros::Publisher detector("detector", &int_msg);

int analogPin = A0; 
double val = 0;

void setup()
{
  nh.initNode();
  nh.advertise(detector);
  Serial.begin(9600);


}

void loop() {
  val = analogRead(analogPin);  
  Serial.println(val);  
  int_msg.data = val;
  detector.publish( &int_msg );
  delay(50);
}
