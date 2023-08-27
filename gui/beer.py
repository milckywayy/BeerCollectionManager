import ctypes
from manager import manager


class Beer(ctypes.Structure):
    _fields_ = [('name', ctypes.c_char_p), ('price', ctypes.c_double),
                ('alcohol_perc', ctypes.c_double), ('volume_ml', ctypes.c_int)]


init_beer = manager.init_beer
init_beer.argtypes = [ctypes.c_char_p, ctypes.c_double, ctypes.c_double, ctypes.c_int]
init_beer.restype = ctypes.POINTER(Beer)

print_beer = manager.print_beer
print_beer.argtypes = [ctypes.POINTER(Beer)]
print_beer.restype = None

free_beer = manager.free_beer
free_beer.argtypes = [ctypes.POINTER(Beer)]
free_beer.restype = None

cmp_beer_name_asc = manager.cmp_beer_name_asc
cmp_beer_name_asc.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
cmp_beer_name_asc.restype = ctypes.c_int

cmp_beer_name_desc = manager.cmp_beer_name_desc
cmp_beer_name_desc.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
cmp_beer_name_desc.restype = ctypes.c_int

cmp_beer_alc_asc = manager.cmp_beer_alc_asc
cmp_beer_alc_asc.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
cmp_beer_alc_asc.restype = ctypes.c_int

cmp_beer_alc_desc = manager.cmp_beer_alc_desc
cmp_beer_alc_desc.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
cmp_beer_alc_desc.restype = ctypes.c_int

cmp_beer_price_asc = manager.cmp_beer_price_asc
cmp_beer_price_asc.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
cmp_beer_price_asc.restype = ctypes.c_int

cmp_beer_price_desc = manager.cmp_beer_price_desc
cmp_beer_price_desc.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
cmp_beer_price_desc.restype = ctypes.c_int

cmp_beer_volume_asc = manager.cmp_beer_volume_asc
cmp_beer_volume_asc.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
cmp_beer_volume_asc.restype = ctypes.c_int

cmp_beer_volume_desc = manager.cmp_beer_volume_desc
cmp_beer_volume_desc.argtypes = [ctypes.c_void_p, ctypes.c_void_p]
cmp_beer_volume_desc.restype = ctypes.c_int

