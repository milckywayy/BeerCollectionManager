#ifndef BEER_H_
#define BEER_H_


typedef struct {
	char name[100];
	double price;
	double alcohol_perc;
	double volume;
} beer_t;


beer_t *init_beer(char *name, double price, double alcohol_perc, double volume);
void free_beer(beer_t *beer);


#endif
