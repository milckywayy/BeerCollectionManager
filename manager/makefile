../build/main.exe: main.c utils.c utils.h beer.c beer.h collection.c collection.h collection_stats.c collection_stats.h
	gcc -o ../build/main.exe utils.c utils.h main.c beer.c collection.c collection.h collection_stats.c collection_stats.h

test: ../build/main.exe
	./../build/main.exe

memtest: ../build/main.exe
	valgrind ./../build/main.exe

windows:
	gcc -shared -o ../build/manager.dll utils.c utils.h beer.c beer.h collection.c collection.h collection_stats.c collection_stats.h

linux:
	gcc -shared -o ../build/manager.so -fPIC utils.c utils.h beer.c beer.h collection.c collection.h collection_stats.c collection_stats.h

clean:
	rm ../build/*
