#include <stdlib.h>
#include <stdio.h>
#include "collection.h"
#include "beer.h"


collection_t *init_collection(int capacity) {
	collection_t *coll = malloc(sizeof(collection_t));

	if (coll == NULL) {
		return NULL;
	}

	coll->n = 0;
	coll->capacity = capacity;
	coll->beers = malloc(sizeof(beer_t*) * capacity);
	coll->amount = malloc(sizeof(int) * capacity);
	
	if (coll->beers == NULL || coll->amount == NULL) {
		return NULL;
	}

	return coll;
}

int double_collection_capacity(collection_t *coll) {
	coll->capacity *= 2;
	
	coll->beers = realloc(coll->beers, sizeof(beer_t) * coll->capacity);
	coll->amount = realloc(coll->amount, sizeof(int) * coll->capacity);

	if (coll->beers == NULL || coll->amount == NULL) {
		return 1;
	}

	return 0;
}

int add_beer_to_collection(collection_t *coll, beer_t *beer) {
	if (coll->n >= coll->capacity) {
		if (double_collection_capacity(coll) != 0) {
			return 1;
		}
	}

	coll->beers[coll->n] = beer;
	coll->amount[coll->n] = 0;
	coll->n++;

	return 0;
}


int set_collcection_beer_count(collection_t *, int count);

void print_collection(collection_t *coll) {
	int i;
	
	for (i = 0; i < coll->n; i++) {
		print_beer(coll->beers[i]);
		// printf("count: %d\n\n", coll->amount[i]);
	}
}

void free_collection(collection_t *coll) {
	int i;

	for (i = 0; i < coll->n; i++) {
		free_beer(coll->beers[i]);
	}

	free(coll->beers);
	free(coll->amount);

	free(coll);
}

