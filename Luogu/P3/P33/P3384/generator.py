import random, os
from cyaron import *


work_dir="D:\\OI-training\\"
problem_name="P3384"
if(problem_name[0]=='P'):
	os.chdir(work_dir+"Luogu\\"+problem_name[0:2]+"\\"+problem_name[0:3]+"\\"+problem_name+"\\")
input=open(problem_name+".in","w+")
n=10
tree = Graph.tree(n,weight_limit=(1,10))
input.write(tree.to_str(shuffle=True))
input.close();