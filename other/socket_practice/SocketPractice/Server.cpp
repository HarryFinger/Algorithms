#include <iostream>
#include <SFML/Network.hpp>
#include <Windows.h>
#include <iostream>

int main()
{
	sf::TcpListener listener;

	if (listener.listen(53000) != sf::Socket::Done)
	{
		std::cout << "listen error on server";
	}

	sf::TcpSocket client;
	if (listener.accept(client) != sf::Socket::Done)
	{
		std::cout << "accept error on server" << std::endl;
	}
	else
	{
		std::cout << "Connected on server" << std::endl;
	}

	std::cout << "Waiting for 3 seconds, before sending data" << std::endl;
	Sleep(3000);

	char arr[100] = "HELLO MAN!!!";

	client.send(arr, 13);
}
