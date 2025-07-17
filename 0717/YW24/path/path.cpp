#include<bits/stdc++.h>
#define rep(i, a, b) for(int (i) = (a);i <= (b);i ++)
#define lop(i, a, b) for(int (i) = (a);i <  (b);i ++)
#define rif(i, a, b, t) rep(i, a, b) if(!(t)) continue; else 
#define iif if
#define elf else if
#define els else
#define int32 int
#define int64 long long
#define def void
#define fn signed
#define i64 1ll
#define mod 998244353
#define inl inline
using namespace std;
int32 n, m;
int64 f[2000005];
inl int64 qpow(int64 a, int64 b) {
   if(b == 0) return 1;
   if(b == 1) return a;
   int64 bs = qpow(a, b >> 1);
   return bs * bs % mod * ((b&1)?a:1) % mod;
}
inl int64 div(int x) {return qpow(x, mod - 2);}
inl int64 C(int n, int m){return f[n] * div(f[m]) % mod * div(f[n - m]) % mod;}
inl int64 ways(int dx, int dy){return C(dx + dy, dy);}
int64 slv(int tx, int ty, int b) { 
   int nx = -b, ny = b;
   return (ways(tx, ty) - ways(tx - nx, ty - ny) + mod) % mod;
}
fn main() {
   freopen("path.in", "r", stdin);freopen("path.out", "w", stdout);
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
   cin >> n >> m;
   iif(m == 0) {cout << 1;return 0;}
   f[0] = 1; rep(i, 1, n + m) f[i] = f[i - 1] * i % mod;
   iif(m >  n) {cout << slv(m - 1, n, 2);}
   elf(m <  n) {cout << slv(n, m, 1);}
   els          cout << slv(n, m, 1) * 2 % mod << "\n";
   return 0;
}