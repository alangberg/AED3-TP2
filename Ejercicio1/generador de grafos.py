
import sys
import random
import math

cant_nodos = int(sys.argv[1])
prob_pared = float(sys.argv[2])

pares_f_c = []

for i in xrange(3, cant_nodos-1):
	if float(cant_nodos / i).is_integer() and (cant_nodos / i) > 2:
		pares_f_c.append((i+1, (cant_nodos / i)+1))

par_random = random.choice(pares_f_c)
F = par_random[0]
C = par_random[1]

cant_paredes = 0

grafo = [['#'] * C]

for i in xrange(1, F-1):
	grafo.append(['#'])
	for j in xrange(1, C-1):
		if random.random() <= prob_pared:
			grafo[i].append('#')
			cant_paredes += 1
		else:
			grafo[i].append('.')
	grafo[i].append('#')

grafo.append(['#']*C)

grafo[1][1] = 'o'
grafo[F-2][C-2] = 'x'

P = int(math.ceil(cant_paredes))

salida = str(F) + ' ' + str(C) + ' ' + str(P) + '\n'
for fila in grafo:
	s = ''.join(fila)
	salida += s + '\n'

print salida