; NASM syntax
bits 16
org 0x7C00

start:
    mov si, msg

print:
    lodsb
    or al, al
    jz load_kernel

    mov ah, 0x0E
    int 0x10
    jmp print

load_kernel:
    ; Read 1 sector (kernel) from disk
    mov ah, 0x02
    mov al, 1
    mov ch, 0
    mov cl, 2
    mov dh, 0
    mov bx, 0x1000
    int 0x13

    jmp 0x0000:0x1000

msg db "Booting OS...",0

times 510-($-$$) db 0
dw 0xAA55
