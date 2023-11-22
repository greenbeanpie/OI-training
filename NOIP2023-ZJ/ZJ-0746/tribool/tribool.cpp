//      %%%
//sto shawryao orz
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
int c,t,n,m;
int a[N];
int ans;
string reads(){
	string s="";
	char ch=getchar();
	while ((ch<'A'||ch>'Z')&&ch!='+'&&ch!='-') ch=getchar();
	while ((ch>='A'&&ch<='Z')||ch=='+'||ch=='-') s+=ch,ch=getchar();
	return s;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-f;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void write(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	c=read(),t=read();
//	if (c==3||c==4){
		while (t--){
			n=read(),m=read();
			for (int i=1;i<=n;i++) a[i]=0;
			for (int i=1;i<=m;i++){
				string s=reads();
//				int x=read();
				if (s=="U"){
					int x=read();
					a[x]=3;
				}else if (s=="T"){
					int x=read();
					a[x]=1;
				}else if (s=="F"){
					int x=read();
					a[x]=2;
				}else if (s=="+"){
					int x=read(),y=read();
					a[x]=a[y];
					continue;
				}else if (s=="-"){
					int x=read(),y=read();
					if (a[y]==1) a[x]=2;
					if (a[y]==0) a[x]=0;
					if (a[y]==3) a[x]=3;
					if (a[y]==2) a[x]=1;
					continue;
				}
			}
			for (int i=1;i<=n;i++) if (a[i]==3) ans++;
			write(ans);
			ans=0;
			putchar('\n');
		}
//	}
	return 0;
}
