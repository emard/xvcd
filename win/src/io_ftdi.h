#define PicoEVB 0
#define ULX3S 1

#if PicoEVB
#define PORT_TCK            0x01
#define PORT_TDI            0x02
#define PORT_TDO            0x04
#define PORT_TMS            0x08
#endif

#if ULX3S
#define PORT_TCK            0x20  // DSR
#define PORT_TDI            0x80  // RI
#define PORT_TDO            0x08  // CTS
#define PORT_TMS            0x40  // DCD
#endif

void io_close(void);
int io_init(int vendor, int product);
int io_scan(const unsigned char *TMS, const unsigned char *TDI, unsigned char *TDO, int bits);

