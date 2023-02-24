#ifndef ROUTE
#define ROUTE
#include <string>
#include <errno.h>
#include <time.h>
#include <iomanip>
#include <sstream>

#if defined(_WIN64) || defined(_WIN32)
namespace win {
#include <winsock2.h>
#include <ws2tcpip.h>
}
#undef INVALID_SOCKET
#define INVALID_SOCKET		(win::SOCKET)(~0)
#undef MAKEWORD
#define MAKEWORD(a, b)      ((win::WORD)(((win::BYTE)(((win::DWORD_PTR)(a)) & 0xff)) | ((win::WORD)((win::BYTE)(((win::DWORD_PTR)(b)) & 0xff))) << 8))
#include <stdio.h>
#undef ERROR
#undef DELETE

#pragma comment(lib, "Ws2_32.lib")
#endif // Windows


class Route
{
public:
	Route();
	~Route();

	void setName(std::string name);
	std::string getName();

	bool isRedirected();
	void setRedirected(bool redirected);

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
	bool redirected;
};


#endif
