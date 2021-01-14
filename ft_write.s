section .text
		extern  ___error
		global  _ft_write

; |input|   rdi = fd    rsi = buffer   rdx = bytes
_ft_write:
		mov     rax, 0x2000004              ; move ro rax write syscall index
		syscall                             ; syscall the kernel write(rdi, rsi, rdx)
		jc      error                       ; jump if syscall change CF flag
		ret                                 ; return rax

error:
		push rax                            ; push to the stack rax
        call ___error                       ; call error
        pop qword [rax]                     ; pop from the stack pushed value
        mov rax, -1                         ; rax = -1
        ret                                 ; return rax