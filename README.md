# icx_m512_issue
It is a small test case to reproduce that, Intel ICX compiler not compatable to MSVC __m512i SIMD type.

reproduce steps:
1. In this project root:
```cmd
mkdir build
cd build
cmake .. -T "Intel C++ Compiler 2024"
```

2. Open the visual studio's .sln file, and then press "F7" to build. Error as below:
```
Build started...
1>------ Build started: Project: research_m512, Configuration: Debug x64 ------
1>Building Custom Rule D:/xuhan/ipex_cpu/icx_m512_issue/CMakeLists.txt
1>Intel(R) oneAPI DPC++/C++ Compiler for applications running on Intel(R) 64, Version 2024.0.2 Build 20231213
1>Copyright (C) 1985-2023 Intel Corporation. All rights reserved.
1>
1>icx-cl  /c /Qm64 /Zi /W3 /Od /Ob0 /D _MBCS /D WIN32 /D _WINDOWS /D CMAKE_INTDIR="Debug" /EHsc /RTC1 /MDd /GS /arch:AVX512 /Zc:forScope /GR /Zc:wchar_t /Foresearch_m512.dir\Debug\ /TP D:\xuhan\ipex_cpu\icx_m512_issue\csrc\research_m512.cpp
1>D:\xuhan\ipex_cpu\icx_m512_issue\csrc\research_m512.cpp(13,43): : error : member reference base type '__m512i' (vector of 8 'long long' values) is not a structure or union
1>   13 |     __m128i int_val0 = _mm_set_epi64x(vals.m512i_u64[1], vals.m512i_u64[0]);
1>      |                                       ~~~~^~~~~~~~~~
1>D:\xuhan\ipex_cpu\icx_m512_issue\csrc\research_m512.cpp(13,62): : error : member reference base type '__m512i' (vector of 8 'long long' values) is not a structure or union
1>   13 |     __m128i int_val0 = _mm_set_epi64x(vals.m512i_u64[1], vals.m512i_u64[0]);
1>      |                                                          ~~~~^~~~~~~~~~
1>D:\xuhan\ipex_cpu\icx_m512_issue\csrc\research_m512.cpp(14,43): : error : member reference base type '__m512i' (vector of 8 'long long' values) is not a structure or union
1>   14 |     __m128i int_val1 = _mm_set_epi64x(vals.m512i_u64[3], vals.m512i_u64[2]);
1>      |                                       ~~~~^~~~~~~~~~
1>D:\xuhan\ipex_cpu\icx_m512_issue\csrc\research_m512.cpp(14,62): : error : member reference base type '__m512i' (vector of 8 'long long' values) is not a structure or union
1>   14 |     __m128i int_val1 = _mm_set_epi64x(vals.m512i_u64[3], vals.m512i_u64[2]);
1>      |                                                          ~~~~^~~~~~~~~~
1>D:\xuhan\ipex_cpu\icx_m512_issue\csrc\research_m512.cpp(15,43): : error : member reference base type '__m512i' (vector of 8 'long long' values) is not a structure or union
1>   15 |     __m128i int_val2 = _mm_set_epi64x(vals.m512i_u64[5], vals.m512i_u64[4]);
1>      |                                       ~~~~^~~~~~~~~~
1>D:\xuhan\ipex_cpu\icx_m512_issue\csrc\research_m512.cpp(15,62): : error : member reference base type '__m512i' (vector of 8 'long long' values) is not a structure or union
1>   15 |     __m128i int_val2 = _mm_set_epi64x(vals.m512i_u64[5], vals.m512i_u64[4]);
1>      |                                                          ~~~~^~~~~~~~~~
1>D:\xuhan\ipex_cpu\icx_m512_issue\csrc\research_m512.cpp(16,43): : error : member reference base type '__m512i' (vector of 8 'long long' values) is not a structure or union
1>   16 |     __m128i int_val3 = _mm_set_epi64x(vals.m512i_u64[7], vals.m512i_u64[6]);
1>      |                                       ~~~~^~~~~~~~~~
1>D:\xuhan\ipex_cpu\icx_m512_issue\csrc\research_m512.cpp(16,62): : error : member reference base type '__m512i' (vector of 8 'long long' values) is not a structure or union
1>   16 |     __m128i int_val3 = _mm_set_epi64x(vals.m512i_u64[7], vals.m512i_u64[6]);
1>      |                                                          ~~~~^~~~~~~~~~
1>8 errors generated.
1>Done building project "research_m512.vcxproj" -- FAILED.
2>------ Skipped Build: Project: ALL_BUILD, Configuration: Debug x64 ------
2>Project not selected to build for this solution configuration 
========== Build: 0 succeeded, 1 failed, 1 up-to-date, 1 skipped ==========
```