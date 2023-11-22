#include <bits/stdc++.h>
using namespace std;
int n,m,sum[26];
string s[3005],mi[3005],ma[3005],p[3005],q[3005];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>s[i],s[i]=" "+s[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) sum[s[i][j]-'a']++;
		mi[i]=" ",ma[i]="";
		for(int j=0;j<26;j++) for(;sum[j]>=1;sum[j]--) mi[i]=mi[i]+char(j+'a'),ma[i]=char(j+'a')+ma[i];
		ma[i]=" "+ma[i];
	}
	p[0]=q[n+1]=" ";
	for(int j=1;j<=m;j++) p[0]+="z",q[n+1]+="z";
	for(int i=1;i<=n;i++) p[i]=min(p[i-1],ma[i]);
	for(int i=n;i>=1;i--) q[i]=min(q[i+1],ma[i]);
	for(int i=1;i<=n;i++) printf("%d",int(mi[i]<min(p[i-1],q[i+1])));
	printf("\n");
	return 0;
}
