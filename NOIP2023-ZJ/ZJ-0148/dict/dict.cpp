#include<bits/stdc++.h>
using namespace std;
char s[3010];
int n,m,mn[3010],mx[3010];
bool cmp(int x,int y){
    if(mn[x]<mx[y])return true;
    if(mn[x]>mx[y])return false;
    if(mn[x]==mx[x]&&mn[y]==mx[y])return true;
    return false;
}
bool check(int t){
    for(int i=1;i<=n;i++){
        if(!cmp(t,i))return false;
    }
    return true;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s),mn[i]=100;
        for(int j=0;j<m;j++){
            mn[i]=min(s[j]-'a',mn[i]);
            mx[i]=max(s[j]-'a',mx[i]);
        }
    }
    for(int i=1;i<=n;i++)putchar(check(i)+'0');
    putchar('\n');
    return 0;
}