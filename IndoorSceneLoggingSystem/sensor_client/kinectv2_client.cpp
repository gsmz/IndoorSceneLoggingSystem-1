#include "kinectv2_client.h"
#include "../util/msgpack_util/msgpack_util.h"
#include "../util/kinect_pack_util/kinect_pack_util.h"
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
	void KinectV2Client::RequestSensorInfo()
	{
		this->Send("hoge"); // this message is test
		std::string receive_message_string;
		this->Receive(receive_message_string);
		util::msgpack_util::unpack( receive_message_string, kinect_pack_ );

		cv::Mat image_color;
	}
	cv::Mat KinectV2Client::GetColorImage()
	{
		cv::Mat image;
		util::kinect_pack_util::ConvertImageToMat( kinect_pack_.image_color, image );
		return image.clone();
	}
	cv::Mat KinectV2Client::GetDepthImage()
	{
		cv::Mat image;
		util::kinect_pack_util::ConvertImageToMat( kinect_pack_.image_depth, image );
		return image.clone();
	}
	cv::Mat KinectV2Client::GetBodyIndexImage()
	{
		cv::Mat image;
		util::kinect_pack_util::ConvertImageToMat( kinect_pack_.image_body_index, image );
		return image.clone();
	}
	std::string KinectV2Client::GetBodyInfoJson()
	{
		return kinect_pack_.bodies.json_body_info;
	}
}