# version 5.510.6062.0 #xxxxxxxx

Unlocking by emulation of activation object. This method is giving full version features.
```
Shapr3D.dll
.text:0000000181B31585 4D 85 FF                                test    r15, r15
.text:0000000181B31588 0F 84 E0 00 00 00                       jz      loc_181B3166E
.text:0000000181B3158E 45 32 E4                                xor     r12b, r12b
.text:0000000181B31591 41 0F B7 47 30                          movzx   eax, word ptr [r15+30h]
.text:0000000181B31596 66 89 45 01                             mov     [rbp+0A0h+var_9F], ax
.text:0000000181B3159A 48 8D 4D 01                             lea     rcx, [rbp+0A0h+var_9F]
.text:0000000181B3159E FF 15 44 D5 28 FF                       call    qword ptr cs:byte_180DBD001+1AE7h
.text:0000000181B315A4 84 C0                                   test    al, al
.text:0000000181B315A6 74 0E                                   jz      short loc_181B315B6
.text:0000000181B315A8 48 8D 4D 01                             lea     rcx, [rbp+0A0h+var_9F]
.text:0000000181B315AC FF 15 46 D5 28 FF                       call    qword ptr cs:byte_180DBD001+1AF7h
.text:0000000181B315B2 44 0F B6 E0                             movzx   r12d, al
.text:0000000181B315B6
.text:0000000181B315B6                         loc_181B315B6:                          ; CODE XREF: sub_181B314C0+E6↑j
.text:0000000181B315B6 C6 45 00 00                             mov     [rbp+0A0h+var_A0], 0
.text:0000000181B315BA 48 8D 0D A7 DD A3 FE                    lea     rcx, off_18056F368
.text:0000000181B315C1 4C 8D 45 00                             lea     r8, [rbp+0A0h+var_A0]
.text:0000000181B315C5 49 8B 57 18                             mov     rdx, [r15+18h]
this call here is returning address of activation object,
quick solution is to just point to memory region that fits reqiurements in this case valid region is under rcx
so just replace call by mov rax,rcx (48 8B C1 90 90)
OFFSET IN DLL FILE IS: 0x1B2E9C9 (in case You use hex editor)
.text:0000000181B315C9 E8 A2 D2 79 FF                          call    lic_call_1812CE870 <--------- mov rax,rcx (48 8B C1 90 90)
.text:0000000181B315CE 48 8B F8                                mov     rdi, rax
.text:0000000181B315D1 48 8B 8D B0 00 00 00                    mov     rcx, [rbp+0A0h+arg_0]
.text:0000000181B315D8 4C 8B 71 20                             mov     r14, [rcx+20h]
.text:0000000181B315DC 48 8D 0D C5 62 50 FE                    lea     rcx, unk_1800378A8
.text:0000000181B315E3 FF 15 97 69 29 FF                       call    cs:RhpNewFast
.text:0000000181B315E9 48 8B F0                                mov     rsi, rax
.text:0000000181B315EC 4D 8B 47 10                             mov     r8, [r15+10h]
.text:0000000181B315F0 49 8B 57 08                             mov     rdx, [r15+8]
.text:0000000181B315F4 48 8B C8                                mov     rcx, rax
.text:0000000181B315F7 E8 E4 D3 FF FF                          call    sub_181B2E9E0
.text:0000000181B315FC 48 8D 4E 18                             lea     rcx, [rsi+18h]
.text:0000000181B31600 48 8B D7                                mov     rdx, rdi
.text:0000000181B31603 FF 15 97 69 29 FF                       call    cs:RhpAssignRefEDX
.text:0000000181B31609 48 8D 4E 20                             lea     rcx, [rsi+20h]
.text:0000000181B3160D 49 8B 57 28                             mov     rdx, [r15+28h]
.text:0000000181B31611 FF 15 89 69 29 FF                       call    cs:RhpAssignRefEDX
.text:0000000181B31617 44 88 66 28                             mov     [rsi+28h], r12b
.text:0000000181B3161B 48 8D 4E 30                             lea     rcx, [rsi+30h]
.text:0000000181B3161F 49 8B 57 38                             mov     rdx, [r15+38h]

```

Unlocking by emulation of activation object. This method is giving full version features.
```
Shapr3D.dll
.text:0000000181B49241 4C 8B 7D 20                             mov     r15, [rbp+0A0h+var_80]
.text:0000000181B49245 4D 85 FF                                test    r15, r15
.text:0000000181B49248 0F 84 E0 00 00 00                       jz      loc_181B4932E
.text:0000000181B4924E 45 32 E4                                xor     r12b, r12b
.text:0000000181B49251 41 0F B7 47 30                          movzx   eax, word ptr [r15+30h]
.text:0000000181B49256 66 89 45 01                             mov     [rbp+0A0h+var_9F], ax
.text:0000000181B4925A 48 8D 4D 01                             lea     rcx, [rbp+0A0h+var_9F]
.text:0000000181B4925E FF 15 BC 08 28 FF                       call    qword ptr cs:byte_180DC8001+1B1Fh
.text:0000000181B49264 84 C0                                   test    al, al
.text:0000000181B49266 74 0E                                   jz      short loc_181B49276
.text:0000000181B49268 48 8D 4D 01                             lea     rcx, [rbp+0A0h+var_9F]
.text:0000000181B4926C FF 15 BE 08 28 FF                       call    qword ptr cs:byte_180DC8001+1B2Fh
.text:0000000181B49272 44 0F B6 E0                             movzx   r12d, al
.text:0000000181B49276
.text:0000000181B49276                         loc_181B49276:                          ; CODE XREF: sub_181B49180+E6↑j
.text:0000000181B49276 C6 45 00 00                             mov     [rbp+0A0h+var_A0], 0
.text:0000000181B4927A 48 8D 0D 2F A4 A2 FE                    lea     rcx, off_1805736B0
.text:0000000181B49281 4C 8D 45 00                             lea     r8, [rbp+0A0h+var_A0]
.text:0000000181B49285 49 8B 57 18                             mov     rdx, [r15+18h]
this call here is returning address of activation object,
quick solution is to just point to memory region that fits reqiurements in this case valid region is under rcx
so just replace call by mov rax,rcx (48 8B C1 90 90)
OFFSET IN DLL FILE IS: 0x1B47489 (in case You use hex editor)
.text:0000000181B49289 E8 22 FD 78 FF                          call    lic_call_1812D8FB0 <--------- mov rax,rcx (48 8B C1 90 90)
.text:0000000181B4928E 48 8B F8                                mov     rdi, rax
.text:0000000181B49291 48 8B 8D B0 00 00 00                    mov     rcx, [rbp+0A0h+arg_0]
.text:0000000181B49298 4C 8B 71 20                             mov     r14, [rcx+20h]
.text:0000000181B4929C 48 8D 0D ED E8 4E FE                    lea     rcx, unk_180037B90
.text:0000000181B492A3 FF 15 17 9D 28 FF                       call    cs:RhpNewFast
.text:0000000181B492A9 48 8B F0                                mov     rsi, rax
.text:0000000181B492AC 4D 8B 47 10                             mov     r8, [r15+10h]
.text:0000000181B492B0 49 8B 57 08                             mov     rdx, [r15+8]
.text:0000000181B492B4 48 8B C8                                mov     rcx, rax
.text:0000000181B492B7 E8 D4 D3 FF FF                          call    sub_181B46690
.text:0000000181B492BC 48 8D 4E 18                             lea     rcx, [rsi+18h]
.text:0000000181B492C0 48 8B D7                                mov     rdx, rdi
.text:0000000181B492C3 FF 15 17 9D 28 FF                       call    cs:RhpAssignRefEDX
.text:0000000181B492C9 48 8D 4E 20                             lea     rcx, [rsi+20h]
.text:0000000181B492CD 49 8B 57 28                             mov     rdx, [r15+28h]
.text:0000000181B492D1 FF 15 09 9D 28 FF                       call    cs:RhpAssignRefEDX
.text:0000000181B492D7 44 88 66 28                             mov     [rsi+28h], r12b
.text:0000000181B492DB 48 8D 4E 30                             lea     rcx, [rsi+30h]
.text:0000000181B492DF 49 8B 57 38                             mov     rdx, [r15+38h]
```


