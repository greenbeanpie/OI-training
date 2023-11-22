#include<bits/stdc++.h>
using namespace std;
const int N=3000+10;
int cnt[N][26];
string s[N];
int ans[N];
int maxt[N];
int n,m;
string heap_sort(string s){
	priority_queue<char>q;
	for(int i=0;i<m;i++) q.push(s[i]);
	string ans="";
	for(int i=0;i<m;i++) ans+=q.top(),q.pop();
	return ans;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	int pos=1;
	string tmps=heap_sort(s[1]);
	for(int i=2;i<=n;i++){
		string tmp=heap_sort(s[i]);
		if(tmp<tmps) tmps=tmp,pos=i; 
	}
	string stmp=s[pos];
	stmp=heap_sort(stmp);
	string cmp=stmp;
	for(int i=1;i<=n;i++){
		string stmp=s[i];
		stmp=heap_sort(stmp);	
		for(int i=0;i<m/2;i++) swap(stmp[i],stmp[m-i-1]);
		if(stmp<cmp) ans[i]=1;
		else ans[i]=0;
	}
	for(int i=1;i<=n;i++) cout<<ans[i];
	puts("");
	return 0;
}