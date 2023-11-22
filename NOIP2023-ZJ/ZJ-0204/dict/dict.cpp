#include<bits/stdc++.h>
using namespace std;
const int N=3005;
const int mod=1e9+7,bas=31;
int n,m;
int a[N][N],b[N][N];
char s[N][N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%s",s[i]+1);
        sort(s[i]+1,s[i]+1+m);
        for(int j=1;j<=m;j++){
            a[i][j]=(1ll*a[i][j-1]*bas%mod+(s[i][j]-'a'));
            a[i][j]>=mod?a[i][j]-=mod:0;
            b[i][j]=(1ll*b[i][j-1]*bas%mod+(s[i][m-j+1]-'a'));
            b[i][j]>=mod?b[i][j]-=mod:0;
		}
    }
    for(int i=1;i<=n;i++){
        int flg=1;
        for(int j=1;j<=n;j++)
            if(i!=j){
            	if(a[i][m]==b[j][m]){flg=0;break;}
                int l=0,r=m-1;
                while(l<r){
                    int mid=(l+r+1)>>1;
                    if(a[i][mid]==b[j][mid])l=mid;
                    else r=mid-1;
                }
                if(s[j][m-l]<s[i][l+1]){flg=0;break;}
            }
        putchar(flg+'0');
    }
    return 0;
}