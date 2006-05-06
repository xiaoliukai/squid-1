#ifndef SQUID_FORWARD_H
#define SQUID_FORWARD_H

class FwdServer
{

public:
    peer *_peer;                /* NULL --> origin server */
    hier_code code;
    FwdServer *next;
};

class FwdState : public RefCountable
{

public:
    typedef RefCount<FwdState> Pointer;
    FwdState(int fd, StoreEntry *, HttpRequest *);
    ~FwdState();
    static void initModule();

    static FwdState * fwdStart(int fd, StoreEntry *, HttpRequest *);
    void startComplete(FwdServer *);
    void startFail();
    void fail(ErrorState *err);
    void unregister(int fd);
    void complete();
    int reforward();
    bool reforwardableStatus(http_status s);
    void serverClosed(int fd);
    void connectStart();
    void connectDone(int server_fd, comm_err_t status, int xerrno);
    void connectTimeout(int fd);
    void initiateSSL();
    void negotiateSSL(int fd);
    bool checkRetry();
    bool checkRetriable();
    void dispatch();
    void pconnPush(int fd, const char *host, int port, const char *domain);

    bool dontRetry() { return flags.dont_retry; }

    void dontRetry(bool val) { flags.dont_retry = val; }

    bool ftpPasvFailed() { return flags.ftp_pasv_failed; }

    void ftpPasvFailed(bool val) { flags.ftp_pasv_failed = val; }

    static void serversFree(FwdServer **);

private:
    static void logReplyStatus(int tries, http_status status);

#if WIP_FWD_LOG

    void uninit
    static void logRotate
    void status()
#endif

public:
    StoreEntry *entry;
    HttpRequest *request;
    int server_fd;
    FwdServer *servers;

private:
    CBDATA_CLASS2(FwdState);
    Pointer self;
    ErrorState *err;
    int client_fd;
    time_t start_t;
    int n_tries;
    int origin_tries;
#if WIP_FWD_LOG

    http_status last_status;
#endif

    struct
    {

unsigned int dont_retry:
        1;

unsigned int ftp_pasv_failed:
        1;
    }

    flags;

};

#endif
