all: temp_data_analiser

temp_data_analiser: main.o temp_api.o
	gcc -o temp_data_analiser main.o temp_api.o

main.o: main.c temp_api.h
	gcc -c -o main.o main.c

temp_functions.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c

clean: 
	rm -rf *.o temp_data_analiser