#ifndef BASEERROR_H
#define BASEERROR_H

#include <string>
#include <exception>

class BaseError : public std::exception {
protected:
	std::string message;
	int line, column;

public:
	explicit BaseError(std::string msg, int ln = -1, int col = -1)
		: message(std::move(msg)), line(ln), column(col) {}

	const char* what() const noexcept override { return message.c_str(); }
	int getLine() const noexcept { return line; }
	int getColumn() const noexcept { return column; }
};
#endif //BASEERROR_H
