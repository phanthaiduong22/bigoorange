#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
// #define FIO                           \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL)

using namespace std;
#define INF 1e15

void buildTree(vector<long long> &a, vector<long long> &segtree, long long left, long long right, long long index)
{
    if (left == right)
    {
        segtree[index] = a[left];
        return;
    }
    long long mid = (left + right) / 2;
    buildTree(a, segtree, left, mid, 2 * index + 1);
    buildTree(a, segtree, mid + 1, right, 2 * index + 2);
    segtree[index] = min(segtree[2 * index + 1], segtree[2 * index + 2]);
}
void updateQuery_minRangeLazy(vector<long long> &segtree, vector<long long> &lazy, long long left, long long right, long long from, long long to, long long delta, long long index)
{
    if (left > right)
        return;
    //make sure all propagation is done at index. If not update tree
    //at index and mark its childrenf or lazy propagation
    if (lazy[index] != 0)
    {
        segtree[index] += lazy[index];
        if (left != right) // not a leaf node
        {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    // no overlap condition
    if (from > right || to < left)
        return;
    //total overlap conditional
    if (from <= left && to >= right)
    {
        segtree[index] += delta;
        if (left != right)
        {
            lazy[2 * index + 1] += delta;
            lazy[2 * index + 2] += delta;
        }
        return;
    }
    long long mid = (left + right) / 2;
    updateQuery_minRangeLazy(segtree, lazy, left, mid, from, to, delta, 2 * index + 1);
    updateQuery_minRangeLazy(segtree, lazy, mid + 1, right, from, to, delta, 2 * index + 2);
    segtree[index] = min(segtree[2 * index + 1], segtree[2 * index + 2]);
}
long long minRangeLazy(vector<long long> &segtree, vector<long long> &lazy, long long left, long long right, long long from, long long to, long long index)
{
    if (left > right)
        return INF;
    if (lazy[index] != 0)
    {
        segtree[index] += lazy[index];
        if (left != right)
        {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    // no overlap
    if (from > right || to < left)
        return INF;
    if (from <= left && to >= right)
    {
        return segtree[index];
    }

    //partial overlap
    long long mid = (left + right) / 2;
    return min(minRangeLazy(segtree, lazy, mid + 1, right, from, to, 2 * index + 2), minRangeLazy(segtree, lazy, left, mid, from, to, 2 * index + 1));
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long n, m, x;
    string s, s1 = "";
    vector<long long> a;
    cin >> n;
    for (long long i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    long long h = (long long)ceil(log2(n));
    long long sizetree = 2 * pow(2, h) - 1;
    vector<long long> segtree(sizetree, INF);
    vector<long long> lazy(sizetree, 0);
    cin >> m;
    buildTree(a, segtree, 0, n - 1, 0);
    cin.ignore();
    for (long long i = 0; i < m; i++)
    {
        getline(cin, s);
        stringstream ss(s);

        int l, r, v;
        ss >> l >> r;
        if (ss >> v) {
            if (l > r)
            {
                updateQuery_minRangeLazy(segtree, lazy, 0, n - 1, 0, r, v, 0);
                updateQuery_minRangeLazy(segtree, lazy, 0, n - 1, l, n - 1, v, 0);
            }
            else
                updateQuery_minRangeLazy(segtree, lazy, 0, n - 1, l, r, v, 0);
        }
        else {
            if (l > r)
            {
                cout << min(minRangeLazy(segtree, lazy, 0, n - 1, 0, r, 0), minRangeLazy(segtree, lazy, 0, n - 1, l, n - 1, 0))<<endl;
            }
            else
                cout << minRangeLazy(segtree, lazy, 0, n - 1, l, r, 0)<<endl;
        }
    }
}
