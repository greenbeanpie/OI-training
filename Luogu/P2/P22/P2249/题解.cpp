#include<cstdio>
#include<algorithm>//用到lower_bound
using namespace std;
const int MAXN=1e6+10;//注意范围
int read(){//快读
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int a[MAXN];
int main(){
	int n=read(),m=read();//读入
	for(int i=1;i<=n;i++) a[i]=read();
	while(m--){
		int x=read();
		int ans=lower_bound(a+1,a+n+1,x)-a;//二分搜，注意-a
		if(x!=a[ans]) printf("-1 ");//没有，输出-1
		else printf("%d ",ans);//有，输出ans
	}
	return 0;//华丽结束
}
