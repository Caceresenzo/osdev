#ifndef MULTIBOOT_H_
# define MULTIBOOT_H_

/*
** More at: https://www.gnu.org/software/grub/manual/multiboot/multiboot.html
*/

# include <common.h>

/* How many bytes from the start of the file we search for the header. */
#define MULTIBOOT_SEARCH				8192
#define MULTIBOOT_HEADER_ALIGN			4

/* The magic field should contain this. */
#define MULTIBOOT_HEADER_MAGIC			0x1BADB002

/* This should be in %eax. */
#define MULTIBOOT_BOOTLOADER_MAGIC		0x2BADB002

/* Alignment of multiboot modules. */
#define MULTIBOOT_MOD_ALIGN				0x00001000

/* Alignment of the multiboot info structure. */
#define MULTIBOOT_INFO_ALIGN			0x00000004

/* Flags set in the 'flags' member of the multiboot header. */

/* Align all boot modules on i386 page (4KB) boundaries. */
#define MULTIBOOT_PAGE_ALIGN			0x00000001

/* Must pass memory information to OS. */
#define MULTIBOOT_MEMORY_INFO			0x00000002

/* Must pass video information to OS. */
#define MULTIBOOT_VIDEO_MODE			0x00000004

/* This flag indicates the use of the address fields in the header. */
#define MULTIBOOT_AOUT_KLUDGE			0x00010000

/* Flags to be set in the 'flags' member of the multiboot info structure. */

/* is there basic lower/upper memory information? */
#define MULTIBOOT_INFO_MEMORY			0x00000001
/* is there a boot device set? */
#define MULTIBOOT_INFO_BOOTDEV			0x00000002
/* is the command-line defined? */
#define MULTIBOOT_INFO_CMDLINE			0x00000004
/* are there modules to do something with? */
#define MULTIBOOT_INFO_MODS				0x00000008

/* These next two are mutually exclusive */

/* is there a symbol table loaded? */
#define MULTIBOOT_INFO_AOUT_SYMS		0x00000010
/* is there an ELF section header table? */
#define MULTIBOOT_INFO_ELF_SHDR			0X00000020

/* is there a full memory map? */
#define MULTIBOOT_INFO_MEM_MAP			0x00000040

/* Is there drive info? */
#define MULTIBOOT_INFO_DRIVE_INFO		0x00000080

/* Is there a config table? */
#define MULTIBOOT_INFO_CONFIG_TABLE		0x00000100

/* Is there a boot loader name? */
#define MULTIBOOT_INFO_BOOT_LOADER_NAME	0x00000200

/* Is there a APM table? */
#define MULTIBOOT_INFO_APM_TABLE		0x00000400

/* Is there video information? */
#define MULTIBOOT_INFO_VBE_INFO			0x00000800
#define MULTIBOOT_INFO_FRAMEBUFFER_INFO	0x00001000

typedef struct {
	/* Multiboot info version number */
	uint32	flags;

	/* Available memory from BIOS */
	uint32	mem_lower;
	uint32	mem_upper;

	/* "root" partition */
	uint32	boot_device;

	/* Kernel command line */
	uint32	cmdline;

	/* Boot-Module list */
	uint32	mods_count;
	uint32	mods_addr;

	uint32	num;
	uint32	size;
	uint32	addr;
	uint32	shndx;

	/* Memory Mapping buffer */
	uint32	mmap_length;
	uint32	mmap_addr;

	 /* Drive Info buffer */
	uint32	drives_length;
	uint32	drives_addr;

	/* ROM configuration table */
	uint32	config_table;

	/* Boot Loader Name */
	uint32	boot_loader_name;

	/* APM table */
	uint32	apm_table;

	/* Video */
	uint32	vbe_control_info;
	uint32	vbe_mode_info;
	uint16	vbe_mode;
	uint16	vbe_interface_seg;
	uint16	vbe_interface_off;
	uint16	vbe_interface_len;
}			multiboot_info;

# define MULTIBOOT_MEMORY_AVAILABLE			1
# define MULTIBOOT_MEMORY_RESERVED			2
# define MULTIBOOT_MEMORY_ACPI_RECLAIMABLE	3
# define MULTIBOOT_MEMORY_NVS				4
# define MULTIBOOT_MEMORY_BADRAM			5

typedef struct
{
	uint32	size;
	uint64	addr;
	uint64	len;
	uint32	type;
} __attribute__((packed)) multiboot_memory_map_t;

void			multiboot_info_store(multiboot_info *ptr);
multiboot_info	multiboot_info_get(void);
void			multiboot_dump();

#endif
