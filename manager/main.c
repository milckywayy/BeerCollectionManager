#include <stdio.h>
#include "beer.h"
#include "collection.h"
#include "utils.h"


int main(int argc, char **argv) {
	
	collection_t *coll = init_collection(8);

	add_beer_to_collection(coll, init_beer("Harnaś", 5.0, 5.0, 500));
	add_beer_to_collection(coll, init_beer("Żubr", 5.0, 5.0, 500));
	
	set_collection_beer_count(coll, "Żubr", 1);
	
	write_collection_to_file(coll, "../build/collection");

	print_collection(coll);
	free_collection(coll);

	return 0;
}

