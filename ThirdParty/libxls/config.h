#ifndef CONFIG_H
#define CONFIG_H

// config.h for MSVC.
#undef HAVE_ICONV
#undef HAVE_ASPRINTF

#define PACKAGE_VERSION "1.3.4"

#ifdef _MSC_VER
#pragma warning (disable : 4005)
#pragma warning (disable : 4244)
#pragma warning (disable : 4996)
#endif

#endif
