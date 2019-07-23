CC := gcc

copy : 
	gcc -o jcopy j_copy.c
clean :
	rm -rf jcopy
