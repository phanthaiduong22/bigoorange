#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int V, E;
struct option
{
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};

bool topologicalsort(vector<vector<int>> &graph, vector<int> &result)
{
    vector<int> indegree(V+1, 0);
    priority_queue<int, vector<int>, option> zero_indegree;
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
        int u = zero_indegree.top();
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
    freopen("topologicalkahn.inp", "r", stdin);
    freopen("topologicalkahn.out", "w", stdout);
    vector<vector<int>> graph;
    vector<int> result;

    cin >> V >> E;
    graph.assign(V + 1, vector<int>());
    for (int u, v, i = 0; i < E; i++)
    {
        cin >> u >> v;
        graph[u-1].push_back(v-1);
    }
    if (topologicalsort(graph, result) == true)
    {
        for (int i = 0; i < result.size(); i++)
            cout << result[i]+1 << " ";
    }
    else
        cout << "Sandro fails.";
}