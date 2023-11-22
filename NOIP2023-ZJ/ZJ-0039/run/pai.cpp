#include<bits/stdc++.h>
using namespace std;

mt19937 eng;
int turn;

int main()
{
	loop:
	ofstream inf("run.in");
	int T=10;
	inf<<0<<' '<<T<<'\n';
	while(T--)
	{
		int n=eng()%18+1,m=eng()%18+1,k=eng()%n+1;
		uniform_int_distribution<int>val(1,1e9),pos(1,n);
		inf<<n<<' '<<m<<' '<<k<<' '<<val(eng)<<'\n';
		while(m--)
		{
			int l=pos(eng),r=pos(eng);
			if(l>r) swap(l,r);
			inf<<r<<' '<<r-l+1<<' '<<val(eng)<<'\n';
		}
	}
	inf.close();
	system("./run && ./run2");
	if(!system("diff run.out run2.out"))
	{
		turn++;
		if(turn%100==0) cout<<turn<<endl;
		goto loop;
	}
	return 0;
}
