#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <time.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("No port given\n");
        return 1;
    }

    typedef struct {
        char* hostname;
        char* files;
    } VirtualHosts;

    VirtualHosts virtualHosts[2];
    virtualHosts[0].hostname = "test.com";
    virtualHosts[0].files = "/home/test/zajecia6/example";
    virtualHosts[1].hostname = "test2.com";
    virtualHosts[1].files = "/home/test/zajecia6/example2";

    struct sockaddr_in serv_addr, client_addr;
    int port;
    socklen_t client_address;
    int socket_n;
    int bind_n;
    int send_n;
    int read_n;
    FILE* addresses;
    FILE* logs;
    char client_ip[INET_ADDRSTRLEN];
    char time_to_str[20];
    struct tm* time_n;
    time_t current_time;
    char client_choose[20];
    char response[255];
    pid_t fork_n;

    time(&current_time);
    time_n = localtime(&current_time);

    logs = fopen("logs.txt", "w+");
    if (logs == NULL) {
        printf("Cannot open logs\n");
        return 1;
    }

    strftime(time_to_str, sizeof(time_to_str), "%Y-%m-%d %H:%M:%S", time_n);
    port = atoi(argv[1]);
    socket_n = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_n < 0) {
        printf("Server: Failed to create socket\n");
        fclose(logs);
        return 1;
    }
    fprintf(logs, "[%s] Created socket\n", time_to_str);

    memset((char*)&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    bind_n = bind(socket_n, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (bind_n < 0) {
        printf("Server: Failed to bind\n");
        fclose(logs);
        return 1;
    }
    fprintf(logs, "[%s] Socket binded\n", time_to_str);
    listen(socket_n, 5);
    fprintf(logs, "[%s] Listening for connections\n", time_to_str);
    printf("Server: Waiting for connection\n");

    while (true) {
        client_address = sizeof(client_addr);
        int accept_n = accept(socket_n, (struct sockaddr*)&client_addr, &client_address);
        if (accept_n < 0) {
            perror("Server: Failed to accept connection\n");
            fprintf(logs, "[%s] Connection failed\n", time_to_str);
            fclose(logs);
            return 1;
        }
        
        fork_n = fork();
        if (fork_n == 0) {
            close(socket_n);
            time(&current_time);
            time_n = localtime(&current_time);
            strftime(time_to_str, sizeof(time_to_str), "%Y-%m-%d %H:%M:%S", time_n);
            getpeername(accept_n, (struct sockaddr*)&client_addr, &client_address);
            inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN);
            fprintf(logs, "[%s] Received connection from %s\n", time_to_str, client_ip);

            char buffer[1024];
            addresses = fopen("forbidden.txt", "r");
            if (addresses == NULL) {
                printf("Server: Can't validate address\n");
                fclose(logs);
                fprintf(logs, "[%s] Can't validate address\n", time_to_str);
                fclose(logs);
                return 1;
            }
            
            while (fgets(buffer, sizeof(buffer), addresses) != NULL) {
                buffer[strcspn(buffer, "\n")] = '\0';
                if (strcmp(client_ip, buffer) == 0) {
                    printf("Server: This address is forbidden\n");
                    fprintf(logs, "[%s] %s was forbidden, connection terminated\n", time_to_str, client_ip);
                    fclose(addresses);
                    fclose(logs);
                    close(accept_n);
                    return 1;
                }
            }
            
            fclose(addresses);
            read_n = read(accept_n, client_choose, sizeof(client_choose));
            if (read_n < 0) {
                printf("Server: Can't get hostname from client\n");
                fprintf(logs, "[%s] Can't get hostname from client %s, connection terminated\n", time_to_str, client_choose);
                fclose(logs);
                close(accept_n);
                return 1;
            }
            
            if (strcmp(client_choose, virtualHosts[0].hostname) != 0 && strcmp(client_choose, virtualHosts[1].hostname) != 0) {
                printf("Server: Couldn't find this host\n");
                strcpy(response, "404 not found\n");
                send(accept_n, response, strlen(response) + 1, 0);
                fprintf(logs, "[%s] Can't open %s host, connection terminated\n", time_to_str, client_choose);
                fclose(logs);
                close(accept_n);
                return 1;
            }
            
            if (strcmp(client_choose, virtualHosts[0].hostname) == 0) {
                strcpy(response, virtualHosts[0].files);
                send_n = send(accept_n, response, strlen(response) + 1, 0);
                if (send_n < 0) {
                    printf("Server: Error while sending files\n");
                    fprintf(logs, "[%s] Can't send files to client %s\n", time_to_str, client_ip);
                    fclose(logs);
                    close(accept_n);
                    return 1;
                }
            }
            
            if (strcmp(client_choose, virtualHosts[1].hostname) == 0) {
                strcpy(response, virtualHosts[1].files);
                send_n = send(accept_n, response, strlen(response) + 1, 0);
                if (send_n < 0) {
                    printf("Server: Error while sending files\n");
                    fprintf(logs, "[%s] Can't send files to client %s\n", time_to_str, client_ip);
                    fclose(logs);
                    close(accept_n);
                    return 1;
                }
            }
            
            fprintf(logs, "[%s] Client successfully received data\n", time_to_str);
            close(accept_n);
            fclose(logs);
            return 0;
        } else if (fork_n < 0) {
            printf("Server: Cannot create client process\n");
            fprintf(logs, "[%s] Failed at creating client process\n", time_to_str);
            fclose(logs);
            close(socket_n);
            return 1;
        } else {
            close(accept_n);
        }
    }
    
    fclose(logs);
    return 0;
}
