#### 设置/修改元素内容

##### document.write()方法

document.write()方法只能追加到body中

##### 元素.innerText属性

1. 将文本内容添加/更新到任意标签位置
2. 文本中包含的标签**不会被解析**
3. innerText属性

- 对象.属性 = ‘值'**（不识别标签）**

##### 元素.innerHTML属性

1. 将文本内容添加/更新到任意标签位置
2. 文本中包含的**标签会被解析**

div {

​	vertical-align : middle;

}

visibility ='hidden'         //隐藏（占空间）

display = 'none'             //不占空间

#### 设置/修改常用属性

1. 获取元素
2. 修改属性

#### 设置/修改元素样式属性

##### 通过style属性操作CSS

语法：

对象.style.样式属性=值

举例说明

let box = document.querySelector('.box')

注意：

1. 修改样式通过style属性引出

   box.style.width '300px'

2. 如果属性有-连接符，需要转换为**小驼峰**命名法

   box.style.margin**T**op = '50px'

3. 赋值的时候，需要的时候不要忘记加css单位

##### 操作类名(className)操作CSS

如果修改的样式比较多，直接通过styl属性修改比较繁琐，我们可以通过借助于css类名的形式。

语法：（active是一个css类名）

元素.className='active'

className是使用新值换旧值，如果需要添加一个类，需要保留之前的类名

##### 通过classList操作类控制CSS

为了解决className容易覆盖以前的类名，我们可以通过classList方式追加和删除类名

语法：

追加一个类（add是一个方法）

- 元素.classList.add('类名')

删除一个类

- 元素.classList.remove('类名')

**切换**一个类

- 元素.classList.toggle('类名')

#### 设置/修改表单元素属性

表单属性中添加就有效果，移除就没有效果，一律使用**布尔值**表示如果为true代表添加了该属性如果是flse代表移除了该属性
比如：disabled、checked、selected

