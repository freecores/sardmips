@00000000	 MIPS (ID): lui $29, 0
@00000004	 MIPS (ID): addiu $29, $29, 16368
@00000008	 MIPS (ID): addiu $8, $0, 0
@0000000c	 MIPS (ID): lui $9, 0
@00000010	 MIPS (ID): addiu $9, $9, 16384
@00000014	 MIPS (ID): jal 620
@00000018	 MIPS (ID): nop
@0000001c	 MIPS (ID): j 28
@00000020	 MIPS (ID): addiu $29, $29, -40
@00000024	 MIPS (ID): sw $31, 36($29) (36)
@00000028	 MIPS (ID): sw $30, 32($29) (32)
@0000002c	 MIPS (ID): or $30, $29, $0
@00000030	 MIPS (ID): sw $4, 40($30) (40)
@00000034	 MIPS (ID): sw $5, 44($30) (44)
@00000038	 MIPS (ID): sw $6, 48($30) (48)
@0000003c	 MIPS (ID): lw $2, 44($30) (44)
@00000040	 MIPS (ID): nop
@00000044	 MIPS (ID): sw $2, 16($30) (16)
@00000048	 MIPS (ID): lw $2, 48($30) (48)
@0000004c	 MIPS (ID): nop
@00000050	 MIPS (ID): sw $2, 20($30) (20)
@00000054	 MIPS (ID): lw $3, 44($30) (44)
@00000058	 MIPS (ID): lw $2, 48($30) (48)
@0000005c	 MIPS (ID): nop
@00000060	 MIPS (ID): addu $3, $3, $2
@00000064	 MIPS (ID): sra $2, $3, 31
@00000068	 MIPS (ID): srl $2, $2, 31
@0000006c	 MIPS (ID): addu $2, $3, $2
@00000070	 MIPS (ID): sra $2, $2, 1
@00000074	 MIPS (ID): sll $3, $2, 2
@00000078	 MIPS (ID): lw $2, 40($30) (40)
@0000007c	 MIPS (ID): nop
@00000080	 MIPS (ID): addu $2, $3, $2
@00000084	 MIPS (ID): lw $2, 0($2) (0)
@00000088	 MIPS (ID): nop
@0000008c	 MIPS (ID): sw $2, 28($30) (28)
@00000090	 MIPS (ID): lw $2, 16($30) (16)
@00000094	 MIPS (ID): nop
@00000098	 MIPS (ID): sll $3, $2, 2
@0000009c	 MIPS (ID): lw $2, 40($30) (40)
@000000a0	 MIPS (ID): nop
@000000a4	 MIPS (ID): addu $2, $3, $2
@000000a8	 MIPS (ID): lw $3, 0($2) (0)
@000000ac	 MIPS (ID): lw $2, 28($30) (28)
@000000b0	 MIPS (ID): nop
@000000b4	 MIPS (ID): slt $2, $3, $2
@000000b8	 MIPS (ID): bne $0, $2, 3
@000000bc	 MIPS (ID): nop
@000000c0	 MIPS (ID): beq $0, $0, 6
@000000c4	 MIPS (ID): nop
@000000c8	 MIPS (ID): lw $2, 16($30) (16)
@000000cc	 MIPS (ID): nop
@000000d0	 MIPS (ID): addiu $2, $2, 1
@000000d4	 MIPS (ID): beq $0, $0, -18
@000000d8	 MIPS (ID): sw $2, 16($30) (16)
@000000dc	 MIPS (ID): nop
@000000e0	 MIPS (ID): lw $2, 20($30) (20)
@000000e4	 MIPS (ID): nop
@000000e8	 MIPS (ID): sll $3, $2, 2
@000000ec	 MIPS (ID): lw $2, 40($30) (40)
@000000f0	 MIPS (ID): nop
@000000f4	 MIPS (ID): addu $2, $3, $2
@000000f8	 MIPS (ID): lw $3, 0($2) (0)
@000000fc	 MIPS (ID): lw $2, 28($30) (28)
@00000100	 MIPS (ID): nop
@00000104	 MIPS (ID): slt $2, $2, $3
@00000108	 MIPS (ID): bne $0, $2, 3
@0000010c	 MIPS (ID): nop
@00000110	 MIPS (ID): beq $0, $0, 6
@00000114	 MIPS (ID): nop
@00000118	 MIPS (ID): lw $2, 20($30) (20)
@0000011c	 MIPS (ID): nop
@00000120	 MIPS (ID): addiu $2, $2, -1
@00000124	 MIPS (ID): beq $0, $0, -18
@00000128	 MIPS (ID): sw $2, 20($30) (20)
@0000012c	 MIPS (ID): lw $2, 16($30) (16)
@00000130	 MIPS (ID): lw $3, 20($30) (20)
@00000134	 MIPS (ID): nop
@00000138	 MIPS (ID): slt $2, $3, $2
@0000013c	 MIPS (ID): bne $0, $2, 42
@00000140	 MIPS (ID): nop
@00000144	 MIPS (ID): lw $2, 16($30) (16)
@00000148	 MIPS (ID): nop
@0000014c	 MIPS (ID): sll $3, $2, 2
@00000150	 MIPS (ID): lw $2, 40($30) (40)
@00000154	 MIPS (ID): nop
@00000158	 MIPS (ID): addu $2, $3, $2
@0000015c	 MIPS (ID): lw $2, 0($2) (0)
@00000160	 MIPS (ID): nop
@00000164	 MIPS (ID): sw $2, 24($30) (24)
@00000168	 MIPS (ID): lw $2, 16($30) (16)
@0000016c	 MIPS (ID): nop
@00000170	 MIPS (ID): sll $3, $2, 2
@00000174	 MIPS (ID): lw $2, 40($30) (40)
@00000178	 MIPS (ID): nop
@0000017c	 MIPS (ID): addu $4, $3, $2
@00000180	 MIPS (ID): lw $2, 20($30) (20)
@00000184	 MIPS (ID): nop
@00000188	 MIPS (ID): sll $3, $2, 2
@0000018c	 MIPS (ID): lw $2, 40($30) (40)
@00000190	 MIPS (ID): nop
@00000194	 MIPS (ID): addu $2, $3, $2
@00000198	 MIPS (ID): lw $2, 0($2) (0)
@0000019c	 MIPS (ID): nop
@000001a0	 MIPS (ID): sw $2, 0($4) (0)
@000001a4	 MIPS (ID): lw $2, 20($30) (20)
@000001a8	 MIPS (ID): nop
@000001ac	 MIPS (ID): sll $3, $2, 2
@000001b0	 MIPS (ID): lw $2, 40($30) (40)
@000001b4	 MIPS (ID): nop
@000001b8	 MIPS (ID): addu $3, $3, $2
@000001bc	 MIPS (ID): lw $2, 24($30) (24)
@000001c0	 MIPS (ID): nop
@000001c4	 MIPS (ID): sw $2, 0($3) (0)
@000001c8	 MIPS (ID): lw $2, 16($30) (16)
@000001cc	 MIPS (ID): nop
@000001d0	 MIPS (ID): addiu $2, $2, 1
@000001d4	 MIPS (ID): sw $2, 16($30) (16)
@000001d8	 MIPS (ID): lw $2, 20($30) (20)
@000001dc	 MIPS (ID): nop
@000001e0	 MIPS (ID): addiu $2, $2, -1
@000001e4	 MIPS (ID): sw $2, 20($30) (20)
@000001e8	 MIPS (ID): lw $2, 16($30) (16)
@000001ec	 MIPS (ID): lw $3, 20($30) (20)
@000001f0	 MIPS (ID): nop
@000001f4	 MIPS (ID): slt $2, $3, $2
@000001f8	 MIPS (ID): beq $0, $2, -91
@000001fc	 MIPS (ID): nop
@00000200	 MIPS (ID): lw $2, 44($30) (44)
@00000204	 MIPS (ID): lw $3, 20($30) (20)
@00000208	 MIPS (ID): nop
@0000020c	 MIPS (ID): slt $2, $2, $3
@00000210	 MIPS (ID): beq $0, $2, 6
@00000214	 MIPS (ID): nop
@00000218	 MIPS (ID): lw $4, 40($30) (40)
@0000021c	 MIPS (ID): lw $5, 44($30) (44)
@00000220	 MIPS (ID): lw $6, 20($30) (20)
@00000224	 MIPS (ID): jal 32
@00000228	 MIPS (ID): nop
@0000022c	 MIPS (ID): lw $2, 16($30) (16)
@00000230	 MIPS (ID): lw $3, 48($30) (48)
@00000234	 MIPS (ID): nop
@00000238	 MIPS (ID): slt $2, $2, $3
@0000023c	 MIPS (ID): beq $0, $2, 6
@00000240	 MIPS (ID): nop
@00000244	 MIPS (ID): lw $4, 40($30) (40)
@00000248	 MIPS (ID): lw $5, 16($30) (16)
@0000024c	 MIPS (ID): lw $6, 48($30) (48)
@00000250	 MIPS (ID): jal 32
@00000254	 MIPS (ID): nop
@00000258	 MIPS (ID): or $29, $30, $0
@0000025c	 MIPS (ID): lw $31, 36($29) (36)
@00000260	 MIPS (ID): lw $30, 32($29) (32)
@00000264	 MIPS (ID): jr $31
@00000268	 MIPS (ID): addiu $29, $29, 40
@0000026c	 MIPS (ID): addiu $29, $29, -88
@00000270	 MIPS (ID): sw $31, 84($29) (84)
@00000274	 MIPS (ID): sw $30, 80($29) (80)
@00000278	 MIPS (ID): or $30, $29, $0
@0000027c	 MIPS (ID): addiu $2, $0, 1024
@00000280	 MIPS (ID): sw $2, 68($30) (68)
@00000284	 MIPS (ID): addiu $2, $0, 4
@00000288	 MIPS (ID): sw $2, 72($30) (72)
@0000028c	 MIPS (ID): lw $3, 68($30) (68)
@00000290	 MIPS (ID): lw $2, 72($30) (72)
@00000294	 MIPS (ID): nop
@00000298	 MIPS (ID): mult [Hi,Lo], $3, $2
@0000029c	 MIPS (ID): mflo $2 [Lo]
@000002a0	 MIPS (ID): sw $2, 64($30) (64)
@000002a4	 MIPS (ID): addiu $2, $0, 13
@000002a8	 MIPS (ID): sw $2, 16($30) (16)
@000002ac	 MIPS (ID): addiu $2, $0, 34
@000002b0	 MIPS (ID): sw $2, 20($30) (20)
@000002b4	 MIPS (ID): addiu $2, $0, 86
@000002b8	 MIPS (ID): sw $2, 24($30) (24)
@000002bc	 MIPS (ID): addiu $2, $0, 23
@000002c0	 MIPS (ID): sw $2, 28($30) (28)
@000002c4	 MIPS (ID): addiu $2, $0, 52
@000002c8	 MIPS (ID): sw $2, 32($30) (32)
@000002cc	 MIPS (ID): addiu $2, $0, 43
@000002d0	 MIPS (ID): sw $2, 36($30) (36)
@000002d4	 MIPS (ID): addiu $2, $0, 45
@000002d8	 MIPS (ID): sw $2, 40($30) (40)
@000002dc	 MIPS (ID): addiu $2, $0, 87
@000002e0	 MIPS (ID): sw $2, 44($30) (44)
@000002e4	 MIPS (ID): addiu $2, $0, 12
@000002e8	 MIPS (ID): sw $2, 48($30) (48)
@000002ec	 MIPS (ID): addiu $2, $0, 24
@000002f0	 MIPS (ID): sw $2, 52($30) (52)
@000002f4	 MIPS (ID): addiu $2, $0, 35
@000002f8	 MIPS (ID): sw $2, 56($30) (56)
@000002fc	 MIPS (ID): addiu $2, $0, 100
@00000300	 MIPS (ID): sw $2, 60($30) (60)
@00000304	 MIPS (ID): addiu $4, $30, 16
@00000308	 MIPS (ID): or $5, $0, $0
@0000030c	 MIPS (ID): jal 32
@00000310	 MIPS (ID): addiu $6, $0, 11
@00000314	 MIPS (ID): lui $2, 256
@00000318	 MIPS (ID): ori $2, $2, 0x1000
@0000031c	 MIPS (ID): sw $2, 76($30) (76)
@00000320	 MIPS (ID): lw $3, 76($30) (76)
@00000324	 MIPS (ID): lw $2, 16($30) (16)
@00000328	 MIPS (ID): nop
@0000032c	 MIPS (ID): sw $2, 0($3) (0)
@00000330	 MIPS (ID): lui $2, 256
@00000334	 MIPS (ID): ori $2, $2, 0x1004
@00000338	 MIPS (ID): sw $2, 76($30) (76)
@0000033c	 MIPS (ID): lw $3, 76($30) (76)
@00000340	 MIPS (ID): lw $2, 20($30) (20)
@00000344	 MIPS (ID): nop
@00000348	 MIPS (ID): sw $2, 0($3) (0)
@0000034c	 MIPS (ID): lui $2, 256
@00000350	 MIPS (ID): ori $2, $2, 0x1008
@00000354	 MIPS (ID): sw $2, 76($30) (76)
@00000358	 MIPS (ID): lw $3, 76($30) (76)
@0000035c	 MIPS (ID): lw $2, 24($30) (24)
@00000360	 MIPS (ID): nop
@00000364	 MIPS (ID): sw $2, 0($3) (0)
@00000368	 MIPS (ID): lui $2, 256
@0000036c	 MIPS (ID): ori $2, $2, 0x100c
@00000370	 MIPS (ID): sw $2, 76($30) (76)
@00000374	 MIPS (ID): lw $3, 76($30) (76)
@00000378	 MIPS (ID): lw $2, 28($30) (28)
@0000037c	 MIPS (ID): nop
@00000380	 MIPS (ID): sw $2, 0($3) (0)
@00000384	 MIPS (ID): lui $2, 256
@00000388	 MIPS (ID): ori $2, $2, 0x1010
@0000038c	 MIPS (ID): sw $2, 76($30) (76)
@00000390	 MIPS (ID): lw $3, 76($30) (76)
@00000394	 MIPS (ID): lw $2, 32($30) (32)
@00000398	 MIPS (ID): nop
@0000039c	 MIPS (ID): sw $2, 0($3) (0)
@000003a0	 MIPS (ID): lui $2, 256
@000003a4	 MIPS (ID): ori $2, $2, 0x1014
@000003a8	 MIPS (ID): sw $2, 76($30) (76)
@000003ac	 MIPS (ID): lw $3, 76($30) (76)
@000003b0	 MIPS (ID): lw $2, 36($30) (36)
@000003b4	 MIPS (ID): nop
@000003b8	 MIPS (ID): sw $2, 0($3) (0)
@000003bc	 MIPS (ID): lui $2, 256
@000003c0	 MIPS (ID): ori $2, $2, 0x1018
@000003c4	 MIPS (ID): sw $2, 76($30) (76)
@000003c8	 MIPS (ID): lw $3, 76($30) (76)
@000003cc	 MIPS (ID): lw $2, 40($30) (40)
@000003d0	 MIPS (ID): nop
@000003d4	 MIPS (ID): sw $2, 0($3) (0)
@000003d8	 MIPS (ID): lui $2, 256
@000003dc	 MIPS (ID): ori $2, $2, 0x101c
@000003e0	 MIPS (ID): sw $2, 76($30) (76)
@000003e4	 MIPS (ID): lw $3, 76($30) (76)
@000003e8	 MIPS (ID): lw $2, 44($30) (44)
@000003ec	 MIPS (ID): nop
@000003f0	 MIPS (ID): sw $2, 0($3) (0)
@000003f4	 MIPS (ID): lui $2, 256
@000003f8	 MIPS (ID): ori $2, $2, 0x1020
@000003fc	 MIPS (ID): sw $2, 76($30) (76)
@00000400	 MIPS (ID): lw $3, 76($30) (76)
@00000404	 MIPS (ID): lw $2, 48($30) (48)
@00000408	 MIPS (ID): nop
@0000040c	 MIPS (ID): sw $2, 0($3) (0)
@00000410	 MIPS (ID): lui $2, 256
@00000414	 MIPS (ID): ori $2, $2, 0x1024
@00000418	 MIPS (ID): sw $2, 76($30) (76)
@0000041c	 MIPS (ID): lw $3, 76($30) (76)
@00000420	 MIPS (ID): lw $2, 52($30) (52)
@00000424	 MIPS (ID): nop
@00000428	 MIPS (ID): sw $2, 0($3) (0)
@0000042c	 MIPS (ID): lui $2, 256
@00000430	 MIPS (ID): ori $2, $2, 0x1028
@00000434	 MIPS (ID): sw $2, 76($30) (76)
@00000438	 MIPS (ID): lw $3, 76($30) (76)
@0000043c	 MIPS (ID): lw $2, 56($30) (56)
@00000440	 MIPS (ID): nop
@00000444	 MIPS (ID): sw $2, 0($3) (0)
@00000448	 MIPS (ID): lui $2, 256
@0000044c	 MIPS (ID): ori $2, $2, 0x102c
@00000450	 MIPS (ID): sw $2, 76($30) (76)
@00000454	 MIPS (ID): lw $3, 76($30) (76)
@00000458	 MIPS (ID): lw $2, 60($30) (60)
@0000045c	 MIPS (ID): nop
@00000460	 MIPS (ID): sw $2, 0($3) (0)
@00000464	 MIPS (ID): lui $2, 256
@00000468	 MIPS (ID): ori $2, $2, 0x1030
@0000046c	 MIPS (ID): sw $2, 76($30) (76)
@00000470	 MIPS (ID): lw $3, 76($30) (76)
@00000474	 MIPS (ID): lw $2, 64($30) (64)
@00000478	 MIPS (ID): nop
@0000047c	 MIPS (ID): sw $2, 0($3) (0)
@00000480	 MIPS (ID): nop
@00000484	 MIPS (ID): lui $2, 32767
@00000488	 MIPS (ID): ori $2, $2, 0xfffffffc
@0000048c	 MIPS (ID): sw $2, 76($30) (76)
@00000490	 MIPS (ID): lw $2, 76($30) (76)
@00000494	 MIPS (ID): nop
@00000498	 MIPS (ID): sw $0, 0($2) (0)
@0000049c	 MIPS (ID): or $2, $0, $0
@000004a0	 MIPS (ID): or $29, $30, $0
@000004a4	 MIPS (ID): lw $31, 84($29) (84)
@000004a8	 MIPS (ID): lw $30, 80($29) (80)
@000004ac	 MIPS (ID): jr $31
@000004b0	 MIPS (ID): addiu $29, $29, 88
@000004b4	 MIPS (ID): nop
@000004b8	 MIPS (ID): nop
@000004bc	 MIPS (ID): nop
@000004c0	 MIPS (ID): sb $0, 768($0) (768)
@000004c4	 MIPS (ID): nop
@000004c8	 MIPS (ID): nop
@000004cc	 MIPS (ID): nop
@000004d0	 MIPS (ID): nop
@000004d4	 MIPS (ID): nop