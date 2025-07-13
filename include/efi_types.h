#pragma once

#define EFIAPI _cdecl

typedef	unsigned	char		BOOLEAN;

typedef	unsigned	char		UINT8;
typedef				char		INT8;
typedef	unsigned	short		UINT16;
typedef				short		INT16;
typedef	unsigned	int			UINT32;
typedef				int			INT32;
typedef	unsigned	long long	UINT64;
typedef				long long	INT64;

typedef struct
{
	UINT64	high;
	UINT64	low;
} UINT128;

typedef struct
{
	INT64	high;
	UINT64	low;
} INT128;

#ifdef IA32
typedef				UINT32		UINTN;
typedef				INT32		INTN;
#else
typedef				UINT64		UINTN;
typedef				INT64		INTN;
#endif

typedef	unsigned	char		CHAR8;
typedef	unsigned	short		CHAR16;

typedef				void		VOID;

typedef 
__declspec(align(8)) struct
{
	UINT32	a;
	UINT16	b, c, d;
	UINT8	e[12];
} EFI_GUID;

typedef	UINTN	EFI_STATUS;
typedef	VOID*	EFI_HANDLE;
typedef	VOID*	EFI_EVENT;
typedef	UINT64	EFI_LBA;
typedef	UINTN	EFI_TPL;

typedef	UINT8	EFI_MAC_ADDRESS[32];
typedef	UINT8	EFI_IPv4_ADDRESS[4];
typedef	UINT8	EFI_IPv6_ADDRESS[16];

typedef 
__declspec(align(4)) struct
{ UINT32 a; }	EFI_IP_ADDRESS;