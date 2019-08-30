#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#define INF 1e9
using namespace std;
vector<int> d;
bool option1(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}
void buildTree(vector<int> &a, vector<int> &segtree, int left, int right, int index)
{
    if (left == right)
    {
        segtree[index] = a[left];
        d.push_back(index);
        return;
    }
    int mid = (left + right) / 2;
    buildTree(a, segtree, left, mid, 2 * index + 1);
    buildTree(a, segtree, mid + 1, right, 2 * index + 2);
    segtree[index] = min(segtree[2 * index + 1], segtree[2 * index + 2]);
}
void update(vector<int> &segTree, vector<int> &lazy, int lo, int hi, int val, int pos, int x)
{
    if (lazy[pos] != 0)
    {
        segTree[pos] += lazy[pos];
        if (lo != hi)
        {
            lazy[2 * pos + 1] += lazy[pos];
            lazy[2 * pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if (lo == hi)
    {
        if (segTree[pos] > x)
        {
            segTree[pos] += val;
        }
        return;
    }
    if (segTree[pos] > x)
    {
        segTree[pos] += val;
        if (lo != hi)
        {
            lazy[2 * pos + 1] += val;
            lazy[2 * pos + 2] += val;
        }
        return;
    }
    int m = (lo + hi) / 2;
    update(segTree, lazy, lo, m, val, 2 * pos + 1, x);
    update(segTree, lazy, m + 1, hi, val, 2 * pos + 2, x);
    segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    vector<pair<int, int>> a;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end(), option1);
    vector<int> b;
    for (int i = 0; i < a.size(); i++)
        b.push_back(a[i].first);
    int h = (int)ceil(log2(n));
    //maximum size of segment tree
    int sizetree = 2 * (int)pow(2, h) - 1;
    vector<int> segtree(sizetree, INF);
    vector<int> lazy(sizetree, 0);
    buildTree(b, segtree, 0, n - 1, 0);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        update(segtree, lazy, 0, n - 1, -1, 0, x);
    }
    vector<pair<int, int>> c;
    for (int i = 0; i < a.size(); i++)
    {
        int temp=a[i].second;
        c.push_back({temp, d[i]});
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++)
        cout << segtree[d[i]] << " ";
}