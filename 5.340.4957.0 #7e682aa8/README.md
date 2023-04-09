# version 5.340.4957.0 #7e682aa8

Unlocking by emulation of activation object. This methos is giving full version features.
```
Shapr3D.dll
00007FFDA54CDE48   | 48:8B57 20                      | mov rdx,qword ptr ds:[rdi+20]                      |
00007FFDA54CDE4C   | 48:8B52 10                      | mov rdx,qword ptr ds:[rdx+10]                      |
00007FFDA54CDE50   | 48:8BCE                         | mov rcx,rsi                                        |
00007FFDA54CDE53   | E8 B8010000                     | call shapr3d.7FFDA54CE010                          |
00007FFDA54CDE58   | 48:8B47 20                      | mov rax,qword ptr ds:[rdi+20]                      |
00007FFDA54CDE5C   | C645 01 00                      | mov byte ptr ss:[rbp+1],0                          |
00007FFDA54CDE60   | 48:8D0D 11ECD2FE                | lea rcx,qword ptr ds:[7FFDA41FCA78]                |
00007FFDA54CDE67   | 4C:8D45 01                      | lea r8,qword ptr ss:[rbp+1]                        |
00007FFDA54CDE6B   | 48:8B50 18                      | mov rdx,qword ptr ds:[rax+18]                      |
this call here is returning address of activation object,
quick solution is to just point to memory region that fits reqiurements in this case valid region is under rcx
so just replace call by mov rax,rcx
Addres 00007FFDA54CDE6F comes from memory with ASLR so in dll file You should have it under 000000018175DE6F
00007FFDA54CDE6F   | E8 AC6B87FF                     | call shapr3d.7FFDA4D44A20 <- put here mov rax,rcx                         |
00007FFDA54CDE74   | 48:8BD0                         | mov rdx,rax                                        |
00007FFDA54CDE77   | 48:8BCE                         | mov rcx,rsi                                        |
00007FFDA54CDE7A   | E8 D1E2FFFF                     | call shapr3d.7FFDA54CC150                          |
00007FFDA54CDE7F   | 48:8B47 20                      | mov rax,qword ptr ds:[rdi+20]                      |
00007FFDA54CDE83   | 48:8B50 28                      | mov rdx,qword ptr ds:[rax+28]                      |
00007FFDA54CDE87   | 48:3956 40                      | cmp qword ptr ds:[rsi+40],rdx                      |
00007FFDA54CDE8B   | 74 08                           | je shapr3d.7FFDA54CDE95                            |
00007FFDA54CDE8D   | 48:8BCE                         | mov rcx,rsi                                        |
00007FFDA54CDE90   | E8 5BE0FFFF                     | call shapr3d.7FFDA54CBEF0                          |
00007FFDA54CDE95   | 48:8B47 20                      | mov rax,qword ptr ds:[rdi+20]                      |
00007FFDA54CDE99   | 0FB748 30                       | movzx ecx,word ptr ds:[rax+30]                     |
00007FFDA54CDE9D   | 66:894D 02                      | mov word ptr ss:[rbp+2],cx                         |
00007FFDA54CDEA1   | 48:8D4D 02                      | lea rcx,qword ptr ss:[rbp+2]                       |
00007FFDA54CDEA5   | FF15 C5AB41FF                   | call qword ptr ds:[7FFDA48E8A70]                   |
00007FFDA54CDEAB   | 84C0                            | test al,al                                         |
00007FFDA54CDEAD   | 74 15                           | je shapr3d.7FFDA54CDEC4                            |
00007FFDA54CDEAF   | 48:8D4D 02                      | lea rcx,qword ptr ss:[rbp+2]                       |
00007FFDA54CDEB3   | FF15 C7AB41FF                   | call qword ptr ds:[7FFDA48E8A80]                   |
```



