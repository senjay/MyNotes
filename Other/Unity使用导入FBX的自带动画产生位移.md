---
title: Unity使用导入FBX的自带动画产生位移
date:  2020-03-06 14:17:34
categories:
- Unity
tags:
- Unity
---

**1.描述**
&emsp;&emsp;在使用3dsMax导出模型带的动画时，再导入Unity，模型会一直移动到一个固定点。
**2.解决**
&emsp;&emsp;导出动画时不要选bake烘培，因为这个似乎是带着坐标信息的，我测试了好几次，把这个去掉就ok了。但是不选这个的画如果模型有做一些绑定物品，比如手中握着的东西在导入到unity时会产生一些小偏差，不过可以再重新绑定。
![在这里插入图片描述](PicStorage/Unity使用导入FBX的自带动画产生位移.assets/20200306141331820.png)