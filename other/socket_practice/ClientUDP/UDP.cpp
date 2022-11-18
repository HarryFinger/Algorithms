#include <iostream>
#include <SFML/Network.hpp>
#include <Windows.h>

int main()
{
	sf::UdpSocket socket;

	if (socket.bind(54000) != sf::Socket::Done) // bind the socket to a port
	{
		std::cout << "ERROR on UDPclient";
	}
	std::cout << " CONNECTED! on UDPclient ";
	Sleep(5000);
}