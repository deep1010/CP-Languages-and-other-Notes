# Java Collections Cheat Sheet – ArrayList, HashMap, HashSet

---

# 1. ArrayList

## 1.1 Import & Declaration

```java
import java.util.ArrayList;
import java.util.List;

List<Integer> list = new ArrayList<>();
```

Note: int,char,bool are not supported, need to use Integer,Char,Boolean

---

## 1.2 Adding Elements

```java
list.add(10);
list.add(20);
list.add(1, 15); // insert at index
```

---

## 1.3 Accessing Elements

```java
int x = list.get(0);
int size = list.size();
```

⚠️ `get()` throws `IndexOutOfBoundsException` if index invalid.

---

## 1.4 Updating Elements

```java
list.set(1, 99);
```

---

## 1.5 Removing Elements

```java
list.remove(0);              // by index
list.remove(Integer.valueOf(10)); // by value
```

⚠️ Be careful: `remove(int)` vs `remove(Object)`

---

## 1.6 Iteration Patterns

### Index-based loop

```java
for (int i = 0; i < list.size(); i++) {
    System.out.println(list.get(i));
}
```

### Enhanced for-loop

```java
for (int x : list) {
    System.out.println(x);
}
```

### Iterator (safe removal)

```java
Iterator<Integer> it = list.iterator();
while (it.hasNext()) {
    if (it.next() == 10) {
        it.remove();
    }
}
```

---

## 1.7 Sorting ArrayList

```java
Collections.sort(list);                 // ascending
Collections.sort(list, Collections.reverseOrder()); // descending

// for custom sorting
Collections.sort(list, (a, b) -> a comes before b ? negative : positive);
```

---

## 1.8 Common Interview Patterns (ArrayList)

### Sum of elements

```java
int sum = 0;
for (int x : list) sum += x;
```

### Remove duplicates

```java
list = new ArrayList<>(new HashSet<>(list));
```

---

# 2. HashMap

## 2.1 Import & Declaration

```java
import java.util.HashMap;
import java.util.Map;

Map<String, Integer> map = new HashMap<>();
```

---

## 2.2 Put & Get

```java
map.put("a", 1);
map.put("b", 2);

int val = map.get("a");           // returns null if missing
int safe = map.getOrDefault("c", 0);
```

---

## 2.3 Check Key / Value Existence

```java
map.containsKey("a");
map.containsValue(2);
```

---

## 2.4 Remove Elements

```java
map.remove("a");
```

---

## 2.5 Iterating HashMap (VERY IMPORTANT)

### Iterate keys

```java
for (String key : map.keySet()) {
    System.out.println(key + " " + map.get(key));
}
```

### Iterate values

```java
for (int val : map.values()) {
    System.out.println(val);
}
```

### Iterate entries (BEST)

```java
for (Map.Entry<String, Integer> e : map.entrySet()) {
    System.out.println(e.getKey() + " " + e.getValue());
}
```

---

## 2.6 Common HashMap Interview Patterns

### Frequency count

```java
for (int x : arr) {
    map.put(x, map.getOrDefault(x, 0) + 1);
}
```

### Find max frequency

```java
int max = 0;
for (int val : map.values()) {
    max = Math.max(max, val);
}
```

---

## 2.7 HashMap Gotchas

* No guaranteed order
* `get()` can return `null`
* Keys must be **unique**
* `HashMap` is **not thread-safe**

---

# 3. HashSet

## 3.1 Import & Declaration

```java
import java.util.HashSet;
import java.util.Set;

Set<Integer> set = new HashSet<>();
```

---

## 3.2 Add & Remove

```java
set.add(10);
set.add(20);
set.add(10); // ignored (no duplicates)

set.remove(20);
```

---

## 3.3 Check Existence

```java
set.contains(10);
```

---

## 3.4 Iterate HashSet

```java
for (int x : set) {
    System.out.println(x);
}
```

⚠️ Order is NOT guaranteed.

---

## 3.5 Common HashSet Interview Patterns

### Remove duplicates from array

```java
Set<Integer> set = new HashSet<>();
for (int x : arr) set.add(x);
```

### Detect duplicates

```java
if (!set.add(x)) {
    // duplicate found
}
```

### Intersection of two arrays

```java
set.retainAll(otherSet);
```

---

# 4. When to Use What (INTERVIEW GOLD)

| Requirement         | Best Choice |
| ------------------- | ----------- |
| Fast random access  | ArrayList   |
| Key-value mapping   | HashMap     |
| Unique elements     | HashSet     |
| Frequency counting  | HashMap     |
| Duplicate detection | HashSet     |
| Ordered insertion   | ArrayList   |

---

# 5. Time Complexity (Must Remember)

| Operation | ArrayList | HashMap | HashSet |
| --------- | --------- | ------- | ------- |
| Add       | O(1)*     | O(1)    | O(1)    |
| Remove    | O(n)      | O(1)    | O(1)    |
| Search    | O(n)      | O(1)    | O(1)    |

\* - Amortized

