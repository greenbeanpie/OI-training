#include<bits/stdc++.h>
using namespace std;
int t,n,m;
char c;
inline int read(){
	int ans=0;
	char c=getchar();
	while(!(c>='0'&&c<='9'))c=getchar();
	while(c>='0'&&c<='9'){
		ans=(ans<<3)+(ans<<1)+c-'0';
		c=getchar();
	}
	return ans;
}
inline char readchar(){
	char c[5];
	scanf("%s",c);
	return c[0];
}
set<int>a0[100010];
int a[100010];
bool b[100010];
bool book[100010];
int ans;

void U(int u){
	book[u]=1;
	ans++;
	for(int v:a0[u]){
		if(book[v]==0) U(v);
	}
}

int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	read();
	t=read();
	for(int t1,t2;t--;){
		n=read(),m=read();
		for(int i=0;i<=n+1;i++){
			a[i]=i;
			a0[i].insert(i);
		}
		b[0]=1;
		while(m--){
			c=readchar();
			if(c=='T'||c=='F'){
				t1=read();
				a[t1]=n+1;
				a0[n+1].insert(t1);
			}
			else if(c=='U'){
				t1=read();
				a[t1]=0;
				a0[0].insert(t1);
			}else if(c=='+'){
				t1=read(),t2=read();
				a0[a[t1]].erase(t1);
				a[t1]=a[t2];
				b[t1]=b[t1]==b[t2]?0:1;
				a0[a[t2]].insert(t1);
			}else if(c=='-'){
				t1=read(),t2=read();
				a0[a[t1]].erase(t1);
				a[t1]=a[t2];
				b[t1]=b[t1]==b[t2]?1:0;
				a0[a[t2]].insert(t1);
			}
		}
		for(int i=n;i>=0;i--){
			while(a[i]>i&&a[i]!=n+1&&a[a[i]]!=a[i]){
				b[i]=b[i]==b[a[i]]?0:1;
				a0[a[i]].erase(i);
				a[i]=a[a[i]];
				a0[a[i]].insert(i);
			}
		}
		
		ans=-1;
		for(int i=0;i<=n;i++){
			if(book[i]==0&&a[i]==i&&b[i]==1)U(i);
		}
		printf("%d\n",ans);
		for(int i=0;i<=n;i++)a0[i].clear();
		memset(book,0,sizeof(book));
		memset(b,0,sizeof(b));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
