# version 5.300.4700.0 #75f1c5ae

# Unlocking by emulation of activation object. This methos is giving full version features.
```
00007FFCCD7CED98  | C645 01 00                      | mov byte ptr ss:[rbp+1],0                                     |
00007FFCCD7CED9C  | 48:8D0D C50AE7FE                | lea rcx,qword ptr ds:[7FFCCC63F868]                           |
00007FFCCD7CEDA3  | 4C:8D45 01                      | lea r8,qword ptr ss:[rbp+1]                                   |
00007FFCCD7CEDA7  | 48:8B50 18                      | mov rdx,qword ptr ds:[rax+18]                                 |
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
