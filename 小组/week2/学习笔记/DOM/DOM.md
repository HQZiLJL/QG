#### 什么是DOM

- DOM（Document Object Model-一文档对象模型）是用来呈现以及与任意HTML或XML文档交互的API
- 白话文：DOM是浏览器提供的一套专门用来操作**网页内容**的功能
- DOM作用
  - 开发网页**内容特效**和实现**用户交互**

#### DOM对象

对象包括属性和方法

#### 获取DOM对象

根据CSS选择器来获取DOM元素（重点）

##### 选择匹配的第一个元素

- 语法：

  document.querySelector(**'**css选择器**'**)

- 参数：

  包含一个或多个有效的CSS选择器**字符串**

- 返回值：

  CSS选择器匹配的第一个元素，一个HTMLElement对象。

  如果没有匹配到，则返回nuul。

##### 选择匹配的多个元素

- 语法：

  document.querySelector**All**('css选择器')

- 参数：

  包含一个或多个有效的CSS选择器**字符串**

- 返回值：

  CSS选择器匹配的NodeList 对象集合（伪数组）

- 例如：

  document.querySelectorAll('ul li')
  
  得到的是一个**伪数组**：
  
  有长度有索引号的数组
  
  但是没有pop()push()等数组方法
  
  想要得到里面的每一个对象，则需要遍历for的方式获得。

思考：

1. querySelector()方法能直接操作修改吗？

   可以

2. querySelectorAll()方法能直接修改吗？如果不能可以怎么做到修改？

#### 其他获取DOM元素方法（了解）

根据id获取一个元素

- document.getElementById('nav')

根据标签获取一类元素获取页面所有div

- document.getElementsByTagName('div')

根据类名获取元素获取页面所有类名为w的

- document.getElementsByClassName('w')

