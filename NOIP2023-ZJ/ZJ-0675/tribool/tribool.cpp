#include<bits/stdc++.h>

using namespace std;

int c,t;
int n,m;
// U=2,T=1,F=0
int s[100010];
vector<int>ans;

struct node{
	char c;
	int x;
	int v;
}p[100010];

bool check(){
	int s1[100010];
	for(int i=1;i<=n;i++){
		s1[i]=s[i];
	}
	for(int i=1;i<=m;i++){
		if(p[i].c=='T')s1[p[i].x]=1;
		if(p[i].c=='F')s1[p[i].x]=0;
		if(p[i].c=='U')s1[p[i].x]=2;
		if(p[i].c=='+')s1[p[i].x]=s1[p[i].v];
		if(p[i].c=='-'){
			if(s[p[i].v]==0)s1[p[i].x]=1;
			if(s[p[i].v]==1)s1[p[i].x]=0;
			if(s[p[i].v]==2)s1[p[i].x]=2;
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]!=s1[i])return 0;
	}
	return 1;
}

int an(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==2)ans++;
	}
	return ans;
}


int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	while(t--){
		for(int i=1;i<=m;i++){
			p[i].v=0;
			p[i].x=0;
		}
		cin>>n>>m;
		for(int i=1,a,b;i<=m;i++){
			char c;
			a=0;b=0;
			cin>>c;
			if(c=='U' || c=='T' || c=='F')cin>>a;
			else cin>>a>>b;
			node op;
			op.c=c;
			op.v=b;
			op.x=a;
			p[i]=op;
		}
		if(n>=1){
			for(int a=0;a<=2;a++){
				if(n>=2){
					for(int b=0;b<=2;b++){
						if(n>=3){
							for(int c=0;c<=2;c++){
								if(n>=4){
									for(int d=0;d<=2;d++){
										if(n>=5){
											for(int e=0;e<=2;e++){
												if(n>=6){
													for(int f=0;f<=2;f++){
														if(n>=7){
															for(int g=0;g<=2;g++){
																if(n>=8){
																	for(int h=0;h<=2;h++){
																		if(n>=9){
																			for(int i=0;i<=2;i++){
																				if(n>=10){
																					for(int j=0;j<=2;j++){
																						s[1]=a;
																						s[2]=b;
																						s[3]=c;
																						s[4]=d;
																						s[5]=e;
																						s[6]=f;
																						s[7]=g;
																						s[8]=h;
																						s[9]=i;
																						s[10]=j;
																						if(check())ans.push_back(an());
																					}
																				}
																				s[1]=a;
																				s[2]=b;
																				s[3]=c;
																				s[4]=d;
																				s[5]=e;
																				s[6]=f;
																				s[7]=g;
																				s[8]=h;
																				s[9]=i;
																				if(check())ans.push_back(an());
																			}
																		}
																		s[1]=a;
																		s[2]=b;
																		s[3]=c;
																		s[4]=d;
																		s[5]=e;
																		s[6]=f;
																		s[7]=g;
																		s[8]=h;
																		if(check())ans.push_back(an());
																	}
																}
																s[1]=a;
																s[2]=b;
																s[3]=c;
																s[4]=d;
																s[5]=e;
																s[6]=f;
																s[7]=g;
																if(check())ans.push_back(an());
															}
														}
														s[1]=a;
														s[2]=b;
														s[3]=c;
														s[4]=d;
														s[5]=e;
														s[6]=f;
														if(check())ans.push_back(an());
													}
												}
												s[1]=a;
												s[2]=b;
												s[3]=c;
												s[4]=d;
												s[5]=e;
												if(check())ans.push_back(an());
											}
										}
										s[1]=a;
										s[2]=b;
										s[3]=c;
										s[4]=d;
										if(check())ans.push_back(an());
									}
								}
								s[1]=a;
								s[2]=b;
								s[3]=c;
								if(check())ans.push_back(an());
							}
						}
						s[1]=a;
						s[2]=b;
						if(check())ans.push_back(an());
					}
				}
				s[1]=a;
				if(check())ans.push_back(an());	
			}
		}
		int minn=1000000;
		for(int i=1;i<=ans.size()-1;i++){
			minn=min(minn,ans[i]);
		}
		cout<<minn<<endl;
	}
}
