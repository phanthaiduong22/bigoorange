#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int V, E;

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &result)
{
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (!visited[v])
        {
            dfs(v, graph, visited, result);
        }
    }
    result.push_back(u);
}

void topologicalsort(vector<vector<int>> &graph, vector<int> &result)
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V;i++)
        if (!visited[i])
        {
            dfs(i, graph, visited, result);
        }
    reverse(result.begin(), result.end());
}
int main()
{
    freopen("topologicalsorting.inp", "r", stdin);
    freopen("topologicalsorting.out", "w", stdout);
    vector<vector<int>> graph;
    vector<int> result;
    cin >> V >> E;
    graph.assign(V+1, vector<int>());
    for (int u, v, i = 0; i < E; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    topologicalsort(graph, result);
    for (int i = 0; i < V; i++)
    {
        cout << result[i] << "  " << endl;
    }
    return 0;
}