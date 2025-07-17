#include<bits/stdc++.h>
#define rep(i, a, b) for(int (i) = (a);i <= (b);i ++)
#define lop(i, a, b) for(int (i) = (a);i <  (b);i ++)
#define dwn(i, a, b) for(int (i) = (a);i >= (b);i --)
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
#define low(x) ((x) & -(x))
using namespace std;
#define N 300005
int a[N], n, b[N], tr[N << 1], t2[N << 1];
def add(int x, int v, int *tr) {
   while(x <= n)   tr[x] += v, x += low(x);}
int qry(int x, int *tr) { int sum = 0;
   while(x) sum += tr[x], x -= low(x); return sum;}
int64 p[N], q[N], ans;
fn main() {
   freopen("seq.in", "r", stdin);freopen("seq.out", "w", stdout);
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   cin >> n;   rep(i, 1, n) cin >> a[i], b[i] = a[i];
   sort(b + 1, b + 1 + n); int tn = unique(b + 1, b + 1 + n) - b - 1;
   rep(i, 1, n) a[i] = lower_bound(b + 1, b + 1 + tn, a[i]) - b;
   rep(i, 1, n) add(a[i], 1, t2);
   rep(i, 1, n) 
      add(a[i],-1, t2),   ans += min(i - 1 - qry(a[i], tr), n - i - qry(a[i], t2)),add(a[i], 1, tr);
   cout << ans << "\n";
}
/*
6
2
8
4
5
3
6
*/