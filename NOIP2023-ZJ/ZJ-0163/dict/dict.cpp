#include<bits/stdc++.h>
using namespace std;
int cnt[26];
void Sort(string& s){
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<(int)s.size();++i) ++cnt[s[i]-'a'];
	for(int i=1;i<26;++i) cnt[i]+=cnt[i-1];
	string ss=s;
	for(int i=(int)ss.size()-1;i>=0;--i) s[--cnt[ss[i]-'a']]=ss[i];
}
const int N=3005;
string s[N],suf[N],s1[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;++i){
		cin >> s[i];
		Sort(s[i]);
		s1[i]=s[i];
		reverse(s1[i].begin(),s1[i].end());
	}
	suf[n]=string(m,char('z'+1));
	for(int j=n-1;j>=0;--j) suf[j]=min(suf[j+1],s1[j]);
	string mx=string(m,char('z'+1));
	for(int i=0;i<n;++i){
		if(s[i]<min(suf[i+1],mx)) cout << "1";
		else cout << "0";
		mx=min(mx,s1[i]);
	}
	return 0;
}