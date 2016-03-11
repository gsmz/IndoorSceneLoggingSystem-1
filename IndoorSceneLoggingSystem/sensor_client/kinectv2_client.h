#pragma once
#include "sensor_client.h"
#include "kinect_pack.h"
namespace sensor_client
{
	/**
	* KinectV2ClientƒNƒ‰ƒX
	*/
	class KinectV2Client : public SensorClient
	{
	public:
		KinectV2Client();
	private:
		KinectPack kinect_pack_;

	public:
		void RequestSensorInfo();
		cv::Mat GetColorImage();
		cv::Mat GetDepthImage();
		cv::Mat GetBodyIndexImage();
		std::string GetBodyInfoJson();
	};
}
