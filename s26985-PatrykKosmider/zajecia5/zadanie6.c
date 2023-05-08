#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>


int main() {
	int line;
	pid_t chatprocess;
	FILE *chat  = fopen("/home/test/tmp/chat.txt", "r+");
	if(chat == NULL){
		printf("Error\n");
		return 0;
	}
	chatprocess = fork();
	if(chatprocess > 0){
		char message[255];
		printf("Podaj wiadomosc: (wpisz exit, by zakonczyc) \n");
		while(1){
			scanf("%s", message);
			strcat(message, "\n");
			if(strcmp(message, "exit\n") == 0){
				break;
				fclose(chat);
			}
			fprintf(chat, message);
			fflush(chat);
		}
	} else if (chatprocess == 0){
		char messages[255];
		FILE *chat = fopen("/home/test/tmp/chat.txt", "r+");
			rewind(chat);
			while(fgets(messages, sizeof(messages), chat)){
				printf("Wiadomosc od %d: %s", getpid(), messages);	
			}
			fflush(stdout);	
			fclose(chat);
	} else {
		printf("Error");
		fclose(chat);
	}
	
	waitpid(chatprocess, NULL, 0);	
	return 0;
}
