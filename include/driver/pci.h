#ifndef _DRIVER_PCI_H
# define _DRIVER_PCI_H

# include <common.h>

# define PCI_CONFIG_ADDR	0xcf8
# define PCI_CONFIG_DATA	0xcfc
# define PCI_REGISTRY_MAX	128

typedef struct
{
	const char *name;
	char *sub[129];
} pci_class_t;

typedef struct
{
	uint32	vendor;
	uint32	device;
	uint32	func;
	uint32	class;
	uint32	subclass;
} pci_device_t;

pci_class_t		PCI_CLASSES[256];
pci_device_t	PCI_DEVICE_REGISTRY[PCI_REGISTRY_MAX];
uint16			PCI_DEVICE_COUNT;

void	pci_initialize(void);

void	pci_print(pci_device_t device);

void	pci_registry_probe(void);

uint32	pci_dword_read(uint8 bus, uint8 slot, uint8 func, uint8 reg);

uint16	pci_vendor_id_get(uint8 bus, uint8 slot, uint8 func);
uint16	pci_device_id_get(uint8 bus, uint8 slot, uint8 func);
uint8	pci_device_class_id_get(uint8 bus, uint8 slot, uint8 func);
uint8	pci_device_subclass_id_get(uint8 bus, uint8 slot, uint8 func);

#endif
