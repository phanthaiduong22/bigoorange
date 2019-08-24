#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

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
void updateQuery_sumQuerylazy(vector<int> &segtree, vector<int> &lazy, int left, int right, int from, int to, int delta, int index)
{
    if (left > right)
        return;
    if (lazy[index] != 0)
    {
        segtree[index] += lazy[index] * (right - left + 1);
        if (right != left)
        {
            lazy[index * 2 + 1] += lazy[index];
            lazy[index * 2 + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if (from > right || to < left)
        return;
    if (from <= left && to >= right)
    {
        segtree[index] += delta * (right - left + 1);
        if (left != right)
        {
            lazy[2 * index + 1] += delta;
            lazy[2 * index + 2] += delta;
        }
        return;
    }
    int mid = (left + right) / 2;
    updateQuery_sumQuerylazy(segtree, lazy, left, mid, from, to, delta, 2 * index + 1);
    updateQuery_sumQuerylazy(segtree, lazy, mid + 1, right, from, to, delta, 2 * index + 2);
    segtree[index] = segtree[2 * index + 1] + segtree[2 * index + 2];
}
int sumQuerylazy(vector<int> &segtree, vector<int> &lazy, int left, int right, int from, int to, int index)
{
    if (left > right)
        return 0;
    if (lazy[index] != 0)
    {
        segtree[index] += lazy[index] * (right - left + 1);
        if (left != right)
        {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    if (from > right || to < left)
        return 0;
    if (from <= left && to >= right)
    {
        return segtree[index];
    }
    int mid = (left + right) / 2;
    return sumQuerylazy(segtree, lazy, left, mid, from, to, 2 * index + 1) + sumQuerylazy(segtree, lazy, mid + 1, right, from, to, 2 * index + 2);
}
int main()
{
}