#ifndef __UTILS_I18N_UDATE_H__
#define __UTILS_I18N_UDATE_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_udate.h
 * @version 0.1
 * @brief utils_i18n_udate
 */

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_UDATE_MODULE Udate
 * @brief The Udate module consists of functions that convert dates and time from their 
 * internal representations to textual form and back again in a language-independent 
 * manner.
 *
 * @section CAPI_BASE_UTILS_I18N_UDATE_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_UDATE_MODULE_OVERVIEW Overview
 * @details The Udate module consists of functions that convert dates and time from their
 * internal representations to textual form and back again in a language-independent
 * manner. Converting from the internal representation (milliseconds since midnight,
 * January 1, 1970) to text is known as "formatting," and converting from text to
 * milliseconds is known as "parsing". We currently define only one concrete handle
 * i18n_udate_format_h, which can handle pretty much all normal date formatting and parsing
 * actions.\n
 * The Udate module helps you format and parse dates for any locale. Your code can be
 * completely independent of the locale conventions for months, days of the week,
 * or even the calendar format: lunar vs. solar.
 *
 * @section CAPI_BASE_UTILS_I18N_UDATE_MODULE_SAMPLE_CODE_1 Sample Code 1
 * @brief Gets the best pattern according to a given locale and formats a current date and time using a locale_udate_format_h
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

    // creates new i18n_udate_format_h to format dates and times
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
    
    // formats a date using i18n_udate_format_h
    i18n_udate_format_date(formatter_KR, date, formatted, 64, NULL, &formattedLength);
    i18n_ustring_copy_au_n(result, formatted, 64);
    //ex) KOREA/Seoul - Current date : Wednesday, June 18, 2014 1:34:54 PM GMT+09:00
    dlog_print(DLOG_INFO, LOG_TAG, "KOREA/Seoul - Current date : %s\n",result);
    
    // formats a date using i18n_udate_format
    i18n_udate_format_date(formatter_LA, date, formatted, 64, NULL, &formattedLength);
    i18n_ustring_copy_au_n(result, formatted, 64);
    //ex) America/LOS Angeles - Current date : Tuesday, June 17, 2014 9:34:54 PM Pacific Daylight Time
    dlog_print(DLOG_INFO, LOG_TAG, "America/LOS Angeles - Current date : %s\n",result);

    // formats a date using i18n_udate_format_h
    i18n_udate_format_date(formatter_SaoPaulo, date, formatted, 64, NULL, &formattedLength);
    i18n_ustring_copy_au_n(result, formatted, 64);
    //ex) Brazil/Sao Paulo - Current date : 6 18, 2014 AD, 1:34:54 PM GMT-2
    dlog_print(DLOG_INFO, LOG_TAG, "Brazil/Sao Paulo - Current date : %s\n",result);

    dlog_print(DLOG_INFO, LOG_TAG, "i18n_udate_destroy\n"); 
    // destroy a i18n_udate_format_h
    i18n_udate_destroy(formatter_KR);
    i18n_udate_destroy(formatter_LA);
    i18n_udate_destroy(formatter_SaoPaulo);
 * @endcode
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UDATE_MODULE
 * @{
 */

/**
 * @brief Creates a new i18n_udate_format_h for formatting and parsing dates and times.
 * @details A i18n_udate_format_h may be used to format dates in calls to {@link #i18n_udate_create()}.
 * @since_tizen 2.3
 * @remarks Must release @a format using i18n_udate_destroy().
 *
 * @param[in] time_style The style used to format times\n One of #I18N_UDATE_FULL, #I18N_UDATE_LONG,
 * #I18N_UDATE_MEDIUM, #I18N_UDATE_SHORT, #I18N_UDATE_DEFAULT, or #I18N_UDATE_NONE (relative time styles
 * are not currently supported).
 * @param[in] date_style The style used to format dates\n One of #I18N_UDATE_FULL, #I18N_UDATE_LONG,
 * #I18N_UDATE_MEDIUM, #I18N_UDATE_SHORT, #I18N_UDATE_DEFAULT, #I18N_UDATE_RELATIVE, #I18N_UDATE_LONG_RELATIVE,
 * #I18N_UDATE_MEDIUM_RELATIVE, #I18N_UDATE_SHORT_RELATIVE, or #I18N_UDATE_NONE
 * @param[in] locale The locale specifying the formatting conventions
 * @param[in] tz_id A timezone ID specifying the timezone to use\n  If @c 0, use the default timezone
 * @param[in] tz_id_len The length of @a tz_id, otherwise @c -1 if null-terminated
 * @param[in] pattern A pattern specifying the format to use. The pattern is generated by Udatepg module
 * @param[in] pattern_len The number of characters in the pattern, or otherwise @c -1 if null-terminated
 * @param[out] format A pointer to an i18n_udate_format_h to use for formatting dates and times, otherwise @c 0 if an error occurs
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_udate_create ( i18n_udate_format_style_e time_style, i18n_udate_format_style_e date_style, const char *locale, const i18n_uchar *tz_id, int32_t tz_id_len, const i18n_uchar *pattern, int pattern_len, i18n_udate_format_h *format );

/**
* @brief Destroys an i18n_udate_format_h.
* @details Once destroyed, an i18n_udate_format_h may no longer be used.
* @since_tizen 2.3
*
* @param[in] format The formatter to close.
*
* @retval #I18N_ERROR_NONE Successful
* @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
*/
int i18n_udate_destroy ( i18n_udate_format_h format );

/**
* @brief Formats a date using an i18n_udate_format_h.
* @details The date will be formatted using the conventions specified in {@link #i18n_udate_create()}
* @since_tizen 2.3
*
* @param[in] format The formatter to use
* @param[in] date_to_format The date to format
* @param[out] result A pointer to a buffer to receive the formatted number
* @param[in] result_len The maximum size of the result
* @param[in] pos A pointer to an i18n_ufield_position\n
* On input, position->field is read\n
* On output, position->beginIndex and position->endIndex indicate
* the beginning and ending indices of field number position->field, if such a field exists\n
* This parameter may be @c NULL, in which case no field
* position data is returned.
* @param[out] buf_size_needed The total buffer size needed\n
* If greater than @a result_len, the output was truncated.
*
* @retval #I18N_ERROR_NONE Successful
* @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
*/
int i18n_udate_format_date ( const i18n_udate_format_h format, i18n_udate date_to_format, i18n_uchar *result, int32_t result_len, i18n_ufield_position_h pos, int32_t *buf_size_needed );

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif	/* __UTILS_I18N_UDATE_H__*/
