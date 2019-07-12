#include <iostream>
#include <bitset>
#include <vector>
#include <string>
using namespace std;

int main()
{
    freopen("poweroftwo.inp", "r", stdin);
    freopen("poweroftwo.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        string ans = "NO";
        cin >> n;   
        vector<int> d[32];
        for (int j = 0; j < n; j++)
        {
            int x, temp;
            cin >> x;
            temp = x;
            int k = 0;
            while (temp)
            {
                if (temp & 1)
                {
                    d[k].push_back(x);
                }
                k++;
                temp = (temp >> 1);
            }
        }
        for (int p = 0; p < 32; p++)
        {
            if (!d[p].empty())
            {
                int sum = d[p][0];//co the de sum=11111111111...(2^32-1)
                for (int q = 1; q < d[p].size(); q++)
                {
                    sum = (sum & d[p][q]);
                }
                if (!(sum & (sum - 1)))
                {
                    ans = "YES";
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}