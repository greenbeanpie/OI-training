#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int gin() {
    int s=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9') {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        s=(s<<3)+(s<<1)+(c^48);
        c=getchar();
    }
    return s*f;
}

int n,m,k;
long long d;
int x[1055],y[1005];
long long v[1005];

bool chk(int ww) {
    for(int i=k;i<n;i++) {
        bool op=0;
        for(int j=i-k;j<=i;j++) {
            if(ww&(1<<j)) continue;
            else {op=1; break;}
        }
        if(op==0) return 1;
    }
    return 0;
}

signed main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int C=gin(),T=gin();
    while(T--) {
        long long ans=0;
        n=gin(),m=gin(),k=gin(),d=gin();
        for(int i=1;i<=m;i++) x[i]=gin(),y[i]=gin(),v[i]=gin();
        for(int i=0;i<262144;i++) {
            if(chk(i)) continue;
            // printf("%lld\n",i);
            long long w=0;
            for(int j=0;j<n;j++) {
                if(i&(1<<j)) w-=d;
            }
            // printf("%lld\n",w);
            for(int j=1;j<=m;j++) {
                bool op=0;
                for(int t=x[j]-y[j]+1;t<=x[j];t++) {
                    if(i&(1<<(t-1))) continue;
                    else {op=1; break;}
                }
                if(op==0) {
                    // printf("# %lld %lld\n",i,w+v[j]);
                    w+=v[j];
                }
            }
            ans=max(ans,w);
        }
        printf("%lld\n",ans);
    }
    return 0;
}