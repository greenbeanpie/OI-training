#include<cstdio>
#include<iostream>
#include<cstring>
//#include<time.h>
using namespace std;
const long long N=1005,NN=100005,inf=200000000;
int count,t,n,m,x;
int cz[NN][3];
char st[NN];
bool stb[NN];
void exec12()
{
	char ch,tch;
	long long ans=inf;
//		cout<<st;
	int x=0,y=0;
	for(int i=0;i<m;i++)
	{
		tch=getchar();
		x=0,y=0;
		if(tch=='U' or tch=='T' or tch=='F')
		{
			ch=getchar();ch=getchar();
			while(ch!='\n')
			{
				if(ch>='0' && ch<='9')
					x=(x<<3)+(x<<1)+ch-48;
				ch=getchar();
			}
			cz[i][0]=tch;cz[i][1]=x;
		}else
		if(tch=='+' or tch=='-')
		{
			ch=getchar();ch=getchar();
			while(ch!=' ')
			{
				if(ch>='0' && ch<='9')	x=(x<<3)+(x<<1)+ch-48;
				ch=getchar();
			}
			while(ch!='\n')
			{
				if(ch>='0' && ch<='9')	y=(y<<3)+(y<<1)+ch-48;ch=getchar();
			}
//			stb[x]=stb[y];
			cz[i][0]=tch;cz[i][1]=x;cz[i][2]=y;
		}
//		cout<<tch<<endl<<x<<endl<<y<<endl;
	}
	int x0[12],x1[12];
	for( x0[1]=-1;x0[1]<=1;x0[1]++)
	for( x0[2]=-1;x0[2]<=1;x0[2]++)
	for( x0[3]=-1;x0[3]<=1;x0[3]++)
	for( x0[4]=-1;x0[4]<=1;x0[4]++)
	for( x0[5]=-1;x0[5]<=1;x0[5]++)
	for( x0[6]=-1;x0[6]<=1;x0[6]++)
	for( x0[7]=-1;x0[7]<=1;x0[7]++)
	for( x0[8]=-1;x0[8]<=1;x0[8]++)
	for( x0[9]=-1;x0[9]<=1;x0[9]++)
	for( x0[10]=-1;x0[10]<=1;x0[10]++)
	{
		for(int i=1;i<=n;i++)
		{
			x1[i]=x0[i];//T=1 F=-1 U=0
//			printf("%d ",x1[i]);
		}
//		printf("\n");
		for(int i=0;i<m;i++)
		{
			if(cz[i][0]==('T'))x1[cz[i][1]]=1;
			if(cz[i][0]==('F'))x1[cz[i][1]]=-1;
			if(cz[i][0]==('U'))x1[cz[i][1]]=0;
			if(cz[i][0]==('+'))x1[cz[i][1]]=x1[cz[i][2]];
			if(cz[i][0]==('-'))x1[cz[i][1]]=-x1[cz[i][2]];
		}
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			if(x1[i]!=x0[i])
			{
				flag=true;//T=1 F=-1 U=0
				break;
			}
//			printf("%d ",x1[i]);
		}
//		printf("\n");printf("\n");
		long long ucnt=0;
		if(!flag)
		{
			for(int i=1;i<=n;i++)
				if(x0[i]==0)ucnt++;
			if(ucnt<ans)
			{
				ans=ucnt;
//				for(int j=1;j<=n;j++)
//					printf("%d ",x0[j]);
//				printf("\n");
			}
		}
	}
	printf("%d\n",ans);
}
void exec34()
{		
	char ch,tch;
//		cout<<st;
	memset(st,'Z',sizeof(st));
	for(int i=0;i<m;i++)
	{
		ch=getchar();
		x=0;
		while(ch!='\n')
		{
			if(ch>='A' && ch<='Z')
				tch=ch;
			if(ch>='0' && ch<='9')
				x=(x<<3)+(x<<1)+ch-48;
			ch=getchar();
		}
//			cout<<tch<<endl<<x<<endl;
		st[x]=tch;
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
		if(st[i]=='U')
			ans++;
	printf("%lld\n",ans);
}

void exec56()
{
	char ch,tch;
	memset(stb,false,sizeof(stb));
//		cout<<st;
	int x=0,y=0;
	for(int i=0;i<m;i++)
	{
		tch=getchar();
		x=0,y=0;
		if(tch=='U')
		{
			ch=getchar();ch=getchar();
			while(ch!='\n')
			{
				if(ch>='0' && ch<='9')
					x=(x<<3)+(x<<1)+ch-48;
				ch=getchar();
			}
			cz[i][0]=0;cz[i][1]=x;
		}else
		if(tch=='+')
		{
			ch=getchar();ch=getchar();
			while(ch!=' ')
			{
				if(ch>='0' && ch<='9')	x=(x<<3)+(x<<1)+ch-48;
				ch=getchar();
			}
			while(ch!='\n')
			{
				if(ch>='0' && ch<='9')	y=(y<<3)+(y<<1)+ch-48;ch=getchar();
			}
//			stb[x]=stb[y];
			cz[i][0]=1;cz[i][1]=x;cz[i][2]=y;
		}
//		cout<<tch<<endl<<x<<endl<<y<<endl;
	}
//	while(1)
//	{
//		bool changed=false;
//		for(int i=0;i<m;i++)
//		{
//			if(cz[i][0])
//			{
//				if(stb[cz[i][1]]!=stb[cz[i][2]])
//					changed=true;
//				stb[cz[i][1]]=stb[cz[i][2]];
//			}else
//			{
//				stb[cz[i][1]]=true;
//			}
//		}
//		if(!changed)break;
//	}

	bool changed=false;
		for(int i=m-1;i>=0;i--)
		{
			if(cz[i][0])
			{
				if(stb[cz[i][1]]!=stb[cz[i][2]])
					changed=true;
				stb[cz[i][1]]=stb[cz[i][2]];
			}else
			{
				stb[cz[i][1]]=true;
			}
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		if(stb[i])
			ans++;
	printf("%d\n",ans);
}
struct edge
{
	long long to,next,type;
}e[NN];
long long head[NN],cnt=0;
void add(long long u,long long v,long long ty)
{
	e[++cnt].to=v;
	e[cnt].next=head[u];
	e[cnt].type=ty;
	head[u]=cnt;
}
long long color[NN];
bool suc=true;
long long dfs(int now,int co)
{
//	if(co==0)return 0;
//	if(now==0)return 0;
//	printf("dfs(%d,%d)\n",now,co);
//	if(co>100000)_sleep(1000);
//	system("PAUSE");
	color[now]=co;
	long long dnum=1;
	for(long long i=head[now];i>0;i=e[i].next)
	{
//		if(e[i].type!=1 and e[i].type!=-1)break;
//		if(co!=1 and co!=-1)break;
		if(color[e[i].to]==0)
			dnum+=dfs(e[i].to,co*e[i].type);else
			if(color[e[i].to]!=co*e[i].type)
				suc=false;
	}
	return dnum;
}
void exec78()
{
//	printf("CHECK");
	memset(head,0,sizeof(head));
	cnt=0;
	char ch,tch;
//		cout<<st;
	long long x=0,y=0;
	for(long long i=0;i<m;i++)
	{
		tch=getchar();
		x=0,y=0;
		if(tch=='+' or tch=='-')
		{
			ch=getchar();ch=getchar();
			while(ch!=' ')
			{
				if(ch>='0' && ch<='9')	x=(x<<3)+(x<<1)+ch-48;
				ch=getchar();
			}
			while(ch!='\n')
			{
				if(ch>='0' && ch<='9')	y=(y<<3)+(y<<1)+ch-48;ch=getchar();
			}
//			stb[x]=stb[y];
			cz[i][0]=tch;cz[i][1]=x;cz[i][2]=y;
			add(x,y,(tch=='+')?1:-1);add(y,x,(tch=='+')?1:-1);
		}
//		cout<<tch<<endl<<x<<endl<<y<<endl;
	}
//	printf("CHECK");
	long long ut=0,unum=0;
	memset(color,0,sizeof(color));
	for(long long i=1;i<=n;i++)
	{	
//	printf("CHECK");
		if(!color[i])
		{
			suc=true;
			ut=dfs(i,1);
			if(suc==false)
				unum+=ut;
		}
		
	}

	printf("%lld\n",unum);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout); //neicun+

	scanf("%d%d",&count,&t);
while(t--){
	scanf("%d%d",&n,&m);
	getchar();
	if(count>=1 && count<=2)
		exec12();
	if(count>=3 && count<=4)
		exec34();
	if(count>=5 && count<=6)
		exec56();
	if(count>=7 && count<=8)
		exec78();

}
	fclose(stdin);fclose(stdout);
	return 0;
}
