#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1e9
using namespace std;
struct node
{
    int optimal;
    int open;
    int close;
};
void buildTree(string &a, vector<node> &segtree, int left, int right, int index)
{
    if (left == right)
    {
        if (a[left] == '(')
        {
            segtree[index] = {0, 1, 0};
        }
        else
        {
            segtree[index] = {0, 0, 1};
        }
        return;
    }
    int mid = (left + right) / 2;
    buildTree(a, segtree, left, mid, 2 * index + 1);
    buildTree(a, segtree, mid + 1, right, 2 * index + 2);
    int temp = min(segtree[2 * index + 1].open, segtree[2 * index + 2].close);
    segtree[index].optimal = segtree[2 * index + 1].optimal + segtree[2 * index + 2].optimal + temp;
    segtree[index].open = segtree[2 * index + 1].open + segtree[2 * index + 2].open - temp;
    segtree[index].close = segtree[2 * index + 1].close + segtree[2 * index + 2].close - temp;
}
void updateQuery(vector<node> &segtree, string &s, int left, int right, int index, int pos)
{
    if (pos < left || right < pos)
        return;
    if (left == right)
    {
        if (s[left] == '(')
        {
            segtree[index] = {0, 0, 1};
            s[left] = ')';
        }
        else
        {
            segtree[index] = {0, 1, 0};
            s[left] = '(';
        }
        return;
    }
    int mid = (right + left) / 2;
    //if (pos <= mid)
    updateQuery(segtree, s, left, mid, 2 * index + 1, pos);
    //else
    updateQuery(segtree, s, mid + 1, right, 2 * index + 2, pos);
    int temp = min(segtree[2 * index + 1].open, segtree[2 * index + 2].close);
    segtree[index].optimal = segtree[2 * index + 1].optimal + segtree[2 * index + 2].optimal + temp;
    segtree[index].open = segtree[2 * index + 1].open + segtree[2 * index + 2].open - temp;
    segtree[index].close = segtree[2 * index + 1].close + segtree[2 * index + 2].close - temp;
}
int main()
{
    ios::sync_with_stdio(false);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    for (int j = 0; j < 10; j++)
    {
        cout << "Test " << j + 1 << ":" << endl;
        int n, q;
        string s;
        cin >> n;
        cin >> s;
        cin >> q;
        int h = (int)ceil(log2(n));
        int sizetree = 2 * pow(2, h) - 1;
        vector<node> segtree(sizetree);
        buildTree(s, segtree, 0, n - 1, 0);
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            if (x > 0)
            {
                updateQuery(segtree, s, 0, n - 1, 0, x - 1);
            }
            else
            {
                if (segtree[0].open == 0 && segtree[0].close == 0)
                    cout << "YES" << endl;
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }
}