#include<bits/stdc++.h>
using namespace std;

mt19937 eng;
int turn,x[100000],y[100000];

int main()
{
	loop:
	ofstream inf("expand.in");
	int i,n=eng()%2000+1,m=eng()%2000+1,q=60;
	uniform_int_distribution<int>val(1,1e9-1);
	inf<<0<<' '<<n<<' '<<m<<' '<<q<<'\n';
	for(i=1;i<=n;i++) inf<<val(eng)<<" \n"[i==n],x[i]=i;
	for(i=1;i<=m;i++) inf<<val(eng)<<" \n"[i==m],y[i]=i;
	while(q--)
	{
		shuffle(x+1,x+n+1,eng);
		shuffle(y+1,y+m+1,eng);
		int kx=eng()%(n+1),ky=eng()%(m+1);
		inf<<kx<<' '<<ky<<'\n';
		for(i=1;i<=kx;i++) inf<<x[i]<<' '<<val(eng)<<'\n';
		for(i=1;i<=ky;i++) inf<<y[i]<<' '<<val(eng)<<'\n';
	}
	inf.close();
	system("./expand && ./expand2");
	if(!system("diff expand.out expand2.out"))
	{
		turn++;
		if(turn%100==0) cout<<turn<<endl;
		goto loop;
	}
	return 0;
}
