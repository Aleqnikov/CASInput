//
// Created by ivan on 30.10.25.
//

#ifndef TOKENERROR_H
#define TOKENERROR_H

#include <string>
#include <exception>

class TokenError : public std::exception {
private:
	std::string message;
	int line;
	int column;

public:
	TokenError(const std::string& msg, int ln = -1, int col = -1)
		: message(msg), line(ln), column(col) {}

	const char* what() const noexcept override {
		return message.c_str();
	}

	int getLine() const { return line; }
	int getColumn() const { return column; }
};
#endif //TOKENERROR_H
