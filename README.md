# HLStoFPGA
ZCU104, Vitis 2019/2020, Tutorial


本教程旨在记录从```hls```到```ZCU104```的快速部署的流程，其中包含了简单的步骤解释，适合有相关基础的同学。  
由于目的是快速验证，因此最后的硬件部署并不基于linux系统，而是基于**裸机+SD card**的形式进行快速硬件验证。  
若想从更深入了解，可以参考Xuan Wang写的[教程](https://github.com/WangXuan95/ZedBoard_Tutorial)。后续会补充hls+petalinux或者Pynq的教程。


# 目录
hls+ vivado + vitis sdk -zcu104为例	1
-  一、 HLS部分	
     - 1.1 C Simulation	
    - 1.2 C Synthesis	
    - 1.3 Co-Simulation	
    - 1.4 Export RTL	
- 二、 Vivado部分	
    - 2.1 创建工程	
    - 2.2 创建Block Design	
    - 2.3 添加HLS IP核心	
    - 2.2 添加PS及配置	
    - 2.3 添加AXI桥	
    - 2.4 Address Assign & Valide Design	
    - 2.3 综合以及实现	
    - 2.4 导出硬件	
- 三、 Vitis部分	
    - 3.1 创建platform 工程	
    - 3.2 创建application工程	
    - 3.3 编写测试程序	
    - 3.4 Program FPGA	
