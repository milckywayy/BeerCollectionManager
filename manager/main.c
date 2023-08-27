#include <stdio.h>
#include "beer.h"
#include "collection.h"


int main(int argc, char **argv) {
	
	collection_t *coll = init_collection(8);
	add_beer_to_collection(coll, init_beer("Harnaś", 5.0, 5.0, 500));
	add_beer_to_collection(coll, init_beer("Żubr", 5.0, 5.0, 500));
	print_collection(coll);
	free_collection(coll);

	return 0;
}

