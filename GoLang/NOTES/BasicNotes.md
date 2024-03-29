Go Lang<br/> Beginner Notes
===========================

---------------------
COMPILING AND RUNNING
---------------------
-   **`go build filename.go`** to compile a file and convert to executable file just like g++ or gcc
-   **`go run filename.go`** to directly run the file without compiling it.  This command combines both the compilation and execution of code for us. This allows us to quickly check the output of our code (and for any errors) along with saving time. It does not create a executable binary file.

------
IMPORT
------

-   To import one or more packages use the following command
``` go
import "package1"
import "package2"
import "package3"
// OR
import (
	"package1"
	"package2"
	"package3"
)
```
-   [Link](https://golang.org/pkg/) to standard Go lang libraries.

------------------------
VARIABLES AND DATA TYPES
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
-   Default values of variables when initialized without values

| dataType | Value             |
|----------|-------------------|
| int      | 0                 |
| string   | "" (empty string) |
| boolean  | false             |

-------------
PACKAGE "fmt"
-------------

>   **fmt.Println()**

-   Prints to the terminal.
-   Prints its *arguments* with an included space in between each argument and adds a line break at the end.

>   **fmt.Print()**

-   Prints to the terminal.
-   Prints its *arguments* without any space in between each argument and without adding a line break at the end.

>   **fmt.Printf()**

-   Use it to Interpolate strings, or leave placeholders in a string and use values to fill in the placeholders.<br/> Example

``` go
guess := "C"
fmt.Printf("Is %v your final answer?", guess)
// Prints: Is C your final answer?
// multiple placeholder in a single print
animal1 := "cat"
animal2 := "dog"
fmt.Printf("Are you a %v or a %v person?",animal1, animal2)
```

-   Different placeholders and use.

| Placeholder | Meaning                              |
|-------------|--------------------------------------|
| %v          | value in default format              |
| %T          | Data-Type (typeof() in python)       |
| %t          | boolean                              |
| %d          | int with base 10                     |
| %f or %F    | float                                |
| %.nf        | print n decimal places of float value|
| %s          | string                               |
| %q          | string with " .. "                   |

-   [Link](https://golang.org/pkg/fmt/#hdr-Printing) to detailed explanation of all placeholders

>   **fmt.Sprintf() fmt.Sprint() fmt.Sprintln()**

-   Same as fmt.Printf() fmt.Print() fmt.Println() respectively. only difference it returns the final modified/computed string rather than printing it.

``` go
// Sprintf
template := "I wish I had a %v."
pet := "puppy"

var wish string
wish = fmt.Sprintf(template,pet)

fmt.Println(wish)
```

>   **fmt.Scan()**

-   similar to cin (c++)
	-   only one variable at a time.
	-   everything after space is ignored.

		examples:
		``` go
		var response string
		fmt.Scan(&response)

		fmt.Printf("I'm %v.", response)
		// if the input is "firstName secondName"
		// It will only print firstName.

		// to scan both of them
		var response1 string
		var response2 string
		fmt.Scan(&response1)
		fmt.Scan(&response2)

		fmt.Printf("I'm %v %v", response1, response2)
		```

------------
CONDITIONALS
------------
>   **If - else if - else**

``` go

if condition1 {
	fmt.Println("Do something 1")
} else if condition2 {
	fmt.Println("Do something 2")
} else if condition3 {
	fmt.Println("Do something 3")
} else {
	fmt.Println("Do something 4")
}
```
-   else/else if statement must be in the same line as previous condition's terminating '}' bracket.

>   **Switch Statement**

``` go
clothingChoice := "sweater"

switch clothingChoice {
case "shirt":
	fmt.Println("We have shirts in S and M only.")
case "polos":
	fmt.Println("We have polos in M, L, and XL.")
case "sweater":
	fmt.Println("We have sweaters in S, M, L, and XL.")
case "jackets":
	fmt.Println("We have jackets in all sizes.")
default:
	fmt.Println("Sorry, we don't carry that")
}
```
>   **Scoped Short Declaration Statement**

-   We can also include a short variable declaration before we provide a condition in either if or switch statments. Here’s the syntax:

``` go
x := 8
y := 9
if product := x * y; product > 60 {
	fmt.Println(product, "  is greater than 60")
}
```
-   One thing to keep in mind when using the short variable declaration in **`if or switch statements`** is that the declared variable is ***scoped*** to the statement blocks.

>   **Comparators**

-   same as c++ (== != < > <= >= && || !)



---------
FUNCTIONS
---------

>   **Format and Examples**
-	Return a single value

``` go
// func funcName (argName1 argType1 , argName2 argType2 .... , argNameN argTypeN) returnType {
// 	your code here
// }
//examples
func summonNicole() {
fmt.Println("Hey Nicole, get over here!")
}

func doubleNum(num int) int {
return num * 2
}

func getLengthOfCentralPark() int32 {
var lengthInBlocks int32
lengthInBlocks = 51
return lengthInBlocks
}

func multiplier(x int32, y int32) int32 {
return x * y
}
```

-	Return multiple Values

``` go
// Declaring Function
// func funcName (argName1 argType1 , argName2 argType2 .... , argNameN argTypeN) 
// (returnType1, returnType2, ... , returnTypeM) {
// 	your code here
//	return value1, value2, ... , valueM
// }
//examples
func GPA(midtermGrade float32, finalGrade float32) (string, float32) {
averageGrade := (midtermGrade + finalGrade) / 2
var gradeLetter string
if averageGrade > 90 {
	gradeLetter = "A"
} else if averageGrade > 80 {
	gradeLetter = "B"
} else if averageGrade > 70 {
	gradeLetter = "C"
} else if averageGrade > 60 {
	gradeLetter = "D"
} else {
	gradeLetter = "F"
}

return gradeLetter, averageGrade 
}

// How to call it
value1, value2 = GPA(89.4 , 79.5)
```

-	**`Defer`** a function:
-	If the keyword `defer` is added before any line, then that line is executed at the end of function only i.e. while exiting or returning the function.
-	Multiple defer can be executed. They will be executed it reverse order of occurrence in code i.e LIFO or STACK

-	**Example :**

``` go
package main
import "fmt"

func queryDatabase(query string) string {
var result string
connectDatabase()
// Add deferred call to disconnectDatabase() here
defer disconnectDatabase()
defer connectDatabase()
if query == "SELECT * FROM coolTable;" {
	result = "NAME|DOB\nVincent Van Gogh|March 30, 1853"
}  
fmt.Println(result)
return result
}

func connectDatabase() {
fmt.Println("Connecting to the database.")
}

func disconnectDatabase() {
fmt.Println("Disconnecting from the database.")
}

func main() {
queryDatabase("SELECT * FROM coolTable;")
}
```

-	**Output of above code :**

```
Connecting to the database.
NAME|DOB
Vincent Van Gogh|March 30, 1853
Connecting to the database.
Disconnecting from the database.
```

----------------------
ADDRESSES AND POINTERS
----------------------

-	Accessing address of a variable and pointer to a variable is same as c++.

``` go
// accessing the pointer
var pointerToVar *varDataType

// accessing and storing the address 
pointerToVar = &varName

// updating value using pointer
*pointerToVar = newVarValue
```

-----------------
PASS-BY-REFERENCE
-----------------

-	Here is an example for pass by reference in GoLang

``` go
func addHundred (numPtr *int) {
  *numPtr += 100
}

func main() {
  x := 1
  addHundred(&x)
  fmt.Println(x) // Prints 101
}
```

---------
RESOURCES
---------

-   [Go Lang CheatSheet Codecademy](https://www.codecademy.com/learn/learn-go/modules/learn-go-introduction/cheatsheet)