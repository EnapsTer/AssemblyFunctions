section .text
		global _ft_strcpy

; |input|   rdi = dest    rsi = src
; |return|  rax = dest
_ft_strcpy:
		xor rcx, rcx                        ; rcx = 0
		.start_loop:                        ; starting loop
				cmp BYTE [rsi + rcx], 0     ; compare value of argument2[rcx] to \0
				je  return                  ; if compare equal jump to return
				mov bl, BYTE [rsi + rcx]    ; bl = (BYTE) argument2[rsx]
				mov BYTE [rdi + rcx], bl    ; (BYTE) argument1[rcx] = bl
				inc rcx                     ; increment rcx
				jmp .start_loop             ; jump to the start loop

return:
		mov BYTE [rdi + rcx], 0             ; in the last index insert the \0
		mov rax, rdi                        ; rax = rdi
		ret                                 ; return rax