/*************************************************************************
	> File Name: heart2.c
	> Author: likang
	> Mail:  
	> Created Time: 2014年12月12日 星期五 00时07分23秒
 ************************************************************************/

#include <stdio.h>

int main() {
    for (float y = 1.5f; y > -1.5f; y -= 0.1f) {
        for (float x = -1.5f; x < 1.5f; x += 0.05f) {
            float z = x * x + y * y - 1;
            float f = z * z * z - x * x * y * y * y;
            putchar(f <= 0.0f ? ".:-=+*#%@"[(int)(f * -8.0f)] : ' ');
        }
        putchar('\n');
    }
}
