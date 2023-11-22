#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
int n,top,m;
pair<string,int> q[2*N];
string s[N];
int ans[N];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		sort(s[i].begin(),s[i].end());
		q[++top]={s[i],i};
		sort(s[i].begin(),s[i].end(),[](char x,char y){
			return x>y;
		});
//		cout<<s[i]<<"\n";
		q[++top]={s[i],0x3f3f3f3f};	
	}
	sort(q+1,q+top+1);
	int cnt=0;
	for(int i=top;i>=1;i--){
		if(q[i].second==0x3f3f3f3f) cnt++;
		else{
			if(cnt<n) ans[q[i].second]=0;
			else ans[q[i].second]=1;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i];
	cout<<"\n";
}
