#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	for (int i = 0; i < phone_book.size(); i++) {
		/*m[i] = phone_book[i];*/
		for (int j = 0; j < phone_book.size(); j++) {
			if (j != i && phone_book[j].size() >= phone_book[i].size()) {
				string t;
				for (int k = 0; k < phone_book[i].size(); k++) {
					t.push_back(phone_book[j][k]);
				}
				if (t == phone_book[i]) {
					answer = false;
					goto skip;
				}

			}
		}
	}
skip:
	return answer;
}