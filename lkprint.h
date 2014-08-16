/*************************************************************************
	> File Name: lkprint.h
	> Author: likang
	> Created Time: 2014年08月16日 星期六 22时29分14秒
 ************************************************************************/

#include<stdarg.h>

int
lkprint(char *format,...)
{
	va_list ap;
	va_start (ap, format);
	int n;
	n = vprintf(format, ap);
	va_end(ap);
	return n;
}
