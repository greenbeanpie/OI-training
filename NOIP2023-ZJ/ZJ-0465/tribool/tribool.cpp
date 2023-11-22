#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int c;
char b[N],bb[N];
char zm[10]={'F','T','U'};
int ans=2e9+10;

struct ss{
	char v;
	int i,j;
}a[N];


void solve1(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++) bb[i]=b[i];
		for(int i=1;i<=m;i++){
			char t=a[i].v;
			if(t=='U'||t=='F'||t=='T')
				b[a[i].i]=t;
			else if(t=='+') b[a[i].i]=b[a[i].j];
			else if(t=='-'){
				char p=b[a[i].j];
				if(p=='U') b[a[i].i]='U';
				if(p=='T') b[a[i].i]='F';
				if(p=='F') b[a[i].i]='T';
			}
		}	
		int sum=0;
		for(int i=1;i<=n;i++) {
			if(bb[i]!=b[i]) return;
			sum+=(b[i]=='U');
		}
		ans=min(ans,sum);
		return;	
	}
	for(int i=0;i<=2;i++){
		b[x]=zm[i];
		solve1(x+1);
	}
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		char t;cin>>t;
		if(t=='T'||t=='U'||t=='F'){
			cin>>x;
			a[i].v=t,a[i].i=x;
		}
		else{
			cin>>x>>y;
			a[i].v=t,a[i].i=x,a[i].j=y;
		}
	}
	if(c<=2){
		ans=n;
		solve1(1);
		cout<<ans<<'\n';
		return ;
	}	
	 if(c==4||c==3){
		for(int i=1;i<=m;i++){
			int x,y;
			char t=a[i].v;
			if(t=='U'||t=='F'||t=='T'){
				x=a[i].i;
				b[x]=t;
			}
		}
		ans=0;
		for(int i=1;i<=n;i++) ans+=(b[i]=='U');
		cout<<ans<<'\n';
		return;
	}
	else if(c==5||c==6){
		for(int i=1;i<=n;i++) b[i]='#';
		for(int t=1;t<=1e8/t/m;t++)
			for(int i=1;i<=m;i++){
				char t=a[i].v;
				if(t=='U'||t=='F'||t=='T') b[a[i].i]=t;
				else if(t=='+') b[a[i].i]=b[a[i].j];			
			}			
		ans=n;
		for(int i=1;i<=n;i++) ans+=(b[i]=='U');
		cout<<ans<<'\n';
		return;
	}
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}

