#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int V, E;
int nextt[100000];
bool topologicalsort(vector<vector<int>> &graph, vector<int> &result)
{

    vector<int> indegree(V + 1, 0);
    queue<int> zero_indegree;
    for (int u = 0; u < V; u++)
    {
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
            indegree[*it]++;
    }
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
        {
            zero_indegree.push(i);
        }
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
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    freopen("hierarchy.inp", "r", stdin);
    freopen("hierarchy.out", "w", stdout);
    vector<vector<int>> graph;
    vector<int> result;

    cin >> V >> E;
    graph.assign(V + 1, vector<int>());
    for (int u, v, i = 0; i < E; i++)
    {
        int T;
        cin >> T;
        for (int j = 0; j < T; j++)
        {
            cin >> v;
            nextt[v - 1] = i;
            graph[i].push_back(v - 1);
        }
    }
    vector<int> ans(V + 1);
    topologicalsort(graph, result);
    for (int i = 0; i < V; i++)
    {
        if (i == 0)
            ans[result[i]] = 0;
        else
        {
            ans[result[i]] = result[i - 1]+1;
        }
    }
    for (int i = 0; i < V; i++)
        cout << ans[i] << endl;
}