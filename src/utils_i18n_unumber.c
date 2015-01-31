#include <stdio.h>
#include <unicode/unum.h>
#include <utils_i18n_unumber.h>
#include <utils_i18n_private.h>

int i18n_unumber_create ( i18n_unumber_format_style_e style, const i18n_uchar *pattern, int32_t pattern_len, const char *locale, i18n_uparse_error_s *parse_err, i18n_unumber_format_h *num_format )
{	
    retv_if (num_format == NULL, I18N_ERROR_INVALID_PARAMETER);
    i18n_error_code_e err = I18N_ERROR_NONE;
    *num_format = unum_open(style, pattern, pattern_len, locale, (UParseError*)parse_err, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);

    return result;
}

int i18n_unumber_destroy ( i18n_unumber_format_h fmt )
{
    retv_if(fmt == NULL, I18N_ERROR_INVALID_PARAMETER);

    unum_close(fmt);

    return I18N_ERROR_NONE;
}

int i18n_unumber_get_symbol ( const i18n_unumber_format_h fmt, i18n_unumber_format_symbol_e symbol, i18n_uchar *buffer, int32_t size, int32_t *len_symbol )
{
    retv_if(fmt == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e err = I18N_ERROR_NONE;
    *len_symbol = unum_getSymbol(fmt, symbol, buffer, size, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);    

    return result;
}
