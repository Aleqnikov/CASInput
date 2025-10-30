#include "Lexer.h"

#include <cctype>

Lexer::Lexer(std::string input) : input_(input) {
	if (input.empty()) {
		throw InputError("Empty input");
	}
};


void Lexer::CreateTokens() {
	for (auto it = input_.begin(); it != input_.end(); ++it) {

		if (*it == '\n' || *it == '\r' || *it == ' ') continue;




		if (std::isdigit(*it)) {
			int last_token = tokens_.size() - 1;

			if (last_token == -1) {
				tokens_.push_back(Token(*it));
				continue;
			}

			if (tokens_[last_token].type == TokenType::Num)
				tokens_[last_token].value += *it;
			else
				tokens_.push_back(Token(*it));

			continue;
		}


		switch (*it) {
			case '/': tokens_.push_back(Token('/')); break;
			case '+': tokens_.push_back(Token('+')); break;
			case '-': tokens_.push_back(Token('-')); break;
			case '^': tokens_.push_back(Token('^')); break;
			case 'x': tokens_.push_back(Token('x')); break;
			case '*': tokens_.push_back(Token('*')); break;
			case 'X': throw InputError("Use lowercase 'x'"); break;  // ← ФИКС
			default: throw InputError("Incorrect Token!"); break;
		}
	}
}

std::vector<Token>& Lexer::GetTokens() {
	return tokens_;
}
