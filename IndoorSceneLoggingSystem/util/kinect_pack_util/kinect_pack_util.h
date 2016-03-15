#pragma
#include "opencv2\opencv.hpp"
#include <picojson.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <vector>
#include <utility>
#include "..\util.h"
#include "..\..\client\sensor_client\kinect_pack.h"
namespace util
{
	namespace kinect_pack_util
	{
		void ConvertImageToMat( const Image& src, cv::Mat& dst )
		{
			dst = util::ConvertVec2Mat( src.image );
		}
		void ConvertDepth16UToDepth8U( const cv::Mat& src, cv::Mat& dst )
		{
			dst = cv::Mat::zeros( src.rows, src.cols, CV_8UC1 );
			for ( int row = 0; row < src.rows; ++row )
			{
				for ( int col = 0; col < src.cols; ++col )
				{
					dst.at< unsigned char >( row, col ) = static_cast<unsigned char>( src.at< short >( row, col ) / 8000. * 255.);
				}
			}
		}
	}
}