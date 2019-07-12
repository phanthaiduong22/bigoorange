//bac cua mot thang phu thuoc vao nhung thang cao hon no
//sap xep trong do thi->topo

#include <iostream>
#include <algorithm>
#include <queue>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
using namespace std;
struct option
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};
bool topological(vector<vector<int>> &graph, vector<pair<int, int>> &result, int V)
{
    int same_rank = 0;
    int rank = 1;
    vector<int> indegree(V);
    queue<int> zero_indegree;
    for (int u = 0; u < V; u++)
    {
        vector<int>::iterator it;
        for (it = graph[u].begin(); it != graph[u].end(); it++)
        {
            indegree[*it]++;
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            zero_indegree.push(i);
            same_rank++;
        }
    }
    while (!zero_indegree.empty())
    {

        if (same_rank == 0)
        {
            rank++;
            same_rank = zero_indegree.size();
        }
        int u = zero_indegree.front();
        zero_indegree.pop();

        result.push_back({rank, u});
        same_rank--;
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
    return true;
}
int main()
{
    freopen("answertheboss.inp", "r", stdin);
    freopen("answertheboss.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cout << "Scenario #" << i+1 << ":" << endl;
        vector<vector<int>> graph;
        vector<pair<int, int>> result;
        int V, E;   
        cin >> V >> E;
        graph.assign(V, vector<int>());
        for (int i = 0; i < E; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[y].push_back(x);
        }
        topological(graph, result, V);
        sort(result.begin(), result.end(), option()); 
        for (int i = 0; i < result.size(); i++)
            cout << result[i].first << " " << result[i].second << endl;
    }
}


