[EXTERN isr_handler]
[EXTERN irq_handler]

%macro ISR_NOERRCODE 1  ; define a macro, taking one parameter
  [GLOBAL isr%1]		; %1 accesses the first parameter.
  isr%1:
	cli
	push byte 0
	push byte %1
	jmp isr_common_stub
%endmacro

%macro ISR_ERRCODE 1
  [GLOBAL isr%1]
  isr%1:
	cli
	push byte %1
	jmp isr_common_stub
%endmacro

%macro IRQ 2
  [GLOBAL irq%2]
  irq%2:
	cli
	push byte 0
	push byte %1
	jmp irq_common_stub
%endmacro

ISR_NOERRCODE 0
ISR_NOERRCODE 1
ISR_NOERRCODE 2
ISR_NOERRCODE 3
ISR_NOERRCODE 4
ISR_NOERRCODE 5
ISR_NOERRCODE 6
ISR_NOERRCODE 7
ISR_ERRCODE   8
ISR_NOERRCODE 9
ISR_ERRCODE   10
ISR_ERRCODE   11
ISR_ERRCODE   12
ISR_ERRCODE   13
ISR_ERRCODE   14
ISR_NOERRCODE 15
ISR_NOERRCODE 16
ISR_NOERRCODE 17
ISR_NOERRCODE 18
ISR_NOERRCODE 19
ISR_NOERRCODE 20
ISR_NOERRCODE 21
ISR_NOERRCODE 22
ISR_NOERRCODE 23
ISR_NOERRCODE 24
ISR_NOERRCODE 25
ISR_NOERRCODE 26
ISR_NOERRCODE 27
ISR_NOERRCODE 28
ISR_NOERRCODE 29
ISR_NOERRCODE 30
ISR_NOERRCODE 31

IRQ	32,	0
IRQ	33,	1
IRQ	34,	2
IRQ	35,	3
IRQ	36,	4
IRQ	37,	5
IRQ	38,	6
IRQ	39,	7
IRQ	40,	8
IRQ	41,	9
IRQ	42,	10
IRQ	43,	11
IRQ	44,	12
IRQ	45,	13
IRQ	46,	14
IRQ	47,	15

; This is our common ISR stub. It saves the processor state, sets
; up for kernel mode segments, calls the C-level fault handler,
; and finally restores the stack frame.
isr_common_stub:
	pusha					; Pushes edi,esi,ebp,esp,ebx,edx,ecx,eax

	mov ax, ds			   ; Lower 16-bits of eax = ds.
	push eax				 ; save the data segment descriptor

	mov ax, 0x10  ; load the kernel data segment descriptor
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	call isr_handler

	pop ebx		; reload the original data segment descriptor
	mov ds, bx
	mov es, bx
	mov fs, bx
	mov gs, bx

	popa					 ; Pops edi,esi,ebp...
	add esp, 8	 ; Cleans up the pushed error code and pushed ISR number
	sti
	iret		   ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP


irq_common_stub:
	pusha

	mov ax, ds
	push eax

	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	call irq_handler

	pop ebx
	mov ds, bx
	mov es, bx
	mov fs, bx
	mov gs, bx

	popa
	add esp, 8
	sti
	iret
