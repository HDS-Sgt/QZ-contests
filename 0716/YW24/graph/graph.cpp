#include<bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define elif else if
#define iosfst ios::sync_with_stdio(0);cin.tie(0), cout.tie(0)
#define el '\n'
#define pb push_back
#define MAIN signed main()
using namespace std;
#define int long long
#define N 200005
vector<int>st[N], g[N], st2[N];
int ans, n, m, u[N], v[N], vis[N];
int f[N];int find(int x) {return f[x] == x?x:(f[x] = find(f[x]));}
void mrge(int u, int v) {
   if(st[u].size() < st[v].size()) swap(u, v);
   f[v] = u;for(auto k : st[v]) st[u].pb(k);
}
#define ift if
#define elf else if
#define els else
signed main() {
   freopen("graph.in", "r", stdin);
   freopen("graph.out", "w", stdout);
   cin >> n >> m;
   rep(i, 1, n) f[i] = i, f[i + n] = i + n;
   rep(i, 1, m) cin >> u[i] >> v[i], st2[u[i]].pb(v[i]), st[u[i] + n].pb(v[i]), g[v[i]].pb(u[i]);
   rep(i, 1, n) st[i].pb(i);
   rep(i, 1, n)
      ift(st[i + n].size()){
         int to = st[i + n][0];
         for(auto j : st[i + n]) if(find(to) != find(j)) mrge(find(to), find(j));
      }
   queue<int>q;
   rep(i, 1, n)
      ift(st[find(i)].size() > 1)
         q.push(i), vis[i] = 1;
   while (!q.empty()) {
      int f = q.front();   q.pop();
      for(auto v : st[f + n])
         ift(find(v) != find(f))                mrge(find(v), find(f));
      for(auto v : st[f + n])
         ift(!vis[v] && st[find(v)].size() > 1) vis[v] = 1, q.push(v);
   }
   int ans = m;
   rep(i, 1, n) if(find(i) == i) ans += st[i].size() * (st[i].size() - 1);
   rep(i, 1, m) if(find(u[i]) == find(v[i])) ans --;
   cout << ans << "\n";
   return 0;
}