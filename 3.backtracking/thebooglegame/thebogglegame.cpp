#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

bool visiteda[4][4];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
string a[4][4];
string b[4][4];
set<string>ans1;
map<string, int>
    word;
int sum = 0;
bool checkvowel(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'U' || s[i] == 'E' || s[i] == 'O' || s[i] == 'A' || s[i] == 'I' || s[i] == 'Y')
            ans++;
    if (ans == 2)
        return true;
    return false;
}
void makeset()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            visiteda[i][j] = false;
    }
    word.clear();
    ans1.clear();
    sum = 0;
}
void input()
{
    for (int i = 1; i < 4; i++)
        cin >> a[0][i];
    for (int i = 0; i < 4; i++)
        cin >> b[0][i];
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> a[i][j];
        for (int j = 0; j < 4; j++)
            cin >> b[i][j];
    }
}
void trya(string s, int n, int i, int j, string c[4][4], int dothing)
{
    if (n == 4)
    {
        if (dothing == 0)
        {
            if (checkvowel(s))
            {
                word[s]++;
                //cout << s << endl;
            }
            return;
        }
        else if (dothing==1)
        {
            if (word[s] > 0)
            {
                sum++;
                ans1.insert(s);
                word[s] = 0;
            }
            return;
        }
    }
    for (int k = 0; k < 8; k++)
    {
        if ((i + dx[k] >= 0) && (i + dx[k] <= 3) && (j + dy[k] >= 0) && (j + dy[k] <= 3))
            if (visiteda[i + dx[k]][j + dy[k]] == false)
            {
                visiteda[i + dx[k]][j + dy[k]] = true;
                s += c[i + dx[k]][j + dy[k]];
                trya(s, n + 1, i + dx[k], j + dy[k], c, dothing);
                s.pop_back();
                visiteda[i + dx[k]][j + dy[k]] = false;
            }
    }
}
int main()
{
    freopen("thebogglegame.inp", "r", stdin);
    freopen("thebogglegame.out", "w", stdout);
    while (cin >> a[0][0])
    {
        if (a[0][0] == "#")
            break;
        else
        {
            input();
            makeset();
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    trya(a[i][j], 1, i, j, a, 0);
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    trya(b[i][j], 1, i, j, b, 1);
            if (sum == 0)
            {
                cout << "There are no common words for this pair of boggle boards." << endl;
            }
            else
            {
                set<string>::iterator it;
                for (it = ans1.begin(); it != ans1.end(); it++)
                    cout << *it << endl;
            }
            cout << endl;
        }
    }
}