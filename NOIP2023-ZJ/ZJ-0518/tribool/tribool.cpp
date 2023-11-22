#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+30;
long long c,t,n,m,uc;
int fa[maxn];
char v;
int Find(int x){
    if(fa[x]==x){
        return x;
    }
    fa[x]=Find(fa[x]);
    return fa[x];
}
void fuzhi3(int x,int a){
    fa[x+n+3]=a;
    if(a==0){
        fa[n+3-x]=0;
    }else{
        fa[n+3-x]=3-a;
    }
}
void fuzhi1(int x,int y){
    int p=Find(n+3+y);
    if(fa[n+3+x]+p!=(2*n+6)){
        fa[n+3+x]=p;
    }else{
        fa[n+3+x]=0;
        fa[n+3-x]=0;
    }
    int q=Find(n+3-y);
    if(fa[n+3-x]+q!=(2*n+6)){
        fa[n+3-x]=q;
    }else{
        fa[n+3+x]=0;
        fa[n+3-x]=0;
    }
}
int main()
{
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    scanf("%d%d",&c,&t);
    for(int R=1;R<=t;R++){
        uc=0;
        scanf("%d%d",&n,&m);
        memset(fa,0,sizeof(fa));
        for(int i=0;i<=2*n+3;i++){
            fa[i]=i;
        }
        for(int i=1;i<=m;i++){
            cin>>v;
            if(v=='-'){
                int a,b;
                scanf("%d%d",&a,&b);
                fuzhi1(a,-b);
            }else if(v=='+'){
                int a,b;
                scanf("%d%d",&a,&b);
                fuzhi1(a,b);
            }else{
                int a;
                scanf("%d",&a);
                if(v=='T')fuzhi3(a,2);
                else if(v=='F')fuzhi3(a,1);
                else fuzhi3(a,0);
            }
        }
        for(int i=n+4;i<=2*n+3;i++){
            int gfa=Find(i);
            if(gfa==0){
                uc++;
            }
        }
        printf("%d\n",uc);
    }
    return 0;
}
