#include <iostream>
#include <vector>
using namespace std;
vector<int> result;
vector<int> path;
struct block
{
    int x;
    int y;
    int w;
};
bool compareblock(block a, block b) //a nho hon hoan toan so voi b
{
    if (a.x < b.x && a.y < b.y)
        return true;
    return false;
}(const vector<block> &a, int length)
{
    vector<block> b;
    int i = result[length - 1];
    while (i >= 0)
    {
        b.push_back(a[i]);
        i = path[i];
    }
    for (int i = b.size() - 1; i >= 0; i--)
        cout << b[i].w << " ";
}
int lowerBound(const vector<block> &a, const vector<int> &sub, int n, block x)
{
    int left = 0;
    int right = n;
    int pos = right;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int index = sub[mid];
        if (compareblock(a[index], x) == false)
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

int LIS(const vector<block> &a)
{
    int length = 1;
    path.assign(a.size(), -1);
    result.push_back(0);
    for (int i = 1; i < a.size(); i++)
    {
        if (compareblock(a[i], a[result[0]]))
        {
            result[0] = i;
        }
        else if (compareblock(a[i], a[result[length - 1]]) == false)
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
    }
    return length;
}
int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<block> a;
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            a.push_back({x, y, z});
            a.push_back({y, x, z});
            a.push_back({y, z, x});
            a.push_back({z, y, x});
            a.push_back({x, z, y});
            a.push_back({z, x, y});
        }
        int length = LIS(a);
        cout << length << endl;
        printLIS(a, length);
    }
}