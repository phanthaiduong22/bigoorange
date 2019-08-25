#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
//#define INF 1e9
using namespace std;
void buildTree(vector<int> &a, vector<int> &segtree, int left, int right, int index)
{
    if (left == right)
    {
        segtree[index] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    buildTree(a, segtree, left, mid, 2 * index + 1);
    buildTree(a, segtree, mid + 1, right, 2 * index + 2);
    segtree[index] = segtree[2 * index + 1] * segtree[2 * index + 2];
}
void updateQuery(vector<int> &segtree, vector<int> &a, int left, int right, int index, int pos, int value)
{
    if (pos < left || right < pos)
        return;
    if (left == right)
    {
        a[pos] = value;
        segtree[index] = value;
        return;
    }
    int mid = (right + left) / 2;
    if (pos <= mid)
        updateQuery(segtree, a, left, mid, 2 * index + 1, pos, value);
    else
        updateQuery(segtree, a, mid + 1, right, 2 * index + 2, pos, value);
    segtree[index] = segtree[2 * index + 1] * segtree[2 * index + 2];
}
int productRange(vector<int> &segtree, int left, int right, int from, int to, int index)
{
    if (from <= left && to >= right)
    {
        return segtree[index];
    }
    if (from > right || to < left)
        return 1;
    int mid = (left + right) / 2;
    return productRange(segtree, left, mid, from, to, 2 * index + 1) * productRange(segtree, mid + 1, right, from, to, 2 * index + 2);
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, k;
    while (cin >> n >> k)
    {
        int x, l, r, pos, value;
        char task;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x > 0)
                a.push_back(1);
            else if (x == 0)
                a.push_back(0);
            else
                a.push_back(-1);
        }
        int h = (int)ceil(log2(n));
        int sizetree = 2 * pow(2, h) - 1;
        vector<int> segtree(sizetree, 1);
        buildTree(a, segtree, 0, n - 1, 0);
        for (int i = 0; i < k; i++)
        {
            cin >> task;
            switch (task)
            {
            case 'C':
                cin >> pos >> value;
                updateQuery(segtree, a, 0, n - 1, 0, pos - 1, value);
                break;
            case 'P':
                cin >> l >> r;
                int res = productRange(segtree, 0, n - 1, l - 1, r - 1, 0);
                if (res > 0)
                    cout << '+';
                else if (res == 0)
                    cout << '0';
                else
                    cout << '-';
            }
        }
        cout << endl;
    }
}
