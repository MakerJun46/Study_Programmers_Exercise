#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<char> vowels = { 'A', 'E', 'I', 'O', 'U' };
vector<string> dictionary;

void func(string word, int wordLength)
{
	if (wordLength == word.length())
	{
		dictionary.push_back(word);
		return;
	}
	for (char vowel : vowels)
	{
		func(word + vowel, wordLength);
	}
}

int solution(string word) {
	for (int len = 1; len <= 5; len++)
	{
		string word = "";
		func(word, len);
	}
	sort(dictionary.begin(), dictionary.end());
	for (int i = 0; i < dictionary.size(); i++)
	{
		if (word == dictionary[i])
		{
			return i + 1;
		}
	}
}

/*
int solution(string word)
{
	int answer = 0;
	int mul[5] = { 1, 5, 25, 125, 625 };

	map<char, int> m = { {'A', 0}, {'E', 1}, {'I', 2}, {'O', 3}, {'U', 4} };

	for (int i = 0; i < word.size(); i++)
	{
		answer += 1;
		for (int j = 0; j < m[word[i]]; j++)
		{
			for (int k = 4; k >= i; k--)
			{
				answer += mul[4 - k];
			}
		}


	}
	return answer;
}
*/

void main()
{
    cout << solution("I") << endl;

	for (auto i : dictionary)
	{
		cout << i << endl;
	}
}