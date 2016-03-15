#pragma once

// ver 1.2

#include "msgpack.hpp"
#include <vector>
#include <opencv2\opencv.hpp>

class Image
{
public:
	int width;
	int height;
	int channels;
	std::vector<unsigned char> image;

	MSGPACK_DEFINE(
		width,
		height,
		channels,
		image
		)
};

class Color : public Image
{
public:

	MSGPACK_DEFINE(
		width,
		height,
		channels,
		image
		);
};

class Depth : public Image
{
public:

	MSGPACK_DEFINE(
		width,
		height,
		channels,
		image
		);
};

class BodyIndex : public Image
{
public:

	MSGPACK_DEFINE(
		width,
		height,
		channels,
		image
		);
};

class LeanAmount
{
public:
	float x;
	float y;
	MSGPACK_DEFINE(
		x,
		y
		);
};

class HandInfo
{
public:
	int handState;
	int tracking_confidence;
	MSGPACK_DEFINE(
		handState,
		tracking_confidence
		);
};
class Position
{
public:
	float x;
	float y;
	float z;
	MSGPACK_DEFINE(
		x,
		y,
		z
		);
};
class Position2D
{
public:
	float x;
	float y;
	MSGPACK_DEFINE(
		x,
		y
		);
};

class Orientation
{
public:
	float w;
	float x;
	float y;
	float z;
	MSGPACK_DEFINE(
		w,
		x,
		y,
		z
		);
};

class JointInfo
{
public:
	int joint_type;
	int tracking_state;
	Position position;
	Position2D position_color_space;
	Orientation orientation;
	MSGPACK_DEFINE(
		joint_type,
		tracking_state,
		position,
		position_color_space,
		orientation
		);
};
class JointsInfo
{
public:
	std::vector< JointInfo > joints;
	int num_joints;
	MSGPACK_DEFINE(
		joints,
		num_joints
		);
};
class BodyInfo
{
public:
	int index_body;
	unsigned long long tracking_id;
	bool is_tracked;
	bool is_restricted;
	LeanAmount lean_amount;
	HandInfo right_hand_state;
	HandInfo left_hand_state;
	JointsInfo joints_info;
	MSGPACK_DEFINE(
		index_body,
		tracking_id,
		is_tracked,
		is_restricted,
		right_hand_state,
		left_hand_state,
		joints_info
		);
};
class BodyInfoTest
{
public:
	std::string json_body_info;
	MSGPACK_DEFINE(
		json_body_info
		);
};
class KinectPack
{
public:
	Color image_color;
	Depth image_depth;
	BodyIndex image_body_index;
	//std::vector< BodyInfo > bodies;
	BodyInfoTest bodies;
	MSGPACK_DEFINE(
		image_color,
		image_depth,
		image_body_index,
		bodies
		);
};
