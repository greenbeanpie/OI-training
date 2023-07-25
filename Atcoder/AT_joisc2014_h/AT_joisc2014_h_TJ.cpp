#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
char ch;
struct node{
	int x,y,id;
}a[200005];
bool cmp(node u,node v){return u.x<v.x||u.x==v.x&&u.y<v.y||u.x==v.x&&u.y==v.y&&u.id<v.id;}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("AT_joisc2014_h.in", "r", stdin);
	freopen("AT_joisc2014_h_TJ.out", "w", stdout);
#endif
	//freopen("joioji.in","r",stdin);
	//freopen("joioji.out","w",stdout);
	scanf("%d",&n);
	ch=getchar();
	while(ch<'A'||ch>'Z') ch=getchar();
	for(int i=1;i<=n;i++){
		if(ch=='J'){
			a[i].x=a[i-1].x-1;
			a[i].y=a[i-1].y-1;
		}
		else if(ch=='O'){
			a[i].x=a[i-1].x+1;
			a[i].y=a[i-1].y;
		}
		else if(ch=='I'){
			a[i].x=a[i-1].x;
			a[i].y=a[i-1].y+1;
		}
		a[i].id=i;
		if(i<n) ch=getchar();
	}
	sort(a,a+n+1,cmp);
	int now=a[0].id,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].x==a[i-1].x&&a[i].y==a[i-1].y) ans=max(ans,a[i].id-now);
		else now=a[i].id;
	}
	printf("%d\n",ans);
	return 0;
}

