#### URL地址的组成部分

URL地址一般由三部组成：

①客户端与服务器之间的通信协议

②存有该资源的服务器名称

③资源在服务器上具体的存放位置![1711957856743](C:\Users\HQZhen12\Downloads\1711957856743.png)

#### 客户端与服务器的通信过程

网页中的海一个资源，都是通过请求一处理一响应的方式从服务器获取回来的。

#### 基于浏览器的开发者工具分析通信过程

1.打开Chrome浏览器

2.Ctrl+Shit+l打开Chrome的开发者工具

3.切换到Network面板

4.选中Doc页签

5.刷新页面，分析客户端与服务器的通信过程

#### 数据是网页的灵魂

HTML是网页的骨架
CSS是网页的颜值
Javascript是网页的行为
数据，则是网页的灵魂
骨架、颜值、行为皆为数据服务
数据，在网页中无处不在

#### 网页中如何请求数据

如果要在网页中请求服务器上的数据资源，则需要用到XMLHttpRequest对象。

XMLHttpRequest(简称xhr）是浏览器提供的js成员，通过它，k可以请求服务器上的数据资源。

最简单的用法var xhrObj=new XMLHttpRequest()

#### 资源的请求方式

客户端请求服务器时，请求的方式有很多种，最常见的两种请求方式分别为gt和post请求。

- get请求通常用于获取服务端资源（向服务器要资源）

  例如：根据URL地址，从服务器获取HTML文件、CSS文件、js文件、图片文件、数据资源等

- post请求通常用于向服务器提交数据（往服务器发送资源）

  例如：登录时向服务器提交的登录信息、注册时向服务器提交的注册信息、添加用户时向服务器提交的用户信息等各种数据提交操作

#### 什么是AJAX

在网页中利用XMLHttpRequest对象和服务器进行数据交互的方式，就是Ajax。

$.get()函数的语法如下：

$get(url,[data],[callback])

其中，三个参数各自代表的含义如下：

| 参数名   | 参数类型 | 是否必选 | 说明                     |
| -------- | -------- | -------- | ------------------------ |
| url      | string   | 是       | 要请求的资源地址         |
| data     | object   | 否       | 请求资源期间要携带的参数 |
| callback | function | 否       | 请求成功时的回调函数     |