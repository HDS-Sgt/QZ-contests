#include<bits/stdc++.h>
#define xx first
#define yy second
#define vtr(n) int a[n];vector<int>g[n];void adde(int x, int y){g[x].push_back(y);}
#define edg(m) pair<int, int> p[m];
#define ato(x, y) for(auto x : y)
#define debug(x) cerr << #x << ": " << x << '\n';
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define lop(i, a, b) for (int i = (a); i < (b); i++)
#define dwn(i, a, b) for (int i = (a); i >= (b); i--)
#define elif else if
#define iosfst ios::sync_with_stdio(0);cin.tie(0), cout.tie(0)
#define el '\n'
#define pb push_back
#define MAIN signed main()
#define _if (
#define _then ?(
#define _els ):
#define _end )
#define ret return 
#define ctd(T) while(T--)
using namespace std;
#define int long long
int n, m;
int vis[205], u[205], v[205], ans, dfn[205], low[205], top, sm, ins[205];
vector<int>g[205];
bool bl[3005];
stack<int> st;
bool tarjan(int u) {
    vis[u] = 1;
    bool ans = 0;
    st.push(u);
    ins[u] = 1;
    dfn[u] = ++ top;
    low[u] = dfn[u];
    for(auto v : g[u])
        if(!vis[v])
            ans |= tarjan(v), low[u] = min(low[u], low[v]);
        else if(ins[v])low[u] = min(low[u], dfn[v]);
    if(low[u] == dfn[u]) {
		int sz = 1;
		while(st.top() != u) ins[st.top()] = 0,st.pop(), sz ++;  
		st.pop(); 
		ins[u] = 0;	
        if(sz > 1)
			return 1;
    }
    return ans;
    
}
bool chk() {
	top = 0;
	memset(dfn, 0, sizeof dfn); 
    memset(vis, 0, sizeof vis);
    memset(low, 0x3f, sizeof low);
    int ans = 0;
    //rep(i, 1, m)
    //	cerr << bl[i] << " ";
    rep(i, 1, n)
        if(!vis[i])
            ans |= tarjan(i);
    //cerr << ans << "\n";
    return ans;
}
void dfs(int p, int sum) {
    if(p == m + 1) {
        if(!chk()) ans += sum, ++sm;
        return;
    }
    g[u[p]].pb(v[p]);
    dfs(p + 1, sum);
    g[u[p]].pop_back();
    g[v[p]].pb(u[p]);
    bl[p] = 1;
    dfs(p + 1, sum + 1);
    g[v[p]].pop_back();
    bl[p] = 0;
}
signed main() {
    freopen("scc.in", "r", stdin);
    freopen("scc.out", "w", stdout);
    cin >>n >> m;
    rep(i, 1, m) cin >> u[i] >> v[i];
    dfs(1, 0);
    cout << ans << "\n";
}
