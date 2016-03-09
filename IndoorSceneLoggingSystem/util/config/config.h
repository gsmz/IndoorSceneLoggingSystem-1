#pragma once
#include <map>
#include <fstream>
#include <iostream>
#include <vector>
namespace util
{
	namespace config
	{
		typedef	std::map< std::string, std::string > ConfigTable;

		ConfigTable ReadConfig( const std::string filename );
		void PrintConfigAll( ConfigTable config_table );
		std::vector<std::string> GetConfigKeyList( const ConfigTable config_table );
	}
}
