#ifndef __UTILS_I18N_UCALENDAR_H__
#define __UTILS_I18N_UCALENDAR_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_ucalendar.h
 * @version 0.1
 * @brief utils_i18n_ucalendar
 */

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE Ucalendar
 * @brief The Ucalendar is used for converting between an udate module and a set of integer fields 
 *       such as #I18N_UCALENDAR_YEAR, #I18N_UCALENDAR_MONTH, #I18N_UCALENDAR_DATE, #I18N_UCALENDAR_HOUR, and so on.
 * @section CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 * @section CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE_OVERVIEW Overview
 * @details The Ucalendar is used for converting between an udate module and a set of integer fields
 *       such as #I18N_UCALENDAR_YEAR, #I18N_UCALENDAR_MONTH, #I18N_UCALENDAR_DATE, #I18N_UCALENDAR_HOUR, and so on.
 *       (An udate module represents a specific instant in time with millisecond precision. See udate for
 *       information about the udate.)
 * @section CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE_SAMPLE_CODE_1 Sample Code 1
 * @brief Converts the given date and time to the corresponding UTC time(number of seconds that have elapsed since January 1, 1970), considering the given time zone
 * @code
 
 #define ms2sec(ms) (long long int)(ms)/1000.0
 
  // get time in sec from input date and time
  long long int _time_convert_itol(char *tzid, int y, int mon, int d, int h, int min, int s)
 {
     long long int lli;
     i18n_ucalendar_h ucal;
     i18n_udate date;
     int ret = I18N_ERROR_NONE;
     int year, month, day, hour, minute, second;
     int len;
 
     i18n_uchar *_tzid = NULL;
 
     if (tzid == NULL) {
         tzid = "Etc/GMT";
     }
     _tzid = (i18n_uchar*)calloc(strlen(tzid) + 1, sizeof(i18n_uchar));
     if (_tzid == NULL) {
         return -1;
     }
     // converts 'tzid' to unicode string
     i18n_ustring_copy_ua(_tzid, tzid);
 
     // gets length of '_tzid'
     i18n_ustring_get_length(_tzid, &len);
     // creates i18n_ucalendar_h
     ret = i18n_ucalendar_create(_tzid, len, "en_US", I18N_UCALENDAR_TRADITIONAL, &ucal);
     if (ret) {
         dlog_print(DLOG_INFO, LOG_TAG, "i18n_ucalendar_create failed.\n");
         return -1;
     }
 
     // sets i18n_ucalendar_h's date
     i18n_ucalendar_set_date_time(ucal, y, mon-1, d, h, min, s);
 
     // gets the current value of a field from i18n_ucalendar_h
     i18n_ucalendar_get(ucal, I18N_UCALENDAR_YEAR, &year);
     i18n_ucalendar_get(ucal, I18N_UCALENDAR_MONTH, &month);
     i18n_ucalendar_get(ucal, I18N_UCALENDAR_DATE, &day);
     i18n_ucalendar_get(ucal, I18N_UCALENDAR_HOUR, &hour);
     i18n_ucalendar_get(ucal, I18N_UCALENDAR_MINUTE, &minute);
     i18n_ucalendar_get(ucal, I18N_UCALENDAR_SECOND, &second);
     dlog_print(DLOG_INFO, LOG_TAG, "Date from ucal, year:%d month:%d day:%d hour:%d minute:%d second:%d.\n",year, month, day, hour, minute, second);
 
     // gets i18n_ucalendar's current time and converts it from milliseconds to seconds
     i18n_ucalendar_get_milliseconds(ucal, &date);
     lli = ms2sec(date);
     // destroys i18n_ucalendar_h
     i18n_ucalendar_destroy(ucal);
     if (_tzid) {
         free(_tzid);
     }
 
     return lli;
 }
 * @endcode
 *
 * @section CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE_SAMPLE_CODE_2 Sample Code 2
 * @brief Describes an example that uses _time_convert_itol from 'Sample Code 2'
 * @code
       // converts the given time to UTC time(number of seconds that have elapsed since January 1, 1970)
     long long int time = _time_convert_itol("Etc/GMT", 2014, 5, 28, 15, 14, 0);
     dlog_print(DLOG_INFO, LOG_TAG, "Time Zone: %s\t, %d/%d/%d/%d/%d/%d\n", "Etc/GMT", 2014, 5, 28, 15, 14, 0);
     dlog_print(DLOG_INFO, LOG_TAG, "_time_convert_itol test : %lld\n", time);
 * @endcode
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE
 * @{
 */

/**
 * @brief Sets the default time zone.
 * @since_tizen 2.3
 *
 * @param[in] zone_id null-terminated time zone ID
 *
 * @retval #I18N_ERROR_NONE Successful
 */
int i18n_ucalendar_set_default_timezone ( const i18n_uchar *zone_id );

/**
 * @brief Gets the current date and time.
 * @details The value returned is represented as milliseconds from the epoch.
 * @since_tizen 2.3
 *
 * @param[out] date The current date and time
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_get_now ( i18n_udate *date );

/**
 * @brief Creates an i18n_ucalendar_h.
 * An i18n_ucalendar_h may be used to convert a millisecond value to a year,
 * month, and day.
 * @details Note: When an unknown TimeZone ID is specified, the i18n_ucalendar_h returned
 * by the function is initialized with GMT ("Etc/GMT") without any
 * errors/warnings.  
 * @since_tizen 2.3
 * @remarks Must release @a calendar using i18n_ucalendar_destroy().
 *
 * @param[in] zone_id The desired TimeZone ID \n
 *                    If @c 0, use the default time zone.
 * @param[in] len The length of the zone ID,
 *                    otherwise @c -1 if null-terminated
 * @param[in] locale The desired locale
 * @param[in] type The type of #I18N_UCALENDAR_DEFAULT to create \n
 *                  This can be #I18N_UCALENDAR_GREGORIAN to create the Gregorian
 * calendar for the locale, or #I18N_UCALENDAR_DEFAULT to create the default calendar for the locale (the
 * default calendar may also be Gregorian). 
 * @param[out] calendar A pointer to an i18n_ucalendar_h,
 *                    otherwise @c 0 if an error occurs
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_create ( const i18n_uchar *zone_id, int32_t len, const char *locale, i18n_ucalendar_type_e type, i18n_ucalendar_h *calendar );

/**
 * @brief Destroys an i18n_ucalendar_h.
 * @details Once destroyed, an i18n_ucalendar_h may no longer be used.
 * @since_tizen 2.3
 *
 * @param[in] calendar The i18n_ucalendar_h to destroy
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_destroy ( i18n_ucalendar_h calendar );

/**
 * @brief Open a copy of a i18n_ucalendar.
 * This function performs a deep copy.
 * @since_tizen 2.3
 *
 * @param[in] cal The i18n_ucalendar_h to copy
 * @param[out] identical_to_cal A pointer to a i18n_ucalendar_h identical to cal.
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_clone ( const i18n_ucalendar_h cal, i18n_ucalendar_h *identical_to_cal );

/**
 * @brief Gets the display name for an i18n_ucalendar_h's TimeZone.
 * @details A display name is suitable for presentation to a user.
 * @since_tizen 2.3
 *
 * @param[in] calendar     The i18n_ucalendar_h to query
 * @param[in] type         The desired display name format \n
 *                          One of #I18N_UCALENDAR_STANDARD, #I18N_UCALENDAR_SHORT_STANDARD, #I18N_UCALENDAR_DST, or #I18N_UCALENDAR_SHORT_DST
 * @param[in] locale       The desired locale for the display name
 * @param[out] result      A pointer to a buffer to receive the formatted number
 * @param[in] result_len The maximum size of the result
 * @param[out] buf_size_needed The total buffer size needed \n 
 *              If greater than @a result_len, the output is truncated
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_get_timezone_displayname ( const i18n_ucalendar_h calendar, i18n_ucalendar_displayname_type_e type, const char *locale, i18n_uchar *result, int32_t result_len, int32_t *buf_size_needed );

/**
 * @brief Determines if an i18n_ucalendar_h is currently in daylight savings time.
 * @details Daylight savings time is not used in all parts of the world.
 * @since_tizen 2.3
 *
 * @param[in] calendar The i18n_ucalendar_h to query
 * @param[out] is_in   If @c true @a calendar is currently in daylight savings time,
 *                   otherwise @c false
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_is_in_daylight_time ( const i18n_ucalendar_h calendar, i18n_ubool *is_in );

/**
 * @brief Sets the value of a field in a i18n_ucalendar_h.
 * @details All fields are represented as 32-bit integers.
 * @since_tizen 2.3
 *
 * @param[in] cal The i18n_ucalendar to set.
 * @param[in] field The field to set \n
 *              One of #I18N_UCALENDAR_ERA, #I18N_UCALENDAR_YEAR,
 * #I18N_UCALENDAR_MONTH, #I18N_UCALENDAR_WEEK_OF_YEAR, #I18N_UCALENDAR_WEEK_OF_MONTH,
 * #I18N_UCALENDAR_DATE, #I18N_UCALENDAR_DAY_OF_YEAR, #I18N_UCALENDAR_DAY_OF_WEEK,
 * #I18N_UCALENDAR_DAY_OF_WEEK_IN_MONTH, #I18N_UCALENDAR_AM_PM, #I18N_UCALENDAR_HOUR,
 * #I18N_UCALENDAR_HOUR_OF_DAY, #I18N_UCALENDAR_MINUTE, #I18N_UCALENDAR_SECOND,
 * #I18N_UCALENDAR_MILLISECOND, #I18N_UCALENDAR_ZONE_OFFSET, #I18N_UCALENDAR_DST_OFFSET.
 * @param[in] val The desired value of @a field.
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_set ( i18n_ucalendar_h cal, i18n_ucalendar_date_fields_e field, int32_t val );

/**
 * @brief Sets a numeric attribute associated with an i18n_ucalendar_h.
 * @details Numeric attributes include the first day of the week, or the minimal number
 * of days in the first week of the month.
 * @since_tizen 2.3
 *
 * @param[in] calendar The i18n_ucalendar_h to set.
 * @param[in] attr The desired attribute \n
 *              One of #I18N_UCALENDAR_LENIENT, #I18N_UCALENDAR_FIRST_DAY_OF_WEEK,
 * or #I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK.
 *
 * @param[in] val The new value of @a attr
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_set_attribute ( i18n_ucalendar_h calendar, i18n_ucalendar_attribute_e attr, int32_t val );

/**
 * @brief Gets a numeric attribute associated with an i18n_ucalendar.
 * @details Numeric attributes include the first day of the week, or the minimal numbers of days
 * in the first week of the month.
 *
 * @since_tizen 2.3
 *
 * @param[in] calendar The i18n_ucalendar to query.
 * @param[in] attr The desired attribute \n
 *              One of #I18N_UCALENDAR_LENIENT, #I18N_UCALENDAR_FIRST_DAY_OF_WEEK,
 * or #I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK.
 *
 * @param[out] val The value of @a attr
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_get_attribute ( i18n_ucalendar_h calendar, i18n_ucalendar_attribute_e attr, int32_t *val);

/**
 * @brief Gets an i18n_ucalendar_h's current time in milliseconds.
 * @details The time is represented as milliseconds from the epoch.
 * @since_tizen 2.3
 *
 * @param[in] calendar The i18n_ucalendar_h to query
 * @param[out] date The calendar's current time in milliseconds
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @see i18n_ucalendar_set_milliseconds()
 * @see i18n_ucalendar_set_date_time()
 */
int i18n_ucalendar_get_milliseconds( const i18n_ucalendar_h calendar, i18n_udate *date );

/**
 * @brief Sets an i18n_ucalendar_h's current time in milliseconds.
 * @details The time is represented as milliseconds from the epoch.
 * @since_tizen 2.3
 *
 * @param[in] calendar The i18n_ucalendar_h to set
 * @param[in] milliseconds The desired date and time
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @see i18n_ucalendar_get_milliseconds()
 * @see i18n_ucalendar_set_date_time()
 */
int i18n_ucalendar_set_milliseconds ( i18n_ucalendar_h calendar, i18n_udate milliseconds );

/**
 * @brief Sets an i18n_ucalendar_h's current date.
 * @details The date is represented as a series of 32-bit integers.
 * @since_tizen 2.3
 *
 * @param[in] calendar The i18n_ucalendar_h to set
 * @param[in] year The desired year
 * @param[in] month The desired month\n
 *          One of #I18N_UCALENDAR_JANUARY, #I18N_UCALENDAR_FEBRUARY, #I18N_UCALENDAR_MARCH, #I18N_UCALENDAR_APRIL, #I18N_UCALENDAR_MAY,
 *          #I18N_UCALENDAR_JUNE, #I18N_UCALENDAR_JULY, #I18N_UCALENDAR_AUGUST, #I18N_UCALENDAR_SEPTEMBER, #I18N_UCALENDAR_OCTOBER, #I18N_UCALENDAR_NOVEMBER, or #I18N_UCALENDAR_DECEMBER
 * @param[in] date The desired day of the month
 * @param[in] hour The desired hour of the day
 * @param[in] min The desired minute
 * @param[in] sec The desired second
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 * @see i18n_ucalendar_get_milliseconds()
 * @see i18n_ucalendar_set_milliseconds()
 */
int i18n_ucalendar_set_date_time ( i18n_ucalendar_h calendar, int32_t year, int32_t month, int32_t date, int32_t hour, int32_t min, int32_t sec );

/**
 * @brief Returns @c true if two i18n_ucalendar_hs are equivalent.
 * @details Equivalent i18n_ucalendar_hs will behave identically, but they may be set to
 * different times.
 * @since_tizen 2.3
 *
 * @param[in] calendar1 The first of the i18n_ucalendar_hs to compare
 * @param[in] calendar2 The second of the i18n_ucalendar_hs to compare
 * @param[out] equiv If @c true @a cal1 and @a cal2 are equivalent, otherwise @c false
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_is_equivalent_to ( const i18n_ucalendar_h calendar1, const i18n_ucalendar_h calendar2, i18n_ubool *equiv );

/**
 * @brief Adds a specified signed amount to a particular field in a i18n_ucalendar_h.
 * @details This can modify more significant fields in the calendar.
 * @since_tizen 2.3
 *
 * @param[in] calendar The i18n_ucalendar_h to which to add
 * @param[in] field The field to which to add the signed value\n One of #I18N_UCALENDAR_ERA, #I18N_UCALENDAR_YEAR, #I18N_UCALENDAR_MONTH,
 * #I18N_UCALENDAR_WEEK_OF_YEAR, #I18N_UCALENDAR_WEEK_OF_MONTH, #I18N_UCALENDAR_DATE, #I18N_UCALENDAR_DAY_OF_YEAR, #I18N_UCALENDAR_DAY_OF_WEEK,
 * #I18N_UCALENDAR_DAY_OF_WEEK_IN_MONTH, #I18N_UCALENDAR_AM_PM, #I18N_UCALENDAR_HOUR, #I18N_UCALENDAR_HOUR_OF_DAY, #I18N_UCALENDAR_MINUTE, #I18N_UCALENDAR_SECOND,
 * #I18N_UCALENDAR_MILLISECOND, #I18N_UCALENDAR_ZONE_OFFSET, or #I18N_UCALENDAR_DST_OFFSET.
 * @param[in] amount The signed amount to add to the field \n
 *              If the amount causes the value to exceed to maximum or minimum values for that field,
 *              other fields are modified to preserve the magnitude of the change.
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter

 */
int i18n_ucalendar_add ( i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field, int32_t amount );

/**
 * @brief Gets the current value of a field from an i18n_ucalendar_h.
 * @details All fields are represented as 32-bit integers.
 * @since_tizen 2.3
 *
 * @param[in] calendar The i18n_ucalendar_h to query
 * @param[in] field The desired field\n One of I18N_UCALENDAR_ERA, I18N_UCALENDAR_YEAR, I18N_UCALENDAR_MONTH,
 * #I18N_UCALENDAR_WEEK_OF_YEAR, #I18N_UCALENDAR_WEEK_OF_MONTH, #I18N_UCALENDAR_DATE, #I18N_UCALENDAR_DAY_OF_YEAR, #I18N_UCALENDAR_DAY_OF_WEEK,
 * #I18N_UCALENDAR_DAY_OF_WEEK_IN_MONTH, #I18N_UCALENDAR_AM_PM, #I18N_UCALENDAR_HOUR, #I18N_UCALENDAR_HOUR_OF_DAY, #I18N_UCALENDAR_MINUTE, #I18N_UCALENDAR_SECOND,
 * #I18N_UCALENDAR_MILLISECOND, #I18N_UCALENDAR_ZONE_OFFSET, or #I18N_UCALENDAR_DST_OFFSET.
 * @param[out] val The value of the desired field.
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ucalendar_get ( const i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field, int32_t *val );

/**
 * @}
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif	/* __I18N_UCALENDAR_H__*/
