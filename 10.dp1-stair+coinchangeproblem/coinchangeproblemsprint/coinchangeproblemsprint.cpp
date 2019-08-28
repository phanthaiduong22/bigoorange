#include <iostream>
#include <vector>

using namespace std;

int coinChangeproblem(int total, int coins[],int n)
{
    vector<int>result(total+1);
    result[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=coins[i];j<=total;j++)
        {
            result[j]+=result[j-coins[i]];
        }
    }
    return result[total];
}
void printSolution(vector<int> &result, int total, int coins[],int n, int pos)
{
    if(total==0)
    {
        for(int r: result)
        {
            cout<<r<<" ";
        }
        cout<<endl;
    }
    for(int i=pos;i<n;i++)
    {
        if(total>=coins[i])
        {
            result.push_back(coins[i]);
            printSolution(result,total-coins[i],coins,n,i);
            result.pop_back();
        }
    }
}
int main()
{
    int total=10;
    int coins[]={1,2,5,10};
    int n=4;
    cout<<"Number Of Solutions : ";
    cout<<coinChangeproblem(total,coins,n)<<endl;
    vector<int>result;
    printSolution(result,total,coins,n,0);
    return 0;
}