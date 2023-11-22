#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+(c^'0'),c=getchar();
    return x;
}
int n,m;
int val[100005];
int fa[200005];
int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    read();int _=read();
    while(_--){
        n=read(),m=read();
        for(int i=1;i<=n;i++)val[i]=i+1;
        while(m--){
            char c=getchar();
            while(c!='T'&&c!='F'&&c!='U'&&c!='+'&&c!='-')c=getchar();
            int x=read();
            if(c=='T')val[x]=1;
            else if(c=='F')val[x]=-1;
            else if(c=='U')val[x]=0;
            else{
                int y=read();
                if(c=='+')val[x]=val[y];
                else val[x]=-val[y];
            }
        }
        for(int i=1;i<=2*n+3;i++)fa[i]=i;
        for(int i=1;i<=n;i++)fa[get(i+n+3)]=get(val[i]+n+2),fa[get(n+1-i)]=get(n+2-val[i]);
        int ans=0;
        for(int i=1;i<=n;i++)if(get(i+n+3)==get(n+2)||get(i+n+3)==get(n+1-i)||get(n+1-i)==get(n+2))ans++;
        printf("%d\n",ans);
    }
    return 0;
}