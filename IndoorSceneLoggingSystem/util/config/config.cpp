#include "config.h"
#include <string>
#include "..\util.h"
#include <vector>
#include <direct.h>
namespace
{
	const std::string path_configs = "configs";
}
namespace util
{
	namespace config
	{
		ConfigTable ReadConfig( const std::string filename )
		{
			_mkdir( path_configs.c_str() );
			std::ifstream ifs( path_configs + "/" + filename );
			if ( !ifs.is_open() )
			{
				std::cerr << "can't open file: " << filename << std::endl;
				return ConfigTable();
			}
			std::cout << "read config:" << filename << std::endl;

			std::string line;
			ConfigTable config_table;
			while ( ifs >> line )
			{
				std::vector<std::string> v = util::Split( line, ":" );
				if ( v.size() != 2 )
				{
					std::cerr << "invalid config status" << std::endl;
					continue;
				}
				config_table[v[0]] = v[1];
			}
			return config_table;
		}
		void PrintConfigAll( const ConfigTable config_table )
		{
			for ( ConfigTable::const_iterator itr = config_table.begin(); itr != config_table.end(); itr++ )
			{
				std::cout << "[" << itr->first << "] = " << itr->second << std::endl;
			}
		}
		std::vector<std::string> GetConfigKeyList( const ConfigTable config_table )
		{
			std::vector<std::string> keys;
			for ( ConfigTable::const_iterator itr = config_table.begin(); itr != config_table.end(); itr++ )
			{
				keys.push_back( itr->first );
			}
			return keys;
		}
	}
}