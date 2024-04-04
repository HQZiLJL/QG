使用serialize函数，快速收集表单元素的值

参数1：要获取哪个表单的数据

   表单元素需要**设置name属性**，值会作为对象的属性名

   建议name属性的值，最好和接口文档参数名一致

参数2：配置对象

- hash设置获取数据结构

  true:**JS对象**一般请求体里提交给服务器

  false:查询字符串

- empty设置是否获取空值

  true:**获取空值**（推荐）数据结构和标签结构一致

  false:不获取空值

![1712050315914](C:\Users\HQZhen12\Downloads\1712050315914.png)

#### 解构技术：

{ key: 新变量名 } = data

const { username: username } = data