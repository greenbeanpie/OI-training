#include<bits/stdc++.h>
#define gc getchar()
using namespace std;
inline int read(){
	int x=0,f=1;char ch=gc;
	for(;!isdigit(ch);ch=gc)if(ch=='-')f=-1;
	for(;isdigit(ch);ch=gc)x=x*10+ch-'0';
	return x*f;
}

const int MAX=1005;
int T,m,n,ans;
string di="TFU";
struct cz{
	char op;
	int i,j;
};
cz a[MAX];

char f(char x){
	if(x=='T')return 'F';
	if(x=='F')return 'T';
	return x;
}
void dfs(string s,int k){
	if(s.size()<n){
		for(int i=0;i<3;i++){
			dfs(s+di[i],k+(di[i]=='U'?1:0));
		}
	}else{
		string x=s;
		for(int i=1;i<=m;i++){
			if(a[i].op=='-'){
				x[a[i].i]=f(x[a[i].j]);
			}else if(a[i].op=='+'){
				x[a[i].i]=x[a[i].j];
			}else{
				x[a[i].i]=a[i].op;
			}
		}
		if(x==s){
//			if(k<=ans)cout<<s+" "+x<<endl;
			ans=min(ans,k);
		}
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	T=read();
	T=read();
	while(T--){
		n=read(),m=read(),ans=n;
		for(int i=1;i<=m;i++){
			cin>>a[i].op;
			if(a[i].op=='-'||a[i].op=='+'){
				a[i].i=read()-1,a[i].j=read()-1;
			}else{
				a[i].i=read()-1;
			}
		}
		dfs("",0);
		printf("%d\n",ans);
	}
	return 0;
}