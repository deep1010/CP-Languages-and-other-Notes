# Java String Manipulation

This document combines:
- Core Java String operations
- `StringBuilder` / `StringBuffer`
- Time & space complexity notes
- A condensed reference of Java String methods

---

## 1. Creating Strings

### 1.1 String Literal
```java
String s = "Hello";
```
- Stored in String Constant Pool
- Immutable

### 1.2 Using `new`
```java
String s = new String("Hello");
```
- Creates a new heap object
- Rarely needed

---

## 2. Length & Character Access

```java
String s = "Java";

int len = s.length();   // 4
char c = s.charAt(1);   // 'a'
```

---

## 3. String Comparison

### equals()
```java
"abc".equals("abc"); // true
```

### equalsIgnoreCase()
```java
"Java".equalsIgnoreCase("JAVA"); // true
```

### `==` (Avoid ❌)
```java
// compares references, not content
```

---

## 4. Case Conversion

```java
String s = "HeLLo";

s.toUpperCase(); // "HELLO"
s.toLowerCase(); // "hello"
```

---

## 5. Prefix & Suffix Checks

```java
String s = "HackerRank";

s.startsWith("Hack"); // true
s.endsWith("Rank");   // true
```

---

## 6. Searching in Strings

### indexOf() – FIRST occurrence
```java
String s = "banana";

s.indexOf('a');     // 1
s.indexOf("na");    // 2
```

### lastIndexOf()
```java
s.lastIndexOf("na"); // 4
```

### contains()
```java
"Java Programming".contains("Java"); // true
```

---

## 7. Substring

```java
String s = "HackerRank";

s.substring(0, 6); // "Hacker"
s.substring(6);    // "Rank"
```

> End index is **exclusive**

---

## 8. Replace Operations

```java
"apple".replace('p', 'b');             // "abble"
"I love Java".replace("Java", "C++");  // "I love C++"
```

---

## 9. Trim & Whitespace

```java
"   hello   ".trim(); // "hello"
```

---

## 10. Split & Join

### split()
```java
String s = "a,b,c";
String[] arr = s.split(",");
```

### join()
```java
String date = String.join("-", "2026", "01", "26");
// "2026-01-26"
```

---

## 11. String Immutability (VERY IMPORTANT)

```java
String s = "Hello";
s.concat(" World");

System.out.println(s); // "Hello"
```

---

## 12. StringBuilder (Mutable & Fast)

```java
StringBuilder sb = new StringBuilder("Hello");

sb.append(" World");
sb.insert(5, ",");
sb.delete(5, 6);
sb.reverse();

String result = sb.toString();
```

---

## 13. StringBuffer (Thread-Safe)

```java
StringBuffer sb = new StringBuffer("Hello");
sb.append(" World");
```

---

## 14. String vs StringBuilder vs StringBuffer

| Feature | String | StringBuilder | StringBuffer |
|------|------|------|------|
| Mutable | ❌ | ✅ | ✅ |
| Thread Safe | ❌ | ❌ | ✅ |
| Performance | Slow | Fast | Medium |

---

## 15. Common Interview Patterns

### Reverse a String
```java
String s = "abc";
String rev = new StringBuilder(s).reverse().toString();
```

### Palindrome Check
```java
String s = "madam";
boolean isPal = s.equals(
    new StringBuilder(s).reverse().toString()
);
```

### Count Character Frequency
```java
Map<Character, Integer> map = new HashMap<>();

for (char c : s.toCharArray()) {
    map.put(c, map.getOrDefault(c, 0) + 1);
}
```

---

## 16. Null & Empty Check (CRUCIAL)

```java
if (s == null || s.isEmpty()) {
    // handle case
}
```

---

## 17. Conversions

### To String
```java
int x = 10;

String a = String.valueOf(x);
String b = Integer.toString(x);
```

### To char[]
```java
char[] arr = "Java".toCharArray();
```

---

## 18. Java String Method Reference (Condensed)

### Character & Unicode
- `charAt(int index)`
- `codePointAt(int index)`
- `codePointBefore(int index)`
- `codePointCount(int begin, int end)`

### Comparison
- `equals(Object o)`
- `equalsIgnoreCase(String s)`
- `compareTo(String s)`
- `compareToIgnoreCase(String s)`
- `contentEquals(CharSequence cs)`

### Searching
- `contains(CharSequence s)`
- `indexOf(String s)`
- `indexOf(String s, int fromIndex)`
- `lastIndexOf(String s)`
- `matches(String regex)`

### Modification (Returns new String)
- `concat(String s)`
- `replace(char a, char b)`
- `replace(CharSequence a, CharSequence b)`
- `substring(int begin)`
- `substring(int begin, int end)`
- `trim()`
- `toUpperCase()`
- `toLowerCase()`

### Conversion
- `toCharArray()`
- `getBytes()`
- `valueOf(anyType)`
- `split(String regex)`
- `format(String format, Object... args)`

### Utility
- `length()`
- `isEmpty()`
- `startsWith(String prefix)`
- `endsWith(String suffix)`
- `hashCode()`
- `intern()`

---

## 19. Time & Space Complexity (Interview Gold)

| Operation | Time |
|---------|------|
| charAt | O(1) |
| equals | O(n) |
| substring | O(n) |
| replace | O(n) |
| concat (String) | O(n) |
| append (StringBuilder) | O(1) amortized |

---

## 20. HackerRank-Style Practice

### Find All Substrings
```java
for (int i = 0; i < s.length(); i++) {
    for (int j = i + 1; j <= s.length(); j++) {
        System.out.println(s.substring(i, j));
    }
}
```

### Count Vowels
```java
int count = 0;
for (char c : s.toLowerCase().toCharArray()) {
    if ("aeiou".indexOf(c) != -1) count++;
}
```

---

## 21. 1-Page Interview Cheat Sheet

- ❌ Never use `==` for strings
- ✅ Use `equals()` / `equalsIgnoreCase()`
- ❗ Strings are immutable
- 🚀 Use `StringBuilder` in loops
- ⚠ Always handle `null`
- ⭐ `indexOf()` → first occurrence
- ⭐ `lastIndexOf()` → last occurrence

---

## Final Advice

If you master everything in this file, you are **fully covered for 90–95% of Java
string interview questions**.

---
```

---

If you want next, I can:
- 📌 Turn this into a **printable 2-page PDF**
- 🧪 Add **50+ string interview questions with answers**
- ⚡ Create a **HackerRank boilerplate template**

Just say the word 😄