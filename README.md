# Mini Shell

- **Binary name:** mysh
- **Repository name:** minishell1_2017
- **Repository rigths:** ramassage-tek
- **Language:** C
- **Compilation:** via Makefile, including re, clean and fclean rules


# Subject

You have to program a **UNIX command interpreter**.

The interpreter is expected to display a prompt ($>, for example) and then wait for you to write a command line, which
must be validated by a newline.
The prompt must be displayed again only after the command execution.

Only basic command lines are expected to executed; no pipes, redirections or any other advanced features.
The executables should be those found in the path, as indicated in the PATH variable.

If the executable cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.
You must correctly handle the PATH and the environment (by copying and restoring the initial env).

You must implement the following builtins: **cd, setenv, unsetenv, env, exit**.

> :bulb: The reference shell is **tcsh**

## Authorized functions

- opendir
- readdir
- closedir
- getcwd
- malloc
- free
- exit
- chdir
- fork
- stat
- lstat
- fstat
- getcwd
- open
- close
- read
- write
- execve
- access
- isatty
- wait
- waitpid
- wait3
- wait4
- signal
- kill
- getpid
- strerror
- perror
