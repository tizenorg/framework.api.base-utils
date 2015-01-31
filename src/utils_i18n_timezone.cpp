#include <stdio.h>
#include <stdlib.h>
#include <utils_i18n_timezone.h>
#include <utils_i18n_private.h>
#include <utils_i18n_ustring.h>

#include <unicode/ustdio.h>
#include <unicode/ucal.h>
#include <unicode/timezone.h>
#include <unicode/strenum.h>
#include <unicode/ustring.h>
#include <unicode/uchar.h>
#include <unicode/locid.h>

int i18n_timezone_create_unknown ( i18n_timezone_h *timezone )
{
    retv_if(timezone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *timezone = (TimeZone::getUnknown()).clone();
    retv_if(timezone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_timezone_create_gmt ( i18n_timezone_h *timezone )
{
    retv_if(timezone == NULL, I18N_ERROR_INVALID_PARAMETER);

    const TimeZone* gmt = TimeZone::getGMT();
    retv_if(gmt == NULL, I18N_ERROR_OUT_OF_MEMORY);

    *timezone = gmt->clone();
    if(gmt != NULL) {
        delete gmt;
    }
    retv_if(timezone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_timezone_create ( i18n_timezone_h *timezone, const char *timezone_id )
{
    retv_if(timezone == NULL, I18N_ERROR_INVALID_PARAMETER);

    const UnicodeString id(timezone_id);
    *timezone = TimeZone::createTimeZone(id);
    retv_if(*timezone == NULL, I18N_ERROR_OUT_OF_MEMORY);

    return I18N_ERROR_NONE;
}

int i18n_timezone_destroy(i18n_timezone_h timezone)
{
    retv_if(timezone == NULL, I18N_ERROR_INVALID_PARAMETER);

    delete((TimeZone*)timezone);

    return I18N_ERROR_NONE;
}

int i18n_timezone_foreach_timezone_id_by_region(i18n_system_timezone_type_e timezone_type, const char *region, const int32_t *raw_offset,
    i18n_timezone_id_cb cb, void* user_data)
{
    retv_if(cb == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode err = U_ZERO_ERROR;

    StringEnumeration *s = TimeZone::createTimeZoneIDEnumeration((USystemTimeZoneType)timezone_type, region, raw_offset, err);

    UErrorCode status=U_ZERO_ERROR;
    int32_t count = s->count(status);
    for (int i = 0; i < count; i++) {
        int32_t resultLength = 0;
        if( cb(s->next(&resultLength, status), user_data) == false ) {
            break;
        }
    }

    delete s;
    int result = _i18n_error_mapping((i18n_uerror_code_private_e)err);
    return result;
}

int i18n_timezone_foreach_timezone_id(i18n_timezone_id_cb cb, void* user_data)
{
    retv_if(cb == NULL, I18N_ERROR_INVALID_PARAMETER);
    StringEnumeration *s = TimeZone::createEnumeration();

    UErrorCode status = U_ZERO_ERROR;
    int32_t count = s->count(status);
    for (int i = 0; i < count; i++) {
        int32_t resultLength = 0;
        if( cb(s->next(&resultLength, status), user_data) == false ) {
            break;
        }
    }

    delete s;
    return I18N_ERROR_NONE;
}

int i18n_timezone_foreach_timezone_id_with_offset(int32_t raw_offset, i18n_timezone_id_cb cb, void* user_data)
{
    retv_if(cb == NULL, I18N_ERROR_INVALID_PARAMETER);
    StringEnumeration *s = TimeZone::createEnumeration(raw_offset);

    UErrorCode status = U_ZERO_ERROR;
    int32_t count = s->count(status);
    for (int i = 0; i < count; i++) {
        int32_t resultLength = 0;
        if( cb(s->next(&resultLength, status), user_data) == false ) {
            break;
        }
    }

    delete s;
    return I18N_ERROR_NONE;
}

int i18n_timezone_foreach_timezone_id_by_country(const char *country, i18n_timezone_id_cb cb, void* user_data)
{
    retv_if(cb == NULL, I18N_ERROR_INVALID_PARAMETER);
    StringEnumeration *s = TimeZone::createEnumeration(country);

    UErrorCode status = U_ZERO_ERROR;
    int32_t count = s->count(status);
    for (int i = 0; i < count; i++) {
        int32_t resultLength = 0;
        if( cb(s->next(&resultLength, status), user_data) == false ) {
            break;
        }
    }

    delete s;
    return I18N_ERROR_NONE;
}

int i18n_timezone_count_equivalent_ids(const char *timezone_id, int32_t *count)
{
    retv_if(timezone_id == NULL || count == NULL, I18N_ERROR_INVALID_PARAMETER);
    const UnicodeString id(timezone_id);
    *count = TimeZone::countEquivalentIDs(id);

    return I18N_ERROR_NONE;
}

int i18n_timezone_get_equivalent_id(const char *timezone_id, int32_t index, char **equivalent_timezone_id)
{
    retv_if(timezone_id == NULL || equivalent_timezone_id == NULL, I18N_ERROR_INVALID_PARAMETER);

    *equivalent_timezone_id = NULL;
    const UnicodeString id(timezone_id);

    UnicodeString equivalentTimezoneId = TimeZone::getEquivalentID(id, index);
    int32_t ulen = u_strlen(equivalentTimezoneId.getTerminatedBuffer());
    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);

    *equivalent_timezone_id = (char*)malloc(ulen + 1);
    retv_if(equivalent_timezone_id == NULL, I18N_ERROR_OUT_OF_MEMORY);

    u_austrcpy(*equivalent_timezone_id, equivalentTimezoneId.getTerminatedBuffer());

    return I18N_ERROR_NONE;
}

int i18n_timezone_create_default ( i18n_timezone_h *timezone )
{
    retv_if(timezone == NULL, I18N_ERROR_INVALID_PARAMETER);
    *timezone = TimeZone::createDefault();

    return I18N_ERROR_NONE;
}

int i18n_timezone_set_default( i18n_timezone_h timezone )
{
    retv_if(timezone == NULL, I18N_ERROR_INVALID_PARAMETER);

    TimeZone::setDefault(*(TimeZone*)timezone);

    return I18N_ERROR_NONE;
}

const char* i18n_timezone_get_tzdata_version()
{
    UErrorCode status = U_ZERO_ERROR;
    return TimeZone::getTZDataVersion(status);
}

int i18n_timezone_get_region(const char *timezone_id, char *region, int32_t *region_len, int32_t region_capacity)
{
    retv_if(timezone_id == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;
    const UnicodeString id(timezone_id);
    *region_len = TimeZone::getRegion(id, region, region_capacity, status);

    int result = _i18n_error_mapping((i18n_uerror_code_private_e)status);
    return result;
}

int i18n_timezone_get_offset_with_date(i18n_timezone_h timezone, i18n_udate date, i18n_ubool local, int32_t *raw_offset, int32_t *dst_offset)
{
    retv_if(timezone == NULL, I18N_ERROR_INVALID_PARAMETER);
    UErrorCode status = U_ZERO_ERROR;
    ((TimeZone*)timezone)->getOffset( date, local, *raw_offset, *dst_offset, status );

    int result = _i18n_error_mapping((i18n_uerror_code_private_e)status);
    return result;
}

int i18n_timezone_set_raw_offset(i18n_timezone_h timezone, int32_t offset_milliseconds)
{
    retv_if(timezone == NULL, I18N_ERROR_INVALID_PARAMETER);
    ((TimeZone*)timezone)->setRawOffset(offset_milliseconds);

    return I18N_ERROR_NONE;
}

int i18n_timezone_get_raw_offset(i18n_timezone_h timezone, int32_t *offset_milliseconds)
{
    retv_if(timezone == NULL, I18N_ERROR_INVALID_PARAMETER);
    *offset_milliseconds = ((TimeZone*)timezone)->getRawOffset();

    return I18N_ERROR_NONE;
}

int i18n_timezone_get_id(i18n_timezone_h timezone, char **timezone_id)
{
    retv_if(timezone == NULL || timezone_id == NULL, I18N_ERROR_INVALID_PARAMETER);

    *timezone_id = NULL;
    UnicodeString TimezoneID;

    ((TimeZone*)timezone)->getID(TimezoneID);
    int32_t ulen = u_strlen(TimezoneID.getTerminatedBuffer());
    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);

    *timezone_id = (char*)malloc(ulen+1);
    retv_if(*timezone_id == NULL, I18N_ERROR_OUT_OF_MEMORY);
    u_austrcpy(*timezone_id, TimezoneID.getTerminatedBuffer());

    return I18N_ERROR_NONE;
}

int i18n_timezone_set_id(i18n_timezone_h timezone, const char *timezone_id)
{
    retv_if(timezone == NULL || timezone_id == NULL, I18N_ERROR_INVALID_PARAMETER);
    const UnicodeString id(timezone_id);
    ((TimeZone*)timezone)->setID(id);

    return I18N_ERROR_NONE;
}

int i18n_timezone_get_display_name(i18n_timezone_h timezone, char **display_name)
{
    retv_if(timezone == NULL || display_name == NULL, I18N_ERROR_INVALID_PARAMETER);

    *display_name = NULL;
    UnicodeString displayName;

    ((TimeZone*)timezone)->getDisplayName(displayName);
    int32_t ulen = u_strlen(displayName.getTerminatedBuffer());
    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);

    *display_name = (char*)malloc(ulen + 1);

    retv_if(*display_name == NULL, I18N_ERROR_OUT_OF_MEMORY);

    u_austrcpy(*display_name, displayName.getTerminatedBuffer());

    return I18N_ERROR_NONE;
}

int i18n_timezone_get_display_name_with_locale(i18n_timezone_h timezone, const char *language, const char *country , char **display_name)
{
    retv_if(timezone == NULL || display_name == NULL, I18N_ERROR_INVALID_PARAMETER);

    Locale locale(language, country, 0, 0);
    *display_name = NULL;
    UnicodeString displayName;

    ((TimeZone*)timezone)->getDisplayName(locale, displayName);
    int32_t ulen = u_strlen(displayName.getTerminatedBuffer());
    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);

    *display_name = (char*)malloc(ulen + 1);

    retv_if(*display_name == NULL, I18N_ERROR_OUT_OF_MEMORY);

    u_austrcpy(*display_name, displayName.getTerminatedBuffer());

    return I18N_ERROR_NONE;
}

int i18n_timezone_get_display_name_with_type(i18n_timezone_h timezone, i18n_ubool daylight, i18n_timezone_display_type_e style,
    char **display_name)
{
    retv_if(timezone == NULL || display_name == NULL, I18N_ERROR_INVALID_PARAMETER);

    *display_name = NULL;
    UnicodeString displayName;

    ((TimeZone*)timezone)->getDisplayName((UBool)daylight, (TimeZone::EDisplayType)style, displayName);
    int32_t ulen = u_strlen(displayName.getTerminatedBuffer());
    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);

    *display_name = (char*)malloc(ulen + 1);

    retv_if(*display_name == NULL, I18N_ERROR_OUT_OF_MEMORY);

    u_austrcpy(*display_name, displayName.getTerminatedBuffer());

    return I18N_ERROR_NONE;
}

int i18n_timezone_get_display_name_with_type_locale(i18n_timezone_h timezone, i18n_ubool daylight, i18n_timezone_display_type_e style,
    const char *language, const char *country, char **display_name)
{
    retv_if(timezone == NULL || display_name == NULL, I18N_ERROR_INVALID_PARAMETER);

    const Locale locale(language, country, 0, 0);
    *display_name = NULL;
    UnicodeString displayName;

    ((TimeZone*)timezone)->getDisplayName((UBool)daylight, (TimeZone::EDisplayType)style, locale, displayName);
    int32_t ulen = u_strlen(displayName.getTerminatedBuffer());
    retv_if(ulen <= 0, I18N_ERROR_INVALID_PARAMETER);

    *display_name = (char*)malloc(ulen + 1);

    retv_if(*display_name == NULL, I18N_ERROR_OUT_OF_MEMORY);

    u_austrcpy(*display_name, displayName.getTerminatedBuffer());

    return I18N_ERROR_NONE;
}

int i18n_timezone_use_daylight_time(i18n_timezone_h timezone, i18n_ubool *daylight_time)
{
    retv_if(timezone == NULL || daylight_time == NULL, I18N_ERROR_INVALID_PARAMETER);

    *daylight_time = ((TimeZone*)timezone)->useDaylightTime();

    return I18N_ERROR_NONE;
}

int i18n_timezone_in_daylight_time(i18n_timezone_h timezone, i18n_udate date, i18n_ubool *daylight_time)
{
    retv_if(timezone == NULL || daylight_time == NULL, I18N_ERROR_INVALID_PARAMETER);

    UErrorCode status;

    *daylight_time = ((TimeZone*)timezone)->inDaylightTime(date, status);

    int result = _i18n_error_mapping((i18n_uerror_code_private_e)status);
    return result;
}

int i18n_timezone_has_same_rule(i18n_timezone_h timezone, i18n_timezone_h other, i18n_ubool *same_rule)
{
    retv_if(timezone == NULL || same_rule == NULL, I18N_ERROR_INVALID_PARAMETER);

    *same_rule = ((TimeZone*)timezone)->hasSameRules(*(TimeZone*)other);

    return I18N_ERROR_NONE;
}

int i18n_timezone_clone(i18n_timezone_h timezone, i18n_timezone_h *clone)
{
    retv_if(timezone == NULL || clone == NULL, I18N_ERROR_INVALID_PARAMETER);

    *clone = ((TimeZone*)timezone)->clone();

    return I18N_ERROR_NONE;
}

int i18n_timezone_get_dst_savings(i18n_timezone_h timezone, int32_t *dst_savings)
{
    retv_if(timezone == NULL || dst_savings == NULL, I18N_ERROR_INVALID_PARAMETER);

    *dst_savings = ((TimeZone*)timezone)->getDSTSavings();

    return I18N_ERROR_NONE;
}