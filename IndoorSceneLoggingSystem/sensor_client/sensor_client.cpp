#include "sensor_client.h"
#include "..\util\config\config.h"
#include <thread>


void DoMonitor( sensor_client::Monitor &monitor, zmq::socket_t &socket )
{
	std::cout << "start" << std::endl;
	monitor.monitor( socket, "inproc://monitor.req", ZMQ_EVENT_ALL );
}
namespace sensor_client
{
	Monitor::Monitor() : zmq::monitor_t()
	{

	}

	SensorClient::SensorClient( std::string client_name, SocketType socket_type, const int num_threads) : client_name_(client_name), socket_type_(socket_type), num_threads_(num_threads)
	{
		Init();
	}
	SensorClient::~SensorClient()
	{
		if ( socket_ ) delete socket_;
		if ( monitor_ ) delete monitor_;
	}
	void SensorClient::Connect()
	{
		std::string filename = client_name_ + ".config";
		util::config::ConfigTable config_table = util::config::ReadConfig( filename );
		for ( util::config::ConfigTable::iterator itr = config_table.begin(); itr != config_table.end(); itr++ )
		{
			std::cout << itr->first << ": " << itr->second << std::endl;
		}
		std::string ipaddr = config_table["ip"];
		std::string port = config_table["port"];
		socket_->connect( "tcp://" + ipaddr + ":" + port );
	}
	void SensorClient::Send( const std::string send_message_string )
	{
		zmq::message_t send_message( send_message_string.size() );
		memcpy( send_message.data(), send_message_string.data(), send_message_string.size() );
		socket_->send( send_message );
	}
	void SensorClient::Receive( std::string &receive_message_string )
	{
		zmq::message_t receive_message;
		socket_->recv(&receive_message );
		receive_message_string = std::string( static_cast<char*>( receive_message.data() ), receive_message.size() );
	}

	void SensorClient::Init()
	{
		try
		{
			zmq::context_t *context = new zmq::context_t( num_threads_ );
			socket_ = new zmq::socket_t( *context, socket_type_ );
			monitor_ = new Monitor();
			std::thread monitor_thread = std::thread( std::bind( DoMonitor, std::ref( *monitor_ ), std::ref( *socket_ ) ) );
			monitor_thread.detach();
		}
		catch ( zmq::error_t &e )
		{
			std::cout << __FUNCTION__ << ": " << e.what() << std::endl;
		}
	}
}