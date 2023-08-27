../build/main.exe: main.c utils.c utils.h beer.c beer.h collection.c collection.h 
	gcc -o ../build/main.exe utils.c utils.h main.c beer.c collection.c collection.h  

test: ../build/main.exe
	./../build/main.exe

testmem: ../build/main.exe
	valgrind ./../build/main.exe

windows:
	# TODO

linux:
	# TODO

clean:
	rm ../build/*
