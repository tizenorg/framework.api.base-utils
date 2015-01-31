#ifndef __UTILS_I18N_PRIVATE_H__
#define __UTILS_I18N_PRIVATE_H__

#include <stdbool.h>
#include <dlog.h>
#include <utils_i18n_types.h>

/**
 * @file utils_i18n_private.h
 * @version 0.1
 * @brief utils_i18n_private
 */

#ifdef __cplusplus
extern "C" {
#endif

#define ERR(fmt, arg...) SLOGE("%s:%d " fmt, __FUNCTION__, __LINE__, ##arg)

#define ret_if(expr) do { \
    if (expr) { \
        ERR("(%s)", #expr); \
        return; \
    } \
} while (0)
#define retv_if(expr, val) do { \
    if (expr) { \
        ERR("(%s)", #expr); \
        return (val); \
    } \
} while (0)
#define retm_if(expr, fmt, arg...) do { \
    if (expr) { \
        ERR(fmt, ##arg); \
        return; \
    } \
} while (0)
#define retvm_if(expr, val, fmt, arg...) do { \
    if (expr) { \
        ERR(fmt, ##arg); \
        return (val); \
    } \
} while (0)

#define retex_if(expr, val, fmt, arg...) do { \
      if(expr) { \
         ERR(fmt, ##arg); \
         val; \
         goto CATCH; \
      } \
    } while (0);

typedef enum {
    I18N_U_ZERO_ERROR                = 0,
    I18N_U_ILLEGAL_ARGUMENT_ERROR    = 1,
    I18N_U_MISSING_RESOURCE_ERROR    = 2,
    I18N_U_INVALID_FORMAT_ERROR      = 3,
    I18N_U_FILE_ACCESS_ERROR         = 4,
    I18N_U_INTERNAL_PROGRAM_ERROR    = 5,
    I18N_U_MEMORY_ALLOCATION_ERROR   = 7,
    I18N_U_INDEX_OUTOFBOUNDS_ERROR   = 8,
    I18N_U_INVALID_CHAR_FOUND        = 10,
    I18N_U_BUFFER_OVERFLOW_ERROR     = 15,
    I18N_U_UNSUPPORTED_ERROR         = 16,
    I18N_U_RESOURCE_TYPE_MISMATCH    = 17,
    I18N_U_TOO_MANY_ALIASES_ERROR    = 24,
    I18N_U_COLLATOR_VERSION_MISMATCH = 28,
    I18N_U_USELESS_COLLATOR_ERROR    = 29,
    I18N_U_NO_WRITE_PERMISSION       = 30
} i18n_uerror_code_private_e;

int _i18n_error_mapping ( i18n_uerror_code_private_e err );


#ifdef __cplusplus
}
#endif

#endif  /* __UTILS_I18N_PRIVATE_H__*/
