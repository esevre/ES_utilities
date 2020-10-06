# Erik's Coding Standards for C++

## Variable Naming Types

Variable names can be written with many different styles.
As a reference some of those styles are listed below.

| Case Name | Description |
|-----|-----|
| `camelCase` | Each word is capitol, but the first is lower case |
| `PascalCase` | Each word is capitol, including the first word |
| `snake_case` | Each word is lowercase seperated by an underscore `_` |
| `kebab-case` | Each word is lowercase seperated by a dash `-` |


## Variable Naming

All variables should follow one of the casing styles listed above.
Additionally, in some contexts, it may be appropriate to add a prefix or a postfix depending on the situation.


### User Defined Types
User defined types, such as classes and structs, should use `PascalCase` for naming variables.

Inside of a class, we will need to name our variables and methods.
#### Member Functions (methods)
Member functions should be named with `camelCase`.

#### Member Variables
Member variables that are `private` or `protected` should be named the prefix `m_`.

Variables that are open for external use should have a simple name following the rules for non-member variables (`snake_case`).

### Objects and Variables
Objects and variable names should be named using `snake_case`.











