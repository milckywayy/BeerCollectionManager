#ifndef BEER_H_
#define BEER_H_


typedef struct {
	char *name;
	double price;
	double alcohol_perc;
	int volume_ml;
} beer_t;


beer_t *init_beer(char *, double, double, int);
void print_beer(beer_t *);
void free_beer(beer_t *);


#endif
