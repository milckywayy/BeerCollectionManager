#include <stdlib.h>
#include <stdio.h>
#include "collection.h"
#include "beer.h"
#include "utils.h"


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
		free(coll);
		return NULL;
	}

	return coll;
}

int double_collection_capacity(collection_t *coll) {
	coll->capacity *= 2;
	
	coll->beers = realloc(coll->beers, sizeof(beer_t*) * coll->capacity);
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

int set_collection_beer_count(collection_t *coll, char *beer_name, int count) {
	beer_t *beer;
	
	for (int i = 0; i < coll->n; i++) {
		beer = coll->beers[i];
		if (str_equals(beer->name, beer_name) == 0) {
			coll->amount[i] = count;
			return 0;
		}
	}

	return 1;
}

int read_collection_from_file(collection_t *coll, char *file_name) {
	int volume_ml, amount;
	double price, alcohol_perc;
	char name[100];
	FILE *file;

	file = fopen(file_name, "r");
	if (file == NULL) {
		return 1;
	}

	while (fscanf(file, "%s %lf %lf %d %d\n", name, &price, &alcohol_perc, &volume_ml, &amount) == 5) {
		beer_t *new_beer = init_beer(name, price, alcohol_perc, volume_ml);
		
		if (new_beer != NULL) {
			add_beer_to_collection(coll, new_beer);
			set_collection_beer_count(coll, name, amount);
		}
		else {
			return 2;
		}
	}

	fclose(file);

	return 0;
}

int write_collection_to_file(collection_t *coll, char *file_name) {
	int i;
	beer_t *beer;
	FILE *file;
		
	file = fopen(file_name, "w");
	if (file == NULL) {
		return 1;
	}

	for (i = 0; i < coll->n; i++) {
		beer = coll->beers[i];
		fprintf(file, "%s %f %f %d %d\n", beer->name, beer->price, beer->alcohol_perc, beer->volume_ml, coll->amount[i]);
	}

	fclose(file);

	return 0;
}

void print_collection(collection_t *coll) {
	int i;
	
	for (i = 0; i < coll->n; i++) {
		print_beer(coll->beers[i]);
		printf("count: %d\n\n", coll->amount[i]);
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

