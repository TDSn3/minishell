#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **argv, char **env)
{
	printf("%s\n", getenv("PATH"));
}
