section .text
		global  _ft_write

; |input|   rdi = fd    rsi = buffer   rdx = bytes
_ft_write:
		mov rax, 0x2000004                          ; move ro rax write syscall index
		syscall                             ; syscall the kernel write(rdi, rsi, rdx)
		ret