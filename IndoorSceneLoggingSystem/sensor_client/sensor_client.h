#pragma once
#include "zmq.hpp"
#include <iostream>
/**
* Sensor名前空間
*/
namespace sensor_client
{
	typedef int SocketType;


	class Monitor : zmq::monitor_t
	{
	public:
		/**
		* コンストラクタ
		*/
		Monitor();
	public:
		void monitor( zmq::socket_t &socket, std::string const& addr, int events = ZMQ_EVENT_ALL )
		{
			zmq::monitor_t::monitor( socket, addr, events );
		}

		void on_monitor_started() { std::cout << "monitor start" << std::endl; }
		inline void on_event_connected( const zmq_event_t &event_, const char* addr_ ) { std::cout << "connected:" << addr_ << std::endl; }
		inline void on_event_connect_delayed( const zmq_event_t &event_, const char* addr_ ) { ( void ) event_; ( void ) addr_; }
		inline void on_event_connect_retried( const zmq_event_t &event_, const char* addr_ ) { ( void ) event_; ( void ) addr_; }
		inline void on_event_listening( const zmq_event_t &event_, const char* addr_ ) { ( void ) event_; ( void ) addr_; }
		inline void on_event_bind_failed( const zmq_event_t &event_, const char* addr_ ) { ( void ) event_; ( void ) addr_; }
		inline void on_event_accepted( const zmq_event_t &event_, const char* addr_ ) { ( void ) event_; ( void ) addr_; }
		inline void on_event_accept_failed( const zmq_event_t &event_, const char* addr_ ) { ( void ) event_; ( void ) addr_; }
		inline void on_event_closed( const zmq_event_t &event_, const char* addr_ ) { ( void ) event_; ( void ) addr_; }
		inline void on_event_close_failed( const zmq_event_t &event_, const char* addr_ ) { ( void ) event_; ( void ) addr_; }
		inline void on_event_disconnected( const zmq_event_t &event_, const char* addr_ ) { std::cout << "disconnected:" << addr_ << std::endl; }
		inline void on_event_unknown( const zmq_event_t &event_, const char* addr_ ) { ( void ) event_; ( void ) addr_; }

	};


	/**
	* SensorClientクラス
	*/
	class SensorClient
	{
	public:
		/**
		* コンストラクタ
		*/
		SensorClient( std::string client_name, SocketType socket_type, const int num_threads = 1 );
		virtual ~SensorClient();

	public:
		void Init();
		virtual void Connect();
		virtual void Send( const std::string send_message );
		virtual void Receive( std::string &receive_message );
	private:
		int num_threads_;
		zmq::socket_t *socket_;
		Monitor * monitor_;
		std::string addr_;
		SocketType socket_type_;
		std::string client_name_;
	};

}