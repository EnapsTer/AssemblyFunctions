section .text
		global _ft_strlen

; |input|   rdi = dest
; |return|  rax = string length
_ft_strlen:
		xor rax, rax                        ; rax = 0
		.start_loop:                        ; starting loop procedure
				cmp BYTE [rdi + rax], 0     ; compare argument
				je return                   ; jump to the return if ZF == 0 (cmp send 0 or 1 to Zero Flag)
				inc rax                     ; increment rax
				jmp .start_loop             ; jump to the start of the loop

return:
		ret                                 ; return rax

