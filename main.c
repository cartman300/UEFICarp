#include <efi.h>
#include <efilib.h>

EFI_STATUS EfiMain(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
	EFI_INPUT_KEY Key;
	InitializeLib(ImageHandle, SystemTable);

	Print(L"Hello Carp!\n");

	SystemTable->ConIn->Reset(SystemTable->ConIn, FALSE);
	while (SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key) == EFI_NOT_READY);

	//RT->ResetSystem(EfiResetShutdown, EFI_SUCCESS, 0, NULL);
	return EFI_SUCCESS;
}