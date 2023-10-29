#include "TCP_Connection.h"


void QuickSend(std::string IP, std::string message, int Port)
{
	if (message != "")
	{
		sf::TcpSocket socket;
		sf::Socket::Status status = socket.connect(IP, Port); 

		size_t t = message.length();

		socket.send(message.c_str(), t);
		socket.disconnect();
	}
}
