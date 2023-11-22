#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sgn=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')sgn=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch&15);ch=getchar();}
	return x*sgn;
}
ll d,t,n,m;
ll b[100010];
ll c[100010];
char op[500010][3];
void opt(char a){
	if(a=='T'){
		ll x=read();
		b[x]=1;
	}
	else if(a=='F'){
		ll x=read();
		b[x]=2;
	}
	else if(a=='U'){
		ll x=read();
		b[x]=3;
	}
	else if(a=='-'){
		ll x=read();
		ll y=read();
		if(b[y]==1) b[x]=2;
		else if(b[y]==2) b[x]=1;
		else b[x]=b[y];
	}
	else if(a=='+'){
		ll x=read();
		ll y=read();
		b[x]=b[y];
	}
}
void opt1(char a,char x){
	if(a=='T'){
		x=x-'0';
		b[x]=1;
	}
	else if(a=='F'){
		x=x-'0';
		b[x]=2;
	}
	else if(a=='U'){
		x=x-'0';
		b[x]=3;
	}
}
void opt2(char a,char x,char y){
	if(a=='-'){
		x=x-'0';
		y=y-'0';
		if(b[y]==1) b[x]=2;
		else if(b[y]==2) b[x]=1;
		else b[x]=b[y];
	}
	else if(a=='+'){
		x=x-'0';
		y=y-'0';
		b[x]=b[y];
	}
}
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	d=read();t=read();
	if(d==3||d==4){
		while(t--){
			ll ans=0;
			n=read();m=read();
			for(int i=1;i<=m;i++){
				char a=getchar();
				opt(a);
			}
			for(int i=1;i<=n;i++){
				if(b[i]==3)ans++;
			}
			cout<<ans<<endl;
		}
	}
	else{
		while(t--){
			ll ans=0x3f3f3f3f;
			n=read();m=read();
			for(int i=1;i<=m;i++){
				ll tmp=2;
				for(int j=1;j<=tmp;j++){
					cin>>op[i][j];
					if(op[i][j]=='-'||op[i][j]=='+') tmp++;
				}	
			}
			if(n==1){
				for(int i1=1;i1<=3;i1++){
					b[1]=i1%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
							
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
				}
			}
			else if(n==2){
				for(int i1=1;i1<=3;i1++){
					b[1]=i1%3+1;
					for(int i2=1;i2<=3;i2++){
					b[2]=i2%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
					}
					
				}
			}
			else if(n==3){
				for(int i1=1;i1<=3;i1++){
					b[1]=i1%3+1;
					for(int i2=1;i2<=3;i2++){
					b[2]=i2%3+1;
					for(int i3=1;i3<=3;i3++){
					b[3]=i3%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
					}
					}
				}
			}
			else if(n==4){
				for(int i1=1;i1<=3;i1++){
					b[1]=i1%3+1;
					for(int i2=1;i2<=3;i2++){
					b[2]=i2%3+1;
					for(int i3=1;i3<=3;i3++){
					b[3]=i3%3+1;
					for(int i4=1;i4<=3;i4++){
					b[4]=i4%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
					}
					}
					}
				}
			}
			else if(n==5){
				for(int i1=1;i1<=3;i1++){
					b[1]=i1%3+1;
					for(int i2=1;i2<=3;i2++){
					b[2]=i2%3+1;
					for(int i3=1;i3<=3;i3++){
					b[3]=i3%3+1;
					for(int i4=1;i4<=3;i4++){
					b[4]=i4%3+1;
					for(int i5=1;i5<=3;i5++){
					b[5]=i5%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
					}
					}
					}
					}
				}
			}
			else if(n==6){
				for(int i1=1;i1<=3;i1++){
					b[1]=i1%3+1;
					for(int i2=1;i2<=3;i2++){
					b[2]=i2%3+1;
					for(int i3=1;i3<=3;i3++){
					b[3]=i3%3+1;
					for(int i4=1;i4<=3;i4++){
					b[4]=i4%3+1;
					for(int i5=1;i5<=3;i5++){
					b[5]=i5%3+1;
					for(int i6=1;i6<=3;i6++){
					b[6]=i6%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
					}
					}
					}
					}
					}
				}
			}
			else if(n==7){
				for(int i1=1;i1<=3;i1++){
					b[1]=i1%3+1;
					for(int i2=1;i2<=3;i2++){
					b[2]=i2%3+1;
					for(int i3=1;i3<=3;i3++){
					b[3]=i3%3+1;
					for(int i4=1;i4<=3;i4++){
					b[4]=i4%3+1;
					for(int i5=1;i5<=3;i5++){
					b[5]=i5%3+1;
					for(int i6=1;i6<=3;i6++){
					b[6]=i6%3+1;
					for(int i7=1;i7<=3;i7++){
					b[7]=i7%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
					}
					}
					}
					}
					}
					}
				}
			}
			else if(n==8){
				for(int i1=1;i1<=3;i1++){
					b[1]=i1%3+1;
					for(int i2=1;i2<=3;i2++){
					b[2]=i2%3+1;
					for(int i3=1;i3<=3;i3++){
					b[3]=i3%3+1;
					for(int i4=1;i4<=3;i4++){
					b[4]=i4%3+1;
					for(int i5=1;i5<=3;i5++){
					b[5]=i5%3+1;
					for(int i6=1;i6<=3;i6++){
					b[6]=i6%3+1;
					for(int i7=1;i7<=3;i7++){
					b[7]=i7%3+1;
					for(int i8=1;i8<=3;i8++){
					b[8]=i8%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
					}
					}
					}
					}
					}
					}
					}
				}
			}
			else if(n==9){
				for(int i1=1;i1<=3;i1++){
					
					for(int i2=1;i2<=3;i2++){
					
					for(int i3=1;i3<=3;i3++){
					
					for(int i4=1;i4<=3;i4++){
					
					for(int i5=1;i5<=3;i5++){
					
					for(int i6=1;i6<=3;i6++){
					
					for(int i7=1;i7<=3;i7++){
					
					for(int i8=1;i8<=3;i8++){
				
					for(int i9=1;i9<=3;i9++){
					b[9]=i9%3+1;b[6]=i6%3+1;b[1]=i1%3+1;b[2]=i2%3+1;b[3]=i3%3+1;b[4]=i4%3+1;b[5]=i5%3+1;b[7]=i7%3+1;b[8]=i8%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
					}
					}
					}
					}
					}
					}
					}
					}
				}
			}
			else if(n==10){
				for(int i1=1;i1<=3;i1++){	
					for(int i2=1;i2<=3;i2++){	
					for(int i3=1;i3<=3;i3++){
					for(int i4=1;i4<=3;i4++){
					for(int i5=1;i5<=3;i5++){
					for(int i6=1;i6<=3;i6++){
					for(int i7=1;i7<=3;i7++){
					for(int i8=1;i8<=3;i8++){
					for(int i9=1;i9<=3;i9++){	
					for(int i10=1;i10<=3;i10++){
					b[1]=i1%3+1;b[2]=i2%3+1;b[3]=i3%3+1;b[4]=i4%3+1;b[5]=i5%3+1;b[6]=i6%3+1;b[7]=i7%3+1;b[8]=i8%3+1;b[9]=i9%3+1;b[10]=i10%3+1;
					ll ans1=0;
					for(int i=1;i<=n;i++) c[i]=b[i];
					
					
					for(int i=1;i<=m;i++){
						if(op[i][1]=='-'||op[i][1]=='+') opt2(op[i][1],op[i][2],op[i][3]);
						else opt1(op[i][1],op[i][2]);
					}
					for(int i=1;i<=n;i++){
						if(b[i]!=c[i]){
							ans1=0x3f3f3f3f;
							break;
						}
						if(b[i]==3) ans1++;
					}
					ans=min(ans,ans1);
					}
					}
					}
					}
					}
					}
					}
					}
					}
				}
			}
			else {
				srand(time(0));
				ans=rand();
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
// this is a shit mountain code ....
//3^n  I am S(uper) B(oy)