# C++案例试炼：机房预约系统

- [CSDN文章解释地址](https://zhiqianghe.blog.csdn.net/article/details/108700890)

&emsp;&emsp;机房预约系统需求：学校存在几个机房，但是由于大家使用的时间基本都是一样的，所以需要设计一个预约系统来解决这一问题。

## 身份简介

&emsp;&emsp;在这个系统中会有三类人用到这个机房。

1. **学生**：申请使用机房。
2. **教师**：审核学生的预约申请。
3. **管理员**：给学生、教师创建账号。

## 机房简介

&emsp;&emsp;机房总共有`3`间：

1. `1`号机房：最大容量`20`人。
2. `2`号机房：最多容量`50`人。
3. `3`号机房：最多容量`100`人。

## 申请简介

- 每周由管理员清空一次申请订单。所以管理员需要给它提供一个清空的能力。
- 学生可以预约未来一周内的机房使用，预约日期为周一至周五，预约时需要选择预约时段(上午、下午)。
- 老师来审核预约，依据实际情况审核预约通过或者不通过。

## 系统具体需求

### 主界面展示

- **首先进入系统登录界面，可选登录身份有**：

1. 学生
2. 老师
3. 管理员
4. 退出

### 各子菜单展示

- **每一个身份都需要进行验证之后，才能进入子菜单**：

1. 学生需要输入：学号、姓名、登录密码。
2. 老师需要输入：职工号、姓名、登录密码。
3. 管理员需要输入：管理员姓名、登录密码。

#### 学生

- **学生的具体功能**：

1. 申请预约。
2. 查看自己的预约状态。
3. 查看全部预约信息以及预约状态。
4. 取消自身的预约，预约成功或审核中的预约均可取消。
5. 注销登录。

#### 老师

- **教师具体功能**：

1. 查看全部预约信息以及预约状态。
2. 对学生的预约进行审核。
3. 注销登录。

#### 管理员

- **管理员具体功能**：

1. 添加学生或教师的账号，需要检测学生编号或教师职工号是否重复。
2. 可以选择查看学生或教师的全部信息。
3. 查看所有机房的信息。
4. 清空所有机房的信息。
5. 清空所有预约记录。
6. 退出登录。
