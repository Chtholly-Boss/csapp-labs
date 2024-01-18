# CSAPP Learning in winter vacation of 2024

本仓库为本人大二寒假时学习CSAPP的lab记录。  
目前完成的lab有：  
- [Datalab]  
- [Bomblab]  



[Datalab]:  
## Datalab  10h
通过 Datalab，我对bit level的运算更加熟悉了。从基本的 xor 实现到 !x，再到条件判断的实现都让我
体会到机器通过bit进行运算的原理。其中，how_many_bits问题我没做出来，在咨询了大佬以及
google后才写下答案...ORZ  
这个lab让我深切的体会到能用高级编程语言进行编程是一件多么便利的事情，如果我是一台计算机的话，我肯定
因为思考怎么在bit level下实现程序员写的各种loop,condition,甚至是object等东西烧掉自己的CPU了吧。 
基本上每道题的思路通过代码都能直接看出来，在这里就不多重复了。 


[Bomblab]:  
## Bomblab  15h
BOOM！
前面爆了几次以及调试过程中因为过于自信也爆了几次...  
这个lab让我学会了使用GDB进行调试，以及AMD标准的汇编语言更加熟悉了  
break打断点，print寄存器信息...  
Phase_6的逆向工程真是艰难，从bomb/trace.txt中就可以看出来本人是如此艰难的解决出来了  
lab写完后返回去看了看，觉得应该对反汇编出来的代码做好分段再做trace  
两个最有用的命令： 
- break * (instruction)
- disassemble instruction1,instruction2 

用第二条指令分好段后做单步执行，慢慢打印出该阶段的寄存器值就行了
