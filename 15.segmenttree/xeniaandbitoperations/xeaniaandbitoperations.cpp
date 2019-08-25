#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
//#define INF 1e9
using namespace std;
void buildTree(vector<int> &a, vector<int> &segtree, int left, int right, int index, int task)
{
    if (left == right)
    {
        segtree[index] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    buildTree(a, segtree, left, mid, 2 * index + 1,abs(task-1));
    buildTree(a, segtree, mid + 1, right, 2 * index + 2,abs(task-1));
    if (task == 1)
        segtree[index] = segtree[2 * index + 1] ^ segtree[2 * index + 2];
    else
        segtree[index] = segtree[2 * index + 1] | segtree[2 * index + 2];
}
void updateQuery(vector<int> &segtree, vector<int> &a, int left, int right, int index, int pos, int value,int task)
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
        updateQuery(segtree, a, left, mid, 2 * index + 1, pos, value,abs(task-1));
    else
        updateQuery(segtree, a, mid + 1, right, 2 * index + 2, pos, value,abs(task-1));
    if (task == 1)
        segtree[index] = segtree[2 * index + 1] ^ segtree[2 * index + 2];
    else
        segtree[index] = segtree[2 * index + 1] | segtree[2 * index + 2];
}
// int productRange(vector<int> &segtree, int left, int right, int from, int to, int index,task)
// {
//     if (from <= left && to >= right)
//     {
//         return segtree[index];
//     }
//     if (from > right || to < left)
//         return 1;
//     int mid = (left + right) / 2;
//     if (task == 1)
//         segtree[index] = segtree[2 * index + 1] ^ segtree[2 * index + 2];
//     else
//         segtree[index] = segtree[2 * index + 1] | segtree[2 * index + 2];
// }
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a;
    n=1<<n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int h = (int)ceil(log2(n));
    int task = h % 2;
    int sizetree = 2 * pow(2, h) - 1;
    vector<int> segtree(sizetree, 1);
    buildTree(a, segtree, 0, n - 1, 0, abs(task - 1));
    for(int i=0;i<m;i++)
    {
        int p,b;
        cin>>p>>b;
        updateQuery(segtree,a,0,n-1,0,p-1,b,abs(task-1));
        cout<<segtree[0]<<endl;
    }
}
