#include <iostream>
#include <string>
#include <vector>

using namespace std;
void kmppreprocess(const string &p, vector<int> &prefix)
{
    int m = p.length();
    int i = 1;
    int j = 0;
    while (i < m)
    {
        if (p[i] == p[j])
        {
            j++;
            prefix[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
                j = prefix[j - 1];
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }
}
int main()
{

    string T = "AAAABAAAAA";
    vector<int> prefix(T.length());
    kmppreprocess(T, prefix);
    for (int i = 0; i < prefix.size(); i++)
    {
        cout << prefix[i];
    }
}