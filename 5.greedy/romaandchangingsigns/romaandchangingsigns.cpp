#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, k, x,number_negative=0;
    int min=1e9;
    long long sum = 0;
    vector<int> a;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
        sum+=x;
        if(abs(x)<min)
            min=abs(x);
        if(x<0)
            number_negative++;
    }
    if(number_negative<k)
    {
        for(int i=0;i<number_negative;i++)
            sum=sum-2*a[i];
        if((k-number_negative)%2==1)
            sum=sum-2*min;
    }
    else
    {
        for(int i=0;i<k;i++)
            sum=sum-2*a[i];
    }
    cout<<sum;
}