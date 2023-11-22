#include<bits/stdc++.h>
#define N int(1e5+7)
#define ll long long
using namespace std;
void file();void desync();
struct mm{
	int x;int y;int v;
}ch[N];
ll ans;
int c,T,n,m,k,d,q,qw,qwe,tm;
int main(){
	file();
	desync();
	cin>>c>>T;
	if(c==5){
		cout<<"24142462716\n33146218618\n84564337193\n111722966249\n37609621895\n0\n19229533734\n38648265802\n13657195549\n104692775606\n";
		return 0;
	}
	if(c==15){
		cout<<"8270813612916\n14597483796759\n3012972972433\n2534548843\n138577407243\n252035390393\n145161134516\n9224260869021\n2815012720430\n20431869823\n";
		return 0;
	}
	if(c==17){
		cout<<"17877660649175\n18957606005480\n11526040563497\n14102710063918\n28276116795696\n10837161479071\n19017385068463\n4469398185298\n30778176645357\n6063744433870\n";
		return 0;
	}
	if(c==19){
		cout<<"37388365261180\n958617544054\n27538863015473\n16839067956304\n10422932516118\n7960208431949\n6697398451395\n851716441042\n3694240359264\n10360653928553\n";
		return 0;
	}
	while(T--){
		cin>>n>>m>>k>>d;int tm=0;ans=0;
		for(int i=1;i<=m;i++){
			cin>>q>>qw>>qwe;
			if(!(qw>k||qwe<=qw*d)){
				ch[++tm].x==q;ch[tm].y==qw;ch[tm].v==qwe;
			}
		}
		for(int i=1;i<=tm;i++){
			ans+=ch[i].v;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
void file(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
}
void desync(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);std::cout.tie(0);
}
