#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int x;bool l;string s;
	bool operator <(Node q){
		return (s==q.s)?l>q.l:s<q.s;
	}
}p[6039];
string s,Min[3039],Max[3039];
bool cmp1(char x,char y){
	return x>y;
}
bool cmp2(char x,char y){
	return x<y;
}
void read(){
	s="";char ch=getchar();
	while('a'>ch||ch>'z')ch=getchar();
	while('a'<=ch&&ch<='z')s.push_back(ch),ch=getchar();
}
int ans[3039];
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		read();Max[i]=Min[i]=s;
		sort(Max[i].begin(),Max[i].end(),cmp1);
		sort(Min[i].begin(),Min[i].end(),cmp2);
		p[i*2-1].s=Max[i],p[i*2].s=Min[i];
		p[i*2-1].x=p[i*2].x=i;
		p[i*2-1].l=0;p[i*2].l=1;
	}
	sort(p+1,p+1+2*n);
	for(int i=1;i<=2*n;i++){
		if(p[i].l)ans[p[i].x]=1;
		else break;
	}
	for(int i=1;i<=n;i++){
		printf("%d",ans[i]);
	}
}