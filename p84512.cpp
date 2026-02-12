#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    vector<int> weight(5, 0);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i; j++) {
            weight[j] += pow(5, i);
        }
    }

    string vowels = "AEIOU";

    int answer = 0;

    for (int i = 0; i < word.length(); i++) {
        int digit = vowels.find(word[i]);  // 5진수 값
        answer += digit * weight[i];
        answer += 1;  // 접두어 자체 포함
    }

    return answer;
}