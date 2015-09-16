#pragma once

// Define import/export macro for public symbols
#ifdef CURVE_LIBRARY_DYNAMIC
#   ifdef CURVE_COMPILER_GCC
#       define CURVE_DECL_EXPORT __attribute__((visibility("default")))
#       define CURVE_DECL_IMPORT __attribute__((visibility("default")))
#   else
#       define CURVE_DECL_EXPORT __declspec(dllexport)
#       define CURVE_DECL_IMPORT __declspec(dllimport)
#   endif
#   ifdef CURVE_LIBRARY
#       define CURVE_API CURVE_DECL_EXPORT
#   else
#       define CURVE_API CURVE_DECL_IMPORT
#   endif
#else
#   define CURVE_API
#endif
