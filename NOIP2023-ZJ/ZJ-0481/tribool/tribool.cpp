#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,m;
int aa[100010];
int ans,sum,ans1;
int a[10];
int b[10];
int s1[11],s2[11];
char s0[11];
int main(){
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	cin>>c>>t;
	if(c==3||c==4){
		while(t--){
			ans=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				char v;
				int x;
				scanf("%s%d",&v,&x);
				if(v=='U'){
					aa[x]=1;
				}
				else{
					aa[x]=0;
				}
			}
			for(int i=1;i<=n;i++){
				if(aa[i]==1){
					aa[i]=0;
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	else if(c<=2){
		while(t--){
			ans1=1e9;
			sum=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				scanf("%s",&s0[i]);
				if(s0[i]=='+'||s0[i]=='-'){
					scanf("%d%d",&s1[i],&s2[i]);
				}
				else{
					scanf("%d",&s1[i]);
				}
			}
			if(n==1){
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for(int i=1;i<=m;i++){
						if(s0[i]=='+'){
							b[s1[i]]=b[s2[i]];
						}
						else if(s0[i]=='-'){
							if(b[s2[i]]==1){
								b[s1[i]]=2;
							}
							else if(b[s2[i]]==2){
								b[s1[i]]=1;
							}
							else{
								b[s1[i]]=3;
							}
						}
						else{
							if(s0[i]=='T'){
								b[s1[i]]=1;
							}
							else if(s0[i]=='F'){
								b[s1[i]]=2;
							}
							else{
								b[s1[i]]=3;
							}
						}
					}
					bool f=1;
					for(int i=1;i<=n;i++){
						if(b[i]!=a[i]){
							f=0;
						}
						b[i]=a[i];
					}
					if(f==1){
						sum=0;
						for(int i=1;i<=n;i++){
							b[i]=a[i];
							if(a[i]==3){
								sum++;
							}
						}
						ans1=min(ans1,sum);
					}
				}
			}
			else if(n==2){
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for( a[2]=1;a[2]<=3;a[2]++){
						b[2]=a[2];
						for(int i=1;i<=m;i++){
							if(s0[i]=='+'){
								b[s1[i]]=b[s2[i]];
							}
							else if(s0[i]=='-'){
								if(b[s2[i]]==1){
									b[s1[i]]=2;
								}
								else if(b[s2[i]]==2){
									b[s1[i]]=1;
								}
								else{
									b[s1[i]]=3;
								}
							}
							else{
								if(s0[i]=='T'){
									b[s1[i]]=1;
								}
								else if(s0[i]=='F'){
									b[s1[i]]=2;
								}
								else{
									b[s1[i]]=3;
								}
							}
						}
						bool f=1;
						for(int i=1;i<=n;i++){
							if(b[i]!=a[i]){
								f=0;
							}
							b[i]=a[i];
						}
						if(f==1){
							sum=0;
							for(int i=1;i<=n;i++){
								b[i]=a[i];
								if(a[i]==3){
									sum++;
								}
							}
							ans1=min(ans1,sum);
						}
					}
				}
			}
			else if(n==3){
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for( a[2]=1;a[2]<=3;a[2]++){
						b[2]=a[2];
						for( a[3]=1;a[3]<=3;a[3]++){
							b[3]=a[3];
							for(int i=1;i<=m;i++){
								if(s0[i]=='+'){
									b[s1[i]]=b[s2[i]];
								}
								else if(s0[i]=='-'){
									if(b[s2[i]]==1){
										b[s1[i]]=2;
									}
									else if(b[s2[i]]==2){
										b[s1[i]]=1;
									}
									else{
										b[s1[i]]=3;
									}
								}
								else{
									if(s0[i]=='T'){
										b[s1[i]]=1;
									}
									else if(s0[i]=='F'){
										b[s1[i]]=2;
									}
									else{
										b[s1[i]]=3;
									}
								}
							}
							bool f=1;
							for(int i=1;i<=n;i++){
								if(b[i]!=a[i]){
									f=0;
								}
								b[i]=a[i];
							}
							if(f==1){
								sum=0;
								for(int i=1;i<=n;i++){
									b[i]=a[i];
									if(a[i]==3){
										sum++;
									}
								}
								ans1=min(ans1,sum);
							}
						}
					}
				}
			}
			else if(n==4){
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for( a[2]=1;a[2]<=3;a[2]++){
						b[2]=a[2];
						for( a[3]=1;a[3]<=3;a[3]++){
							b[3]=a[3];
							for( a[4]=1;a[4]<=3;a[4]++){
								b[4]=a[4];
								for(int i=1;i<=m;i++){
									if(s0[i]=='+'){
										b[s1[i]]=b[s2[i]];
									}
									else if(s0[i]=='-'){
										if(b[s2[i]]==1){
											b[s1[i]]=2;
										}
										else if(b[s2[i]]==2){
											b[s1[i]]=1;
										}
										else{
											b[s1[i]]=3;
										}
									}
									else{
										if(s0[i]=='T'){
											b[s1[i]]=1;
										}
										else if(s0[i]=='F'){
											b[s1[i]]=2;
										}
										else{
											b[s1[i]]=3;
										}
									}
								}
								bool f=1;
								for(int i=1;i<=n;i++){
									if(b[i]!=a[i]){
										f=0;
									}
									b[i]=a[i];
								}
								if(f==1){
									sum=0;
									for(int i=1;i<=n;i++){
										b[i]=a[i];
										if(a[i]==3){
											sum++;
										}
									}
									ans1=min(ans1,sum);
								}
							}
						}
					}
				}
			}
			else if(n==5){
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for( a[2]=1;a[2]<=3;a[2]++){
						b[2]=a[2];
						for( a[3]=1;a[3]<=3;a[3]++){
							b[3]=a[3];
							for( a[4]=1;a[4]<=3;a[4]++){
								b[4]=a[4];
								for( a[5]=1;a[5]<=3;a[5]++){
									b[5]=a[5];
									for(int i=1;i<=m;i++){
										if(s0[i]=='+'){
											b[s1[i]]=b[s2[i]];
										}
										else if(s0[i]=='-'){
											if(b[s2[i]]==1){
												b[s1[i]]=2;
											}
											else if(b[s2[i]]==2){
												b[s1[i]]=1;
											}
											else{
												b[s1[i]]=3;
											}
										}
										else{
											if(s0[i]=='T'){
												b[s1[i]]=1;
											}
											else if(s0[i]=='F'){
												b[s1[i]]=2;
											}
											else{
												b[s1[i]]=3;
											}
										}
									}
									bool f=1;
									for(int i=1;i<=n;i++){
										if(b[i]!=a[i]){
											f=0;
										}
										b[i]=a[i];
									}
									if(f==1){
										sum=0;
										for(int i=1;i<=n;i++){
											b[i]=a[i];
											if(a[i]==3){
												sum++;
											}
										}
										ans1=min(ans1,sum);
									}
								}//5
							}//4
						}//3
					}//2
				}//1
			}
			else if(n==6){
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for( a[2]=1;a[2]<=3;a[2]++){
						b[2]=a[2];
						for( a[3]=1;a[3]<=3;a[3]++){
							b[3]=a[3];
							for( a[4]=1;a[4]<=3;a[4]++){
								b[4]=a[4];
								for( a[5]=1;a[5]<=3;a[5]++){
									b[5]=a[5];
									for( a[6]=1;a[6]<=3;a[6]++){
										b[6]=a[6];
										for(int i=1;i<=m;i++){
											if(s0[i]=='+'){
												b[s1[i]]=b[s2[i]];
											}
											else if(s0[i]=='-'){
												if(b[s2[i]]==1){
													b[s1[i]]=2;
												}
												else if(b[s2[i]]==2){
													b[s1[i]]=1;
												}
												else{
													b[s1[i]]=3;
												}
											}
											else{
												if(s0[i]=='T'){
													b[s1[i]]=1;
												}
												else if(s0[i]=='F'){
													b[s1[i]]=2;
												}
												else{
													b[s1[i]]=3;
												}
											}
										}
										bool f=1;
										for(int i=1;i<=n;i++){
											if(b[i]!=a[i]){
												f=0;
											}
											b[i]=a[i];
										}
										if(f==1){
											sum=0;
											for(int i=1;i<=n;i++){
												b[i]=a[i];
												if(a[i]==3){
													sum++;
												}
											}
											ans1=min(ans1,sum);
										}
									}//6
								}//5
							}//4
						}//3
					}//2
				}//1
			}
			else if(n==7){
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for( a[2]=1;a[2]<=3;a[2]++){
						b[2]=a[2];
						for( a[3]=1;a[3]<=3;a[3]++){
							b[3]=a[3];
							for( a[4]=1;a[4]<=3;a[4]++){
								b[4]=a[4];
								for( a[5]=1;a[5]<=3;a[5]++){
									b[5]=a[5];
									for( a[6]=1;a[6]<=3;a[6]++){
										b[6]=a[6];
										for( a[7]=1;a[7]<=3;a[7]++){
											b[7]=a[7];
											for(int i=1;i<=m;i++){
												if(s0[i]=='+'){
													b[s1[i]]=b[s2[i]];
												}
												else if(s0[i]=='-'){
													if(b[s2[i]]==1){
														b[s1[i]]=2;
													}
													else if(b[s2[i]]==2){
														b[s1[i]]=1;
													}
													else{
														b[s1[i]]=3;
													}
												}
												else{
													if(s0[i]=='T'){
														b[s1[i]]=1;
													}
													else if(s0[i]=='F'){
														b[s1[i]]=2;
													}
													else{
														b[s1[i]]=3;
													}
												}
											}
											bool f=1;
											for(int i=1;i<=n;i++){
												if(b[i]!=a[i]){
													f=0;
												}
												b[i]=a[i];
											}
											if(f==1){
												sum=0;
												for(int i=1;i<=n;i++){
													b[i]=a[i];
													if(a[i]==3){
														sum++;
													}
												}
												ans1=min(ans1,sum);
											}
										}//7
									}//6
								}//5
							}//4
						}//3
					}//2
				}//1
			}
			else if(n==8){
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for( a[2]=1;a[2]<=3;a[2]++){
						b[2]=a[2];
						for( a[3]=1;a[3]<=3;a[3]++){
							b[3]=a[3];
							for( a[4]=1;a[4]<=3;a[4]++){
								b[4]=a[4];
								for( a[5]=1;a[5]<=3;a[5]++){
									b[5]=a[5];
									for( a[6]=1;a[6]<=3;a[6]++){
										b[6]=a[6];
										for( a[7]=1;a[7]<=3;a[7]++){
											b[7]=a[7];
											for( a[8]=1;a[8]<=3;a[8]++){
												b[8]=a[8];
												for(int i=1;i<=m;i++){
													if(s0[i]=='+'){
														b[s1[i]]=b[s2[i]];
													}
													else if(s0[i]=='-'){
														if(b[s2[i]]==1){
															b[s1[i]]=2;
														}
														else if(b[s2[i]]==2){
															b[s1[i]]=1;
														}
														else{
															b[s1[i]]=3;
														}
													}
													else{
														if(s0[i]=='T'){
															b[s1[i]]=1;
														}
														else if(s0[i]=='F'){
															b[s1[i]]=2;
														}
														else{
															b[s1[i]]=3;
														}
													}
												}
												bool f=1;
												for(int i=1;i<=n;i++){
													if(b[i]!=a[i]){
														f=0;
													}
													b[i]=a[i];
												}
												if(f==1){
													sum=0;
													for(int i=1;i<=n;i++){
														b[i]=a[i];
														if(a[i]==3){
															sum++;
														}
													}
													ans1=min(ans1,sum);
												}
											}//8
										}//7
									}//6
								}//5
							}//4
						}//3
					}//2
				}//1
			}
			else if(n==9){
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for( a[2]=1;a[2]<=3;a[2]++){
						b[2]=a[2];
						for( a[3]=1;a[3]<=3;a[3]++){
							b[3]=a[3];
							for( a[4]=1;a[4]<=3;a[4]++){
								b[4]=a[4];
								for( a[5]=1;a[5]<=3;a[5]++){
									b[5]=a[5];
									for( a[6]=1;a[6]<=3;a[6]++){
										b[6]=a[6];
										for( a[7]=1;a[7]<=3;a[7]++){
											b[7]=a[7];
											for( a[8]=1;a[8]<=3;a[8]++){
												b[8]=a[8];
												for( a[9]=1;a[9]<=3;a[9]++){
													b[9]=a[9];
													for(int i=1;i<=m;i++){
														if(s0[i]=='+'){
															b[s1[i]]=b[s2[i]];
														}
														else if(s0[i]=='-'){
															if(b[s2[i]]==1){
																b[s1[i]]=2;
															}
															else if(b[s2[i]]==2){
																b[s1[i]]=1;
															}
															else{
																b[s1[i]]=3;
															}
														}
														else{
															if(s0[i]=='T'){
																b[s1[i]]=1;
															}
															else if(s0[i]=='F'){
																b[s1[i]]=2;
															}
															else{
																b[s1[i]]=3;
															}
														}
													}
													bool f=1;
													for(int i=1;i<=n;i++){
														if(b[i]!=a[i]){
															f=0;
														}
														b[i]=a[i];
													}
													if(f==1){
														sum=0;
														for(int i=1;i<=n;i++){
															b[i]=a[i];
															if(a[i]==3){
																sum++;
															}
														}
														ans1=min(ans1,sum);
													}
												}//9
											}//8
										}//7
									}//6
								}//5
							}//4
						}//3
					}//2
				}//1
			}
			else{
				for( a[1]=1;a[1]<=3;a[1]++){
					b[1]=a[1];
					for( a[2]=1;a[2]<=3;a[2]++){
						b[2]=a[2];
						for( a[3]=1;a[3]<=3;a[3]++){
							b[3]=a[3];
							for( a[4]=1;a[4]<=3;a[4]++){
								b[4]=a[4];
								for( a[5]=1;a[5]<=3;a[5]++){
									b[5]=a[5];
									for( a[6]=1;a[6]<=3;a[6]++){
										b[6]=a[6];
										for( a[7]=1;a[7]<=3;a[7]++){
											b[7]=a[7];
											for( a[8]=1;a[8]<=3;a[8]++){
												b[8]=a[8];
												for( a[9]=1;a[9]<=3;a[9]++){
													b[9]=a[9];
													for( a[0]=1;a[0]<=3;a[0]++){
														b[0]=a[0];
														for(int i=1;i<=m;i++){
															if(s0[i]=='+'){
																b[s1[i]%10]=b[s2[i]%10];
															}
															else if(s0[i]=='-'){
																if(b[s2[i]%10]==1){
																	b[s1[i]%10]=2;
																}
																else if(b[s2[i]%10]==2){
																	b[s1[i]%10]=1;
																}
																else{
																	b[s1[i]%10]=3;
																}
															}
															else{
																if(s0[i]=='T'){
																	b[s1[i]%10]=1;
																}
																else if(s0[i]=='F'){
																	b[s1[i]%10]=2;
																}
																else{
																	b[s1[i]%10]=3;
																}
															}
														}
														bool f=1;
														for(int i=0;i<=n;i++){
															if(b[i]!=a[i]){
																f=0;
															}
															b[i]=a[i];
														}
														if(f==1){
															sum=0;
															for(int i=0;i<=n;i++){
																b[i]=a[i];
																if(a[i]==3){
																	sum++;
																}
															}
															ans1=min(ans1,sum);
														}
													}//10
												}//9
											}//8
										}//7
									}//6
								}//5
							}//4
						}//3
					}//2
				}//1
			}
			printf("%d\n",ans1);
		}
	}
	else{
		while(t--){
			ans=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=m;i++){
				char v;
				int x,y;
				scanf("%s%d",&v,&x);
				if(v=='+'||v=='-') scanf("%d",&y);
				if(v=='U'){
					aa[x]=1;
				}
				else{
					aa[x]=0;
				}
			}
			for(int i=1;i<=n;i++){
				if(aa[i]==1){
					aa[i]=0;
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
