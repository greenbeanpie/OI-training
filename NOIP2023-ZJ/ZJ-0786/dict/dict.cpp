#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
string s[3005];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	if(n==1)putchar('1');
	else if(m==1){
		char mn=127;
		int cnt=0;
		for(int i=1;i<=n;++i){
			cin>>s[i];
			mn=min(mn,s[i][0]);
		}for(int i=1;i<=n;++i)
			if(s[i][0]==mn)cnt++;
		for(int i=1;i<=n;++i)putchar('0'+(s[i][0]==mn&&cnt==1));
	}else if(m==2){
		for(int i=1;i<=n;++i)cin>>s[i];
		for(int i=1;i<=n;++i){
			if(s[i][0]>s[i][1])swap(s[i][0],s[i][1]);
			string mn=s[i];
			bool flag=1;
			for(int j=1;j<=n;++j)
				if(i-j){
					if(s[j][0]<s[j][1])swap(s[j][0],s[j][1]);
					s[j]<=mn?flag=0:1;
				}
			putchar('0'+flag);
		}
	}else{
		priority_queue<char>q[3005];
		for(int i=1;i<=n;++i)cin>>s[i];
		for(int i=1;i<=n;++i)
			for(char c:s[i])q[i].push(c);
		for(int i=1;i<=n;++i){
			string str[3005];
			for(int j=1;j<=n;++j)str[j]=s[j];
			for(int j=m;j>0;--j)str[i][j-1]=q[i].top(),q[i].pop();
			string mn=str[i];
			bool flag=1;
			for(int j=1;j<=n;++j){
				if(i-j)for(int k=0;k<m;++k)str[j][k]=q[j].top(),q[j].pop();
				str[j]<mn?flag=0:1;
			}
			putchar('0'+flag);
		}
	}
	return 0;
}


