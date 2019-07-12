#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <queue>

using namespace std;
struct option
{
    bool operator()(const int &a,const int &b)const{
        return a>b;
    }
};
bool topologicalsort(vector<vector<int>> &graph, vector<int> &result, int n)
{
    vector<int> indegree(n);
    priority_queue<int,vector<int>,option> zero_indegree;
    for (int u = 0; u < n; u++)
    {
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
            indegree[*it]++;
    }
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            zero_indegree.push(i);
    while (!zero_indegree.empty())
    {
        int u = zero_indegree.top();
        result.push_back(u);
        zero_indegree.pop();
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
                zero_indegree.push(*it);
        }
    }
    for (int i = 0; i < n; i++)
        if (indegree[i] != 0)
            return false;
    return true;
}
int main()
{
    freopen("beverages.inp", "r", stdin);
    freopen("beverages.out", "w", stdout);
    int n, T = 0;
    while (cin >> n)
    {
        T++;
        int m;
        vector<vector<int>> graph;
        vector<int> result;
        graph.assign(n, vector<int>());
        map<string, int> name;
        map<int, string> number;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            name[s] = i;
            number[i] = s;
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            graph[name[s1]].push_back(name[s2]);
        }
        topologicalsort(graph, result, n);
        cout << "Case #" << T << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < result.size(); i++)
            cout << " " << number[result[i]];
        cout << "." << endl;
        cout<<endl;
    }
}