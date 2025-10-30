#include <gtest/gtest.h>

#include "src/Lexer.h"
using namespace std;

TEST(LexerTest, BasicOperations) {
	std::string input = "x + 2";
	Lexer lexer(input);
	lexer.CreateTokens();
	auto tokens = lexer.GetTokens();

	ASSERT_EQ(tokens.size(), 3);
	EXPECT_EQ(tokens[0].type, TokenType::X);
	EXPECT_EQ(tokens[1].type, TokenType::Add);
	EXPECT_EQ(tokens[2].type, TokenType::Num);
}

TEST(LexerTest, MultipleDigitNumber) {
	std::string input = "123+x";
	Lexer lexer(input);
	lexer.CreateTokens();
	auto tokens = lexer.GetTokens();

	ASSERT_EQ(tokens.size(), 3);
	EXPECT_EQ(tokens[0].type, TokenType::Num);
	EXPECT_EQ(tokens[0].value, "123");
}

TEST(LexerTest, AllOperators) {
	std::string input = "x+-*/^";
	Lexer lexer(input);
	lexer.CreateTokens();
	auto tokens = lexer.GetTokens();

	ASSERT_EQ(tokens.size(), 6);
	EXPECT_EQ(tokens[1].type, TokenType::Add);
	EXPECT_EQ(tokens[2].type, TokenType::Sub);
	EXPECT_EQ(tokens[3].type, TokenType::Mul);
	EXPECT_EQ(tokens[4].type, TokenType::Div);
	EXPECT_EQ(tokens[5].type, TokenType::Pow);
}

TEST(LexerTest, IgnoreSpaces) {
	std::string input = "x + 2 ";
	Lexer lexer(input);
	lexer.CreateTokens();
	auto tokens = lexer.GetTokens();

	ASSERT_EQ(tokens.size(), 3);
}

TEST(LexerTest, InvalidTokenThrows) {
	std::string input = "x&2";
	Lexer lexer(input);

	EXPECT_THROW(lexer.CreateTokens(), InputError);
}

TEST(LexerTest, EmptyInputThrows) {
	std::string input = "";

	EXPECT_THROW(Lexer lexer(input), InputError);
}

TEST(LexerTest, BigX) {
	std::string input = "X^2";

	EXPECT_THROW(Lexer lexer(input), InputError);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);


    return RUN_ALL_TESTS();
}