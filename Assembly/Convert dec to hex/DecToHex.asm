.model small
.data
    enter   db  10, 13, "$"
    hx      dw  16
    did     db  10
    kint    db  9
    cikl    db  0
    msg     db  "Input decimal value from 0 to 65535:", 13, 10, "$"
    sk      dw  0
    daug    dw  1
    ind     db  0
.code
mov ax, @data
mov ds, ax

    mov dx, offset msg
    mov ah, 9
    int 21h
    mov bx, 0
nuskaitymas:


    mov ah, 01h
    int 21h

    cmp al, 13
    je  skaiciavimai

    mov ah, 0
    sub al, 48
    push ax

    inc cikl

    jmp nuskaitymas

skaiciavimai:

skaicius:

    mov dx, 0

    pop ax
    mul daug



    add sk, ax
    dec cikl
    mov bx,sk

    mov ax, daug
    mul did
    mov daug, ax

    cmp cikl, 0
    jne skaicius

    jmp konvertavimas

did9:
    add dx, 55
    jmp toliau

konvertavimas:

    mov ax, sk
    jmp ciklas

ciklas:
    mov dx, 0
    div hx

    cmp dx, 9
    jg did9

    add dx,48
toliau:
    push dx
    add cikl, 1

    cmp ax, 1
    jg ciklas

    mov dx, offset enter
    mov ah, 09h
    int 21h

exit:
    pop dx

    mov ah,02h
    int 21h

    dec cikl

    cmp cikl,0
    jne exit


    mov ah, 04ch
    int 21h

 end
