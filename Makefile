# Makefile for pwncloud PoC
#
# author: Hanno Böck, https://hboeck.de/
# license: CC0 / public domain

all: xor pwn.com

xor: xor.c

pwn.com: pwn.asm
	nasm -fbin -o pwn.com pwn.asm

clean:
	rm pwn.com xor
