# Standard library header <concepts> _(C++20)_

## Concepts

### Core language concepts

| Concept               | Description                                         |
|-----------------------|-----------------------------------------------------|
| same_as _(C++20)_       | Specifies that a type is the same as another type   |
| derived_from _(C++20)_  | Specifies that a type is derived from another type |
| convertible_to _(C++20)_| Specifies that a type is implicitly convertible to another type|
| common_reference_with _(C++20)_| Specifies that two types share a common reference type|
| common_with _(C++20)_   | Specifies that two types share a common type        |
| integral _(C++20)_      | Specifies that a type is an integral type           |
| signed_integral _(C++20)_| Specifies that a type is an integral type that is signed|
| unsigned_integral _(C++20)_ | Specifies that a type is an integral type that is unsigned|
| floating_point _(C++20)_ | Specifies that a type is a floating-point type       |
| assignable_from _(C++20)_ | Specifies that a type is assignable from another type|
| swappable _(C++20)_     | Specifies that a type can be swapped                |
| swappable_with _(C++20)_ | Specifies that two types can be swapped with each other|
| destructible _(C++20)_  | Specifies that an object of the type can be destroyed|
| constructible_from _(C++20)_ | Specifies that a variable of the type can be constructed from or bound to a set of argument types|
| default_initializable _(C++20)_ | Specifies that an object of a type can be default constructed|
| move_constructible _(C++20)_ | Specifies that an object of a type can be move constructed|
| copy_constructible _(C++20)_ | Specifies that an object of a type can be copy constructed and move constructed|

### Comparison concepts

| Concept                   | Description                                                    |
|---------------------------|----------------------------------------------------------------|
| equality_comparable, equality_comparable_wit _(C++20)_       | Specifies that the operator == is an equivalence relation   |
| totally_ordered, totally_ordered_with _(C++20)_  | Specifies that the comparison operators on the type yield a total order |

### Object concepts

| Concept          | Description                                          |
|------------------|------------------------------------------------------|
| movable _(C++20)_  | Specifies that an object of a type can be moved and swapped  |
| copyable _(C++20)_ | Specifies that an object of a type can be copied, moved, and swapped  |
| semiregular _(C++20)_ | Specifies that an object of a type can be copied, moved, swapped, and default constructed  |
| regular _(C++20)_ | Specifies that a type is regular, that is, it is both semiregular and equality_comparable  |

### Callable concepts

| Concept              | Description                                                |
|----------------------|------------------------------------------------------------|
| invocable, regular_invocable _(C++20)_    | Specifies that a callable type can be invoked with a given set of argument types |
| predicate _(C++20)_    | Specifies that a callable type is a Boolean predicate       |
| relation _(C++20)_     | Specifies that a callable type is a binary relation         |
| equivalence_relation _(C++20)_ | Specifies that a relation imposes an equivalence relation |
| strict_weak_order _(C++20)_ | Specifies that a relation imposes a strict weak ordering   |

### Customization point objects
| Concept          | Description                                          |
|------------------|------------------------------------------------------|
| ranges::swap _(C++20)_ | Swaps the values of two objects (customization point object)  |

## Synopsis
```cpp
namespace std {
  // language-related concepts
  // concept same_as
  template<class T, class U>
    concept same_as = /* see description */;
 
  // concept derived_from
  template<class Derived, class Base>
    concept derived_from = /* see description */;
 
  // concept convertible_to
  template<class From, class To>
    concept convertible_to = /* see description */;
 
  // concept common_reference_with
  template<class T, class U>
    concept common_reference_with = /* see description */;
 
  // concept common_with
  template<class T, class U>
    concept common_with = /* see description */;
 
  // arithmetic concepts
  template<class T>
    concept integral = /* see description */;
  template<class T>
    concept signed_integral = /* see description */;
  template<class T>
    concept unsigned_integral = /* see description */;
  template<class T>
    concept floating_point = /* see description */;
 
  // concept assignable_from
  template<class LHS, class RHS>
    concept assignable_from = /* see description */;
 
  // concept swappable
  namespace ranges {
    inline namespace /* unspecified */ {
      inline constexpr /* unspecified */ swap = /* unspecified */;
    }
  }
  template<class T>
    concept swappable = /* see description */;
  template<class T, class U>
    concept swappable_with = /* see description */;
 
  // concept destructible
  template<class T>
    concept destructible = /* see description */;
 
  // concept constructible_from
  template<class T, class... Args>
    concept constructible_from = /* see description */;
 
  // concept default_initializable
  template<class T>
    concept default_initializable = /* see description */;
 
  // concept move_constructible
  template<class T>
    concept move_constructible = /* see description */;
 
  // concept copy_constructible
  template<class T>
    concept copy_constructible = /* see description */;
 
  // comparison concepts
  // concept equality_comparable
  template<class T>
    concept equality_comparable = /* see description */;
  template<class T, class U>
    concept equality_comparable_with = /* see description */;
 
  // concept totally_ordered
  template<class T>
    concept totally_ordered = /* see description */;
  template<class T, class U>
    concept totally_ordered_with = /* see description */;
 
  // object concepts
  template<class T>
    concept movable = /* see description */;
  template<class T>
    concept copyable = /* see description */;
  template<class T>
    concept semiregular = /* see description */;
  template<class T>
    concept regular = /* see description */;
 
  // callable concepts
  // concept invocable
  template<class F, class... Args>
    concept invocable = /* see description */;
 
  // concept regular_invocable
  template<class F, class... Args>
    concept regular_invocable = /* see description */;
 
  // concept predicate
  template<class F, class... Args>
    concept predicate = /* see description */;
 
  // concept relation
  template<class R, class T, class U>
    concept relation = /* see description */;
 
  // concept equivalence_relation
  template<class R, class T, class U>
    concept equivalence_relation = /* see description */;
 
  // concept strict_weak_order
  template<class R, class T, class U>
    concept strict_weak_order = /* see description */;
}
```

## Concept same_as
```cpp
template<class T, class U>
  concept __SameImpl = is_same_v<T, U>;  // exposition only 
template<class T, class U>
  concept same_as = __SameImpl<T, U> && __SameImpl<U, T>;
```

## Concept derived_from
```cpp
template<class Derived, class Base>
  concept derived_from =
    is_base_of_v<Base, Derived> &&
    is_convertible_v<const volatile Derived*, const volatile Base*>;
```

### Concept convertible_to
```cpp
template<class From, class To>
  concept convertible_to =
    is_convertible_v<From, To> &&
    requires(From (&f)()) {
      static_cast<To>(f());
    };
```

### Concept common_reference_with
```cpp
template<class T, class U>
  concept common_reference_with =
    same_as<common_reference_t<T, U>, common_reference_t<U, T>> &&
    convertible_to<T, common_reference_t<T, U>> &&
    convertible_to<U, common_reference_t<T, U>>;
```


### Concept common_with
```cpp
template<class T, class U>
  concept common_with =
    same_as<common_type_t<T, U>, common_type_t<U, T>> &&
    requires {
      static_cast<common_type_t<T, U>>(declval<T>());
      static_cast<common_type_t<T, U>>(declval<U>());
    } &&
    common_reference_with<
      add_lvalue_reference_t<const T>,
      add_lvalue_reference_t<const U>> &&
    common_reference_with<
      add_lvalue_reference_t<common_type_t<T, U>>,
      common_reference_t<
        add_lvalue_reference_t<const T>,
        add_lvalue_reference_t<const U>>>;
```

### Concept integral
```cpp
template<class T>
  concept integral = is_integral_v<T>;
```


### Concept signed_integral
```cpp
template<class T>
  concept signed_integral = integral<T> && is_signed_v<T>;
```

### Concept unsigned_integral
```cpp
template<class T>
  concept unsigned_integral = integral<T> && !signed_integral<T>;
```

### Concept floating_point
```cpp
template<class T>
  concept floating_point = is_floating_point_v<T>;
```

### Concept assignable_from
```cpp
template<class LHS, class RHS>
  concept assignable_from =
    is_lvalue_reference_v<LHS> &&
    common_reference_with<
      const remove_reference_t<LHS>&,
      const remove_reference_t<RHS>&> &&
    requires(LHS lhs, RHS&& rhs) {
      { lhs = std::forward<RHS>(rhs) } -> same_as<LHS>;
```

### Concept swappable
```cpp
template<class T>
  concept swappable = requires(T& a, T& b) { ranges::swap(a, b); };

```
### Concept swappable_with
```cpp
template<class T, class U>
  concept swappable_with =
    common_reference_with<const remove_reference_t<T>&, const remove_reference_t<U>&> &&
    requires(T&& t, U&& u) {
      ranges::swap(std::forward<T>(t), std::forward<T>(t));
      ranges::swap(std::forward<U>(u), std::forward<U>(u));
      ranges::swap(std::forward<T>(t), std::forward<U>(u));
      ranges::swap(std::forward<U>(u), std::forward<T>(t));
    };
```

### Concept destructible
```cpp
template<class T>
  concept destructible = is_nothrow_destructible_v<T>;
```

### Concept constructible_from
```cpp
template<class T, class... Args>
  concept constructible_from = destructible<T> && is_constructible_v<T, Args...>;
```
### Concept default_initializable
```cpp
template<class T>
  inline constexpr bool __is_default_initializable =
    /* see description */;  // exposition only
 
template<class T>
  concept default_initializable = constructible_from<T> &&
                                  requires{ T{}; } &&
                                  __is_default_initializable<T>;
```

### Concept move_constructible
```cpp
template<class T>
  concept move_constructible = constructible_from<T, T> && convertible_to<T, T>;
```

### Concept copy_constructible
```cpp
template<class T>
  concept copy_constructible =
    move_constructible<T> &&
    constructible_from<T, T&> && convertible_to<T&, T> &&
    constructible_from<T, const T&> && convertible_to<const T&, T> &&
    constructible_from<T, const T> && convertible_to<const T, T>;
```

### Concept equality_comparable
```cpp
template<class T, class U>
  concept __WeaklyEqualityComparableWith = // exposition only
    requires(const remove_reference_t<T>& t,
             const remove_reference_t<U>& u) {
      { t == u } -> boolean-testable;
      { t != u } -> boolean-testable;
      { u == t } -> boolean-testable;
      { u != t } -> boolean-testable;
    };
 
template<class T>
  concept equality_comparable = __WeaklyEqualityComparableWith<T, T>;
```

### Concept equality_comparable_with
```cpp
template<class T, class U>
  concept equality_comparable_with =
    equality_comparable<T> && equality_comparable<U> &&
    common_reference_with<const remove_reference_t<T>&, const remove_reference_t<U>&> &&
    equality_comparable<
      common_reference_t<
        const remove_reference_t<T>&,
        const remove_reference_t<U>&>> &&
    __WeaklyEqualityComparableWith<T, U>;
```


### Concept totally_ordered
```cpp
template<class T>
  concept totally_ordered =
    equality_comparable<T> &&
    requires(const remove_reference_t<T>& a,
             const remove_reference_t<T>& b) {
      { a <  b } -> boolean-testable;
      { a >  b } -> boolean-testable;
      { a <= b } -> boolean-testable;
      { a >= b } -> boolean-testable;
    };
```

### Concept totally_ordered_with
```cpp
template<class T, class U>
  concept totally_ordered_with =
    totally_ordered<T> && totally_ordered<U> &&
    common_reference_with<const remove_reference_t<T>&, const remove_reference_t<U>&> &&
    totally_ordered<
      common_reference_t<
        const remove_reference_t<T>&,
        const remove_reference_t<U>&>> &&
    equality_comparable_with<T, U> &&
    requires(const remove_reference_t<T>& t,
             const remove_reference_t<U>& u) {
      { t <  u } -> boolean-testable;
      { t >  u } -> boolean-testable;
      { t <= u } -> boolean-testable;
      { t >= u } -> boolean-testable;
      { u <  t } -> boolean-testable;
      { u >  t } -> boolean-testable;
      { u <= t } -> boolean-testable;
      { u >= t } -> boolean-testable;
    };
```

### Concept movable
```cpp
template<class T>
  concept movable = is_object_v<T> && move_constructible<T> &&
                    assignable_from<T&, T> && swappable<T>;
```


### Concept copyable
```cpp
template<class T>
  concept copyable = copy_constructible<T> && movable<T> && assignable_from<T&, T&> &&
                     assignable_from<T&, const T&> && assignable_from<T&, const T>;
```


### Concept semiregular
```cpp
template<class T>
  concept semiregular = copyable<T> && default_initializable<T>;
```

### Concept regular
```cpp
template<class T>
  concept regular = semiregular<T> && equality_comparable<T>;
```

### Concept invocable
```cpp
template<class F, class... Args>
  concept invocable = requires(F&& f, Args&&... args) {
    invoke(std::forward<F>(f), std::forward<Args>(args)...);
      // not required to be equality-preserving
  };
```

### Concept regular_invocable
```cpp
template<class F, class... Args>
  concept regular_invocable = invocable<F, Args...>;
```

### Concept predicate
```cpp
template<class F, class... Args>
  concept predicate =
    regular_invocable<F, Args...> && boolean-testable<invoke_result_t<F, Args...>>;
```

### Concept relation
```cpp
template<class R, class T, class U>
  concept relation =
    predicate<R, T, T> && predicate<R, U, U> &&
    predicate<R, T, U> && predicate<R, U, T>;
```

### Concept equivalence_relation
```cpp
template<class R, class T, class U>
  concept equivalence_relation = relation<R, T, U>;
```

### Concept strict_weak_order
```cpp
template<class R, class T, class U>
  concept strict_weak_order = relation<R, T, U>;
```
