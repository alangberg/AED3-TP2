# python plot_graphs.py titulo_1 titulo_2 ... < input

# Ejemplo de entrada para dos grafos (stdin):
#
# 4 4
# 0 1 1
# 1 2 2
# 2 3 3
# 0 3 4
# *****
# 4 3
# 0 1 1
# 1 2 2
# 2 3 3

# Ejemplo de entrada para un grafo (stdin):
#
# 4 4
# 0 1 1
# 1 2 2
# 2 3 3
# 0 3 4

import matplotlib.pyplot as plt
import networkx as nx
import sys

SAME_LAYOUT_FOR_ALL = True

def readGraph(data):
	G = nx.Graph()

	V = int(data[0].split()[0])
	E = int(data[0].split()[1])

	aristas = []

	for i in xrange(0,E):
		inicio = int(data[i+1].split()[0])
		fin = int(data[i+1].split()[1])
		peso = int(data[i+1].split()[2])
		aristas.append((inicio,fin,peso))

	for a in aristas:
		G.add_edge(a[0], a[1], weight=a[2])

	return G

data = sys.stdin.readlines()

def splitList(l, splitter):
	dividers = [i for i in xrange(0,len(l)) if l[i].strip()==splitter.strip()]
	dividers.append(len(l))
	dividers = [-1] + dividers
	return [l[dividers[i]+1:dividers[i+1]] for i in xrange(0, len(dividers)-1)]

data = splitList(data, '*****')

graphs = []

for x in data:
	graphs.append(readGraph(x))

pos = nx.spring_layout(graphs[0])

i = 1
for G in graphs:
	sp = plt.subplot(1, len(graphs), i)
	sp.set_title(sys.argv[i])
	if not SAME_LAYOUT_FOR_ALL:
		# pos=nx.spectral_layout(G)
		pos=nx.spring_layout(G)

	nx.draw(G,pos, node_color='c', with_labels=True)
	# specifiy edge labels explicitly
	edge_labels=dict([((u,v,),d['weight'])
	             for u,v,d in G.edges(data=True)])
	nx.draw_networkx_edge_labels(G,pos,edge_labels=edge_labels)
	i = i + 1

# show graphs
plt.show()