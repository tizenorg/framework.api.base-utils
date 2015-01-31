#include <unicode/udatpg.h>
#include <utils_i18n_udatepg.h>
#include <utils_i18n_private.h>

int i18n_udatepg_create ( const char *locale, i18n_udatepg_h *dtpg )
{
    retv_if(dtpg == NULL, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	*dtpg = udatpg_open(locale, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);

	return result;
}

int i18n_udatepg_destroy ( i18n_udatepg_h dtpg )
{
    retv_if(dtpg == NULL, I18N_ERROR_INVALID_PARAMETER);

	udatpg_close(dtpg);

	return I18N_ERROR_NONE;
}

int i18n_udatepg_get_best_pattern ( i18n_udatepg_h dtpg, const i18n_uchar *skeleton, int32_t len, i18n_uchar *best_pattern, int32_t capacity, int32_t *best_pattern_len )
{
    retv_if(dtpg == NULL, I18N_ERROR_INVALID_PARAMETER);
    retv_if(best_pattern == NULL && capacity > 0, I18N_ERROR_INVALID_PARAMETER);

	i18n_error_code_e err = I18N_ERROR_NONE;
	*best_pattern_len = udatpg_getBestPattern(dtpg, skeleton, len, best_pattern, capacity, (UErrorCode*)&err);
	int result = _i18n_error_mapping(err);

	return result;
}

