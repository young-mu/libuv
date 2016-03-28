#include <stdio.h>
#include <uv.h>

int main()
{
    printf("%s\n", uv_version_string());
    return 0;
}
