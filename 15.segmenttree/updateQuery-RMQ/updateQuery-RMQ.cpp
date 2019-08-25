#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1e9
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
    segtree[index] = min(segtree[2 * index + 1], segtree[2 * index + 2]);
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
    segtree[index] = min(segtree[2 * index + 1], segtree[2 * index + 2]);
}
int minRange(vector<int> &segtree, int left, int right, int from, int to, int index)
{
    if (from <= left && to >= right)
    {
        return segtree[index];
    }
    if (from > right || to < left)
        return INF;
    int mid = (left + right) / 2;
    return min(minRange(segtree, left, mid, from, to, 2 * index + 1), minRange(segtree, mid + 1, right, from, to, 2 * index + 2));
}
int main()
{
    vector<int> a = {5, -7, 9, 1, -2, 8, 3, 6, 4, 1};
    int n = a.size();
    int h = (int)ceil(log2(n));
    int sizetree = 2 * (int)pow(2, h) - 1;
    vector<int> segtree(sizetree, INF);
    buildTree(a, segtree, 0, n - 1, 0);
    int fromRange = 2;
    int toRange = 7;
    updateQuery(segtree, a, 0, n - 1, 0, 4, 9);
    cout << minRange(segtree, 0, n - 1, fromRange, toRange, 0);
}