
all: libfunctionA.so libfunctionB.so my_program

libfunctionA.so: lib_function_A.c
	gcc -fPIC -shared -o libfunctionA.so lib_function_A.c

libfunctionB.so: lib_function_B.c
	gcc -fPIC -shared -o libfunctionB.so lib_function_B.c

my_program: my_program.c
	gcc -g -L./ -o my_program my_program.c -l functionA -l functionB

clean:
	rm -f *.so my_program

