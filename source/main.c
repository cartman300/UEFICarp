#include <efi.h>
#include <efilib.h>
#include <intrin.h>
#include "loader.h"

UINTN Columns;
UINTN Rows;

void InitializeConsole(EFI_SYSTEM_TABLE* SystemTable) {
	UINTN BiggestMode = 0;
	for (UINTN i = 0; i < 20; i++)
		if (SystemTable->ConOut->QueryMode(SystemTable->ConOut, i, &Columns, &Rows) == EFI_SUCCESS)
			BiggestMode = i;
	SystemTable->ConOut->SetMode(SystemTable->ConOut, BiggestMode);
	SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
}

EFI_STATUS EfiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
	InitializeLib(ImageHandle, SystemTable);
	InitializeConsole(SystemTable);

	entry(SystemTable->RuntimeServices);

	Pause();
	RT->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, NULL);
	return EFI_SUCCESS;
}

void entry(EFI_RUNTIME_SERVICES* RT) {
	Print(L"Hello Carp!\r\n");
	_crash();

	/*INT16* Vid = (INT16*)0xB8000;
	char* Str = "Hello World!";
	for (int i = 0; i < 12; i++)
		*(Vid + i) = Str[i] | (2 | 0 << 4) << 8;*/
}