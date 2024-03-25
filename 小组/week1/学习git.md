## git的使用

#### 一. 快速克隆与连接远程仓库

语法：`git clone http://username:password@gitlab.com/test.git`

#### 二. 工作区与暂存区

在Git中包含三个区域分别是：`工作区`、`暂存区`、`历史记录区`

#### 三、常用快捷命令

##### 检查配置信息：

- git config --list：列出所有Git当前找到的配置，如用户名、密码、过滤属性值等等。(可能会看到重复的变

  量名，因为会从不同的文件中读取同一个配置)

- git config <key>：检查Git某一项配置。例如查看用户名：git config user.name

##### 获取帮助：

- git help <verb>或git <verb> --help：获取指定命令的帮助，跳转指定页面包含详细介绍
- git <verb> -h：-h为help简写，在cmd中获取到帮助描述

##### 版本库操作

- git init：在指定目录创建一个.git的子目录，也就是该目录下创建了一个git仓库用来管理

- git clone <url>：克隆指定的仓库

- git status：检查当前文件状态，会有较详细的信息描述

- git status -s或git status --short：缩短状态命令输出，简洁查看信息。若无任何信息说明暂时没有所需提

  交文件

  - ?? file1：在工作区，表示该文件还未添加到暂存区
  - A file2：在暂存区，表示该文件还未提交到版本库

##### 添加到暂存区

- git add <filename>：添加指定文件到暂存区。
- git add .：添加所有修改文件到暂存区。

情况1：若是你是用git add添加一个文件到暂存区了，接着你对该文件进行修改，之后使用git commit提交，

注意了提交的是之前添加到暂存区的版本而不是你之后修改的！！！想要提交新的你还得重新git add接着git 

comit。

##### 提交到版本库

- git commit -m "描述信息" ：将暂存区的提交到版本库，并且会提示哪个分支提交的，多少文件修订、多少行添加和删改过。

- git commit -a -m "描述信息"：添加-a选项，可自动将所有跟踪文件暂存起来并提交，跳过git add步骤。

包含所有修改过的文件，注意有时该选项会将不需要的文件添加到提交中。

注意：只针对于修改文件可以直接跳过git add，对于新创建的文件还是需要使用git add的！

- git commit --amend -m [message]：如果代码没有任何新变化，则用来改写上一次commit的提交信息。

- git commit --amend [file 1] [file 2] ...：重做上一次commit，并包括指定文件的新变化。

##### 比较命令

-  git diff：比较工作目录中当前文件和暂存区域快照之间的差异。

- git diff --staged或git diff --cached：比较暂存区与版本区最后一次提交的文件差异。

##### 移动文件

- git mv <file_from> <file_to>：重命名文件，改名放入暂存区。查看状态会显示重命名操作。

使用git mv相当于执行三条语句如下：

$ mv README.md README
$ git rm README.md
$ git add README

##### 删除操作

格式：git rm [-r | -f | --cached]。

- -r：覆盖最新检查。

- -f：递归删除文件目录。

- --cached：从索引中删除路径，工作区保留。(简单说就是在最新提交中删除指定文件索引，原本工作目录

  保留)

小例子：

- git rm -r <filename>：删除工作区中的指定文件，注意并不会删除索引，所以还是需要进行提交操作。
- git rm -r --cached <filename>：删除最新提交中的指定索引
- git rm -r --cached *：删除最新提交的所有索引(需要提交)。

##### 查看日志记录

- git log：列出所有提交情况，最近更新的在最上面，列出内容为每个提交的 SHA-1 校验和、作者的名字和电子邮件地址、提交时间以及提交说明。

- git log -p或git log --patch：可显示每次提交所引入的差异(用于代码审查)，并且可限制日志条数数量，如

  再添加-2参数表示最近两次提交。

- git log --stat：快速浏览某个提交变化，只显示简略信息。

定制默认格式来展示提交历史：选项--pretty

- git log --pretty=oneline：在一行中显示日志信息，仅包含哈希值以及提交信息。

- git log --pretty=short：非一行，包含哈希值、作者auther、提交信息。

- git log --pretty=full：非一行，包含哈希值、作者auther、提交者commit、提交信息。

- git log --pretty=fuller：非一行，包含哈希值、作者auther、作者日期、提交者commit、提交日期、提交

  信息。

- git log --pretty=format:"%h - %an, %ar : %s"(建议！！！)：定制记录显示格式。常用选项如下：

| 选项 | 说明                                          |
| ---- | --------------------------------------------- |
| %H   | 提交的完整哈希值                              |
| %h   | 提交的简写哈希值                              |
| %T   | 树的完整哈希值                                |
| %t   | 树的简写哈希值                                |
| %P   | 父提交的完整哈希值                            |
| %p   | 父提交的简写哈希值                            |
| %an  | 作者名字                                      |
| %ae  | 作者的电子邮件地址                            |
| %ad  | 作者修订日期（可以用 --date=选项 来定制格式） |

| %ar  | 作者修订日期，按多久以前的方式显示 |
| ---- | ---------------------------------- |
| %cn  | 提交者的名字                       |
| %ce  | 提交者的电子邮件地址               |
| %cd  | 提交日期                           |
| %cr  | 提交日期（距今多长时间）           |
| %s   | 提交说明                           |

作者指的是实际作出修改的人，提交者指的是最后将此工作成果提交到仓库的人。

git log --pretty=format:"%cd %h %s" --graph：添加选项--graph能够展示形象展示分支、合并历史,包含提交

的时间。

- 时间样式修改：Mon Oct 20 17:26:23 2014 => 2014-10-21 14:55:24 +0800。需要你进行配置：git config 

  log.date iso-strict-local。全局设置为：git config --global log.date iso-strict-local

##### 分支

- 查看：当前使用的分支前有*号

  git branch：查看所有本地分支，信息有分支名(简略信息)。

  git branch -v：查看所有本地分支，信息有分支名、哈希值、最新的操作说明及相关文件名。

  git branch -r：查看所有的远程分支。

  git branch -a：列出所有本地分支和远程分支

- 创建：创建了分支之后默认保存master最新的版本及操作。

  git branch <branchName>：创建指定名称的分支。

- 切换分支：文件中的内容会进行改变，即为对应切换分支的内容！！！

  注意：在切换分支时最好将工作区以及暂存区的中的修改了但未提交了的进行提交。

  git checkout <branchName>：切换指定名称的分支，并更新工作区。

  git checkout -b <branchName>：直接创建并切换到该分支。

  实际使用了两条命令：git branch <branchName>、git checkout <branchName>

- 删除分支

  git branch -b <branchName>：删除指定的分支。

- 合并分支：一般都是master合并其他分支，首先需要切换到master主分支，接着合并其他分支

  git merge <mergeBranchName>：合并其他分支，合并之后会切换到目标合并分支。

一般合并好之后当前分支是在目标分支上的，合并之后目标分支已经没有用了(解决问题了)，之后我们切换到

主分支，接着删除该目标分支即可！！！

##### 远程仓库

###### 抓取与拉取

url：指的是对应仓库的ssh地址或url地址；remoteName：表示关联仓库名称。

- git clone <url>：默认只有一个本地分支为master以及包含所有远程分支。若只是通过git branch -v只能

  查看到本地分支，想要切换其他远程分支进行开发，直接git checkout <远程分支名>命令切换即可！

- git clone -b <分支名> <url>：克隆指定远程仓库的指定分支。例如：git clone -b dev git@gitee.co

  m:changluJava/exer.git。

- git pull [remote] [branch]：取回远程仓库的变化，并与本地分支合并。使用git pull默认更新当前分支，自动合并操作。

  简单来说就是根据远程仓库来更新指定分支内容！

- git fetch <remote>：下载远程仓库的所有变动(所有分支)，但是不会自动合并。

  使用git fetch命令之后，接着使用git merge进行合并。

  说明：推荐使用git pull来进行更新指定分支内容！git fetch并不常用。

##### 查看远程仓库

git remote -v：查看该仓库所有的关联仓库名称、远程仓库地址。

git remote show或git remote：仅仅获取远程仓库的remote名称。

git remote show <remote>：查看某一个远程仓库信息，例如git remote show origin，即可查看origin远程

仓库的URL、跟踪分支的信息(告诉你处于的分支)

##### 关联远程仓库

git remote add 名称标识 ssh地址：添加一个关联远程库。

##### 重命名远程仓库与移除

###### 重命名：

- git remote rename <remoteOld> <remoteNew> ：修改一个远程仓库名称。这样也会修改所有远程跟

  踪的分支名称。举例：git remote rename origin github ，修改仓库名后，对应分支名称也会随之改变，

  原本origin/master会改变为github/master。

  - 可事先使用查看关联仓库之后选定修改：git remote -v或git remote

###### 移除：

- git remote rm <remote>：删除指定的远程仓库，包含这个仓库所有的相关远程跟踪分支及配置信息。

##### 推送远程仓库

- remote指的是关联仓库名称、branch为对应关联仓库的分支

git push <remote> <branch>(常用)：将指定branch分支推送到指定remote服务器上。

git push [remote] --force：强行推送当前分支到远程仓库，即使有冲突。

git push [remote] --all：推送所有分支到远程仓库

git push -u <remote> <branch>：添加-u选项，记住推送的远程仓库及指定分支。

- 记住之后直接使用git push即可推送到指定远程仓库及分支。

##### 标签

###### 查看标签

git tag：以字母顺序列出所有列表标签。

git tag -l <通配符序列>或git tag --list <通配符序列>：按照特定模式查找标签，例如git tag -l "v1.8.5*"，查看所有1.8.5系列的标签。

git show <v.版本>：查看指定标签的信息。

对于轻量标签：仅有提交信息(提交哈希值、作者邮箱、日期)，无额外的标签信息(下面图片信息没有)。
对于附注标签：查看标签信息和对应的提交信息(打标签者的信息、打标签的日期时间、附注信息及具体的提交信息)。

###### 创建标签：

**轻量标签**(临时打标签建议使用)：只是某个特定提交的引用。只是将提交检验和存储到一个文件，没有保存任何其他信息。

git tag <v.版本>：最近提交的指定分支打上轻量标签。例如：git tag v1.0-lw

**附注标签**(建议使用)：存储在 Git 数据库中的一个完整对象，可被校验，包含打标签者的名字、电子邮件地址、日期时间及标签信息( 可使用GNU Privacy Guard （GPG）签名并验证)。

git tag -a <v.版本> -m <msg>：指定-a选项表示附注标签，-m后表示标签描述。

###### 后期打标签：之前多次提交都没有打标签，想给之前某次提交打上标签。

首先使用git log --pretty=oneline命令查看所有的提交日志，包含对应提交的哈希值如下：

- git tag -a <v.版本> <某次提交哈希值>：给指定提交记录打上标签(附注标签)即可。

  推送标签：即共享标签，默认情况下你使用git push并不会把打上的标签传送到远程服务器上，可理解为对于标签需要额外使用命令上传。

- git push <remote> <tagname>：将指定标签推送到远程仓库中去。例如：git push origin v1.5。

- git push <remote> --tags：将会把所有不在远程仓库服务器上的标签全部传送到指定关联的远程仓库中。


删除标签：删除本地标签与删除远程仓库的标签需要使用不同命令，轻量、附注标签都可删。

##### 删除本地仓库标签

git tag -d <tagname>：在本地删除指定标签，远程仓库并不会删除该标签的。示例：git tag -d v0.6-lw

###### 删除远程仓库标签

方式一**(较复杂)**： git push <remote> :refs/tags/<tagname>：将冒号前面的空值推送到远程标签名，从而高效地删除指定标签。示例：git push origin :refs/tags/v1.0-lw
方式二**(直观)**：git push origin --delete <tagname>：比较容易看懂。示例：git push origin --delete v1.0。

检出标签：若是想要修复某个标签下的项目bug(旧版本错误检测)，那么首先需要找到对应标签的提交记录(即该提交的哈希值)。

前提说明：使用的check out <tagname>来查看指定标签对应的提交记录(找到哈希值)。

较好解决方案：创建一个新分支在该分支上进行检出标签获取到对应标签的提交哈希，接着切回原来的master主分支即可！！！

创建并切换分支：git checkout -b findTagHash

检出标签：git checkout v1.0

此时头指针处于分离状态也就是之前提出的问题：

切回主分支master，并删除findTagHash分支：git checkout master、git branch -d findTagHash。

##### 版本回退

注意了回退版本并不是删除了最新的版本，仅仅只是回退！

回退一个版本：HEAD，回退上上版本：HEAD，表示回退版本的个数，若是回退到第100个：HEAD~100

git reset：重置暂存区的文件与某次提交(commit)保持一致，工作区文件内容保持不变。(主要用于提交有误时进行悔步，工作区与暂存区保持不变，可进行重新提交)。

git reset --hard：重置暂存区与工作区与指定commit保持一致。

**方式一**(根据指定数量回退)：

- git reset --hard <指定回退哪个版本>：回退指定数量版本，例如回退一个版本git reset --hard HEAD~

**方式二**(根据提交哈希回退)：建议先使用git log --pretty=oneline来查看所有提交记录其中包含哈希值

- git reset --hard <提交哈希>：通过哈希值来进行回退，哈希值只需要部分即可。

说明：使用提交哈希还可以回到未来版本，意思就是我可以回到过去也可以回到将来只需要有该提交哈希即可。

注意注意(重点)：若是你回到过去了想要回到以前的最新的版本，单单使用git log --pretty=oneline是查看不到

之前最新的版本的，只能查看到当前回退时的最高版本；想要查看所有的记录包含以前最新的使用git reflog命

令查看获取到提交哈希！！！

