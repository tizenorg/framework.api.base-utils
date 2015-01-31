#ifndef __UTILS_I18N_ULOCALE_H__
#define __UTILS_I18N_ULOCALE_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_ulocale.h  
 * @version 0.1 
 * @brief utils_i18n_ulocale
 */

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_ULOCALE_MODULE Ulocale
 * @brief A ulocale represents a specific geographical, political, or cultural region.
 * @section CAPI_BASE_UTILS_I18N_ULOCALE_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_ULOCALE_MODULE_OVERVIEW Overview
 * @details A ulocale represents a specific geographical, political, or cultural region.
 * An operation that requires a ulocale to perform its task is called locale-sensitive
 * and uses the ulocale to tailor information for the user. For example, displaying
 * a number is a locale-sensitive operation. The number should be formatted according
 * to the customs/conventions of the user's native country, region, or culture.
 * In the C APIs, a locale is simply a const char string.
 *
 * @section CAPI_BASE_UTILS_I18N_ULOCALE_MODULE_SAMPLE_CODE_1 Sample Code 1
 * @brief Gets a default locale and a full name for the locale
 * @code
    const char *locale;
    const char *in_locale_id = "en_US";
    char language[64] = {0,};
    i18n_uchar result_w[64] = {0,};
    char result[64] = {0,};
    int language_capacity = 64;
    int buf_size_language;
    int buf_size_display_name;
    int ret = I18N_ERROR_NONE;

    // Sets default locale
    ret = i18n_ulocale_set_default(getenv("LC_TIME"));

    // Gets default locale
    ret = i18n_ulocale_get_default(&locale);
    if ( ret != I18N_ERROR_NONE ) {
        dlog_print(DLOG_INFO, LOG_TAG, "i18n_ulocale_get_default() is failed!!! \n");
    }
    dlog_print(DLOG_INFO, LOG_TAG, "default locale : %s\n", locale);    // default locale : en_GB.UTF-8

    // Gets the language code for the specified locale
    ret = i18n_ulocale_get_language(locale, language, language_capacity, &buf_size_language);
    if ( ret != I18N_ERROR_NONE ) {
        dlog_print(DLOG_INFO, LOG_TAG, "i18n_ulocale_get_language() is failed!!! \n");
    }
    dlog_print(DLOG_INFO, LOG_TAG, "language code for the locale : %s\n", language);  // language code for the locale : en

    // Gets the full name suitable for display for the specified locale
    ret = i18n_ulocale_get_display_name(locale, in_locale_id, result_w, 64, &buf_size_display_name);
    i18n_ustring_copy_au(result, result_w);
    dlog_print(DLOG_INFO, LOG_TAG, "full name suitable for the locale : %s\n", result); // full name suitable for the locale : English (United Kingdom)
 * @endcode
 *
 * @section CAPI_BASE_UTILS_I18N_ULOCALE_MODULE_SAMPLE_CODE_2 Sample Code 2
 * @brief See all available locales
 * @code
    int i = 0;
    int32_t count = i18n_ulocale_count_available();
    for(i = 0; i < count; i++)
    {
        dlog_print(DLOG_INFO, LOG_TAG, "Available locale %d : %s " ,i, i18n_ulocale_get_available(i));
        //   ...
        //Available locale 5 : en_GB
        //Available locale 6 : en_US
        //Available locale 7 : en_US_POSIX
        //   ...
    }
 * @endcode
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_ULOCALE_MODULE
 * @{
 */ 
    
#ifdef __cplusplus
extern "C" {
#endif  

/**
 * @brief Gets the default locale.
 * @details The returned string is a snapshot in time, and will remain valid
 * and unchanged even when i18n_ulocale_set_default() is called.
 * @since_tizen 2.3
 *
 * @param[out] locale The default locale
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ulocale_get_default ( const char **locale );

/**
 * @brief Sets the default locale.
 * @since_tizen 2.3
 *
 * @param[in] locale_id The new ICU default locale\n
 * A value of @c NULL will try to get the system's default locale.
 *
 * @retval #I18N_ERROR_NONE Successful
 */
int i18n_ulocale_set_default ( const char *locale_id );

/**
 * @brief Gets the language code for the specified locale.
 * @since_tizen 2.3
 *
 * @param[in] locale_id The locale to get the ISO language code with
 * @param[out] language The language code for @a locale_id
 * @param[in] language_capacity The size of the language buffer to store the language code with
 * @param[out] buf_size_language The actual buffer size needed for the language code\n
 * If it's greater than @a language_capacity, the returned language code will be truncated.
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ulocale_get_language ( const char *locale_id, char *language, int32_t language_capacity, int32_t *buf_size_language );

/**
 * @brief Gets the country code for the specified locale.
 * @since_tizen 2.3
 *
 * @param[in]  locale_id The locale to get the country code with
 * @param[out] country the country code for locale_id
 * @param[in]  country_capacity The size of the country buffer to store the country code with
 * @param[out] error error information if retrieving the country code is failed
 *                   (It must not indicate a failure before the function call)
 *
 * @return The actual buffer size needed for the language code\n
 * If it's greater than @a language_capacity, the returned language code will be truncated.
 */
int32_t i18n_ulocale_get_country ( const char *locale_id, char *country, int32_t country_capacity, int *error );

/**
 * @brief Gets the full name suitable for display for the specified locale.
 * @since_tizen 2.3
 *
 * @param[in] locale_id The locale to get the displayable name with\n
 * @c NULL may be used to specify the default.
 * @param[in] in_locale_id The locale to be used to display the name\n
 * @c NULL may be used to specify the default.
 * @param[out] result The displayable name for locale_id
 * @param[in] max_result_size The size of the name buffer to store the displayable full name with
 * @param[out] buf_size_display_name The actual buffer size needed for the displayable name\n
 * If it's greater than @a max_result_size, the returned displayable name will be truncated.
 *
 * @retval #I18N_ERROR_NONE Successful
 * @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
 */
int i18n_ulocale_get_display_name ( const char *locale_id, const char *in_locale_id, i18n_uchar *result, int32_t max_result_size, int32_t *buf_size_display_name );

/**
 * @brief Gets the specified locale from a list of all available locales.
 * @details The return value is a pointer to an item of a locale name array. Both this array and the pointers
 * it contains are owned by I18N and should not be deleted or written through by the caller.
 * The locale name is terminated by a null pointer.
 * @since_tizen 2.3
 *
 * @param[in] n the specific locale name index of the available locale list
 *
 * @return A specified locale name of all available locales
 */
const char* i18n_ulocale_get_available ( int32_t n );

/**
 * @brief Gets the size of the all available locale list.
 * @since_tizen 2.3
 *
 * @return the size of the locale list
 */
int32_t i18n_ulocale_count_available ( void );

#ifdef __cplusplus
}
#endif

/**
 * @}
 * @}
 */

#endif  /* __UTILS_I18N_ULOCALE_H__*/
