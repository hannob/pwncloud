; pwn.asm
; just prints the string "PWN"
;
; part of pwncloud PoC, must stay below 16 bytes to work
; author: Hanno Böck, https://hboeck.de/
; license: CC0 / public domain

org 0x100
mov dx, pwn
mov ah, 9
int 0x21
mov ax, 0x4c00
int 0x21

pwn db 'PWN$'
