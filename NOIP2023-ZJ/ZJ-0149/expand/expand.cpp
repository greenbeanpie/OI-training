#include <bits/stdc++.h>
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

int c,n,m,q;
vector<int> X,Y;

void solve(vector<int> x,vector<int> y) {
    if(x[0]>y[0]) swap(x,y);
    if(x[0]==y[0] || x.back()>=y.back()) {printf("0"); return;}
    vector<int> A,B;
    A.push_back(x[0]),B.push_back(y[0]);
    for(int i=1;i<x.size()-1;i++) {
        if(x[i-1]<=x[i] && x[i]<=x[i+1]) continue;
        if(x[i-1]>=x[i] && x[i]>=x[i+1]) continue;
        A.push_back(x[i]);
    }
    for(int i=1;i<y.size()-1;i++) {
        if(y[i-1]<=y[i] && y[i]<=y[i+1]) continue;
        if(y[i-1]>=y[i] && y[i]>=y[i+1]) continue;
        B.push_back(y[i]);
    }
    A.push_back(x.back());
    B.push_back(y.back());
    // for(int i=0;i<A.size();i++) printf("%d ",A[i]); puts("");
    // for(int i=0;i<B.size();i++) printf("%d ",B[i]); puts("");
    
    // if(A.size()<B.size()) {
    //     for(int i=0;i<A.size();i++) {
    //         for(int j=0;j<)
    //     }
    // }
    printf("1");
    return ;
}

signed main() {
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    c=gin(),n=gin(),m=gin(),q=gin();
    if(n==1 & m==1) {
        int aa=gin(),bb=gin();
        if(aa>bb) printf("1");
        else printf("0");
        while(q--) {
            int kx=gin(),ky=gin();
            for(int i=1;i<=kx;i++) gin(),aa=gin();
            for(int i=1;i<=ky;i++) gin(),bb=gin();
            if(aa>bb) printf("1");
            else printf("0");
        }
        return 0;
    }
    if(n==2 && m==2) {
        int aa[3],bb[3];
        aa[1]=gin(),aa[2]=gin();
        bb[1]=gin(),bb[2]=gin();
        if((aa[1]-bb[1])*(aa[2]-bb[2])>0) printf("1");
        else printf("0");
        while(q--) {
            int kx=gin(),ky=gin();
            for(int i=1;i<=kx;i++) aa[gin()]=gin();
            for(int i=1;i<=ky;i++) bb[gin()]=gin();
            if((aa[1]-bb[1])*(aa[2]-bb[2])>0) printf("1");
            else printf("0");
        }
        return 0;
    }
    for(int i=1;i<=n;i++) X.push_back(gin());
    for(int i=1;i<=m;i++) Y.push_back(gin());
    solve(X,Y);
    while(q--) {
        int kx=gin(),ky=gin();
        vector<int> kX,kY;
        kX=X,kY=Y;
        for(int i=1;i<=kx;i++) kX[gin()-1]=gin();
        for(int i=1;i<=ky;i++) kY[gin()-1]=gin();
        // for(int i=1;i<=n;i++) printf("%d ",kX[i-1]);
        // puts("");
        // for(int i=1;i<=m;i++) printf("%d ",kY[i-1]);
        // puts("");
        solve(kX,kY);
    }
    return 0;
}