#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool option(int a,int b)
{
    return a<b;
}
void permutation(vector<int> a, vector<int> b, vector<bool> visited, int number, int n)
{
    if (number == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << b[i] << " ";
        cout << endl;
    }
    else
    {
        for (int j = 0; j < n - 6 + 1; j++)
        {
            if (visited[number + j] == false)
            {
                b.push_back(a[number + j]);
                visited[number + j] = true;
                permutation(a, b, visited, number + 1, n);
                visited[number + j] = true;
                b.pop_back();
            }
        }
    }
}
int main()
{
    freopen("lotto.inp", "r", stdin);
    freopen("lotto.out", "w", stdout);
    int n;
    while (cin >> n)
    {
        vector<int> a, b;
        vector<bool> visited(n + 1, false);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(),a.end(),option);
        permutation(a, b, visited, 0, n);
        cout << endl;
    }
}