import random
class graph(object):
	def __init__(self, n):
		self.n=n
		self.adj=[[0] for i in range(n)]

	def insert(self, u, v, w):
		self.adj[u].append(v)
		self.adj[u].append(w)
		self.adj[u][0]+=1

		self.adj[v].append(u)
		self.adj[v].append(w)
		self.adj[v][0]+=1



no_of_nodes = 62586
g = graph(no_of_nodes)

with open('p2p.txt') as ipfile:
	for line in ipfile:
		#print(line)
		u,v = line.split('\t')
		u = int(u)
		v = int(v)
		w = random.randint(1, 100)
		#print(u,v,w)
		if w>0 and u!=v:
			g.insert(u-1,v-1,w)

#print(g.adj[1])

with open('9.csv','w') as opfile:
	opfile.write(str(no_of_nodes)+'\n')
	for i in range(no_of_nodes):
		opfile.write(str(i)+' ')
		adj_line = g.adj[i]
		m = adj_line[0]
		for j in range(2*m+1):
			opfile.write(str(adj_line[j])+' ')
		opfile.write('\n')

