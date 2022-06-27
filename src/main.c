#include "calculator.h"

char *get_total_string(int argc, char const *argv[])
{
	size_t total_size = 0;
	char *str = NULL;
	for (int i = 0; i < argc; i++)
	{
		size_t current_str = strlen(argv[i]) + 1;
		total_size += current_str;
		str = realloc(str, total_size * sizeof(*str));
		if (str == NULL)
			return (NULL);
		memcpy(str + total_size - current_str, argv[i], current_str);
		str[total_size - 1] = ' ';
	}
	str[total_size - 1] = '\0';
	return (str);
}

int main(int argc, char const *argv[])
{
	if (argc <= 1)
	{
		printf("No args provided\n");
		return (0);
	}
	char *str = get_total_string(argc - 1, argv + 1);
	printf("%s\n", str);
	// printf("%lu\n", sizeof(Token));
	Lexer lexing = lexer(str);
	for (size_t i = 0; i < lexing.token_len; i++)
	{
		Token current_token = lexing.tokens[i];	
		
		switch (current_token.type)
		{
		case TOKEN_VAR:
			printf("%s(%s)", TOKEN_ENUM_NAME[current_token.type], current_token.var);
			break;
		case TOKEN_INT:
			printf("%s(%i)", TOKEN_ENUM_NAME[current_token.type], current_token.number);
			break;
		case TOKEN_OP:
			printf("%s", OP_TYPE_ENUM_NAME[current_token.operation]);
			break;
		default:
			printf("%s",TOKEN_ENUM_NAME[current_token.type]);
			break;
		}
		printf(" ");
	}
	printf("\n");
	lexer_free(&lexing);
	free(str);
	return (0);
}
