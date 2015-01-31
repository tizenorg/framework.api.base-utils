#ifndef __UTILS_I18N_UNUMBER_H__
#define __UTILS_I18N_UNUMBER_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_unumber.h
 * @version 0.1
 * @brief utils_i18n_unumber
 */

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_UNUMBER_MODULE Unumber
 * @brief The Unumber module helps you format and parse numbers for any locale.
 *
 * @section CAPI_BASE_UTILS_I18N_UNUMBER_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_UNUMBER_MODULE_OVERVIEW Overview
 * @details The Unumber module helps you format and parse numbers for any locale.
 * Your code can be completely independent of the locale conventions for decimal
 * points, thousands-separators, or even the particular decimal digits used,
 * or whether the number format is even decimal. There are different number format
 * styles like decimal, currency, percent and spellout.
 *
 * @section CAPI_BASE_UTILS_I18N_UNUMBER_MODULE_SAMPLE_CODE_1 Sample Code 1
 * @brief Gets a currency symbol according to a given locale.
 * @code
    int buf_len;
    i18n_uchar u_buffer[64];
    char a_buffer[64];
    i18n_unumber_format_h num_format;

    // creates and returns a new unumber_format
    i18n_unumber_create(I18N_UNUMBER_CURRENCY, NULL, -1, "en_US", NULL, &num_format);

    // gets a symbol associated with i18n_unumber_format
    i18n_unumber_get_symbol(num_format, I18N_UNUMBER_CURRENCY_SYMBOL, u_buffer, 64, &buf_len);
 
    i18n_ustring_copy_au(a_buffer, u_buffer);
    // en_US currency symbol: $
    dlog_print(DLOG_INFO, LOG_TAG, "en_US currency symbol: %s \n", a_buffer);

    // destroys i18n_unumber_format
    i18n_unumber_destroy(num_format);
 * @endcode
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UNUMBER_MODULE
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Creates and returns a new unumber_format_h for formatting and parsing numbers.
 * @details A unumber_format_style_e may be used to format numbers by calling {@link #i18n_unumber_create()}.
 * The caller must call {@link #i18n_unumber_destroy() } when done to release resources used by this object.
 * @since_tizen 2.3
 * @remarks Must release @a num_format using i18n_unumber_destroy().
 *
 * @param[in] style The type of number format to open: one of
 * #I18N_UNUMBER_DECIMAL,
 * #I18N_UNUMBER_CURRENCY,
 * #I18N_UNUMBER_PERCENT,
 * #I18N_UNUMBER_SCIENTIFIC,
 * #I18N_UNUMBER_SPELLOUT,
 * #I18N_UNUMBER_ORDINAL,
 * #I18N_UNUMBER_DURATION,
 * #I18N_UNUMBER_NUMBERING_SYSTEM,
 * #I18N_UNUMBER_PATTERN_RULEBASED,
 * or #I18N_UNUMBER_DEFAULT \n
 * If #I18N_UNUMBER_PATTERN_DECIMAL or #I18N_UNUMBER_PATTERN_RULEBASED is passed then the number format is opened using the given pattern, which must conform
 * to the syntax described in DecimalFormat or RuleBasedNumberFormat, respectively.
 * @param[in] pattern A pattern specifying the format to use \n This parameter is ignored unless the style is #I18N_UNUMBER_PATTERN_DECIMAL or #I18N_UNUMBER_PATTERN_RULEBASED.
 * @param[in] pattern_len The number of characters in the pattern, otherwise @c -1 if null-terminated\n
 * This parameter is ignored unless the style is @c I18N_UNUMBER_PATTERN.
 * @param[in] locale A locale identifier to use to determine formatting
 * and parsing conventions, otherwise @c NULL to use the default locale.
 * @param[in] parse_err A pointer to a i18n_unumber_uparse_error_h struct to receive the
 * details of any parsing errors, otherwise @c NULL if no parsing error details
 * are desired.
 * @param[out] num_format A pointer to a newly created i18n_unumber_format_h, otherwise @c NULL if an
 * error occurrs.
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_unumber_create ( i18n_unumber_format_style_e style, const i18n_uchar *pattern, int32_t pattern_len, const char *locale, 
    i18n_uparse_error_s *parse_err, i18n_unumber_format_h *num_format );

/**
* @brief Destroys an i18n_unumber_format_h.
* @details Once destroyed, an i18n_unumber_format may no longer be used.
* @since_tizen 2.3
*
* @param[in] fmt The formatter to destroy
*
* @retval #I18N_ERROR_NONE Successful
*/
int i18n_unumber_destroy ( i18n_unumber_format_h fmt );

/**
* @brief Gets a symbol associated with an i18n_unumber_format_h.
* @details An i18n_unumber_format_h uses symbols to represent the special locale-dependent characters in a number,
* for example the percent sign. This API is not supported for rule-based formatters.
* @since_tizen 2.3
*
* @param[in] fmt The formatter to query.
* @param[in] symbol The unumber_format_symbol_e constant for the symbol to get
* @param[out] buffer The string buffer that will receive the symbol string\n
* If it is @c NULL, then only the length of the symbol is returned.
* @param[in] size The size of the string buffer
* @param[out] len_symbol The length of the symbol\n
* The buffer is not modified if <code>length &gt;= size</code>
*
* @retval #I18N_ERROR_NONE Successful.
* @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
*/
int i18n_unumber_get_symbol ( const i18n_unumber_format_h fmt, i18n_unumber_format_symbol_e symbol, i18n_uchar *buffer, int32_t size, int32_t *len_symbol );

#ifdef __cplusplus
}
#endif

/**
 * @}
 * @}
 */

#endif  /* __UTILS_I18N_UNUMBER_H__*/
