#include "indoor_scene_logging_system.h"

IndoorSceneLoggingSystem::IndoorSceneLoggingSystem()
{
	Init();
}
void IndoorSceneLoggingSystem::Init()
{
	if ( kinectv2_client_ )
	{
		delete kinectv2_client_;
	}
	kinectv2_client_ = new sensor_client::KinectV2Client();
}
void IndoorSceneLoggingSystem::Run()
{
	kinectv2_client_->Connect();
	while ( 1 )
	{
		std::string send_message_string = "test";
		kinectv2_client_->Send(send_message_string);

		std::string receive_message_string;
		kinectv2_client_->Receive( receive_message_string );
	}
}