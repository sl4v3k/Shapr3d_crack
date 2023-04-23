# version 5.352.5062.0 #c013d13c

Unlocking by emulation of activation object. This methos is giving full version features.
```
Shapr3D.dll
.text:00000001817787B8 48 8B 47 20                             mov     rax, [rdi+20h]
.text:00000001817787BC C6 45 01 00                             mov     byte ptr [rbp+1], 0
.text:00000001817787C0 48 8D 0D 51 00 D2 FE                    lea     rcx, off_180498818
.text:00000001817787C7 4C 8D 45 01                             lea     r8, [rbp+1]
.text:00000001817787CB 48 8B 50 18                             mov     rdx, [rax+18h]
this call here is returning address of activation object,
quick solution is to just point to memory region that fits reqiurements in this case valid region is under rcx
so just replace call by mov rax,rcx (48 8B C1 90 90)
.text:00000001817787CF E8 9C E6 86 FF                          call    sub_180FE6E70 <---------
.text:00000001817787D4 48 8B D0                                mov     rdx, rax
.text:00000001817787D7 48 8B CE                                mov     rcx, rsi
.text:00000001817787DA E8 71 E2 FF FF                          call    sub_181776A50
.text:00000001817787DF 48 8B 47 20                             mov     rax, [rdi+20h]
.text:00000001817787E3 48 8B 50 28                             mov     rdx, [rax+28h]
.text:00000001817787E7 48 39 56 40                             cmp     [rsi+40h], rdx
.text:00000001817787EB 74 08                                   jz      short loc_1817787F5
.text:00000001817787ED 48 8B CE                                mov     rcx, rsi
.text:00000001817787F0 E8 FB DF FF FF                          call    sub_1817767F0
```



