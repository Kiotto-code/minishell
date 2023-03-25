#include "libft.h"

int main()
{
	char str[] = "dsfas dargdfdgshtd";
	int i = 4;
	// i++;
	char *test = ft_substr(str,i, 5);
	printf("%s", test);
}