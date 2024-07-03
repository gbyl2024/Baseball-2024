#include "pch.h"
#include "../Project20/baseball.cpp"
#include<stdexcept>
using namespace std;

TEST(BaseballGame, ThrowExceptionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}