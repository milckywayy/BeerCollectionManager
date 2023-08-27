#ifndef COLLECTION_H_
#define COLLECTION_H_


#include "beer.h"


typedef struct {
	beer_t **beers;
	int *amount;
	int n;
	int capacity;
} collection_t;


collection_t *init_collection(int);
int double_collection_capacity(collection_t *);
int add_beer_to_collection(collection_t *, beer_t *);
int set_collcection_beer_count(collection_t *, int count);
void print_collection(collection_t *);
void free_collection(collection_t *);


#endif
