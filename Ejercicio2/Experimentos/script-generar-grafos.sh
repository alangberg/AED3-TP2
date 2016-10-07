F=100
C=1000

BASE=0
TOPE=10000
INC=500
for ((i=BASE; i<TOPE; i+=INC)); do
	./generador $((i+F)) $C < probabilidades > ins/entrada$((i/INC))
done