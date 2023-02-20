/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "myshell.h"


// Put macros or constants here using #define
#define BUFFER_LEN 1024
#define MAX_TOKENS 10

// Put global environment variables here

// Define functions declared in myshell.h here

int main(int argc, char *argv[])
{
    // Input buffer and and commands
	char environ[2][BUFFER_LEN] = {0};
	char pwd[BUFFER_LEN] = {0};
	char myshell[BUFFER_LEN] = {0};
    char buffer[BUFFER_LEN] = {0};
    char command[BUFFER_LEN] = {0};
    char tokens[MAX_TOKENS][BUFFER_LEN] = {0};
	int token_count = 0;

	FILE* fp = NULL;
    // Parse the commands provided using argc and argv
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
	
    // Perform an infinite loop getting command input from users
	
	printf("\n-------------------------------------------------------\n");
	printf("\nWelcome to the shell!, type help to discover more commands\n\n");
	get_currentDir(pwd);
	get_currentDir(myshell);
	strcpy(environ[0], "PWD: ");
	strcpy(environ[1], "MYSHELL: ");
	strcat(environ[0], pwd);
	strcat(environ[1], myshell);
	
	printf("%s> ", pwd);
    while (fgets(buffer, BUFFER_LEN, fp) != NULL){
        // Perform string tokenization to get the command and argument
	    int index = 0;
		while (buffer[index] != '\n'){
			index++;
		}
		buffer[index] = '\0';
		
		token_count = string_tokenizer(buffer, tokens);
		strcpy(command, tokens[0]);
		
        // Check the command and execute the operations for each command
        // cd command -- change the current directory
        if (strcmp(command, "cd") == 0){
            // your code here
			change_dir(pwd, tokens[1]);
			strcpy(environ[0], "PWD: ");
			strcat(environ[0], pwd);
        }

        // other commands here...
	    
	    	// enter
		else if (strcmp(command, "") == 0){
			printf("");
		}
		
		// clear screen
		else if (strcmp(command, "clear") == 0){
			clear_screen();
		}

		// display help
		else if (strcmp(command, "help") == 0){
			display_help();
		}	
		
		// pause the shell
		else if (strcmp(command, "pause") == 0){
			pause_shell();
		}	
		
		// lists the contents of the specified directory
		else if (strcmp(command, "dir") == 0){
			display_dir(tokens[1]);
			printf("\n");
		}
		
		// run the echo command
		else if (strcmp(command, "echo") == 0){
			for (int i = 1; i < token_count; i++){
				printf("%s ", tokens[i]);
			}
			printf("\n");
		}
		
		// display environment variables
		else if (strcmp(command, "environ") == 0){
			display_environs(environ);
		}
		
        // quit command -- exit the shell
        else if (strcmp(tokens[0], "quit") == 0 || strcmp(tokens[0], "exit") == 0){
            printf("Bye!\n");
			return EXIT_SUCCESS;
        }

        // Unsupported command
        else{
			printf("%s> ", pwd);
            printf("Unsupported command, use help to display the manual\n");
        }
		
		memset(buffer, 0, sizeof buffer);
		memset(command, 0, sizeof command);
		for (int i = 0; i < MAX_TOKENS; i++){
			memset(tokens[i], 0, sizeof tokens[i]);
		}
		
		printf("%s> ", pwd);
    }
    return EXIT_SUCCESS;
}
