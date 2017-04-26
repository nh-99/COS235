;;;;;;;;;;;;;;;;;;;;;;;;
; Author: Noah Howard  ;
; Assignemnt 7 COS 235 ;
;;;;;;;;;;;;;;;;;;;;;;;;

; This code was a port of the following C function, in assembly:
; main()
; { int X, Y ;
;   X = 2 ;
;   Y = 10 ;
;   if (X > Y)
; 	X = 10 ;
;   else
; 	X = 20 ;
;   printf(“X is %d\n”. X) ;
; }

; To compile and run this program, execute:
; nasm -felf32 assignment1.asm && ld -melf_i386 -dynamic-linker /lib/ld-linux.so.2 assignment1.o -lc && ./a.out

extern printf                   ; Import C printf funcion

section .data
message db "X is %d", 10, 0     ; Declare print statement
x resd 1                        ; Initialize memory space for x variable
y resd 1                        ; Initialize memory space for y variable

section .text
global _start                   ; Declare main function public

_start:                         ; Start main function
    mov dword[x], 2             ; Set initial variable values
    mov dword[y], 10
    jz setx                     ; Run setx function

setx:
    mov eax, dword[x]           ; Put x into eax register
    mov ebx, dword[y]           ; Put y into ebx register
    cmp eax, ebx                ; Compare x and y
    je conditionIsTrue          ; If true, run the true function
    jmp conditionIsFalse        ; If false, run the false function

conditionIsTrue:
    mov dword[x], 10            ; Set x to 10
    jz my_print

conditionIsFalse:
    mov dword[x], 20            ; Set x to 20
    jz my_print

my_print:                       ; Print function from assignment sheet,
    mov eax, dword[x]           ; although a bit less verbose.
    push eax
    push message
    call printf

    mov ebx, 0                  ; Cleanly terminate program
    mov eax, 1
    int 0x80