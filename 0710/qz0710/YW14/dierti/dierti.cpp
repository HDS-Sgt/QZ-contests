#include<bits/extc++.h>
#define xx first
#define yy second
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
int n, m;
#define N 3005
vector<int> g[N];
int dp[N][N][3], ans;
bool vis[N][N][3];
signed main() {
    freopen("dierti.in", "r", stdin);
    freopen("dierti.out", "w", stdout);
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    queue<pair<pair<int, int>, int > > q;
    rep(i, 1, n)
        dp[i][i][0] = 1, q.push({{i, i}, 0}),
        vis[i][i][0] = 1;
    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        if(u.yy == 0) ans ++;
        if(u.yy == 0) {
            for(auto v : g[u.xx.xx])
                if(!vis[v][u.xx.yy][1])
                    vis[v][u.xx.yy][1] = 1,
                    q.push({{v, u.xx.yy}, 1});
        }
        else {
            for(auto v : g[u.xx.yy])
                if(!vis[u.xx.xx][v][(u.yy + 1) % 3])
                    vis[u.xx.xx][v][(u.yy + 1) % 3] = 1,
                    q.push({{u.xx.xx, v}, (u.yy + 1) % 3});
        }
    }
    cout << ans << "\n";
    ret 0;
}
