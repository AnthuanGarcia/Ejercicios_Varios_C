#include<stdio.h>
#include<limits.h>

main()
{

    printf("Tamano minimo del char        = %d\n", SCHAR_MIN);
    printf("Tamano maximo del char        = %d\n", SCHAR_MAX);
    printf("Tamano minimo del short       = %d\n", SHRT_MIN);
    printf("Tamano maximo del short       = %d\n", SHRT_MAX);
    printf("Tamano minimo del int         = %d\n", INT_MIN);
    printf("Tamano maximo del int         = %d\n", INT_MAX);
    printf("Tamano minimo del long        = %d\n", LONG_MIN);
    printf("Tamano maximo del long        = %1d\n", LONG_MAX);

    printf("Unsigned char max             = %u\n", UCHAR_MAX);
    printf("Unsigned short max            = %u\n", USHRT_MAX);
    printf("Unsigned int max              = %u\n", UINT_MAX);
    printf("Unsigned long max             = %1u\n", ULLONG_MAX);

}