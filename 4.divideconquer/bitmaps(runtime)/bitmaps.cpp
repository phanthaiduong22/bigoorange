#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
string b, s = "";
char s2[50000];
int Row, Col, index;
void BtoD(int x, int y, int r, int c)
{
    if (x >= Row || y >= Col || c == 0 || r == 0)
        return;
    int cnt0 = 0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (b[(x + i) * Col + (y +  j)] == '0')
                cnt0++; 
    if (cnt0 == r * c)
        s += '0';
    else if (cnt0 == 0)
        s += '1';
    else if (0 < cnt0 && 0 < r * c)
    {
        s += 'D';
        int sr = (r + 1) / 2;
        int sc = (c + 1) / 2;
        BtoD(x, y, sr, sc);
        BtoD(x, y + sc, sr, c - sc);
        BtoD(x + sr, y, r - sr, sc);
        BtoD(x + sr, y + sc, r - sr, c - sc);
        return;
    }
    return;
}
void fills(int x, int y, int r, int c, char value)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            s2[(x + i) * Col + (y + j)] = value;
}
void DtoB(int x, int y, int r, int c)
{   
    if (r == 0 || c == 0)
        return;
    if (b[index] == '0')
    {
        fills(x, y, r, c, '0');
        index++;
        return;
    }
    else if (b[index] == '1')
    {
        fills(x, y, r, c, '1');
        index++;
        return;
    }
    else
    {
        int sr = (r + 1) / 2;
        int sc = (c + 1) / 2;
        index++;
        DtoB(x, y, sr, sc);
        DtoB(x, y + sc, sr, c - sc);
        DtoB(x + sr, y, r - sr, sc);
        DtoB(x + sr, y + sc, r - sr, c - sc);
        return;
    }
}
int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    char kind;
    while (cin >> kind)
    {
        if (kind == '#')
            break;
        cin >> Row >> Col >> b;
        if (kind == 'B')
        {
            s = "";
            BtoD(0, 0, Row, Col);
            cout << "D"
                 << " " << Row << " " << Col << endl;
            cout << s << endl;
        }
        else
        {
            //s2.clear();
            index = 0;
            DtoB(0, 0, Row, Col);
            cout << "B"
                 << " " << Row << " " << Col << endl;
            for (int i = 0; i < Row; i++)
                for (int j = 0; j < Col; j++)
                    cout << s2[(i)*Col + (j)];
            cout << endl;
        }
    }
}