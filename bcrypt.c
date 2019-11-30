/*

Copyright (C) 2019 by Gianluigi Tiesi <sherpya@netfarm.it>

Permission to use, copy, modify, and/or distribute this software
for any purpose with or without fee is hereby granted.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

*/

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <ntstatus.h>
#include <wincrypt.h>
#include <bcrypt.h>

static NTSTATUS GLE_NTStatus(BOOL result)
{
    if (result)
        return STATUS_SUCCESS;

    switch (GetLastError())
    {
        case ERROR_SUCCESS:
            return STATUS_SUCCESS;
        case ERROR_FILE_NOT_FOUND:
            return STATUS_FILE_NOT_AVAILABLE;
        case ERROR_INVALID_HANDLE:
            return STATUS_INVALID_HANDLE;
        case ERROR_NOT_ENOUGH_MEMORY:
            return STATUS_NO_MEMORY;
        case ERROR_INVALID_PARAMETER:
            return STATUS_INVALID_PARAMETER;
        default:
            return STATUS_UNSUCCESSFUL;
    }
}

NTSTATUS WINAPI BCryptOpenAlgorithmProvider(BCRYPT_ALG_HANDLE *phAlgorithm, LPCWSTR pszAlgId, LPCWSTR pszImplementation, ULONG dwFlags)
{
    return GLE_NTStatus(CryptAcquireContext((HCRYPTPROV *) phAlgorithm, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_SILENT));
}

NTSTATUS WINAPI BCryptCloseAlgorithmProvider(BCRYPT_ALG_HANDLE hAlgorithm, ULONG dwFlags)
{
    return GLE_NTStatus(CryptReleaseContext((HCRYPTPROV) hAlgorithm, 0));
}

NTSTATUS WINAPI BCryptGenRandom(BCRYPT_ALG_HANDLE hAlgorithm, PUCHAR pbBuffer, ULONG cbBuffer, ULONG dwFlags)
{
    return GLE_NTStatus(CryptGenRandom((HCRYPTPROV) hAlgorithm, cbBuffer, pbBuffer));
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    return TRUE;
}
