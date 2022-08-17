all:
	@gcc -g -c intvector.c merge.c
	@gcc -g main.c intvector.o merge.o
	@rm intvector.o
	@rm merge.o
	@./a.out 8
