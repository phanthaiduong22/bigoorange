#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int T,n;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>n; 
        cout<<n*2-2<<endl;
    }
}