#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "myshell.h"



#define BUFFER_LEN 1024
#define MAX_TOKENS 10


int main(int argc, char *argv[])
{
    // Input buffer and and commands
	pid_t child_pid, wpid;
	int status = 0;

	char environ[2][BUFFER_LEN] = {0};
	char pwd[BUFFER_LEN] = {0};
	char myshell[BUFFER_LEN] = {0};
    char buffer[BUFFER_LEN] = {0};
    char command[BUFFER_LEN] = {0};
    char tokens[MAX_TOKENS][BUFFER_LEN] = {0};
	int token_count = 0;

	FILE* fp = NULL;
	 	// opens and read only for batch file and runs given shell commands 
    if (argc > 1){
		fp = fopen(argv[1],"r");
		if (fp == NULL){
			printf("Error opening batch file...\n");
			return EXIT_FAILURE;
		}
	}
	else {
		fp = stdin;
	}
	
  // beginning of shell 
	
	printf("\n---------------------------------------------------------\n");
	printf("\nYou're now in the shell!, type help to see all commands\n\n");
	get_currentDir(pwd);
	get_currentDir(myshell);
	strcpy(environ[0], "PWD: ");
	strcpy(environ[1], "MYSHELL: ");
	strcat(environ[0], pwd);
	strcat(environ[1], myshell);
	
	printf("%s> ", pwd);
    while (fgets(buffer, BUFFER_LEN, fp) != NULL){
      //tokenization to seperate the command and argument
	    int index = 0;
		while (buffer[index] != '\n'){
			index++;
		}
		buffer[index] = '\0';
		
		token_count = string_tokenizer(buffer, tokens);
		strcpy(command, tokens[0]);

		if ((child_pid = fork()) == 0){
			// cd command changes directory
			if (strcmp(command, "cd") == 0){
							// your code here
				change_dir(pwd, tokens[1]);
				strcpy(environ[0], "PWD: ");
				strcat(environ[0], pwd);
			}

					
			// enter
			else if (strcmp(command, "") == 0){
				
			}
			
			// clear screen
			else if (strcmp(command, "clr") == 0){
				
				clear_screen();
				
			}

			//help
			else if (strcmp(command, "help") == 0){
				display_help();
				
			}	
			
			// pause shell
			else if (strcmp(command, "pause") == 0){
				
				pause_shell();
				
			}	
			
			// lists the contents of the specified directory
			else if (strcmp(command, "dir") == 0){
				if ((child_pid = fork()) == 0)
				
				display_dir(tokens[1]);
				printf("\n");
				
			}
			
			// echo command
			else if (strcmp(command, "echo") == 0){
				if ((child_pid = fork()) == 0)
				
				for (int i = 1; i < token_count; i++){
				printf("%s ", tokens[i]);
				}
				printf("\n");
				
			}
			
			// displays environment variables
			else if (strcmp(command, "environ") == 0){
				
				display_environs(environ);
				
			}
			
			// quit/exit the shell
			else if (strcmp(tokens[0], "quit") == 0 || strcmp(tokens[0], "exit") == 0){
				printf("Bye!\n");
				return EXIT_SUCCESS;
			}

			// invalid command
			else{
				printf("%s> ", pwd);
				printf("Unsupported command, type 'help'\n");
			}
	}
			while ((wpid = wait(&status)) > 0);
    // Check the command and execute the operations for each command
    // cd command -- change the current directory
		
		memset(buffer, 0, sizeof buffer);
		memset(command, 0, sizeof command);
		for (int i = 0; i < MAX_TOKENS; i++){
			memset(tokens[i], 0, sizeof tokens[i]);
		}
		
		printf("%s> ", pwd);
    }
    return EXIT_SUCCESS;
}
