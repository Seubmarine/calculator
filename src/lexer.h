#ifndef LEXER_H
# define LEXER_H
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

enum op_type
{
	OP_PLUS,
	OP_MINUS,
	OP_MUL,
	OP_DIV,
	OP_POWER,
	OP_UNKNOWN,
	OP_ENUM_LEN,
};

extern char *OP_TYPE_ENUM_NAME[OP_ENUM_LEN];

enum token_type
{
	TOKEN_INT,
	TOKEN_FLOAT,
	TOKEN_OP,
	TOKEN_PARENTHESE,
	TOKEN_VAR,
	TOKEN_UNKNOWN,
	TOKEN_ENUM_LEN,
};

extern char	*TOKEN_ENUM_NAME[TOKEN_ENUM_LEN];

typedef struct Token
{
	enum token_type type;
	union
	{
		int number;
		float fnumber;
		char *var;
		enum op_type operation;
	};
} Token;

typedef struct Lexer
{
	Token *tokens;
	size_t token_len;
} Lexer;

Lexer	lexer(char *str);
void	lexer_free(Lexer *lexing);

#endif