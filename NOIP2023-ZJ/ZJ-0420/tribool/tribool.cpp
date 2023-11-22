#include"cstdio"
int c,t;
int n,m,x,y;
int f[200020];
int a[200020];
int ans;
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
inline char read(){
	char c=getchar();
	while(c!='T'&&c!='F'&&c!='U'&&c!='+'&&c!='-')c=getchar();
	return c;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);ans=0;
		for(int i=0;i<=200005;i++)f[i]=i;
		for(int i=0;i<=200005;i++)a[i]=i;
		for(int i=1;i<=m;i++)
		{
			char c=read();
			scanf("%d",&x);
			if(c=='T')a[x]=200001;
			if(c=='F')a[x]=200002;
			if(c=='U')a[x]=200003;
			if(c=='+')
			{
				scanf("%d",&y);
				a[x]=a[y];
			}
			if(c=='-')
			{
				scanf("%d",&y);
				if(a[y]<100000)a[x]=a[y]+100000;
				else a[x]=a[y]-100000;
			}
		}
		for(int i=1;i<=n;i++)
		{
			int fx=find(i),fy=find(a[i]);
			if(fx!=fy)f[fx]=fy;
			int fa=a[i];
			if(fa>100000)fa-=100000;
			else fa+=100000;
			fx=find(i+100000),fy=find(fa);
			if(fx!=fy)f[fx]=fy;
		}
		a[find(200003)]=-1;
		for(int i=1;i<=n;i++)
		{
			int fx=find(i),fy=find(i+100000);
			if(fx==fy)a[fx]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[find(i)]==-1||a[find(i+100000)]==-1)ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
