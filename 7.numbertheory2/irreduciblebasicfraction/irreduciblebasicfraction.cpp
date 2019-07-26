#include <iostream>
#include <vector>

using namespace std;

int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)

            {
                n /= i;
            }
            result=result/i*(i-1);
        }
    }
    if(n>1)
        result=result/n*(n-1);
        return result;
}
int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        cout<<phi(n)<<endl;
    }
}