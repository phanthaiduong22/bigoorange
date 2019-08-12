#include <iostream>
#include <vector>
using namespace std;
vector<long long> result;
vector<long long> path;
void printLIS(const vector<long long> &a, long long length)
{
    vector<long long> b;
    long long i = result[length - 1];
    while (i >= 0)
    {
        b.push_back(a[i]);
        i = path[i];
        ;
    }
    for (long long i = b.size() - 1; i >= 0; i--)
        cout << b[i] << " ";
}
long long upperBound(const vector<long long> &a, const vector<long long> &sub, long long n, long long x)
{
    long long left = 0;
    long long right = n;
    long long pos = right;
    while (left < right)
    {
        long long mid = left + (right - left) / 2;
        long long index = sub[mid];
        if (a[index] > x)
        {
            pos = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    // if (a[sub[pos]] == a[sub[pos + 1]])
    // {
    //     while (a[sub[pos]] == a[sub[pos + 1]])
    //         pos++;
    //     return pos + 1;
    // }
    // else
    // {
    //     return pos;
    // }
    return pos;
    
}
vector<long long> reverse(vector<long long> a)
{
    vector<long long> b;
    for (long long i = a.size() - 1; i >= 0; i--)
        b.push_back(a[i]);
    return b;
}
long long LIS(const vector<long long> &a)
{
    long long length = 1;
    path.assign(a.size(), -1);
    result.push_back(0);
    for (long long i = 1; i < a.size(); i++)
    {
        if (a[i] < a[result[0]])
        {
            result[0] = i;
        }
        else if (a[i] >= a[result[length - 1]])
        {
            path[i] = result[length - 1];
            result.push_back(i);
            length++;
        }
        else
        {
            long long pos = upperBound(a, result, length, a[i]);
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
    long long x, length, j = 0;
    vector<long long> a;
    cin >> x;
    while (1)
    {
        if (x != -1)
        {
            a.push_back(x);
            cin >> x;
        }
        else
        {
            a = reverse(a);
            length = LIS(a);
            //prlong longLIS(a, length);
            j++;
            cout << "Test #" << j << ": " << endl;
            cout << "  maximum possible interceptions: " << length << endl;
            cout << endl;
            a.clear();
            result.clear();
            path.clear();
            cin >> x;
            if (x == -1)
                break;
        }
    }
}