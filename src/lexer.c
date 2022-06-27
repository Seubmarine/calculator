#include "lexer.h"

char *TOKEN_ENUM_NAME[TOKEN_ENUM_LEN] = {
	"TOKEN_INT",
	"TOKEN_FLOAT",
	"TOKEN_OP",
	"TOKEN_PARENTHESE",
	"TOKEN_VAR",
	"TOKEN_UNKNOWN",
};

Lexer lexer(char *str)
{
	Lexer lexing = {.token_len = 0, .tokens = NULL};

	for (size_t i = 0; str[i]; i++)
	{
		Token token;
		while (str[i] == ' ')
			i++;
		if (isdigit(str[i]))
		{
			char *endptr;
			long long nbr = strtoll(str + i, &endptr, 10);
			i = endptr - str - 1;
			token = (Token){.type = TOKEN_INT, .number = nbr};
		}
		else if (isalpha(str[i]))
		{
			size_t var_token_len;

			for (var_token_len = 0; isalpha(str[i + var_token_len]); var_token_len++)
				;
			token =
				(Token){
					.type = TOKEN_VAR,
					.var = malloc(sizeof(*token.var) * (var_token_len + 1))};
			if (token.var == NULL)
				return (lexing);
			memcpy(token.var, str + i, var_token_len);
			token.var[var_token_len] = '\0';
			i += var_token_len - 1;
		}
		else
		{
			switch (str[i])
			{
			case '/':
				token = (Token){.type = TOKEN_OP, .operation = OP_DIV};
				break;
			case '+':
				token = (Token){.type = TOKEN_OP, .operation = OP_PLUS};
				break;
			case '-':
				token = (Token){.type = TOKEN_OP, .operation = OP_MINUS};
				break;
			case '*':
				token = (Token){.type = TOKEN_OP, .operation = OP_MUL};
				break;
			case '^':
				token = (Token){.type = TOKEN_OP, .operation = OP_POWER};
				break;
			default:
				token = (Token){.type = TOKEN_UNKNOWN};
				break;
			}
		}
		lexing.tokens = realloc(lexing.tokens, sizeof(*lexing.tokens) * (lexing.token_len + 1));
		if (lexing.tokens == NULL)
			return (lexing);
		lexing.tokens[lexing.token_len] = token;
		lexing.token_len += 1;
	}
	return (lexing);
}

void lexer_free(Lexer *lexing)
{
	for (size_t i = 0; i < lexing->token_len; i++)
	{
		free(lexing->tokens + i);
	}
}