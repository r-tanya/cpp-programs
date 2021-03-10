#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** args) {

	if (argc != 2) {
		cout << "Error.";
		return 1;
	}

	ifstream input(args[1]);

	if (input.is_open()) {
		cout << "Opened.\n";

		vector<string> wordvec;
		string s;
		while (input) {
			input >> s;
			for (int i = 0; i < s.length(); i++) {
				if (ispunct(s[i])) s.erase(i);
				s[i] = tolower(s[i]);
			}
			if (s != "") wordvec.push_back(s);
		}

		sort(wordvec.begin(), wordvec.end());

		vector<pair <int, string> > wordcount;
		int count = 1;
		wordcount.push_back(make_pair(count, wordvec[0]));
		for (int i = 1; i < wordvec.size(); i++)
		{
			if (wordvec[i] == wordvec[i - 1])
			{
				count = wordcount.back().first;
				wordcount.pop_back();
				wordcount.push_back(make_pair(++count, wordvec[i]));

			}
			else wordcount.push_back(make_pair(1, wordvec[i]));
		}

		sort(wordcount.begin(), wordcount.end());
		reverse(wordcount.begin(), wordcount.end());

		for (int i = 0; i < 10; i++)
		{
			cout << i + 1 << ". " << wordcount[i].second;
			cout << "\tfrequency: " << wordcount[i].first << "\n";
		}

		input.close();
	}
	else {
		cout << "Could not open.\n";
	}

	//system("pause");
	return 0;
}