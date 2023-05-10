# version 5.361.5107.0 #5d76db5d

Unlocking by emulation of activation object. This methos is giving full version features.
```
Shapr3D.dll
.text:000000018178C288 48 8B 47 20                             mov     rax, [rdi+20h]
.text:000000018178C28C C6 45 01 00                             mov     [rbp+70h+var_6F], 0
.text:000000018178C290 48 8D 0D E1 18 D1 FE                    lea     rcx, off_18049DB78
.text:000000018178C297 4C 8D 45 01                             lea     r8, [rbp+70h+var_6F]
.text:000000018178C29B 48 8B 50 18                             mov     rdx, [rax+18h]
this call here is returning address of activation object,
quick solution is to just point to memory region that fits reqiurements in this case valid region is under rcx
so just replace call by mov rax,rcx (48 8B C1 90 90)
OFFSET IN FILE IS: 0x178989F (in case You use hex editor)
.text:000000018178C29F E8 1C AE 86 FF                          call    sub_180FF70C0   <--------- mov rax,rcx (48 8B C1 90 90)
.text:000000018178C2A4 48 8B D0                                mov     rdx, rax
.text:000000018178C2A7 48 8B CE                                mov     rcx, rsi
.text:000000018178C2AA E8 71 E2 FF FF                          call    sub_18178A520
.text:000000018178C2AF 48 8B 47 20                             mov     rax, [rdi+20h]
.text:000000018178C2B3 48 8B 50 28                             mov     rdx, [rax+28h]
.text:000000018178C2B7 48 39 56 40                             cmp     [rsi+40h], rdx
.text:000000018178C2BB 74 08                                   jz      short loc_18178C2C5
.text:000000018178C2BD 48 8B CE                                mov     rcx, rsi
.text:000000018178C2C0 E8 FB DF FF FF                          call    sub_18178A2C0
```



