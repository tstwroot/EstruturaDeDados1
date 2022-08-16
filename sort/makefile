all:
	@gcc -c intvector.c merge.c
	@gcc main.c -o main intvector.o merge.o
	@rm intvector.o
	@rm merge.o
	@./main 10
