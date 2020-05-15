#include <common.h>
#include <driver/pci.h>

uint32
	pci_dword_read(uint8 bus, uint8 slot, uint8 func, uint8 reg)
{
	uint32 address;
	uint32 lbus = (uint32) bus;
	uint32 lslot = (uint32) slot;
	uint32 lfunc = (uint32) func;

	address = (uint32) ((lbus << 16)
			| ((lslot & 0b00011111) << 11)
			| ((lfunc & 0b00000111) << 8)
	        | (reg << 2) /* Register to offset. */
	        | ((uint32) (1 << 31)));
	outl(PCI_CONFIG_ADDR, address);
	return (inl(PCI_CONFIG_DATA));
}

uint16
	pci_vendor_id_get(uint8 bus, uint8 slot, uint8 func)
{
	return (pci_dword_read(bus, slot, func, 0) & 0xffff);
}

uint16
	pci_device_id_get(uint8 bus, uint8 slot, uint8 func)
{
    return ((pci_dword_read(bus, slot, func, 0) >> 16) & 0xffff);
}

uint8
	pci_device_class_id_get(uint8 bus, uint8 slot, uint8 func)
{
    return ((pci_dword_read(bus, slot, func, 2) >> 24) & 0xff);
}

uint8
	pci_device_subclass_id_get(uint8 bus, uint8 slot, uint8 func)
{
    return ((pci_dword_read(bus, slot, func, 2) >> 16) & 0xff);
}
