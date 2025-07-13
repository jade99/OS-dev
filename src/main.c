#include <uefi.h>

EFI_IMAGE_ENTRY_POINT 
main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable)
{
	SystemTable->ConOut->Reset(SystemTable->ConOut, 0);
	SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello World!");

	while (1) { /* HALT and catch fire */ };

	return 0;
}