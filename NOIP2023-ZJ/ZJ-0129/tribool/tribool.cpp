/*
xcopy tribool2.in tribool.in
g++ tribool.cpp -o tribool -O2 -std=c++14 -static
./tribool
cmd /C "fc tribool.out tribool2.ans"
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

void work();

int main(){

    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int c,t;cin>>c>>t;
    while(t--){
        work();
    }

    cout.flush(); fclose(stdin); fclose(stdout);

    return 0;
}


const int N=100010;

int n,m;
int fa[3*N];
int p[N];bool iv[N];
/*
n+1 -> T
n+2 -> F
n+3 -> U
*/
inline int G(char x){
    return (x=='T')?0:((x=='F')?1:2);
}

int find(int u){
    int t=u,l=u;
    while(fa[t]!=t) t=fa[t];
    while(fa[u]!=u) l=u,u=fa[u],fa[l]=t;
    return t;
}
inline void mer(int u,int v){ fa[find(u)]=find(v); }
inline bool get(int u,int v){ return find(u)==find(v); }

#define T(i) (3*(i)-2)
#define F(i) (3*(i)-1)
#define U(i) (3*(i))

void work(){

    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i]=i,iv[i]=0;
    for(int i=1;i<=3*n+5;i++) fa[i]=i;

    for(int i=1;i<=m;i++){
        char op;int x,y;
        cin>>op;
        if(op=='+') cin>>x>>y,p[x]=p[y],iv[x]=iv[y];
        else if(op=='-') cin>>x>>y,p[x]=p[y],iv[x]=!iv[y];
        else cin>>x,p[x]=n+1+G(op),iv[x]=0;
    }

    // for(int i=1;i<=n;i++) cout<<i<<"  "<<p[i]<<" , "<<iv[i]<<"\n";

    for(int i=1;i<=n;i++){
        int j=p[i];
        if(j>n){
            if(j==n+3) mer(U(i),3*n+1);
            continue;
        }
        if(iv[i]){
            mer(T(i),F(j));
            mer(U(i),U(j));
            mer(F(i),T(j));
        }else{
            mer(T(i),T(j));
            mer(U(i),U(j));
            mer(F(i),F(j));
        }
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(get(T(i),F(i))) cnt++;
        else if(get(3*n+1,U(i))) cnt++;
    }
    cout<<cnt<<"\n";

}