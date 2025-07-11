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
int n, a[100], b[100], m;
struct act{
    int st, t;
    bool operator<(act b){return t < b.t;}
}st[500005], st2[500005], st3[500005][3];
int stime, mns = 0, ast, ans = 0x3f3f3f3f3f3f3f3f, cnt;
map<int ,int>mp, mp2;

int f[2000005];
void solve_luangao() {
    sort(st + 1, st + 1 + m);
    rep(i, 1, n)
        if(a[i] - b[i] < b[i])
            ast |= (1 << (i - 1)),
            mns += a[i] - b[i];
        else mns += b[i];
    rep(i, 1, m)
        if(st[i].t <= ans)
            cnt ++, 
            st2[cnt] = st[i];
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    int ans = 0x3f3f3f3f3f3f3f3f, mt = 0x3f3f3f3f3f3f3f3f;
    rep(i, 1, cnt)
        if(st[i].t < f[st[i].st])
        rep(j, 0, (1 << n) - 1)
            f[j] = min(f[j], f[j ^ st2[i].st] + st2[i].t);
    rep(i, 0, (1 << n) - 1) {
        int res = 0;
        rep(j, 1, n)
            if(i & (1 << (j - 1)))
                res += a[j] - b[j];
            else
                res += b[j];
        if(res < ans && f[i] != 0x3f3f3f3f3f3f3f3f) ans = res, mt = f[i];
        else if(res == ans) mt = min(mt, f[i]);
    }
    cout << ans << " " << mt << "\n";
            //mp2[st[i].st] ? (mp2[st[i].st] = min(st[i].t, mp2[st[i].st])) : (mp2[st[i].st] = st[i].t);
    //cerr << cnt;
    // cout << mns << " " << ans;
    // int flg = 0, tcnt = cnt;
    // while(cnt <= 50000 && (clock() * 1.0 - stime ) / CLOCKS_PER_SEC <= 0.90) {
    //     //flg = flg % 2 + 1;
    //     int cnt2 = 0;
    //     rep(i, 1, cnt)
    //         rep(j, 1, tcnt)
    //             if(st3[i][flg].t + st3[j][0].t <= ans)
    //                 st3[++ cnt2][flg % 2 + 1].t = st3[i][flg].t + st3[j][0].t,
    //                 st3[cnt2][flg % 2 + 1].st = (st3[i][flg].st ^ st3[j][0].st);
    //     rep(i, 1, cnt2)
    //         if(mp2[st3[i][flg % 2 + 1].st ^ ast])
    //             ans = min(ans, st3[i][flg % 2 + 1].t + mp2[st3[i][flg % 2 + 1].st ^ ast]);
    //     cnt = cnt2;
    //     flg = flg % 2 + 1;
    // }
    // cout << mns << " " << ans << "\n";
}
void solve_dp() {
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    int ans = 0x3f3f3f3f3f3f3f3f, mt = 0x3f3f3f3f3f3f3f3f;
    rep(i, 1, m)
        rep(j, 0, (1 << n) - 1)
            f[j] = min(f[j], f[j ^ st[i].st] + st[i].t);
    rep(i, 0, (1 << n) - 1) {
        int res = 0;
        rep(j, 1, n)
            if(i & (1 << (j - 1)))
                res += a[j] - b[j];
            else
                res += b[j];
        if(res < ans && f[i] != 0x3f3f3f3f3f3f3f3f) ans = res, mt = f[i];
        else if(res == ans) mt = min(mt, f[i]);
    }
    cout << ans << " " << mt << "\n";
}


signed main() {
    freopen("judger.in", "r", stdin);
    freopen("judger.out", "w", stdout);
    iosfst;
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    rep(i, 1, m) {
        string s;
        cin >> s;
        while(s.size())
            st[i].st = ((st[i].st << 1) | (s.back() - '0')),
            s.pop_back();
        //cout << st[i].st << "\n";
        cin >> st[i].t, mp[st[i].st] ? (mp[st[i].st] = min(st[i].t, mp[st[i].st])) : (mp[st[i].st] = st[i].t);
    }
    if(n <= 12 && m <= 3000) {
        solve_dp();
    }
    else 
        solve_luangao();
}