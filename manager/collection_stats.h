#ifndef COLLECTION_STATS_H_
#define COLLECTION_STATS_H_

#include "collection.h"


char *get_most_common_beer(collection_t *);
char *get_strongest_beer(collection_t *);
char *get_most_expensive_beer(collection_t *);
char *get_cheapest_beer(collection_t *);

int get_all_beer_count(collection_t *);
int get_all_beer_volume_ml(collection_t *);
double get_all_beer_price(collection_t *);
double get_all_beer_alcohol_ml(collection_t *);


#endif
