/*
 * MyShell Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2017, <GROUP MEMBERS>
 * All rights reserved.
 * 
 */
#ifndef UTILITY_H_
#define UTILITY_H_

#define BUFFER_LEN 1024 

// Include your relevant functions declarations here they must start with the
// extern keyword such as in the following example:
// extern void display_help(void);

// string tokenizer functions
extern int string_tokenizer(char* str, char tokens[][BUFFER_LEN]);

// returns current directory
extern void get_currentDir(char* pwd);

// changes the directory
extern void change_dir(char* pwd, char* path);

// clears the screen
extern void clear_screen(void);

// pauses the shell
extern void pause_shell(void);

// displays the directory
extern void display_dir(char* path);

// displays the environment variables
extern void display_environs(char env[][BUFFER_LEN]);

#endif /* UTILITY_H_ */