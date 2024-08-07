#include<stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {

	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		int strikes = getStrikeNumber(guessNumber);
		int balls = getBallNumber(guessNumber);

		return { strikes == 3, strikes, balls };
	}

	int getBallNumber(const std::string& guessNumber) {
		int balls = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j || guessNumber[i] != question[j])continue;
				balls++;
			}
		}
		return balls;
	}

	int getStrikeNumber(const std::string& guessNumber) {
		int strikes = 0;
		for (int i = 0; i < 3; i++) {
			if (guessNumber[i] == question[i]) {
				strikes++;
			}
		}
		return strikes;
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letter");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Mus be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
private:
	string question;
};