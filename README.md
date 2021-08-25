**This folder/directory displays all the under-pinnings of a Simple Shell in C programming language**


/******
Task 0
*******/

In this task, a Manual Page (man page using the groff format) for the simple shell, as well as a Readme file explaining the entire project should be made
available. Also a file that lists all the names of the authors is very much required for the completion of this task.

/******
Task 1
*******/

In this task, all file must pass through all the checks of the Betty Linter. The task is considered completed when all files meets the Betty requirements.

/******
Task 2
*******/

A shell script is written to display prompt and execute one-word command lines (commands without arguments and options). The shell script also handles error.

/******
Task 3
*******/

A shell script is written to display prompt and execute command lines with arguments and options. The shell script also handles error.

/******
Task 4
*******/

An updated shell script from task 3 to handle the `PATH`, and dosen't call `fork` if the file dosen't exist.

/******
Task 5
*******/

An updated shell script from task 4 that implements the `exit` and dosen't handle any `exit` built-in arguments.

/******
Task 6
*******/

An updated shell script from task 5 that implements the `ENV` built-in which prints the current environment

/******
Task 7
*******/

In this task,  a blog post describing step by step what happens when you type ls -l *.c and hit Enter in a shell must be written and publlished. It should
also be posted on LinkedIn and other social media platforms.

/******
Task 8
*******/

A group class work that should be tested in a single respository with every team contributing to the repository.

/******
Task 9
*******/

An updated shell script from task 6 that impliments the getline function.

/******
Task 10
*******/

An updated shell script from task 9 that does not use `strtok`.

/******
Task 11
*******/

An updated shell script from task 10 that handles arguments for the built-in `exit`. Usage: exit status, where status is an integer used to exit the shell. 

/******
Task 12
*******/

An updated shell script from task 11 that handles `Ctrl+C`, the shell should not quit when the user inputs `^C`.

/******
Task 13
*******/

An updated shell script from task 12 that 1mplement the `setenv` and `unsetenv` builtin commands.

/******
Task 14
*******/

An updated shell script from task 13 that implement the builtin command cd which changes the current directory of the process. Command syntax: `cd [DIRECTORY]`. If no argument is given to `cd` the command must be interpreted like `cd $HOME`.It also has to handle the command `cd -`. You have to update the environment variable `PWD` when you change directory.

/******
Task 15
*******/

An updated shell script from task 14 that handles the commands separator. 

/******
Task 16
*******/

An updated shell script from task 15 handles the `&&` and `||` shell logical operators.

/******
Task 17
*******/

An updated shell script from task 16 that implements the `alias` builtin command.

Usage: alias `[name[='value'] ...]`
`alias`: Prints a list of all aliases, one per line, in the form `name='value'
`alias name [name2 ...]`: Prints the aliases `name`, `name2`, etc 1 per line, in the form `name='value'`.
`alias name='value' [...]`: Defines an alias for each `name` whose `value` is given. If `name` is already an alias, replaces its value with `value`.

/******
Task 18
*******/

An updated shell script from task 17 that handles variables replacement, and also handles the `$?` variable and the `$$` variable.

/******
Task 19
*******/

An updated shell script from task 18 that handles comments (`#`).

/******
Task 20
*******/

An updated shell script from task 19 that implements the `help` built-in.
Usage: `help [BUILTIN]`.

/******
Task 21
*******/

An updated shell script from task 20 that implements the history built-in, without any argument.
The history built-in displays the history list, one command by line, preceded with line numbers (starting at `0`)
On `exit`, write the entire history, without line numbers, to a file named `.simple_shell_history` in the directory `$HOME`.
When the shell starts, read the file `.simple_shell_history` in the directory `$HOME` if it exists, and set the first line number to the total number of lines in the file modulo `4096`.

/******
Task 22
*******/

An updated shell script from task 21 that implements files input.
Usage: `simple_shell [filename]`
Your shell can take a file as a command line argument
The file contains all the commands that your shell should run before exiting
The file should contain one command per line
In this mode, the shell should not print a prompt and should not read from `stdin`.

/************
Style Section
*************/

## Description :speech_balloon:
​
**hsh** is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them.
​
### Invocation :running:
​
Usage: **hsh** [filename]
​
To invoke **shellby**, compile all `.c` files in the repository and run the resulting executable:
​
```
gcc *.c -o hsh
./hsh
```
​
**hsh** can be invoked both interactively and non-interactively. If **hsh** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.
​
Example:
```
$ echo "echo 'hello'" | ./hsh
'hello'
$
```
​
If **hsh** is invoked with standard input connected to a terminal (determined by [isatty](https://linux.die.net/man/3/isatty)(3)), an *interactive* shell is opened. When executing interactively, **hsh** displays the prompt `$ ` when it is ready to read a command.
​
Example:
```
$./hsh
$
```
​
Alternatively, if command line arguments are supplied upon invocation, **hsh** treats the first argument as a file from which to read commands. The supplied file should contain one command per line. **hsh** runs each of the commands contained in the file in order before exiting.
​
Example:
```
$ cat test
echo 'hello'
$ ./hsh test
'hello'
$
```
​
### Environment :deciduous_tree:
​
Upon invocation, **hsh** receives and copies the environment of the parent process in which it was executed. This environment is an array of *name-value* strings describing variables in the format *NAME=VALUE*. A few key environmental variables are:
​
#### HOME
The home directory of the current user and the default directory argument for the **cd** builtin command.
​
```
$ echo "echo $HOME" | ./hsh
/home/vagrant
```
​
#### PWD
The current working directory as set by the **cd** command.
​
```
$ echo "echo $PWD" | ./hsh
/home/vagrant/holberton/simple_shell
```
​
#### OLDPWD
The previous working directory as set by the **cd** command.
​
```
$ echo "echo $OLDPWD" | ./hsh
/home/vagrant/holberton/printf
```
​
#### PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.
​
```
$ echo "echo $PATH" | ./hsh
/home/vagrant/.cargo/bin:/home/vagrant/.local/bin:/home/vagrant/.rbenv/plugins/ruby-build/bin:/home/vagrant/.rbenv/shims:/home/vagrant/.rbenv/bin:/home/vagrant/.nvm/versions/node/v10.15.3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/vagrant/.cargo/bin:/home/vagrant/workflow:/home/vagrant/.local/bin
```
​
### Command Execution :hocho:
​
After receiving a command, **hsh** tokenizes it into words using `" "` as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. **hsh** then proceeds with the following actions:
1. If the first character of the command is neither a slash (`\`) nor dot (`.`), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
2. If the first character of the command is none of a slash (`\`), dot (`.`), nor builtin, **hsh** searches each element of the **PATH** environmental variablefor a directory containing an executable file by that name.
3. If the first character of the command is a slash (`\`) or dot (`.`) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.
​
### Exit Status :wave:
​
**hsh** returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.
​
If a command is not found, the return status is `127`; if a command is found but is not executable, the return status is 126.
​
All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).
​
### Signals :exclamation:
​
While running in interactive mode, **hsh** ignores the keyboard input `Ctrl+c`. Alternatively, an input of end-of-file (`Ctrl+d`) will exit the program.
​
User hits `Ctrl+d` in the third line.
```
$ ./hsh
$ ^C
$ ^C
$
```
​
### Variable Replacement :heavy_dollar_sign:
​
**hsh** interprets the `$` character for variable replacement.
​
#### $ENV_VARIABLE
`ENV_VARIABLE` is substituted with its value.
​
Example:
```
$ echo "echo $PWD" | ./hsh
/home/vagrant/holberton/simple_shell
```
​
#### $?
`?` is substitued with the return value of the last program executed.
​
Example:
```
$ echo "echo $?" | ./hsh
0
```
​
#### $$
The second `$` is substitued with the current process ID.
​
Example:
```
$ echo "echo $$" | ./hsh
6494
```
​
### Comments :hash:
​
**hsh** ignores all words and characters preceeded by a `#` character on a line.
​
Example:
```
$ echo "echo 'hello' #this will be ignored!" | ./hsh
'hello'
```
​
### Operators :guitar:
​
**hsh** specially interprets the following operator characters:
​
#### ; - Command separator
Commands separated by a `;` are executed sequentially.
​
Example:
```
$ echo "echo 'hello' ; echo 'world'" | ./hsh
'hello'
'world'
```
​
#### && - AND logical operator
`command1 && command2`: `command2` is executed if, and only if, `command1` returns an exit status of zero.
​
Example:
```
$ echo "error! && echo 'hello'" | ./hsh
./hsh: 1: error!: not found
$ echo "echo 'all good' && echo 'hello'" | ./hsh
'all good'
'hello'
```
​
#### || - OR logical operator
`command1 || command2`: `command2` is executed if, and only if, `command1` returns a non-zero exit status.
​
Example:
```
$ echo "error! || echo 'but still runs'" | ./hsh
./hsh: 1: error!: not found
'but still runs'
```
​
The operators `&&` and `||` have equal precedence, followed by `;`.
​
### hsh Builtin Commands :nut_and_bolt:
​
#### cd
* Usage: `cd [DIRECTORY]`
* Changes the current directory of the process to `DIRECTORY`.
* If no argument is given, the command is interpreted as `cd $HOME`.
* If the argument `-` is given, the command is interpreted as `cd $OLDPWD` and the pathname of the new working directory is printed to standad output.
* If the argument, `--` is given, the command is interpreted as `cd $OLDPWD` but the pathname of the new working directory is not printed.
* The environment variables `PWD` and `OLDPWD` are updated after a change of directory.
​
Example
```
$ ./hsh
$ pwd
/home/vagrant/holberton/simple_shell
$ cd ../
$ pwd
/home/vagrant/holberton
$ cd -
$ pwd
/home/vagrant/holberton/simple_shell
```
​
#### alias
* Usage: `alias [NAME[='VALUE'] ...]`
* Handles aliases.
* `alias`: Prints a list of all aliases, one per line, in the form `NAME='VALUE'`.
* `alias NAME [NAME2 ...]`: Prints the aliases `NAME`, `NAME2`, etc. one per line, in the form `NAME='VALUE'`.
* `alias NAME='VALUE' [...]`: Defines an alias for each `NAME` whose `VALUE` is given. If `name` is already an alias, its value is replaced with `VALUE`.
​
Example:
```
$ ./hsh
$ alias show=ls
$ show
AUTHORS              builtins_1.c      error.c             input_helpers.c        scanner.c       shell.h       
README.md            builtins_2.c      error_funct.c       man_1_simple_shell     sh_help.c       shunt.c
alias_builtins.c     env_builtins.c    error_funct_1.c     node.c                 sh_help_1.c     string1.c
builtins.c           environs.c        getline.c           proc_file_comm.c       shell.c         string2.c
```
​
#### exit
* Usage: `exit [STATUS]`
* Exits the shell.
* The `STATUS` argument is the integer used to exit the shell.
* If no argument is given, the command is interpreted as `exit 0`.
​
Example:
```
$ ./hsh
$ exit
```
​
#### env
* Usage: `env`
* Prints the current environment.
​
Example:
```
$ ./hsh
$ env
NVM_DIR=/home/vagrant/.nvm
...
```
​
#### setenv
* Usage: `setenv [VARIABLE] [VALUE]`
* Initializes a new environment variable, or modifies an existing one.
* Upon failure, prints a message to `stderr`.
​
Example:
```
$ ./hsh
$ setenv NAME Poppy
$ echo $NAME
Poppy
```
​
#### unsetenv
* Usage: `unsetenv [VARIABLE]`
* Removes an environmental variable.
* Upon failure, prints a message to `stderr`.
​
Example:
```
$ ./hsh
$ setenv NAME Poppy
$ unsetenv NAME
$ echo $NAME
​
$
```