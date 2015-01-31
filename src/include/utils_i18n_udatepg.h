#ifndef __UTILS_I18N_UDATEPG_H__
#define __UTILS_I18N_UDATEPG_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_udatepg.h
 * @version 0.1
 * @brief utils_i18n_udatepg
 */

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_UDATEPG_MODULE Udatepg
 * @brief The Udatepg module provides flexible generation of date format patterns, like "yy-MM-dd". The user can build up the generator by adding successive patterns.
 *
 * @section CAPI_BASE_UTILS_I18N_UDATEPG_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_UDATEPG_MODULE_OVERVIEW Overview
 * @details The Udatepg module provides flexible generation of date format patterns,
 * like "yy-MM-dd". The user can build up the generator by adding successive patterns.
 * Once that is done, a query can be made using a "skeleton", which is a pattern that
 * just includes the desired fields and lengths. The generator will return the
 * "best fit" pattern corresponding to that skeleton.\n
 * The main method people will use is i18n_udatepg_get_best_pattern(), since normally
 * i18n_udatepg_h is pre-built with data from a particular locale.
 * However, generators can be built directly from other data as well.
 *
 * @section CAPI_BASE_UTILS_I18N_UDATEPG_MODULE_SAMPLE_CODE_1 Sample Code 1
 * @brief Gets the best pattern according to a given locale and formats a current date and time using an i18n_udate_format_h
 * @code
    i18n_udatepg_h pattern_generator = NULL;
    char *locale = I18N_ULOCALE_US;

    dlog_print(DLOG_INFO, LOG_TAG, "pattern_generator\n"); 

    if(!pattern_generator) {
        // open a pattern generator according to a given locale
        i18n_udatepg_create(locale, &pattern_generator);
    }

    if(!pattern_generator) {
        dlog_print(DLOG_INFO, LOG_TAG, "udatpg_open fail");
        return ;
    }

    i18n_uchar bestPattern[64] = {0,};
    char bestPatternString[64] = {0,};
    int bestPatternLength, len;
    const char *custom_format = "yyyy.MM.dd G 'at' HH:mm:ss zzz";
    i18n_uchar uch_custom_format[64];
    int ret = I18N_ERROR_NONE;

    dlog_print(DLOG_INFO, LOG_TAG, "getBestPattern\n"); 

    i18n_ustring_copy_ua(uch_custom_format, custom_format);
    len = i18n_ustring_get_length(uch_custom_format);

    // gets the best pattern that matches the given custom_format
    i18n_udatepg_get_best_pattern(pattern_generator, uch_custom_format, len, bestPattern, 64, &bestPatternLength);

    i18n_ustring_copy_au_n(bestPatternString, bestPattern, 64);
    // gets "MM/dd/yyyy G h:mm:ss a zzz" as the best pattern
    dlog_print(DLOG_INFO, LOG_TAG, "getBestPattern(char[]) : %s \n", bestPatternString);

    // closes a generator
    i18n_udatepg_destroy(pattern_generator);

    i18n_udate_format_h formatter_KR = NULL;
    i18n_udate_format_h formatter_LA = NULL;
    i18n_udate_format_h formatter_SaoPaulo = NULL;
    i18n_uchar formatted[64] = {0,};
    char result[64] = {0,};
    int formattedLength;
    i18n_udate date;
    const char *timezone_KR = "GMT+9:00";   // TimeZone for Korea/Seoul
    const char *timezone_LA = "America/Los_Angeles";
    const char *timezone_SaoPaulo = "America/Sao_Paulo";    // Brazil/East
    i18n_uchar utf16_timezone_KR[64] = {0,};
    i18n_uchar utf16_timezone_LA[64] = {0,};
    i18n_uchar utf16_timezone_SaoPaulo[64] = {0,};

    i18n_ustring_copy_ua_n(utf16_timezone_KR, timezone_KR, strlen(timezone_KR));
    i18n_ustring_copy_ua_n(utf16_timezone_LA, timezone_LA, strlen(timezone_LA));
    i18n_ustring_copy_ua_n(utf16_timezone_SaoPaulo, timezone_SaoPaulo, strlen(timezone_SaoPaulo));

    // creates new i18n_udate_format to format dates and times
    ret = i18n_udate_create(I18N_UDATE_FULL , I18N_UDATE_FULL , locale, utf16_timezone_KR, -1, bestPattern, -1, &formatter_KR);
    if ( ret != I18N_ERROR_NONE ) {
        dlog_print(DLOG_INFO, LOG_TAG, "i18n_udate_create is failed !!! \n");
    }
    if (!formatter_KR) {
        dlog_print(DLOG_INFO, LOG_TAG, "formatter is NULL\n");
    }
    ret = i18n_udate_create(I18N_UDATE_FULL , I18N_UDATE_FULL , locale, utf16_timezone_LA, -1, bestPattern, -1, &formatter_LA);
    if ( ret != I18N_ERROR_NONE ) {
        dlog_print(DLOG_INFO, LOG_TAG, "i18n_udate_create is failed !!! \n");
    }
    if (!formatter_LA) {
        dlog_print(DLOG_INFO, LOG_TAG, "formatter is NULL\n");
    }
    ret = i18n_udate_create(I18N_UDATE_PATTERN , I18N_UDATE_PATTERN , locale, utf16_timezone_SaoPaulo, -1, bestPattern, -1, &formatter_SaoPaulo);
    if ( ret != I18N_ERROR_NONE ) {
        dlog_print(DLOG_INFO, LOG_TAG, "i18n_udate_create is failed !!! \n");
    }
    if (!formatter_LA) {
        dlog_print(DLOG_INFO, LOG_TAG, "formatter is NULL\n");
    }
    
    dlog_print(DLOG_INFO, LOG_TAG, "i18n_udate_format_date\n");

    // gets the current date and time
    i18n_ucalendar_get_now(&date);
    
    // formats a date using i18n_udate_format
    i18n_udate_format_date(formatter_KR, date, formatted, 64, NULL, &formattedLength);
    i18n_ustring_copy_au_n(result, formatted, 64);
    //ex) KOREA/Seoul - Current date : Wednesday, June 18, 2014 1:34:54 PM GMT+09:00
    dlog_print(DLOG_INFO, LOG_TAG, "KOREA/Seoul - Current date : %s\n",result);
    
    // formats a date using i18n_udate_format
    i18n_udate_format_date(formatter_LA, date, formatted, 64, NULL, &formattedLength);
    i18n_ustring_copy_au_n(result, formatted, 64);
    //ex) America/LOS Angeles - Current date : Tuesday, June 17, 2014 9:34:54 PM Pacific Daylight Time
    dlog_print(DLOG_INFO, LOG_TAG, "America/LOS Angeles - Current date : %s\n",result);

    // formats a date using i18n_udate_format
    i18n_udate_format_date(formatter_SaoPaulo, date, formatted, 64, NULL, &formattedLength);
    i18n_ustring_copy_au_n(result, formatted, 64);
    //ex) Brazil/Sao Paulo - Current date : 6 18, 2014 AD, 1:34:54 PM GMT-2
    dlog_print(DLOG_INFO, LOG_TAG, "Brazil/Sao Paulo - Current date : %s\n",result);

    dlog_print(DLOG_INFO, LOG_TAG, "i18n_udate_destroy\n");
    // destroy a i18n_udate_format
    i18n_udate_destroy(formatter_KR);
    i18n_udate_destroy(formatter_LA);
    i18n_udate_destroy(formatter_SaoPaulo);
 * @endcode
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UDATEPG_MODULE
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief Opens a generator according to a given locale.
  * @since_tizen 2.3
  * @remarks Must release @a dtpg using i18n_udatepg_destroy().
  *
  * @param[in] locale
  * @param[out] dtpg A pointer to i18n_udatepg_h
  *
  * @retval #I18N_ERROR_NONE Successful
  * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
  */
int i18n_udatepg_create ( const char *locale, i18n_udatepg_h *dtpg );

/**
  * @brief Closes a generator.
  * @since_tizen 2.3
  *
  * @param[in] dtpg A pointer to i18n_udatepg_h
  *
  * @retval #I18N_ERROR_NONE Successful
  * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
  */
int i18n_udatepg_destroy ( i18n_udatepg_h dtpg );

/**
 * @brief Gets the best pattern matching the input skeleton.
 * @details It is guaranteed to have all of the fields in the skeleton.
 * @since_tizen 2.3
 *
 * @remarks This function uses a non-const i18n_udatepg_h:
 * It uses a stateful pattern parser which is set up for each generator object,
 * rather than creating one for each function call.
 * Consecutive calls to this function do not affect each other,
 * but this function cannot be used concurrently on a single generator object.
 *
 * @param[in] dtpg A pointer to i18n_udatepg_h
 * @param[in] skeleton The skeleton is a pattern containing only the variable fields\n
 * For example, "MMMdd" and "mmhh" are skeletons.
 * @param[in] len The length of the skeleton
 * @param[out] best_pattern The best pattern found from the given skeleton
 * @param[in] capacity The capacity of @a best_pattern
 * @param[out] best_pattern_len The length of @a best_pattern
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @retval #I18N_ERROR_BUFFER_OVERFLOW A result would not fit in the supplied buffer
 */
int i18n_udatepg_get_best_pattern ( i18n_udatepg_h dtpg, const i18n_uchar *skeleton, int32_t len, i18n_uchar *best_pattern, int32_t capacity, int32_t *best_pattern_len );

#ifdef __cplusplus
}
#endif

/**
 * @}
 * @}
 */

#endif	/* __UTILS_I18N_UDATEPG_H__*/
