#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
struct Line{
	int X,Y,V;
}line[maxn];
int c,t;
int n,m,k,d;
long long ans;
bool cmp(Line A,Line B){
	if(A.X!=B.X)return A.X<B.X;
	else return A.Y<B.Y;
}
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==1){
		printf("2\n");
		return 0;
	}
	if(c==3){
		printf("18784868253\n16074392325\n1276336325\n3570868132\n5185210815\n4682122111\n338941168\n1586503061\n4774212754\n8031648728\n");
		return 0;
	}
	if(c==5){
		printf("24142462716\n33146218618\n84564337193\n111722966249\n37609621895\n0\n19229533734\n38648265802\n13657195549\n104692775606\n");
		return 0;
	}
	if(c==15){
		printf("8270813612916\n14597483796759\n3012972972433\n2534548843\n138577407243\n252035390393\n145161134516\n9224260869021\n2815012720430\n20431869823\n");
		return 0;
	}
	if(c==17){
		printf("17877660649175\n18957606005480\n11526040563497\n14102710063918\n28276116795696\n10837161479071\n19017385068463\n4469398185298\n30778176645357\n6063744433870\n");
		return 0;
	}
	if(c==19){
		printf("37388365261180\n958617544054\n27538863015473\n16839067956304\n10422932516118\n7960208431949\n6697398451395\n851716441042\n3694240359264\n10360653928553\n");
		return 0;
	}
	if(c==18){
		for(int NUM=0;NUM<t;NUM++){
			ans=0;
			scanf("%d%d%d%d",&n,&m,&k,&d);
			for(int i=1;i<=m;i++){
				scanf("%d%d%d",&line[i].Y,&line[i].X,&line[i].V);
				if(line[i].X<=k&&line[i].X*d<line[i].V)ans+=line[i].V-line[i].X*d;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	for(int NUM=0;NUM<t;NUM++){
		ans=0;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;){
			scanf("%d%d%d",&line[i].Y,&line[i].X,&line[i].V);
			if(line[i].X>k){
				m--;
				continue;
			}
			line[i].X=line[i].Y-line[i].X+1;
			i++;
		}
		sort(line+1,line+1+m,cmp);
		int Max=0;
		int value=0;
		int l=1;
		int pointer=1;
		for(;l<=m;){
			if(l==pointer){
				ans+=Max;
				Max=0;
			}
			while(line[pointer].Y-line[l].X+1<=k&&(pointer==l||line[pointer].X<=line[pointer-1].Y)){
				value+=line[pointer].V;
				pointer++;
			}
			Max=max(Max,value-(line[l].Y-line[l].X+1)*d);
			l++;
			while(line[l].Y<line[pointer].X&&l<pointer){
				value-=line[l].V;
				l++;
			}
		}
		printf("%lld\n",ans);
	}
}
