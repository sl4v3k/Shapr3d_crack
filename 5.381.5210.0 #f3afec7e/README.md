# version 5.381.5210.0 #f3afec7e

Unlocking by emulation of activation object. This methos is giving full version features.
```
Shapr3D.dll
.text:0000000181910FB7
.text:0000000181910FB7                         loc_181910FB7:                          ; CODE XREF: sub_181910E90+117↑j
.text:0000000181910FB7 48 8B 4E 20                             mov     rcx, [rsi+20h]
.text:0000000181910FBB 48 8B 51 18                             mov     rdx, [rcx+18h]
.text:0000000181910FBF C6 45 01 00                             mov     [rbp+60h+var_5F], 0
.text:0000000181910FC3 48 8D 0D 16 43 BD FE                    lea     rcx, off_1804E52E0
.text:0000000181910FCA 4C 8D 45 01                             lea     r8, [rbp+60h+var_5F]
this call here is returning address of activation object,
quick solution is to just point to memory region that fits reqiurements in this case valid region is under rcx
so just replace call by mov rax,rcx (48 8B C1 90 90)
OFFSET IN FILE IS: 0x1910FCE (in case You use hex editor)
.text:0000000181910FCE E8 4D 2E 80 FF                          call    lic_call_181113E20 ; <--------- mov rax,rcx (48 8B C1 90 90)
.text:0000000181910FD3 48 8B D8                                mov     rbx, rax
.text:0000000181910FD6 48 8D 0D F3 55 72 FE                    lea     rcx, unk_1800365D0
.text:0000000181910FDD FF 15 DD FE 35 FF                       call    cs:RhpNewFast
.text:0000000181910FE3 48 8B F8                                mov     rdi, rax
.text:0000000181910FE6 48 8B C8                                mov     rcx, rax
.text:0000000181910FE9 FF 15 41 7A 35 FF                       call    qword ptr cs:byte_180C66001+2A2Fh
```



