#ifndef KERNEL_PORTS_H
# define KERNEL_PORTS_H

# define VGA_COMMAND 0x3D4
# define VGA_DATA 0x3D5

# define PIC_MASTER_COMMAND 0x20
# define PIC_MASTER_DATA 0x21
# define PIC_SLAVE_COMMAND 0xA0
# define PIC_SLAVE_DATA 0xA1

# define PIC_EOI 0x20

# define PIT_DATA_CHN0 0x40
# define PIT_DATA_CHN1 0x41
# define PIT_DATA_CHN2 0x42
# define PIT_COMMAND 0x43

#endif
