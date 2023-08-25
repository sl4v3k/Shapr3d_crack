# version 5.440.5599.0 #bf8b6c74

Unlocking by emulation of activation object. This method is giving full version features.
```
Shapr3D.dll
.text:0000000181AF65C2 0F 84 DF 00 00 00                       jz      loc_181AF66A7
.text:0000000181AF65C8 45 32 FF                                xor     r15b, r15b
.text:0000000181AF65CB 41 0F B7 46 30                          movzx   eax, word ptr [r14+30h]
.text:0000000181AF65D0 66 89 45 01                             mov     [rbp+90h+var_8F], ax
.text:0000000181AF65D4 48 8D 4D 01                             lea     rcx, [rbp+90h+var_8F]
.text:0000000181AF65D8 FF 15 22 05 25 FF                       call    qword ptr cs:byte_180D45001+1AFFh
.text:0000000181AF65DE 84 C0                                   test    al, al
.text:0000000181AF65E0 74 0E                                   jz      short loc_181AF65F0
.text:0000000181AF65E2 48 8D 4D 01                             lea     rcx, [rbp+90h+var_8F]
.text:0000000181AF65E6 FF 15 24 05 25 FF                       call    qword ptr cs:byte_180D45001+1B0Fh
.text:0000000181AF65EC 44 0F B6 F8                             movzx   r15d, al
.text:0000000181AF65F0
.text:0000000181AF65F0                         loc_181AF65F0:                          ; CODE XREF: sub_181AF6500+E0↑j
.text:0000000181AF65F0 C6 45 00 00                             mov     [rbp+90h+var_90], 0
.text:0000000181AF65F4 48 8D 0D D5 4E A4 FE                    lea     rcx, off_18053B4D0
.text:0000000181AF65FB 4C 8D 45 00                             lea     r8, [rbp+90h+var_90]
.text:0000000181AF65FF 49 8B 56 18                             mov     rdx, [r14+18h]
this call here is returning address of activation object,
quick solution is to just point to memory region that fits reqiurements in this case valid region is under rcx
so just replace call by mov rax,rcx (48 8B C1 90 90)
OFFSET IN DLL FILE IS: 0x1AF3603 (in case You use hex editor)
.text:0000000181AF6603 E8 78 86 75 FF                          call    lic_call_18124EC80 <--------- mov rax,rcx (48 8B C1 90 90)
.text:0000000181AF6608 48 8B D8                                mov     rbx, rax
.text:0000000181AF660B 48 8B 8D A0 00 00 00                    mov     rcx, [rbp+90h+arg_0]
.text:0000000181AF6612 48 8B 71 20                             mov     rsi, [rcx+20h]
.text:0000000181AF6616 48 8D 0D D3 49 54 FE                    lea     rcx, unk_18003AFF0
.text:0000000181AF661D FF 15 15 9A 25 FF                       call    cs:RhpNewFast
.text:0000000181AF6623 48 8B F8                                mov     rdi, rax
.text:0000000181AF6626 4D 8B 46 10                             mov     r8, [r14+10h]
.text:0000000181AF662A 49 8B 56 08                             mov     rdx, [r14+8]
.text:0000000181AF662E 48 8B C8                                mov     rcx, rax
.text:0000000181AF6631 E8 2A 24 73 FF                          call    sub_181228A60
.text:0000000181AF6636 48 8D 4F 18                             lea     rcx, [rdi+18h]
.text:0000000181A
```



