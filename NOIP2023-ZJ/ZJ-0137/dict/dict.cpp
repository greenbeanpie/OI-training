#include<bits/stdc++.h>
using namespace std;

bool f1;
int n,m;
int c[3100][3100];
int son[1200000][30],tot=1;
vector<int>belo[1200000];
bool cmp1(int x,int y){
	return x<y;
}
bool cmp2(int x,int y){
	return x>y;
}
void insert(int id){
	int now=1;
	for(int i=1;i<=m;i++){
		int nxt=c[id][i];
		if(!son[now][nxt])son[now][nxt]=++tot;
		now=son[now][nxt];
	}
	belo[now].push_back(id);
}
int ask(int id){
	int now=1;
	for(int i=1;i<=m;i++){
		int nxt=c[id][i];
		for(int j=1;j<nxt;j++){
			if(son[now][j])return 0;
		}
		if(!son[now][nxt])return 1;
		now=son[now][nxt];
	}
	return (belo[now].size()==1&&belo[now][0]==id)?1:0;
}
bool f2;
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch=getchar();
		for(int j=1;j<=m;j++){
			while(ch<'a'||ch>'z')ch=getchar();
			c[i][j]=ch-'a'+1;
			ch=getchar();		
		}
		sort(c[i]+1,c[i]+1+m,cmp2);
		insert(i);
	}
	for(int i=1;i<=n;i++){
		sort(c[i]+1,c[i]+1+m,cmp1);
		printf("%d",ask(i));
	}
}
