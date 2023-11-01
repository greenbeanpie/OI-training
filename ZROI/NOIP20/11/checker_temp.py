import os

filename = "value"

for i in range(1,21):
	os.system("./"+filename+"_TJ < "+filename+str(i)+".in > "+filename+str(i)+".out")