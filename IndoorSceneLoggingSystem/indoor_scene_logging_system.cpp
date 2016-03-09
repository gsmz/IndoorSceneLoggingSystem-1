#include "indoor_scene_logging_system.h"

IndoorSceneLoggingSystem::IndoorSceneLoggingSystem()
{

}
void IndoorSceneLoggingSystem::Init()
{
	if ( !kinectv2_client_ )
	{
		kinectv2_client_ = new sensor_client::KinectV2Client();
	}
}
void IndoorSceneLoggingSystem::Run()
{

}