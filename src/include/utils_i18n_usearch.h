#ifndef __UTILS_I18N_USEARCH_H__
#define __UTILS_I18N_USEARCH_H__

#include <utils_i18n_types.h>

/**
 * @file utils_i18n_usearch.h
 * @version 0.1
 * @brief utils_i18n_usearch
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_BASE_UTILS_I18N_MODULE
 * @defgroup CAPI_BASE_UTILS_I18N_USEARCH_MODULE Usearch
 * @brief The Usearch module provides language-sensitive text searching based on the comparison rules defined in a ucollator data struct.
 *
 * @section CAPI_BASE_UTILS_I18N_USEARCH_MODULE_HEADER Required Header
 *  \#include <utils_i18n.h>
 *
 * @section CAPI_BASE_UTILS_I18N_USEARCH_MODULE_OVERVIEW Overview
 * @details The Usearch module provides language-sensitive text searching based on the comparison rules defined in a ucollator data struct.
 *
 * @section CAPI_BASE_UTILS_I18N_USEARCH_MODULE_SAMPLE_CODE_1 Sample Code 1
 * @brief Searches the pattern and gets the matched text.
 * @code
    char *string = "TIZEN";
    char *keyword = "ZE";
    i18n_uchar target[16] = {0,};
    i18n_uchar pattern[16] = {0,};
    i18n_uchar u_matched[16] = {0,};
    char tmp[1] = {0};
    i18n_usearch_h search = NULL;
    int pos = 0;
    int matched_text_len = 0;
    int i = 0;
    i18n_error_code_e error_code;

    i18n_ustring_from_UTF8( target, 16, NULL, string, -1, &error_code );
    i18n_ustring_from_UTF8( pattern, 16, NULL, keyword, -1, &error_code );

    // creates a search
    i18n_usearch_create( pattern, -1, target, -1, "en_US", NULL, &search );

    // gets the first index of the target that matches with the pattern
    i18n_usearch_first( search, &pos );
    dlog_print(DLOG_INFO, LOG_TAG, "the first index = %d", pos );    // The first index = 2

    // gets the matched text
    i18n_usearch_get_matched_text( search, u_matched, 16, &matched_text_len );
    for ( i = 0; i < matched_text_len; i++) {
        i18n_ustring_copy_au_n( tmp, &u_matched[i], 1 );
        dlog_print(DLOG_INFO, LOG_TAG, "u_matched[%d] = %c", i, tmp[0] );    // u_matched[0] = Z, u_matched[1] = E
    }
    i18n_usearch_destroy( search );
 * @endcode
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USEARCH_MODULE
 * @{
 */

/**
* @brief Creates an i18n_usearch_h using the argument locale language rule set.
* @details A collator will be created in the process, which will be owned by
* this search and will be deleted in {@link #i18n_usearch_destroy()}.
* @since_tizen 2.3
* @remarks Must release @a searchiter using i18n_usearch_destroy().
*
* @param[in] pattern The pattern for matching
* @param[in] pattern_len The length of the pattern, otherwise @c -1 for null-termination
* @param[in] text The text string
* @param[in] text_len The length of the text string, otherwise @c -1 for null-termination
* @param[in] locale The name of the locale for the rules to be used
* @param[in] breakiter A BreakIterator that will be used to restrict the points at which matches are detected If a match is found,\n
* but the match's start or end index is not a boundary as determined by the @c i18n_ubreak_iterator_s,
* the match will be rejected and another will be searched If this parameter is @c NULL,\n
* no break detection is attempted.
* @param[out] searchiter The i18n_usearch_h, otherwise @c NULL if there is an error
*
* @retval #I18N_ERROR_NONE Successful
* @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
*/
int i18n_usearch_create ( const i18n_uchar *pattern, int32_t pattern_len, const i18n_uchar *text, int32_t text_len, const char *locale, i18n_ubreak_iterator_s *breakiter, i18n_usearch_h *searchiter );

/**
* @brief Destroys and cleans up the i18n_usearch_h.
* @details If a collator is created in {@link #i18n_usearch_create() }, it will be destroyed here.
* @since_tizen 2.3
*
* @param[in] searchiter The i18n_usearch_h to clean up
*
* @retval #I18N_ERROR_NONE Successful
* @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
*/
int i18n_usearch_destroy ( i18n_usearch_h searchiter );

/**
* @brief Returns the text that matches by the most recent call to {@link #i18n_usearch_first()}, or so on.
* @details If the iterator is not pointing at a valid match (e.g. just after
* construction or after @c I18N_USEARCH_DONE has been returned, it returns
* an empty string. If the result is not large enough to store the matched text,
* the result will be filled with the partial text and an #I18N_ERROR_BUFFER_OVERFLOW
* will be returned in status. The result will be null-terminated whenever
* possible. If the buffer fits the matched text exactly, a null-termination
* is not possible.
* @since_tizen 2.3
*
* @param[in]  strsrch The search iterator data struct
* @param[out] result i18n_uchar The buffer to store the matched string
* @param[in]  result_capacity The length of the result buffer
* @param[out] len_matched_text The exact length of the matched text, not counting the null-termination
*
* @retval #I18N_ERROR_NONE Successful
* @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
* @retval #I18N_ERROR_BUFFER_OVERFLOW A result would not fit in the supplied buffer
*/
int i18n_usearch_get_matched_text ( const i18n_usearch_h strsrch, i18n_uchar *result, int32_t result_capacity, int32_t *len_matched_text );

/**
* @brief Gets the collator used for the language rules.
* @details Deleting the returned i18n_ucollator_h before calling
* {@link #i18n_usearch_destroy()} would cause the string search to fail.
* {@link #i18n_usearch_destroy()} will delete the collator if this search owns it.
* @since_tizen 2.3
*
* @param[in] strsrch The search iterator data struct
* @param[out] collator The collator
*
* @retval #I18N_ERROR_NONE Successful
* @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
*/
int i18n_usearch_get_collator ( const i18n_usearch_h strsrch, i18n_ucollator_h *collator );

/**
* @brief Returns the first index at which the string text matches the search pattern.
* @details The iterator is adjusted so that its current index
* is the match position if one is found.
* If a match is not found, @c I18N_USEARCH_DONE will be returned and
* the iterator will be adjusted to the index @c I18N_USEARCH_DONE.
* @since_tizen 2.3
*
* @param[in] strsrch The search iterator data struct
* @param[out] index_first The character index of the first match,
* otherwise @c I18N_USEARCH_DONE if there are no matches.
*
* @retval #I18N_ERROR_NONE Successful
* @retval #I18N_ERROR_INVALID_PARAMETER Invalid function parameter
*/
int i18n_usearch_first ( i18n_usearch_h strsrch, int32_t *index_first );

#ifdef __cplusplus
}
#endif

/**
 * @}
 * @}
 */

#endif  /* __UTILS_I18N_USEARCH_H__*/