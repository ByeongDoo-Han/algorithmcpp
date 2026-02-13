#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
        int d = storey % 10;
        storey /= 10;
        answer += min(10 - d, d);
        cout << min(10 - d, d) << " ";
        if (d >= 5) {
            if (d > 5) {
                storey += 1;
            } else if (storey / 10 > 0 && storey % 10 >= 5) {
                storey += 1;
            }
        }
    }

    return answer;
}