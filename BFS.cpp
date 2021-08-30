#include <bits/stdc++.h>
#define ll long long
using namespace std;

void addedge(vector<int> graph[], int x, int y)
{
    graph[x].push_back(y);
}


void display(vector<int> graph[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "-->";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}
void bfs(vector<int> graph[], int s, int v)
{
    vector<bool> check(v, 0);
    queue<int> q;
    check[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        s = q.front();
        cout << s << " ";
        q.pop();
        for (auto it = graph[s].begin(); it != graph[s].end(); it++)
        {
            if (check[*it] == 0)
            {
                check[*it] == 1;
                q.push(*it);
            }
        }
    }
}
int main()
{
    int v;
    int e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<int> graph[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cout << "Enter the vertices x and y: ";
        cin >> x >> y;
        addedge(graph, x, y);
    }
    int s;
    cout<<"Enter source node: ";
    cin>>s;
    display(graph, v);
    bfs(graph,  s,  v);
}