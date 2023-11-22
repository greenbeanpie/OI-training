#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char c;c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ x=x*10+(c-48);c=getchar();}
	return x*f;
}

const int maxn=3e3+10,N=2e6+10;//caculate!!!

int b[maxn][maxn],a[maxn][maxn],tmp[maxn],ans[maxn];
int n,m,aim;
char S[maxn];

bool cmp1(int x,int y){
	return x<y;
}

bool cmp2(int x,int y){
	return x>y;
}

int tree[N][27],cnt;//foot print

void insert(int s[]){
	int p=0;
	for(int i=1;i<=m;i++){
		int x=s[i];
		if(tree[p][x]==0){
			tree[p][x]=++cnt;
			p=cnt;
		}
		else p=tree[p][x];
	}
}

int idx[maxn],len;

void find(){
	int p=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=26;j++){
			if(tree[p][j]){
				idx[++len]=j;
				p=tree[p][j];
				break;
			}
		}
	}
}

bool cmp(int x){
	for(int i=1;i<=m;i++){
		if(b[x][i]>idx[i]) return false;
		if(b[x][i]<idx[i]) return true;
	}
	return true;
}

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>S;
		for(int j=0;j<m;j++) tmp[j+1]=int(S[j]-'a');
		sort(tmp+1,tmp+m+1,cmp1);
		for(int j=1;j<=m;j++) b[i][j]=tmp[j];
		sort(tmp+1,tmp+m+1,cmp2);
		insert(tmp);
	}//find minn!!!
	find();
	for(int i=1;i<=n;i++){
		bool flag=false;
		flag=cmp(i);
		if(flag) ans[i]=1;
	}
	for(int i=1;i<=n;i++) printf("%d",ans[i]);
	return 0;
}