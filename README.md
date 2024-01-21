# CSAPP Learning in winter vacation of 2024

本仓库为本人大二寒假时学习CSAPP的lab记录。  
目前完成的lab有：  
- [CSAPP Learning in winter vacation of 2024](#csapp-learning-in-winter-vacation-of-2024)
  - [Datalab  10h](#datalab--10h)
  - [Bomblab  15h](#bomblab--15h)
  - [Attacklab](#attacklab)



## Datalab  10h
通过 Datalab，我对bit level的运算更加熟悉了。从基本的 xor 实现到 !x，再到条件判断的实现都让我
体会到机器通过bit进行运算的原理。其中，how_many_bits问题我没做出来，在咨询了大佬以及
google后才写下答案...ORZ  

这个lab让我深切的体会到能用高级编程语言进行编程是一件多么便利的事情，如果我是一台计算机的话，我肯定
因为思考怎么在bit level下实现程序员写的各种loop,condition,甚至是object等东西烧掉自己的CPU了吧。 
基本上每道题的思路通过代码都能直接看出来，在这里就不多重复了。 


## Bomblab  15h
BOOM！
前面爆了几次以及调试过程中因为过于自信也爆了几次... 

这个lab让我学会了使用GDB进行调试，以及AMD标准的汇编语言更加熟悉了  
break打断点，print寄存器信息...  

Phase_6的逆向工程真是艰难，从bomb/trace.txt中就可以看出来本人是如此艰难的解决出来了。lab写完后返回去看了看，觉得应该对反汇编出来的代码做好分段再做trace。 

两个最有用的命令： 
- break * (instruction)
- disassemble instruction1,instruction2 

用第二条指令分好段后做单步执行，慢慢打印出该阶段的寄存器值就行了。

## Attacklab
遇到了奇奇怪怪的问题...  
在Ubuntu22.04运行代码 `./ctarget -q` 时无论怎么输入得到的结果都是 `Segmentation Fault`，不得不转移精力去解决该问题。 
所幸在StackOverFlow上找到了[解决方案](https://stackoverflow.com/questions/77568098/csapp-attack-lab-phase1-segmentation-fault-on-ubuntu22-04)。  
Phase_1比较简单，反汇编后找到调用`getbuf()`前栈地址减少了多少以及找到`touch1()`的指令地址就行了。  

Phase_2稍微绕了一下，要求注入自己的代码。我的解决方案是将返回地址`ret`指向`$rsp-0x28`，然后对`touch2`的指令地址做一次push后进行自己的代码操作。所以实际上只要从gdb中获取`%rsp-0x28`在哪里就可以了。  
需要注意的是指令代码不需要调整字节序，是顺序存储的。  

Phase_3的提示很微妙。  
```
As a result, you will need to be careful
where you place the string representation of your cookie.
```
`To be careful!`  
在做lab的过程中会发现基本上buffer区域都会被覆盖掉，因此将cookie对应的ascii码直接放到缓冲区是不合适的，在`GDB`中探索一番过后发现放到返回地址的上方可行...  
一注意到这个点，这个phase就很容易通过了。  

Phase_4比之前的更有难度一些，目的是在一些指令中找到`gadgets`，然后组合到一起实现目的。
对照指令表利用`ctrl+F`，耐心一点就能解决。
