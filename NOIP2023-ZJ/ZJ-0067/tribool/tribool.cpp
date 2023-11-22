#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,m,pos[N],fa[N];
int get(int x) {return fa[x]==x?x:fa[x]=get(fa[x]);}
void solve() {
    cin>>n>>m;
    for(int i=2*n+1;i<=4*n;i++) pos[i]=i-2*n;
    while(m--) {
        char v;
        cin>>v;
        if(v=='T') {
            int i;
            cin>>i;
            pos[2*n+i]=4*n+1;
            pos[3*n+i]=4*n+2;
        }
        else if(v=='F') {
            int i;
            cin>>i;
            pos[2*n+i]=4*n+2;
            pos[3*n+i]=4*n+1;
        }
        else if(v=='U') {
            int i;
            cin>>i;
            pos[2*n+i]=4*n+3;
            pos[3*n+i]=4*n+3;
        }
        else if(v=='+') {
            int i,j;
            cin>>i>>j;
            int x=pos[2*n+j],y=pos[3*n+j];
            pos[2*n+i]=x;
            pos[3*n+i]=y;
        }
        else {
            int i,j;
            cin>>i>>j;
            int x=pos[2*n+j],y=pos[3*n+j];
            pos[2*n+i]=y;
            pos[3*n+i]=x;
        }
    }
    for(int i=1;i<=4*n+3;i++) fa[i]=i;
    for(int i=2*n+1;i<=4*n;i++) fa[get(i)]=get(pos[i]);
    for(int i=1;i<=2*n;i++) fa[get(i)]=get(i+2*n);
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(get(i)==get(n+i)||get(i)==get(4*n+3)) {
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}
int main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) solve();
    return 0;
}