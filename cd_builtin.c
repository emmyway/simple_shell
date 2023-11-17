#include "main.h"

/**
 * cd_builtin - changes directory to user's choice directory
 * cmd: user's choice folder directory
 */
void cd_builtin(chr *cmd)
{
	char *home;


	/* when no user inpout */
	if (cmd == NULL)
	{
		home = getenv("HOME");

		/* check if getenv() failed */
		if (home == NULL)
		{
			perror("getenv failed to fetch home");
		}
		else /* if getenv() is a success */
		{
			if (chdir(home) != 0)
			{
				perror("failed to change directory");
			}
		}
	}
	else/* if user pass in input */ 
	{
		if (chdir(cmd) != 0)
		{
			perror("failed to change directory");
		}
	}
}
