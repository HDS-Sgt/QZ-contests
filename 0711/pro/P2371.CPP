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
int n, l, r, m;
int f[500005], a[500005], b[500005];
signed main() {
    iosfst;
    cin >> n >> l >> r;
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    rep(i, 1, n) {
        cin >> a[i];
        if(a[i] == 0) i--, n--;
    }
    if(n == 0) {cout << 0; ret 0;}
    sort(a + 1, a + n + 1);
    m = a[1];
    rep(i, 1, n) {
        b[i] = a[i] % m;
        rep(j, 0, __gcd(a[i], m) - 1) {
            int k = (j + b[i]) % m;
            while(k != j) {
                f[k] = min(f[k], f[(k - b[i] + m) % m] + a[i]);
                k = (k + b[i]) % m;
            }
            f[k] = min(f[k], f[(k - b[i] + m) % m] + a[i]);
            k = (j + b[i]) % m;
            while(k != j) {
                f[k] = min(f[k], f[(k - b[i] + m) % m] + a[i]);
                k = (k + b[i]) % m;
            }
        }//每次在环上转移，走两次一定是对的 
    }
    int ans = 0;
    lop(i, 0, a[1]) {
        if(r >=  f[i]) 
            ans += (r - f[i]) / a[1] + 1;
        if(l > f[i])
            ans -= (l - 1 - f[i]) / a[1] + 1;
        // ansr - ans(l - 1) 相当于差分求答案
    }
    cout << ans << "\n";
    return 0;
}