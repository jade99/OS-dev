#pragma once

#include <tables/efi_system_table.h>

typedef EFI_STATUS
(EFIAPI* EFI_IMAGE_ENTRY_POINT)(
	EFI_HANDLE ImageHandle,
	EFI_SYSTEM_TABLE* SystemTable
	);