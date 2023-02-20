### Simple Shell Project<br>
[![Build Status](https://travis-ci.org/Umar-Eh/Simple-Shell.svg?branch=master)](https://travis-ci.org/Umar-Eh/Simple-Shell)
<br>

**Objectives:**<br>
1. Learn to develop software using Git<br>
2. Gain experience developing multi-source file projects in C<br>
3. Experience using Makefiles and other software build tools<br><br>


**Description:**<br><br>
Design a simple command line shell and implement it on the specified UNIX platform
The Shell or Command Line Interpreter is the fundamental User interface to
an Operating System. The project is to write a simple shell - myshell -
that has the following functions:<br>

* change working directory
* clear the screen
* list the contents of the directory
* list all the environment string
* display the diaply followed by a new line
* display the user manual using the more filter
* pause operation of the shell
* quit the shell

<br>**Usage:**<br><br>
To build the project clone this repository first and switch to the directory of the repository. Then run the command<br>
**make** to build the myshell executible.<br><br>
The shell can be invoked on Windows command line interpreter by typing myshell. It can be invoked on a UNIX based OS<br>
by typing /myshell. The program accepts one argument which can be a batchfile containing user commands. <br>
For example: **./myshell commands.txt** <br>

The following are the commands for the shell: <br>

**help:**  Lists the help menu <br>
**dir <directory\>:**  Lists the contents of the directory <br>
**environ:** Lists all the environment strings <br>
**echo <comment\>:** Displays comment on the command line followed by a newline <br>
**clr:** Clears the screen <br>
**cd <path\>:** Changes the working directory to the specified path. <br>
**pause:** Pauses operation of the shell until the ENTER key is hit <br>
**quit:** Quits the shell <br>
