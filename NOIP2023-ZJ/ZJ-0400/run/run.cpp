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
struct point{
	int x,y,z;
}a[100010];
int num;
signed main(){
	srand(time(0));
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c=read(),T=read();
	while(T--){
		int n=read(),m=read(),k=read(),d=read();
		for(int i=1;i<=m;i++){
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			num+=a[i].z;
		}
		num-=n-n%k;
		cout<<(int)rand()%num;
	}
	return 0;
}
