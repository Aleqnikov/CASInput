//
// Created by ivan on 30.10.25.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <cctype>  // для std::isdigit
#include "Exeptions/TokenError.h"

enum class TokenType {
	Mul = '*',
	Add = '+',
	Sub = '-',
	Div = '/',
	Pow = '^',
	X = 'x',
	Num,
};

struct Token {
	Token(char symb) {
		switch (symb) {
			case '+': type = TokenType::Add; value = "+"; break;
			case '*': type = TokenType::Mul; value = "*"; break;
			case '-': type = TokenType::Sub; value = "-"; break;
			case '/': type = TokenType::Div; value = "/"; break;
			case '^': type = TokenType::Pow; value = "^"; break;
			case 'x': type = TokenType::X;   value = "x"; break;  // исправил на строчную
			default:
				if (std::isdigit(symb)) {
					type = TokenType::Num;
					value = std::string(1, symb);
				} else {
					throw TokenError("Invalid token: " + std::string(1, symb));
				}
		}
	}

	TokenType type;
	std::string value;

	bool operator==(const Token& other) const {
		return type == other.type && value == other.value;
	}
};

#endif //TOKEN_H