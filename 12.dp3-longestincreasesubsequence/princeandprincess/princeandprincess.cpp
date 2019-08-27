#include <iostream>
#include <vector>
using namespace std;
vector<int> result;
vector<int> path;
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
int LIS(const vector<int> &a)
{
    int length = 1;
    path.assign(a.size(), -1);
    result.push_back(0);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] <= a[result[0]])
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
    }
    return length;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int T,test=0;
    cin >> T;
    while (T > 0)
    {
        cout<<  "Case "<<test+1<<": ";
        test++;
        int n, p, q, x;
        vector<int> a;
        T--;
        cin >> n >> p >> q;
        vector<int> pos(n * n + 1, -1);
        for (int i = 0; i < p + 1; i++)
        {
            cin >> x;
            pos[x] = i;
        }
        for (int i = 0; i < q + 1; i++)
        {
            cin >> x;
            if (pos[x] >= 0)
                a.push_back(pos[x]);
        }
        cout << LIS(a)<<endl;
        result.clear();
        path.clear();
    }
}