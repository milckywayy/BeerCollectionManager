import ctypes
from manager import manager
from beer import *


class Collection(ctypes.Structure):
    _fields_ = [('beers', ctypes.POINTER(ctypes.POINTER(Beer))),
                ('amount', ctypes.POINTER(ctypes.c_int)),
                ('n', ctypes.c_int),
                ('capacity', ctypes.c_int)]


init_collection = manager.init_collection
init_collection.argtypes = [ctypes.c_int]
init_collection.restype = ctypes.POINTER(Collection)

add_beer_to_collection = manager.add_beer_to_collection
add_beer_to_collection.argtypes = [ctypes.POINTER(Collection), ctypes.POINTER(Beer)]
add_beer_to_collection.restype = ctypes.c_int

set_collection_beer_count = manager.set_collection_beer_count
set_collection_beer_count.argtypes = [ctypes.POINTER(Collection), ctypes.c_char_p, ctypes.c_int]
set_collection_beer_count.restype = ctypes.c_int

read_collection_from_file = manager.read_collection_from_file
read_collection_from_file.argtypes = [ctypes.POINTER(Collection), ctypes.c_char_p]
read_collection_from_file.restype = ctypes.c_int

write_collection_to_file = manager.write_collection_to_file
write_collection_to_file.argtypes = [ctypes.POINTER(Collection), ctypes.c_char_p]
write_collection_to_file.restype = ctypes.c_int

sort_collection = manager.sort_collection
sort_collection.argtypes = [ctypes.POINTER(Collection), ctypes.c_void_p]  # Typ cmp_beer_func_t nie jest dostępny w Pythonie
sort_collection.restype = None

print_collection = manager.print_collection
print_collection.argtypes = [ctypes.POINTER(Collection)]
print_collection.restype = None

free_collection = manager.free_collection
free_collection.argtypes = [ctypes.POINTER(Collection)]
free_collection.restype = None
