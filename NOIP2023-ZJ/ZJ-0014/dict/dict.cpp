#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define pii pair<int,int>
inline int read(void) {
    int sgn=1,x=0; char c=getchar();
    while(c< '0'||'9'< c) { c=='-' && (sgn=0); c=getchar(); }
    while('0'<=c&&c<='9') { x=x*10+c-'0'; c=getchar(); }
    return sgn ? x : -x;
}
void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar('0'+x%10);
}
int n,m;
char s[3003][3003];
int mi[3003],mx[3003],ck[3003];
signed main() {
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    n=read(); m=read();
    for(int i=1; i<=n; ++i) {
        scanf("%s",s[i]+1); mi[i]=128;
        for(int u=1; u<=m; ++u) mx[i]=max(mx[i],(int)s[i][u]);
        for(int u=1; u<=m; ++u) mi[i]=min(mi[i],(int)s[i][u]);
    }
    for(int i=1; i<=n; ++i) {
        bool f=1;
        for(int u=1; u<=n; ++u) if(u!=i) {
            f&=(mi[i]<mx[u]);
        }
        write(f);
    }
    puts("");
    return 0;
}