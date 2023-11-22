#! /usr/bin/python3
# encoding=utf-8

import cyaron

print(4,8,1)

print(cyaron.Graph.DAG(4,8,weight_limit = 10))