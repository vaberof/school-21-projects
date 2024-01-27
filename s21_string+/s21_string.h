#ifndef S21_STRING_H
#define S21_STRING_H

#endif /* S21_STRING_H */

#ifndef NULL
#define NULL ((void *)0)

#endif /* NULL */

#ifndef SIZE_TYPE
#define SIZE_TYPE unsigned long int

typedef SIZE_TYPE size_t;

#endif /* SIZE_TYPE */

#include <stdlib.h>
typedef struct error {
  int value;
  char *const msg;
} ERROR;

#ifdef __APPLE__
#ifndef err_arr
#define err_arr                                                                \
  {                                                                            \
    "Undefined error: 0", "Operation not permitted",                           \
        "No such file or directory", "No such process",                        \
        "Interrupted system call", "Input/output error",                       \
        "Device not configured", "Argument list too long",                     \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource deadlock avoided", "Cannot allocate memory",                 \
        "Permission denied", "Bad address", "Block device required",           \
        "Resource busy", "File exists", "Cross-device link",                   \
        "Operation not supported by device", "Not a directory",                \
        "Is a directory", "Invalid argument", "Too many open files in system", \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain", "Result too large", \
        "Resource temporarily unavailable", "Operation now in progress",       \
        "Operation already in progress", "Socket operation on non-socket",     \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol family",                     \
        "Address already in use", "Can't assign requested address",            \
        "Network is down", "Network is unreachable",                           \
        "Network dropped connection on reset",                                 \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available", "Socket is already connected",            \
        "Socket is not connected", "Can't send after socket shutdown",         \
        "Too many references: can't splice", "Operation timed out",            \
        "Connection refused", "Too many levels of symbolic links",             \
        "File name too long", "Host is down", "No route to host",              \
        "Directory not empty", "Too many processes", "Too many users",         \
        "Disc quota exceeded", "Stale NFS file handle",                        \
        "Too many levels of remote in path", "RPC struct is bad",              \
        "RPC version wrong", "RPC prog. not avail", "Program version wrong",   \
        "Bad procedure for program", "No locks available",                     \
        "Function not implemented", "Inappropriate file type or format",       \
        "Authentication error", "Need authenticator", "Device power is off",   \
        "Device error", "Value too large to be stored in data type",           \
        "Bad executable (or shared library)", "Bad CPU type in executable",    \
        "Shared library version mismatch", "Malformed Mach-o file",            \
        "Operation canceled", "Identifier removed",                            \
        "No message of desired type", "Illegal byte sequence",                 \
        "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",          \
        "No message available on STREAM", "ENOLINK (Reserved)",                \
        "No STREAM resources", "Not a STREAM", "Protocol error",               \
        "STREAM ioctl timeout", "Operation not supported on socket",           \
        "Policy not found", "State not recoverable", "Previous owner died",    \
        "Interface output queue is full"                                       \
  }
#endif
#elif __linux__
#ifndef err_arr
#define err_arr                                                                \
  {                                                                            \
    "Success", "Operation not permitted", "No such file or directory",         \
        "No such process", "Interrupted system call", "Input/output error",    \
        "No such device or address", "Argument list too long",                 \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource temporarily unavailable", "Cannot allocate memory",          \
        "Permission denied", "Bad address", "Block device required",           \
        "Device or resource busy", "File exists", "Invalid cross-device link", \
        "No such device", "Not a directory", "Is a directory",                 \
        "Invalid argument", "Too many open files in system",                   \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain",                     \
        "Numerical result out of range", "Resource deadlock avoided",          \
        "File name too long", "No locks available",                            \
        "Function not implemented", "Directory not empty",                     \
        "Too many levels of symbolic links", "Unknown error 41",               \
        "No message of desired type", "Identifier removed",                    \
        "Channel number out of range", "Level 2 not synchronized",             \
        "Level 3 halted", "Level 3 reset", "Link number out of range",         \
        "Protocol driver not attached", "No CSI structure available",          \
        "Level 2 halted", "Invalid exchange", "Invalid request descriptor",    \
        "Exchange full", "No anode", "Invalid request code", "Invalid slot",   \
        "Unknown error 58", "Bad font file format", "Device not a stream",     \
        "No data available", "Timer expired", "Out of streams resources",      \
        "Machine is not on the network", "Package not installed",              \
        "Object is remote", "Link has been severed", "Advertise error",        \
        "Srmount error", "Communication error on send", "Protocol error",      \
        "Multihop attempted", "RFS specific error", "Bad message",             \
        "Value too large for defined data type", "Name not unique on network", \
        "File descriptor in bad state", "Remote address changed",              \
        "Can not access a needed shared library",                              \
        "Accessing a corrupted shared library",                                \
        ".lib section in a.out corrupted",                                     \
        "Attempting to link in too many shared libraries",                     \
        "Cannot exec a shared library directly",                               \
        "Invalid or incomplete multibyte or wide character",                   \
        "Interrupted system call should be restarted", "Streams pipe error",   \
        "Too many users", "Socket operation on non-socket",                    \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol", "Address already in use",  \
        "Cannot assign requested address", "Network is down",                  \
        "Network is unreachable", "Network dropped connection on reset",       \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available",                                           \
        "Transport endpoint is already connected",                             \
        "Transport endpoint is not connected",                                 \
        "Cannot send after transport endpoint shutdown",                       \
        "Too many references: cannot splice", "Connection timed out",          \
        "Connection refused", "Host is down", "No route to host",              \
        "Operation already in progress", "Operation now in progress",          \
        "Stale file handle", "Structure needs cleaning",                       \
        "Not a XENIX named type file", "No XENIX semaphores available",        \
        "Is a named type file", "Remote I/O error", "Disk quota exceeded",     \
        "No medium found", "Wrong medium type", "Operation canceled",          \
        "Required key not available", "Key has expired",                       \
        "Key has been revoked", "Key was rejected by service", "Owner died",   \
        "State not recoverable", "Operation not possible due to RF-kill",      \
        "Memory page has hardware error"                                       \
  }
#endif
#else
#error "Unsupported operating system"
#endif

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(void *dest, const void *src, size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_sprintf(char *str, const char *format, ...);

/* sprintf types */
#ifndef STDARG_H
#include <stdarg.h>

#endif /* STDARG_H */

#ifndef STDBOOL_H
#include <stdbool.h>

#endif /* STDBOOL_H */

typedef struct flags {
  bool minus;
  bool plus;
  bool space;
  bool sharp;
  bool zero;
} flags_t;

typedef struct precision {
  int value;
  bool has_precision;
} precision_t;

typedef struct lengths {
  bool h;
  bool l;
  bool L;
} lengths_t;

enum Flag {
  kFlagMinus = '-',
  kFlagPlus = '+',
  kFlagSpace = ' ',
  kFlagSharp = '#',
  kFlagZero = '0',
};

enum Length {
  kLengthShortIntShortUint = 'h',
  kLengthLongIntLongUint = 'l',
  kLengthLongDouble = 'L',
};

enum Specifier {
  kSpecifierChar = 'c',
  kSpecifierInt = 'd',
  kSpecifierFloat = 'f',
  kSpecifierString = 's',
  kSpecifierUint = 'u',
  kSpecifierPercent = '%',
  kSpecifierLowerHex = 'x',
  kSpecifierUpperHex = 'X',
  kSpecifierOctal = 'o',
  kSpecifierPtrAddress = 'p',
};

int s21_sprintf(char *str, const char *format, ...);

/* FORMAT PARSING FUNCS */
void s21_sprintf_parse_format(char **buf, const char **format, va_list *args,
                              int *width, precision_t *precision,
                              flags_t *flags, lengths_t *lengths);
void s21_sprintf_parse_flags(const char **format, flags_t *flags);
void s21_sprintf_process_flag(char flag, flags_t *flags);
void s21_sprintf_parse_width(const char **format, va_list *args, int *width);
void s21_sprintf_parse_precision(const char **format, va_list *args,
                                 precision_t *precision);
void s21_sprintf_parse_length(const char **format, lengths_t *lengths);
void s21_sprintf_process_length(char length, lengths_t *lengths);
void s21_sprintf_parse_specifier(const char **format, char *specifier);

char *s21_sprintf_parse_number(const char **format);
void s21_reset_format_parameters(int *width, flags_t *flags,
                                 precision_t *precision, lengths_t *lengths);

/* BUFFER PROCESSING FUNCS */
void s21_sprintf_proccess_buf(char **buf, flags_t *flags, int *width,
                              precision_t *precision, lengths_t *lengths,
                              char specifier, va_list *args);

void s21_process_char_specifier(char **buf, int *width, flags_t *flags,
                                va_list *args);
void s21_process_int_specifier(char **buf, int *width, flags_t *flags,
                               precision_t *precision, lengths_t *lengths,
                               va_list *args);
void s21_process_double_specifier(char **buf, int *width, flags_t *flags,
                                  precision_t *precision, lengths_t *lengths,
                                  va_list *args);
void s21_process_string_specifier(char **buf, int *width, flags_t *flags,
                                  precision_t *precision, va_list *args);
void s21_process_uint_specifier(char **buf, int *width, flags_t *flags,
                                precision_t *precision, lengths_t *lengths,
                                va_list *args);
void s21_process_percent_specifier(char **buf);
void s21_process_hex_specifier(char **buf, bool is_lower_case, int *width,
                               flags_t *flags, precision_t *precision,
                               lengths_t *lengths, va_list *args);
void s21_process_octal_specifier(char **buf, int *width, flags_t *flags,
                                 precision_t *precision, lengths_t *lengths,
                                 va_list *args);

void s21_process_ptr_specifier(char **buf, int *width, flags_t *flags,
                               va_list *args);
void s21_output_char_specifier_to_buf(char **buf, char c, flags_t *flags,
                                      int *width);
void s21_output_int_specifier_to_buf(char **buf, long int number,
                                     flags_t *flags, int width,
                                     precision_t *precision,
                                     lengths_t *lengths);
void s21_output_double_specifier_to_buf(char **buf, long double number,
                                        flags_t *flags, int width,
                                        precision_t *precision);
void s21_output_string_specifier_to_buf(char **buf, char *string,
                                        flags_t *flags, int width,
                                        precision_t *precisio);
void s21_output_uint_specifier_to_buf(char **buf, unsigned long number,
                                      flags_t *flags, int width,
                                      precision_t *precision,
                                      lengths_t *lengths);
void s21_output_percent_pecifier_to_buf(char **buf);
void s21_output_hex_specifier_to_buf(char **buf, bool is_lower_case,
                                     long number, flags_t *flags, int width,
                                     precision_t *precision,
                                     lengths_t *lengths);
void s21_output_octal_specifier_to_buf(char **buf, long number, flags_t *flags,
                                       int width, precision_t *precision,
                                       lengths_t *lengths);

void s21_output_ptr_specifier_to_buf(char **buf, unsigned long int ptr,
                                     flags_t *flags, int *width);

void s21_output_sign_to_buf(char **buf, char *str_number, flags_t *flags);
void s21_output_leading_zeros_to_buf(char **buf, int leading_zeros_count);
void s21_output_width_to_buf(char **buf, int width, flags_t *flags);

void s21_output_hex_prefix_to_buf(char **buf, char *str_number,
                                  bool is_lower_case, flags_t *flags);
void s21_output_octal_prefix_to_buf(char **buf, char *str_number,
                                    flags_t *flags, precision_t *precision);
void s21_output_hex_ptr_prefix_to_buf(char **buf);

void s21_process_output_str_number_to_buf(char **buf, char *str_number,
                                          int leading_zeros_count, int width,
                                          flags_t *flags);

void s21_process_output_hex_number_to_buf(char **buf, char *str_number,
                                          bool is_lower_case,
                                          int leading_zeros_count, int width,
                                          flags_t *flags);
void s21_process_output_octal_number_to_buf(char **buf, char *str_number,
                                            int leading_zeros_count, int width,
                                            flags_t *flags,
                                            precision_t *precision);

void s21_output_str_number_to_buf(char **buf, char *str);

void s21_output_str_to_buf(char **buf, char *str);

void s21_output_int_no_character_to_buf(char **buf, long number, flags_t *flags,
                                        int width);
void s21_output_uint_no_character_to_buf(char **buf, unsigned long number,
                                         flags_t *flags, int width);
void s21_output_base8_int_no_character_to_buf(char **buf, flags_t *flags,
                                              precision_t *precision,
                                              int width);
void s21_output_base16_int_no_character_to_buf(char **buf, flags_t *flags,
                                               int width);

bool s21_must_not_output_int_to_buf(long number, precision_t *precision);
bool s21_must_not_output_uint_to_buf(unsigned long number,
                                     precision_t *precision);

int s21_get_leading_zeros_count(precision_t *precision, char *str_number);
char *s21_strcpy(char *destination, const char *source);