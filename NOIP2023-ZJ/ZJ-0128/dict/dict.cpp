/*
签到题，我们只需要排个序然后比较一下就行了
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3003;
int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
struct node{
    int fi,las;
}a[N];
char w[N];
bool ch[28];
int n,m;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        scanf("%s",w);
        for(int j=0;j<m;j++)
            ch[w[j]-'a']=1;
        for(int j=0;j<=26;j++){
            if(ch[j]){
                a[i].fi=j;
                break;
            }
        }
        for(int j=26;~j;--j){
            if(ch[j]){
                a[i].las=j;
                break;
            }
        }
        memset(ch,0,sizeof(ch));
    }
    for(int i=1;i<=n;i++){
        bool flag=1;
        for(int j=1;flag&&j<=n;j++){
            if(i==j)continue;
            if(a[i].fi>=a[j].las)flag=0;
        }
        putchar(flag?'1':'0');
    }
    return 0;
}