#### 使用XMLHttpRequest

步骤：

1.创建XMLHttpRequest对象

2.配置请求方法和请求url地址

3.监听loadend事件，接收响应结果

4.发起请求

![1712076978551](C:\Users\HQZhen12\Downloads\1712076978551.png)

#### XMLHttpRequest-数据提交

需求：通过XHR提交用户名和密码，完成注册功能

核心：

请求头设置Content-Type:application/json

请求体携带JSON字符串

![1712153141004](C:\Users\HQZhen12\Downloads\1712153141004.png)