### CSS 之 z-index 属性

#### 属性作用

z-index属性是用来设置元素的堆叠顺序或者叫做元素层级，z-index的值越大，元素的层级越高。当元素发生重叠时，层级高的元素会覆盖在层级低的元素的上面，使层级低的元素的重叠部分被遮盖住。

当**父元素设置了z-index属性**时，子元素的z-index属性只与同级元素和父级元素作比较时才有意义，与其他元素对比时无意义。此时子元素与父元素外的所有的外部元素进行堆叠层级顺序对比时，都以父元素的z-index属性值为准进行对比，子元素本身的z-index属性值无效。

当**父元素未设置了z-index属性**，子元素的z-index属性与父元素外的所有的外部元素进行堆叠层级顺序对比时，都以元素本身的z-index属性值为准进行对比。

------------------------------------------------

#### attr()的使用

.btn::before {  content: attr(data-tip);}

attr()还可以获取更多的其他属性

#### [transition、transform、animation三个属性的使用与区别详解](https://blog.csdn.net/krysliang/article/details/84634235)

transition（过渡）	transform（变换）	animation（动画）

**transition**是一个过渡属性，就是一个属性从一个值过渡到另一个值

**transform**变换，就是一个整体的位置（或整体大小）发生变换

**animation**动画，就是在一段时间内各种属性进行变化从而达到一个动画的效果

##### 一、transition（过渡）

W3C中对transition的描述是：css中的transition**允许css的属性值在一定的时间区间内平滑地过渡**。这种效果可以在鼠标单击、获得焦点、被点击或对元素任何改变中触发，并圆滑的以动画效果改变css的属性值。

###### transition主要包含四个值

transition-property（执行变换的属性）

transition-duration（执行变换的持续时间）

transition-timing-function(变换的速率变化模式)

transition-delay(变换延迟时间)

###### （1）transition-property

这只属性是用来指定元素中哪一个属性执行过渡效果，取值有

none 没有属性需要执行过渡

all 所有属性发生变化（默认值）

indent 元素的某一个属性值

indent的取值覆盖了大部分的css取值，但是自适应的时候，宽度发生变化是不会触发的。

###### （2）transiton-duration

用来指定元素转换过程的持续时间，单位为s或ms，可以作用域任何元素。默认值为0

###### （3）transition-timing-function

transition-timing-function允许我们根据时间的推进去改变属性值的变换速率。主要有以下几个取值

ease（逐渐变慢）

linear（匀速）

ease-in（加速）

ease-out（减速）

ease-in-out（**加速然后减速**）

cubic-bezier（允许自定义一个时间曲线）

 ![1712162810900](C:\Users\HQZhen12\Downloads\1712162810900.png)

（4）transition-delay

用来指定一个动画开始执行的时间，也就是说当改变元素属性值后多唱时间执行transition效果。

 

当我们想要改变不知一个css属性而是改变多个属性的时候，只要把几个transition的声明串在一起，用逗号分隔开，然后定义各自的效果。

因为transition-duration和transition-delay都是时间值，所以一定要**把duration的值放在delay的前面**。



###### transition的连写

transition: <property> <duration> <animation type> <delay>

二、transform（变换）

------------------------------------------------



### 设置字母间距、中文汉字间距

一、 letter-spacing：设置汉字间字间距或者英文单词中每个字母的间距

二、 word-spacing:设置英文每个单词之间的距离，对中文文字之间的距离没有效果

------------------------------------------------

### [负边距（negative margin）原理](https://www.cnblogs.com/LiveWithIt/p/6024864.html)

###### 圣杯布局中的负边距问题

**所有的框都处于流动状态**

浮动框的上边缘会去贴当前行盒的上边缘或是之前浮动框的下边缘，左浮动框的左边缘会去贴包含框的左边缘，或者他

之前的左浮动框的右边缘。如果当前行剩余的空间容不下一个浮动框，他就会换行。（右浮动同理）

这句话描述就是，只要空间够且无阻碍，浮动框边缘一定是要挨着包含框content边缘的。

所以，浮动框的流应该是这样的：

(三个框都是左浮动，包含框做了清浮动处理，设置了宽度500pX。第一个浮动宽为100%，第二个浮动宽为150px,第三个浮动宽为100px.)

![1712242118125](C:\Users\HQZhen12\Downloads\1712242118125.png)

浮动流的力量会推它去贴包含框的content边缘，也就是说，如果一个浮动边缘已经贴在包含框的content边缘，且没有margin的话，在那个方向上，他将不受流动的力量控制。上图中，第二个浮动的上边缘被第一个浮动挡住，第三个浮动的左边缘被第二个浮动挡住，上边缘被第一个浮动挡住。

如果给第二个浮动设置margin-left:-20px的话，他的左拦截线就会移动到第一个浮动的border-right左侧20px的位置：

![1712242150127](C:\Users\HQZhen12\Downloads\1712242150127.png)

------------------------------------------------

### 鼠标摁下按钮样式变化

