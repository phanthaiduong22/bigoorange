#include <iostream>
#include <vector>
#define N 8
using namespace std;
int board[N][N];
int ans[10000][70];
int soluong=-1;
bool checkqueen(int board[N][N], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][column] == 1)
            return false;
    }
    for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    for (int i = row, j = column; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}
bool tryqueen(int board[N][N], int row)
{
    if (row == N)
    {
        soluong++;
        int k=-1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                k++;
                ans[soluong][k]=board[i][j];
            }
        }
        return true;
    }
    for (int j = 0; j < N; j++)
    {
        if (checkqueen(board, row, j) == true)
        {
            board[row][j] = 1;
            tryqueen(board, row + 1);
            board[row][j] = 0;
        }
    }
    return true;
}
int main()
{
    freopen("input.inp","r",stdin);
    freopen("output.out", "w", stdout);
    tryqueen(board, 0);
    int T;
    cin>>T;
    while(T>0)
    {
        T--;
        int x,sum,min=0;
        vector<int>a;
        for(int i=0;i<64;i++)
        {
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<=soluong;i++)
        {
            sum=0;
            for(int j=0;j<64;j++)
                if(ans[i][j]==1)
                    sum+=a[j];
            if(sum>min)
                min=sum;
        }
        cout<<min<<endl;
    }
    //memset(board,0,sizeof(board));
    
}