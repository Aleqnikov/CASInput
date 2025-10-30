//
// Created by ivan on 30.10.25.
//

#ifndef INPUTERROR_H
#define INPUTERROR_H

#include <string>
#include <exception>

class InputError : public std::exception {
private:
	std::string message;
	int line;
	int column;

public:
	InputError(const std::string& msg, int ln = -1, int col = -1)
		: message(msg), line(ln), column(col) {}

	const char* what() const noexcept override {
		return message.c_str();
	}

	int getLine() const { return line; }
	int getColumn() const { return column; }
};



#endif //INPUTERROR_H
