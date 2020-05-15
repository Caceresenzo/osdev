#include <kernel/memory.h>
#include <kernel/multiboot.h>
#include <kernel.h>
#include <stdio.h>
#include <bits.h>

static bool				multiboot_stored = false;
static multiboot_info	multiboot = { 0 };

void
	multiboot_info_store(multiboot_info *ptr)
{
	if (ptr != NULL)
	{
		multiboot_stored = true;
		multiboot = *ptr;
	}
}

multiboot_info
	multiboot_info_get(void)
{
	if (!multiboot_stored)
		PANIC("No multiboot info provided.");
	return (multiboot);
}

void
	multiboot_dump()
{
	if (!multiboot_stored)
	{
		printk("No stored multiboot header to dump.\n");
		return ;
	}
	printk("flags             > %b\n", multiboot.flags);
	if (bitset_test32(multiboot.flags, 0))
	{
		printk("mem_lower    (kb) > %d\n", multiboot.mem_lower);
		printk("mem_upper    (kb) > %d\n", multiboot.mem_upper);
	}
	if (bitset_test32(multiboot.flags, 1)) {
		printk("boot_device       > P3 %p -- P2 %p -- P1 %p -- DRIVE %p\n",
		        (void*) (multiboot.boot_device >> 24 && 0xFF),
		        (void*) (multiboot.boot_device >> 16 && 0xFF),
		        (void*) (multiboot.boot_device >> 8 && 0xFF),
		        (void*) (multiboot.boot_device >> 0 && 0xFF));
	}
	if (bitset_test32(multiboot.flags, 2))
		printk("cmdline           > %s\n", (char*) multiboot.cmdline);
	if (bitset_test32(multiboot.flags, 3))
	{
		printk("mods_count        > %d\n", multiboot.mods_count);
		printk("mods_addr         > %p\n", (void*) multiboot.mods_addr);
	}
	if (bitset_test32(multiboot.flags, 6))
	{
		printk("mmap_length       > %d\n", multiboot.mmap_length);
		printk("mmap_addr         > %p\n", (void*) multiboot.mmap_addr);
		memory_dump_maps();
	}
	if (bitset_test32(multiboot.flags, 7))
	{
		printk("drives_length     > %d\n", multiboot.drives_length);
		printk("drives_addr       > %p\n", (void*) multiboot.drives_addr);
	}
	if (bitset_test32(multiboot.flags, 8))
		printk("config_table      > %p\n", (void*) multiboot.config_table);
	if (bitset_test32(multiboot.flags, 9))
		printk("boot_loader_name  > %s\n", (void*) multiboot.boot_loader_name);
	if (bitset_test32(multiboot.flags, 10))
		printk("apm_table         > %p\n", (void*) multiboot.apm_table);
}
