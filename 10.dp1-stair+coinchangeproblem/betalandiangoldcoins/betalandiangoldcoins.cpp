#include <iostream>
#include <vector>
#define MAX 1e7
using namespace std;
vector<long long> store(MAX, 0);
long long dynamic_programing(long long n)
{

    long long a = n / 2, b = n / 3, c = n / 4;
    if (a + b + c > n)
    {
        long long x,y,z;
        if (a >= MAX || store[a] == 0)
        {
            x = dynamic_programing(a);
            if(a<MAX)
                store[a]=x;
        }
        else
            x=store[a];
        if (b >= MAX || store[b] == 0)
        {
            y = dynamic_programing(b);
            if(b<MAX)
                store[b]=y;
        }
        else
            y=store[b];
        if (c >= MAX || store[c] == 0)
        {
            z = dynamic_programing(c);
            if(c<MAX)
                store[c]=z;
        }
        else
            z=store[c];
        return x+y+z;        
    }
    return n;
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    long long n;
    while (cin >> n)
        cout<<dynamic_programing(n)<<endl;
}