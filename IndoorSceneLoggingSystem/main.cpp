#include <iostream>
#include "sensor_client\kinectv2_client.h"
// エントリーポイント
void TestKinectV2Client()
{
	sensor_client::KinectV2Client kinectv2_client;
	kinectv2_client.Connect();
	while ( 1 )
	{
		std::string send_message_string = "test";
		kinectv2_client.Send( send_message_string );

		std::string receive_message_string;
		kinectv2_client.Receive( receive_message_string );
		std::cout << receive_message_string << std::endl;
	}
}
int main()
{
	TestKinectV2Client();
	return 0;
}