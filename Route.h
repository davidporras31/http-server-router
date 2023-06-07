#ifndef ROUTE
#define ROUTE
#include <string>
#include <SFML/Network/TcpSocket.hpp>


class Route
{
public:
	Route();
	~Route();

	void setName(std::string name);
	std::string getName();
	
	std::string getPath();

	virtual void GET(sf::TcpSocket * socket, std::string path, std::string* data) = 0;
	virtual void HEAD(sf::TcpSocket * socket, std::string path, std::string* data) = 0;
	virtual void POST(sf::TcpSocket * socket, std::string path, std::string* data) = 0;
	virtual void OPTIONS(sf::TcpSocket * socket, std::string path, std::string* data) = 0;
	virtual void CONNECT(sf::TcpSocket * socket, std::string path, std::string* data) = 0;
	virtual void TRACE(sf::TcpSocket * socket, std::string path, std::string* data) = 0;
	virtual void PUT(sf::TcpSocket * socket, std::string path, std::string* data) = 0;
	virtual void PATCH(sf::TcpSocket * socket, std::string path, std::string* data) = 0;
	virtual void DELETE(sf::TcpSocket * socket, std::string path, std::string* data) = 0;
private:
	std::string name;
};


#endif
