#include "main.h"
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
	int n_read, status, i = 0;

	while (1)
	{
		write(1, "#cisfun$ ", 9);

		n_read = getline(&buffer, &buf_size, stdin);
		if (n_read == -1)
		{
			free(buffer);
			perror("getline error:");
			exit(EXIT_FAILURE);
		}

		token = strtok(buffer, " \t\n");

		while (token)
		{
			arr[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}

		fork_pid = fork();
		if (fork_pid == 0)
		{
			if (execve(arr[0], arr, NULL) == -1)
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
