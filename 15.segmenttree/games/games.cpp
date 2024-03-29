#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
// #define FIO                           \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL)

using namespace std;
#define INF 0

void buildTree(vector<int> &a, vector<int> &segtree, int left, int right, int index)
{
    if (left == right)
    {
        segtree[index] = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    buildTree(a, segtree, left, mid, 2 * index + 1);
    buildTree(a, segtree, mid + 1, right, 2 * index + 2);
    segtree[index] = max(segtree[2 * index + 1], segtree[2 * index + 2]);
}
void updateQuery_minRangeLazy(vector<int> &segtree, vector<int> &lazy, int left, int right, int from, int to, int delta, int index)
{
    if (left > right)
        return;
    //make sure all propagation is done at index. If not update tree
    //at index and mark its childrenf or lazy propagation
    if (lazy[index] != 0)
    {
        segtree[index] = lazy[index];
        if (left != right) // not a leaf node
        {
            lazy[2 * index + 1] = lazy[index];
            lazy[2 * index + 2] = lazy[index];
        }
        lazy[index] = 0;
    }
    // no overlap condition
    if (from > right || to < left)
        return;
    //total overlap conditional
    if (from <= left && to >= right)
    {
        segtree[index] = delta;
        if (left != right)
        {
            lazy[2 * index + 1] = delta;
            lazy[2 * index + 2] = delta;
        }
        return;
    }
    int mid = (left + right) >> 1;
    updateQuery_minRangeLazy(segtree, lazy, left, mid, from, to, delta, 2 * index + 1);
    updateQuery_minRangeLazy(segtree, lazy, mid + 1, right, from, to, delta, 2 * index + 2);
    segtree[index] = max(segtree[2 * index + 1], segtree[2 * index + 2]);
}
int minRangeLazy(vector<int> &segtree, vector<int> &lazy, int left, int right, int from, int to, int index)
{
    if (left > right)
        return INF;
    if (lazy[index] != 0)
    {
        segtree[index] = lazy[index];
        if (left != right)
        {
            lazy[2 * index + 1] = lazy[index];
            lazy[2 * index + 2] = lazy[index];
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
    int mid = (left + right) >> 1;
    return max(minRangeLazy(segtree, lazy, mid + 1, right, from, to, 2 * index + 2), minRangeLazy(segtree, lazy, left, mid, from, to, 2 * index + 1));
}
int main()
{
    // FIO;
    ios::sync_with_stdio(false);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    vector<int> a;
    int N, M, x;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    int n = a.size();
    //height of segment tree
    int h = (int)ceil(log2(n));
    //maximum size of segment tree
    int sizetree = 2 * (int)pow(2, h) - 1;
    vector<int> segtree(sizetree, INF);
    vector<int> lazy(sizetree, 0);
    buildTree(a, segtree, 0, n - 1, 0);
    int delta, fromindex, toindex;
    for (int i = 0; i < M; i++)
    {
        cin >> fromindex >> toindex;
        int max1 = minRangeLazy(segtree, lazy, 0, n - 1, fromindex - 1, fromindex + toindex - 2, 0);
        cout << max1 + 1 << endl;
        updateQuery_minRangeLazy(segtree, lazy, 0, n - 1, fromindex - 1, fromindex + toindex - 2, max1 + 1, 0);
    }
}
