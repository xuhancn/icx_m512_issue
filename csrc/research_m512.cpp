#include <immintrin.h>

int main()
{
    __m512i vals;

    /*
    Issue: ICX not support __m512i as union, but msvc support it.
    */
    #if defined(_MSC_VER)
    __m128i int_val0 = _mm_set_epi64x(vals.m512i_u64[1], vals.m512i_u64[0]);
    __m128i int_val1 = _mm_set_epi64x(vals.m512i_u64[3], vals.m512i_u64[2]);
    __m128i int_val2 = _mm_set_epi64x(vals.m512i_u64[5], vals.m512i_u64[4]);
    __m128i int_val3 = _mm_set_epi64x(vals.m512i_u64[7], vals.m512i_u64[6]);
    #else
    __m128i int_val0 = _mm_set_epi64x(vals[1], vals[0]);
    __m128i int_val1 = _mm_set_epi64x(vals[3], vals[2]);
    __m128i int_val2 = _mm_set_epi64x(vals[5], vals[4]);
    __m128i int_val3 = _mm_set_epi64x(vals[7], vals[6]);
    #endif

    // WA: exclude scope by __clang__
    #if defined(_MSC_VER) && !defined(__clang__)
    int_val0 = _mm_set_epi64x(vals.m512i_u64[1], vals.m512i_u64[0]);
    int_val1 = _mm_set_epi64x(vals.m512i_u64[3], vals.m512i_u64[2]);
    int_val2 = _mm_set_epi64x(vals.m512i_u64[5], vals.m512i_u64[4]);
    int_val3 = _mm_set_epi64x(vals.m512i_u64[7], vals.m512i_u64[6]);
    #else
    int_val0 = _mm_set_epi64x(vals[1], vals[0]);
    int_val1 = _mm_set_epi64x(vals[3], vals[2]);
    int_val2 = _mm_set_epi64x(vals[5], vals[4]);
    int_val3 = _mm_set_epi64x(vals[7], vals[6]);
    #endif

    return 0;
}