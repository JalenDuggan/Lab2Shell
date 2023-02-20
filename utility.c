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

// Define your utility functions here, these will most likely be functions that you call
// in your myshell.c source file

// string tokenizer functions
extern int string_tokenizer(char* str, char tokens[][BUFFER_LEN]){
	const char delimiter[2] = " ";
	int tokens_count = 0;
	char* token = strtok(str, delimiter);
	while (token != NULL){
		strcpy(tokens[tokens_count], token);
		tokens_count++;
		token = strtok(NULL, delimiter);
	}
	return tokens_count;
}

// returns current directory
extern void get_currentDir(char* pwd){
	getcwd(pwd, BUFFER_LEN);
}

// changes the directory
extern void change_dir(char* pwd, char* path){
	int changed = chdir(path);
	if (strcmp(path,"") != 0){
		if (changed == 0){
			get_currentDir(pwd);
		}
		else {
			printf("%s> No such path exists!\n", pwd);
		}
	}
}

// clears the screen
extern void clear_screen(void){
	system("cls||clear");
}

// pauses the shell
extern void pause_shell(void){
	printf("\n\nShell is now paused. Please press ENTER key to continue....\n\n");
	char code = (char)getchar();
	while (code != '\n'){
		code = (char)getchar();
	}
}

// displays help menu
extern void display_help(void){
    printf("\nList of available commands:\n\n");
    printf("help\t\t\t Lists the help menu.\n");
    printf("dir <directory>\t\t Lists the contents of the directory\n");
    printf("environ\t\t\t Lists all the environment strings..\n");
    printf("echo <comment>\t\t Displays comment on the command line followed by a newline.\n");
	printf("cd <path>\t\t Changes the working directory to the specified path.\n");
    printf("clear\t\t\t Clears the screen.\n");
    printf("pause\t\t\t Pauses operation of the shell until the ENTER key is hit.\n");
    printf("quit\t\t\t Quits the shell.\n\n\n");
    
}

// displays the directory
extern void display_dir(char* path){
	struct dirent *de; 
	DIR *dr = NULL;
    if (strcmp(path, "") == 0){
        dr = opendir(".");
	}
    else {	
		dr = opendir(path); 
	}
	if (dr == NULL) { 
		printf("Could not find the directory specified!\n" );  
	} 
	while ((de = readdir(dr)) != NULL){ 
		printf("%s\n", de->d_name); 
	}
    closedir(dr);     
}

// displays the environment variables
extern void display_environs(char env[][BUFFER_LEN]){
	printf("%s\n%s\n", env[0], env[1]);
}
