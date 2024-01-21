
farm:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 a2 2f 00 00    	push   0x2fa2(%rip)        # 3fc8 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 a3 2f 00 00 	bnd jmp *0x2fa3(%rip)        # 3fd0 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)

Disassembly of section .plt.got:

0000000000001030 <__cxa_finalize@plt>:
    1030:	f3 0f 1e fa          	endbr64 
    1034:	f2 ff 25 bd 2f 00 00 	bnd jmp *0x2fbd(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    103b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001040 <_start>:
    1040:	f3 0f 1e fa          	endbr64 
    1044:	31 ed                	xor    %ebp,%ebp
    1046:	49 89 d1             	mov    %rdx,%r9
    1049:	5e                   	pop    %rsi
    104a:	48 89 e2             	mov    %rsp,%rdx
    104d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1051:	50                   	push   %rax
    1052:	54                   	push   %rsp
    1053:	45 31 c0             	xor    %r8d,%r8d
    1056:	31 c9                	xor    %ecx,%ecx
    1058:	48 8d 3d 52 04 00 00 	lea    0x452(%rip),%rdi        # 14b1 <main>
    105f:	ff 15 73 2f 00 00    	call   *0x2f73(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    1065:	f4                   	hlt    
    1066:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    106d:	00 00 00 

0000000000001070 <deregister_tm_clones>:
    1070:	48 8d 3d 99 2f 00 00 	lea    0x2f99(%rip),%rdi        # 4010 <__TMC_END__>
    1077:	48 8d 05 92 2f 00 00 	lea    0x2f92(%rip),%rax        # 4010 <__TMC_END__>
    107e:	48 39 f8             	cmp    %rdi,%rax
    1081:	74 15                	je     1098 <deregister_tm_clones+0x28>
    1083:	48 8b 05 56 2f 00 00 	mov    0x2f56(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    108a:	48 85 c0             	test   %rax,%rax
    108d:	74 09                	je     1098 <deregister_tm_clones+0x28>
    108f:	ff e0                	jmp    *%rax
    1091:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1098:	c3                   	ret    
    1099:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010a0 <register_tm_clones>:
    10a0:	48 8d 3d 69 2f 00 00 	lea    0x2f69(%rip),%rdi        # 4010 <__TMC_END__>
    10a7:	48 8d 35 62 2f 00 00 	lea    0x2f62(%rip),%rsi        # 4010 <__TMC_END__>
    10ae:	48 29 fe             	sub    %rdi,%rsi
    10b1:	48 89 f0             	mov    %rsi,%rax
    10b4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10b8:	48 c1 f8 03          	sar    $0x3,%rax
    10bc:	48 01 c6             	add    %rax,%rsi
    10bf:	48 d1 fe             	sar    %rsi
    10c2:	74 14                	je     10d8 <register_tm_clones+0x38>
    10c4:	48 8b 05 25 2f 00 00 	mov    0x2f25(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    10cb:	48 85 c0             	test   %rax,%rax
    10ce:	74 08                	je     10d8 <register_tm_clones+0x38>
    10d0:	ff e0                	jmp    *%rax
    10d2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10d8:	c3                   	ret    
    10d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010e0 <__do_global_dtors_aux>:
    10e0:	f3 0f 1e fa          	endbr64 
    10e4:	80 3d 25 2f 00 00 00 	cmpb   $0x0,0x2f25(%rip)        # 4010 <__TMC_END__>
    10eb:	75 2b                	jne    1118 <__do_global_dtors_aux+0x38>
    10ed:	55                   	push   %rbp
    10ee:	48 83 3d 02 2f 00 00 	cmpq   $0x0,0x2f02(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    10f5:	00 
    10f6:	48 89 e5             	mov    %rsp,%rbp
    10f9:	74 0c                	je     1107 <__do_global_dtors_aux+0x27>
    10fb:	48 8b 3d 06 2f 00 00 	mov    0x2f06(%rip),%rdi        # 4008 <__dso_handle>
    1102:	e8 29 ff ff ff       	call   1030 <__cxa_finalize@plt>
    1107:	e8 64 ff ff ff       	call   1070 <deregister_tm_clones>
    110c:	c6 05 fd 2e 00 00 01 	movb   $0x1,0x2efd(%rip)        # 4010 <__TMC_END__>
    1113:	5d                   	pop    %rbp
    1114:	c3                   	ret    
    1115:	0f 1f 00             	nopl   (%rax)
    1118:	c3                   	ret    
    1119:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001120 <frame_dummy>:
    1120:	f3 0f 1e fa          	endbr64 
    1124:	e9 77 ff ff ff       	jmp    10a0 <register_tm_clones>

0000000000001129 <start_farm>:
    1129:	f3 0f 1e fa          	endbr64 
    112d:	55                   	push   %rbp
    112e:	48 89 e5             	mov    %rsp,%rbp
    1131:	b8 01 00 00 00       	mov    $0x1,%eax
    1136:	5d                   	pop    %rbp
    1137:	c3                   	ret    

0000000000001138 <getval_142>:
    1138:	f3 0f 1e fa          	endbr64 
    113c:	55                   	push   %rbp
    113d:	48 89 e5             	mov    %rsp,%rbp
    1140:	b8 fb 78 90 90       	mov    $0x909078fb,%eax
    1145:	5d                   	pop    %rbp
    1146:	c3                   	ret    

0000000000001147 <addval_273>:
    1147:	f3 0f 1e fa          	endbr64 
    114b:	55                   	push   %rbp
    114c:	48 89 e5             	mov    %rsp,%rbp
    114f:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1152:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1155:	2d b8 76 38 3c       	sub    $0x3c3876b8,%eax
    115a:	5d                   	pop    %rbp
    115b:	c3                   	ret    

000000000000115c <addval_219>:
    115c:	f3 0f 1e fa          	endbr64 
    1160:	55                   	push   %rbp
    1161:	48 89 e5             	mov    %rsp,%rbp
    1164:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1167:	8b 45 fc             	mov    -0x4(%rbp),%eax
    116a:	2d af 8c a7 6f       	sub    $0x6fa78caf,%eax
    116f:	5d                   	pop    %rbp
    1170:	c3                   	ret    

0000000000001171 <setval_237>:
    1171:	f3 0f 1e fa          	endbr64 
    1175:	55                   	push   %rbp
    1176:	48 89 e5             	mov    %rsp,%rbp
    1179:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    117d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1181:	c7 00 48 89 c7 c7    	movl   $0xc7c78948,(%rax)
    1187:	90                   	nop
    1188:	5d                   	pop    %rbp
    1189:	c3                   	ret    

000000000000118a <setval_424>:
    118a:	f3 0f 1e fa          	endbr64 
    118e:	55                   	push   %rbp
    118f:	48 89 e5             	mov    %rsp,%rbp
    1192:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1196:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    119a:	c7 00 54 c2 58 92    	movl   $0x9258c254,(%rax)
    11a0:	90                   	nop
    11a1:	5d                   	pop    %rbp
    11a2:	c3                   	ret    

00000000000011a3 <setval_470>:
    11a3:	f3 0f 1e fa          	endbr64 
    11a7:	55                   	push   %rbp
    11a8:	48 89 e5             	mov    %rsp,%rbp
    11ab:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    11af:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    11b3:	c7 00 63 48 8d c7    	movl   $0xc78d4863,(%rax)
    11b9:	90                   	nop
    11ba:	5d                   	pop    %rbp
    11bb:	c3                   	ret    

00000000000011bc <setval_426>:
    11bc:	f3 0f 1e fa          	endbr64 
    11c0:	55                   	push   %rbp
    11c1:	48 89 e5             	mov    %rsp,%rbp
    11c4:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    11c8:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    11cc:	c7 00 48 89 c7 90    	movl   $0x90c78948,(%rax)
    11d2:	90                   	nop
    11d3:	5d                   	pop    %rbp
    11d4:	c3                   	ret    

00000000000011d5 <getval_280>:
    11d5:	f3 0f 1e fa          	endbr64 
    11d9:	55                   	push   %rbp
    11da:	48 89 e5             	mov    %rsp,%rbp
    11dd:	b8 29 58 90 c3       	mov    $0xc3905829,%eax
    11e2:	5d                   	pop    %rbp
    11e3:	c3                   	ret    

00000000000011e4 <mid_farm>:
    11e4:	f3 0f 1e fa          	endbr64 
    11e8:	55                   	push   %rbp
    11e9:	48 89 e5             	mov    %rsp,%rbp
    11ec:	b8 01 00 00 00       	mov    $0x1,%eax
    11f1:	5d                   	pop    %rbp
    11f2:	c3                   	ret    

00000000000011f3 <add_xy>:
    11f3:	f3 0f 1e fa          	endbr64 
    11f7:	55                   	push   %rbp
    11f8:	48 89 e5             	mov    %rsp,%rbp
    11fb:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    11ff:	48 89 75 f0          	mov    %rsi,-0x10(%rbp)
    1203:	48 8b 55 f8          	mov    -0x8(%rbp),%rdx
    1207:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
    120b:	48 01 d0             	add    %rdx,%rax
    120e:	5d                   	pop    %rbp
    120f:	c3                   	ret    

0000000000001210 <getval_481>:
    1210:	f3 0f 1e fa          	endbr64 
    1214:	55                   	push   %rbp
    1215:	48 89 e5             	mov    %rsp,%rbp
    1218:	b8 5c 89 c2 90       	mov    $0x90c2895c,%eax
    121d:	5d                   	pop    %rbp
    121e:	c3                   	ret    

000000000000121f <setval_296>:
    121f:	f3 0f 1e fa          	endbr64 
    1223:	55                   	push   %rbp
    1224:	48 89 e5             	mov    %rsp,%rbp
    1227:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    122b:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    122f:	c7 00 99 d1 90 90    	movl   $0x9090d199,(%rax)
    1235:	90                   	nop
    1236:	5d                   	pop    %rbp
    1237:	c3                   	ret    

0000000000001238 <addval_113>:
    1238:	f3 0f 1e fa          	endbr64 
    123c:	55                   	push   %rbp
    123d:	48 89 e5             	mov    %rsp,%rbp
    1240:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1243:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1246:	2d 77 31 87 36       	sub    $0x36873177,%eax
    124b:	5d                   	pop    %rbp
    124c:	c3                   	ret    

000000000000124d <addval_490>:
    124d:	f3 0f 1e fa          	endbr64 
    1251:	55                   	push   %rbp
    1252:	48 89 e5             	mov    %rsp,%rbp
    1255:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1258:	8b 45 fc             	mov    -0x4(%rbp),%eax
    125b:	2d 73 2e df 24       	sub    $0x24df2e73,%eax
    1260:	5d                   	pop    %rbp
    1261:	c3                   	ret    

0000000000001262 <getval_226>:
    1262:	f3 0f 1e fa          	endbr64 
    1266:	55                   	push   %rbp
    1267:	48 89 e5             	mov    %rsp,%rbp
    126a:	b8 89 d1 48 c0       	mov    $0xc048d189,%eax
    126f:	5d                   	pop    %rbp
    1270:	c3                   	ret    

0000000000001271 <setval_384>:
    1271:	f3 0f 1e fa          	endbr64 
    1275:	55                   	push   %rbp
    1276:	48 89 e5             	mov    %rsp,%rbp
    1279:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    127d:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1281:	c7 00 81 d1 84 c0    	movl   $0xc084d181,(%rax)
    1287:	90                   	nop
    1288:	5d                   	pop    %rbp
    1289:	c3                   	ret    

000000000000128a <addval_190>:
    128a:	f3 0f 1e fa          	endbr64 
    128e:	55                   	push   %rbp
    128f:	48 89 e5             	mov    %rsp,%rbp
    1292:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1295:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1298:	2d bf b7 76 1f       	sub    $0x1f76b7bf,%eax
    129d:	5d                   	pop    %rbp
    129e:	c3                   	ret    

000000000000129f <setval_276>:
    129f:	f3 0f 1e fa          	endbr64 
    12a3:	55                   	push   %rbp
    12a4:	48 89 e5             	mov    %rsp,%rbp
    12a7:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    12ab:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    12af:	c7 00 88 c2 08 c9    	movl   $0xc908c288,(%rax)
    12b5:	90                   	nop
    12b6:	5d                   	pop    %rbp
    12b7:	c3                   	ret    

00000000000012b8 <addval_436>:
    12b8:	f3 0f 1e fa          	endbr64 
    12bc:	55                   	push   %rbp
    12bd:	48 89 e5             	mov    %rsp,%rbp
    12c0:	89 7d fc             	mov    %edi,-0x4(%rbp)
    12c3:	8b 45 fc             	mov    -0x4(%rbp),%eax
    12c6:	2d 77 31 6f 6f       	sub    $0x6f6f3177,%eax
    12cb:	5d                   	pop    %rbp
    12cc:	c3                   	ret    

00000000000012cd <getval_345>:
    12cd:	f3 0f 1e fa          	endbr64 
    12d1:	55                   	push   %rbp
    12d2:	48 89 e5             	mov    %rsp,%rbp
    12d5:	b8 48 89 e0 c1       	mov    $0xc1e08948,%eax
    12da:	5d                   	pop    %rbp
    12db:	c3                   	ret    

00000000000012dc <addval_479>:
    12dc:	f3 0f 1e fa          	endbr64 
    12e0:	55                   	push   %rbp
    12e1:	48 89 e5             	mov    %rsp,%rbp
    12e4:	89 7d fc             	mov    %edi,-0x4(%rbp)
    12e7:	8b 45 fc             	mov    -0x4(%rbp),%eax
    12ea:	2d 77 3d ff 36       	sub    $0x36ff3d77,%eax
    12ef:	5d                   	pop    %rbp
    12f0:	c3                   	ret    

00000000000012f1 <addval_187>:
    12f1:	f3 0f 1e fa          	endbr64 
    12f5:	55                   	push   %rbp
    12f6:	48 89 e5             	mov    %rsp,%rbp
    12f9:	89 7d fc             	mov    %edi,-0x4(%rbp)
    12fc:	8b 45 fc             	mov    -0x4(%rbp),%eax
    12ff:	2d 77 31 c7 3f       	sub    $0x3fc73177,%eax
    1304:	5d                   	pop    %rbp
    1305:	c3                   	ret    

0000000000001306 <setval_248>:
    1306:	f3 0f 1e fa          	endbr64 
    130a:	55                   	push   %rbp
    130b:	48 89 e5             	mov    %rsp,%rbp
    130e:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1312:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1316:	c7 00 81 ce 08 db    	movl   $0xdb08ce81,(%rax)
    131c:	90                   	nop
    131d:	5d                   	pop    %rbp
    131e:	c3                   	ret    

000000000000131f <getval_159>:
    131f:	f3 0f 1e fa          	endbr64 
    1323:	55                   	push   %rbp
    1324:	48 89 e5             	mov    %rsp,%rbp
    1327:	b8 89 d1 38 c9       	mov    $0xc938d189,%eax
    132c:	5d                   	pop    %rbp
    132d:	c3                   	ret    

000000000000132e <addval_110>:
    132e:	f3 0f 1e fa          	endbr64 
    1332:	55                   	push   %rbp
    1333:	48 89 e5             	mov    %rsp,%rbp
    1336:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1339:	8b 45 fc             	mov    -0x4(%rbp),%eax
    133c:	2d 38 76 1f 3c       	sub    $0x3c1f7638,%eax
    1341:	5d                   	pop    %rbp
    1342:	c3                   	ret    

0000000000001343 <addval_487>:
    1343:	f3 0f 1e fa          	endbr64 
    1347:	55                   	push   %rbp
    1348:	48 89 e5             	mov    %rsp,%rbp
    134b:	89 7d fc             	mov    %edi,-0x4(%rbp)
    134e:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1351:	2d 77 3d 7b 3f       	sub    $0x3f7b3d77,%eax
    1356:	5d                   	pop    %rbp
    1357:	c3                   	ret    

0000000000001358 <addval_201>:
    1358:	f3 0f 1e fa          	endbr64 
    135c:	55                   	push   %rbp
    135d:	48 89 e5             	mov    %rsp,%rbp
    1360:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1363:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1366:	2d b8 76 1f 38       	sub    $0x381f76b8,%eax
    136b:	5d                   	pop    %rbp
    136c:	c3                   	ret    

000000000000136d <getval_272>:
    136d:	f3 0f 1e fa          	endbr64 
    1371:	55                   	push   %rbp
    1372:	48 89 e5             	mov    %rsp,%rbp
    1375:	b8 99 d1 08 d2       	mov    $0xd208d199,%eax
    137a:	5d                   	pop    %rbp
    137b:	c3                   	ret    

000000000000137c <getval_155>:
    137c:	f3 0f 1e fa          	endbr64 
    1380:	55                   	push   %rbp
    1381:	48 89 e5             	mov    %rsp,%rbp
    1384:	b8 89 c2 c4 c9       	mov    $0xc9c4c289,%eax
    1389:	5d                   	pop    %rbp
    138a:	c3                   	ret    

000000000000138b <setval_299>:
    138b:	f3 0f 1e fa          	endbr64 
    138f:	55                   	push   %rbp
    1390:	48 89 e5             	mov    %rsp,%rbp
    1393:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1397:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    139b:	c7 00 48 89 e0 91    	movl   $0x91e08948,(%rax)
    13a1:	90                   	nop
    13a2:	5d                   	pop    %rbp
    13a3:	c3                   	ret    

00000000000013a4 <addval_404>:
    13a4:	f3 0f 1e fa          	endbr64 
    13a8:	55                   	push   %rbp
    13a9:	48 89 e5             	mov    %rsp,%rbp
    13ac:	89 7d fc             	mov    %edi,-0x4(%rbp)
    13af:	8b 45 fc             	mov    -0x4(%rbp),%eax
    13b2:	2d 77 31 6d 3c       	sub    $0x3c6d3177,%eax
    13b7:	5d                   	pop    %rbp
    13b8:	c3                   	ret    

00000000000013b9 <getval_311>:
    13b9:	f3 0f 1e fa          	endbr64 
    13bd:	55                   	push   %rbp
    13be:	48 89 e5             	mov    %rsp,%rbp
    13c1:	b8 89 d1 08 db       	mov    $0xdb08d189,%eax
    13c6:	5d                   	pop    %rbp
    13c7:	c3                   	ret    

00000000000013c8 <setval_167>:
    13c8:	f3 0f 1e fa          	endbr64 
    13cc:	55                   	push   %rbp
    13cd:	48 89 e5             	mov    %rsp,%rbp
    13d0:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    13d4:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    13d8:	c7 00 89 d1 91 c3    	movl   $0xc391d189,(%rax)
    13de:	90                   	nop
    13df:	5d                   	pop    %rbp
    13e0:	c3                   	ret    

00000000000013e1 <setval_328>:
    13e1:	f3 0f 1e fa          	endbr64 
    13e5:	55                   	push   %rbp
    13e6:	48 89 e5             	mov    %rsp,%rbp
    13e9:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    13ed:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    13f1:	c7 00 81 c2 38 d2    	movl   $0xd238c281,(%rax)
    13f7:	90                   	nop
    13f8:	5d                   	pop    %rbp
    13f9:	c3                   	ret    

00000000000013fa <setval_450>:
    13fa:	f3 0f 1e fa          	endbr64 
    13fe:	55                   	push   %rbp
    13ff:	48 89 e5             	mov    %rsp,%rbp
    1402:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1406:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    140a:	c7 00 09 ce 08 c9    	movl   $0xc908ce09,(%rax)
    1410:	90                   	nop
    1411:	5d                   	pop    %rbp
    1412:	c3                   	ret    

0000000000001413 <addval_358>:
    1413:	f3 0f 1e fa          	endbr64 
    1417:	55                   	push   %rbp
    1418:	48 89 e5             	mov    %rsp,%rbp
    141b:	89 7d fc             	mov    %edi,-0x4(%rbp)
    141e:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1421:	2d f8 76 1f 6f       	sub    $0x6f1f76f8,%eax
    1426:	5d                   	pop    %rbp
    1427:	c3                   	ret    

0000000000001428 <addval_124>:
    1428:	f3 0f 1e fa          	endbr64 
    142c:	55                   	push   %rbp
    142d:	48 89 e5             	mov    %rsp,%rbp
    1430:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1433:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1436:	05 89 c2 c7 3c       	add    $0x3cc7c289,%eax
    143b:	5d                   	pop    %rbp
    143c:	c3                   	ret    

000000000000143d <getval_169>:
    143d:	f3 0f 1e fa          	endbr64 
    1441:	55                   	push   %rbp
    1442:	48 89 e5             	mov    %rsp,%rbp
    1445:	b8 88 ce 20 c0       	mov    $0xc020ce88,%eax
    144a:	5d                   	pop    %rbp
    144b:	c3                   	ret    

000000000000144c <setval_181>:
    144c:	f3 0f 1e fa          	endbr64 
    1450:	55                   	push   %rbp
    1451:	48 89 e5             	mov    %rsp,%rbp
    1454:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1458:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    145c:	c7 00 48 89 e0 c2    	movl   $0xc2e08948,(%rax)
    1462:	90                   	nop
    1463:	5d                   	pop    %rbp
    1464:	c3                   	ret    

0000000000001465 <addval_184>:
    1465:	f3 0f 1e fa          	endbr64 
    1469:	55                   	push   %rbp
    146a:	48 89 e5             	mov    %rsp,%rbp
    146d:	89 7d fc             	mov    %edi,-0x4(%rbp)
    1470:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1473:	2d 77 3d 9f 2d       	sub    $0x2d9f3d77,%eax
    1478:	5d                   	pop    %rbp
    1479:	c3                   	ret    

000000000000147a <getval_472>:
    147a:	f3 0f 1e fa          	endbr64 
    147e:	55                   	push   %rbp
    147f:	48 89 e5             	mov    %rsp,%rbp
    1482:	b8 8d ce 20 d2       	mov    $0xd220ce8d,%eax
    1487:	5d                   	pop    %rbp
    1488:	c3                   	ret    

0000000000001489 <setval_350>:
    1489:	f3 0f 1e fa          	endbr64 
    148d:	55                   	push   %rbp
    148e:	48 89 e5             	mov    %rsp,%rbp
    1491:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
    1495:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
    1499:	c7 00 48 89 e0 90    	movl   $0x90e08948,(%rax)
    149f:	90                   	nop
    14a0:	5d                   	pop    %rbp
    14a1:	c3                   	ret    

00000000000014a2 <end_farm>:
    14a2:	f3 0f 1e fa          	endbr64 
    14a6:	55                   	push   %rbp
    14a7:	48 89 e5             	mov    %rsp,%rbp
    14aa:	b8 01 00 00 00       	mov    $0x1,%eax
    14af:	5d                   	pop    %rbp
    14b0:	c3                   	ret    

00000000000014b1 <main>:
    14b1:	f3 0f 1e fa          	endbr64 
    14b5:	55                   	push   %rbp
    14b6:	48 89 e5             	mov    %rsp,%rbp
    14b9:	b8 00 00 00 00       	mov    $0x0,%eax
    14be:	5d                   	pop    %rbp
    14bf:	c3                   	ret    

Disassembly of section .fini:

00000000000014c0 <_fini>:
    14c0:	f3 0f 1e fa          	endbr64 
    14c4:	48 83 ec 08          	sub    $0x8,%rsp
    14c8:	48 83 c4 08          	add    $0x8,%rsp
    14cc:	c3                   	ret    
