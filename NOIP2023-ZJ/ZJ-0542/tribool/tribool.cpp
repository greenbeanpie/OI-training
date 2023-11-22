#include<bits/stdc++.h>

using namespace std;
const int maxn=1e5+200;
int n,m,c,t,ans;
int mo[maxn],wo[maxn],com[maxn][5];
//com[p][t] data t
void solve_1_2() {
	scanf("%d%d",&n,&m);
	ans=n+1;
	for(int i=1; i<=m; i++) {
		char a;
		cin>>a;
		if(a=='T'||a=='U'||a=='F') {
			com[i][0]=2;
			cin>>com[i][2];
			if(a=='T') {
				com[i][1]=0;
			} else if(a=='U') {
				com[i][1]=2;
			} else {
				com[i][1]=1;
			}
		} else if(a=='+') {
			com[i][0]=0;
			cin>>com[i][1]>>com[i][2];
		} else {
			com[i][0]=1;
			cin>>com[i][1]>>com[i][2];
		}
	}
	for(int i=0; i<=pow(3,n)-1; i++) {
		int t=i;
		int q=0;
		for(int j=1; j<=n; j++) {
			mo[j]=t%3;
			t/=3;
			wo[j]=mo[j];
			if(mo[j]==2) q++;
		}
		for(int j=1; j<=m; j++) {
			if(com[j][0]==0) {
				wo[com[j][1]]=wo[com[j][2]];
			} else if(com[j][0]==1) {
				if(wo[com[j][2]]==0) wo[com[j][1]]=1;
				else if(wo[com[j][2]]==1) wo[com[j][1]]=0;
				else {
					wo[com[j][1]]=2;
				}
			} else {
				wo[com[j][2]]=com[j][1];
			}
		}
		int flag=1;
		for(int j=1; j<=n; j++) {
			if(wo[j]!=mo[j]) {
				flag=0;
				break;
			}
		}
		if(flag)
			ans=min(ans,q);
	}
	cout<<ans<<endl;
}
void solve_3_4() {
	scanf("%d%d",&n,&m);
	memset(mo,1,sizeof(mo));
	ans=0;
	for(int i=1; i<=m; i++) {
		char t;
		cin>>t>>com[i][2];
		if(t=='T') com[i][1]=0;
		else if(t=='U') com[i][1]=2;
		else com[i][1]=1;
	}
	for(int i=1; i<=m; i++) {
		mo[com[i][2]]=com[i][1];
	}
	for(int i=1; i<=n; i++) {
		if(mo[i]==2) ans++;
	}
	printf("%d\n",ans);
}
int main() {
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);

	if(c==3||c==4) {
		for(int i=1; i<=t; i++)
			solve_3_4();
	} else {
		for(int i=1; i<=t; i++)
			solve_1_2();
	}
	return 0;
}
