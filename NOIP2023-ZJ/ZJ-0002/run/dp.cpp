#include<bits/stdc++.h>
using namespace std;
mt19937 rd(time(0)+1);
int Random(int l,int r){return uniform_int_distribution<int>(l,r)(rd);}
int main(){
	ofstream fout;
	while(1){
		fout.open("run.in");
		int cid=0,T=10;
		fout<<cid<<' '<<T<<'\n';
		while(T--){
			int n,m,K,d;
			n=Random(10,20);
			m=Random(100,100);
			K=Random(1,n);
			int V=1000'000'000;
			d=Random(1,V);
			fout<<n<<' '<<m<<' '<<K<<' '<<d<<'\n';
			int i;
			for(i=1;i<=m;++i){
				int l,r,v;
				l=Random(1,n),r=Random(1,n),v=Random(1,V);
				if(l>r) swap(l,r);
				fout<<r<<' '<<r-l+1<<' '<<v<<'\n';
			}
		}
		fout.close();
		system("./run");
		system("./bl < run.in > run.bl");
		if(system("diff run.out run.bl")) break;
		cerr<<"success\n";
	}
	return 0;
}
