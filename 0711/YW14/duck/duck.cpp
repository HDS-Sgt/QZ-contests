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
#define mod 998244353
#define int long long
inline int qpow(int x, int y) {
	if(y == 0) return 1;
	if(y == 1) return x % mod;
	int m = qpow(x, y >> 1);
	return m * m % mod * (y & 1 ? x : 1) % mod;
}
signed main() {
    freopen("duck.in", "r", stdin);
    freopen("duck.out", "w", stdout);
    iosfst;
    int n;
    cin >> n;
    cout << qpow(qpow(2, n - 1), mod - 2) * n % mod << "\n";
}
