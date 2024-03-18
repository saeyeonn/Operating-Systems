#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

void *handle_client(void *); // 클라이언트와의 통신을 처리하는 스레드 함수

int main() 
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // 서버 소켓 생성
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

	// 서버 소켓을 특정 포트에 바인딩
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) 
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    
    // 클라이언트 연결 기다림
    if (listen(server_fd, MAX_CLIENTS) < 0) 
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // 클라이언트 연결 수락 + 클라이언트와의 통신을 위한 새로운 소켓 반환
    pthread_t threads[MAX_CLIENTS];
    int i = 0;
    while (1) 
    {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) 
        {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        printf("Client connected\n");
		
        // 클라이언트와의 통신을 처리하는 스레드 생성 -> 해당 스레드에 handle_client 함수 실행
        if (pthread_create(&threads[i], NULL, handle_client, (void *)&new_socket))
        {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        i++;
    }

    // 서버 소켓 닫기
    close(server_fd);

    return 0;
}

void *handle_client(void *arg) 
{
    int client_socket = *(int *)arg;
    char buffer[1024] = {0};
    int valread;
		
	// 클라이언트로부터 메시지 읽고 해당 메시지에 응답 보내기
    Read client request
    valread = read(client_socket, buffer, 1024);
    printf("Received message: %s\n", buffer);

    char *response = "Hello from server";
    send(client_socket, response, strlen(response), 0);
    printf("Response sent\n");

	// 클라이어트와의 통신 끝난 후 클라이언트 소켓 닫기
    close(client_socket);

    return NULL;
}
