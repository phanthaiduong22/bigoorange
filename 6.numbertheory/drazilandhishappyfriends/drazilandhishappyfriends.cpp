#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int b, g, boy_fun, girl_fun, x;
    vector<bool> state_b(200, false), state_g(200, false);
    cin >> b >> g;
    cin >> boy_fun;
    for (int i = 0; i < boy_fun; i++)
    {
        cin >> x;
        state_b[x] = true;
    }
    cin >> girl_fun;
    for (int i = 0; i < girl_fun; i++)
    {
        cin >> x;
        state_g[x] = true;
    }
    for (int i = 0; i <= 10005; i++)
    {
        if (state_b[i % b] == true && state_g[i % g] == false)
        {
            girl_fun++;
            state_g[i % g] = true;
        }
        else if (state_b[i % b] == false && state_g[i % g] == true)
        {
            boy_fun++;
            state_b[i % b] = true;
        }
    }
    if (boy_fun == b && girl_fun == g)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
}