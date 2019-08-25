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
    segtree[index] = segtree[2 * index + 1] + segtree[2 * index + 2];
}
void updateQueryadd(vector<int> &segtree, vector<int> &a, int left, int right, int index, int pos, int value)
{
    if (pos < left || right < pos)
        return;
    if (left == right)
    {
        a[pos] += value;
        segtree[index] += value;
        return;
    }
    int mid = (right + left) / 2;
    if (pos <= mid)
        updateQueryadd(segtree, a, left, mid, 2 * index + 1, pos, value);
    else
        updateQueryadd(segtree, a, mid + 1, right, 2 * index + 2, pos, value);
    segtree[index] = segtree[2 * index + 1] + segtree[2 * index + 2];
}
void updateQuerypoor(vector<int> &segtree, vector<int> &a, int left, int right, int index, int pos, int value)
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
        updateQuerypoor(segtree, a, left, mid, 2 * index + 1, pos, value);
    else
        updateQuerypoor(segtree, a, mid + 1, right, 2 * index + 2, pos, value);
    segtree[index] = segtree[2 * index + 1] + segtree[2 * index + 2];
}
int sumRange(vector<int> &segtree, int left, int right, int from, int to, int index)
{
    if (from <= left && to >= right)
    {
        return segtree[index];
    }
    if (from > right || to < left)
        return 0;
    int mid = (left + right) / 2;
    return sumRange(segtree, left, mid, from, to, 2 * index + 1) + sumRange(segtree, mid + 1, right, from, to, 2 * index + 2);
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int T, m = 0;
    cin >> T;
    while (T > 0)
    {
        int n, q, x, task, i, j, v;
        vector<int> a;
        T--;
        m++;
        cout << "Case " << m << ":" << endl;
        cin >> n >> q;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }
        int h = (int)ceil(log2(n));
        int sizetree = 2 * pow(2, h) - 1;
        vector<int> segtree(sizetree, 0);
        buildTree(a, segtree, 0, n - 1, 0);
        for (int k = 0; k < q; k++)
        {
            cin >> task;
            switch (task)
            {
            case 1:
                cin >> i;
                cout << a[i] << endl;
                updateQuerypoor(segtree, a, 0, n - 1, 0, i, 0);
                break;
            case 2:
                cin >> i >> v;
                updateQueryadd(segtree, a, 0, n - 1, 0, i, v);
                break;
            case 3:
                cin >> i >> j;
                cout << sumRange(segtree, 0, n - 1, i, j, 0) << endl;
                break;
            }
        }
    }
}