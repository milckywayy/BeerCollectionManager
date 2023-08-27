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

typedef int (*cmp_beer_func_t)(const void *, const void *);
int cmp_beer_name_asc(const void *, const void *);
int cmp_beer_name_desc(const void *, const void *);
int cmp_beer_alc_asc(const void *, const void *);
int cmp_beer_alc_desc(const void *, const void *);
int cmp_beer_price_asc(const void *, const void *);
int cmp_beer_price_desc(const void *, const void *);
int cmp_beer_volume_asc(const void *, const void *);
int cmp_beer_volume_desc(const void *, const void *);


#endif
