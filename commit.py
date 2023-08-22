# encoding=utf-8
import os
import requests
import json
problem_name=input("请输入题号\n")
work_dir="D:\\OI-training\\"
if(problem_name[0]=='P'):
	os.chdir(work_dir+"Luogu\\"+problem_name[0:2]+"\\"+problem_name[0:3]+"\\"+problem_name+"\\")
file=open(problem_name+".cpp","r+")
param={"code":file.read(),"enableO2":1,"lang":0}
header={"Cookie":"__client_id=4488cb875a0b7b3dbbf00172abf123ce2381ab21; _uid=499156","Referer":"https://www.luogu.com.cn/problem/"+problem_name,"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.203","X-Csrf-Token":"1692662667:moEtnmWDZe+3r6VwZVdVi+tq9NsOOmsuq2m+/POSUTY="}

response=requests.post("https://www.luogu.com.cn/fe/api/problem/submit/"+problem_name,params=param,headers=header)
ans=json.loads(response.text)
rid=ans["rid"]
os.system("start \"C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe\" https://www.luogu.com.cn/record/"+rid)