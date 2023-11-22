//LG UID 1019966
//9:00 T1
//ying gai ke yi,gan jue zhi you J T2
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
ll n,m;char s[3005][3005],minn[3005],ss[3005];bool bb;
bool cmp(char a,char b){return a>b;}
int main(){
freopen("dict.in","r",stdin);freopen("dict.out","w",stdout);
	memset(minn,'z',sizeof(minn));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);
		sort(s[i],s[i]+m,cmp);
		for(int j=0;j<m;j++)
			if(s[i][j]<minn[j]){memcpy(minn,s[i],sizeof(s[i]));break;}
			else if(s[i][j]>minn[j])break;
//		printf("%s\n",minn);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++)ss[j]=s[i][m-j-1];
		bb=0;
		for(int j=0;j<m;j++)
			if(ss[j]<minn[j]){putchar(49);bb=1;break;}
			else if(ss[j]>minn[j]){putchar(48);bb=1;break;}
		if(!bb)putchar(49);
	}
	return 0;
}