//      %%% 
//sto shawryao orz
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
int n,m;
//ll t;
struct letter{
	int val,idx;
};
bool operator < (letter a,letter b){
	return a.val>b.val;
}
priority_queue<letter> q[3010];
int w[3010][3010];
bool cmp1(int a,int b){
	return a>b;
}
bool cmp2(int a,int b){
	return a<b;
}
string reads(){
	string s="";
	char ch=getchar();
	while (ch<'a'||ch>'z') ch=getchar();
	while (ch>='a'&&ch<='z') s+=ch,ch=getchar();
	return s;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-f;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void write(ll x){
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	n=read(),m=read();
	if (n==1){
		write(1);
		return 0;
	}
	for (int i=1;i<=n;i++){
//		t+=1;
//		printf("%d\n",i);
//		string s="";
//		s=reads();
		char ch=getchar();
		while (ch<'a'||ch>'z') ch=getchar();
//		cout<<s<<endl;
		for (int j=0;j<m;j++) w[i][j+1]=ch-'a'+1/*,t+=1*/,ch=getchar();
//		sort(w[i]+1,w[i]+m+1,cmp1);
//		t+=m*12;
		sort(w[i]+1,w[i]+m+1,cmp2);
		for (int j=1;j<=m;j++) q[j].push({w[i][m-j+1],i})/*,t+=12*/;
//		t+=m*12;
	}
//	printf("%lld\n",t);
//	printf("duru\n");
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
//			t+=1;
//			printf("%lld\n",t);
//			continue;
			letter s=q[j].top();
//			t+=12;
//			printf("%d %d\n",w[i][j],s.val);
			if (s.idx==i){
				q[j].pop();
				letter c=q[j].top();
				q[j].push(s);
				s=c;
//				t+=24;
			}
			if (w[i][j]<s.val){
				write(1);
//				putchar('\n');
				break;
			}
			if (w[i][j]>s.val){
				write(0);
//				putchar('\n');
				break;
			}
		}
	}
//	printf("\n%lld\n",t);
	return 0;
}
