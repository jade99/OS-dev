#include <uefi.h>

EFI_IMAGE_ENTRY_POINT 
main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE* SystemTable)
{
	SystemTable->ConOut->Reset(SystemTable->ConOut, 0);
	SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_GREEN);
	SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello World!\r\n");

	while (1) {}

	return EFI_SUCCESS;
}