# python plot_graphs.py titulo_1 titulo_2 ... titulo_N < input

# Ejemplo de entrada para dos grafos (stdin):
#
# 4 4		|	cantNodos 		cantAristas
# 0 1 1		|	arista1_inicio 	arista1_fin 	arista1_peso
# 1 2 2		|	...
# 2 3 3		|	...
# 0 3 4		|	aristaM_inicio 	aristaM_fin 	aristaM_peso
# *****		|	Separador
# 4 3		|	cantNodos 		cantAristas
# 0 1 1		|	arista1_inicio 	arista1_fin 	arista1_peso
# 1 2 2		|	...
# 2 3 3		|	aristaM_inicio 	aristaM_fin 	aristaM_peso

# Ejemplo de entrada para un grafo (stdin):
#
# 4 4
# 0 1 1
# 1 2 2
# 2 3 3
# 0 3 4

# Ejemplo de entrada para un grafo con layout grilla (stdin):
#
# 4 4		|	cantNodos 		cantAristas
# 0 1 1		|	nodo1 			pos_i 				pos_j
# 1 1 2		|	...
# 2 2 2		|	...
# 3 3 3		|	nodoN 			pos_i 				pos_j
# 0 1 1		|	arista1_inicio 	arista1_fin 		arista1_peso
# 1 2 2		|	...
# 2 3 3		|	...
# 0 3 4		|	aristaM_inicio 	aristaM_fin 		aristaM_peso

import matplotlib.pyplot as plt
import networkx as nx
import sys

LAYOUT = 'grid'
SAME_LAYOUT_FOR_ALL = True

def readGraph(data):
	G = nx.Graph()

	V = int(data[0].split()[0])
	E = int(data[0].split()[1])

	nodos = []
	aristas = []

	if LAYOUT == 'grid':
		for i in xrange(0,V):
			id = int(data[i+1].split()[0])
			pos_i = int(data[i+1].split()[1])
			pos_j = int(data[i+1].split()[2])
			nodos.append((id,pos_i,pos_j))

		for i in xrange(0,E):
			inicio = int(data[i+V+1].split()[0])
			fin = int(data[i+V+1].split()[1])
			peso = int(data[i+V+1].split()[2])
			aristas.append((inicio,fin,peso))
	else:
		for i in xrange(0,E):
			inicio = int(data[i+1].split()[0])
			fin = int(data[i+1].split()[1])
			peso = int(data[i+1].split()[2])
			aristas.append((inicio,fin,peso))

	for a in aristas:
		G.add_edge(a[0], a[1], weight=a[2])

	return G, nodos

data = sys.stdin.readlines()

def splitList(l, splitter):
	dividers = [i for i in xrange(0,len(l)) if l[i].strip()==splitter.strip()]
	dividers.append(len(l))
	dividers = [-1] + dividers
	return [l[dividers[i]+1:dividers[i+1]] for i in xrange(0, len(dividers)-1)]

data = splitList(data, '*****')

graphs = []
nodos = []

for x in data:
	g, n = readGraph(x)
	graphs.append(g)
	nodos.append(n)

if LAYOUT == 'grid':
	N = graphs[0].number_of_nodes()
	key, value = xrange(0,N), [(nodos[0][i][2],N-nodos[0][i][1]) for i in xrange(0,N)]
	pos = dict(zip(key, value))
else:
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