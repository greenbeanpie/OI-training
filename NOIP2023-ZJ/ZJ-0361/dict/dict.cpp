#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
string s,fr[maxn][2],minn,minn2;
int n,m,tong[maxn],tong2[maxn],minp;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<m;j++)tong[s[j]-'a'+1]++,tong2[s[j]-'a'+1]++;
		int cnt=0;
		for(int j=26;j>=1;j--)
			while(tong[j])
				fr[i][0]+=(j+'a'-1),tong[j]--;
		cnt=0;
		for(int j=1;j<=26;j++)
			while(tong2[j])
				fr[i][1]+=(j+'a'-1),tong2[j]--;
	}
	minn=fr[1][0],minp=1;
	for(int i=2;i<=n;i++)
		if(fr[i][0]<minn)
			minn=fr[i][0],minp=i;
	if(minp==1)minn2=fr[2][0];
	else minn2=fr[1][0];
	for(int i=1;i<=n;i++)
		if(fr[i][0]<minn2&&i!=minp)
			minn2=fr[i][0];
	for(int i=1;i<=n;i++){
		if(i==minp){
			if(fr[i][1]<minn2)printf("1");
			else printf("0");
		}
		else{
			if(fr[i][1]<minn)printf("1");
			else printf("0");
		}
	}
	return 0;
}
