#ifndef _SQUID_ERR_TYPE_H
#define _SQUID_ERR_TYPE_H

typedef enum {
    ERR_NONE,

/* Access Permission Errors.  Prefix new with ERR_ACCESS_ */
    ERR_ACCESS_DENIED,
    ERR_CACHE_ACCESS_DENIED,
    ERR_CACHE_MGR_ACCESS_DENIED,
    ERR_FORWARDING_DENIED,
    ERR_NO_RELAY,
    ERR_CANNOT_FORWARD,

/* TCP Errors. */
    ERR_READ_TIMEOUT,
    ERR_LIFETIME_EXP,
    ERR_READ_ERROR,
    ERR_WRITE_ERROR,
    ERR_CONNECT_FAIL,
    ERR_SECURE_CONNECT_FAIL,
    ERR_SOCKET_FAILURE,

/* DNS Errors */
    ERR_DNS_FAIL,
    ERR_URN_RESOLVE,

/* HTTP Errors */
    ERR_ONLY_IF_CACHED_MISS,    /* failure to satisfy only-if-cached request */
    ERR_TOO_BIG,
    ERR_INVALID_RESP,
    ERR_UNSUP_HTTPVERSION,     /* HTTP version is not supported */
    ERR_INVALID_REQ,
    ERR_UNSUP_REQ,
    ERR_INVALID_URL,
    ERR_ZERO_SIZE_OBJECT,

/* FTP Errors */
    ERR_FTP_DISABLED,
    ERR_FTP_UNAVAILABLE,
    ERR_FTP_FAILURE,
    ERR_FTP_PUT_ERROR,
    ERR_FTP_NOT_FOUND,
    ERR_FTP_FORBIDDEN,
    ERR_FTP_PUT_CREATED,        /* !error,a note that the file was created */
    ERR_FTP_PUT_MODIFIED,       /* modified, !created */

/* ESI Errors */
    ERR_ESI,                    /* Failure to perform ESI processing */

/* ICAP Errors */
    ERR_ICAP_FAILURE,

/* Special Cases */
    ERR_SQUID_SIGNATURE,        /* not really an error */
    ERR_SHUTTING_DOWN,
    TCP_RESET,

    ERR_MAX
} err_type;

extern const char *err_type_str[];

#endif /* _SQUID_ERR_TYPE_H */
