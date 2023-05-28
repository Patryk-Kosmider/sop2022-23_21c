#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<signal.h>
#include<stdbool.h>

bool serverStatus = true;
int socket_n;
FILE *file = NULL;
char *filename;
char *buffer;

void stopServer(){
	printf("Server is stopping\n");
	serverStatus = false;
	close(socket_n);
	fclose(file);
	free(filename);
	free(buffer);
	exit(0);
}


int main(int argc, char* argv[]){
	struct sockaddr_in serv_addr, client_addr;
	socklen_t client_address;
	int fileLen;
	int fileSize;
	int port;
	int socket_n;
	int bind_n;
	int socket_accept;
	int read_n;
	int write_n;
	int error_n;
	signal(SIGINT, stopServer);
	if(argc < 1){
		printf("No port given\n");
		return 1;
	}
	port = atoi(argv[1]);
	socket_n = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_n < 0){
		printf("Server: Socket error\n");
		return 1;
	}
	
	memset((char *) &serv_addr, 0 , sizeof(serv_addr));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	bind_n = bind(socket_n, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	if(bind_n < 0){
		printf("Error, cannot bind\n");
		close(socket_n);
	}	

	printf("Server: Socket bounded\n");
	listen(socket_n, 5);
	printf("Server: Waiting for connection\n");
	serverStatus = true;
	while(serverStatus){
		client_address = sizeof(client_addr);
		socket_accept = accept(socket_n, (struct sockaddr*)&serv_addr, &client_address);
	       	if(socket_accept < 0){
			printf("Server: Error accepting connection\n");
			close(socket_n);
			return 1;
		}	
		printf("Server: New connection\n");

		read_n = read(socket_accept, &fileLen, sizeof(int));
		if(read_n < 0){
			printf("Server: Error reading file name length\n");
			close(socket_n);
			return 1;
		}
		printf("Server: Lenght of file name obtained\n");
	
		filename = malloc((fileLen + 1) * sizeof(char));
		if(filename == NULL){
			printf("Server: Error allocating memory\n");
			free(filename);
			close(socket_n);
			return 1;
		}
		read_n = read(socket_accept, filename, fileLen);
		if(read_n < 0){
			printf("Server: Error reading file name \n");
			free(filename);
			close(socket_n);
			return 1;

		}
		printf("Server: File name obtained\n");
		printf("%s", filename);
		file = fopen(filename, "r");
		if(!file){
			printf("Server : Error opening a file");
			error_n = -1;
			write_n = write(socket_accept, &error_n,sizeof(int));
			free(filename);
			close(socket_accept);
			return 1;


		}
		printf("Server: File opened\n");
		fseek(file, 0, SEEK_END);
		fileSize = ftell(file);
		rewind(file);

		write_n = write(socket_accept, &fileSize, sizeof(int));
		if(write_n < 0){
			printf("Server: Error sending file size to client\n");
			free(filename);
			fclose(file);
			close(socket_n);
			return 1;

		}
		printf("Server: Size of file sended to client\n");

		filename[fileLen] = '\0';
		int number_bytes = 0;
		int bytes;
		buffer = malloc(fileSize * sizeof(char));
		while(bytes < fileSize){
			bytes = fread(buffer, sizeof(char), fileSize - number_bytes + 1, file);
			write(socket_accept, buffer, bytes);
			number_bytes += bytes;
		}
		
		fclose(file);
		free(buffer);
		free(filename);
		close(socket_accept);
		printf("Server: File sended properly\n");

	}
	return 0;
}
