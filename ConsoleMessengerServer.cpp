#include <winsock.h>
#include <stdio.h>
#include <iostream>

#pragma comment (lib,"ws2_32.lib" )

int main() {
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (result != 0) { std::cout << "EROR - 1; WSAStartup not started\n"; exit(1); };

    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(9999);
    addr.sin_family = AF_INET;

    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);

    bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
    listen(sListen, SOMAXCONN);

    SOCKET newConnection ;
    newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

    if (newConnection == 0) { std::cout << "EROR - 2; newConnection not started\n"; }
    else { std::cout << "Client Connected\n"; }

    system("pause");
    return 0;
}