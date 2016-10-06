import random
from random import randrange as rand

random.seed()

x = rand(1,1001)


def generadorRandom(nodosMAX):
	#w, h = 8, 5. 
	# Matrix = [[rand(1,1001) for x in range(nodos)] for y in range(nodos)] 
	# print Matrix
		# a = str(rand(1,1001))
					# f.write(str(x+1))
					# f.write(" ")
					# f.write(str(y+1))
					# f.write(" ")
					# f.write(a)
					# f.write('\n')

	nodos = 50


	f = open('workfile', 'w')
	
	while nodos <= nodosMAX :
		aristas=10*nodos
		matriz = []
		cantAristas = 0
		for x in range(nodos):
			
			l = []
			for y in range(nodos):
				if x<=y and cantAristas<aristas:
					aux = rand(0,3)
					if aux != 0:
						l.append(rand(1,1001))
						cantAristas = cantAristas + 1
					else:
						l.append(0)
				else:
					l.append(0)
				
			matriz.append(l)

		f.write(str(nodos))
		f.write(" ")
		f.write(str(cantAristas))
		f.write('\n')

		for x in range(nodos):
			for y in range(nodos):
				if matriz[x][y]!=0:
					f.write(str(x+1))
					f.write(" ")
					f.write(str(y+1))
					f.write(" ")
					f.write(str(matriz[x][y]))
					f.write('\n')
		f.write('\n')
		nodos = nodos + 50
		



def generadorCompleto(nodos):
	f = open('workfile', 'w')
	for x in range(nodos):
		for y in range(nodos):
				a = str(rand(1,1001))
				f.write(str(x+1))
				f.write(" ")
				f.write(str(y+1))
				f.write(" ")
				f.write(a)
				f.write('\n')



generadorRandom(1000)