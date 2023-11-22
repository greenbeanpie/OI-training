#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

const int N=5005;
int c,nn,mm,n,m,q;
int xt[N],xo[N],yt[N],yo[N];
int *x,*y;

bool f[N][N];
int cnt[10];

void sol(){

    if(xt[1]<yt[1]) x=xt,y=yt,n=nn,m=mm;
    else if(xt[1]>yt[1]) x=yt,y=xt,n=mm,m=nn;
    else{ cout<<0; return; }
    
    // for(int i=1;i<=n;i++) cout<<x[i]<<" \n"[i==n];
    // for(int i=1;i<=m;i++) cout<<y[i]<<" \n"[i==m];

    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(x[i]>=y[j]) f[i][j]=0;
            else{
                f[i][j]=f[i][j-1]||f[i-1][j]||f[i-1][j-1];
            }
        }

    cout<<f[n][m];

}

int main(){

    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>c>>nn>>mm>>q;
    
    for(int i=1;i<=nn;i++) cin>>xo[i],xt[i]=xo[i];
    for(int i=1;i<=mm;i++) cin>>yo[i],yt[i]=yo[i];

    sol();
    while(q--){
        int kx,ky,p,v;
        cin>>kx>>ky;
        while(kx--) cin>>p>>v,xt[p]=v;
        while(ky--) cin>>p>>v,yt[p]=v;
        sol();
        memcpy(xt,xo,nn*sizeof(int));
        memcpy(yt,yo,mm*sizeof(int));
    }
    cout<<endl;

    cout.flush(); fclose(stdin); fclose(stdout);

    return 0;
}