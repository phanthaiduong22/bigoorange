#include <iostream>
#include <vector>

using namespace std;
vector<int> result;
vector<int> path;
int LDS(vector<int> &a)
{
    int length = 1;
    path.assign(a.size(), -1);
    result.push_back(0);
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > a[result[0]])
            result[0] = i;
        else if (a[i] <= a[result[length - 1]])
        {
            path[i] = result[length - 1];
            result.push_back(i);
            length++;
        }
    }
}
int main()
{

    vector<int> a = {8, 6, 10, 3, 12, 5, 2};
    int length = LDS(a);
}