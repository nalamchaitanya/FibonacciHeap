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
		vals = [range(9),range(9)]
		for ds in [0,1]:
			count = 0;
			with open(algo+str(ds)+".res") as file:
				for line in file:
					vals[ds][count] = int(line)
					count += 1
		res = []
		for i in range(9):
			res.append((vals[0][i],vals[1][i]))
		res.sort();
		for i in range(9):
			vals[0][i] = res[i][0]
			vals[1][i] = res[i][1]
		fig = plt.figure()
		plt.plot(range(9), vals[0], label="BinaryHeap")
		plt.plot(range(9), vals[1], label="FibonacciHeap")
		plt.xlabel('Graphs')
		plt.ylabel('Time in microseconds')
		plt.title(algo+': FibonacciHeap vs BinaryHeap')
		plt.legend()
		plt.savefig(algo+".png")

getResults()
plotGraph()