#include "testlib.h"
#include <bits/stdc++.h>
#include <bits/random.h>

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    //double pans = ouf.readDouble();
    //double jans = ans.readDouble();
	std::string a=ans.readString();
	std::string o=ouf.readString();
	int in=inf.readReal();
	std::random_device rd;
	std::mt19937 random(rd());
	if(a[in-1]==o[in-1]){
		quitf(_ok,"OvO,YOU AK IOI!");
	}
	else if(o[in-1]=='?'&&random()%4==0){
		quitf(_ok,"OvO,YOU HAVE A GOOD LUCK!");
	}
	else if(o[in-1]=='?'){
		quitf(_wa,"QwQ,you don't have a good luck.");
	}
	else{
		quitf(_wa,"The correct answer to question %d is %c,but yours is %c",in,a[in-1],o[in-1]);
	}
	return 0;
}