#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline int read(){
	int w=1,s=0;
	char c=getchar();
	for(;c<'0'||c>'9';w*=(c=='-')?-1:1,c=getchar());
	for(;c>='0'&&c<='9';s=s*10+c-'0',c=getchar());
	return w*s;
}
int Id,T;
int n,m;
struct P{
	char opt;
	int x,y;
}a[N];
int ans;
int calc(char c){
	if(c=='T') return 1;
	if(c=='F') return -1;
	return 0;
}
struct state{
	int name;
	int id;
	int flag;   //0:wu 1:tong 2:yi 3:que
	int val;
	void Init(int i){
		name=i,id=flag=val=0;
	}
	void gave1(state x){
		if(x.flag==0){
			id=x.name,flag=1;
		}
		else{
			id=x.id,flag=x.flag,val=x.val;
		}
	}
	void gave2(state x){
		if(x.flag==0){
			id=x.name,flag=2;
		}
		if(x.flag==1){
			id=x.id,flag=2;
		}
		if(x.flag==2){
			id=x.id,flag=1;
		}
		if(x.flag==3){
			flag=3,val=-x.val;
		}
	}
	void gave3(char c){
		flag=3,val=calc(c);
	}
}f[N];

int fa[N];
long long Size[N];
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x),y=get(y);
	fa[x]=y;
	Size[y]+=Size[x];
}

int Fa[2*N];
int Get(int x){
	if(x==Fa[x]) return x;
	return Fa[x]=Get(Fa[x]);
}
void Merge(int x,int y){
	if(Get(x)==Get(y)) return;
	Fa[Get(x)]=Get(y);
}

bool flag[N];

void Init(){
	memset(flag,0,sizeof flag);
	ans=0;
	for(int i=1;i<=n;i++) f[i].Init(i);
	for(int i=1;i<=n;i++) fa[i]=i,Size[i]=1,Fa[i]=i,Fa[i+n]=i+n;
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	Id=read(),T=read();
	while(T--){
		n=read(),m=read();
		
		Init();
		
		for(int i=1;i<=m;i++){
			cin>>a[i].opt;
			if(a[i].opt=='+'){
				a[i].x=read(),a[i].y=read();
				f[a[i].x].gave1(f[a[i].y]);
			}
			else if(a[i].opt=='-'){
				a[i].x=read(),a[i].y=read();
				f[a[i].x].gave2(f[a[i].y]);
			}
			else{
				a[i].x=read();
				f[a[i].x].gave3(a[i].opt);
			}
		}
		
		for(int i=1;i<=n;i++){
			if(f[i].flag==1||f[i].flag==2){
				int x=i,y=f[i].id;
				if(get(x)!=get(y)){
					merge(x,y);
				} 
				int same_x=x,dif_x=x+n,same_y=y,dif_y=y+n;
				if(f[i].flag==1){
					Merge(same_x,same_y);
					Merge(dif_x,dif_y);
				}
				else{
					Merge(same_x,dif_y);
					Merge(dif_x,same_y);
				}
			}
		}
		
		for(int i=1;i<=n;i++){
			if(Get(i)==Get(i+n)){
				f[i].flag=3,f[i].val=0;
			} 
		}
		
		for(int i=1;i<=n;i++){
			if(f[i].flag==3&&f[i].val==0){
				if(!flag[get(i)]) ans+=Size[get(i)],flag[get(i)]=true;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
1 1
10 10
T 3
+ 1 2
- 7 1
+ 2 10
T 6
- 1 4
U 3
+ 7 10
F 5
+ 6 9

1 1
3 3
- 2 1
- 3 2
- 1 3

1 1
10 10
- 7 5
+ 5 1
+ 1 7
+ 2 3
+ 3 4
+ 4 6
+ 6 8
- 8 9
+ 9 10
- 10 2

1 1
10 10
- 7 3
- 5 3
+ 3 7
- 1 6
+ 4 6
- 8 4
- 6 8
+ 2 2
- 9 9
- 10 10
//5
*/
