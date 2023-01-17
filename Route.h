#ifndef ROUTE
#define ROUTE

#include <string> 

class Route
{
public:
	Route();
	~Route();

	void setName(std::string name);
	std::string getName();

	virtual void GET(win::SOCKET socket, std::string path, std::string* data) = 0;
	virtual void HEAD(win::SOCKET socket, std::string path, std::string* data) = 0;
	virtual void POST(win::SOCKET socket, std::string path, std::string* data) = 0;
	virtual void OPTIONS(win::SOCKET socket, std::string path, std::string* data) = 0;
	virtual void CONNECT(win::SOCKET socket, std::string path, std::string* data) = 0;
	virtual void TRACE(win::SOCKET socket, std::string path, std::string* data) = 0;
	virtual void PUT(win::SOCKET socket, std::string path, std::string* data) = 0;
	virtual void PATCH(win::SOCKET socket, std::string path, std::string* data) = 0;
	virtual void DELETE(win::SOCKET socket, std::string path, std::string* data) = 0;
private:
	std::string name;
};


#endif