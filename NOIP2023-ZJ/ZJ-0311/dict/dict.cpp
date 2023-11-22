#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
il ll read(){
	ll a=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=a*10+ch-'0';ch=getchar();}
	return a*f;
}
ll n,m,num[27],maxp;
string s,demomax,demomin,mins[3100],maxmin="{";
void creat(){
	demomax="";
	demomin="";
	for(int i=26;i>=1;i--)for(int j=1;j<=num[i];j++)demomax+=char('a'-1+i);
	for(int i=1;i<=26;i++){
		while(num[i]--)demomin+=char('a'-1+i);
		num[i]++;
	}
	return;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read();
	m=read();
	for(register int i=1;i<=n;i++){
		cin>>s;
		for(register int j=0;j<m;j++)num[s[j]-'a'+1]++;
		creat();
		mins[i]=demomin;
		if(demomax<maxmin){
			maxmin=demomax;
			maxp=i;
		}
	}
	for(register int i=1;i<maxp;i++){
		if(mins[i]<maxmin)cout<<1;
		else cout<<0;
	}
	cout<<1;
	for(register int i=maxp+1;i<=n;i++){
		if(mins[i]<maxmin)cout<<1;
		else cout<<0;
	}
	return 0;
}
