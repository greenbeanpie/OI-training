#include<bits/stdc++.h>
#define int long long
const int maxn = 3e3+5;
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int n,m;
string s[maxn];
int idx,t[maxn][30];
int mins[maxn];
void insert(string s){
	int p=0;
	for(register int i=0;i<s.length();i++){
		int ch=s[i]-'a';
		if(!t[p][ch]){
			++idx;
			t[p][ch]=idx;
		}
		mins[p]=min(mins[p],ch);
		p=t[p][ch];
	}
}
int vis[30];
int find(string s){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<s.length();i++){
		int ch=s[i]-'a';
		vis[ch]++;
	}
	int p=0;
	for(register int i=0;i<s.length();i++){
		for(register int j=0;j<mins[p];j++) if(vis[j]) return 1;
		if(vis[mins[p]]){
			vis[mins[p]]--;
			p=t[p][mins[p]];
		}else return 0;
	}
	return 1;
}
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();
	if(n==1){printf("%d",1);return 0;}
	for(int i=0;i<=m*26;i++) mins[i]=114;
	for(register int i=1;i<=n;i++){
		cin>>s[i];
		insert(s[i]);
	}
	for(int i=1;i<=n;i++) cout<<find(s[i]);
	return 0;
}
