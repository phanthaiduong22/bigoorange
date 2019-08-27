#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
vector<int> result;
vector<int> path;
struct member
{
    int s, b, id;
};
bool option(member &a, member &c)
{
    return (a.s < c.s || (a.s == c.s && a.b > c.b));
}
void printLIS(const vector<member> &a, int length)
{
    vector<int> b;
    int i = result[length - 1];
    while (i >= 0)
    {
        b.push_back(a[i].id);
        i = path[i];
    }
    for (int i = b.size() - 1; i >= 0; i--)
        cout << b[i] << " ";
}
int lowerBound(const vector<member> &a, const vector<int> &sub, int n, int x)
{
    int left = 0;
    int right = n;
    int pos = right;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int index = sub[mid];
        if (a[index].b >= x)
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
int LIS(const vector<member> &a)
{
    int length = 1;
    path.assign(a.size(), -1);
    result.push_back(0);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i].b <= a[result[0]].b)
        {
            result[0] = i;
        }
        else
        if (a[i].b > a[result[length - 1]].b)
        {
            path[i] = result[length - 1];
            result.push_back(i);
            length++;
        }
        else
        {
            int pos = lowerBound(a, result, length, a[i].b);
            path[i] = result[pos - 1];
            result[pos] = i;
        }
    }
    return length;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, x, y;
    vector<member> a, c;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a.push_back({x, y, i});
    }
    sort(a.begin(), a.end(), option);
    // for (int i = 0; i < a.size(); i++)
    //     cout << a[i].s << " " << a[i].b << " " << a[i].id << endl;
    int length = LIS(a);
    cout << length << endl;
    printLIS(a, length);
}