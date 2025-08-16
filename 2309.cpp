#include <bits/stdc++.h>
using namespace std;

/*
20
7
23
19
10
15
25
8
13
*/

/*
7
8
10
13
19
20
23
*/

int arr[9];
int result;
int n = 9, r = 7;

void solve()
{
    int sum = 0;
    for (int i = 0; i < r; i++)
    {
        sum += arr[i];
    }
    if (sum == 100)
    {
        sort(arr, arr + 7);
        for (int i = 0; i < 7; i++)
        {
            cout << arr[i] << "\n";
        }
        exit(0);
    }
}

void makePermutation(int n, int r, int depth)
{
    if (depth == r)
    {
        solve();
        return;
    }
    for (int i = depth; i < n; i++)
    {
        swap(arr[i], arr[depth]);
        makePermutation(n, r, depth + 1);
        swap(arr[i], arr[depth]);
    }
}
int main()
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    makePermutation(n, r, 0);
    return 0;
}
