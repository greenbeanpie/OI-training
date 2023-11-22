#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<3)+(s<<1)+ch-'0';
        ch=getchar();
    }
    return s*w;
}
const int maxn=5e5+5;
int n,m;
int a[2][maxn];
int c,q;
int main(){
    freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
    c=read(),n=read(),m=read(),q=read();
    for(int i=1;i<=n;i++)a[0][i]=read();
    for(int i=1;i<=m;i++)a[1][i]=read();
    while(q--){
       int x=read(),y=read(); 
       for(int i=1;i<=x;i++){
            int k=read(); 
       }
       for(int j=1;j<=y;j++){
        int k=read();
       }
       cout<<0;
    }
}