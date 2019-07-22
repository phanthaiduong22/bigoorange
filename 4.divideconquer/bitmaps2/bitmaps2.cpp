#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int row, col;
string code, ans;
char ans2[500000];
void BtoD(int x, int y, int r, int c)
{
    int cnt0 = 0;
    int k = 0;
    for (int i = x; i < r; i++)
        for (int j = y; j < c; j++)
        {
            k++;
            if (code[i * col + j] == '0')
                cnt0++;
        }
    if (cnt0 == (r - x) * (c - y) || (cnt0 == 1 && k == 1))
    {
        ans += '0';
    }
    else if (cnt0 == 0)
    {
        ans += '1';
    }
    else
    {
        ans += 'D';
        int sr = (r - x + 1) / 2;
        int sc = (c - y + 1) / 2;
        BtoD(x, y, x + sr, y + sc);
        if (y + sc < c)
            BtoD(x, y + sc, x + sr, c);
        if (x + sr < r)
            BtoD(x + sr, y, r, y + sc);
        if (x + sr < r && y + sc < c)
            BtoD(x + sr, y + sc, r, c);
        return;
    }
    return;
}
void fill(int x, int y, int r, int c, char value)
{
    for (int i = x; i < r; i++)
        for (int j = y; j < c; j++)
        {
            ans2[i * col + j] = value;
        }
}
void DtoB(int x, int y, int r, int c)
{
    char index;
    cin >> index;
    if (index == '1')
    {
        fill(x, y, r, c, '1');
        //index++;
        return;
    }
    else if (index == '0')
    {
        fill(x, y, r, c, '0');
        //index++;
        return;
    }
    else
    {
        //index++;
        int sr = (r - x + 1) / 2;
        int sc = (c - y + 1) / 2;
        DtoB(x, y, x + sr, y + sc);
        if (y + sc < c)
            DtoB(x, y + sc, x + sr, c);
        if (x + sr < r)
            DtoB(x + sr, y, r, y + sc);
        if (x + sr < r && y + sc < c)
            DtoB(x + sr, y + sc, r, c);
        return;
    }
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    char kind;
    cin >> kind;
    while (1)
    {
        char temp;
        code = "";
        if (kind == '#')
            break;
        cin >> row >> col;
        if (kind == 'B')
        {
            while (1)
            {
                cin >> temp;
                if (temp == 'B' || temp == 'D' || temp == '#')
                    break;
                code += temp;
            }
            ans = "";
            BtoD(0, 0, row, col);
            cout << "D " << row << " " << col << endl;
            int k = 0;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i];
                if ((i + 1) % 50 == 0 || i == (int)ans.size() - 1)
                {
                    cout << endl;
                }
            }
            //cout << endl;
        }
        else
        {
            //index = 0;
            DtoB(0, 0, row, col);
            ans = "";
            cout << "B " << row << " " << col << endl;
            int k = 0;
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                {
                    ans += ans2[i * col + j];
                }
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i];
                if ((i + 1) % 50 == 0 || i == (int)ans.size() - 1)
                {
                    cout << endl;
                }
            }
            //cout << endl;
            cin >> temp;
        }
        kind = temp;
    }
}