#include <iostream>
#include <string>
#include <vector>

using namespace std;
void KMPpreprocess(const string &p, vector<int> &prefix)
{
     prefix[0]=0;
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
void KMPsearch(const string &t, const string &p, const vector<int>& prefix)
{
    int n= t.length();
    int m=p.length();
    int i=0,j=0;
    while(i<n)
    {
        if(p[j]==t[i])
        {            
            j++;
            i++;
        }
        if(j==m)
        {
            cout<<"Found pattern at index: "<<(i-j)<<endl;
            j=prefix[j-1];
        }
        else if(i<n&&p[j]!=t[i])
        {
            if(j!=0)
            {
                j=prefix[j];
            }
            else
            {
                i++;
            }
            
        }
    }
}
int main()
{

    string t = "ABABAABACDABABCABAB";
    string p = "ABABCABAB";
    vector<int> prefix(p.length());
    KMPpreprocess(p, prefix);
    KMPsearch(t,p,prefix);
    return 0;
}