int	main(void)
{
	char	*str;

	while (1)
	{
		str = readline("read> ");
		if (str == NULL)
			break ;
		// printf("str: [%s]\n", str);
		free(str);
	}
}