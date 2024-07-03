#include<stdexcept>

using namespace std;
class Baseball {
public:
	void guess(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letter");
		}

		for (char ch : guessNumber) {
			if (ch < '0' || ch > '9') {
				throw invalid_argument("Mus be number");
			}
		}
	}
};