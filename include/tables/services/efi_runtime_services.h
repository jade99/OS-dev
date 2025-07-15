#pragma once

#include <efi_types.h>
#include <tables/efi_table_header.h>

#define	EFI_RUNTIME_SERVICES_SIGNATURE	0x56524553544e5552
#define	EFI_RUNTIME_SERVICES_REVISION	EFI_SPECIFICATION_VERSION

typedef EFI_STATUS
GetVariable(
	CHAR16* VariableName,
	EFI_GUID* VendorGuid,
	UINT32* Attributes,
	UINTN* DataSize,
	VOID* Data
);

typedef struct
{
	EFI_TABLE_HEADER	Hdr;
} EFI_RUNTIME_SERVICES;