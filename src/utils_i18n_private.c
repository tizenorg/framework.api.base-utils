#include <utils_i18n_private.h>

int _i18n_error_mapping ( i18n_uerror_code_private_e err )
{
    switch(err){
        case I18N_U_ZERO_ERROR:
            return I18N_ERROR_NONE;
        case I18N_U_MISSING_RESOURCE_ERROR:
            return I18N_ERROR_MISSING_RESOURCE;
        case I18N_U_INVALID_FORMAT_ERROR:
            return I18N_ERROR_INVALID_FORMAT;
        case I18N_U_FILE_ACCESS_ERROR:
            return I18N_ERROR_FILE_ACCESS;
        case I18N_U_INTERNAL_PROGRAM_ERROR:
            return I18N_ERROR_INTERNAL_PROGRAM;
        case I18N_U_MEMORY_ALLOCATION_ERROR:
            return I18N_ERROR_OUT_OF_MEMORY;
        case I18N_U_INDEX_OUTOFBOUNDS_ERROR:
            return I18N_ERROR_INDEX_OUTOFBOUNDS;
        case I18N_U_INVALID_CHAR_FOUND:
            return I18N_ERROR_INVALID_CHAR_FOUND;
        case I18N_U_BUFFER_OVERFLOW_ERROR:
            return I18N_ERROR_BUFFER_OVERFLOW;
        case I18N_U_UNSUPPORTED_ERROR:
            return I18N_ERROR_NOT_SUPPORTED;
        case I18N_U_RESOURCE_TYPE_MISMATCH:
            return I18N_ERROR_RESOURCE_TYPE_MISMATCH;
        case I18N_U_TOO_MANY_ALIASES_ERROR:
            return I18N_ERROR_TOO_MANY_ALIASES;
        case I18N_U_COLLATOR_VERSION_MISMATCH:
            return I18N_ERROR_COLLATOR_VERSION_MISMATCH;
        case I18N_U_USELESS_COLLATOR_ERROR:
            return I18N_ERROR_USELESS_COLLATOR;
        case I18N_U_NO_WRITE_PERMISSION:
            return I18N_ERROR_NO_WRITE_PERMISSION;
        case I18N_U_ILLEGAL_ARGUMENT_ERROR:
            return I18N_ERROR_INVALID_PARAMETER;
        default:
            return I18N_ERROR_NONE;
    }
}
