# version 5.521.6217.0 #30c67d09

Unlocking by emulation of activation object. This method is giving full version features.
But this time is bit different than in previous versions. I mean the code looks different.
```
Shapr3D.dll
.text:0000000181B40F0D FF 15 A5 40 28 FF                       call    qword ptr cs:byte_180DC0001+4FB7h
.text:0000000181B40F13 48 8B 45 08                             mov     rax, [rbp+70h+var_68]
.text:0000000181B40F17 48 8B 48 48                             mov     rcx, [rax+48h]
.text:0000000181B40F1B 48 89 4D 10                             mov     [rbp+70h+var_60], rcx
.text:0000000181B40F1F 48 8B 5D 10                             mov     rbx, [rbp+70h+var_60]
.text:0000000181B40F23 48 85 DB                                test    rbx, rbx
.text:0000000181B40F26 75 08                                   jnz     short loc_181B40F30
.text:0000000181B40F28 88 5D 00                                mov     [rbp+70h+var_70], bl
.text:0000000181B40F2B E9 F4 00 00 00                          jmp     loc_181B41024
.text:0000000181B40F30                         ; ---------------------------------------------------------------------------
.text:0000000181B40F30
.text:0000000181B40F30                         loc_181B40F30:                          ; CODE XREF: sub_181B40E20+106↑j
.text:0000000181B40F30 C6 45 03 00                             mov     [rbp+70h+var_6D], 0
.text:0000000181B40F34 48 8D 0D 7D 92 A2 FE                    lea     rcx, off_18056A1B8
.text:0000000181B40F3B 4C 8D 45 03                             lea     r8, [rbp+70h+var_6D]
.text:0000000181B40F3F 48 8B 53 18                             mov     rdx, [rbx+18h]
this call here is returning address of activation object,
quick solution is to just point to memory region that fits reqiurements in this case valid region is under rcx
so just replace call by mov rax,rcx (48 8B C1 90 90)
OFFSET IN DLL FILE IS: 0x1B3d743(in case You use hex editor)
.text:0000000181B40F43 E8 88 F5 78 FF                          call    lic_call_1812D04D0 <--------- mov rax,rcx (48 8B C1 90 90)
.text:0000000181B40F48 4C 8B F8                                mov     r15, rax
.text:0000000181B40F4B 4C 8B 63 08                             mov     r12, [rbx+8]
.text:0000000181B40F4F 48 8B 4B 10                             mov     rcx, [rbx+10h]
.text:0000000181B40F53 FF 15 77 11 28 FF                       call    qword ptr cs:byte_180DC0001+20CFh
.text:0000000181B40F59 84 C0                                   test    al, al
.text:0000000181B40F5B 75 06                                   jnz     short loc_181B40F63
.text:0000000181B40F5D 48 8B 7B 10                             mov     rdi, [rbx+10h]
.text:0000000181B40F61 EB 02                                   jmp     short loc_181B40F65
.text:0000000181B40F63                         ; ---------------------------------------------------------------------------
.text:0000000181B40F63
.text:0000000181B40F63                         loc_181B40F63:                          ; CODE XREF: sub_181B40E20+13B↑j
.text:0000000181B40F63 33 FF                                   xor     edi, edi
.text:0000000181B40F65
.text:0000000181B40F65                         loc_181B40F65:                          ; CODE XREF: sub_181B40E20+141↑j
.text:0000000181B40F65 0F B7 43 30                             movzx   eax, word ptr [rbx+30h]
.text:0000000181B40F69 66 89 45 01                             mov     [rbp+70h+var_6F], ax
.text:0000000181B40F6D 48 8D 4D 01                             lea     rcx, [rbp+70h+var_6F]
.text:0000000181B40F71 FF 15 81 0B 28 FF                       call    qword ptr cs:byte_180DC0001+1AF7h
.text:0000000181B40F77 0F B6 C8                                movzx   ecx, al
.text:0000000181B40F7A E8 F1 6B FF FF                          call    sub_181B37B70
.text:0000000181B40F7F 48 8B 85 80 00 00 00                    mov     rax, [rbp+70h+arg_0]
.text:0000000181B40F86 4C 8B 70 18                             mov     r14, [rax+18h]
.text:0000000181B40F8A 48 8D 0D 57 E4 5A FE                    lea     rcx, unk_1800EF3E8
.text:0000000181B40F91 FF 15 41 9F 28 FF                       call    cs:RhpNewFast
.text:0000000181B40F97 48 8B F0                                mov     rsi, rax
.text:0000000181B40F9A 4C 8B C7                                mov     r8, rdi
.text:0000000181B40F9D 49 8B D4                                mov     rdx, r12
.text:0000000181B40FA0 48 8B C8                                mov     rcx, rax
.text:0000000181B40FA3 E8 68 D2 D8 FF                          call    sub_1818CE210
.text:0000000181B40FA8 48 8D 4E 18                             lea     rcx, [rsi+18h]
.text:0000000181B40FAC 49 8B D7                                mov     rdx, r15
.text:0000000181B
```
