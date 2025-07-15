#include <uefi.h>
#include <asm\strops.h>
#include <asm\io.h>

#define COM1 0x3F8

EFI_IMAGE_ENTRY_POINT 
main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable)
{
	SystemTable->ConOut->Reset(SystemTable->ConOut, 0);
	SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello World!\r\n");

	SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Probing COM1 port...");
	__outb(COM1 + 7, 'A');

	CHAR8 byte = __inb(COM1 + 7);

	if ('A' != byte)
	{
		SystemTable->ConOut->OutputString(SystemTable->ConOut, L" FAIL");
		while (1) { /* HALT and catch fire */ };
		return 1;
	}

	SystemTable->ConOut->OutputString(SystemTable->ConOut, L"OK\r\n");

	/* set baud rate */
	CHAR8 lcr = __inb(COM1 + 3);
	__outb(COM1 + 3, lcr || 0x80);
	__outb(COM1, 1);
	__outb(COM1 + 1, 0);
	__outb(COM1 + 3, lcr);

	CHAR8 string[] = "Hello World!\r\n";
	while (1) 
	{
		CHAR8 lsr = __inb(COM1 + 5);
		while (lsr & 0x20)
		{
			__outs(COM1, string, sizeof(string));
			lsr = __inb(COM1 + 5);
		}
	}

	return 0;
}