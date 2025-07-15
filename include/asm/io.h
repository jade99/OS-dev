#pragma once

#include <efi_types.h>

extern void EFIAPI __outb(UINT16 port, CHAR8 byte);
extern CHAR8 EFIAPI __inb(UINT16 port);