#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;
inline int read(){
	int w=1,s=0;
	char c=getchar();
	for(;c<'0'||c>'9';w*=(c=='-')?-1:1,c=getchar());
	for(;c>='0'&&c<='9';s=s*10+c-'0',c=getchar());
	return w*s;
}
int n,m;
char ming[N],maxn[N];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		ming[i]='z',maxn[i]='a';
		for(int j=0;j<m;j++){
			ming[i]=min(ming[i],s[j]);
			maxn[i]=max(maxn[i],s[j]);
		}
	}
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(ming[i]>=maxn[j]){
				flag=false;
				break;
			}
		}
		cout<<flag;
	}
	cout<<endl;
	return 0;
}

