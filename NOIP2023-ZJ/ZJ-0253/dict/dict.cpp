#include <bits/stdc++.h>
using namespace std;
struct zheng{
	int a[50];
	string s;
	int id;
}f[3010];
struct dao{
	string s;
	int id;
}g[3010];
bool answer[3010];
int n,m;
char c;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
bool cmp2(dao x,dao y){
	return x.s<y.s;
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c=getchar();
			f[i].a[c-'a'+1]++;
		}
		getchar();
		for(int k=1;k<=26;k++){
			int t1=f[i].a[k];
			while(t1){
				f[i].s+=char('a'+k-1);
				t1--;
			}
		}
		for(int k=26;k>=1;k--){
			int t2=f[i].a[k];
			while(t2){
				g[i].s+=char('a'+k-1);
				t2--;
			}
		}
		g[i].id=i;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	sort(g+1,g+1+n,cmp2);
//	for(int i=1;i<=n;i++){
//		cout<<" g: "<<g[i].id<<endl;
//	}

	for(int i=1;i<=n;i++){
		int tot=1;
		if(g[tot].id==i) tot=2;
		if(f[i].s<g[tot].s){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}