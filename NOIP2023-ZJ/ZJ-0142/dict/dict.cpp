#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define OPFI(x) freopen(#x".in", "r", stdin);\
                freopen(#x".out", "w", stdout)
#define REP(i, a, b) for(int i=(a); i<=(b); ++i)
#define REPd(i, a, b) for(int i=(a); i>=(b); --i)
inline ll rd(){
    ll r=0, k=1; char c=0; while(!isdigit(c=getchar())) if(c=='-') k=-k;
    while(isdigit(c)) r=r*10+c-'0', c=getchar(); return r*k;
}
const int N=3030;
ll n, m;
string mns[N], mxs[N], st[30][N];
int to[30][N];
string Min(int l, int r){
    int d=log2(r-l+1);
    return max(st[d][l], st[d][r-(1<<d)+1]);
}
int main(){
    OPFI(dict);
    n=rd(), m=rd();
    if(n==1){
        printf("1");
        return 0;
    }
    REP(i, 1, n){
        char str[N];
        scanf("%s", str);
        mns[i]=str, mxs[i]=str;
        sort(mns[i].begin(), mns[i].end());
        sort(mxs[i].begin(), mxs[i].end(), greater<char>());
        to[0][i]=i+1, st[0][i]=mxs[i];
    }
    REP(j, 1, 13) REP(i, 1, n)
        to[j][i]=to[j-1][to[j-1][i]], 
        st[j][i]=min(st[j-1][i], st[j-1][to[j-1][i]]);
    REP(i, 1, n){
        string minothers;
        if(i>1&&i<n) minothers=min(Min(1, i-1), Min(i+1, n));
        else if(i==1) minothers=Min(i+1, n);
        else minothers=Min(1, i-1);
        printf("%d", (mns[i]<minothers));
    }
    return 0;
}