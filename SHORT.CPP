#include <bits/stdc++.h>
#define ll long long
using namespace std;

void addedge(vector<int> graph[], int x, int y)
{
    graph[x].push_back(y);
    graph[y].push_back(x);
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
int bfsmodified(vector<int> graph[], int s, int v,int t,vector<int>&pred,vector<int> &dist)
{
    vector<bool> check(v, 0);
    queue<int> q;
    check[s] = 1;
    dist[s] = 0; 
    q.push(s);
    while (!q.empty())
    {
        s = q.front();
        q.pop();
        for (auto it = graph[s].begin(); it != graph[s].end(); it++)
        {
            if (check[*it] == 0)
            {
                check[*it] == 1;
                dist[*it] = dist[s] + 1;
                pred[*it]=s;
                q.push(*it);

                if (*it == t)
                    return 1;
            }
        }
    }
    return 0;
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
    int s,t;
    vector<int> pred(v,-1);
    vector<int> dist(v,-1);
    cout<<"Enter source node: ";
    cin>>s;
     cout<<"Enter target node: ";
    cin>>t;
    display(graph, v);
    int res=bfsmodified(graph,s,v,t,pred,dist);
    if(res==1)
        cout<<dist[t];
    else
    cout<<"not connected"; 
}