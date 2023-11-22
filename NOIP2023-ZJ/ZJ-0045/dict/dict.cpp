#include<bits/stdc++.h>
using namespace std;
int n,m;
int mn[3005],mx[3005];
char str[3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",str+1);
        mx[i]=-1,mn[i]=26;
        for(int j=1;j<=m;j++)mx[i]=max(mx[i],str[j]-'a'),mn[i]=min(mn[i],str[j]-'a');
    }
    for(int i=1;i<=n;i++){
        int mxx=26;
        for(int j=1;j<=n;j++)if(j!=i)mxx=min(mxx,mx[j]);
        if(mn[i]<mxx)putchar('1');else putchar('0');
    }
    puts("");
    return 0;
}