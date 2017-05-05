from struct import *

def ushort_uint(bBytes):
	x, y = unpack(">HI", bBytes)
	return (x, y)

def buf2latin(bBytes):
	l = unpack(">H", bBytes[:2])[0]
	s = str(l) + 's'
	return (l, unpack(s, bBytes[2:])[0].decode("latin_1"))

def ascii2buf(*vars):
	array = bytearray()
	size = pack(">L", len(vars))
	array += size
	for var in vars:
		size = pack(">H", len(var))
		array += size
		array += var.encode("ascii")
	return array