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
void KMPsearch(const string &s,const string &)
int main()
{

    string T = "AAAABAAAAA";
    vector<int> prefix(T.length());
    kmppreprocess(T, prefix);
    for (int i = 0; i < prefix.size(); i++)
    {
        cout << prefix[i];
    }
    int T;
    cin >> T;
    while (T > 0)
    {
        T--;
        string s, s1, s2 = "", s3 = "";
        getline(cin, s);
        getline(cin, s1);
        for (int i = 0; i < s.length(); i++)
            if (s != " ")
                s2 += s[i];
        for (int i = 0; i < s.length(); i++)
            if (s1 != " ")
                s3 += s1[i];
        vector<int> prefix(s3.length());
        kmppreprocess(s3, prefix);
    }
}