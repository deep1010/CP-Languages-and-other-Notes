Important Links
---------------

-   [Cheat Sheet Link](https://www.youtube.com/redirect?redir_token=p8abjyBFF8T0GhzcO0Dxz2rhW7x8MTU4MTY4NTg2MEAxNTgxNTk5NDYw&q=http%3A%2F%2Fgoo.gl%2FO1CuGM&v=DzFt0YkZo8M&event=video_description)
-   [Tutorial Video](https://www.youtube.com/watch?v=DzFt0YkZo8M)

Declaring Variables
-------------------

-   while declaring variables use `var` to make them mutable and use `val` to make them immutable.
-   Generally while declaring them you do not need to mention data type. Scala does it automatically. but in case if you explicitly want to mention it,<br>
``` scala
    val: <datatype> variableName = initialValue
```
- ternary operator<br>
``` scala
    val x = if (a < b) a else b
```

Data Types 
----------
 
-   All datatypes in Scala are objects and they include
-   (Get the max value with MaxValue)
-   Byte : -128 to 127
-   Boolean : true or false
-   Char : unsigned max value 65535
-   Short : -32768 to 32767
-   Int : -2147483648 to 2147483647
-   Long : -9223372036854775808 to 9223372036854775807
-   Float : -3.4028235E38 to 3.4028235E38
-   Double : -1.7976931348623157E308 to 1.7976931348623157E308

Manipulating Values
-------------------

-   ++ and -- is not allowed in scala. rather use += or -= respectively.

Importing libraries
-------------------

-   `import scala.(library location)._` &nbsp;&nbsp;&nbsp; _ is equivalent to * in python for import math.*

Boilerplate for initializing
----------------------------

``` scala
object FileName{
    def main(args: Array[Strings]){

        /*
        your code here!
        */
    }
}
```

Loops in Scala
--------------

-   while loop <br>
    ``` scala
    while(condition)
    {
        /*
        do something
        */
    }
    ```

-   do while loop <br>
    ``` scala
    do
    {
        /*
        do something
        */
    } while(condition)
    ```

-   for loop <br>
``` scala
    var i;
    for(i<-1 to 10)
    {
        println(i);
    }
```
<br>check cheat sheet for printing elements from the list, nested loop, etc!

-   there is no break statement in scala.

Taking Input
------------

-   var userInput = readLine readInt readChar readByte readLong etc..   