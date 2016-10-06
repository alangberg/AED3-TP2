
g++ main.cpp -o main.out -std=c++11
python generador\ de\ grafos.py 100 0.3 > entrada
# uso un archivo de por medio para poder ver lo que se genero.
# podria usar un pipe directamente
./main.out < entrada 
