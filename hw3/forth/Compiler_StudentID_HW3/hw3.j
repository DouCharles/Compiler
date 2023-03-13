.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
ldc 11
istore 0
iload 0
goto L_switch_begin_0
L_case_00:
ldc "A"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto L_switch_end_0
L_case_01:
ldc "B"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto L_switch_end_0
L_case_02:
ldc "C"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto L_switch_end_0
L_case_03:
ldc "D"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto L_switch_end_0
L_case_04:
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
goto L_switch_end_0
L_switch_begin_0:
lookupswitch
0: L_case_00
1: L_case_01
2: L_case_02
3: L_case_03
default: L_case_04
L_switch_end_0:
iload 0
goto L_switch_begin_1
L_case_10:
ldc "A"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto L_switch_end_1
L_case_11:
ldc "B"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto L_switch_end_1
L_case_12:
ldc "C"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto L_switch_end_1
L_case_13:
ldc "D"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
goto L_switch_end_1
L_case_14:
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(I)V
goto L_switch_end_1
L_switch_begin_1:
lookupswitch
10: L_case_10
11: L_case_11
12: L_case_12
13: L_case_13
default: L_case_14
L_switch_end_1:
return
.end method
