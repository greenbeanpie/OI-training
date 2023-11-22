#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3005],c[3005];
priority_queue <pair <string,int> ,vector <pair <string,int> > ,greater <pair <string,int> > > p,q;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m ;
	if(n==1){
		cout << 1 ;
		return 0;
	}for(int i=1;i<=n;i++){
		cin >> s[i] ;
		sort(s[i].begin(),s[i].end());
		c[i]=s[i];
		reverse(c[i].begin(),c[i].end());
		p.push({c[i],i});
		q.push({c[i],i});
	}q.pop();
	for(int i=1;i<=n;i++){
		if(p.top().second==i) cout << (q.top().first>s[i]) ;
		else cout << (p.top().first>s[i]) ;
	}return 0;
}