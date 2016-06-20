# Coding Standard

## 1. Identation, Code Formatting, Editor Settings

### 1.1 Identation Rules

##### Ident.1 Spaces should be used everywhere as indentation symbol. Spaces not tabs!

##### Ident.2  Use 4 spaces to indent code.

``` cpp
{
    // code line 1
    // code line 2
    {
        // inner block
        // 
    }
}

```

##### Ident.3 One indent should be placed before new line.

``` cpp
if (longExpression
    + otherLongExpression
    + otherOtherLongExpression)
{
}
```

### 1.2 Line breaks

##### Breaks.1 Keep lines shorter than 100 characters; insert line breaks if necessary.

##### Breaks.2 Operators start at the beginning of the new line.
```cpp
if (longExpression
    + otherLongExpression
    + otherOtherLongExpression)
{
}
```

### 1.3 Whitespaces

##### Spaces.1 Always use blank lines to group statements together where suited. Always use only one blank line.

##### Spaces.2 Always use a single space after a keyword, and before a curly brace.
```cpp
if (foo)
{
}
```

##### Spaces.3 For pointers or references, always use a single space between the type and * or &, but no space between the * or & and the variable name.

##### Spaces.4 No space is allowed between return type and * or & in function/method definitions/declarations.

##### Spaces.5 No space is allowed between function/method name and braces in function/method definitions/declarations/call.

```cpp
const char* ch;
const void *const someConstant;
std::string &str = someString;
char* func1();
```

##### Spaces.6 No space after a cast.

```cpp
char *blockOfMemory = reinterpret_cast<char*>(malloc(data.size()));
```


#### 1.4 Braces

##### Braces.1 Always use a new line for open/closed curly brace
```cpp
if (foo)
{
}
```

##### Braces.2 Always use curly braces with conditional statements, even if it contains only one line.
```cpp
// Wrong
if (address.isEmpty())
return false;
 
// Wrong
for (int i = 0; i < 10; ++i) qDebug("%i", i);
 
// Correct
if (address.isEmpty())
{
    return false;
}
```


### 1.5 IDE Editor Settings

##### IDE.1 Make Qt Creator follow identation rules. Use editor settings. Recommended settings see below.

``` ini
[%General]
DefaultFileEncoding=@ByteArray(UTF-8)
 
[textMarginSettings]
MarginColumn=100
ShowMargin=true
 
[textStorageSettings]
addFinalNewLine=true
cleanIndentation=true
cleanWhitespace=true
inEntireDocument=true
 
[textTabPreferences]
AutoSpacesForTabs=false
IndentSize=4
PaddingMode=1
SpacesForTabs=true
TabSize=4
 
[textTypingSettings]
AutoIndent=true
SmartBackspaceBehavior=1
TabKeyBehavior=0
```

## 2. Statements, Expressions, Operations

### 2.1 Expressions

##### Expr.1 Use parentheses to group expressions.

```cpp
// Wrong
if (a && b || c)
 
// Wrong
a + b & c
 
// Correct
if ((a && b) || c)
 
// Correct
(a + b) & c
```

### 2.2 Statements


##### Stat.1 The case labels are on the same column as the switch.

##### Stat.2 Every case block has identation. break or return should have same identation as case block.

##### Stat.3 Every case must have a break (or return) statement at the end or a comment to indicate that there’s intentionally no break.
   ```cpp
switch (myEnum)
{
case Value1:
    doSomething();
    break;
 
case Value2:
    // nothing
    break;
 
default:
    defaultHandling();
    break;
}
```

## 3 Types, Variables, Declatation and Initialization

### 3.1 Variable and Type Naming Conventions

##### Name.1 Use camel case style for names (e. g. each consecive word in a name starts with a capital letter)

##### Name.2 Variables, functions and methods names must start with a small letter.

##### Name.3 Add 'g' prefix to global variables.

##### Name.4 Add 'm' prefix to class and structure members.

##### Name.5 Add 'pr' prefix to function or method parameters used to return value.

##### Name.6 Add 'r' prefix to variables that will be returned from function or method.

##### Name.7 Add 'c' prefix to constants.

##### Name.8 Add 's' prefix to static variables and class/structure members.

##### Name.9 Local variables and function/method parameters that are not static or constant and do not return value from function/method - has no prefix.

##### Name.9 Class and structure names always start with big letters.

##### Name.10 Namespace names always start with big letters.

##### Name.11 Enum names starts with big letters. Start every enum with a big letter.

##### Name.12 Use only upper case letters and _ symbol as a word separator for macros names.

### 3.2 Variable Declarations and Initialization

#### Var.1 Declare each variable on a separate line.

##### Var.2 Avoid abbraviations, short, unclear or hard to understand/remember variable names whenever possible.

##### Var.3 Single character variable names are only okay for counters, where the purpose of the variable is obvious or in math calculation (only when meaning of variable is obvious).

```cpp
// Wrong
int a, b;
char *c, *d;
int foo;
int bar, baz;
void *scsdSgPtr;
char *Var, VAR;
 
// Correct
int height;
int width;
char *userName;
QHash<int, QString> mNameByIndex;
QWidget *mTimeDisplayWidget;
QTimer mRequestTimeoutTimer;
for (int i = 0; i < count; ++i) {.....}
while (k < count) {++k}
```

##### Var.4 Use initializer lists wherever possible. Skip = when using {}-initializer.

##### Var.5 Use auto only for local variables where precision or range should not be specified explicitly.

```cpp
// Not desirable 
int i = 1.02; // Narrowing
int i = {1} ;
 
// Right
int i {1}; // Also saves from narrowing
QList<QString> vegetables{"potato", "tomato", "cabbage"};
 
auto i = 0;
```

##### Var.6. Wait with declaring a variable until it is needed.

##### Var.7. Make variable lifetime and visibility scope as short as possible.

### 3.3 Type Declarations

##### Type.1 Use strongly typed enums (enum classes) as much as possible.

```cpp
enum class TrafficLightColors {Red, Green, Blue}
```

## 4. Coding Documentation

### 4.1 Comments

##### Comment.1 Use Doxygen style of code documentation.

## 5. Coding Guidelines

**Here will be rules in addition to CPP Core Guidelines.**

## 6. Project Structure

### 6.1 File Naming

##### File.1 All headers and source files should be named in lowercase.

##### File.2 In general: no underscore sumbols “_” as separators between words.

