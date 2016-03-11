#include "util.h"
#include "base64.h"
namespace util
{
	template< typename T >
	std::string ToString( T t )
	{
		std::stringstream ss;
		ss << n;
		return ss.str();
	}


	void ReplaceAll( std::string &str, const std::string from, const std::string to )
	{
		std::string::size_type pos = 0;
		while ( ( pos = str.find( from ) ) != std::string::npos )
		{
			str.replace( pos, from.size(), to );
		}
	}

	std::vector< std::string > Split( std::string s, std::string delimiter )
	{
		std::vector< std::string > v;
		for ( size_t p = 0; ( p = s.find( delimiter ) ) != s.npos; )
		{
			v.push_back( s.substr( 0, p ) );
			s = s.substr( p + delimiter.size() );
		}
		v.push_back( s );
		return v;
	}


	std::vector< std::string > SplitFirst( std::string s, const std::string delimiter )
	{
		std::vector< std::string > v;
		size_t p = s.find( delimiter );
		if ( p != s.npos )
		{
			v.push_back( s.substr( 0, p ) );
			s = s.substr( p + delimiter.size() );
		}
		v.push_back( s );
		return v;
	}

	cv::Mat ConvertVec2Mat( const std::vector<unsigned char>& vec )
	{
		if ( vec.size() == 0 )
		{
			return cv::Mat::zeros( 1920, 1080, CV_8UC3 );
		}
		return cv::imdecode( cv::Mat( vec ), CV_LOAD_IMAGE_UNCHANGED );
	}

	cv::Mat ConvertString2Mat( std::string str )
	{
		std::vector< unsigned char > buf( str.begin(), str.end() );
		buf.push_back( '0' );

		return cv::imdecode( cv::Mat( buf ), CV_LOAD_IMAGE_UNCHANGED );
	}

	std::string ConvertMat2String( cv::Mat mat )
	{
		if ( mat.data == NULL )
		{
			return "";
		}
		std::vector< unsigned char > buf;
		std::vector< int > param = std::vector< int >( 2 );
		param[0] = CV_IMWRITE_JPEG_QUALITY;
		param[1] = 95;
		cv::imencode( ".jpg", mat, buf, param );
		std::istringstream iss( std::string( buf.begin(), buf.end() ) );
		std::ostringstream oss;
		base64::Encode( iss, oss );
		return oss.str();
	}

}