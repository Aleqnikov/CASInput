#include "Lexer.h"
#include <memory>

Lexer::Lexer(std::string input) : input_(std::move(input)) {}

void Lexer::CreateTokens() {
    if (input_.empty())
        throw InputError("Lexer::CreateTokens(): empty input string");

    for (int i = 0; i < input_.length(); i++) {
        char ch = input_[i];

        if (std::isspace(ch)) continue;

        if (!std::isdigit(ch) && ch != 'x') {
            push_token(ch);
            continue;
        }

        if (tokens_.empty()) {
            push_token(ch);
            continue;
        }

        auto& last_token = tokens_.back();

        if (last_token.type != TokenType::Num) {
            push_token(ch);
            continue;
        }

        if (ch != 'x') {
            last_token.value += ch;
            continue;
        }

        push_token('*');
        push_token('x');
    }
}


const std::vector<Token>& Lexer::GetTokens() const{
    return tokens_;
}

void Lexer::push_token(char ch) {
    try {
        tokens_.push_back(Token::CreateToken(ch));
    } catch (const TokenError&) {
        throw InputError(
            std::string("Lexer::CreateTokens(): invalid token '") + ch + "'"
        );
    }
}