#include<bits/stdc++.h>
#define ll  long long

using namespace std;

const ll  inf=1410065743;

int n,m;
string w[3010];
ll    ha[3010];
string s;

void build(){
	int k=0;
	char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while('0'<=c && c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	n=k;
	k=0;
	while(c<'0' || c>'9')c=getchar();
	while('0'<=c && c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	m=k;
	k=0;
	if(c<'a' || c>'z'){
		for(int i=0;i<n;i++){
			cin>>w[i];
		}
	}else{
		w[0]+=c;
		for(int i=1;i<n*m;i++){
			c=getchar();
			w[i/m]+=c;
		}	
	}
	
}

ll has(string s){
	ll ans=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		ans=(ans*26+(s[i]-'a'))%inf;
	}
	return ans%inf;
}

string heal(ll ans){
	string s="";
	string s1="";
	for(int i=0;i<m;i++){
		ll k;
		k=ans%26;
		s+=(k+'a');
		ans/=26;
	}
	for(int i=0;i<m;i++){
		s1+=s[m-1-i];
	}
	return s;
}

string op(string s){
	string ans1="";
	string ans="";
	priority_queue<char>que;
	ll len=s.size();
	for(int i=0;i<len;i++){
		que.push(s[i]);
	}
	for(int i=1;i<=len;i++){
		ans1+=que.top();
		que.pop();
	}
	for(int i=0;i<len;i++){
		ans+=ans1[len-1-i];
	}
	return ans;
}

string op1(string s){
	string ans1="";
	priority_queue<char>que;
	ll len=s.size();
	for(int i=0;i<len;i++){
		que.push(s[i]);
	}
	for(int i=1;i<=len;i++){
		ans1+=que.top();
		que.pop();
	}
	return ans1;
}

bool check(ll ans){
	if(ans<=ha[0])return 1;
	else return 0;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	build();
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=0;i<n;i++){
		ha[i]=has(op1(w[i]));
	}
	sort(ha,ha+n-1);
	for(int i=0;i<n;i++){
		ll ans;
		ans=has(op(w[i]));//min
		if(check(ans))cout<<1;
		else cout<<0;
	}
	return 0;
}
