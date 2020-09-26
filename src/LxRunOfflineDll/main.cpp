#include "config.h"
#include "../lib/error.h"
#include "../lib/fs.h"
#include "../lib/reg.h"
#include "../lib/shortcut.h"
#include "../lib/utils.h"

#ifdef __MINGW32__
extern "C"
{
#endif

#define STDCALL_EXPORT(TYPE) __declspec(dllexport) ##TYPE __stdcall

STDCALL_EXPORT(BOOL) CheckDistroRunning(LPCWSTR lpszDistroName) {
	const auto p = get_distro_dir(lpszDistroName);
	if (check_in_use(p + L"\\rootfs\\init") || check_in_use(p + L"\\ext4.vhdx")) {
		return TRUE;
	}
	return FALSE;
}

#ifdef __MINGW32__
}
#endif
