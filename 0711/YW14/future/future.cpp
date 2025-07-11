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
#define _if (
#define _then ?(
#define _els ):
#define _end )
#define ret return 
#define ctd(T) while(T--)
using namespace std;
#define int long long
int a[5005], n, dp[5005][5005], rt;
namespace dick_cut_tree{
    stack<int>st;
    int lc[5005], rc[5005], sz[5005];
    void build() {
        st.push(1);
        sz[1] = 1;
        rep(i, 2, n) {
            sz[i] = 1;
            while(!st.empty() && a[st.top()] < a[i]) {
                int tp = st.top();
                st.pop();
                if(!st.empty() && a[st.top()] < a[i])
                    rc[st.top()] = tp, sz[st.top()] += sz[tp];
                else lc[i] = tp, sz[i] += sz[tp];
            }
            st.push(i);
        }
        while(!st.empty()) {
            int tp = st.top();
            st.pop();
            if(!st.empty())
                rc[st.top()] = tp, sz[st.top()] += sz[tp];
            else rt = tp;
        }
    }
    void dfs(int u) {
        //cout << u << "\n";
        if(!u) return ;
        dp[u][0] = 0;
        dfs(lc[u]);dfs(rc[u]);
        rep(k, 1, sz[u]){
            rep(ll, max(0ll, k - sz[rc[u]]), min(sz[lc[u]], k)){
                dp[u][k] = min({
                    dp[u][k], 
                    dp[lc[u]][ll] 
                    + dp[rc[u]][k - ll] 
                    + ll * (k - ll) * a[u]});
            }
            rep(ll, max(0ll, k - sz[rc[u]] - 1), min(sz[lc[u]], k - 1)){
                dp[u][k] = min({
                    dp[u][k], 
                    dp[lc[u]][ll] 
                    + dp[rc[u]][k - 1 - ll] 
                    + (ll * (k - 1 - ll) + k) * a[u]});
            }
        }
    }
}
signed main() {
    freopen("future.in", "r", stdin);
    freopen("future.out", "w", stdout);
    iosfst;
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    dp[0][0] = 0;
    rep(i, 1, n) cin >> a[i];
    dick_cut_tree::build();
    dick_cut_tree::dfs(rt);
    rep(i, 1, n)
        cout << dp[rt][i] << "\n";
}
