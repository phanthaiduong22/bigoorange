#include <iostream>
#include <vector>
using namespace std;
vector<int> result;
vector<int> path;
void printLIS(const vector<int> &a, int length)
{
    vector<int> b;
    int i = result[length - 1];
    while (i >= 0)
    {
        b.push_back(a[i]);
        i = path[i];
    }
    for (int i = b.size() - 1; i >= 0; i--)
        cout << b[i] << " ";
}
int lowerBound(const vector<int> &a, const vector<int> &sub, int n, int x)
{
    int left = 0;
    int right = n;
    int pos = right;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int index = sub[mid];
        if (a[index] >= x)
        {
            pos = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return pos;
}
int LIS(const vector<int> &a)
{
    int length = 1;
    path.assign(a.size(), -1);
    result.push_back(0);
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] <= a[result[0]])
        {
            result[0] = i;
        }
        else if (a[i] > a[result[length - 1]])
        {
            path[i] = result[length - 1];
            result.push_back(i);
            length++;
        }
        else
        {
            int pos = lowerBound(a, result, length, a[i]);
            path[i] = result[pos - 1];
            result[pos] = i;
        }
    }
    return length;
}
int main()
{
    vector<int> a = {2, 5, 12, 3, 10, 6, 8, 14, 4, 11, 7, 15};
    int length = LIS(a);
    cout << "length of longest increasing subsequence is: ";
    cout << length << endl;
    printLIS(a, length);
    return 0;
}