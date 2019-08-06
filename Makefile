all:
	gcc main.c -o worksheet
	cp worksheet /usr/bin/
clean :
	\rm -r *.o
	\rm -r *.exe

