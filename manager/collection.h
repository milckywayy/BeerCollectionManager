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
int remove_beer_from_collection(collection_t *, char *);
int set_collection_beer_count(collection_t *, char*, int);
int read_collection_from_file(collection_t *, char *);
int write_collection_to_file(collection_t *, char *);
void sort_collection(collection_t *, cmp_beer_func_t);
void print_collection(collection_t *);
void free_collection(collection_t *);


#endif
