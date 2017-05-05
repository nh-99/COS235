;;;;;;;;;;;;;;;;;;;;;;;;
; Author: Noah Howard  ;
; Assignemnt 8 COS 235 ;
;;;;;;;;;;;;;;;;;;;;;;;;

; This code was a port of the following C function, in assembly:
; main() {
;   int I, J, B[10] ;
;
;   for(I = 0 ; I < 10 ; I++) {
;     J = I + 1;
; 	  if ((I % 2) == 0)
;       B[I] = J ;
;     else
;       B[I] = 1 ;
;     printf(“B Value is %d\n”, B[I]) ;
;   }
; }


; To compile and run this program, execute:
; nasm -felf32 assignment2.asm && ld -melf_i386 -dynamic-linker /lib/ld-linux.so.2 assignment2.o -lc && ./a.out

extern printf                     ; Import C printf function

section .data
message db "B value is %d", 10, 0 ; Statement to print

segment .bss
b resd 10                         ; Init variables
i resd 1
j resd 1

section .text
global _start                     ; Start function

_start:
    mov dword[i], 0               ; Set variables to 0
    mov dword[j], 0
    jz runFor                     ; Run for loop

runFor:
    cmp dword[i], 10              ; Check if i < 10
    jge forDone
    mov eax, dword[i]             ; Set eax register to i
    add eax, 1                    ; Calculate j
    mov dword[j], eax             ; Set j
    mov eax, dword[i]             ; Set eax to i
    mov edx, 0
    mov ecx, 2
    div ecx                       ; Compute modulus
    cmp edx, 0                    ; if((i % 2) == 0)
    je moduloTrue                 ; Set value of b[i] to j
    mov eax, 1                    ; Set value of b[i] to 1
    mov [b + ebx * 4], eax
    jmp afterModulo               ; Jump to final piece of program

moduloTrue:
    mov eax, dword[j]             ; Set b[i] to j
    mov ebx, dword[i]
    mov [b + ebx * 4], eax
    jz afterModulo                ; Run final piece of program

afterModulo:
    mov ebx, dword[i]
    mov eax, [b + ebx * 4]
    push eax                      ; Print value of b[i]
    push message
    call printf
    add ebx, 1                    ; Increment i
    mov dword[i], ebx
    jmp runFor                    ; Run again!

forDone:
    mov ebx, 0                    ; Cleanly terminate program
    mov eax, 1
    int 0x80
