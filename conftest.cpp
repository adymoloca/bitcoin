/* confdefs.h */
#define PACKAGE_NAME "Bitcoin Core"
#define PACKAGE_TARNAME "bitcoin"
#define PACKAGE_VERSION "22.99.0"
#define PACKAGE_STRING "Bitcoin Core 22.99.0"
#define PACKAGE_BUGREPORT "https://github.com/bitcoin/bitcoin/issues"
#define PACKAGE_URL "https://bitcoincore.org/"
#define HAVE_CXX17 1
#define STDC_HEADERS 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STRINGS_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_UNISTD_H 1
#define HAVE_DLFCN_H 1
#define LT_OBJDIR ".libs/"
#define USE_ASM 1
#define ENABLE_SSE41 1
#define ENABLE_AVX2 1
#define ENABLE_SHANI 1
#define HAVE___INT128 1
#define HAVE_PTHREAD_PRIO_INHERIT 1
#define HAVE_PTHREAD 1
#define HAVE_DECL_STRERROR_R 1
#define HAVE_STRERROR_R 1
#define STRERROR_R_CHAR_P 1
#define HAVE_ENDIAN_H 1
#define HAVE_BYTESWAP_H 1
#define HAVE_STDIO_H 1
#define HAVE_STDLIB_H 1
#define HAVE_UNISTD_H 1
#define HAVE_STRINGS_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_SYS_SELECT_H 1
#define HAVE_SYS_PRCTL_H 1
#define HAVE_SYS_SYSCTL_H 1
#define HAVE_DECL_GETIFADDRS 1
#define HAVE_DECL_FREEIFADDRS 1
#define HAVE_DECL_STRNLEN 1
#define HAVE_DECL_FORK 1
#define HAVE_DECL_SETSID 1
#define HAVE_DECL_PIPE2 1
#define HAVE_DECL_LE16TOH 1
#define HAVE_DECL_LE32TOH 1
#define HAVE_DECL_LE64TOH 1
#define HAVE_DECL_HTOLE16 1
#define HAVE_DECL_HTOLE32 1
#define HAVE_DECL_HTOLE64 1
#define HAVE_DECL_BE16TOH 1
#define HAVE_DECL_BE32TOH 1
#define HAVE_DECL_BE64TOH 1
#define HAVE_DECL_HTOBE16 1
#define HAVE_DECL_HTOBE32 1
#define HAVE_DECL_HTOBE64 1
#define HAVE_DECL_BSWAP_16 1
#define HAVE_DECL_BSWAP_32 1
#define HAVE_DECL_BSWAP_64 1
#define HAVE_BUILTIN_CLZL 1
#define HAVE_BUILTIN_CLZLL 1
#define HAVE_MALLOC_INFO 1
#define HAVE_MALLOPT_ARENA_MAX 1
#define HAVE_POSIX_FALLOCATE 1
#define HAVE_DEFAULT_VISIBILITY_ATTRIBUTE 1
/* end confdefs.h.  */

    #include <thread>
    static thread_local int foo = 0;
    static void run_thread() { foo++;}
    int main(){
    for(int i = 0; i < 10; i++) { std::thread(run_thread).detach();}
    return foo;
    }

