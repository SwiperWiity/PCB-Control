## 文件的说明



- Startup是单片机启动文件，描述了从哪个地址开始启动等等（0x0800000默认），每类不同内存大小的启动文件不一样
- CMSIS是内核的文件，不希望改动
- Config是时钟等配置文件（设置使用内/外部晶振、频率、IT中断）每个程序不一定相同
- SDK是官方提供的**标准外设库**（又称固件库），把寄存器封装成函数的库
- User是用户对IDE的配置文件和Main函数（黑匣子.a文件也放这里吧）
- OBJ是编译生成文件，包含中间文件，最重要的HEX & bin



- MCU_Cloud_Lib 是我提供的云端库文件，它可以在其他的MCU中使用（随时可能会更改，所以打包了起来）（它不在这个 文件夹内，在前面...）



- 一些单片机还有.ld文件（链接脚本）
- 还有可能有历程文件



KEIL软件使用——先看这里，很重要！！



![image-20220924001357178](https://raw.githubusercontent.com/SwiperWitty/img/main/img/202209240013200.png)



Device 选择芯片。

![925edd54c1ce062f8aa13624c778f83](https://raw.githubusercontent.com/SwiperWitty/img/main/img/202209240009590.png)





Target 这个是使用哪些参数（KEIL编译的版本），Use MicroLIB 是为了使用 printf()函数。

![81407f712d57c99130649892977aac8](https://raw.githubusercontent.com/SwiperWitty/img/main/img/202209240009999.png)



C/C++  这个是编译规则 & 编译路径。

![51a31448ebd6eb722c90bc78780608a](https://raw.githubusercontent.com/SwiperWitty/img/main/img/202209240011355.png)



下载&调试 方式 具体看这个 [SWD接口下载程序](https://blog.csdn.net/ReCclay/article/details/103449476)  

![fb1c5e997dc4f894d6d261e487b052d](https://raw.githubusercontent.com/SwiperWitty/img/main/img/202209240012482.png)

你要是还看不懂，那么就： [点这里](https://www.baidu.com/) ！！

