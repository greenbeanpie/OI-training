#include<bits/stdc++.h>
#define int long long
using namespace std; 
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,m;
struct point{
	string a,s,b;
	int num;
}a[3010];
int t[30];
signed main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			a[i].a[j]=getchar();
			t[a[i].a[j]-'a'+1]++;
		}
		for(int j=1,p=0;j<=26;j++)
			for(int k=0;k<t[j];k++)
				a[i].s+='a'+j-1;
		for(int j=26,p=0;j>=1;j--)
			for(int k=0;k<t[j];k++)
				a[i].b+='a'+j-1;
		memset(t,0,sizeof(t));
		getchar();
	}
	for(int i=1;i<=n;i++){
		bool flag=1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(a[i].s>=a[j].b){
				flag=0;
				break;
			}
		}
		cout<<flag;
	}
	return 0;
}
