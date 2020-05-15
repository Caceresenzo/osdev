#include <common.h>
#include <driver/pci.h>

pci_device_t	PCI_DEVICE_REGISTRY[PCI_REGISTRY_MAX] = {};
uint16			PCI_DEVICE_COUNT = 0;

bool
	pci_registry_add(uint16	bus, uint8 slot, uint8 func)
{
	uint16			vendor_id;
	pci_device_t	*entry;

	vendor_id = pci_vendor_id_get(bus, slot, func);
	if (vendor_id == 0xFFFF)
		return (false);
	if (PCI_DEVICE_COUNT < PCI_REGISTRY_MAX)
	{
		entry = PCI_DEVICE_REGISTRY + PCI_DEVICE_COUNT;
		entry->vendor = vendor_id;
		entry->device = pci_device_id_get(bus, slot, func);
		entry->func = func;
		entry->class = pci_device_class_id_get(bus, slot, func);
		entry->subclass = pci_device_subclass_id_get(bus, slot, func);
		pci_print(*entry);
		PCI_DEVICE_COUNT++;
	}
	return (true);
}

void
	pci_registry_probe(void)
{
	uint16	bus;
	uint8	slot;
	uint8	func;

	bus = 0;
	while (bus < 256)
	{
		slot = 0;
		while (slot < 32)
		{
			func = 0;
			while (func < 8)
			{
				pci_registry_add(bus, slot, func);
				func++;
			}
			slot++;
		}
		bus++;
	}
}
