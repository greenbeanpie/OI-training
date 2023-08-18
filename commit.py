import requests
import json
problem_name=input("请输入题号\n")

param={"code":"","enableO2":1,"lang":0}
header={"Cookie":"__client_id=4488cb875a0b7b3dbbf00172abf123ce2381ab21; _uid=499156","Referer":"https://www.luogu.com.cn/problem/"+problem_name,"User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.203"}
response=requests.post("https://www.luogu.com.cn/fe/api/problem/submit/"+problem_name,params=param,headers=header)
ans=json.loads(response.text)
rid=ans["rid"]
