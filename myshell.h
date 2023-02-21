#ifndef UTILITY_H_
#define UTILITY_H_

#define BUFFER_LEN 1024 

// string tokenizer 
extern int string_tokenizer(char* str, char tokens[][BUFFER_LEN]);

// returns current working directory
extern void get_currentDir(char* pwd);

// changes the directory to the path given 
extern void change_dir(char* pwd, char* path);

// clears screen
extern void clear_screen(void);

// pauses the shell until user presses enter key
extern void pause_shell(void);

// displays the path of the directory
extern void display_dir(char* path);

// displays valid commands
extern void display_help(void);

// wait function for a parent procces
extern int wait();

// displays the PWD and the directory the shell program where are the current variables
extern void display_environs(char env[][BUFFER_LEN]);

#endif /* UTILITY_H_ */