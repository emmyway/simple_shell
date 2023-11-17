#include "main.h"

extern char **environ;

/**
 * main - entry of program
 * description: this is a student simple shell project that is
 * similar to the thompson shell
 *
 * Return: 0 on success
 */

int main(void)
{
	char *buffer = NULL;
	size_t buf_size = 0;
	char **arr = malloc(sizeof(char *) * 1024);
	char *token;
	pid_t  fork_pid;
	int n_read, status, i;

	while (1)
	{
		write(1, "simple_shell ", 13);

		n_read = getline(&buffer, &buf_size, stdin);

		if (n_read == -1)
		{
			if (feof(stdin))
			{
				free(buffer);
				free(arr);
				write(1, "\n", 1);
				exit(0);
			}

			free(buffer);
			free(arr);
			perror("getline error:");
			exit(EXIT_FAILURE);
		}

		else if (n_read == 1)
			continue;

		token = strtok(buffer, " \t\n");

		i = 0;
		while (token)
		{
			arr[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}

		fork_pid = fork();
		if (fork_pid == 0)
		{
			if (execve(arr[0], arr, environ) == -1)
			{
				perror("execve:");
				free(buffer);
				free(arr);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}

	}
	free(buffer);
	free(arr);
}
