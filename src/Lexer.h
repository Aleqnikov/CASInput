#ifndef LEXER_H
#define LEXER_H

#include <vector>

#include "Token.h"
#include "Exeptions/InputError.h"

class Lexer {
public:
	Lexer();
	Lexer(std::string);

	void CreateTokens();

	std::vector<Token>& GetTokens();

private:
	std::string input_;
	std::vector<Token> tokens_;


};



#endif //LEXER_H
