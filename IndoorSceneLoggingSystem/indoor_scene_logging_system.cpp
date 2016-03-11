#include "indoor_scene_logging_system.h"
#include "msgpack_util.h"
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
		kinectv2_client_->RequestSensorInfo();
		cv::Mat image_color = kinectv2_client_->GetColorImage();
		cv::imshow( "color", image_color );
		cv::waitKey( 1 );
	}
}