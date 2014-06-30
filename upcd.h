#ifndef __UPCD_H__

#define __UPCD_H__

#define SIZEBUF 16
#define min(a, b) a > b ? a : b
typedef struct {
	uint32_t USBBase;
	tDeviceInfo devInfo;
	volatile uint16_t deferredOpFlags;
	volatile bool connected;
	uint8_t intInEP;
	uint8_t intOutEP;
	uint8_t interfaceNo;
} upcd_devInst;

typedef struct {
	const uint16_t vid;
	const uint16_t pid;
	const uint16_t maxPwr;
	const uint8_t pwrAttr;
	const uint8_t *const *stringDescp;
	const uint32_t numStringDescp;
	upcd_devInst privInst;
} upcd_device;

void *UPCDInit(uint32_t index, upcd_device *dev);

uint32_t CmdHandler(upcd_devInst *devInst,uint8_t *data, uint32_t size);

void writeUSBData(upcd_devInst *devInst, void *data, uint32_t len);
#endif
