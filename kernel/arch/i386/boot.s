MBOOT_PAGE_ALIGN	equ 1<<0			; load kernel and modules on page boundary
MBOOT_MEM_INFO		equ 1<<1			; provide kernel. with memory info
MBOOT_VBE_MODE		equ 1<<2			; have GRUB set video mode

MBOOT_HEADER_MAGIC	equ 0x1BADB002
MBOOT_HEADER_FLAGS	equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO ;| MBOOT_VBE_MODE

MBOOT_CHECKSUM		equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

SECTION .multiboot
	ALIGN 4

	DD MBOOT_HEADER_MAGIC
	DD MBOOT_HEADER_FLAGS
	DD MBOOT_CHECKSUM

SECTION .bss
	ALIGN 16

	stack_bottom:
		RESB 4 * 4096
	stack_top:

SECTION .text
	GLOBAL _start
	EXTERN kmain

	_start:
		mov esp, stack_top

		cli
		push ebx						; Header

		call kmain

		cli
		hlt
		jmp $
