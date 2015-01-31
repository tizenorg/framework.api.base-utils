#include <unicode/ucal.h>
#include <utils_i18n_ucalendar.h>
#include <utils_i18n_private.h>

int i18n_ucalendar_create ( const i18n_uchar *zone_id, int32_t len, const char *locale, i18n_ucalendar_type_e type, i18n_ucalendar_h *calendar )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	*calendar = ucal_open(zone_id, len, locale, type, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);
    
	return result;
}

int i18n_ucalendar_destroy ( i18n_ucalendar_h calendar )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

	ucal_close(calendar);
    
	return I18N_ERROR_NONE;
}

int i18n_ucalendar_clone ( const i18n_ucalendar_h cal, i18n_ucalendar_h *identical_to_cal )
{
    retv_if(cal == NULL || identical_to_cal == NULL, I18N_ERROR_INVALID_PARAMETER);

    i18n_error_code_e err = I18N_ERROR_NONE;
    *identical_to_cal =  ucal_clone(cal, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);

    return result;
}

int i18n_ucalendar_add ( i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field, int32_t amount )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	ucal_add(calendar, field, amount, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);
    
	return result;
}

int i18n_ucalendar_is_equivalent_to ( const i18n_ucalendar_h calendar1, const i18n_ucalendar_h calendar2, i18n_ubool *equiv )
{
    retv_if(calendar1 == NULL || calendar2 == NULL, I18N_ERROR_INVALID_PARAMETER);

	*equiv = ucal_equivalentTo(calendar1, calendar2);

	return I18N_ERROR_NONE;
}

int i18n_ucalendar_get_milliseconds ( const i18n_ucalendar_h calendar, i18n_udate *date )
{
    retv_if(calendar == NULL || date == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	*date = ucal_getMillis(calendar, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);
    
	return result;
}

int i18n_ucalendar_get ( const i18n_ucalendar_h calendar, i18n_ucalendar_date_fields_e field, int32_t *val )
{
    retv_if(calendar == NULL || val == NULL, I18N_ERROR_INVALID_PARAMETER);
    
	i18n_error_code_e err = I18N_ERROR_NONE;
	*val = ucal_get(calendar, field, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err); 
    
	return result;
}

int i18n_ucalendar_get_attribute ( i18n_ucalendar_h calendar, i18n_ucalendar_attribute_e attr, int32_t *val)
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

    *val = ucal_getAttribute(calendar, attr);

    return I18N_ERROR_NONE;
}

int i18n_ucalendar_get_timezone_displayname ( const i18n_ucalendar_h calendar, i18n_ucalendar_displayname_type_e type, const char *locale,
    i18n_uchar *result, int32_t result_len, int32_t *buf_size_needed )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	*buf_size_needed = ucal_getTimeZoneDisplayName(calendar, type, locale, result, result_len, (UErrorCode*)&err);
    
	return _i18n_error_mapping(err); 
}

int i18n_ucalendar_is_in_daylight_time ( const i18n_ucalendar_h calendar, i18n_ubool *is_in )
{
    retv_if(calendar == NULL || is_in == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	*is_in = ucal_inDaylightTime(calendar, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);
    
	return result;
}

int i18n_ucalendar_set ( i18n_ucalendar_h cal, i18n_ucalendar_date_fields_e field, int32_t val )
{
    retv_if(cal == NULL, I18N_ERROR_INVALID_PARAMETER);

    ucal_set(cal, field, val);

    return I18N_ERROR_NONE;
}

int i18n_ucalendar_set_attribute ( i18n_ucalendar_h calendar, i18n_ucalendar_attribute_e attr, int32_t val )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

	ucal_setAttribute(calendar, attr, val);

	return I18N_ERROR_NONE;
}

int i18n_ucalendar_set_date_time ( i18n_ucalendar_h calendar, int32_t year, int32_t month, int32_t date, int32_t hour, int32_t min, int32_t sec )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	ucal_setDateTime(calendar, year, month, date, hour, min, sec, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);
    
	return result;
}

int i18n_ucalendar_set_milliseconds ( i18n_ucalendar_h calendar, i18n_udate milliseconds )
{
    retv_if(calendar == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	ucal_setMillis(calendar, milliseconds, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);
    
	return result;
}

int i18n_ucalendar_set_default_timezone ( const i18n_uchar *zone_id )
{
    i18n_error_code_e err = I18N_ERROR_NONE;
    ucal_setDefaultTimeZone(zone_id, (UErrorCode*)&err);
    int result = _i18n_error_mapping(err);

    return result;
}

int i18n_ucalendar_get_now ( i18n_udate *date )
{
    retv_if(date == NULL, I18N_ERROR_INVALID_PARAMETER);
	*date = ucal_getNow(); 
	return I18N_ERROR_NONE;
}
