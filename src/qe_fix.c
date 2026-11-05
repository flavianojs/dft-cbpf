/* Fix for the Ubuntu 24.04 quantum-espresso 6.7 package (used by Google Colab).

   pw.x stops at startup with "*** buffer overflow detected ***". The cause is a
   false alarm of _FORTIFY_SOURCE: QE writes the MD5 checksum of the pseudopotential
   with snprintf, declaring a larger buffer than the real one, and the checked
   snprintf aborts even though nothing is written out of bounds.

   This replacement writes at most as many bytes as the buffer really has
   (truncating instead of aborting). Build and load it in every program with:

     gcc -O2 -shared -fPIC -o /usr/local/lib/qe_fix.so qe_fix.c
     echo /usr/local/lib/qe_fix.so > /etc/ld.so.preload
*/
#include <stdio.h>
#include <stdarg.h>

int __snprintf_chk(char *s, size_t maxlen, int flag, size_t slen, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int r = vsnprintf(s, maxlen < slen ? maxlen : slen, fmt, ap);
    va_end(ap);
    return r;
}
