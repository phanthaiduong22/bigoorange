#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int minimalpainting(vector<int> a, int left, int right)
{
    if (right - left <= 1)
    {
        int ans=1;
        for (int i = left; i <= right; i++)
        {
            if (a[i] > 1)
                ans = 2;
            break;
        }
        return ans;
    }
    int mid = (right + left) / 2;
    int minleft=minimalpainting(a,left,mid);    
    int minright=minimalpainting(a,mid+1,right);


}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    long long x;
    vector<long long> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
}