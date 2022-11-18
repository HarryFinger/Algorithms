#include <iostream>
#include <SFML/Network.hpp>
#include <Windows.h>

int main()
{
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect("127.0.0.1", 53000);
	if (status != sf::Socket::Done)
	{
		std::cout << "ERROR on client" << std::endl;
	}
	else
	{
		std::cout << "Connected on client" << std::endl;
	}

	char data[100];
	std::size_t received;

	std::cout << "Waiting for data" << std::endl;
	socket.receive(data, 100, received);

	std::cout << "Received " << received << " bytes" << std::endl;
	std::cout << "Message: " << data << std::endl;
	system("pause");
}