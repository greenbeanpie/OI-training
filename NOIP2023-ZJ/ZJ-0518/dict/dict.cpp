#include <bits/stdc++.h>

using namespace std;
const int maxn=3010;//3010
int n,m,ans[maxn];
struct word{
    int id;
    int a[30];
}w[maxn];
int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        char c[maxn];
        scanf("%s",c);
        for(int j=0;j<m;j++){
            w[i].a[c[j]-'a'+1]++;
        }
        w[i].id=i;
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            word x=w[i],y=w[j];
            int cnt1=1,cnt2=26;
            for(int i=1;i<=m;i++){
                while(x.a[cnt1]==0)cnt1++;
                while(y.a[cnt2]==0)cnt2--;
                if(cnt1<cnt2){
                    break;
                }else if(cnt1>cnt2){
                    flag=false;
                    break;
                }else{
                    x.a[cnt1]--;
                    y.a[cnt2]--;
                }
            }
            if(flag==false){
                break;
            }
        }
        if(flag){
            printf("1");
        }else{
            printf("0");
        }
    }
    return 0;
}
