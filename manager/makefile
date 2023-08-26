../build/main.exe: main.c utils.c utils.h beer.c beer.h 
	gcc -o ../build/main.exe utils.c utils.h main.c beer.c  

test: ../build/main.exe
	./../build/main.exe

windows:
	# TODO

linux:
	# TODO

clean:
	rm ../build/*
