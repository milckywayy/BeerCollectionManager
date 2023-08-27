#include <stdio.h>
#include "beer.h"
#include "collection.h"
#include "utils.h"


int main(int argc, char **argv) {
	
	collection_t *coll = init_collection(8);

	// read_collection_from_file(coll, "../build/collection");
	// write_collection_to_file(coll, "../build/collection");

	beer_t *beer1 = init_beer("piwo D", 6.0, 5.0, 900);
	beer_t *beer2 = init_beer("piwo B", 2.0, 4.0, 200);
	beer_t *beer3 = init_beer("piwo C", 1.0, 1.0, 500);
	beer_t *beer4 = init_beer("piwo N", 7.0, 12.0, 600);
	beer_t *beer5 = init_beer("piwo M", 10.0, 7.0, 100);
	
	add_beer_to_collection(coll, beer1);
	add_beer_to_collection(coll, beer2);
	add_beer_to_collection(coll, beer3);
	add_beer_to_collection(coll, beer4);
	add_beer_to_collection(coll, beer5);
	
	sort_collection(coll, cmp_beer_name_asc);

	print_collection(coll);

	free_collection(coll);

	return 0;
}

