#include<bits/stdc++.h>
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
#define int long long
int n, m, ans = 0;
pair<int, int>p[300005];
signed main() {
    freopen("mst.in", "r", stdin);
    freopen("mst.out", "w", stdout);
    iosfst;
    cin >> n >> m;
    rep(i, 1, m)
        cin >> p[i].second >> p[i].first;
    sort(p + 1, p + 1 + m);
    rep(i, 1, m) {
        int g = __gcd(p[i].second, n);
        ans += (n - g) * p[i].first;
        n = g;
    }
    if(n == 1)
        cout << ans << "\n";
    else
        cout << -1 << "\n";
    ret 0;
}
