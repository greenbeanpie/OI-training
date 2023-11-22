#include<bits/stdc++.h>
using namespace std;
char ch;
string st;
int c,T,n,m,x,y,ans,to,ccL,BO,Luc,Ly,Mid,L;
int f[200001],cc[200001],Rl[200001],Rled[200001];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m,ans=0;
		for(int i=1;i<=n;i++)f[i]=i+1;//别忘记这里特殊处理过，0给了U,1给了T,-1给了F,i+1表示第i位
		for(int i=1;i<=n;i++)cc[i]=Rl[i]=Rled[i]=0;
		for(int i=1;i<=m;i++)
		{
			getline(cin,st);
			ch=getchar();
			scanf("%d",&x);
			if(ch=='U')f[x]=0;
			if(ch=='T')f[x]=1;
			if(ch=='F')f[x]=-1;
			if(ch=='+')
			{
				scanf("%d",&y);
				f[x]=f[y];
			}
			if(ch=='-')
			{
				scanf("%d",&y);
				f[x]=-f[y];
			}
		}
		for(int i=1;i<=n;i++)
		if(!Rled[i])
		{
			if(f[i]==1||f[i]==0||f[i]==-1)Rl[i]=f[i],Rled[i]=1;
			if(f[i]==i+1)Rl[i]=1,Rled[i]=1;
			if(f[i]==-i-1)Rl[i]=0,Rled[i]=1;
		}
		for(int i=1;i<=n;i++)
		if(!Rled[i])
		{
			if(f[i]!=1&&f[i]!=0&&f[i]!=-1&&f[i]!=i+1&&f[i]!=-i-1)
			{
				to=abs(f[i])-1;
				cc[i]=1;
				ccL=1;
				BO=0;
				Luc=0;
				Ly=0;
				Mid=0;
				L=i;
				while(1)
				{
					if(Rled[to])
					{
						BO=1;
						Ly=to;
						break;
					}
					if(cc[to])
					{
						BO=2;
						Luc=ccL-cc[to];//奇偶判断点
						if(f[L]<0)Luc++;
						Mid=to;//带环标记点
						break;
					}
					if(f[L]<0)ccL++;
					cc[to]=ccL;
					L=to;
					//cout<<"TEST!!!"<<to<<" "<<ccL<<endl;
					to=abs(f[to])-1;
				}
				if(BO==1)
				{
					Rl[i]=Rl[Ly];
					cc[i]=0;
					to=abs(f[i])-1;
					while(1)
					{
						if(Rled[to])break;
						Rl[to]=Rl[Ly];
						cc[to]=0;
						Rled[to]=1;
						to=abs(f[to])-1;
					}
				}
				if(BO==2)
				{
					if(Luc%2==1)
					{
						Rl[Mid]=0;
						cc[Mid]=0;
						to=abs(f[Mid])-1;
						while(1)
						{
							if(Rled[to])break;
							Rl[to]=0;
							cc[to]=0;
							Rled[to]=1;
							to=abs(f[to])-1;
						}
					}
					else
					{
						Rl[Mid]=1;
						cc[Mid]=0;
						to=abs(f[Mid])-1;
						while(1)
						{
							if(Rled[to])break;
							Rl[to]=1;
							cc[to]=0;
							Rled[to]=1;
							to=abs(f[to])-1;
						}
					}
					Rl[i]=Rl[Mid];
					cc[i]=0;
					to=abs(f[i])-1;
					while(1)
					{
						if(Rled[to])break;
						Rl[to]=Rl[Mid];
						cc[to]=0;
						Rled[to]=1;
						to=abs(f[to])-1;
					}
				}
			}
			Rled[i]=1;
		}
		/*for(int i=1;i<=n;i++)
		{
			printf("%d:",i);
			if(Rl[i]==1||Rl[i]==-1)putchar('T'),putchar(10);
			if(Rl[i]==0)putchar('U'),putchar(10);
		}*/
		for(int i=1;i<=n;i++)if(Rl[i]==0)ans++;
		printf("%d\n",ans);
	}
	return 0;
}