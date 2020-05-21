Go Lang<br/> Beginner Notes
===========================


Compiling and Running
---------------------
-   **`go build filename.go`** to compile a file and convert to executable file just like g++ or gcc
-   **`go run filename.go`** to directly run the file without compiling it.  This command combines both the compilation and execution of code for us. This allows us to quickly check the output of our code (and for any errors) along with saving time. It does not create a executable binary file. 

------
Import
------

-   To import one or more packages use the following command
    ``` go
    import "package1"
    import "package2"
    import "package3"
    ```
    **OR**
    ``` go
    import (
        "package1"
        "package2"
        "package3"
    )
    ```
-   [Link](https://golang.org/pkg/) to standard Go lang libraries.

------------------------
Variables and Data Types
------------------------

>   **Data Types:**

-   string
-   bool
-   numeric types:
    -   int8, uint8, int16, uint16, int32 , uint32, int64, uint64, int, uint, uintptr, float32, float64, complex64, complex128

>   **Declaring Variables**

Different ways to declare variables are as follows
``` go
// var variableName Datatype
var numberOfMonths int8

// var variableName Datatype = initialValue
var numberOfMonths int8 = 12

// var variableName = initialValue
var numberOfMonths = 12

// variableName := initialValue
numberOfMonths := 12

// Multiple Declarations

// var varName1, varName2 .. ,varNameN Datatype
// If we’re using this syntax, both variables must be the same type.
var part1, part2 string
part1 = "some string"
part2 = "some string"

// varName1, varName2 := value1, value2
// Here they need not be the same dataType.
part1,part2 := "string here", 123.34

```

>   **Strings**

-   To **initialize** or store value for **string** dataType always use **double quotes " "**.
-   stringVar1 + stringVar2 to concatenate two string variables.

>   **Notes**

-   **Declaring a variable** or importing a package and **not using** it will give **error**.
-   Default values of variables when initialized without values<br><br>
    
    | dataType | Value             |
    |----------|-------------------|
    | int      | 0                 |
    | string   | "" (empty string) |
    | boolean  | false             |

--------
Resources
---------

-   [Go Lang CheatSheet Codecademy](https://www.codecademy.com/learn/learn-go/modules/learn-go-introduction/cheatsheet)