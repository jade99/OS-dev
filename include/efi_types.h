#pragma once

#define EFIAPI _cdecl

#ifdef IA32
#define EFI_WARN	(0x00 << 24)
#define PI_WARN		(0x20 << 24)
#define OEM_WARN	(0x40 << 24)
#define EFI_ERROR	(0x80 << 24)
#define PI_ERROR	(0xa0 << 24)
#define OEM_ERROR	(0xc0 << 24)
#else
#define EFI_WARN	(0x00 << 56)
#define PI_WARN		(0x20 << 56)
#define OEM_WARN	(0x40 << 56)
#define EFI_ERROR	(0x80 << 56)
#define PI_ERROR	(0xa0 << 56)
#define OEM_ERROR	(0xc0 << 56)
#endif

#define EFI_SUCCESS					0
#define EFI_LOAD_ERROR				(EFI_ERROR + 1)
#define EFI_INVALID_PARAMETER		(EFI_ERROR + 2)
#define EFI_UNSUPPORTED				(EFI_ERROR + 3)
#define EFI_BAD_BUFFER_SIZE			(EFI_ERROR + 4)
#define EFI_BUFFER_TO_SMALL			(EFI_ERROR + 5)
#define EFI_NOT_READY				(EFI_ERROR + 6)
#define	EFI_DEVICE_ERROR			(EFI_ERROR + 7)
#define EFI_WRITE_PROTECTED			(EFI_ERROR + 8)
#define EFI_OUT_OF_RESOURCES		(EFI_ERROR + 9)
#define EFI_VOLUME_CORRUPTED		(EFI_ERROR + 10)
#define EFI_VOLUME_FULL				(EFI_ERROR + 11)
#define EFI_NO_MEDIA				(EFI_ERROR + 12)
#define EFI_MEDIA_CHANGED			(EFI_ERROR + 13)
#define EFI_NOT_FOUND				(EFI_ERROR + 14)
#define EFI_ACCESS_DENIED			(EFI_ERROR + 15)
#define EFI_NO_RESPONSE				(EFI_ERROR + 16)
#define EFI_NO_MAPPING				(EFI_ERROR + 17)
#define EFI_TIMEOUT					(EFI_ERROR + 18)
#define EFI_NOT_STARTED				(EFI_ERROR + 19)
#define EFI_ALREADY_STARTED			(EFI_ERROR + 20)
#define EFI_ABORTED					(EFI_ERROR + 21)
#define EFI_ICMP_ERROR				(EFI_ERROR + 22)
#define EFI_TFTP_ERROR				(EFI_ERROR + 23)
#define EFI_PROTOCOL_ERROR			(EFI_ERROR + 24)
#define EFI_INCOMPATIBLE_VERSION	(EFI_ERROR + 25)
#define EFI_SECURITY_VIOLATION		(EFI_ERROR + 26)
#define EFI_CRC_ERROR				(EFI_ERROR + 27)
#define EFI_END_OF_MEDIA			(EFI_ERROR + 28)
#define EFI_END_OF_FILE				(EFI_ERROR + 31)
#define EFI_INVALID_LANGUAGE		(EFI_ERROR + 32)
#define EFI_COMPROMISED_DATA		(EFI_ERROR + 33)
#define EFI_IP_ADDRESS_CONFLICT		(EFI_ERROR + 34)
#define EFI_HTTP_ERROR				(EFI_ERROR + 35)
#define EFI_WARN_UNKOWN_GLYPH		(EFI_WARN + 1)
#define EFI_WARN_DELETE_FAILURE		(EFI_WARN + 2)
#define EFI_WARN_WRITE_FAILURE		(EFI_WARN + 3)
#define EFI_WARN_BUFFER_TO_SMALL	(EFI_WARN + 4)
#define EFI_WARN_STALE_DATA			(EFI_WARN + 5)
#define EFI_WARN_FILE_SYSTEM		(EFI_WARN + 6)
#define EFI_WARN_RESET_REQUIRED		(EFI_WARN + 7)


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