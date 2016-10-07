# -*- coding: utf-8 -*-
# argumentos: <input.file> <graph.eps>

import sys
import matplotlib.pyplot as plt
import math
from math import log
from math import ceil
import pylab
import numpy as np


arr = np.genfromtxt(sys.argv[1])
x = [row[0] for row in arr]
y = [row[4] for row in arr]

constante = 48000
x_Cuad = np.linspace(100, 10000, 100)
y_Cuad = constante * x_Cuad * np.log2(x_Cuad)

y = [a/(b*np.log2(b)) for a,b in zip(y, x)]
y_Cuad = constante * x_Cuad / x_Cuad

fig = plt.figure()
fig.patch.set_facecolor('white')

ax1 = fig.add_subplot(111)
pylab.plot(x_Cuad, y_Cuad, c='red', label= u'Constante K = 48000')
pylab.plot(x, y, c='b', marker= 'o', markersize = 5,  label= u'Tiempo de ejecución / F*log2(F)')

ax1.set_xlabel('Cantidad de filas F(con columnas = 1000)')
ax1.set_ylabel(u'Tiempo de ejecución [nanosegundos] / F*log2(F)')

plt.axis([0, 10000, 20000, 70000])

leg = ax1.legend()

leg = plt.legend( loc = 'upper left')

plt.savefig(sys.argv[2], format='eps', bbox_inches = 'tight')
# plt.savefig(sys.argv[2], format='png', bbox_inches = 'tight')

# plt.show()

plt.close(fig)