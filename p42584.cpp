#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    int l = prices.size();
    int cnt = 0;

    for (int i = 0; i < l - 1; i++) {
        for (int j = i + 1; j < l; j++) {
            cnt++;
            if (prices[i] <= prices[j])
                continue;
            else
                break;
        }
        answer.push_back(cnt);
        cnt = 0;
    }
    answer.push_back(cnt);

    return answer;
}