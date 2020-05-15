#include <common.h>
#include <driver/cpu.h>

char
	*cpuid_vendor_get(char *vendor)
{
	uint32 where[4];

	cpuid_string(CPUID_REQUEST_GETVENDORSTRING, where);
	vendor[0] = (where[1] >> 0) & 0xFF;
	vendor[1] = (where[1] >> 8) & 0xFF;
	vendor[2] = (where[1] >> 16) & 0xFF;
	vendor[3] = (where[1] >> 24) & 0xFF;
	vendor[4] = (where[3] >> 0) & 0xFF;
	vendor[5] = (where[3] >> 8) & 0xFF;
	vendor[6] = (where[3] >> 16) & 0xFF;
	vendor[7] = (where[3] >> 24) & 0xFF;
	vendor[8] = (where[2] >> 0) & 0xFF;
	vendor[9] = (where[2] >> 8) & 0xFF;
	vendor[10] = (where[2] >> 16) & 0xFF;
	vendor[11] = (where[2] >> 24) & 0xFF;
	return (vendor);
}
