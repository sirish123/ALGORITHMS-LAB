#include <bits/stdc++.h>
#define ll long long
using namespace std;

int find(vector<pair<ll, ll>> s, ll n)
{
    if (s[n].first == n)
        return s[n].first;
    else
        return find(s, s[n].first);
}
void setunion(vector<pair<ll, ll>> s, ll a, ll b)
{
    ll ax = find(s, a);
    ll bx = find(s, b);
    if (s[ax].second < s[bx].second)
        s[ax].first = bx;
    else if (s[ax].second > s[bx].second)
        s[ax].first = bx;
    else
    {
        s[bx].first = ax;
        s[ax].second++;
    }
}

int main()
{
    ll e, v;
    cout << " Enter the number of vertices: ";
    cin >> v;
    cout << " Enter the number of edges: ";
    cin >> e;
    vector<vector<ll>> krux(e);
    vector<pair<ll, ll>> s(v);
    for (int i = 0; i < e; i++)
    {
        cout << " ENTER W,V,U: ";
        ll u, v, w;
        cin >> w >> v >> u;
        krux[i].push_back(w);
        krux[i].push_back(v);
        krux[i].push_back(u);
    }
    sort(krux.begin(), krux.end());
    for (ll i = 0; i < v; i++)
    {
        s[i].first = i;
        s[i].second = 0;
    }
    ll cost = 0;
    for (ll i = 0; i < e; i++)
    {
        ll a = krux[i][1];
        ll b = krux[i][2];
        if (find(s, a) != find(s, b))
        {
            setunion(s, a, b);
            cost = cost + krux[i][0];
        }
    }
    cout << cost << "\n";
}