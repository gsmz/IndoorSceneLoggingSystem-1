#include "util.h"

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
}