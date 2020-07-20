#!/usr/bin/env python

import sys

rot     = 11
min     = ord('0')
max     = ord('z')
limite  = (max-min)+1
cifrado = sys.argv[1]

for caracter in cifrado:

    valor = ord(caracter)
    descifrado = (((valor-rot)-min)%limite)+min

    print(chr(descifrado), end="")

print("\n")

