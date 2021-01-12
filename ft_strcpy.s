section .text
		global _ft_strcpy

; |input|   rdi = dest    rsi = src
; |return|  rax = dest
_ft_strcpy:
		xor rcx, rcx
		.start_loop:
				cmp BYTE [rsi + rcx], 0
				je  return
				mov rbx, [rsi + rcx]
				mov [rdi + rcx], rbx
				inc rcx
				jmp .start_loop


return:
		mov BYTE [rdi + rcx], 0
		mov rax, rdi
		ret