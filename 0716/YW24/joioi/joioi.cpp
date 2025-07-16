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
#define ift if
#define elf else if
#define els else
using namespace std;
string s;   int n, ans;
signed main() {
   freopen("joioi.in", "r", stdin);
   freopen("joioi.out", "w", stdout);
   cin >> n >> s; s = " " + s;
   int ci = 0, coi = 0, cij = 0;
   rep(i, 1, n)
      if(s[i] != 'O') cij ++;
   dwn(i, n, 1) {
      ift(s[i] == 'J' && coi) ans ++, coi --;
      elf(s[i] == 'O' && ci)  coi ++, ci --;
      ift(s[i] != 'O')        cij --;
      ift(s[i] == 'I')
         ift(coi + ci > cij && coi)   coi --, ans ++;
         els                          ci ++;
      //debug(cij);debug(coi);debug(co);
      // if(coi)
      //    ans += coi,
      //    cij -= coi, coi = 0, co = min(co, cij);
   }
   cout << ans;
   return 0;
}
/*
6 JJOOII
6 JOIOII
6 JOIIOI
7 OJOOJII
*/