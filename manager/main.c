#include <stdio.h>
#include "beer.h"
#include "collection.h"
#include "utils.h"


int main(int argc, char **argv) {
	
	collection_t *coll = init_collection(8);

	read_collection_from_file(coll, "../build/collection");
	write_collection_to_file(coll, "../build/collection");

	print_collection(coll);
	
	free_collection(coll);

	return 0;
}

