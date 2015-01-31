#include <unicode/usearch.h>
#include <utils_i18n_usearch.h>
#include <utils_i18n_private.h>

int i18n_usearch_destroy ( i18n_usearch_h searchiter )
{
    retv_if ( searchiter == NULL, I18N_ERROR_INVALID_PARAMETER );
    
    usearch_close ( searchiter );

    return I18N_ERROR_NONE;
}

int i18n_usearch_first ( i18n_usearch_h strsrch, int32_t *index_first )
{
    retv_if ( strsrch == NULL || index_first == NULL, I18N_ERROR_INVALID_PARAMETER );
    i18n_error_code_e err = I18N_ERROR_NONE;
    *index_first = usearch_first ( strsrch, (UErrorCode*)&err );

    return I18N_ERROR_NONE;
}

int i18n_usearch_get_collator ( const i18n_usearch_h strsrch, i18n_ucollator_h *collator )
{
    retv_if ( strsrch == NULL || collator == NULL, I18N_ERROR_INVALID_PARAMETER );
    *collator = usearch_getCollator ( strsrch );

    return I18N_ERROR_NONE;
}

int i18n_usearch_get_matched_text ( const i18n_usearch_h strsrch, i18n_uchar *result_w, int32_t result_capacity, int32_t *len_matched_text )
{
    retv_if ( strsrch == NULL, I18N_ERROR_INVALID_PARAMETER );
    
    i18n_error_code_e err = I18N_ERROR_NONE;
    *len_matched_text = usearch_getMatchedText ( strsrch, result_w, result_capacity, (UErrorCode*)&err );
    int result = _i18n_error_mapping ( err );
    
    return result;
}

int i18n_usearch_create ( const i18n_uchar *pattern, int32_t pattern_len, const i18n_uchar *text, int32_t text_len, const char *locale, i18n_ubreak_iterator_s *breakiter, i18n_usearch_h *search_iter )
{
    retv_if ( search_iter == NULL, I18N_ERROR_INVALID_PARAMETER );
    i18n_error_code_e err = I18N_ERROR_NONE;
    *search_iter = usearch_open ( pattern, pattern_len, text, text_len, locale, (UBreakIterator*)breakiter, (UErrorCode*)&err );
    int result = _i18n_error_mapping ( err );
    
    return result;
}
