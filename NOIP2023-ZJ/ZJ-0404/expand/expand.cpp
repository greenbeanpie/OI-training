#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
void read(T &x)
{
	x=0;
	bool sgn=0;
	char c=getchar();
	while(!isdigit(c))
		sgn|=c=='-',c=getchar();
	while(isdigit(c))
		x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x=sgn?-x:x;
}
int c,n,m,q;
const int maxn=5e5+5;//soas maxm
//vector<int>A,B;
int A[maxn],B[maxn];
int st[maxn],ed[maxn],walll,wallr;
bool wallfl,smfl;
pair<int,int>wall[maxn];
//vector<int>conn[maxn];
void init()
{
	for(int i=1;i<=n;++i)
		//conn[i].clear();
		wall[i]=make_pair(0,0),
		st[i]=ed[i]=0;
	return;
}
void solve()
{
	//puts(">>>");
	init();
	if(c==1)//5pts
	{
		if(A[1]==B[1])
			putchar('0');
		else
			putchar('1');
		return;
	}
	if(A[1]==B[1])
	{
		putchar('0');
		//puts("<case1>");
		return;
	}
	if(A[1]>B[1])//exploaded.FaQ.
	{

		if(A[n]<=B[m])
		{
			putchar('0');
			//puts("<case3>");
			return;
		}
//		for(int i=1;i<n;++i)
//		{
//			if(A[i]<=B[m])
//			{
//				putchar('0');
//				//puts("<case4>");
//				return;
//			}
//		}
		st[1]=1;
		for(int i=1,j;i<n;++i)
		{
//			stat1:;
			if(ed[i])
			{
				st[i+1]=ed[i];
				continue;
			}
			wallfl=0;
			for(j=st[i];j<=m;++j)
			{
//				if(A[i+1]==A[i])
//					goto stat1;
				if(A[i+1]<A[i])
				{
					smfl=0;
					if(B[j]<A[i+1])
					{
						if(wallfl==1)
						{
							wall[i]=make_pair(walll,j-1);
						}
						wallfl=0;
						continue;
					}
					if(B[j]<A[i])
					{
						//conn[i].emplace_back(j);
						//wall[i]=j;
						if(wallfl==0)
						{
							wallfl=1;
							walll=j;
						}
						continue;
					}
					else
					{
						if(wallfl==1)
						{
							wall[i]=make_pair(walll,j-1);
						}
						break;
					}
				}
				else
				{
					smfl=1;
					if(B[j]>=A[i])
						break;
				}
			}
			if(j==m+1)
			{
				putchar('1');
				return;
			}
			int x=wall[i].first,y=wall[i].second;
			if(x&&y)
			{
				if(y+1<j)
				{
					ed[i]=y+1;
					st[i+1]=y+1;
				}
				else
				{
					ed[i]=x-1;
					st[i+1]=x-1;
				}
			}
			else
			{
				if(smfl==0)
				{
					ed[i]=j-1;
					st[i+1]=j-1;
				}
				else
				{
					if(B[j]<A[i+1])
					{
						ed[i]=j-1;
						st[i+1]=j;
					}
					else
					{
						ed[i]=j-1;
						st[i+1]=j-1;
					}
				}
			}
			if(ed[i]<st[i])
			{
//					printf("<st[%d]:%d ed[%d]:%d>\n",i,st[i],i,ed[i]);
//					printf("<wall lr:%d %d>\n",x,y);
				putchar('0');
				//puts("<case5>");
				return;
			}
		}
		//
	}
	else
	{
		if(A[n]>=B[m])
		{
			putchar('0');
			//puts("<case3>");
			return;
		}
		//if(8<=c&&c<=14)//special
		{
//			for(int i=1;i<n;++i)
//			{
//				if(A[i]>=B[m])
//				{
//					putchar('0');
//					//puts("<case4>");
//					return;
//				}
//			}
			st[1]=1;
			for(int i=1,j;i<n;++i)
			{
//				stat:;
				if(ed[i])
				{
					st[i+1]=ed[i];
					continue;
				}
				wallfl=0;
				for(j=st[i];j<=m;++j)
				{
//					if(A[i+1]==A[i])
//					{
//						++i;
//						goto stat;
//					}
					if(A[i+1]>A[i])
					{
						smfl=0;
						if(B[j]>A[i+1])
						{
							if(wallfl==1)
							{
								wall[i]=make_pair(walll,j-1);
							}
							wallfl=0;
							continue;
						}
						if(B[j]>A[i])
						{
							//conn[i].emplace_back(j);
							//wall[i]=j;
							if(wallfl==0)
							{
								wallfl=1;
								walll=j;
							}
							continue;
						}
						else
						{
//							if(B[j]<=A[n])
//							{
//								putchar('0');
//								return;
//							}
							if(wallfl==1)
							{
								wall[i]=make_pair(walll,j-1);
							}
							break;
						}
					}
					else
					{
						smfl=1;
						if(B[j]<=A[i])
							break;
					}
				}
				if(j==m+1)
				{
					putchar('1');
					return;
				}
				int x=wall[i].first,y=wall[i].second;
				//printf("[wall:%d %d]\n",x,y);
				if(x&&y)
				{
					if(y+1<j)
					{
						ed[i]=y+1;
						st[i+1]=y+1;
					}
					else
					{
						ed[i]=x-1;
						st[i+1]=x-1;
					}
				}
				else
				{
					if(smfl==0)
					{
						ed[i]=j-1;
						st[i+1]=j-1;
					}
					else
					{
						if(B[j]>A[i+1])
						{
							ed[i]=j-1;
							st[i+1]=j;
						}
						else
						{
							ed[i]=j-1;
							st[i+1]=j-1;
						}
					}
				}
				if(ed[i]<st[i])
				{
//					printf("<st[%d]:%d ed[%d]:%d>\n",i,st[i],i,ed[i]);
//					printf("<wall lr:%d %d>\n",x,y);
					putchar('0');
					//puts("<case5>");
					return;
				}
			}
		}
	}
	putchar('1');
	return;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
//	freopen("E:\\down\\expand\\expand4.in","r",stdin);
//	freopen("E:\\down\\expand\\expand4.out","w",stdout);
	read(c),read(n),read(m),read(q);
	for(int i=1;i<=n;++i)
		read(A[i]);
	for(int i=1;i<=m;++i)
		read(B[i]);
	solve();
//	for(int i=1;i<=n;++i)
//		printf("<st[%d]:%d ed[%d]:%d>\n",i,st[i],i,ed[i]);
	//puts(">>>");
	for(int i=0,kx,ky;i<q;++i)
	{
		read(kx),read(ky);
		//printf("<%d %d>\n",kx,ky);
		//puts("***");
		for(int j=0,px,vx;j<kx;++j)
		{
			read(px),read(vx);
			A[px]=vx;
			//putchar('-');
		}
		//puts("***");
		for(int j=0,py,vy;j<ky;++j)
		{
			read(py),read(vy);
			B[py]=vy;
			//putchar('-');
		}
		//puts(">>>");
		solve();
	}
	puts("");
	return 0;
}

