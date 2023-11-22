#include<bits/stdc++.h>
using namespace std;
int x[100001],y[100001],px[100001],py[100001],xx[100001],yy[100001];
int check(int n,int m)
{
	int li,lj,tl,ri,rj,tr;
	bool f1,f2;
	f1=x[1]>y[1]&&x[n]>y[m];
	f2=x[1]<y[1]&&x[n]<y[m];
	if(!(f1||f2)) return 0;
	if(f1)
	{
		li=1,lj=1,tl=0;
		while(li<=n&&lj<=m)
		{
			if(x[li]>y[lj]) lj++,tl++;
			else
			{
				li++,tl--;
				if(tl<0)
				return 0;
			}
		}
		ri=n,rj=m,tr=0;
		while(ri>=1&&rj>=1)
		{
			if(x[ri]>y[rj]) ri--,tr++;
			else
			{
				rj--,tr--;
				if(tr<0)
				return 0;
			}
		}
		return 1;
	}
	if(f2)
	{
		lj=1,li=1,tl=0;
		while(lj<=m&&li<=n)
		{
			if(y[lj]>x[li]) li++,tl++;
			else
			{
				lj++,tl--;
				if(tl<0)
				return 0;
			}
		}
		ri=n,rj=m,tr=0;
		while(rj>=1&&ri>=1)
		{
			if(y[rj]>x[ri]) rj--,tr++;
			else
			{
				ri--,tr--;
				if(tr<0)
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int c,n,m,q,kx,ky,vx,vy,i,j;
	cin>>c>>n>>m>>q;
	for(i=1;i<=n;i++)
	cin>>x[i];
	for(j=1;j<=m;j++)
	cin>>y[j];
	printf("%d",check(n,m));
	while(q--)
	{
		cin>>kx>>ky;
		for(i=1;i<=kx;i++)
		{
			cin>>px[i]>>vx;
			xx[px[i]]=x[px[i]];
			x[px[i]]=vx;
		}
		for(j=1;j<=ky;j++)
		{
			cin>>py[j]>>vy;
			yy[py[j]]=y[py[j]];
			y[py[j]]=vy;
		}
//		for(i=1;i<=n;i++)
//		printf("%d%c",x[i]," \n"[i==n]);
//		for(j=1;j<=m;j++)
//		printf("%d%c",y[j]," \n"[j==m]);
		printf("%d",check(n,m));
		for(i=1;i<=kx;i++)
		x[px[i]]=xx[px[i]];
		for(j=1;j<=ky;j++)
		y[py[j]]=yy[py[j]];
	}
	printf("\n");
	return 0;
}

//8 6 9
//1 7 4
//1 4 0 3 True [sample 1]

//8 0 9
//1 7 4
//1 4 2 0 False

//8 6 9
//1 10 4
//4 2 0 3 False

//8 4 9
//1 7 4
//1 4 0 1 True

//8 6 9
//1 8 4
//3 4 0 3 True

// ???

// 950 922 880 966 834 909
// 918 930 791 956 941 845
// 791 834 845 880 909 918 922 930 941 950 956 966
// 1   2   3   4   5   6   7   8   9   10  11  12
// 10 7 4 12 2 5
// 6  8 1 11 9 3 
// 4 7 0 3 False ? Solved

// 908 747 695 912 681 855
// 741 725 753 615 827 688
// 615 681 688 695 725 741 747 753 827 855 908 912
// 1   2   3   4   5   6   7   8   9   10  11  12
// 11 7 4 12 2 10
// 6  5 8 1  9 3
// Give up. goto T2 & T4.

