#include <unicode/udat.h>
#include <utils_i18n_udate.h>
#include <utils_i18n_private.h>

int i18n_udate_create ( i18n_udate_format_style_e time_style, i18n_udate_format_style_e date_style, const char *locale, const i18n_uchar *tz_id, int32_t tz_id_len, const i18n_uchar *pattern, int32_t pattern_len, i18n_udate_format_h *format )
{
    retv_if( format == NULL, I18N_ERROR_INVALID_PARAMETER );
    
	i18n_error_code_e err = I18N_ERROR_NONE;
	*format = udat_open(time_style, date_style, locale, tz_id, tz_id_len, pattern, pattern_len, (UErrorCode*)&err);
	return err;
}

int i18n_udate_destroy ( i18n_udate_format_h format )
{
    retv_if( format == NULL, I18N_ERROR_INVALID_PARAMETER );
    
	udat_close(format);
	return I18N_ERROR_NONE;
}

int i18n_udate_format_date ( const i18n_udate_format_h format, i18n_udate date_to_format, i18n_uchar *result, int32_t result_len, i18n_ufield_position_h pos, int32_t *buf_size_needed )
{
    retv_if( format == NULL || buf_size_needed == NULL, I18N_ERROR_INVALID_PARAMETER );
    
	i18n_error_code_e err = I18N_ERROR_NONE;
	*buf_size_needed = udat_format(format, date_to_format, result, result_len, (UFieldPosition*)pos, (UErrorCode*)&err);
	return _i18n_error_mapping(err); 
}
