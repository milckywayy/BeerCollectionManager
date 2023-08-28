#include <stdio.h>
#include "beer.h"
#include "collection.h"
#include "utils.h"
#include "collection_stats.h"


int main(int argc, char **argv) {
	
	collection_t *coll = init_collection(8);

	// read_collection_from_file(coll, "../build/collection");
	// write_collection_to_file(coll, "../build/collection");

	beer_t *beer1 = init_beer("piwo 1", 6.0, 5.0, 900);
	beer_t *beer2 = init_beer("piwo 2", 2.0, 4.0, 200);
	beer_t *beer3 = init_beer("piwo 3", 1.0, 1.0, 500);
	beer_t *beer4 = init_beer("piwo 4", 7.0, 12.0, 600);
	beer_t *beer5 = init_beer("piwo 5", 10.0, 7.0, 100);
	beer_t *beer6 = init_beer("piwo 6", 10.0, 7.0, 100);

	add_beer_to_collection(coll, beer1);
	set_collection_beer_count(coll, beer1->name, 4);
	add_beer_to_collection(coll, beer2);
	set_collection_beer_count(coll, beer2->name, 1);
	add_beer_to_collection(coll, beer3);
	set_collection_beer_count(coll, beer3->name, 7);
	add_beer_to_collection(coll, beer4);
	set_collection_beer_count(coll, beer4->name, 9);
	add_beer_to_collection(coll, beer5);
	set_collection_beer_count(coll, beer5->name, 2);

	remove_beer_from_collection(coll, "piwo 4");

	add_beer_to_collection(coll, beer6);
	set_collection_beer_count(coll, beer6->name, 7);

	// sort_collection(coll, cmp_beer_name_asc);

	print_collection(coll);

	printf("most common: %s\n", get_most_common_beer(coll));
	printf("strongest: %s\n", get_strongest_beer(coll));
	printf("most expensive: %s\n", get_most_expensive_beer(coll));
	printf("cheapest: %s\n", get_cheapest_beer(coll));
	printf("all beers count: %d\n", get_all_beer_count(coll));
	printf("sum volume (ml): %d\n", get_all_beer_volume_ml(coll));
	printf("sum price: %f\n", get_all_beer_price(coll));
	printf("sum alcohol (ml): %f\n", get_all_beer_alcohol_ml(coll));

	free_collection(coll);

	return 0;
}

