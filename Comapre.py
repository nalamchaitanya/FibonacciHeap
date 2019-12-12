import os
import matplotlib.pyplot as plt

def getResults():
	os.system('make clean')
	os.system('make')
	for graph in range(1,10):
		for algo in ["Dijkstras", "Prims"]:
			res = "";
			for ds in [0,1]:
				os.system("./"+algo+" dataset/"+str(graph)+".csv "+str(ds)+" >> "+algo+str(ds)+".res")

def plotGraph():
	for algo in ["Dijkstras", "Prims"]:
		vals = [[],[]]
		for ds in [0,1]:
			count = 0;
			with open(algo+str(ds)+".res") as file:
				for line in file:
					(edges,time) = line.split(" ")
					vals[ds].append((int(edges),int(time)))
		# res = []
		# for i in range(9):
		# 	res.append((vals[0][i],vals[1][i]))
		# res.sort();
		vals[0].sort()
		vals[1].sort()

		binlist = []
		edges = []
		fiblist = []
		print(vals)
		for i in range(len(vals[0])-1):
			x,y = vals[0][i]
			_, z = vals[1][i]
			edges.append(x)
			binlist.append(y)
			fiblist.append(z)
		print(edges)
		print(binlist)
		print(fiblist)
		# for i in range(9):
		# 	vals[0][i] = res[i][0]
		# 	vals[1][i] = res[i][1]
		fig = plt.figure()
		plt.plot(edges, binlist, label="BinaryHeap")
		plt.plot(edges, fiblist, label="FibonacciHeap")
		plt.xlabel('Number of Edges')
		plt.ylabel('Time in microseconds')
		plt.title(algo+': FibonacciHeap vs BinaryHeap')
		plt.legend()
		plt.savefig(algo+".png")

getResults()
plotGraph()