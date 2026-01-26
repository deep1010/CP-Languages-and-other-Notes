
# Java JSON Parsing & Manipulation

This guide focuses on **practical JSON parsing and manipulation in Java**

---

## 1. JSON Libraries Commonly Available

Most HackerRank Java environments allow:

```java
import org.json.JSONObject;
import org.json.JSONArray;
```

Always assume `org.json` is available, but be prepared for **manual parsing fallback**.

---

## 2. Creating JSON Objects

### From String

```java
String json = "{\"name\":\"John\",\"age\":30}";
JSONObject obj = new JSONObject(json);
```

### From Scratch

```java
JSONObject obj = new JSONObject();
obj.put("name", "Alice");
obj.put("age", 25);
```

---

## 3. Accessing JSON Fields

### Required fields (throws exception if missing)

```java
String name = obj.getString("name");
int age = obj.getInt("age");
boolean active = obj.getBoolean("active");
```

### Optional / Safe access (preferred)

```java
String city = obj.optString("city", "NA");
int score = obj.optInt("score", 0);
```

---

## 4. Checking Key Existence

```java
if (obj.has("email")) {
    String email = obj.getString("email");
}
```

---

## 5. Working with JSON Arrays

### Parse Array

```java
String json = "[{\"id\":1},{\"id\":2}]";
JSONArray arr = new JSONArray(json);
```

### Iterate Array

```java
for (int i = 0; i < arr.length(); i++) {
    JSONObject o = arr.getJSONObject(i);
    int id = o.getInt("id");
}
```

### Array of primitives

```java
JSONArray nums = new JSONArray("[1,2,3]");
int first = nums.getInt(0);
```

---

## 6. Nested JSON Parsing (Very Common)

### JSON

```json
{
  "user": {
    "name": "Bob",
    "skills": ["Java", "SQL"]
  }
}
```

### Java

```java
JSONObject root = new JSONObject(json);
JSONObject user = root.getJSONObject("user");

String name = user.getString("name");

JSONArray skills = user.getJSONArray("skills");
String firstSkill = skills.getString(0);
```

---

## 7. Iterating Over Keys

```java
Iterator<String> keys = obj.keys();

while (keys.hasNext()) {
    String key = keys.next();
    Object value = obj.get(key);
}
```

Useful when JSON structure is dynamic.

---

## 8. Modifying JSON

### Add / Update

```java
obj.put("age", 31);
```

### Remove

```java
obj.remove("city");
```

---

## 9. Convert JSON Back to String

```java
String compact = obj.toString();
String pretty = obj.toString(2);
```

---

## 10. Common HackerRank Patterns

### Filter array by condition

```java
for (int i = 0; i < arr.length(); i++) {
    JSONObject o = arr.getJSONObject(i);
    if (o.getInt("score") > 50) {
        // process
    }
}
```

### Sum values

```java
int sum = 0;
for (int i = 0; i < arr.length(); i++) {
    sum += arr.getInt(i);
}
```

---

## 11. Reading JSON Input from STDIN (CRITICAL)

HackerRank often provides JSON across **multiple lines**.

```java
Scanner sc = new Scanner(System.in);
StringBuilder sb = new StringBuilder();

while (sc.hasNextLine()) {
    sb.append(sc.nextLine());
}

String json = sb.toString();
```

Never assume single-line input.

---

## 12. Exception Handling

```java
try {
    JSONObject obj = new JSONObject(json);
} catch (Exception e) {
    // malformed JSON
}
```



