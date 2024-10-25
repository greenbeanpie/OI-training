# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

import pandas as pd
df1 = pd.read_excel("浙江省2022年普通高校招生普通类第一段平行投档分数线表.xls")
df2 = pd.read_excel("浙江省2023年普通高校招生普通类第一段平行投档分数线表.xls")
df3 = pd.read_excel("浙江省2024年普通高校招生普通类第一段平行投档分数线表.xls")

res = pd.merge(df3,df2,on=["学校名称","专业名称"],suffixes=("2024","2023"),how="outer").merge(df1,how="outer",on=["学校名称","专业名称"],suffixes=("","2022"))
res.to_excel("temp.xlsx")
