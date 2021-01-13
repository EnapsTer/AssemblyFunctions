section .text
		global _ft_strcmp

; |input|   rdi = s1  rsi = s2
; |return|  1, 0, -1    depend on arguments
_ft_strcmp:
		xor rcx, rcx                    ; rcx = 0
		xor rax, rax                    ; rax = 0
		jmp start_loop                  ; jump to the loop start

start_loop:
		mov dl, BYTE [rsi + rcx]        ; dl = (BYTE) argument2[rcx]
		cmp BYTE [rdi + rcx], dl        ; compare dl and argument1[rcx]
		jmp check_compare               ; jump to check_compare

check_compare:
		ja  greater                     ; if cmp above jump to the greater label
		jb  less                        ; if cmp below jump to the less label
		cmp dl, 0                       ; compare argument[2] and \0
		je  equal                       ; if compare equal jump to the equal label
		inc rcx                         ; increment rcx
		jmp start_loop                  ; jump to start loop

greater:
		mov rax, 1                      ; rax = 1
		ret                             ; return rax

less:
		mov rax, -1                     ; rax = -1
		ret                             ; return rax

equal:
		mov rax, 0                      ; rax = 0
		ret                             ; return rax