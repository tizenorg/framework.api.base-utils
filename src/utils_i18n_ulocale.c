#include <unicode/uloc.h>
#include <utils_i18n_ulocale.h>
#include <utils_i18n_private.h>

int i18n_ulocale_get_default ( const char **locale )
{
	retv_if (locale == NULL, I18N_ERROR_INVALID_PARAMETER);

    *locale = uloc_getDefault ();

    return I18N_ERROR_NONE;
}

int i18n_ulocale_set_default ( const char *locale_id )
{
    i18n_error_code_e err =I18N_ERROR_NONE;
    uloc_setDefault(locale_id, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);

    return result;
}

int i18n_ulocale_get_language ( const char *locale_id, char *language, int32_t language_capacity, int32_t *buf_size_language )
{
    retv_if(buf_size_language  == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e err = I18N_ERROR_NONE;
    *buf_size_language = uloc_getLanguage(locale_id, language, language_capacity, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);

    return result;
}

int32_t i18n_ulocale_get_country ( const char *locale_id, char *country, int32_t country_capacity, int *error )
{
    int32_t result = uloc_getCountry(locale_id, country, country_capacity, error);
    *error = _i18n_error_mapping(*error);

    return result;
}

int i18n_ulocale_get_display_name ( const char *locale_id, const char *in_locale_id, i18n_uchar *result_w, int32_t max_result_size, int32_t *buf_size_display_name )
{
    retv_if(buf_size_display_name == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e err = I18N_ERROR_NONE;
    *buf_size_display_name = uloc_getDisplayName(locale_id, in_locale_id, result_w, max_result_size,(UErrorCode*)&err);
    int result = _i18n_error_mapping(err);

    return result;
}

const char* i18n_ulocale_get_available ( int32_t n )
{
    return uloc_getAvailable(n);
}

int32_t i18n_ulocale_count_available ( void )
{
    return uloc_countAvailable();
}
