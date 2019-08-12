//backtracking
#include <iostream>

using namespace std;

int n, k;
long long backtrack(int x, int count)
{
    if (count == 1)
    {
        if (x == 1)
            return 1;       
        if (x == k - 1)
            return k - 1;
    }
    else
    {
        if (x == k - 1)
            return (k - 1) * backtrack(1, count - 1) + (k - 1) * backtrack(x, count - 1);
        return backtrack(k - 1, count - 1);
    }
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n >> k;
    cout << backtrack(k - 1, n);
}
//dynamicprograming
// s0[i]=s1[i-1];
// s1[i]=so[i-1]+s1[i-1];
// s0[1]=0;
// s0[1]=k-1;