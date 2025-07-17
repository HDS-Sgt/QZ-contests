//赝品做法
#include<bits/stdc++.h>
#define rep(i, a, b) for(int (i) = (a);i <= (b);i ++)
#define lop(i, a, b) for(int (i) = (a);i <  (b);i ++)
#define dwn(i, a, b) for(int (i) = (a);i >= (b);i --)
#define rif(i, a, b, t) rep(i, a, b) if(!(t)) continue; else 
#define iif if
#define elf else if
#define els else
#define int long long
#define pii pair<int, int>
#define int32 int
#define int64 long long
#define def void
#define fn signed
#define i64 1ll
#define inl inline
#define low(x) ((x) & -(x))
#define N 100005
using namespace std;
int n, p[N], c[N];
vector<pii >in[N];

int vis[N], inc[N], now, ans;
int top = 0;vector<int>cir[N];
int findC(int u) {
   if(vis[u] == now) return cir[++ top].push_back(u), u;
   if(vis[u]) return 0;
   vis[u] = now;int back = findC(p[u]);
   if(back && back != u) return cir[top].push_back(u), back;
   return 0;
}

fn main() {
   freopen("graph.in", "r", stdin);freopen("graph.out", "w", stdout);
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
   cin >> n;
   rep(i, 1, n) cin >> p[i] >> c[i], in[p[i]].push_back({c[i], i});
   rep(i, 1, n) if(!vis[i]) now = i, findC(i);
   rep(i, 1, n) sort(in[i].begin(), in[i].end());
   int res = 0;
   rep(i, 1, n)
      for(auto p : in[i])
         res += p.first;
   rep(i, 1, n) 
      if(in[i].size())
         res -= in[i].back().first;
   if(top == 1 && cir[top].size() == n) {
      cout << 0;
      return 0;
   }
   rep(i, 1, top) {
      int bu = 0, bw = 0x3f3f3f3f3f3f3f3f;
      for(auto u : cir[i]) {
         int w = c[u];
         if(in[p[u]].size() > 1)
            if(in[p[u]][in[p[u]].size() - 1].first == w) 
            	w -= in[p[u]][in[p[u]].size() - 2].first;
            else w = 0;
         //else w = 0;
         if(w < bw)
            bu = u, bw = w;
      }
      res += bw;
   }
   cout << res <<"\n";
}
