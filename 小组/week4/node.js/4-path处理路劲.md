#### path.join()的语法格式

使用path.join()方法，可以把**多个路径片段拼接为完整的路径字符**串，语法格式如下：

path.join([...paths])

参数解读：

- path**<string>**路径片段的序列
- 返回值<strn

../会抵消前一个路径

注意：凡是涉及到路径拼接的操作，都要使用path.join()方法进行处理。不要直接使用+进行字符串的拼接。

#### 获取路径中的文件名

###### path.basename()的语法格式

使用path.basename()方法，可以获取路径中的最后一部分，经常通过这个方法获取路径中的文件名，语法格式如下：

path.basename(path[,ext])

参数解读：

- path**<string>**必选参数，表示一个路径的字符串
- ext**<string>**可选参数，表示文件扩展名
- 返回：**<string>**表示路径中的最后部分

#### 获取路径中的文件扩展名

###### path.extname()的语法格式

使用path.extname()方法，可以获取路径中的扩展名部分，语法格式如下：

path.extname(path)

参数解读：

- path**<string>**必选参数，表示一个路径的字符串
- 返回：**<string>**返回得到的扩展名字符串公