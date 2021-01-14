section .text
		extern  ___error
		global  _ft_read

; |input|   rdi = fd    rsi = buffer   rdx = bytes
_ft_read:
		mov     rax, 0x2000003              ; move ro rax read syscall index
		syscall                             ; syscall the kernel write(rdi, rsi, rdx)
		jc      error                       ; jump to the error if CF flag = 1
		ret                                 ; return rax

error:
		push rax                            ; push to the stack rax
        call ___error                       ; call error
        pop qword [rax]                     ; pop from the stack pushed value
        mov rax, -1                         ; rax = -1
        ret                                 ; return rax