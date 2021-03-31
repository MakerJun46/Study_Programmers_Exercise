#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> score;
    vector<char> bonus;
    vector<pair<int, char>> option;
    

    int chance = 0;

    for (int i = 0; i < dartResult.size(); i++) {
        char c = dartResult[i];
        
        if (isdigit(c)) {
            chance++;
            if (isdigit(dartResult[i + 1])) {
                score.push_back(10);
                i++;
            }
            else
                score.push_back(atoi(&c));
        }
        else if (c == 'S' || c == 'D' || c == 'T') {
            bonus.push_back(c);
        }
        else if (c == '*' || c == '#') {
            option.push_back(make_pair(chance, c));
        }
    }

    for (int i = 0; i < bonus.size(); i++) {
        if (bonus[i] == 'D')
            score[i] = pow(score[i], 2);
        else if (bonus[i] == 'T')
            score[i] = pow(score[i], 3);
    }

    for (int i = 0; i < option.size(); i++) {
        if (option[i].second == '*') {
            if (option[i].first == 1)
                score[0] *= 2;
            else {
                score[option[i].first - 2] *= 2;
                score[option[i].first - 1] *= 2;
            }
        }
        else if (option[i].second == '#') {
            score[option[i].first - 1] *= -1;
        }
    }
    
    for (auto i : score) {
        answer += i;
    }

    return answer;
}

int main() {

    cout << solution("1S*2T*3S");
    cout << endl;

    cout << solution("1D2S#10S");

    cout << endl;
    cout << solution("1D#2S*3S");

    return 0;
}

/* Best Answer
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    stringstream ss(dartResult);

    int sum[3] = { 0, 0, 0 };
    int options[3] = { 1, 1, 1 };
    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;

        bonus = ss.get();
        option = ss.get();

        if (option != '*' && option != '#') {
            ss.unget();
        }

        switch (bonus) {
        case 'S':
            sum[i] += pow(score, 1);
            break;
        case 'D':
            sum[i] += pow(score, 2);
            break;
        case 'T':
            sum[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] = -options[i];
            break;
        default:
            break;
        }
    }

    return sum[0] * options[0] + sum[1] * options[1] + sum[2] * options[2];
}
*/