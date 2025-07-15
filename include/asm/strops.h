#pragma once

#include <efi_types.h>

extern void EFIAPI __outs(UINT16 port, CHAR8* string, UINTN count);
extern void EFIAPI __ins(UINT16 port, CHAR8* string, UINTN count);
extern BOOLEAN EFIAPI __cmps(CHAR8* string1, CHAR8* string2, UINTN count);