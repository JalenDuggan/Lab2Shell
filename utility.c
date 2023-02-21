#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include "myshell.h" 

// utility of functions defined here

// string tokenizer function
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

// returns the current directory user is in 
extern void get_currentDir(char* pwd){
	getcwd(pwd, BUFFER_LEN);
}

// changes the directory of terminal 
extern void change_dir(char* pwd, char* path){
	int changed = chdir(path);
	if (strcmp(path,"") != 0){
		if (changed == 0){
			get_currentDir(pwd);
		}
		else {
			printf("%s> No path exists\n", pwd);
		}
	}
}
// clears screen
extern void clear_screen(void){
	system("cls||clear");
}

// pauses the shell
extern void pause_shell(void){
	printf("\n\n\nShell is paused. Please press ENTER key to continue\n\n");
	char code = (char)getchar();
	while (code != '\n'){
		code = (char)getchar();
	}
}

// displays all commands within the shell using "help" 
extern void display_help(void){
    printf("\nAll Available Commands:\n\n");
    printf("help\t\t\t Lists available commands\n");
    printf("dir <directory>\t\t Lists contents in given directory\n");
    printf("environ\t\t\t Lists all the environment strings\n");
    printf("echo <comment>\t\t Displays comment on newline\n");
		printf("cd <path>\t\t Changes the working directory to the given path\n");
    printf("clr\t\t\t Clears the screen\n");
    printf("pause\t\t\t Pauses operation of current shell until 'ENTER' is pressed\n");
    printf("quit\t\t\t Exits the shell\n\n\n");
    
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
		printf("Could not given directory\n" );  
	} 
	while ((de = readdir(dr)) != NULL){ 
		printf("%s\n", de->d_name); 
	}
    closedir(dr);     
}

// displays environment variables   the pwd and the directory the shell is running in
extern void display_environs(char env[][BUFFER_LEN]){
	printf("%s\n%s\n", env[0], env[1]);
}
