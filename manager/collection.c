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
	if (coll == NULL) {
		return 2;
	}

	coll->capacity *= 2;
	
	coll->beers = realloc(coll->beers, sizeof(beer_t*) * coll->capacity);
	coll->amount = realloc(coll->amount, sizeof(int) * coll->capacity);

	if (coll->beers == NULL || coll->amount == NULL) {
		return 1;
	}

	return 0;
}

int add_beer_to_collection(collection_t *coll, beer_t *beer) {
	if (coll == NULL || beer == NULL) {
		return 2;
	}
	
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

int remove_beer_from_collection(collection_t *coll, char *beer_name) {
	int i, j;
	
	if (coll == NULL || beer_name == NULL) {
		return 1;
	}

	for (i = 0; i < coll->n; i++) {
		if (str_equals(coll->beers[i]->name, beer_name)) {
			free_beer(coll->beers[i]);

			for (j = i; j < coll->n - 1; j++) {
				coll->beers[j] = coll->beers[j + 1];
				coll->amount[j] = coll->amount[j + 1];
			}
			coll->n--;

			return 0;
		}
	}

	return 2;
}

int set_collection_beer_count(collection_t *coll, char *beer_name, int count) {
	int i;
	beer_t *beer;
	
	if (coll == NULL || beer_name == NULL) {
		return 2;
	}

	if (count < 0) {
		return 3;
	}

	for (i = 0; i < coll->n; i++) {
		beer = coll->beers[i];
		if (str_equals(beer->name, beer_name)) {
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

	if (coll == NULL || file_name == NULL) {
		return 2;
	}

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
			return 3;
		}
	}

	fclose(file);

	return 0;
}

int write_collection_to_file(collection_t *coll, char *file_name) {
	int i;
	beer_t *beer;
	FILE *file;
	
	if (coll == NULL || file_name == NULL) {
		return 2;
	}

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

void sort_collection(collection_t *coll, cmp_beer_func_t cmp_func) {
	int i, j;

	if (coll == NULL || cmp_func == NULL) {
		return;
	}

	for (i = 0; i < coll->n - 1; i++) {
		for (j = 0; j < coll->n - i - 1; j++) {
			if (cmp_func(&(coll->beers[j]), &(coll->beers[j + 1])) > 0) {
				swap_beer(&(coll->beers[j]), &(coll->beers[j + 1]));
				swap_int(&(coll->amount[j]), &(coll->amount[j + 1]));
			}
		}
	}
}

void print_collection(collection_t *coll) {
	int i;
	
	if (coll == NULL) {
		return;
	}

	for (i = 0; i < coll->n; i++) {
		print_beer(coll->beers[i]);
		printf("count: %d\n\n", coll->amount[i]);
	}
}

void free_collection(collection_t *coll) {
	int i;

	if (coll == NULL) {
		return;
	}

	for (i = 0; i < coll->n; i++) {
		free_beer(coll->beers[i]);
	}

	free(coll->beers);
	free(coll->amount);

	free(coll);
}

