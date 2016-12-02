all: programa limpa

programa: btreemain.o btree.o
	gcc btreemain.o btree.o -o exec

btreemain.o: btreemain.c btree.c btree.h
	gcc -c btreemain.c

btree.o: btree.c btree.h
	gcc -c btree.c

limpa: 
	rm *.o
