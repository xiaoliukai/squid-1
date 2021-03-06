/*
 * Copyright (C) 1996-2015 The Squid Software Foundation and contributors
 *
 * Squid software is distributed under GPLv2+ license and includes
 * contributions from numerous individuals and organizations.
 * Please see the COPYING and CONTRIBUTORS files for details.
 */

/* DEBUG: section 13    High Level Memory Pool Management */

#ifndef _SQUID_SRC_MEM_FORWARD_H
#define _SQUID_SRC_MEM_FORWARD_H

#include "mem/AllocatorProxy.h"
/* for FREE */
#include "typedefs.h"

#include <iosfwd>

class StoreEntry;
class MemPoolStats;
class MemPoolMeter;

namespace Mem
{
void Init();
void Report();
void Stats(StoreEntry *);
void CleanIdlePools(void *unused);
void Report(std::ostream &);
void PoolReport(const MemPoolStats * mp_st, const MemPoolMeter * AllMeter, std::ostream &);
};

extern const size_t squidSystemPageSize;

/// Types of memory pool which do not yet use MEMPROXY_CLASS() API
typedef enum {
    MEM_NONE,
    MEM_2K_BUF,
    MEM_4K_BUF,
    MEM_8K_BUF,
    MEM_16K_BUF,
    MEM_32K_BUF,
    MEM_64K_BUF,
    MEM_ACL_DENY_INFO_LIST,
    MEM_ACL_NAME_LIST,
#if USE_CACHE_DIGESTS
    MEM_CACHE_DIGEST,
#endif
    MEM_CLIENT_INFO,
    MEM_LINK_LIST,
    MEM_DLINK_NODE,
    MEM_DREAD_CTRL,
    MEM_DWRITE_Q,
    MEM_HTTP_HDR_CONTENT_RANGE,
    MEM_MD5_DIGEST,
    MEM_NETDBENTRY,
    MEM_NET_DB_NAME,
    MEM_RELIST,
    // IMPORTANT: leave this here. pools above are initialized early with memInit()
    MEM_DONTFREE,
    // following pools are initialized late by their component if needed (or never)
    MEM_FQDNCACHE_ENTRY,
    MEM_FWD_SERVER,
    MEM_IDNS_QUERY,
    MEM_IPCACHE_ENTRY,
    MEM_MAX
} mem_type;

void memClean(void);
void memInitModule(void);
void memCleanModule(void);
void memConfigure(void);
void *memAllocate(mem_type);
void *memAllocString(size_t net_size, size_t * gross_size);
void *memAllocBuf(size_t net_size, size_t * gross_size);
void *memReallocBuf(void *buf, size_t net_size, size_t * gross_size);
void memFree(void *, int type);
void memFreeString(size_t size, void *);
void memFreeBuf(size_t size, void *);
FREE *memFreeBufFunc(size_t size);
int memInUse(mem_type);
void memDataInit(mem_type, const char *, size_t, int, bool doZero = true);
void memCheckInit(void);

#endif /* _SQUID_SRC_MEM_FORWARD_H */

