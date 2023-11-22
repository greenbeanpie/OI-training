#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n,m,col[maxn],ans,fa[maxn];
struct node{int op,x;}d[maxn];
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f * x;
}
int find(int x){return (fa[x] == x) ? x : fa[x] = find(fa[x]);}
int num(int x,int k){return x + k * n;}
void merge(int x,int y){fa[find(x)] = find(y);}
void clear(){
	for(int i = 1;i <= 2 * n;i++)	fa[i] = i,col[i] = 0;
	for(int i = 1;i <= n;i++)	d[i] = (node){0,i};
	ans = 0;
}
void input(){
	while(m--)
	{
		char ch;int x,y;
		cin >> ch;
		if(ch == '+')
			x = read(),y = read(),d[x] = d[y];
		else if(ch == '-')
		{
			x = read(),y = read(),d[x] = d[y];
			if(d[x].op < 4)	d[x].op ^= 1;		
		}
		else if(ch == 'T')
			x = read(),d[x] = (node){2,0};
		else if(ch == 'F')
			x = read(),d[x] = (node){3,0};
		else if(ch == 'U')
			x = read(),d[x] = (node){4,0};
	}
}
void solve(){
	for(int i = 1;i <= n;i++)	
		if(d[i].op == 0)	merge(num(i,0),num(d[i].x,0)),merge(num(i,1),num(d[i].x,1));
		else if(d[i].op == 1)	merge(num(i,1),num(d[i].x,0)),merge(num(i,0),num(d[i].x,1));
	for(int i = 1;i <= n;i++)	if(d[i].op == 4)	col[num(i,0)] = 1,col[num(i,1)] = 1;
	for(int i = 1;i <= n;i++)	if(find(num(i,0)) == find(num(i,1)))	col[find(num(i,0))] = 1;
	for(int i = 1;i <= n;i++)	ans += col[find(num(i,0))];
	printf("%d\n",ans);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int type = read(),T = read();
	while(T--)
	{
		n = read(),m = read();
		clear();
		input();
		solve();
	}
	return 0  ;
}
/*
2 1
10 10
- 1 1
U 1
T 7
U 8
- 9 6
U 3
- 9 3
- 6 3
+ 9 3
- 9 8
*/
