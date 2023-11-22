#include<bits/stdc++.h>
using namespace std;
#define N 3005
#define il inline
#define ll long long
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m;
int Min[N],Max[N];
int cnt;
struct node{
	string s;
	int id,type;
	bool operator<(node x){
		return s<x.s;
	}
}a[N<<1];
int ton[30];
il void solve(int id,string s){
	memset(ton,0,sizeof(ton));
	for(int i=0;i<m;i++) ton[s[i]-'a']++;
	string t;
	t="";
	for(int i=0;i<26;i++){
		for(int j=ton[i];j>=1;j--)
		t+=char(i+'a');
	}
	a[++cnt]=node{t,id,0};
	t="";
	for(int i=25;i>=0;i--){
		for(int j=ton[i];j>=1;j--)
		t+=char(i+'a');
	}
	a[++cnt]=node{t,id,1};
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(); m=read();
	string s;
	for(int i=1;i<=n;i++) cin>>s,solve(i,s);
	sort(a+1,a+cnt+1);
	int Rank=1;
	if(a[1].type==0){
		Min[a[1].id]=Rank;
	}
	else{
		Max[a[1].id]=Rank;
	}
	for(int i=2;i<=cnt;i++){
		if(a[i-1].s!=a[i].s) Rank++;
		if(a[i].type==0){
			Min[a[i].id]=Rank;
		}
		else{
			Max[a[i].id]=Rank;
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(Min[i]>Max[j]){
					flag=0;
					break;
				}
			}
		}
		if(flag) putchar('1');
		else putchar('0');
	}
	return 0;
}
