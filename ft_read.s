section .text
		global  _ft_read

; |input|   rdi = fd    rsi = buffer   rdx = bytes
_ft_read:
		mov rax, 0x2000003                  ; move ro rax read syscall index
		syscall                             ; syscall the kernel write(rdi, rsi, rdx)
		ret