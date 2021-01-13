section .text
		extern _malloc
		extern _ft_strcpy
		extern _ft_strlen
		global _ft_strdup

; |input| rdi = string to dup
; |return| rax = allocated and copied string
_ft_strdup:
		push    rdi
		call    _ft_strlen
		inc     rax
		mov     rdi, rax
		call    _malloc
		pop     rsi
		mov     rdi, rax
		call    _ft_strcpy
		ret