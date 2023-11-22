#include<bits/stdc++.h>
#define ll long long 
#define UF(i,x,y) for(int i=x;i<=y;i++)
#define DF(i,x,y) for(int i=x;i>=y;i--)
#define ce continue
#define inf 0x7fffffff
#define N 3005
using namespace std;
int a[26],n,m,flag;
char st[N];
string Lo[N],Up[N];
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9') f=-f,ch=getchar();while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();return x*f;}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1) {printf("1");fclose(stdin);fclose(stdout);return 0;}
	UF(i,1,n)
	{
		cin>>st;
		memset(a,0,sizeof(a));
		UF(j,0,m-1) a[st[j]-'a']++;
		UF(j,0,25) UF(k,1,a[j]) Lo[i]+=char(97+j),Up[i]=char(97+j)+Up[i];
	}
	UF(i,1,n)
	{
		flag=1;
		UF(j,1,n) if(i!=j&&Lo[i]>=Up[j]) {flag=0;break;}
		printf("%d",flag);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
