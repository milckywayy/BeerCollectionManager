#ifndef BEER_H_
#define BEER_H_


typedef struct {
	char *name;
	double price;
	double alcohol_perc;
	double volume_ml;
} beer_t;


beer_t *init_beer(char *, double, double, double);
void free_beer(beer_t *);


#endif
