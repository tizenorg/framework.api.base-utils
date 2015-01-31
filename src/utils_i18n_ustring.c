#include <unicode/ustring.h>
#include <utils_i18n_ustring.h>
#include <utils_i18n_private.h>

int32_t i18n_ustring_get_length ( const i18n_uchar *s )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }

	return u_strlen (s);
}

int32_t i18n_ustring_count_char32 ( const i18n_uchar *s, int32_t length )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_countChar32(s, length);
}

i18n_ubool i18n_ustring_has_more_char32_than ( const i18n_uchar *s, int32_t length, int32_t number )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_strHasMoreChar32Than(s, length, number);
}

i18n_uchar* i18n_ustring_cat ( i18n_uchar *dest, const i18n_uchar *src )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_strcat(dest, src);
}

i18n_uchar * i18n_ustring_cat_n ( i18n_uchar *dest, const i18n_uchar *src, int32_t n )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_strncat(dest, src, n);
}

i18n_uchar* i18n_ustring_string ( const i18n_uchar *s, const i18n_uchar *sub_string )
{
    set_last_result(I18N_ERROR_NONE);
    return (i18n_uchar*)u_strstr(s, sub_string);
}

i18n_uchar* i18n_ustring_find_first ( const i18n_uchar *s, int32_t length, const i18n_uchar *sub_string, int32_t sub_length )
{
    set_last_result(I18N_ERROR_NONE);
    return u_strFindFirst(s, length, sub_string, sub_length);
}

i18n_uchar* i18n_ustring_char ( const i18n_uchar *s, i18n_uchar c )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return (i18n_uchar*)u_strchr(s, c);
}

i18n_uchar* i18n_ustring_char32 ( const i18n_uchar *s, i18n_uchar32 c )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return (i18n_uchar*)u_strchr32(s, c);
}

i18n_uchar* i18n_ustring_r_string ( const i18n_uchar *s, const i18n_uchar *sub_string )
{
    set_last_result(I18N_ERROR_NONE);
    return (i18n_uchar*)u_strrstr(s, sub_string);
}

i18n_uchar* i18n_ustring_find_last( const i18n_uchar *s, int32_t length, const i18n_uchar *sub_string, int32_t sub_length )
{
    set_last_result(I18N_ERROR_NONE);
    return (i18n_uchar*)u_strFindLast(s, length, sub_string, sub_length);
}

i18n_uchar* i18n_ustring_r_char ( const i18n_uchar *s, i18n_uchar c )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return (i18n_uchar*)u_strrchr(s, c);
}

i18n_uchar* i18n_ustring_r_char32 ( const i18n_uchar *s, i18n_uchar32 c )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return (i18n_uchar*)u_strrchr32(s, c);
}

i18n_uchar* i18n_ustring_pbrk ( const i18n_uchar *string, const i18n_uchar *match_set )
{
    set_last_result(I18N_ERROR_NONE);
    if(string == NULL || match_set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return (i18n_uchar*)u_strpbrk(string, match_set);
}

int32_t i18n_ustring_cspn ( const i18n_uchar *string, const i18n_uchar *match_set )
{
    set_last_result(I18N_ERROR_NONE);
    if(string == NULL || match_set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_strcspn(string, match_set);
}

int32_t i18n_ustring_spn ( const i18n_uchar *string, const i18n_uchar *match_set )
{
    set_last_result(I18N_ERROR_NONE);
    if(string == NULL || match_set == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_strspn(string, match_set);
}

i18n_uchar* i18n_ustring_tokenizer_r ( i18n_uchar *src, const i18n_uchar *delim, i18n_uchar **save_state )
{
    set_last_result(I18N_ERROR_NONE);
    return u_strtok_r(src, delim, save_state);
}

int32_t i18n_ustring_compare ( const i18n_uchar *s1, const i18n_uchar *s2 )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_strcmp (s1, s2);
}

int32_t i18n_ustring_compare_code_point_order( const i18n_uchar *s1, const i18n_uchar *s2 )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_strcmpCodePointOrder(s1, s2);
}

int32_t i18n_ustring_compare_binary_order( const i18n_uchar *s1, int32_t length1, const i18n_uchar *s2, int32_t length2, i18n_ubool code_point_order )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_strCompare(s1, length1,  s2, length2, code_point_order);
}

int32_t i18n_ustring_case_compare_with_length( const i18n_uchar *s1, int32_t length1, const i18n_uchar *s2, int32_t length2, uint32_t options, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    UErrorCode err = U_ZERO_ERROR;
    int32_t result = u_strCaseCompare(s1, length1, s2, length2, options, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

int32_t i18n_ustring_compare_n( const i18n_uchar *s1, const i18n_uchar *s2, int32_t n )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_strncmp(s1, s2, n);
}

int32_t i18n_ustring_compare_n_code_point_order( const i18n_uchar *s1, const i18n_uchar *s2, int32_t n )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_strncmpCodePointOrder(s1, s2, n);
}

int32_t i18n_ustring_case_compare( const i18n_uchar *s1, const i18n_uchar *s2, uint32_t options )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_strcasecmp(s1, s2, options);
}

int32_t i18n_ustring_case_compare_n( const i18n_uchar *s1, const i18n_uchar *s2, int32_t n, uint32_t options )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }    return u_strncasecmp(s1, s2, n, options);
}

int32_t i18n_ustring_mem_case_compare( const i18n_uchar *s1, const i18n_uchar *s2, int32_t length, uint32_t options )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_memcasecmp(s1, s2, length, options);
}

i18n_uchar* i18n_ustring_copy ( i18n_uchar *dest, const i18n_uchar *src )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_strcpy(dest, src);
}

i18n_uchar* i18n_ustring_copy_n ( i18n_uchar *dest, const i18n_uchar *src, int32_t n )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_strncpy(dest, src, n);
}

i18n_uchar* i18n_ustring_copy_ua ( i18n_uchar *dest, const char *src )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_uastrcpy(dest, src);
}

i18n_uchar* i18n_ustring_copy_ua_n ( i18n_uchar *dest, const char *src, int32_t n )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_uastrncpy(dest, src, n);
}

char* i18n_ustring_copy_au ( char *dest, const i18n_uchar *src )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_austrcpy(dest, src);
}

char* i18n_ustring_copy_au_n ( char *dest, const i18n_uchar *src, int32_t n )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_austrncpy(dest, src, n);
}

i18n_uchar* i18n_ustring_mem_copy ( i18n_uchar *dest, const i18n_uchar *src, int32_t count )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_memcpy(dest, src, count);
}

i18n_uchar* i18n_ustring_mem_move ( i18n_uchar *dest, const i18n_uchar *src, int32_t count )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_memmove(dest, src, count);
}

i18n_uchar* i18n_ustring_mem_set ( i18n_uchar *dest, const i18n_uchar c, int32_t count )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return u_memset(dest, c, count);
}

int32_t i18n_ustring_mem_compare ( const i18n_uchar *buf1, const i18n_uchar *buf2, int32_t count )
{
    set_last_result(I18N_ERROR_NONE);
    if(buf1 == NULL || buf2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_memcmp(buf1, buf2, count);
}

int32_t i18n_ustring_mem_compare_code_point_order ( const i18n_uchar *s1, const i18n_uchar *s2, int32_t count )
{
    set_last_result(I18N_ERROR_NONE);
    if(s1 == NULL || s2 == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_memcmpCodePointOrder(s1, s2, count);
}

i18n_uchar* i18n_ustring_mem_char ( const i18n_uchar *s, i18n_uchar c, int32_t count )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return (i18n_uchar*)u_memchr(s, c, count);
}

i18n_uchar* i18n_ustring_mem_char32 ( const i18n_uchar *s, i18n_uchar32 c, int32_t count )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return (i18n_uchar*)u_memchr32(s, c, count);
}

i18n_uchar* i18n_ustring_mem_r_char ( const i18n_uchar *s, i18n_uchar c, int32_t count )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return (i18n_uchar*)u_memrchr(s, c, count);
}

i18n_uchar* i18n_ustring_mem_r_char32 ( const i18n_uchar *s, i18n_uchar32 c, int32_t count )
{
    set_last_result(I18N_ERROR_NONE);
    if(s == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    return (i18n_uchar*)u_memrchr32(s, c, count);
}

int32_t i18n_ustring_unescape ( const char *src, i18n_uchar *dest, int32_t dest_capacity )
{
    set_last_result(I18N_ERROR_NONE);
    if(dest == NULL || src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_unescape(src, dest, dest_capacity);
}

i18n_uchar32 i18n_ustring_unescape_at ( i18n_ustring_unescape_char_at_cb char_at, int32_t *offset, int32_t length, void *context )
{
    set_last_result(I18N_ERROR_NONE);
    if(char_at == NULL || offset == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    return u_unescapeAt(char_at, offset, length, context);
}

int32_t i18n_ustring_to_upper ( i18n_uchar *dest, int32_t dest_capacity, const i18n_uchar *src, int32_t src_len, const char *locale, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    UErrorCode err = U_ZERO_ERROR;
    int32_t result = u_strToUpper (dest, dest_capacity, src, src_len, locale, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

int32_t i18n_ustring_to_lower ( i18n_uchar *dest, int32_t dest_capacity, const i18n_uchar *src, int32_t src_len, const char *locale, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    UErrorCode err = U_ZERO_ERROR;
    int32_t result = u_strToLower (dest, dest_capacity, src, src_len, locale, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

int32_t i18n_ustring_to_title ( i18n_uchar *dest, int32_t dest_capacity, const i18n_uchar *src, int32_t src_len, i18n_ubreak_iterator_s *title_iter,
        const char *locale, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    UErrorCode err = U_ZERO_ERROR;
    int32_t result = u_strToTitle (dest, dest_capacity, src, src_len, (UBreakIterator*)title_iter, locale, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

int32_t i18n_ustring_fold_case ( i18n_uchar *dest, int32_t dest_capacity, const i18n_uchar *src, int32_t src_len, uint32_t options, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return 0;
    }
    UErrorCode err = U_ZERO_ERROR;
    int32_t result =u_strFoldCase (dest, dest_capacity, src, src_len, options, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

wchar_t* i18n_ustring_to_WCS ( wchar_t *dest, int32_t dest_capacity, int32_t *dest_len, const i18n_uchar *src, int32_t src_len, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    wchar_t* result = u_strToWCS (dest, dest_capacity, dest_len, src, src_len, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

i18n_uchar* i18n_ustring_from_WCS ( i18n_uchar *dest, int32_t dest_capacity, int32_t *dest_len, const wchar_t *src, int32_t src_len, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    i18n_uchar* result = u_strFromWCS (dest, dest_capacity, dest_len, src, src_len, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

char* i18n_ustring_to_UTF8 ( char *dest, int32_t dest_capacity, int32_t *dest_len, const i18n_uchar *src, int32_t src_len, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    char* result = u_strToUTF8 (dest, dest_capacity, dest_len, src, src_len, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

i18n_uchar* i18n_ustring_from_UTF8 ( i18n_uchar *dest, int32_t dest_capacity, int32_t *dest_len, const char *src, int32_t src_len, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    i18n_uchar* result = u_strFromUTF8 (dest, dest_capacity, dest_len, src, src_len, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

char* i18n_ustring_to_UTF8_with_sub ( char *dest, int32_t dest_capacity, int32_t *dest_len, const i18n_uchar *src, int32_t src_len, i18n_uchar32 sub_char, int32_t *num_substitutions, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    char* result = u_strToUTF8WithSub (dest, dest_capacity, dest_len, src, src_len, sub_char, num_substitutions, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

i18n_uchar* i18n_ustring_from_UTF8_with_sub ( i18n_uchar *dest, int32_t dest_capacity, int32_t *dest_len, const char *src, int32_t src_len, i18n_uchar32 sub_char, 
    int32_t *num_substitutions, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    i18n_uchar* result = u_strFromUTF8WithSub (dest, dest_capacity, dest_len, src, src_len, sub_char, num_substitutions, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

i18n_uchar* i18n_ustring_from_UTF8_lenient ( i18n_uchar *dest, int32_t dest_capacity, int32_t *dest_len, const char *src, int32_t src_len, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    i18n_uchar* result = u_strFromUTF8Lenient (dest, dest_capacity, dest_len, src, src_len, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

i18n_uchar32* i18n_ustring_to_UTF32 ( i18n_uchar32 *dest, int32_t dest_capacity, int32_t *dest_len, const i18n_uchar *src, int32_t src_len, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    i18n_uchar32* result = u_strToUTF32 (dest, dest_capacity, dest_len, src, src_len, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

i18n_uchar* i18n_ustring_from_UTF32 ( i18n_uchar *dest, int32_t dest_capacity, int32_t *dest_len, const i18n_uchar32 *src, int32_t src_len, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    i18n_uchar* result = u_strFromUTF32 (dest, dest_capacity, dest_len, src, src_len, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

i18n_uchar32* i18n_ustring_to_UTF32_with_sub ( i18n_uchar32 *dest, int32_t dest_capacity, int32_t *dest_len, const i18n_uchar *src, int32_t src_len,
        i18n_uchar32 sub_char, int32_t *num_substitutions, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    i18n_uchar32* result = u_strToUTF32WithSub (dest, dest_capacity, dest_len, src, src_len, sub_char, num_substitutions, &err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

i18n_uchar* i18n_ustring_from_UTF32_with_sub ( i18n_uchar *dest, int32_t dest_capacity, int32_t *dest_len, const i18n_uchar32 *src, int32_t src_len, i18n_uchar32 sub_char, int32_t *num_substitutions, i18n_error_code_e *pErrorCode )
{
    set_last_result(I18N_ERROR_NONE);
    if(src == NULL) {
        set_last_result(I18N_ERROR_INVALID_PARAMETER);
        return NULL;
    }
    UErrorCode err = U_ZERO_ERROR;
    i18n_uchar* result = u_strFromUTF32WithSub (dest, dest_capacity, dest_len, src, src_len, sub_char, num_substitutions, (UErrorCode*)&err);
    *pErrorCode = _i18n_error_mapping(err);

    return result;
}

