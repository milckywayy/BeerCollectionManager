from collection import *
from beer import *


col = init_collection(8)

add_beer_to_collection(col, init_beer(b"Beer 1", 5.0, 4.0, 1000))
add_beer_to_collection(col, init_beer(b"Beer 2", 3.0, 2.0, 330))
add_beer_to_collection(col, init_beer(b"Beer 3", 5.0, 6.0, 550))
add_beer_to_collection(col, init_beer(b"Beer 4", 6.0, 9.0, 600))

set_collection_beer_count(col, b"Beer 1", 29)
set_collection_beer_count(col, b"Beer 2", 8)
set_collection_beer_count(col, b"Beer 3", 22)
set_collection_beer_count(col, b"Beer 4", 21)

sort_collection(col, cmp_beer_name_desc)

for i in range(col.contents.n):
    print(col.contents.beers[i].contents.name.decode())
    print("amount: " + str(col.contents.amount[i]) + '\n')

free_collection(col)

print("Yaay!")
