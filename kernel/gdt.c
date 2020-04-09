#include <kernel/gdt.h>

gdt_entry_t	gdt_entries[5] = { 0 };
gdt_ptr_t	gdt_ptr = (gdt_ptr_t) { 0, 0 };

void
	gdt_initialize(void)
{
	gdt_ptr.limit = (sizeof(gdt_entry_t) * 5) - 1;
	gdt_ptr.base = (uint32) &gdt_entries;
	gdt_set(0, 0, 0, NULL_SEGMENT_ACCESS, 0);
	gdt_set(1, 0, 0xFFFFFFFF, CODE_SEGMENT_ACCESS, 0xCF);
	gdt_set(2, 0, 0xFFFFFFFF, DATA_SEGMENT_ACCESS, 0xCF);
	gdt_set(3, 0, 0xFFFFFFFF, USERM_CODE_SEGMENT_ACCESS, 0xCF);
	gdt_set(4, 0, 0xFFFFFFFF, USERM_DATA_SEGMENT_ACCESS, 0xCF);
	gdt_flush((uint32) &gdt_ptr);
}

void
	gdt_set(int32 id, uint32 base, uint32 limit, uint8 access, uint8 gran)
{
	gdt_entries[id].base_low = base & 0xFFFF;
	gdt_entries[id].base_middle = (base >> 16) & 0xFF;
	gdt_entries[id].base_high = (base >> 24) & 0xFF;
	gdt_entries[id].limit_low = (limit & 0xFFFF);
	gdt_entries[id].granularity = (limit >> 16) & 0x0F;
	gdt_entries[id].granularity |= gran & 0xF0;
	gdt_entries[id].access = access;
}
