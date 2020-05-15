#include <kernel/multiboot.h>
#include <kernel/memory.h>
#include <stdio.h>

uint32			TOTAL_MEMORY = 0;
uint64			FIRST_MEMORY_MAP = 0;

static char		*memory_map_names[] = (char*[]) {
	"UNKWN",
	"AVAIL",
	"RESRV",
	"RECLM",
	"NVS  ",
	"BADRM",
	"UNKWN"
};

uint32
	memory_compute_available(void)
{
	multiboot_info			info;
	multiboot_memory_map_t	*mmap;

	info = multiboot_info_get();
	mmap = (multiboot_memory_map_t*) info.mmap_addr;
	TOTAL_MEMORY = 0;
	FIRST_MEMORY_MAP = 0;
	while ((uint32) mmap < info.mmap_addr + info.mmap_length) {
		mmap = (multiboot_memory_map_t*) ((uint32) mmap + mmap->size + sizeof(uint32));
		if (mmap->type == MULTIBOOT_MEMORY_AVAILABLE)
		{
			TOTAL_MEMORY = mmap->len;
			if (FIRST_MEMORY_MAP == 0)
				FIRST_MEMORY_MAP = mmap->addr;
		}
	}
	return (TOTAL_MEMORY);
}

void
	memory_dump_maps(void)
{
	multiboot_info			info;
	multiboot_memory_map_t	*mmap;

	info = multiboot_info_get();
	mmap = (multiboot_memory_map_t*) info.mmap_addr;
	while ((uint32) mmap < info.mmap_addr + info.mmap_length) {
		mmap = (multiboot_memory_map_t*) ((uint32) mmap + mmap->size + sizeof(uint32));
		printk("(%d) %s : ", mmap->type, memory_map_names[mmap->type]);
		printk("%p to %p = %d b (or ~%d kb or ~%d mb)\n", (uint32) mmap->addr,
				(uint32) mmap->addr + (uint32) mmap->len - 1,
				(uint32) mmap->len, (uint32) mmap->len / 1024,
				(uint32) mmap->len / 1024 / 1024);
	}
}
