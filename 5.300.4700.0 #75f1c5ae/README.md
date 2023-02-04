# version 5.300.4700.0 #75f1c5ae

Unlocking by emulation of activation object. This methos is giving full version features.
```
00007FFCCD7CED98  | C645 01 00                      | mov byte ptr ss:[rbp+1],0                                     |
00007FFCCD7CED9C  | 48:8D0D C50AE7FE                | lea rcx,qword ptr ds:[7FFCCC63F868]                           |
00007FFCCD7CEDA3  | 4C:8D45 01                      | lea r8,qword ptr ss:[rbp+1]                                   |
00007FFCCD7CEDA7  | 48:8B50 18                      | mov rdx,qword ptr ds:[rax+18]
this call here is returning address of activation object,
quick solution is to just point to memory region that fits reqiurements in this case valid region is under rcx
so just replace call by mov rax,rcx
00007FFCCD7CEDAB  | E8 3031B9FF                     | call shapr3d.7FFCCD361EE0  <- put here mov rax,rcx            | ustalanie adresu obiektu rejestracji
00007FFCCD7CEDB0  | 48:8BD0                         | mov rdx,rax                                                   |
00007FFCCD7CEDB3  | 48:8BCE                         | mov rcx,rsi                                                   |
00007FFCCD7CEDB6  | E8 25E1FFFF                     | call shapr3d.7FFCCD7CCEE0                                     |
00007FFCCD7CEDBB  | 48:8B47 20                      | mov rax,qword ptr ds:[rdi+20]                                 |
00007FFCCD7CEDBF  | 48:8B50 28                      | mov rdx,qword ptr ds:[rax+28]                                 |
00007FFCCD7CEDC3  | 48:3956 50                      | cmp qword ptr ds:[rsi+50],rdx                                 |
00007FFCCD7CEDC7  | 74 08                           | je shapr3d.7FFCCD7CEDD1                                       |
00007FFCCD7CEDC9  | 48:8BCE                         | mov rcx,rsi                                                   |
00007FFCCD7CEDCC  | E8 AFDEFFFF                     | call shapr3d.7FFCCD7CCC80                                     |
00007FFCCD7CEDD1  | 48:8B47 20                      | mov rax,qword ptr ds:[rdi+20]                                 |
```


Above patch is enought to run all features without limitations. But if You want to play more with Shapr3d executable try below patches.

1. Increase number of possible designs including imports:
```
00007FFCCD7D4F50  | 48:83EC 38               | sub rsp,38                                             |
00007FFCCD7D4F54  | 48:C74424 20 00000000    | mov qword ptr ss:[rsp+20],0                            |
00007FFCCD7D4F5D  | BA 02000000              | mov edx,2        <--- trial gives 2 just put number You wish|
00007FFCCD7D4F62  | 48:8D4C24 20             | lea rcx,qword ptr ss:[rsp+20]                          |
00007FFCCD7D4F67  | FF15 C3F94EFF            | call qword ptr ds:[7FFCCCCC4930]                       |
00007FFCCD7D4F6D  | 48:8B4424 20             | mov rax,qword ptr ss:[rsp+20]                          |
00007FFCCD7D4F72  | 48:83C4 38               | add rsp,38                                             |
00007FFCCD7D4F76  | C3                       | ret                                                    |
```

2. Unlock couple other things like exporting
```
serch for pattern: 41 FF 12 84 C0 74 09 C6 45
There should be couple places, this is actually piece of code:
00007FFCCD7E61AA  | 41:FF12                         | call qword ptr ds:[r10]                                       |
00007FFCCD7E61AD  | 84C0                            | test al,al                                                    |
00007FFCCD7E61AF  | 74 09                           | je shapr3d.7FFCCD7E61BA                                       | EXPORT IGL

change je to jne
```