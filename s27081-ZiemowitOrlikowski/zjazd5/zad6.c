#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void receiveMessage(const char *username) {
	char filename[20];
    	sprintf(filename, "/tmp/chat_%s.txt", username);

    	FILE *file = fopen(filename, "r");
    	if (file == NULL) {
        	printf("Nie można otworzyć pliku.\n");
        	exit(1);
    	}

    	char message[100];

    	while (fgets(message, sizeof(message), file) != NULL) {
        	printf("Wiadomość od użytkownika %s: %s", username, message);
    	}

    	fclose(file);
}

void sendMessage(const char *username, const char *message) {
    	char filename[20];
    	sprintf(filename, "/tmp/chat_%s.txt", username);

    	FILE *file = fopen(filename, "w");
    	if (file == NULL) {
        	printf("Nie można otworzyć pliku.\n");
        	exit(1);
    	}

    	fputs(message, file);
    	fclose(file);
}

int main() {

	char message[100];
	
	while(1){
    	
		pid_t pid = fork();

		if(pid < 0){
			printf("Błąd");
			exit(1);
		}else if(pid == 0){
			const char *username = "A";
			receiveMessage("B");
			printf("Użytkownik A: ");
			fgets(message, sizeof(message), stdin);

			sendMessage(username, message);
			break;
		}else{
			wait(NULL);
			const char *username = "B";
			receiveMessage("A");
			printf("Użytkownik B: ");
			fgets(message, sizeof(message), stdin);

			sendMessage(username, message);
		}
		
	}
	return 0;
}

