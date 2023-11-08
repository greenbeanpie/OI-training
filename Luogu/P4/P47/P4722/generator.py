import cyaron, random

print(1200, 120000, 1, 1200)
print(cyaron.Graph.UDAG(1200, 120000, weight_limit=(5, 100)).to_str())
