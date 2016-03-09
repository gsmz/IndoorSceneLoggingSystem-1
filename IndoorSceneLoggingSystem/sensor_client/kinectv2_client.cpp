#include "kinectv2_client.h"
namespace
{
	const int num_threads_kinectv2_client = 4;
	const std::string client_name_kinectv2_client = "KinectV2Client";
	sensor_client::SocketType socket_type_kinectv2_client = ZMQ_REQ;
}
namespace sensor_client
{
	KinectV2Client::KinectV2Client() : SensorClient::SensorClient(client_name_kinectv2_client, socket_type_kinectv2_client, num_threads_kinectv2_client)
	{

	}

}