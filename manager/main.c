#include <stdio.h>
#include "beer.h"


int main(int argc, char **argv) {

	char *name = "LALA";
	beer_t *beer = init_beer(name, 5.0, 5.0, 500.0); 
	printf("%f\n", beer->price);
	free_beer(beer);

	return 0;
}

