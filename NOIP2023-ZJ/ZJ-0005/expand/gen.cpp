#include<bits/stdc++.h>
using namespace std;
int n=5e5,m=5e5-1,q=60;
mt19937 rnd(time(0));
const int M=1e6;
int main(){
    freopen("expand.in","w",stdout);
    printf("8 %d %d %d\n",n,m,q);
    cerr<<"helo\n";
    for(int i=1;i<=n;++i) printf("%d ",rnd()%M+1);printf("\n");
    for(int i=1;i<=m;++i) printf("%d ",rnd()%M+1);printf("\n");
    cerr<<"helo\n";
    for(int i=1;i<=q;++i){
        printf("%d %d\n",1,1);
        printf("%d %d\n",rnd()%n+1,rnd()%M+1);
        printf("%d %d\n",rnd()%m+1,rnd()%M+1);
    }
    cerr<<"fin\n";
}