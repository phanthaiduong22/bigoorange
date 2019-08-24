//day con tang va con giam khong rang buoc
#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int> &a, const vector<int> &sub, int n, int x)
{
    int left = 0;
    int right = n;
    int pos = right;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int index = sub[mid];
        if (a[index] >= x)
        {
            pos = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return pos;
}
vector<pair<int, int>> LIS(const vector<int> &a)
{
    vector<int> result, path;
    vector<pair<int, int>> d;
    int length = 1;
    path.assign(a.size(), -1);
    result.push_back(0);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < a[result[0]])
        {
            result[0] = i;
        }
        else if (a[i] > a[result[length - 1]])
        {
            path[i] = result[length - 1];
            result.push_back(i);
            length++;
        }
        else
        {
            int pos = lowerBound(a, result, length, a[i]);
            path[i] = result[pos - 1];
            result[pos] = i;
        }
        d.push_back({result.size(), a[result[result.size() - 1]]});
    }
    return d;
}
int main()
{
    //ios::sync_with_stdio(false);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    while (cin >> n)
    {
        vector<pair<int, int>> d1, d2;
        int x, max = 1;
        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            b.push_back(a[n - i - 1]);
        }
        d1 = LIS(a);
        d2 = LIS(b);
        for (int i = 0; i < d1.size() - 1; i++)
        {
            if (d1[i].first == d2[d1.size() - i - 2].first)
            {
                if (d1[i].second == d2[d1.size() - i - 2].second)
                {
                    int temp = d1[i].first + d2[d1.size() - i - 2].first - 1;
                    if (temp % 2 == 0)
                        temp--;
                    if (temp > max)
                        max = temp;
                }
                else
                {
                    int temp = d1[i].first + d2[d1.size() - i - 2].first;
                    if (temp % 2 == 0)
                        temp--;
                    if (temp > max)
                        max = temp;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}