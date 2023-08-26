#include <stdio.h>
#include "beer.h"


int main(int argc, char **argv) {
	beer_t *beer = NULL;
	char name[50] = "Harnaś";
	
	beer = init_beer(name, 5.0, 5.0, 500.0); 
	
	printf("%s\n", beer->name);
	
	free_beer(beer);

	return 0;
}

