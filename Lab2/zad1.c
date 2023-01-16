#include<stdio.h>
#include<string.h>

const void* mymax(
    const void *base, size_t nmemb, size_t size,
    int (*compar)(const void *, const void *)) {

    const void *m = base;
    for (int i = 0; i < nmemb; i++) {
        if (compar((char*)base + i * size, m))
            m = (char*)base + i*size;
    }
    return m;
}

int gt_int(const void* first, const void* second) {
    if (*((int* ) first) > *((int* ) second)) 
        return 1;
    return 0;
}

int gt_char(const void* first, const void* second) {
    if (*((char* ) first) > *((char* ) second)) 
        return 1;
    return 0;
}

int gt_string(const void* first, const void* second) {
    if (strcmp(*((const char**) first), *((const char**) second)) >= 0)
        return 1;
    return 0;
}

int main() {
    int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
    char arr_char[]="Suncana strana ulice";
    const char* arr_str[] = {
        "Gle", "malu", "vocku", "poslije", "kise",
        "Puna", "je", "kapi", "pa", "ih", "njise"
    };

    int* max_int = (int*) mymax(arr_int, 9, sizeof(int), gt_int);
    char* max_char = (char*) mymax(arr_char, 20, sizeof(char), gt_char);
    const char** max_str = (const char**) mymax(arr_str, 11, sizeof(char*), gt_string);

    printf("Najveci integer: %d\n", *max_int);
    printf("Najveci char: %c\n", *max_char);
    printf("Najveci string: %s\n", *max_str);
}