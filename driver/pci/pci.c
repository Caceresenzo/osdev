#include <driver/pci.h>
#include <stdio.h>

pci_class_t	PCI_CLASSES[256] = {
	[0x00] = (pci_class_t) {
		.name = "Unclassified",
		.sub = {
			[0x00] = "Non-VGA-Compatible devices",
			[0x01] = "VGA-Compatible Device",
		},
	},
	[0x01] = (pci_class_t) {
		.name = "Mass Storage Controller",
		.sub = {
			[0x00] = "SCSI Bus Controller",
			[0x01] = "IDE Controller",
			[0x02] = "Floppy Disk Controller",
			[0x03] = "IPI Bus Controller",
			[0x04] = "RAID Controller",
			[0x05] = "ATA Controller",
			[0x06] = "Serial ATA",
			[0x07] = "Serial Attached SCSI",
			[0x08] = "Non-Volatile Memory Controller",
			[0x80] = "Other",
		},
	},
	[0x02] = (pci_class_t) {
		.name = "Network Controller",
		.sub = {
			[0x00] = "Ethernet Controller",
			[0x01] = "Token Ring Controller",
			[0x02] = "FDDI Controller",
			[0x03] = "ATM Controller",
			[0x04] = "ISDN Controller",
			[0x05] = "WorldFip Controller",
			[0x06] = "PICMG 2.14 Multi Computing",
			[0x07] = "Infiniband Controller",
			[0x08] = "Fabric Controller",
			[0x80] = "Other",
		},
	},
	[0x03] = (pci_class_t) {
		.name = "Display Controller",
		.sub = {
			[0x00] = "VGA Compatible Controller",
			[0x01] = "XGA Controller",
			[0x02] = "3D Controller (Not VGA-Compatible)",
			[0x80] = "Other",
		},
	},
	[0x04] = (pci_class_t) {
		.name = "Multimedia Controller",
		.sub = {
			[0x00] = "Multimedia Video Controller",
			[0x01] = "Multimedia Audio Controller",
			[0x02] = "Computer Telephony Device",
			[0x03] = "Audio Device",
			[0x80] = "Other",
		},
	},
	[0x05] = (pci_class_t) {
		.name = "Memory Controller",
		.sub = {
			[0x00] = "RAM Controller",
			[0x01] = "Flash Controller",
			[0x80] = "Other",
		},
	},
	[0x06] = (pci_class_t) {
		.name = "Bridge Device",
		.sub = {
			[0x00] = "Host Bridge",
			[0x01] = "ISA Bridge",
			[0x02] = "EISA Bridge",
			[0x03] = "MCA Bridge",
			[0x04] = "PCI-to-PCI Bridge",
			[0x05] = "PCMCIA Bridge",
			[0x06] = "NuBus Bridge",
			[0x07] = "CardBus Bridge",
			[0x08] = "RACEway Bridge",
			[0x09] = "PCI-to-PCI Bridge",
			[0x0A] = "InfiniBand-to-PCI Host Bridge",
			[0x80] = "Other",
		},
	},
	[0x07] = (pci_class_t) {
		.name = "Simple Communication Controller",
		.sub = {
			[0x00] = "Serial Controller",
			[0x01] = "Parallel Controller",
			[0x02] = "Multiport Serial Controller",
			[0x03] = "Modem",
			[0x04] = "IEEE 488.1/2 (GPIB) Controller",
			[0x05] = "Smart Card",
			[0x80] = "Other",
		},
	},
	[0x08] = (pci_class_t) {
		.name = "Base System Peripheral",
		.sub = {
			[0x00] = "PIC",
			[0x01] = "DMA Controller",
			[0x02] = "Timer",
			[0x03] = "RTC Controller",
			[0x04] = "PCI Hot-Plug Controller",
			[0x05] = "SD Host controller",
			[0x06] = "IOMMU",
			[0x80] = "Other",
		},
	},
	[0x09] = (pci_class_t) {
		.name = "Input Device Controller",
		.sub = {
			[0x00] = "Keyboard Controller",
			[0x01] = "Digitizer Pen",
			[0x02] = "Mouse Controller",
			[0x03] = "Scanner Controller",
			[0x04] = "Gameport Controller",
			[0x80] = "Other",
		},
	},
	[0x0a] = (pci_class_t) {
		.name = "Docking Station",
		.sub = {
			[0x00] = "Generic",
			[0x80] = "Other",
		},
	},
	[0x0b] = (pci_class_t) {
		.name = "Processor",
		.sub = {
			[0x00] = "386",
			[0x01] = "486",
			[0x02] = "Pentium",
			[0x03] = "Pentium Pro",
			[0x10] = "Alpha",
			[0x20] = "PowerPC",
			[0x30] = "MIPS",
			[0x40] = "Co-Processor",
			[0x80] = "Other",
		},
	},
	[0x0c] = (pci_class_t) {
		.name = "Serial Bus Controller",
		.sub = {
			[0x00] = "FireWire (IEEE 1394) Controller",
			[0x01] = "ACCESS Bus",
			[0x02] = "SSA",
			[0x03] = "USB Controller",
			[0x04] = "Fibre Channel",
			[0x05] = "SMBus",
			[0x06] = "InfiniBand",
			[0x07] = "IPMI Interface",
			[0x08] = "SERCOS Interface (IEC 61491)",
			[0x09] = "CANbus",
			[0x80] = "Other",
		},
	},
	[0x0d] = (pci_class_t) {
		.name = "Wireless Controller",
		.sub = {
			[0x00] = "iRDA Compatible Controller",
			[0x01] = "Consumer IR Controller",
			[0x10] = "RF Controller",
			[0x11] = "Bluetooth Controller",
			[0x12] = "Broadband Controller",
			[0x20] = "Ethernet Controller (802.1a)",
			[0x21] = "Ethernet Controller (802.1b)",
			[0x80] = "Other",
		},
	},
	[0x0e] = (pci_class_t) {
		.name = "Intelligent Controller",
		.sub = {
			[0x20] = "I20",
		},
	},
	[0x0f] = (pci_class_t) {
		.name = "Satellite Communication Controller",
		.sub = {
			[0x01] = "Satellite TV Controller",
			[0x02] = "Satellite Audio Controller",
			[0x03] = "Satellite Voice Controller",
			[0x04] = "Satellite Data Controller",
		},
	},
	[0x10] = (pci_class_t) {
		.name = "Encryption Controller",
		.sub = {
			[0x00] = "Network and Computing Encrpytion/Decryption",
			[0x10] = "Entertainment Encryption/Decryption",
			[0x80] = "Other Encryption/Decryption",
		},
	},
	[0x11] = (pci_class_t) {
		.name = "Signal Processing Controller",
		.sub = {
			[0x00] = "DPIO Modules",
			[0x01] = "Performance Counters",
			[0x10] = "Communication Synchronizer",
			[0x20] = "Signal Processing Management",
			[0x80] = "Other",
		},
	},
	[0x12] = (pci_class_t) {
		.name = "Processing Accelerator",
		.sub = { NULL },
	},
	[0x13] = (pci_class_t) {
		.name = "Non-Essential Instrumentation",
		.sub = { NULL },
	},
	[0x40] = (pci_class_t) {
		.name = "Co-Processor",
		.sub = { NULL },
	},
	[0xff] = (pci_class_t) {
		.name = "Unassigned Class (Vendor specific)",
		.sub = { NULL },
	},
	[0x14 ... 0x3f] = (pci_class_t) {
		.name = "(Reserved)",
		.sub = { NULL },
	},
	[0x41 ... 0xfe] = (pci_class_t) {
		.name = "(Reserved)",
		.sub = { NULL },
	},
};

void
	pci_initialize(void)
{
	pci_registry_probe();
}

void
	pci_print(pci_device_t device)
{
	printk("[pci] v:%x d:%x - %s (%s)\n", device.vendor, device.device,
			PCI_CLASSES[device.class].name,
			PCI_CLASSES[device.class].sub[device.subclass]);
}
