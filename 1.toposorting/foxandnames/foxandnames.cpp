#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
using namespace std;
bool topologicalsort(vector<vector<int>> &graph, vector<int> &result)
{
    vector<int> indegree(26, 0);
    queue<int> zero_indegree;
    for (int u = 0; u < 26; u++)
    {
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]++;
        }
    }
    for (int i = 0; i < 26; i++)
        if (indegree[i] == 0)
            zero_indegree.push(i);
    while (!zero_indegree.empty())
    {
        int u = zero_indegree.front();
        zero_indegree.pop();
        result.push_back(u);
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
            {
                zero_indegree.push(*it);
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (indegree[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    freopen("foxandnames.inp", "r", stdin);
    freopen("foxandnames.out", "w", stdout);
    vector<vector<int>> graph;
    vector<int> result;
    string s, s1;
    vector<string> check;
    int n;
    cin >> n;
    graph.assign(26, vector<int>());
    cin >> s;
    check.push_back(s);
    for (int i = 1; i < n; i++)
    {

        cin >> s1;
        check.push_back(s1);
        int j = 0;
        while ((j < min(s.length(), s1.length())) && (s[j] == s1[j]))
        {
            j++;
        }
        if (j != s.length() && j != s1.length())
            graph[s[j] - 97].push_back(s1[j] - 97);
        s = s1;
    }
    if (topologicalsort(graph, result) == false)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        bool check_alphabet = true;
        for (int i = 1; i < n; i++)
        {
            int j = 0;
            string temp = check[i];
            string temp1 = check[i - 1];
            int minn = min(temp.length(), temp1.length());
            while (j < minn && (temp[j] == temp1[j]))
                j++;
            if (j < minn)
            {
                check_alphabet = true;
            }
            else if (temp1.length() > temp.length())
            {
                check_alphabet = false;
                break;
            }
        }
        if (check_alphabet == true)
            for (int i = 0; i < 26; i++)
                cout << char(result[i] + 97);
        else
        {
            cout << "Impossible" << endl;
        }
    }
}