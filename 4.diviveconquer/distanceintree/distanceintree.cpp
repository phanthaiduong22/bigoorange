#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
vector<int>graph[1000005];
bfs(int s)
{
    for(int i=0;i<V)
}
int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
}