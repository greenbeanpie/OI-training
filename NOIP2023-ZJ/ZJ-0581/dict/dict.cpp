#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
struct wt{
	string smx;
	string smn;
}a[3010];
string s;
int ch[27];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(m==1){
		if(n==1){
			cin>>s;
			cout<<1<<endl;
			return 0;
		}
		int t=0,t1=30;
		for(int i=1;i<=n;i++){
			char s1;
			cin>>s1;
			if((s1-'a')<t1){
				t1=(s1-'a');
				t=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(t==i)
			cout<<1;
			else
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s;
		memset(ch,0,sizeof(ch));
		for(int i=0;i<s.size();i++)
		ch[s[i]-'a']++;
		for(int j=0;j<=25;j++){
			for(int k=1;k<=ch[j];k++)
			a[i].smn=a[i].smn+(char)(j+'a');
		}
		for(int j=a[i].smn.size()-1;j>=0;j--)
		a[i].smx=a[i].smx+a[i].smn[j];
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=1;j<=n;j++){
			if(a[i].smn<a[j].smx&&i!=j)
			continue;
			if(i==j)
			continue;
			cout<<0;
			t++;
			break;
		}
		if(!t)
		cout<<1;
	}
	return 0;
}
