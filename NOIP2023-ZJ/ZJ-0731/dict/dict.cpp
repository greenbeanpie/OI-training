#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
const int N=3005;
int n,m;
string mn="z";
bool ans[N];
string s[N];
struct word{
	string s;
	int pos;
}p[N],q[N];
queue <int> Q;
void IO(string name){
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}
bool cmp(word x,word y){
	return x.s<y.s;
}
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++)
			q[i].s=p[i].s,q[i].pos=p[i].pos;
		sort(q+1,q+n+1,cmp);
		ans[q[1].pos]=1;
		return;
	}
	swap(p[x].s[0],p[x].s[1]);
	dfs(x+1);
	swap(p[x].s[0],p[x].s[1]);
	dfs(x+1);
}
signed main(){
	IO("dict");
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		p[i].s=s[i];
		p[i].pos=i;
		if(m==1)	mn=min(mn,s[i]);
	}	
	if(m==1){
		for(int i=1;i<=n;i++){
			if(s[i]==mn)	cout<<1;
			else cout<<0;
		}
	}
	if(m==2){
		dfs(1);
		for(int i=1;i<=n;i++)
			cout<<ans[i];
	}
	return 0;
}

