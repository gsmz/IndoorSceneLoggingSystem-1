#pragma once
#include "client\sensor_client\kinectv2_client.h"

class IndoorSceneLoggingSystem
{
public:
	/**
	* コンストラクタ
	*/
	IndoorSceneLoggingSystem();
private:
	client::sensor_client::KinectV2Client* kinectv2_client_;
private:
	void Init();
public:
	void Run();
};