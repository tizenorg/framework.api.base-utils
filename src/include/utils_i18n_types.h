#ifndef __UTILS_I18N_TYPES_H__
#define __UTILS_I18N_TYPES_H__

#include <inttypes.h>
#include <tizen.h>
#include <wchar.h>

/**
 * @file utils_i18n_types.h
 * @version 0.1
 * @brief utils_i18n_types
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCHAR_MODULE
 * @{
 */

#define I18N_U_MASK(x)                        ((uint32_t)1<<(x))

#define I18N_U_GC_CN_MASK                     I18N_U_MASK(I18N_UCHAR_U_GENERAL_OTHER_TYPES)
#define I18N_U_GC_LU_MASK                     I18N_U_MASK(I18N_UCHAR_U_UPPERCASE_LETTER)
#define I18N_U_GC_LL_MASK                     I18N_U_MASK(I18N_UCHAR_U_LOWERCASE_LETTER)
#define I18N_U_GC_LT_MASK                     I18N_U_MASK(I18N_UCHAR_U_TITLECASE_LETTER)
#define I18N_U_GC_LM_MASK                     I18N_U_MASK(I18N_UCHAR_U_MODIFIER_LETTER)
#define I18N_U_GC_LO_MASK                     I18N_U_MASK(I18N_UCHAR_U_OTHER_LETTER)
#define I18N_U_GC_MN_MASK                     I18N_U_MASK(I18N_UCHAR_U_NON_SPACING_MARK)
#define I18N_U_GC_ME_MASK                     I18N_U_MASK(I18N_UCHAR_U_ENCLOSING_MARK)
#define I18N_U_GC_MC_MASK                     I18N_U_MASK(I18N_UCHAR_U_COMBINING_SPACING_MARK)
#define I18N_U_GC_ND_MASK                     I18N_U_MASK(I18N_UCHAR_U_DECIMAL_DIGIT_NUMBER)
#define I18N_U_GC_NL_MASK                     I18N_U_MASK(I18N_UCHAR_U_LETTER_NUMBER)
#define I18N_U_GC_NO_MASK                     I18N_U_MASK(I18N_UCHAR_U_OTHER_NUMBER)
#define I18N_U_GC_ZS_MASK                     I18N_U_MASK(I18N_UCHAR_U_SPACE_SEPARATOR)
#define I18N_U_GC_ZL_MASK                     I18N_U_MASK(I18N_UCHAR_U_LINE_SEPARATOR)
#define I18N_U_GC_ZP_MASK                     I18N_U_MASK(I18N_UCHAR_U_PARAGRAPH_SEPARATOR)
#define I18N_U_GC_CC_MASK                     I18N_U_MASK(I18N_UCHAR_U_CONTROL_CHAR)
#define I18N_U_GC_CF_MASK                     I18N_U_MASK(I18N_UCHAR_U_FORMAT_CHAR)
#define I18N_U_GC_CO_MASK                     I18N_U_MASK(I18N_UCHAR_U_PRIVATE_USE_CHAR)
#define I18N_U_GC_CS_MASK                     I18N_U_MASK(I18N_UCHAR_U_SURROGATE)
#define I18N_U_GC_PD_MASK                     I18N_U_MASK(I18N_UCHAR_U_DASH_PUNCTUATION)
#define I18N_U_GC_PS_MASK                     I18N_U_MASK(I18N_UCHAR_U_START_PUNCTUATION)
#define I18N_U_GC_PE_MASK                     I18N_U_MASK(I18N_UCHAR_U_END_PUNCTUATION)
#define I18N_U_GC_PC_MASK                     I18N_U_MASK(I18N_UCHAR_U_CONNECTOR_PUNCTUATION)
#define I18N_U_GC_PO_MASK                     I18N_U_MASK(I18N_UCHAR_U_OTHER_PUNCTUATION)
#define I18N_U_GC_SM_MASK                     I18N_U_MASK(I18N_UCHAR_U_MATH_SYMBOL)
#define I18N_U_GC_SC_MASK                     I18N_U_MASK(I18N_UCHAR_U_CURRENCY_SYMBOL)
#define I18N_U_GC_SK_MASK                     I18N_U_MASK(I18N_UCHAR_U_MODIFIER_SYMBOL)
#define I18N_U_GC_SO_MASK                     I18N_U_MASK(I18N_UCHAR_U_OTHER_SYMBOL)
#define I18N_U_GC_PI_MASK                     I18N_U_MASK(I18N_UCHAR_U_INITIAL_PUNCTUATION)
#define I18N_U_GC_PF_MASK                     I18N_U_MASK(I18N_UCHAR_U_FINAL_PUNCTUATION)
#define I18N_U_GC_L_MASK                      (I18N_U_GC_LU_MASK|I18N_U_GC_LL_MASK|I18N_U_GC_LT_MASK|I18N_U_GC_LM_MASK|I18N_U_GC_LO_MASK)
#define I18N_U_GC_LC_MASK                     (I18N_U_GC_LU_MASK|I18N_U_GC_LL_MASK|I18N_U_GC_LT_MASK)
#define I18N_U_GC_M_MASK                      (I18N_U_GC_MN_MASK|I18N_U_GC_ME_MASK|I18N_U_GC_MC_MASK)
#define I18N_U_GC_N_MASK                      (I18N_U_GC_ND_MASK|I18N_U_GC_NL_MASK|I18N_U_GC_NO_MASK)
#define I18N_U_GC_Z_MASK                      (I18N_U_GC_ZS_MASK|I18N_U_GC_ZL_MASK|I18N_U_GC_ZP_MASK)
#define I18N_U_GC_C_MASK                      (I18N_U_GC_CN_MASK|I18N_U_GC_CC_MASK|I18N_U_GC_CF_MASK|I18N_U_GC_CO_MASK|I18N_U_GC_CS_MASK)
#define I18N_U_GC_P_MASK                      (I18N_U_GC_PD_MASK|I18N_U_GC_PS_MASK|I18N_U_GC_PE_MASK|I18N_U_GC_PC_MASK|I18N_U_GC_PO_MASK|I18N_U_GC_PI_MASK|I18N_U_GC_PF_MASK)
#define I18N_U_GC_S_MASK                      (I18N_U_GC_SM_MASK|I18N_U_GC_SC_MASK|I18N_U_GC_SK_MASK|I18N_U_GC_SO_MASK)

#define I18N_U_NO_NUMERIC_VALUE               ((double)-123456789.)

#define I18N_U_GET_GC_MASK(c)                 I18N_U_MASK(u_charType(c))

#define I18N_U_FOLD_CASE_DEFAULT              0
#define I18N_U_FOLD_CASE_EXCLUDE_SPECIAL_I    1

#define I18N_USEARCH_DONE                     -1


#if !defined(U_WCHAR_IS_UTF16) && !defined(U_WCHAR_IS_UTF32)
#   ifdef __STDC_ISO_10646__
#       if (U_SIZEOF_WCHAR_T==2)
#           define U_WCHAR_IS_UTF16
#       elif (U_SIZEOF_WCHAR_T==4)
#           define  U_WCHAR_IS_UTF32
#       endif
#   elif defined __UCS2__
#       if (U_PF_OS390 <= U_PLATFORM && U_PLATFORM <= U_PF_OS400) && (U_SIZEOF_WCHAR_T==2)
#           define U_WCHAR_IS_UTF16
#       endif
#   elif defined(__UCS4__) || (U_PLATFORM == U_PF_OS400 && defined(__UTF32__))
#       if (U_SIZEOF_WCHAR_T==4)
#           define U_WCHAR_IS_UTF32
#       endif
#   elif U_PLATFORM_IS_DARWIN_BASED || (U_SIZEOF_WCHAR_T==4 && U_PLATFORM_IS_LINUX_BASED)
#       define U_WCHAR_IS_UTF32
#   elif U_PLATFORM_HAS_WIN32_API
#       define U_WCHAR_IS_UTF16
#   endif
#endif
#define U_SIZEOF_UCHAR 2
#if defined(UCHAR_TYPE)
    typedef UCHAR_TYPE i18n_uchar;
/* Not #elif U_HAVE_CHAR16_T -- because that is type-incompatible with pre-C++11 callers
    typedef char16_t i18n_uchar;  */
#elif U_SIZEOF_WCHAR_T==2
    typedef wchar_t i18n_uchar;
#elif defined(__CHAR16_TYPE__)
    typedef __CHAR16_TYPE__ i18n_uchar;
#else
    typedef uint16_t i18n_uchar;
#endif

typedef int32_t i18n_uchar32;

/**
 * @brief Enumeration of constants for Unicode properties. 
 *     The properties APIs are intended to reflect Unicode properties as defined in the Unicode Character Database (UCD) and Unicode Technical Reports (UTR). For details about the properties see http://www.unicode.org/ucd/ . For names of Unicode properties see the UCD file PropertyAliases.txt.
 */
typedef enum {
    I18N_UCHAR_ALPHABETIC                      = 0,                                    /**<  */

    I18N_UCHAR_BINARY_START                    = I18N_UCHAR_ALPHABETIC,                /**<  */
    I18N_UCHAR_ASCII_HEX_DIGIT,                                                        /**<  */
    I18N_UCHAR_BIDI_CONTROL,                                                           /**<  */
    I18N_UCHAR_BIDI_MIRRORED,                                                          /**<  */
    I18N_UCHAR_DASH,                                                                   /**<  */
    I18N_UCHAR_DEFAULT_IGNORABLE_CODE_POINT,                                           /**<  */
    I18N_UCHAR_DEPRECATED,                                                             /**<  */
    I18N_UCHAR_DIACRITIC,                                                              /**<  */
    I18N_UCHAR_EXTENDER,                                                               /**<  */
    I18N_UCHAR_FULL_COMPOSITION_EXCLUSION,                                             /**<  */
    I18N_UCHAR_GRAPHEME_BASE,                                                          /**<  */
    I18N_UCHAR_GRAPHEME_EXTEND,                                                        /**<  */
    I18N_UCHAR_GRAPHEME_LINK,                                                          /**<  */
    I18N_UCHAR_HEX_DIGIT,                                                              /**<  */
    I18N_UCHAR_HYPHEN,                                                                 /**<  */
    I18N_UCHAR_ID_CONTINUE,                                                            /**<  */
    I18N_UCHAR_ID_START,                                                               /**<  */    
    I18N_UCHAR_IDEOGRAPHIC,                                                            /**<  */
    I18N_UCHAR_IDS_BINARY_OPERATOR,                                                    /**<  */
    I18N_UCHAR_IDS_TRINARY_OPERATOR,                                                   /**<  */
    I18N_UCHAR_JOIN_CONTROL,                                                           /**<  */
    I18N_UCHAR_LOGICAL_ORDER_EXCEPTION,                                                /**<  */
    I18N_UCHAR_LOWERCASE,                                                              /**<  */
    I18N_UCHAR_MATH,                                                                   /**<  */
    I18N_UCHAR_NONCHARACTER_CODE_POINT,                                                /**<  */
    I18N_UCHAR_QUOTATION_MARK,                                                         /**<  */
    I18N_UCHAR_RADICAL,                                                                /**<  */
    I18N_UCHAR_SOFT_DOTTED,                                                            /**<  */
    I18N_UCHAR_TERMINAL_PUNCTUATION,                                                   /**<  */
    I18N_UCHAR_UNIFIED_IDEOGRAPH,                                                      /**<  */
    I18N_UCHAR_UPPERCASE,                                                              /**<  */
    I18N_UCHAR_WHITE_SPACE,                                                            /**<  */
    I18N_UCHAR_XID_CONTINUE,                                                           /**<  */
    I18N_UCHAR_XID_START,                                                              /**<  */
    I18N_UCHAR_CASE_SENSITIVE,                                                         /**<  */
    I18N_UCHAR_S_TERM,                                                                 /**<  */
    I18N_UCHAR_VARIATION_SELECTOR,                                                     /**<  */
    I18N_UCHAR_NFD_INERT,                                                              /**<  */
    I18N_UCHAR_NFKD_INERT,                                                             /**<  */
    I18N_UCHAR_NFC_INERT,                                                              /**<  */
    I18N_UCHAR_NFKC_INERT,                                                             /**<  */
    I18N_UCHAR_SEGMENT_STARTER,                                                        /**<  */
    I18N_UCHAR_PATTERN_SYNTAX,                                                         /**<  */
    I18N_UCHAR_PATTERN_WHITE_SPACE,                                                    /**<  */
    I18N_UCHAR_POSIX_ALNUM,                                                            /**<  */
    I18N_UCHAR_POSIX_BLANK,                                                            /**<  */
    I18N_UCHAR_POSIX_GRAPH,                                                            /**<  */
    I18N_UCHAR_POSIX_PRINT,                                                            /**<  */
    I18N_UCHAR_POSIX_XDIGIT,                                                           /**<  */
    I18N_UCHAR_CASED,                                                                  /**<  */
    I18N_UCHAR_CASE_IGNORABLE,                                                         /**<  */
    I18N_UCHAR_CHANGES_WHEN_LOWERCASED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_UPPERCASED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_TITLECASED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_CASEFOLDED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_CASEMAPPED,                                                /**<  */
    I18N_UCHAR_CHANGES_WHEN_NFKC_CASEFOLDED,                                           /**<  */
    I18N_UCHAR_BINARY_LIMIT,                                                           /**<  */

    I18N_UCHAR_BIDI_CLASS                      = 0x1000,                               /**<  */

    I18N_UCHAR_INT_START                       = I18N_UCHAR_BIDI_CLASS,                /**<  */
    I18N_UCHAR_BLOCK,                                                                  /**<  */
    I18N_UCHAR_CANONICAL_COMBINING_CLASS,                                              /**<  */
    I18N_UCHAR_DECOMPOSITION_TYPE,                                                     /**<  */
    I18N_UCHAR_EAST_ASIAN_WIDTH,                                                       /**<  */
    I18N_UCHAR_GENERAL_CATEGORY,                                                       /**<  */
    I18N_UCHAR_JOINING_GROUP,                                                          /**<  */
    I18N_UCHAR_JOINING_TYPE,                                                           /**<  */
    I18N_UCHAR_LINE_BREAK,                                                             /**<  */
    I18N_UCHAR_NUMERIC_TYPE,                                                           /**<  */
    I18N_UCHAR_SCRIPT,                                                                 /**<  */
    I18N_UCHAR_HANGUL_SYLLABLE_TYPE,                                                   /**<  */
    I18N_UCHAR_NFD_QUICK_CHECK,                                                        /**<  */
    I18N_UCHAR_NFKD_QUICK_CHECK,                                                       /**<  */
    I18N_UCHAR_NFC_QUICK_CHECK,                                                        /**<  */
    I18N_UCHAR_NFKC_QUICK_CHECK,                                                       /**<  */
    I18N_UCHAR_LEAD_CANONICAL_COMBINING_CLASS,                                         /**<  */
    I18N_UCHAR_TRAIL_CANONICAL_COMBINING_CLASS,                                        /**<  */
    I18N_UCHAR_GRAPHEME_CLUSTER_BREAK,                                                 /**<  */
    I18N_UCHAR_SENTENCE_BREAK,                                                         /**<  */
    I18N_UCHAR_WORD_BREAK,                                                             /**<  */
    I18N_UCHAR_BIDI_PAIRED_BRACKET_TYPE,                                               /**<  */
    I18N_UCHAR_INT_LIMIT,                                                              /**<  */

    I18N_UCHAR_GENERAL_CATEGORY_MASK           = 0x2000,                               /**<  */

    I18N_UCHAR_MASK_START                      = I18N_UCHAR_GENERAL_CATEGORY_MASK,     /**<  */
    I18N_UCHAR_MASK_LIMIT,                                                             /**<  */

    I18N_UCHAR_NUMERIC_VALUE                   = 0x3000,                               /**<  */
    I18N_UCHAR_DOUBLE_START                    = I18N_UCHAR_NUMERIC_VALUE,             /**<  */
    I18N_UCHAR_DOUBLE_LIMIT,                                                           /**<  */

    I18N_UCHAR_AGE                             = 0x4000,                               /**<  */ 
    I18N_UCHAR_STRING_START                    = I18N_UCHAR_AGE,                       /**<  */
    I18N_UCHAR_BIDI_MIRRORING_GLYPH,                                                   /**<  */
    I18N_UCHAR_CASE_FOLDING,                                                           /**<  */

    I18N_UCHAR_LOWERCASE_MAPPING               = 0x4004,                               /**<  */
    I18N_UCHAR_NAME,                                                                   /**<  */
    I18N_UCHAR_SIMPLE_CASE_FOLDING,                                                    /**<  */
    I18N_UCHAR_SIMPLE_LOWERCASE_MAPPING,                                               /**<  */
    I18N_UCHAR_SIMPLE_TITLECASE_MAPPING,                                               /**<  */
    I18N_UCHAR_SIMPLE_UPPERCASE_MAPPING,                                               /**<  */ 
    I18N_UCHAR_TITLECASE_MAPPING,                                                      /**<  */
    
    I18N_UCHAR_UPPERCASE_MAPPING               = 0x400C,                               /**<  */
    I18N_UCHAR_BIDI_PAIRED_BRACKET,                                                    /**<  */
    I18N_UCHAR_STRING_LIMIT,                                                           /**<  */
    
    I18N_UCHAR_SCRIPT_EXTENSIONS               = 0x7000,                               /**<  */
    I18N_UCHAR_OTHER_PROPERTY_START            = I18N_UCHAR_SCRIPT_EXTENSIONS,         /**<  */
    I18N_UCHAR_OTHER_PROPERTY_LIMIT,                                                   /**<  */
    I18N_UCHAR_INVALID_CODE                    = -1                                    /**<  */
} i18n_uchar_uproperty_e;

/**
 * @brief Constants for Unicode blocks, see the Unicode Data file Blocks.txt.
 */
typedef enum {
    I18N_UCHAR_UBLOCK_NO_BLOCK,                                                  /**<  */
    I18N_UCHAR_UBLOCK_BASIC_LATIN,                                               /**<  */
    I18N_UCHAR_UBLOCK_LATIN_1_SUPPLEMENT,                                        /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_A,                                          /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_B,                                          /**<  */
    I18N_UCHAR_UBLOCK_IPA_EXTENSIONS,                                            /**<  */  
    I18N_UCHAR_UBLOCK_SPACING_MODIFIER_LETTERS,                                  /**<  */
    I18N_UCHAR_UBLOCK_COMBINING_DIACRITICAL_MARKS,                               /**<  */
    I18N_UCHAR_UBLOCK_GREEK,                                                     /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC,                                                  /**<  */
    I18N_UCHAR_UBLOCK_ARMENIAN,                                                  /**<  */
    I18N_UCHAR_UBLOCK_HEBREW,                                                    /**<  */
    I18N_UCHAR_UBLOCK_ARABIC,                                                    /**<  */
    I18N_UCHAR_UBLOCK_SYRIAC,                                                    /**<  */
    I18N_UCHAR_UBLOCK_THAANA,                                                    /**<  */
    I18N_UCHAR_UBLOCK_DEVANAGARI,                                                /**<  */
    I18N_UCHAR_UBLOCK_BENGALI,                                                   /**<  */
    I18N_UCHAR_UBLOCK_GURMUKHI,                                                  /**<  */
    I18N_UCHAR_UBLOCK_GUJARATI,                                                  /**<  */
    I18N_UCHAR_UBLOCK_ORIYA,                                                     /**<  */
    I18N_UCHAR_UBLOCK_TAMIL,                                                     /**<  */
    I18N_UCHAR_UBLOCK_TELUGU,                                                    /**<  */
    I18N_UCHAR_UBLOCK_KANNADA,                                                   /**<  */
    I18N_UCHAR_UBLOCK_MALAYALAM,                                                 /**<  */
    I18N_UCHAR_UBLOCK_SINHALA,                                                   /**<  */
    I18N_UCHAR_UBLOCK_THAI,                                                      /**<  */
    I18N_UCHAR_UBLOCK_LAO,                                                       /**<  */
    I18N_UCHAR_UBLOCK_TIBETAN,                                                   /**<  */
    I18N_UCHAR_UBLOCK_MYANMAR,                                                   /**<  */                
    I18N_UCHAR_UBLOCK_GEORGIAN,                                                  /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_JAMO,                                               /**<  */
    I18N_UCHAR_UBLOCK_ETHIOPIC,                                                  /**<  */
    I18N_UCHAR_UBLOCK_CHEROKEE,                                                  /**<  */
    I18N_UCHAR_UBLOCK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS,                     /**<  */
    I18N_UCHAR_UBLOCK_OGHAM,                                                     /**<  */
    I18N_UCHAR_UBLOCK_RUNIC,                                                     /**<  */
    I18N_UCHAR_UBLOCK_KHMER,                                                     /**<  */
    I18N_UCHAR_UBLOCK_MONGOLIAN,                                                 /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_ADDITIONAL,                                 /**<  */
    I18N_UCHAR_UBLOCK_GREEK_EXTENDED,                                            /**<  */
    I18N_UCHAR_UBLOCK_GENERAL_PUNCTUATION,                                       /**<  */
    I18N_UCHAR_UBLOCK_SUPERSCRIPTS_AND_SUBSCRIPTS,                               /**<  */
    I18N_UCHAR_UBLOCK_CURRENCY_SYMBOLS,                                          /**<  */
    I18N_UCHAR_UBLOCK_COMBINING_MARKS_FOR_SYMBOLS,                               /**<  */
    I18N_UCHAR_UBLOCK_LETTERLIKE_SYMBOLS,                                        /**<  */
    I18N_UCHAR_UBLOCK_NUMBER_FORMS,                                              /**<  */
    I18N_UCHAR_UBLOCK_ARROWS,                                                    /**<  */
    I18N_UCHAR_UBLOCK_MATHEMATICAL_OPERATORS,                                    /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_TECHNICAL,                                   /**<  */
    I18N_UCHAR_UBLOCK_CONTROL_PICTURES,                                          /**<  */
    I18N_UCHAR_UBLOCK_OPTICAL_CHARACTER_RECOGNITION,                             /**<  */
    I18N_UCHAR_UBLOCK_ENCLOSED_ALPHANUMERICS,                                    /**<  */
    I18N_UCHAR_UBLOCK_BOX_DRAWING,                                               /**<  */
    I18N_UCHAR_UBLOCK_BLOCK_ELEMENTS,                                            /**<  */
    I18N_UCHAR_UBLOCK_GEOMETRIC_SHAPES,                                          /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_SYMBOLS,                                     /**<  */
    I18N_UCHAR_UBLOCK_DINGBATS,                                                  /**<  */
    I18N_UCHAR_UBLOCK_BRAILLE_PATTERNS,                                          /**<  */
    I18N_UCHAR_UBLOCK_CJK_RADICALS_SUPPLEMENT,                                   /**<  */
    I18N_UCHAR_UBLOCK_KANGXI_RADICALS,                                           /**<  */
    I18N_UCHAR_UBLOCK_IDEOGRAPHIC_DESCRIPTION_CHARACTERS,                        /**<  */
    I18N_UCHAR_UBLOCK_CJK_SYMBOLS_AND_PUNCTUATION,                               /**<  */
    I18N_UCHAR_UBLOCK_HIRAGANA,                                                  /**<  */
    I18N_UCHAR_UBLOCK_KATAKANA,                                                  /**<  */
    I18N_UCHAR_UBLOCK_BOPOMOFO,                                                  /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_COMPATIBILITY_JAMO,                                 /**<  */
    I18N_UCHAR_UBLOCK_KANBUN,                                                    /**<  */
    I18N_UCHAR_UBLOCK_BOPOMOFO_EXTENDED,                                         /**<  */
    I18N_UCHAR_UBLOCK_ENCLOSED_CJK_LETTERS_AND_MONTHS,                           /**<  */
    I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY,                                         /**<  */
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A,                        /**<  */
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS,                                    /**<  */
    I18N_UCHAR_UBLOCK_YI_SYLLABLES,                                              /**<  */
    I18N_UCHAR_UBLOCK_YI_RADICALS,                                               /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_SYLLABLES,                                          /**<  */
    I18N_UCHAR_UBLOCK_HIGH_SURROGATES,                                           /**<  */
    I18N_UCHAR_UBLOCK_HIGH_PRIVATE_USE_SURROGATES,                               /**<  */
    I18N_UCHAR_UBLOCK_LOW_SURROGATES,                                            /**<  */    
    I18N_UCHAR_UBLOCK_PRIVATE_USE_AREA,                                          /**<  */
    I18N_UCHAR_UBLOCK_PRIVATE_USE,                                               /**<  */
    I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY_IDEOGRAPHS,                              /**<  */   
 
    I18N_UCHAR_UBLOCK_ALPHABETIC_PRESENTATION_FORMS,                             /**<  */
    I18N_UCHAR_UBLOCK_ARABIC_PRESENTATION_FORMS_A,                               /**<  */
    I18N_UCHAR_UBLOCK_COMBINING_HALF_MARKS,                                      /**<  */
    I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY_FORMS,                                   /**<  */
    I18N_UCHAR_UBLOCK_SMALL_FORM_VARIANTS,                                       /**<  */
    I18N_UCHAR_UBLOCK_ARABIC_PRESENTATION_FORMS_B,                               /**<  */
    I18N_UCHAR_UBLOCK_SPECIALS,                                                  /**<  */
    I18N_UCHAR_UBLOCK_HALFWIDTH_AND_FULLWIDTH_FORMS,                             /**<  */
    I18N_UCHAR_UBLOCK_OLD_ITALIC,                                                /**<  */
    I18N_UCHAR_UBLOCK_GOTHIC,                                                    /**<  */
    I18N_UCHAR_UBLOCK_DESERET,                                                   /**<  */
    I18N_UCHAR_UBLOCK_BYZANTINE_MUSICAL_SYMBOLS,                                 /**<  */
    I18N_UCHAR_UBLOCK_MUSICAL_SYMBOLS,                                           /**<  */   
    I18N_UCHAR_UBLOCK_MATHEMATICAL_ALPHANUMERIC_SYMBOLS,                         /**<  */        
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B,                        /**<  */
    I18N_UCHAR_UBLOCK_CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT,                   /**<  */    
    I18N_UCHAR_UBLOCK_TAGS,                                                      /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC_SUPPLEMENT,                                       /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC_SUPPLEMENTARY,                                    /**<  */
    I18N_UCHAR_UBLOCK_TAGALOG,                                                   /**<  */
    I18N_UCHAR_UBLOCK_HANUNOO,                                                   /**<  */
    I18N_UCHAR_UBLOCK_BUHID,                                                     /**<  */
    I18N_UCHAR_UBLOCK_TAGBANWA,                                                  /**<  */    
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A,                      /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTAL_ARROWS_A,                                     /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTAL_ARROWS_B,                                     /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B,                      /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTAL_MATHEMATICAL_OPERATORS,                       /**<  */
    I18N_UCHAR_UBLOCK_KATAKANA_PHONETIC_EXTENSIONS,                              /**<  */
    I18N_UCHAR_UBLOCK_VARIATION_SELECTORS,                                       /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTARY_PRIVATE_USE_AREA_A,                          /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTARY_PRIVATE_USE_AREA_B,                          /**<  */
    I18N_UCHAR_UBLOCK_LIMBU,                                                     /**<  */
    I18N_UCHAR_UBLOCK_TAI_LE,                                                    /**<  */
    I18N_UCHAR_UBLOCK_KHMER_SYMBOLS,                                             /**<  */
    I18N_UCHAR_UBLOCK_PHONETIC_EXTENSIONS,                                       /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_SYMBOLS_AND_ARROWS,                          /**<  */
    I18N_UCHAR_UBLOCK_YIJING_HEXAGRAM_SYMBOLS,                                   /**<  */
    I18N_UCHAR_UBLOCK_LINEAR_B_SYLLABARY,                                        /**<  */
    I18N_UCHAR_UBLOCK_LINEAR_B_IDEOGRAMS,                                        /**<  */
    I18N_UCHAR_UBLOCK_AEGEAN_NUMBERS,                                            /**<  */    
    I18N_UCHAR_UBLOCK_UGARITIC,                                                  /**<  */   
    I18N_UCHAR_UBLOCK_SHAVIAN,                                                   /**<  */
    I18N_UCHAR_UBLOCK_OSMANYA,                                                   /**<  */   
    I18N_UCHAR_UBLOCK_CYPRIOT_SYLLABARY,                                         /**<  */
    I18N_UCHAR_UBLOCK_TAI_XUAN_JING_SYMBOLS,                                     /**<  */
    I18N_UCHAR_UBLOCK_VARIATION_SELECTORS_SUPPLEMENT,                            /**<  */
    I18N_UCHAR_UBLOCK_ANCIENT_GREEK_MUSICAL_NOTATION,                            /**<  */
    I18N_UCHAR_UBLOCK_ANCIENT_GREEK_NUMBERS,                                     /**<  */
    I18N_UCHAR_UBLOCK_ARABIC_SUPPLEMENT,                                         /**<  */
    I18N_UCHAR_UBLOCK_BUGINESE,                                                  /**<  */
    I18N_UCHAR_UBLOCK_CJK_STROKES,                                               /**<  */
    I18N_UCHAR_UBLOCK_COMBINING_DIACRITICAL_MARKS_SUPPLEMENT,                    /**<  */
    I18N_UCHAR_UBLOCK_COPTIC,                                                    /**<  */
    I18N_UCHAR_UBLOCK_ETHIOPIC_EXTENDED,                                         /**<  */
    I18N_UCHAR_UBLOCK_ETHIOPIC_SUPPLEMENT,                                       /**<  */
    I18N_UCHAR_UBLOCK_GEORGIAN_SUPPLEMENT,                                       /**<  */
    I18N_UCHAR_UBLOCK_GLAGOLITIC,                                                /**<  */
    I18N_UCHAR_UBLOCK_KHAROSHTHI,                                                /**<  */    
    I18N_UCHAR_UBLOCK_MODIFIER_TONE_LETTERS,                                     /**<  */
    I18N_UCHAR_UBLOCK_NEW_TAI_LUE,                                               /**<  */
    I18N_UCHAR_UBLOCK_OLD_PERSIAN,                                               /**<  */
    I18N_UCHAR_UBLOCK_PHONETIC_EXTENSIONS_SUPPLEMENT,                            /**<  */
    I18N_UCHAR_UBLOCK_SUPPLEMENTAL_PUNCTUATION,                                  /**<  */
    I18N_UCHAR_UBLOCK_SYLOTI_NAGRI,                                              /**<  */
    I18N_UCHAR_UBLOCK_TIFINAGH,                                                  /**<  */
    I18N_UCHAR_UBLOCK_VERTICAL_FORMS,                                            /**<  */
    I18N_UCHAR_UBLOCK_NKO,                                                       /**<  */
    I18N_UCHAR_UBLOCK_BALINESE,                                                  /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_C,                                          /**<  */
    I18N_UCHAR_UBLOCK_LATIN_EXTENDED_D,                                          /**<  */
    I18N_UCHAR_UBLOCK_PHAGS_PA,                                                  /**<  */
    I18N_UCHAR_UBLOCK_PHOENICIAN,                                                /**<  */
    I18N_UCHAR_UBLOCK_CUNEIFORM,                                                 /**<  */
    I18N_UCHAR_UBLOCK_CUNEIFORM_NUMBERS_AND_PUNCTUATION,                         /**<  */
    I18N_UCHAR_UBLOCK_COUNTING_ROD_NUMERALS,                                     /**<  */
    I18N_UCHAR_UBLOCK_SUNDANESE,                                                 /**<  */
    I18N_UCHAR_UBLOCK_LEPCHA,                                                    /**<  */
    I18N_UCHAR_UBLOCK_OL_CHIKI,                                                  /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC_EXTENDED_A,                                       /**<  */
    I18N_UCHAR_UBLOCK_VAI,                                                       /**<  */
    I18N_UCHAR_UBLOCK_CYRILLIC_EXTENDED_B,                                       /**<  */
    I18N_UCHAR_UBLOCK_SAURASHTRA,                                                /**<  */
    I18N_UCHAR_UBLOCK_KAYAH_LI,                                                  /**<  */
    I18N_UCHAR_UBLOCK_REJANG,                                                    /**<  */
    I18N_UCHAR_UBLOCK_CHAM,                                                      /**<  */
    I18N_UCHAR_UBLOCK_ANCIENT_SYMBOLS,                                           /**<  */
    I18N_UCHAR_UBLOCK_PHAISTOS_DISC,                                             /**<  */
    I18N_UCHAR_UBLOCK_LYCIAN,                                                    /**<  */
    I18N_UCHAR_UBLOCK_CARIAN,                                                    /**<  */
    I18N_UCHAR_UBLOCK_LYDIAN,                                                    /**<  */
    I18N_UCHAR_UBLOCK_MAHJONG_TILES,                                             /**<  */
    I18N_UCHAR_UBLOCK_DOMINO_TILES,                                              /**<  */
    I18N_UCHAR_UBLOCK_SAMARITAN,                                                 /**<  */
    I18N_UCHAR_UBLOCK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED,            /**<  */
    I18N_UCHAR_UBLOCK_TAI_THAM,                                                  /**<  */
    I18N_UCHAR_UBLOCK_VEDIC_EXTENSIONS,                                          /**<  */
    I18N_UCHAR_UBLOCK_LISU,                                                      /**<  */
    I18N_UCHAR_UBLOCK_BAMUM,                                                     /**<  */
    I18N_UCHAR_UBLOCK_COMMON_INDIC_NUMBER_FORMS,                                 /**<  */
    I18N_UCHAR_UBLOCK_DEVANAGARI_EXTENDED,                                       /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_JAMO_EXTENDED_A,                                    /**<  */
    I18N_UCHAR_UBLOCK_JAVANESE,                                                  /**<  */
    I18N_UCHAR_UBLOCK_MYANMAR_EXTENDED_A,                                        /**<  */
    I18N_UCHAR_UBLOCK_TAI_VIET,                                                  /**<  */
    I18N_UCHAR_UBLOCK_MEETEI_MAYEK,                                              /**<  */
    I18N_UCHAR_UBLOCK_HANGUL_JAMO_EXTENDED_B,                                    /**<  */
    I18N_UCHAR_UBLOCK_IMPERIAL_ARAMAIC,                                          /**<  */
    I18N_UCHAR_UBLOCK_OLD_SOUTH_ARABIAN,                                         /**<  */
    I18N_UCHAR_UBLOCK_AVESTAN,                                                   /**<  */
    I18N_UCHAR_UBLOCK_INSCRIPTIONAL_PARTHIAN,                                    /**<  */
    I18N_UCHAR_UBLOCK_INSCRIPTIONAL_PAHLAVI,                                     /**<  */
    I18N_UCHAR_UBLOCK_OLD_TURKIC,                                                /**<  */
    I18N_UCHAR_UBLOCK_RUMI_NUMERAL_SYMBOLS,                                      /**<  */
    I18N_UCHAR_UBLOCK_KAITHI,                                                    /**<  */
    I18N_UCHAR_UBLOCK_EGYPTIAN_HIEROGLYPHS,                                      /**<  */
    I18N_UCHAR_UBLOCK_ENCLOSED_ALPHANUMERIC_SUPPLEMENT,                          /**<  */
    I18N_UCHAR_UBLOCK_ENCLOSED_IDEOGRAPHIC_SUPPLEMENT,                           /**<  */
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C,                        /**<  */
    I18N_UCHAR_UBLOCK_MANDAIC,                                                   /**<  */
    I18N_UCHAR_UBLOCK_BATAK,                                                     /**<  */
    I18N_UCHAR_UBLOCK_ETHIOPIC_EXTENDED_A,                                       /**<  */
    I18N_UCHAR_UBLOCK_BRAHMI,                                                    /**<  */
    I18N_UCHAR_UBLOCK_BAMUM_SUPPLEMENT,                                          /**<  */
    I18N_UCHAR_UBLOCK_KANA_SUPPLEMENT,                                           /**<  */
    I18N_UCHAR_UBLOCK_PLAYING_CARDS,                                             /**<  */
    I18N_UCHAR_UBLOCK_MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS,                     /**<  */
    I18N_UCHAR_UBLOCK_EMOTICONS,                                                 /**<  */
    I18N_UCHAR_UBLOCK_TRANSPORT_AND_MAP_SYMBOLS,                                 /**<  */
    I18N_UCHAR_UBLOCK_ALCHEMICAL_SYMBOLS,                                        /**<  */
    I18N_UCHAR_UBLOCK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D,                        /**<  */
    I18N_UCHAR_UBLOCK_COUNT,                                                     /**<  */
    I18N_UCHAR_UBLOCK_INVALID_CODE = -1                                          /**<  */
} i18n_uchar_ublock_code_e;

/**
  * @brief Enumeration for the language directional property of a character set.
  */
typedef enum {
 /*
 * Note: UCharDirection constants and their API comments are parsed by preparseucd.py.
 * It matches pairs of lines like
 * / ** <Unicode 1..3-letter Bidi_Class value> comment... * /
 * U_<[A-Z_]+> = <integer>,
 */
    I18N_UCHAR_U_LEFT_TO_RIGHT,                                      /**< L */
    I18N_UCHAR_U_RIGHT_TO_LEFT,                                      /**< R */
    I18N_UCHAR_U_EUROPEAN_NUMBER,                                    /**< EN */
    I18N_UCHAR_U_EUROPEAN_NUMBER_SEPARATOR,                          /**< ES */
    I18N_UCHAR_U_EUROPEAN_NUMBER_TERMINATOR,                         /**< ET */
    I18N_UCHAR_U_ARABIC_NUMBER,                                      /**< AN */
    I18N_UCHAR_U_COMMON_NUMBER_SEPARATOR,                            /**< CS */
    I18N_UCHAR_U_BLOCK_SEPARATOR,                                    /**< B */
    I18N_UCHAR_U_SEGMENT_SEPARATOR,                                  /**< S */
    I18N_UCHAR_U_WHITE_SPACE_NEUTRAL,                                /**< WS */
    I18N_UCHAR_U_OTHER_NEUTRAL,                                      /**< ON */
    I18N_UCHAR_U_LEFT_TO_RIGHT_EMBEDDING,                            /**< LRE */
    I18N_UCHAR_U_LEFT_TO_RIGHT_OVERRIDE,                             /**< LRO */
    I18N_UCHAR_U_RIGHT_TO_LEFT_ARABIC,                               /**< AL */
    I18N_UCHAR_U_RIGHT_TO_LEFT_EMBEDDING,                            /**< RLE */
    I18N_UCHAR_U_RIGHT_TO_LEFT_OVERRIDE,                             /**< RLO */
    I18N_UCHAR_U_POP_DIRECTIONAL_FORMAT,                             /**< PDF */
    I18N_UCHAR_U_DIR_NON_SPACING_MARK,                               /**< NSM */
    I18N_UCHAR_U_BOUNDARY_NEUTRAL,                                   /**< BN */
    I18N_UCHAR_U_CHAR_DIRECTION_COUNT                                /**<  */
} i18n_uchar_direction_e;

/**
  * @brief Enumeration for Decomposition Type constants.
  */
typedef enum {
 /*
 * Note: UDecompositionType constants are parsed by preparseucd.py.
 * It matches lines like
 * U_DT_<Unicode Decomposition_Type value name>
 */
    I18N_UCHAR_U_DT_NONE,           /**< [none] */
    I18N_UCHAR_U_DT_CANONICAL,      /**< [can] */
    I18N_UCHAR_U_DT_COMPAT,         /**< [com] */
    I18N_UCHAR_U_DT_CIRCLE,         /**< [enc] */
    I18N_UCHAR_U_DT_FINAL,          /**< [fin] */
    I18N_UCHAR_U_DT_FONT,           /**< [font] */
    I18N_UCHAR_U_DT_FRACTION,       /**< [fra] */
    I18N_UCHAR_U_DT_INITIAL,        /**< [init] */
    I18N_UCHAR_U_DT_ISOLATED,       /**< [iso] */
    I18N_UCHAR_U_DT_MEDIAL,         /**< [med] */
    I18N_UCHAR_U_DT_NARROW,         /**< [nar] */
    I18N_UCHAR_U_DT_NOBREAK,        /**< [nb] */
    I18N_UCHAR_U_DT_SMALL,          /**< [sml] */
    I18N_UCHAR_U_DT_SQUARE,         /**< [sqr] */
    I18N_UCHAR_U_DT_SUB,            /**< [sub] */
    I18N_UCHAR_U_DT_SUPER,          /**< [sup] */
    I18N_UCHAR_U_DT_VERTICAL,       /**< [vert] */
    I18N_UCHAR_U_DT_WIDE,           /**< [wide] */
    I18N_UCHAR_U_DT_COUNT           /**< 18 */
} i18n_uchar_u_decomposition_type_e;

/**
  * @brief Enumeration for East Asian Width constants.
  */
typedef enum {
    I18N_UCHAR_U_EA_NEUTRAL,         /**< [N] */
    I18N_UCHAR_U_EA_AMBIGUOUS,       /**< [A] */
    I18N_UCHAR_U_EA_HALFWIDTH,       /**< [H] */
    I18N_UCHAR_U_EA_FULLWIDTH,       /**< [F] */
    I18N_UCHAR_U_EA_NARROW,          /**< [Na] */
    I18N_UCHAR_U_EA_WIDE,            /**< [W] */
    I18N_UCHAR_U_EA_COUNT
} i18n_uchar_u_east_asian_width_e;

/**
  * @brief Enumeration for Unicode general category types.
  */
typedef enum {
    I18N_UCHAR_U_UNASSIGNED,                        /**< Non-category for unassigned and non-character code points */
    I18N_UCHAR_U_GENERAL_OTHER_TYPES = 0,           /**< Cn "Other, Not Assigned (no characters in [UnicodeData.txt] have this property)" (same as I18N_UCHAR_U_UNASSIGNED!) */
    I18N_UCHAR_U_UPPERCASE_LETTER,                  /**< Lu */
    I18N_UCHAR_U_LOWERCASE_LETTER,                  /**< Ll */
    I18N_UCHAR_U_TITLECASE_LETTER,                  /**< Lt */
    I18N_UCHAR_U_MODIFIER_LETTER,                   /**< Lm */
    I18N_UCHAR_U_OTHER_LETTER,                      /**< Lo */
    I18N_UCHAR_U_NON_SPACING_MARK,                  /**< Mn */
    I18N_UCHAR_U_ENCLOSING_MARK,                    /**< Me */
    I18N_UCHAR_U_COMBINING_SPACING_MARK,            /**< Mc */
    I18N_UCHAR_U_DECIMAL_DIGIT_NUMBER,              /**< Nd */
    I18N_UCHAR_U_LETTER_NUMBER,                     /**< Nl */
    I18N_UCHAR_U_OTHER_NUMBER,                      /**< No */
    I18N_UCHAR_U_SPACE_SEPARATOR,                   /**< Zs */
    I18N_UCHAR_U_LINE_SEPARATOR,                    /**< Zl */
    I18N_UCHAR_U_PARAGRAPH_SEPARATOR,               /**< Zp */
    I18N_UCHAR_U_CONTROL_CHAR,                      /**< Cc */
    I18N_UCHAR_U_FORMAT_CHAR,                       /**< Cf */
    I18N_UCHAR_U_PRIVATE_USE_CHAR,                  /**< Co */
    I18N_UCHAR_U_SURROGATE,                         /**< Cs */
    I18N_UCHAR_U_DASH_PUNCTUATION,                  /**< Pd */
    I18N_UCHAR_U_START_PUNCTUATION,                 /**< Ps */
    I18N_UCHAR_U_END_PUNCTUATION,                   /**< Pe */
    I18N_UCHAR_U_CONNECTOR_PUNCTUATION,             /**< Pc */
    I18N_UCHAR_U_OTHER_PUNCTUATION,                 /**< Po */
    I18N_UCHAR_U_MATH_SYMBOL,                       /**< Sm */
    I18N_UCHAR_U_CURRENCY_SYMBOL,                   /**< Sc */
    I18N_UCHAR_U_MODIFIER_SYMBOL,                   /**< Sk */
    I18N_UCHAR_U_OTHER_SYMBOL,                      /**< So */
    I18N_UCHAR_U_INITIAL_PUNCTUATION,               /**< Pi */
    I18N_UCHAR_U_FINAL_PUNCTUATION,                 /**< Pf */
    I18N_UCHAR_U_CHAR_CATEGORY_COUNT                /**< One higher than the last enum i18n_uchar_category_e constant */
} i18n_uchar_category_e;

/**
  * @brief Enumeration for Joining Group constants.
  */
typedef enum {
  /*
  * Note: UJoiningGroup constants are parsed by preparseucd.py.
  * It matches lines like
  * U_JG_<Unicode Joining_Group value name>
  */
    I18N_UCHAR_U_JG_NO_JOINING_GROUP,                                              /**<  */
    I18N_UCHAR_U_JG_AIN,                                                           /**<  */
    I18N_UCHAR_U_JG_ALAPH,                                                         /**<  */
    I18N_UCHAR_U_JG_ALEF,                                                          /**<  */
    I18N_UCHAR_U_JG_BEH,                                                           /**<  */
    I18N_UCHAR_U_JG_BETH,                                                          /**<  */
    I18N_UCHAR_U_JG_DAL,                                                           /**<  */
    I18N_UCHAR_U_JG_DALATH_RISH,                                                   /**<  */
    I18N_UCHAR_U_JG_E,                                                             /**<  */
    I18N_UCHAR_U_JG_FEH,                                                           /**<  */
    I18N_UCHAR_U_JG_FINAL_SEMKATH,                                                 /**<  */
    I18N_UCHAR_U_JG_GAF,                                                           /**<  */
    I18N_UCHAR_U_JG_GAMAL,                                                         /**<  */
    I18N_UCHAR_U_JG_HAH,                                                           /**<  */
    I18N_UCHAR_U_JG_TEH_MARBUTA_GOAL,                                              /**<  */
    I18N_UCHAR_U_JG_HAMZA_ON_HEH_GOAL = I18N_UCHAR_U_JG_TEH_MARBUTA_GOAL,          /**<  */
    I18N_UCHAR_U_JG_HE,                                                            /**<  */
    I18N_UCHAR_U_JG_HEH,                                                           /**<  */
    I18N_UCHAR_U_JG_HEH_GOAL,                                                      /**<  */
    I18N_UCHAR_U_JG_HETH,                                                          /**<  */
    I18N_UCHAR_U_JG_KAF,                                                           /**<  */
    I18N_UCHAR_U_JG_KAPH,                                                          /**<  */
    I18N_UCHAR_U_JG_KNOTTED_HEH,                                                   /**<  */
    I18N_UCHAR_U_JG_LAM,                                                           /**<  */
    I18N_UCHAR_U_JG_LAMADH,                                                        /**<  */
    I18N_UCHAR_U_JG_MEEM,                                                          /**<  */
    I18N_UCHAR_U_JG_MIM,                                                           /**<  */
    I18N_UCHAR_U_JG_NOON,                                                          /**<  */
    I18N_UCHAR_U_JG_NUN,                                                           /**<  */
    I18N_UCHAR_U_JG_PE,                                                            /**<  */
    I18N_UCHAR_U_JG_QAF,                                                           /**<  */
    I18N_UCHAR_U_JG_QAPH,                                                          /**<  */
    I18N_UCHAR_U_JG_REH,                                                           /**<  */
    I18N_UCHAR_U_JG_REVERSED_PE,                                                   /**<  */
    I18N_UCHAR_U_JG_SAD,                                                           /**<  */
    I18N_UCHAR_U_JG_SADHE,                                                         /**<  */
    I18N_UCHAR_U_JG_SEEN,                                                          /**<  */
    I18N_UCHAR_U_JG_SEMKATH,                                                       /**<  */
    I18N_UCHAR_U_JG_SHIN,                                                          /**<  */
    I18N_UCHAR_U_JG_SWASH_KAF,                                                     /**<  */
    I18N_UCHAR_U_JG_SYRIAC_WAW,                                                    /**<  */
    I18N_UCHAR_U_JG_TAH,                                                           /**<  */
    I18N_UCHAR_U_JG_TAW,                                                           /**<  */
    I18N_UCHAR_U_JG_TEH_MARBUTA,                                                   /**<  */
    I18N_UCHAR_U_JG_TETH,                                                          /**<  */
    I18N_UCHAR_U_JG_WAW,                                                           /**<  */
    I18N_UCHAR_U_JG_YEH,                                                           /**<  */
    I18N_UCHAR_U_JG_YEH_BARREE,                                                    /**<  */
    I18N_UCHAR_U_JG_YEH_WITH_TAIL,                                                 /**<  */
    I18N_UCHAR_U_JG_YUDH,                                                          /**<  */
    I18N_UCHAR_U_JG_YUDH_HE,                                                       /**<  */
    I18N_UCHAR_U_JG_ZAIN,                                                          /**<  */
    I18N_UCHAR_U_JG_FE,                                                            /**<  */
    I18N_UCHAR_U_JG_KHAPH,                                                         /**<  */
    I18N_UCHAR_U_JG_ZHAIN,                                                         /**<  */
    I18N_UCHAR_U_JG_BURUSHASKI_YEH_BARREE,                                         /**<  */
    I18N_UCHAR_U_JG_FARSI_YEH,                                                     /**<  */
    I18N_UCHAR_U_JG_NYA,                                                           /**<  */
    I18N_UCHAR_U_JG_ROHINGYA_YEH,
    I18N_UCHAR_U_JG_COUNT                                                          /**<  */
 } i18n_uchar_u_joining_group_e;

/**
  * @brief Enumeration for Joining Type constants.
  */
typedef enum {
 /*
 * Note: UJoiningType constants are parsed by preparseucd.py.
 * It matches lines like
 * U_JT_<Unicode Joining_Type value name>
 */
     I18N_UCHAR_U_JT_NON_JOINING,        /**< [U] */
     I18N_UCHAR_U_JT_JOIN_CAUSING,       /**< [C] */
     I18N_UCHAR_U_JT_DUAL_JOINING,       /**< [D] */
     I18N_UCHAR_U_JT_LEFT_JOINING,       /**< [L] */
     I18N_UCHAR_U_JT_RIGHT_JOINING,      /**< [R] */
     I18N_UCHAR_U_JT_TRANSPARENT,        /**< [T] */
     I18N_UCHAR_U_JT_COUNT               /**< 6 */
} i18n_uchar_u_joining_type_e;

/**
  * @brief Enumeration for Line Break constants.
  */
typedef enum {
  /*
  * Note: ULineBreak constants are parsed by preparseucd.py.
  * It matches lines like
  * U_LB_<Unicode Line_Break value name>
  */
    I18N_UCHAR_U_LB_UNKNOWN,                                                         /**< [XX] */
    I18N_UCHAR_U_LB_AMBIGUOUS,                                                       /**< [AI] */
    I18N_UCHAR_U_LB_ALPHABETIC,                                                      /**< [AL] */
    I18N_UCHAR_U_LB_BREAK_BOTH,                                                      /**< [B2] */
    I18N_UCHAR_U_LB_BREAK_AFTER,                                                     /**< [BA] */
    I18N_UCHAR_U_LB_BREAK_BEFORE,                                                    /**< [BB] */
    I18N_UCHAR_U_LB_MANDATORY_BREAK,                                                 /**< [BK] */
    I18N_UCHAR_U_LB_CONTINGENT_BREAK,                                                /**< [CB] */
    I18N_UCHAR_U_LB_CLOSE_PUNCTUATION,                                               /**< [CL] */
    I18N_UCHAR_U_LB_COMBINING_MARK,                                                  /**< [CM] */
    I18N_UCHAR_U_LB_CARRIAGE_RETURN,                                                 /**< [CR] */
    I18N_UCHAR_U_LB_EXCLAMATION,                                                     /**< [EX] */
    I18N_UCHAR_U_LB_GLUE,                                                            /**< [GL] */
    I18N_UCHAR_U_LB_HYPHEN,                                                          /**< [HY] */
    I18N_UCHAR_U_LB_IDEOGRAPHIC,                                                     /**< [ID] */
    I18N_UCHAR_U_LB_INSEPARABLE,                                                     /**< [IN] */
    I18N_UCHAR_U_LB_INSEPERABLE = I18N_UCHAR_U_LB_INSEPARABLE,
    I18N_UCHAR_U_LB_INFIX_NUMERIC,                                                   /**< [IS] */
    I18N_UCHAR_U_LB_LINE_FEED,                                                       /**< [LF] */
    I18N_UCHAR_U_LB_NONSTARTER,                                                      /**< [NS] */
    I18N_UCHAR_U_LB_NUMERIC,                                                         /**< [NU] */
    I18N_UCHAR_U_LB_OPEN_PUNCTUATION,                                                /**< [OP] */
    I18N_UCHAR_U_LB_POSTFIX_NUMERIC,                                                 /**< [PO] */
    I18N_UCHAR_U_LB_PREFIX_NUMERIC,                                                  /**< [PR] */
    I18N_UCHAR_U_LB_QUOTATION,                                                       /**< [QU] */
    I18N_UCHAR_U_LB_COMPLEX_CONTEXT,                                                 /**< [SA] */
    I18N_UCHAR_U_LB_SURROGATE,                                                       /**< [SG] */
    I18N_UCHAR_U_LB_SPACE,                                                           /**< [SP] */
    I18N_UCHAR_U_LB_BREAK_SYMBOLS,                                                   /**< [SY] */
    I18N_UCHAR_U_LB_ZWSPACE,                                                         /**< [ZW] */
    I18N_UCHAR_U_LB_NEXT_LINE,                                                       /**< [NL] */
    I18N_UCHAR_U_LB_WORD_JOINER,                                                     /**< [WJ] */
    I18N_UCHAR_U_LB_H2,                                                              /**< [H2] */
    I18N_UCHAR_U_LB_H3,                                                              /**< [H3] */
    I18N_UCHAR_U_LB_JL,                                                              /**< [JL] */
    I18N_UCHAR_U_LB_JT,                                                              /**< [JT] */
    I18N_UCHAR_U_LB_JV,                                                              /**< [JV] */
    I18N_UCHAR_U_LB_CLOSE_PARENTHESIS,                                               /**< [CP] */
    I18N_UCHAR_U_LB_COUNT       
 } i18n_uchar_u_line_break_e;

/**
  * @brief Enumeration for Numeric Type constants.
  */
typedef enum {
 /*
 * Note: UNumericType constants are parsed by preparseucd.py.
 * It matches lines like
 * U_NT_<Unicode Numeric_Type value name>
 */
     I18N_UCHAR_U_NT_NONE,         /**< [None] */
     I18N_UCHAR_U_NT_DECIMAL,      /**< [de] */
     I18N_UCHAR_U_NT_DIGIT,        /**< [di] */
     I18N_UCHAR_U_NT_NUMERIC,      /**< [nu] */
     I18N_UCHAR_U_NT_COUNT         /**<  */
} i18n_uchar_u_numeric_type_e;

/**
  * @brief Enumeration for Hangul Syllable Type constants.
  */
typedef enum {
 /*
 * Note: UHangulSyllableType constants are parsed by preparseucd.py.
 * It matches lines like
 * U_HST_<Unicode Hangul_Syllable_Type value name>
 */
     I18N_UCHAR_U_HST_NOT_APPLICABLE,     /**< [NA] */
     I18N_UCHAR_U_HST_LEADING_JAMO,       /**< [L] */
     I18N_UCHAR_U_HST_VOWEL_JAMO,         /**< [V] */
     I18N_UCHAR_U_HST_TRAILING_JAMO,      /**< [T] */
     I18N_UCHAR_U_HST_LV_SYLLABLE,        /**< [LV] */
     I18N_UCHAR_U_HST_LVT_SYLLABLE,       /**< [LVT] */
     I18N_UCHAR_U_HST_COUNT               /**<  */
} i18n_uchar_u_hangul_syllable_type_e;

/**
  * @brief Enumeration for Sentence Break constants.
  */
typedef enum {
 /*
 * Note: USentenceBreak constants are parsed by preparseucd.py.
 * It matches lines like
 * U_SB_<Unicode Sentence_Break value name>
 */
     I18N_UCHAR_U_SB_OTHER,         /**< [XX] */
     I18N_UCHAR_U_SB_ATERM,         /**< [AT] */
     I18N_UCHAR_U_SB_CLOSE,         /**< [CL] */
     I18N_UCHAR_U_SB_FORMAT,        /**< [FO] */
     I18N_UCHAR_U_SB_LOWER,         /**< [LO] */
     I18N_UCHAR_U_SB_NUMERIC,       /**< [NU] */
     I18N_UCHAR_U_SB_OLETTER,       /**< [LE] */
     I18N_UCHAR_U_SB_SEP,           /**< [SE] */
     I18N_UCHAR_U_SB_SP,            /**< [SP] */
     I18N_UCHAR_U_SB_STERM,         /**< [ST] */
     I18N_UCHAR_U_SB_UPPER,         /**< [UP] */
     I18N_UCHAR_U_SB_CR,            /**< [CR] */
     I18N_UCHAR_U_SB_EXTEND,        /**< [EX] */
     I18N_UCHAR_U_SB_LF,            /**< [LF] */
     I18N_UCHAR_U_SB_SCONTINUE,     /**< [SC] */
     I18N_UCHAR_U_SB_COUNT          /**<  */
} i18n_uchar_u_sentence_break_e;

/**
  * @brief Enumeration for Word Break constants.
  */
typedef enum {
 /*
 * Note: UWordBreakValues constants are parsed by preparseucd.py.
 * It matches lines like
 * U_WB_<Unicode Word_Break value name>
 */
     I18N_UCHAR_U_WB_OTHER,              /**< [XX] */
     I18N_UCHAR_U_WB_ALETTER,            /**< [LE] */
     I18N_UCHAR_U_WB_FORMAT,             /**< [FO] */
     I18N_UCHAR_U_WB_KATAKANA,           /**< [KA] */
     I18N_UCHAR_U_WB_MIDLETTER,          /**< [ML] */
     I18N_UCHAR_U_WB_MIDNUM,             /**< [MN] */
     I18N_UCHAR_U_WB_NUMERIC,            /**< [NU] */
     I18N_UCHAR_U_WB_EXTENDNUMLET,       /**< [EX] */
     I18N_UCHAR_U_WB_CR,                 /**< [CR] */
     I18N_UCHAR_U_WB_EXTEND,             /**< [Extend] */
     I18N_UCHAR_U_WB_LF,                 /**< [LF] */
     I18N_UCHAR_U_WB_MIDNUMLET,          /**< [MB] */
     I18N_UCHAR_U_WB_NEWLINE,            /**< [NL] */
     I18N_UCHAR_U_WB_COUNT               /**<  */
} i18n_uchar_u_word_break_values_e;

/**
  * @brief Enumeration for Grapheme Cluster Break constants.
  */
 typedef enum {
  /*
  * Note: UGraphemeClusterBreak constants are parsed by preparseucd.py.
  * It matches lines like
  * U_GCB_<Unicode Grapheme_Cluster_Break value name>
  */
      I18N_UCHAR_U_GCB_OTHER,                    /**< [XX] */
      I18N_UCHAR_U_GCB_CONTROL,                  /**< [CN] */
      I18N_UCHAR_U_GCB_CR,                       /**< [CR] */
      I18N_UCHAR_U_GCB_EXTEND,                   /**< [EX] */
      I18N_UCHAR_U_GCB_L,                        /**< [L] */
      I18N_UCHAR_U_GCB_LF,                       /**< [LF] */
      I18N_UCHAR_U_GCB_LV,                       /**< [LV] */
      I18N_UCHAR_U_GCB_LVT,                      /**< [LVT] */
      I18N_UCHAR_U_GCB_T,                        /**< [T] */
      I18N_UCHAR_U_GCB_V,                        /**< [V] */
      I18N_UCHAR_U_GCB_SPACING_MARK,             /**< [SM] */ 
      I18N_UCHAR_U_GCB_PREPEND,                  /**< [PP] */
      I18N_UCHAR_UCHAR_U_GCB_COUNT               /**<  */
 } i18n_uchar_u_grapheme_cluster_break_e;


/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCOLLATOR_MODULE
 * @{
 */

typedef void* i18n_ucollator_h;

/**
 * @brief Enumeration for attributes that collation service understands. 
 *     All the attributes can take I18N_UCOLLATOR_DEFAULT value, as well as the values specific to each one.
 */
typedef enum {
    I18N_UCOLLATOR_FRENCH_COLLATION,             /**< Attribute for direction of secondary weights - used in Canadian French. Acceptable values are #I18N_UCOLLATOR_ON, which results in secondary weights being considered backwards, and #I18N_UCOLLATOR_OFF which treats secondary weights in the order they appear */
    I18N_UCOLLATOR_ALTERNATE_HANDLING,           /**< Attribute for handling variable elements. Acceptable values are #I18N_UCOLLATOR_NON_IGNORABLE (default) which treats all the codepoints with non-ignorable primary weights in the same way, and #I18N_UCOLLATOR_SHIFTED which causes codepoints with primary weights that are equal or below the variable top value to be ignored at the primary level and moved to the quaternary level */
    I18N_UCOLLATOR_CASE_FIRST,                   /**< Controls the ordering of upper and lower case letters. Acceptable values are #I18N_UCOLLATOR_OFF (default), which orders upper and lower case letters in accordance to their tertiary weights, #I18N_UCOLLATOR_UPPER_FIRST which forces upper case letters to sort before lower case letters, and #I18N_UCOLLATOR_LOWER_FIRST which does the opposite */
    I18N_UCOLLATOR_CASE_LEVEL,                   /**< Controls whether an extra case level (positioned before the third level) is generated or not. Acceptable values are #I18N_UCOLLATOR_OFF (default), when case level is not generated, and #I18N_UCOLLATOR_ON which causes the case level to be generated. Contents of the case level are affected by the value of the #I18N_UCOLLATOR_CASE_FIRST attribute. A simple way to ignore accent differences in a string is to set the strength to #I18N_UCOLLATOR_PRIMARY and enable case level */
    I18N_UCOLLATOR_NORMALIZATION_MODE,           /**< Controls whether the normalization check and necessary normalizations are performed. When set to #I18N_UCOLLATOR_OFF (default) no normalization check is performed. The correctness of the result is guaranteed only if the input data is in so-called FCD form (see users manual for more info). When set to #I18N_UCOLLATOR_ON, an incremental check is performed to see whether the input data is in the FCD form. If the data is not in the FCD form, incremental NFD normalization is performed */
    I18N_UCOLLATOR_DECOMPOSITION_MODE = I18N_UCOLLATOR_NORMALIZATION_MODE,     /**< An alias for the #I18N_UCOLLATOR_NORMALIZATION_MODE attribute */
    I18N_UCOLLATOR_STRENGTH,                     /**< The strength attribute. Can be either #I18N_UCOLLATOR_PRIMARY, #I18N_UCOLLATOR_SECONDARY, #I18N_UCOLLATOR_TERTIARY, #I18N_UCOLLATOR_QUATERNARY, or #I18N_UCOLLATOR_IDENTICAL. The usual strength for most locales (except Japanese) is tertiary. Quaternary strength is useful when combined with shifted setting for the alternate handling attribute and for JIS X 4061 collation, when it is used to distinguish between Katakana and Hiragana. Otherwise, quaternary level is affected only by the number of non-ignorable code points in the string. Identical strength is rarely useful, as it amounts to codepoints of the NFD form of the string */
    I18N_UCOLLATOR_NUMERIC_COLLATION = I18N_UCOLLATOR_STRENGTH + 2,            /**< When turned on, this attribute makes substrings of digits that are sort according to their numeric values. This is a way to get '100' to sort AFTER '2'. Note that the longest digit substring that can be treated as a single unit is 254 digits (not counting leading zeros). If a digit substring is longer than that, the digits beyond the limit will be treated as a separate digit substring. A "digit" in this sense is a code point with General_Category=Nd, which does not include circled numbers, roman numerals, and so on. Only a contiguous digit substring is considered, that is, non-negative integers without separators. There is no support for plus/minus signs, decimals, exponents, and so on */
    I18N_UCOLLATOR_ATTRIBUTE_COUNT                        /**< The number of UColAttribute constants */
} i18n_ucollator_attribute_e;

/**
 * @brief Enumeration containing attribute values for controling collation behavior.
 *     Here are all the allowable values. Not every attribute can take every value. The only universal value is #I18N_UCOLLATOR_DEFAULT, which resets the attribute value to the predefined value for that locale.
 */
typedef enum {
    I18N_UCOLLATOR_DEFAULT           = -1,                          /**< Accepted by most attributes */
    I18N_UCOLLATOR_PRIMARY           = 0,                           /**< Primary collation strength */
    I18N_UCOLLATOR_SECONDARY         = 1,                           /**< Secondary collation strength */
    I18N_UCOLLATOR_TERTIARY          = 2,                           /**< Tertiary collation strength */
    I18N_UCOLLATOR_DEFAULT_STRENGTH  = I18N_UCOLLATOR_TERTIARY,     /**< Default collation strength */
    I18N_UCOLLATOR_CE_STRENGTH_LIMIT,    
    I18N_UCOLLATOR_QUATERNARY        = 3,                           /**< Quaternary collation strength */
    I18N_UCOLLATOR_IDENTICAL         = 15,                          /**< Identical collation strength */
    I18N_UCOLLATOR_STRENGTH_LIMIT,       
    
    I18N_UCOLLATOR_OFF               = 16,                          /**< Turn the feature off - works for #I18N_UCOLLATOR_FRENCH_COLLATION, #I18N_UCOLLATOR_CASE_LEVEL & #I18N_UCOLLATOR_DECOMPOSITION_MODE */
    I18N_UCOLLATOR_ON                = 17,                          /**< Turn the feature on - works for #I18N_UCOLLATOR_FRENCH_COLLATION, #I18N_UCOLLATOR_CASE_LEVEL & #I18N_UCOLLATOR_DECOMPOSITION_MODE */

    I18N_UCOLLATOR_SHIFTED           = 20,                          /**< Valid for #I18N_UCOLLATOR_ALTERNATE_HANDLING. Alternate handling will be shifted. */
    I18N_UCOLLATOR_NON_IGNORABLE     = 21,                          /**< Valid for #I18N_UCOLLATOR_ALTERNATE_HANDLING. Alternate handling will be non ignorable. */
    I18N_UCOLLATOR_LOWER_FIRST       = 24,                          /**< Valid for #I18N_UCOLLATOR_CASE_FIRST - lower case sorts before upper case. */
    I18N_UCOLLATOR_UPPER_FIRST       = 25,                           /**< Upper case sorts before lower case. */
    I18N_UCOLLATOR_ATTRIBUTE_VALUE_COUNT
} i18n_ucollator_attribute_value_e;

/**
 * @brief Enumeration in which the base letter represents a primary difference. Set comparison level to #I18N_UCOLLATOR_PRIMARY to ignore secondary and tertiary differences. Use this to set the strength of an i18n_ucollator_h. Example of primary difference, "abc" < "abd"
 *     Diacritical differences on the same base letter represent a secondary difference. Set comparison level to #I18N_UCOLLATOR_SECONDARY to ignore tertiary differences. Use this to set the strength of an i18n_ucollator_h. Example of secondary difference, "&auml;" >> "a".
 *     Uppercase and lowercase versions of the same character represent a tertiary difference. Set comparison level to #I18N_UCOLLATOR_TERTIARY to include all comparison differences. Use this to set the strength of an i18n_ucollator_h. Example of tertiary difference, "abc" <<< "ABC".
 *     Two characters are considered "identical" when they have the same unicode spellings. #I18N_UCOLLATOR_IDENTICAL. For example, "&auml;" == "&auml;".
 *     #i18n_ucollator_strength_e is also used to determine the strength of sort keys generated from Ui18n_ucollator_hs. These values can now be found in the #i18n_ucollator_attribute_value_e enum.
 */
typedef i18n_ucollator_attribute_value_e i18n_ucollator_strength_e;

/**
 * @brief Enumeration for source and target string comparison result. #I18N_UCOLLATOR_EQUAL is returned if the source string is compared to be less than the target string in the {@link #i18n_ucollator_str_collator() } method. 
 *     {@link #i18n_ucollator_equal() } is returned if the source string is compared to be equal to the target string in the {@link #i18n_ucollator_str_collator() } method. #I18N_UCOLLATOR_GREATER is returned if the source string is compared to be greater than the target string in the {@link #i18n_ucollator_str_collator() } method.
 */
typedef enum {
    I18N_UCOLLATOR_EQUAL     = 0,    /**< string a == string b */
    I18N_UCOLLATOR_GREATER   = 1,    /**< string a > string b */
    I18N_UCOLLATOR_LESS      = -1    /**< string a < string b */
} i18n_ucollator_result_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UNORMALIZATION_MODULE
 * @{
 */

typedef const void* i18n_unormalizer_h;

/**
 * @brief Enumeration of constants for normalization modes.
 *     For details about standard Unicode normalization forms and about the algorithms which are also used with custom mapping tables see http://www.unicode.org/unicode/reports/tr15/
 */
typedef enum {
    I18N_UNORMALIZATION_COMPOSE,              /**< Decomposition followed by composition. Same as standard NFC when using an "nfc" instance. Same as standard NFKC when using an "nfkc" instance. For details about standard Unicode normalization forms see http://www.unicode.org/unicode/reports/tr15/ */
    I18N_UNORMALIZATION_DECOMPOSE,            /**< Map and reorder canonically. Same as standard NFD when using an "nfc" instance. Same as standard NFKD when using an "nfkc" instance. For details about standard Unicode normalization forms see http://www.unicode.org/unicode/reports/tr15/ */
    I18N_UNORMALIZATION_FCD,                  /**< "Fast C or D" form. If a string is in this form, then further decomposition without reordering would yield the same form as DECOMPOSE. Text in "Fast C or D" form can be processed efficiently with data tables that are "canonically closed", that is, that provide equivalent data for equivalent text, without having to be fully normalized. Not a standard Unicode normalization form. Not a unique form: Different FCD strings can be canonically equivalent. For details see http://www.unicode.org/notes/tn5/#FCD  */
    I18N_UNORMALIZATION_COMPOSE_CONTIGUOUS    /**< Compose only contiguously. Also known as "FCC" or "Fast C Contiguous". The result will often but not always be in NFC. The result will conform to FCD which is useful for processing. Not a standard Unicode normalization form. For details see http://www.unicode.org/notes/tn5/#FCC  */
} i18n_unormalization_mode_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USEARCH_MODULE
 * @{
 */

typedef void* i18n_usearch_h;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UCALENDAR_MODULE
 * @{
 */

typedef void* i18n_ucalendar_h;

/**
 * @brief Enumeration for possible fields in an i18n_ucalendar_h.
 */
typedef enum {
    I18N_UCALENDAR_ERA,                                 /**< Field number indicating the era, e.g., AD or BC in the Gregorian (Julian) calendar*/
    I18N_UCALENDAR_YEAR,                                /**< Field number indicating the year */
    I18N_UCALENDAR_MONTH,                               /**< Field number indicating the month. This is a calendar-specific value. \n The first month of the year is JANUARY; the last depends on the number of months in a year */
    I18N_UCALENDAR_WEEK_OF_YEAR,                        /**< Field number indicating the week number within the current year. \n The first week of the year, as defined by the #I18N_UCALENDAR_FIRST_DAY_OF_WEEK and #I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK attributes, has value 1. Subclasses define the value of #I18N_UCALENDAR_WEEK_OF_YEAR for days before the first week of the year  */
    I18N_UCALENDAR_WEEK_OF_MONTH,                       /**< Field number indicating the week number within the current month. \n The first week of the month, as defined by the #I18N_UCALENDAR_FIRST_DAY_OF_WEEK and #I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK attributes, has value 1. Subclasses define the value of WEEK_OF_MONTH for days before the first week of the month  */
    I18N_UCALENDAR_DATE,                                /**< Field number indicating the day of the month.  \n This is a synonym for DAY_OF_MONTH. The first day of the month has value 1  */
    I18N_UCALENDAR_DAY_OF_YEAR,                         /**< Field number indicating the day number within the current year. \n The first day of the year has value 1. */
    I18N_UCALENDAR_DAY_OF_WEEK,                         /**< Field number indicating the day of the week.   \n This field takes values "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday, "Friday", and "Saturday" */
    I18N_UCALENDAR_DAY_OF_WEEK_IN_MONTH,                /**< Field number indicating the ordinal number of the day of the week within the current month.  \n Together with the "day of week" field, this uniquely specifies a day within a month. "day of month" 1 through 7 always correspond to "day of week in month" 1; 8 through 15 correspond to "day of week in month" 2, and so on. "day of week in month" 0 indicates the week before "day of week in month" 1. Negative values count back from the end of the month, so the last Sunday of a month is specified as "day of week" = "Sunday", "day of week in month" = -1. Because negative values count backward they will usually be aligned differently within the month than positive values. For example, if a month has 31 days, "day of week in month" -1 will overlap "day of week in month" 5 and the end of 4 */
    I18N_UCALENDAR_AM_PM,                               /**< Field number indicating whether the "hour" is before or after noon.  \n E.g., at 10:04:15.250 PM the AM_PM is PM */
    I18N_UCALENDAR_HOUR,                                /**< Field number indicating the hour of the morning or afternoon.  \n "hour" is used for the 12-hour clock. E.g., at 10:04:15.250 PM the "Hour" is 10 */
    I18N_UCALENDAR_HOUR_OF_DAY,                         /**< Field number indicating the hour of the day.  \n "Hour of day" is used for the 24-hour clock. E.g., at 10:04:15.250 PM the "Hour of day" is 22 */ 
    I18N_UCALENDAR_MINUTE,                              /**< Field number indicating the minute within the hour.  \n E.g., at 10:04:15.250 PM the #I18N_UCALENDAR_MINUTE is 4 */
    I18N_UCALENDAR_SECOND,                              /**< Field number indicating the second within the minute.  \n E.g., at 10:04:15.250 PM the #I18N_UCALENDAR_SECOND is 15 */ 
    I18N_UCALENDAR_MILLISECOND,                         /**< Field number indicating the millisecond within the second.  \n E.g., at 10:04:15.250 PM the #I18N_UCALENDAR_MILLISECOND is 250 */
    I18N_UCALENDAR_ZONE_OFFSET,                         /**< Field number indicating the raw offset from GMT in milliseconds  */
    I18N_UCALENDAR_DST_OFFSET,                          /**< Field number indicating the daylight savings offset in milliseconds  */
    I18N_UCALENDAR_YEAR_WOY,                            /**< Field number indicating the extended year corresponding to the #I18N_UCALENDAR_WEEK_OF_YEAR field.  \n This may be one greater or less than the value of #I18N_UCALENDAR_EXTENDED_YEAR */ 
    I18N_UCALENDAR_DOW_LOCAL,                           /**< Field number indicating the localized day of the week.  \n This will be a value from 1 to 7 inclusive, with 1 being the localized first day of the week */
    I18N_UCALENDAR_EXTENDED_YEAR,                       /**< Year of this calendar system, encompassing all supra-year fields.  \n For example, in Gregorian/Julian calendars, positive Extended Year values indicate years AD, 1 BC = 0 extended, 2 BC = -1 extended, and so on */
    I18N_UCALENDAR_JULIAN_DAY,                          /**< Field number indicating the modified Julian day number.  \n This is different from the conventional Julian day number in two regards. First, it demarcates days at local zone midnight, rather than noon GMT. Second, it is a local number; that is, it depends on the local time zone. It can be thought of as a single number that encompasses all the date-related fields */
    I18N_UCALENDAR_MILLISECONDS_IN_DAY,                 /**< Ranges from 0 to 23:59:59.999 (regardless of DST).  \n This field behaves exactly like a composite of all time-related fields, not including the zone fields. As such, it also reflects discontinuities in those fields on DST transition days. On a day of DST onset, it will jump forward. On a day of DST cessation, it will jump backward. This reflects the fact that it must be combined with the DST offset field to obtain a unique local time value */
    I18N_UCALENDAR_IS_LEAP_MONTH,                       /**< Whether or not the current month is a leap month (0 or 1) */
    I18N_UCALENDAR_FIELD_COUNT,                         /**< Field count  */
    I18N_UCALENDAR_DAY_OF_MONTH = I18N_UCALENDAR_DATE   /**< Field number indicating the day of the month.  \n This is a synonym for #I18N_UCALENDAR_DATE. The first day of the month has value 1 */
} i18n_ucalendar_date_fields_e;

/**
 * @brief Enumeration for possible months in an i18n_ucalendar_h. 
 */
typedef enum {
    I18N_UCALENDAR_TRADITIONAL,                             /**< Despite the name, #I18N_UCALENDAR_TRADITIONAL designates the locale's default calendar, which may be the Gregorian calendar or some other calendar */
    I18N_UCALENDAR_DEFAULT = I18N_UCALENDAR_TRADITIONAL,    /**< A better name for #I18N_UCALENDAR_TRADITIONAL  */
    I18N_UCALENDAR_GREGORIAN                                /**< Unambiguously designates the Gregorian calendar for the locale */
} i18n_ucalendar_type_e;

/**
 * @brief Enumeration for possible months in an i18n_ucalendar_h.
 */
typedef enum {
    I18N_UCALENDAR_JANUARY,         /**< January */
    I18N_UCALENDAR_FEBRUARY,        /**< February */
    I18N_UCALENDAR_MARCH,           /**< March */
    I18N_UCALENDAR_APRIL,           /**< April */
    I18N_UCALENDAR_MAY,             /**< May */
    I18N_UCALENDAR_JUNE,            /**< June */
    I18N_UCALENDAR_JULY,            /**< July */
    I18N_UCALENDAR_AUGUST,          /**< August */
    I18N_UCALENDAR_SEPTEMBER,       /**< September */
    I18N_UCALENDAR_OCTOBER,         /**< October */
    I18N_UCALENDAR_NOVEMBER,        /**< November */
    I18N_UCALENDAR_DECEMBER         /**< December */
} i18n_ucalendar_months_e;

/**
 * @brief Enumeration for possible formats of an i18n_ucalendar_h's display name.
 */
typedef enum {
    I18N_UCALENDAR_STANDARD,          /**< Standard display name */
    I18N_UCALENDAR_SHORT_STANDARD,    /**< Short standard display name */
    I18N_UCALENDAR_DST,               /**< Daylight savings display name */
    I18N_UCALENDAR_SHORT_DST          /**< Short daylight savings display name */
} i18n_ucalendar_displayname_type_e;

/**
 * @brief Enumeration for types of i18n_ucalendar_h attributes.
 */
typedef enum {
    I18N_UCALENDAR_LENIENT,                       /**< Lenient parsing */
    I18N_UCALENDAR_FIRST_DAY_OF_WEEK,             /**< First day of the week */
    I18N_UCALENDAR_MINIMAL_DAYS_IN_FIRST_WEEK     /**< Minimum number of days in the first week */
} i18n_ucalendar_attribute_e;

/**
 * @brief System time zone type constants.
 */
typedef enum {
    I18N_UCALENDAR_ZONE_TYPE_ANY,                   /**< Any system zones. */
    I18N_UCALENDAR_ZONE_TYPE_CANONICAL,             /**< Canonical system zones. */
    I18N_UCALENDAR_ZONE_TYPE_CANONICAL_LOCATION     /**< Canonical system zones associated with actual locations. */
} i18n_system_timezone_type_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UDATE_MODULE
 * @{
 */

/**
 * @brief Date and Time data type. \n
 * This is a primitive data type that holds the date and time
 * as the number of milliseconds since 1970-jan-01, 00:00 UTC. UTC leap seconds are ignored.
 */
typedef double i18n_udate;

typedef void* i18n_udate_format_h;


typedef struct {
    int32_t field;
    int32_t beginIndex;
    int32_t endIndex;
} i18n_ufield_position_s;

typedef i18n_ufield_position_s* i18n_ufield_position_h;

/**
 * @brief Enumeration for the possible date/time format styles.
 */
typedef enum {
    I18N_UDATE_FULL,                                                         /**< Full style */
    I18N_UDATE_LONG,                                                         /**< Long style */
    I18N_UDATE_MEDIUM,                                                       /**< Medium style */
    I18N_UDATE_SHORT,                                                        /**< Short style */
    I18N_UDATE_DEFAULT           = I18N_UDATE_MEDIUM,                        /**< Default style */
    I18N_UDATE_RELATIVE          = (1 << 7),                                 /**< Bitfield for relative date */
    I18N_UDATE_FULL_RELATIVE     = I18N_UDATE_FULL   | I18N_UDATE_RELATIVE,  /**< I18N_UDATE_FULL | I18N_UDATE_RELATIVE */
    I18N_UDATE_LONG_RELATIVE     = I18N_UDATE_LONG   | I18N_UDATE_RELATIVE,  /**< I18N_UDATE_LONG | I18N_UDATE_RELATIVE */ 
    I18N_UDATE_MEDIUM_RELATIVE   = I18N_UDATE_MEDIUM | I18N_UDATE_RELATIVE,  /**< I18N_UDATE_MEDIUM | I18N_UDATE_RELATIVE */
    I18N_UDATE_SHORT_RELATIVE    = I18N_UDATE_SHORT  | I18N_UDATE_RELATIVE,  /**< I18N_UDATE_SHORT | I18N_UDATE_RELATIVE */
    I18N_UDATE_NONE              = -1,                                       /**< No style */
    I18N_UDATE_PATTERN           = -2                                        /**< Use the pattern given in the parameter to #i18n_udate_create(). */
} i18n_udate_format_style_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UDATEPG_MODULE
 * @{
 */

typedef void* i18n_udatepg_h;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_UNUMBER_MODULE
 * @{
 */

typedef void* i18n_unumber_format_h;


enum { I18N_U_PARSE_CONTEXT_LEN = 16 };

typedef struct {
    int32_t        line;
    int32_t        offset;
    i18n_uchar          preContext[I18N_U_PARSE_CONTEXT_LEN];
    i18n_uchar          postContext[I18N_U_PARSE_CONTEXT_LEN];
} i18n_uparse_error_s;

/**
 * @brief Enumeration for the possible number format styles.
 */
typedef enum {
    I18N_UNUMBER_PATTERN_DECIMAL      = 0,  /**< Decimal format defined by a pattern string */
    I18N_UNUMBER_DECIMAL              = 1,  /**< Decimal format ("normal" style) */
    I18N_UNUMBER_CURRENCY,                  /**< Currency format with a currency symbol, e.g., "$1.00" */
    I18N_UNUMBER_PERCENT,                   /**< Percent format */
    I18N_UNUMBER_SCIENTIFIC,                /**< Scientific format */
    I18N_UNUMBER_SPELLOUT,                  /**< Spellout rule-based format */
    I18N_UNUMBER_ORDINAL,                   /**< Ordinal rule-based format */
    I18N_UNUMBER_DURATION,                  /**< Duration rule-based format */
    I18N_UNUMBER_NUMBERING_SYSTEM,          /**< Numbering system rule-based format */
    I18N_UNUMBER_PATTERN_RULEBASED,         /**< Rule-based format defined by a pattern string */
    I18N_UNUMBER_CURRENCY_ISO,              /**< Currency format with an ISO currency code, e.g., "USD1.00" */
    I18N_UNUMBER_CURRENCY_PLURAL,           /**< Currency format with a pluralized currency name, e.g., "1.00 US dollar" and "3.00 US dollars" */

    I18N_UNUMBER_FORMAT_STYLE_COUNT   = I18N_UNUMBER_CURRENCY_PLURAL + 2,   /**< One more than the highest number format style constant */
    I18N_UNUMBER_DEFAULT              = I18N_UNUMBER_DECIMAL,               /**< Default format */
    I18N_UNUMBER_IGNORE               = I18N_UNUMBER_PATTERN_DECIMAL        /**< Alias for #I18N_UNUMBER_PATTERN_DECIMAL */
 } i18n_unumber_format_style_e;

/**
 * @brief Enumeration of constants for specifying a number format symbol.
 */
typedef enum {
    I18N_UNUMBER_DECIMAL_SEPARATOR_SYMBOL            = 0,       /**< The decimal separator */
    I18N_UNUMBER_GROUPING_SEPARATOR_SYMBOL           = 1,       /**< The grouping separator */
    I18N_UNUMBER_PATTERN_SEPARATOR_SYMBOL            = 2,       /**< The pattern separator */
    I18N_UNUMBER_PERCENT_SYMBOL                      = 3,       /**< The percent sign */
    I18N_UNUMBER_ZERO_DIGIT_SYMBOL                   = 4,       /**< Zero */
    I18N_UNUMBER_DIGIT_SYMBOL                        = 5,       /**< Character representing a digit in the pattern.*/
    I18N_UNUMBER_MINUS_SIGN_SYMBOL                   = 6,       /**< The minus sign */
    I18N_UNUMBER_PLUS_SIGN_SYMBOL                    = 7,       /**< The plus sign */
    I18N_UNUMBER_CURRENCY_SYMBOL                     = 8,       /**< The currency symbol */
    I18N_UNUMBER_INTL_CURRENCY_SYMBOL                = 9,       /**< The international currency symbol */
    I18N_UNUMBER_MONETARY_SEPARATOR_SYMBOL           = 10,      /**< The monetary separator */
    I18N_UNUMBER_EXPONENTIAL_SYMBOL                  = 11,      /**< The exponential symbol */
    I18N_UNUMBER_PERMILL_SYMBOL                      = 12,      /**< Per mill symbol */
    I18N_UNUMBER_PAD_ESCAPE_SYMBOL                   = 13,      /**< Escape padding character */
    I18N_UNUMBER_INFINITY_SYMBOL                     = 14,      /**< Infinity symbol */
    I18N_UNUMBER_NAN_SYMBOL                          = 15,      /**< Nan symbol */
    I18N_UNUMBER_SIGNIFICANT_DIGIT_SYMBOL            = 16,      /**< Significant digit symbol */
    I18N_UNUMBER_MONETARY_GROUPING_SEPARATOR_SYMBOL  = 17,      /**< The monetary grouping separator */
    I18N_UNUMBER_ONE_DIGIT_SYMBOL                    = 18,      /**< One */
    I18N_UNUMBER_TWO_DIGIT_SYMBOL                    = 19,      /**< Two */
    I18N_UNUMBER_THREE_DIGIT_SYMBOL                  = 20,      /**< Three */
    I18N_UNUMBER_FOUR_DIGIT_SYMBOL                   = 21,      /**< Four */
    I18N_UNUMBER_FIVE_DIGIT_SYMBOL                   = 22,      /**< Five */
    I18N_UNUMBER_SIX_DIGIT_SYMBOL                    = 23,      /**< Six */
    I18N_UNUMBER_SEVEN_DIGIT_SYMBOL                  = 24,      /**< Seven */
    I18N_UNUMBER_EIGHT_DIGIT_SYMBOL                  = 25,      /**< Eight */
    I18N_UNUMBER_NINE_DIGIT_SYMBOL                   = 26,      /**< Nine */ 
    I18N_UNUMBER_FORMAT_SYMBOL_COUNT                 = 27       /**< count symbol constants  */ 
 } i18n_unumber_format_symbol_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_ULOCALE_MODULE
 * @{
 */

#define I18N_ULOCALE_CHINESE                   "zh"         /**< Useful constant for zh */
#define I18N_ULOCALE_ENGLISH                   "en"         /**< Useful constant for en */
#define I18N_ULOCALE_FRENCH                    "fr"         /**< Useful constant for fr */
#define I18N_ULOCALE_GERMAN                    "de"         /**< Useful constant for de */
#define I18N_ULOCALE_ITALIAN                   "it"         /**< Useful constant for it */
#define I18N_ULOCALE_JAPANESE                  "ja"         /**< Useful constant for ja */
#define I18N_ULOCALE_KOREAN                    "ko"         /**< Useful constant for ko */
#define I18N_ULOCALE_SIMPLIFIED_CHINESE        "zh_CN"      /**< Useful constant for zh_CN */
#define I18N_ULOCALE_TRADITIONAL_CHINESE       "zh_TW"      /**< Useful constant for zh_TW */
#define I18N_ULOCALE_CANADA                    "en_CA"      /**< Useful constant for en_CA */
#define I18N_ULOCALE_CANADA_FRENCH             "fr_CA"      /**< Useful constant for fr_CA */
#define I18N_ULOCALE_CHINA                     "zh_CN"      /**< Useful constant for zh_CN */
#define I18N_ULOCALE_PRC                       "zh_CN"      /**< Useful constant for zh_CN */
#define I18N_ULOCALE_FRANCE                    "fr_FR"      /**< Useful constant for fr_FR */
#define I18N_ULOCALE_GERMANY                   "de_DE"      /**< Useful constant for de_DE */
#define I18N_ULOCALE_ITALY                     "it_IT"      /**< Useful constant for it_IT */
#define I18N_ULOCALE_JAPAN                     "ja_JP"      /**< Useful constant for ja_JP */
#define I18N_ULOCALE_KOREA                     "ko_KR"      /**< Useful constant for ko_KR */
#define I18N_ULOCALE_TAIWAN                    "zh_TW"      /**< Useful constant for zh_TW */
#define I18N_ULOCALE_UK                        "en_GB"      /**< Useful constant for en_GB */
#define I18N_ULOCALE_US                        "en_US"      /**< Useful constant for en_US */

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_MODULE
 * @{
 */

typedef void* i18n_ubreak_iterator_s;

/**
 * @brief Enumeration for error codes to replace exception handlings.
 */
typedef enum {
    I18N_ERROR_NONE                         = TIZEN_ERROR_NONE,                   /**< No error, no warning */
    I18N_ERROR_MISSING_RESOURCE             = TIZEN_ERROR_UTILITY_ICU | 0x01,     /**< The requested resource cannot be found */
    I18N_ERROR_INVALID_FORMAT               = TIZEN_ERROR_UTILITY_ICU | 0x02,     /**< Data format is not what is expected */
    I18N_ERROR_FILE_ACCESS                  = TIZEN_ERROR_UTILITY_ICU | 0x03,     /**< The requested file cannot be found */
    I18N_ERROR_INTERNAL_PROGRAM             = TIZEN_ERROR_UTILITY_ICU | 0x04,     /**< Indicates a bug in the library code */
    I18N_ERROR_OUT_OF_MEMORY                = TIZEN_ERROR_OUT_OF_MEMORY,          /**< Out of memory */
    I18N_ERROR_INDEX_OUTOFBOUNDS            = TIZEN_ERROR_UTILITY_ICU | 0x05,     /**< Trying to access the index that is out of bounds */
    I18N_ERROR_INVALID_CHAR_FOUND           = TIZEN_ERROR_UTILITY_ICU | 0x06,     /**< Character conversion: Unmappable input sequence. In other APIs: Invalid character */
    I18N_ERROR_BUFFER_OVERFLOW              = TIZEN_ERROR_UTILITY_ICU | 0x07,     /**< A result would not fit in the supplied buffer */
    I18N_ERROR_NOT_SUPPORTED                = TIZEN_ERROR_NOT_SUPPORTED,          /**< Requested operation is not supported in the current context */
    I18N_ERROR_COLLATOR_VERSION_MISMATCH    = TIZEN_ERROR_UTILITY_ICU | 0x08,     /**< Collator version is not compatible with the base version */
    I18N_ERROR_USELESS_COLLATOR             = TIZEN_ERROR_UTILITY_ICU | 0x09,     /**< Collator is options only and no base is specified */
    I18N_ERROR_NO_WRITE_PERMISSION          = TIZEN_ERROR_UTILITY_ICU | 0x0A,     /**< Attempt to modify read-only or constant data */
    I18N_ERROR_RESOURCE_TYPE_MISMATCH       = TIZEN_ERROR_UTILITY_ICU | 0x0B,     /**< An operation is requested over a resource that does not support it */
    I18N_ERROR_TOO_MANY_ALIASES             = TIZEN_ERROR_UTILITY_ICU | 0x0C,     /**< Too many aliases in the path to the requested resource  */
    I18N_ERROR_INVALID_PARAMETER            = TIZEN_ERROR_INVALID_PARAMETER,      /**< Invalid function parameter */
    I18N_ERROR_PERMISSION_DENIED            = TIZEN_ERROR_PERMISSION_DENIED       /**< Permission denied */
} i18n_error_code_e;

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_USTRING_MODULE
 * @{
 */

/**
 * @brief Callback function for #i18n_ustring_unescape_at() that returns a character of the source text given an offset and a context pointer.\n
 *  The context pointer will be whatever is passed into #i18n_ustring_unescape_at().
 *
 * @param[in]   offset pointer to the offset that will be passed to #i18n_ustring_unescape_at().
 * @param[in]   context an opaque pointer passed directly into #i18n_ustring_unescape_at()
 *
 * @retval  character the character represented by the escape sequence at offset
 *
 * @see #i18n_ustring_unescape_at()
 */
typedef i18n_uchar(* i18n_ustring_unescape_char_at_cb)(int32_t offset, void *context);

/**
 * @brief Option value for case folding: use default mappings defined in CaseFolding.txt.
 */
#define I18N_USTRING_U_FOLD_CASE_DEFAULT 0

/**
 * @brief Option value for case folding: \n
 * Use the modified set of mappings provided in CaseFolding.txt to handle dotted I and dotless i appropriately for Turkic languages (tr, az).\n
 * Before Unicode 3.2, CaseFolding.txt contains mappings marked with 'I' that are to be included for default mappings and excluded for the Turkic-specific mappings.\n
 * Unicode 3.2 CaseFolding.txt instead contains mappings marked with 'T' that are to be excluded for default mappings and included for the Turkic-specific mappings.
 */
#define I18N_USTRING_U_FOLD_CASE_EXCLUDE_SPECIAL_I 1

/**
 * @brief Option bit #i18n_ustring_case_compare_with_length(), #i18n_ustring_case_compare(), etc: Compare strings in code point order instead of code unit order.
 */
#define I18N_USTRING_U_COMPARE_CODE_POINT_ORDER  0x8000

/**
 * @}
 * @}
 */

/**
 * @addtogroup CAPI_BASE_UTILS_I18N_TIMEZONE_MODULE
 * @{
 */
typedef	void* i18n_timezone_h;

/**
 * @brief Callback function for #i18n_timezone_foreach_timezone_id(), #i18n_timezone_foreach_timezone_id_with_offset(), and i18n_timezone_foreach_timezone_id_by_country()
 * that returns an enumeration over all recognized time zone IDs.
 *
 * @param[in] timezone_id time zone ID
 * @param[in] user_data The user data passed to the callback function.
 *
 * @return true to continue with the next iteration of the loop, otherwise false to break out of the loop.
 *
 * @see #i18n_ustring_unescape_at()
 */
typedef	bool (*i18n_timezone_id_cb)(const char *timezone_id, void* user_data);
typedef int8_t i18n_ubool;

/**
 * @brief Enumeration for use with #i18n_timezone_get_display_name, #i18n_timezone_get_display_name_with_locale, and #i18n_timezone_get_display_name_with_type.
 */
typedef enum {
    I18N_TIMEZONE_DISPLAY_TYPE_SHORT = 1,           /**< Selector for short display name */
    I18N_TIMEZONE_DISPLAY_TYPE_LONG,                /**< Selector for long display name */
    I18N_TIMEZONE_DISPLAY_TYPE_SHORT_GENERIC,       /**< Selector for short generic display name */
    I18N_TIMEZONE_DISPLAY_TYPE_LONG_GENERIC,        /**< Selector for long generic display name */
    I18N_TIMEZONE_DISPLAY_TYPE_SHORT_GMT,           /**< Selector for short display name derived */
    I18N_TIMEZONE_DISPLAY_TYPE_LONG_GMT,            /**< Selector for long display name derived from time zone offset */
    I18N_TIMEZONE_DISPLAY_TYPE_SHORT_COMMONLY_USED, /**< Selector for short display name derived from the time zone's fallback name */
    I18N_TIMEZONE_DISPLAY_TYPE_GENERIC_LOCATION     /**< Selector for long display name derived from the time zone's fallback name */
}i18n_timezone_display_type_e;

/**
 * @}
 * @}
 */


#ifdef __cplusplus
}
#endif

#endif	/* __UTILS_I18N_TYPES_H__*/