whats is casting

is treating a memorys datatype like another datatype
```c++
double d = 3.14;
int i = d; // i == 3;
```

## A - casting can happen be done implisitly in this cases:  

Smaller type → larger type✅
```c++
char c = 9;
int i = c;
```

Derived → Base✅
```c++
Drived d;
Base &b = d;
```

T* → void*✅
```c++
int *s;
void v = s;
```

Adding const✅
```c++
int a = 99;
const int d = a;
```

Larger → smaller (narrowing)⚠️ compiles, data loss
```c++
int i = 1000;
char c = i; //c == 0
```

Base → Derived❌ 
```c++
Derived *d = ...;

Base * b = d; // fails
```

Unrelated types❌ 
```c++
class A {...}; 
class B {...}; 
A a;

B *b = *a; // fails

// info: numiric types are excluded
```

## B - explisit casting

### 1- C-Style cast


c-style cast tryies 5 types of castings intel one of them works and and can't know which type it uses

```ini
    const_cast
    static_cast
    static_cast + const_cast
    reinterpret_cast
    reinterpret_cast + const_cast
```

# but whats the problem with c-style cast ???

removes const silently
```c++
const int a = 42;
int *p = (int *)&a;

*p = 1337;

//now a == 1337  
```

reinterpret_cast silently
```c++
class A {int a();};
class B {float b();};

A a;

B * b = (B *) &a;
b->b(); // UB. treats a's memory address as b which are not the same
```

bypass the private Base 
```c++
class Base {};
class Drived : private Base {};

Drived d;
Base * b = (Base *)&d; //this bypasses private access specifier; 
```

### 2- static_cast

```ini
I know the types, this is a logical conversion
```
- runs in compile time;
- The conversion is meaningful between the two types
```c++
    int i;
    bool k = statis_cast<bool>(i); // bool and i are numiric types

    class A { void f(); };
    A a;

    bool b = static_cast<bool>(a); ❌ // fails

```

- The hierarchy relationship exists (for up/downcasts)
```c++
    class A{};
    class B : A {};

    B b;
    A &a = static_cast<A&>(b) ✅

```
- No const is being dropped
```c++
    const int a;
    int b = static_cast<int>(a); ❌ //fail
```

- No unrelated pointer types
```c++
    double b = 3.14;
    int *i = static_cast<int *>(&b); ❌ //fail
```

- downcast 
```c++
    Base *b = &d
    Drived * d = static_cast<Drived *>(b); ✅/❌ //compile but unsafe at runtime
    //safe way is use dynamic_cast
```

- void* <-> T*
```c++
    int i = 99;
    void * ptr = static_cast<void *>(i); ✅
    int * p  = static_cast<int *>(ptr); ✅
```

-  void — discard a value
```c++
    int i;
    static_cast<void>(i); ✅ //avoid unused variable warning/error
```

- virtual base 
```c++
    struct Base {};
    struct Derived : virtual Base {};

    Base* b = ...;
    Derived* d = static_cast<Derived*>(b); ❌ // fails — need dynamic_cast
```


### 3- dynamic_cast

- works only polymorphic types
- the only cast that checks type at run time using RTTI (RunTime Type Information)
- identify the actual type of an object at runtime
- safely convert Base pointer/reference to Derived classes (or base to base in sideway casting)


# what is RTTI ?

- is a metadata the compiler inject into vtable in polymorphic classes ("real type", "type_info *")

### 3-reinterpret_cast




