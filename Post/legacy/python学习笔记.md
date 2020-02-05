

1. 查看该库文件里的所有函数

    查看某个类型的所有方法

   ```python
	   >>> import math
   >>> dir(math)
   ['__doc__', '__loader__', '__name__', '__package__', '__spec__', 'acos', 'acosh', 'asin', 'asinh', 'atan', 'atan2', 'atanh', 'ceil', 'copysign', 'cos', 'cosh', 'degrees', 'e', 'erf', 'erfc', 'exp', 'expm1', 'fabs', 'factorial', 'floor', 'fmod', 'frexp', 'fsum', 'gamma', 'gcd', 'hypot', 'inf', 'isclose', 'isfinite', 'isinf', 'isnan', 'ldexp', 'lgamma', 'log', 'log10', 'log1p', 'log2', 'modf', 'nan', 'pi', 'pow', 'radians', 'sin', 'sinh', 'sqrt', 'tan', 'tanh', 'trunc']
   >>> dir(str)
   ['__add__', '__class__', '__contains__', '__delattr__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__getitem__', '__getnewargs__', '__gt__', '__hash__', '__init__', '__iter__', '__le__', '__len__', '__lt__', '__mod__', '__mul__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__rmod__', '__rmul__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', 'capitalize', 'casefold', 'center', 'count', 'encode', 'endswith', 'expandtabs', 'find', 'format', 'format_map', 'index', 'isalnum', 'isalpha', 'isdecimal', 'isdigit', 'isidentifier', 'islower', 'isnumeric', 'isprintable', 'isspace', 'istitle', 'isupper', 'join', 'ljust', 'lower', 'lstrip', 'maketrans', 'partition', 'replace', 'rfind', 'rindex', 'rjust', 'rpartition', 'rsplit', 'rstrip', 'split', 'splitlines', 'startswith', 'strip', 'swapcase', 'title', 'translate', 'upper', 'zfill']
   ```

2. `help([函数])`  # 查看函数的帮助文档

3. math库: 各种数学函数

   用法: `import math`

4. ** 运算符: 乘方

5. 四舍五入: 

   ```python
   >>> round(1.234)
   1.0
   >>> round(1.234, 2)
   1.23
   ```

6. 强制类型转换

   (1).  `str()` 转换为字符串

   (2).  `int()` 转换为整型

7. 打印字符串时在前面加`r`禁止转义

   ```python
   >>> print("c:\new")
   c:
   ew
   >>> print(r"c:\new")
   c:\new
   ```

8. 字符串索引

   ```python
   >>> str = "test"
   >>> str[0]
   't'
   >>> "test"[0]
   't'
   >>> str.index("t") # 反索引
   0
   >>> "test".index("t")
   0
   ```

9. 字符串切片

   ```python
   >>> str = "test"
   >>> str[1:1]
   ''
   >>> str[1:3] # 切片中的[i:j]指的是字符串中的第[i, j), 为左闭右开区间
   'es'
   >>> str[0:] # 从0切到尾
   'test'
   >>> str[: 3] # 3以前的所有字符
   'tes'
   ```

10. 查看对象/变量的地址:

  ```python
  >>> id(233)
  6348814630
  ```

11. `in` 运算符的使用:

    ```python
    >>> "a" in "ask"
    True
    ```

12.  `ord()` 获取字符ASCII码

     `chr()` ASCII码转字符

    ​```python
    >>> ord('a')
    97
    >>> chr(97)
    'a'
    ​```

13.  字符串乘法`*`运算:

    ```python
    >>> 'a' * 20
    'aaaaaaaaaaaaaaaaaaaa'
    ```

14.  `len()` 获取字符串长度函数

    ```python
    >>> len("abcde")
    5
    ```

15. 字符串格式化输出的两种方法

    ```python
    >>> print("My name is {0}. Are you {1}?".format("lym", "mike"))
    My name is lym. Are you mike?
    >>> print("My name is %s. Are you %s?" % ("lym", "mike"))
    My name is lym. Are you mike?
    ```

16.   根据分割符分割字符串 `split()`

    ```python
    >>> "I love python!".split(" ")
    ['I', 'love', 'python!']
    ```

17.   去掉字符串两边空格

    - `S.strip()`：去掉字符串的左右空格
    - `S.lstrip()`：去掉字符串的左边空格
    - `S.rstrip()`：去掉字符串的右边空格

18.   用`.join()` 拼接字符串

    ```python
    >>> b = 'www.itdiffer.com'
    >>> c = b.split(".")
    >>> c 
    ['www', 'itdiffer', 'com']
    >>> ".".join(c)
    'www.itdiffer.com'
    >>> "*".join(c)
    'www*itdiffer*com'
    ```

19.   list 或 str 反转

    ```python
    >>> "233"[::-1]
    '332'
    ```

20.  list 中追加元素

    ```python
    >>> a = list([1, 2])
    >>> a
    [1, 2]
    >>> a.append(3)
    >>> a
    [1, 2, 3]
    >>> a[len(a):] = [4]
    >>> a
    [1, 2, 3, 4]
    ```

21.  `range()` 函数

    用于生成一个递增的整数列表

    可用于`for循环`

    ```python
    >>> range(2, 5)
    range(2, 5)
    >>> list(range(2, 5))
    [2, 3, 4]
    >>> list(range(2, 5, 2))
    [2, 4]
    >>> for i in range(5):
    ...     print(i, end=' ')
    ... 
    0 1 2 3 4
    ```

22.   文件读写

    ```python
    # 打开文件
    >>> f = open('130.txt')
    >>> for line in f:
    ...     print(line, end='')
    ... 
    learn python
    http://qiwsir.github.io
    qiwsir@gmail.com
    # 写入/新建文件
    >>> nf = open("131.txt", "w")
    >>> nf.write("test")
    >>> nf.close()
    ```

    |  模式  |                    描述                    |
    | :--: | :--------------------------------------: |
    |  r   |            以读方式打开文件，可读取文件信息。             |
    |  w   |  以写方式打开文件，可向文件写入信息。如文件存在，则清空该文件，再写入新内容   |
    |  a   | 以追加模式打开文件（即一打开文件，文件指针自动移到文件末尾），如果文件不存在则创建 |
    |  r+  |          以读写方式打开文件，可对文件进行读和写操作。          |
    |  w+  |           消除文件内容，然后以读写方式打开文件。            |
    |  a+  |          以读写方式打开文件，并把文件指针移到文件尾。          |
    |  b   | 以二进制模式打开文件，而不是以文本模式。该模式只对Windows或Dos有效，类Unix的文件是用二进制模式进行操作的。 |
    **"w":以写方式打开文件，可向文件写入信息。如文件存在，则清空该文件，再写入新内容**

    记得及时使用`.close()`关闭文件

23.   使用with以使用文件

    ```python
    >>> with open("130.txt","r") as f:
    ...     print f.read()
    ... 
    ```

24.  ​
