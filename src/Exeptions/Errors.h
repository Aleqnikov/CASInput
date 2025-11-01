#ifndef ERRORS_H
#define ERRORS_H

#include "BaseError.h"

class TokenError : public BaseError { using BaseError::BaseError; };
class InputError : public BaseError { using BaseError::BaseError; };

#endif //ERRORS_H
