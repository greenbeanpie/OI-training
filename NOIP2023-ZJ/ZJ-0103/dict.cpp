//FSZ with yingxue-cat
#include<bits/stdc++.h>
using namespace std;
char s[3005];
char t[3005][3005],zf[3005];
char qz[3005][3005],hz[3005][3005];
int tt[11005];
char ans[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=0;j<26;++j)tt[j]=0;
		for(int j=1;j<=m;++j)++tt[s[j]-'a'];
		int wz=0;
		for(int j=25;j>=0;--j)while(tt[j]){
			t[i][++wz]=j;
			--tt[j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j)qz[i][j]=t[i][j];
		if(i>1){
			int fl=0;
			for(int j=1;j<=m;++j)if(qz[i][j]!=qz[i-1][j]){
				if(qz[i][j]>qz[i-1][j])fl=1;
				else fl=-1;
				break;
			}
			if(fl==1)for(int j=1;j<=m;++j)qz[i][j]=qz[i-1][j];
		}
	}
	for(int i=n;i>=1;--i){
		for(int j=1;j<=m;++j)hz[i][j]=t[i][j];
		if(i<n){
			int fl=0;
			for(int j=1;j<=m;++j)if(hz[i][j]!=hz[i+1][j]){
				if(hz[i][j]>hz[i+1][j])fl=1;
				else fl=-1;
				break;
			}
			if(fl==1)for(int j=1;j<=m;++j)hz[i][j]=hz[i+1][j];
		}
	}
//n=1 tepan
//n=1 tepan
//n=1 tepan
//n=1 tepan
//n=1 tepan
//n=1 tepan
//n=1 tepan
	for(int i=1;i<=n;++i){
		if(i==1)for(int j=1;j<=m;++j)zf[j]=hz[i+1][j];
		if(i==n)for(int j=1;j<=m;++j)zf[j]=qz[i-1][j];
		if(1<i&&i<n){
			int fl=0;
			for(int j=1;j<=m;++j)if(qz[i-1][j]!=hz[i+1][j]){
				if(qz[i-1][j]<hz[i+1][j])fl=1;
				else fl=-1;
				break;
			}
			if(fl==1)for(int j=1;j<=m;++j)zf[j]=qz[i-1][j];
			else for(int j=1;j<=m;++j)zf[j]=hz[i+1][j];
		}
		int fl=0;
		for(int j=1;j<=m;++j)if(t[i][m-j+1]!=zf[j]){
			if(t[i][m-j+1]<zf[j])fl=1;
			else fl=-1;
			break;
		}
		if(fl==1)ans[i]='1';
		else ans[i]='0';
	}
	if(n==1)ans[1]='1';
	printf("%s\n",ans+1);
	return 0;
}
