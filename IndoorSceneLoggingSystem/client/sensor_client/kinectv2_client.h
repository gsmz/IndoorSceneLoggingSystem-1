#pragma once
#include "..\client.h"
#include "kinect_pack.h"
namespace client
{
	namespace sensor_client
	{
		/**
		* KinectV2ClientƒNƒ‰ƒX
		*/
		class KinectV2Client : public Client
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
}
