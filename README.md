# ft_printf

*This project has been created as part of the 42 curriculum by [Pau-Narvaez-Roy](https://github.com/Pau-Narvaez-Roy).*

---

## Description

**ft_printf** is a 42 school project that implements a custom version of the standard C library's `printf` function. This project teaches essential concepts about variadic functions, string formatting, type conversion, and the inner workings of one of the most commonly used functions in C programming.

### Objective

The goal of this project is to develop a robust function that:
- Recreates the core functionality of the standard `printf` function
- Handles variable arguments (variadic functions) using `va_list`
- Supports multiple format specifiers and conversion specifiers
- Correctly formats and prints various data types (integers, strings, characters, pointers, hexadecimal numbers)
- Returns the number of characters printed, matching `printf` behavior

### Overview

`ft_printf` is a fundamental exercise in the 42 curriculum that provides deep insight into how formatted output functions work internally. Rather than relying on the standard library's `printf`, students build their own implementation from scratch, gaining understanding of variadic function syntax, format string parsing, type casting, and efficient output handling. This project bridges the gap between basic I/O operations and advanced string manipulation.

---

## Instructions

### Compilation

To compile this project, use the provided `Makefile`:

```bash
make
```

To create only the object files:

```bash
make all
```

To clean up object files:

```bash
make clean
```

To remove all generated files including the library:

```bash
make fclean
```

To recompile the entire project:

```bash
make re
```

### Installation

1. Clone the repository:
```bash
git clone git@github.com:Pau-Narvaez-Roy/ft_printf.git
cd ft_printf
```

2. Compile the project:
```bash
make
```

This will generate the `libftprintf.a` library file.

### Usage

#### Basic Function Signature

```c
#include "ft_printf.h"

int ft_printf(char const *format, ...);
```

#### Parameters

- `format` (const char *): Format string containing text and conversion specifiers
- `...` (variadic): Variable arguments corresponding to the format specifiers

#### Return Value

- Returns the number of characters successfully printed
- Returns `-1` if the format string is NULL
- Returns `-1` on error

#### Supported Format Specifiers

| Specifier | Type | Example |
|-----------|------|---------|
| `%c` | Character | `'A'` |
| `%s` | String | `"hello"` |
| `%p` | Pointer (hexadecimal) | `0x7ffc6d40` |
| `%d` | Signed decimal integer | `42` |
| `%i` | Signed decimal integer | `42` |
| `%u` | Unsigned decimal integer | `4294967295` |
| `%x` | Unsigned hexadecimal (lowercase) | `ff` |
| `%X` | Unsigned hexadecimal (uppercase) | `FF` |
| `%%` | Literal percent sign | `%` |

#### Example Usage

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int count;
    
    count = ft_printf("Hello, %s!\n", "World");
    ft_printf("Number of characters printed: %d\n", count);
    
    ft_printf("Integer: %d, Hex: %x, Unsigned: %u\n", 42, 255, 100);
    
    int num = 123;
    ft_printf("Pointer address: %p\n", &num);
    
    return (0);
}
```

#### Output

```
Hello, World!
Number of characters printed: 14
Integer: 42, Hex: ff, Unsigned: 100
Pointer address: 0x7ffc6d40
```

### Requirements

- **Standard C library**: Uses `stdarg.h` for variadic function support, `unistd.h` for `write()`, and `stdlib.h` for memory allocation
- **Variadic Arguments**: Format string must be NULL-terminated
- **Return Value**: Must accurately count all characters printed
- **Error Handling**: Returns -1 for invalid format strings

---

## Algorithm Explanation and Justification

### Algorithm Overview

The `ft_printf` function implements a **format string parsing and type dispatch algorithm** that processes a format string character by character, identifies conversion specifiers, extracts corresponding arguments from the variadic list, and outputs formatted data.

#### 1. **Main Processing Loop: `ft_choose_format()`**

```c
int ft_choose_format(char const *format, va_list vargs)
{
    int count_printed = 0;
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            count_printed += ft_print_vargs(format + 1, vargs);
            if (count_printed < temp)
                count_printed += ft_putchar((char) *format);
            else
                format++;
        }
        else
            count_printed += ft_putchar((char) *format);
        format++;
    }
    return (count_printed);
}
```

**Key Features**:
- Iterates through each character in the format string
- When encountering `%`, checks if a conversion specifier follows
- Dispatches to `ft_print_vargs()` for format-specific processing
- Counts all printed characters accurately
- Handles error cases by printing `%` if format specifier is invalid

**Justification**:
- **Character-by-character parsing**: Allows precise control over output and accurate character counting
- **Lookahead for format specifier**: Checking `*(format + 1)` prevents undefined behavior with trailing `%`
- **Error recovery**: Invalid format specifiers are printed as literals, mimicking standard `printf` behavior

#### 2. **Format Specifier Dispatch: `ft_print_vargs()`**

```c
static int ft_print_vargs(char const *format, va_list vargs)
{
    int count_printed = 0;
    if (*format == 'c')
        count_printed += ft_putchar(va_arg(vargs, int));
    else if (*format == 's')
        count_printed += ft_putstr(va_arg(vargs, char *));
    else if (*format == 'p')
        count_printed += ft_putnbr_long_base(va_arg(vargs, void *));
    else if (*format == 'd')
        count_printed += ft_putnbr(va_arg(vargs, int));
    // ... more specifiers ...
    else
        count_printed--;  // Invalid specifier
    return (count_printed);
}
```

**Key Features**:
- Uses a cascade of `if-else` statements for format specifier matching
- Each specifier calls a type-specific output function
- Returns count modification (positive for successful output, negative for errors)
- Handles special cases like `%%` (literal percent)

**Justification**:
- **Type-specific functions**: Each data type has an optimized conversion and output function
- **Consistent return mechanism**: All functions return character count for proper accumulation
- **Variadic argument extraction**: `va_arg()` macro correctly extracts next argument based on type

#### 3. **Variadic Function Mechanism**

```c
int ft_printf(char const *format, ...)
{
    va_list vargs;
    int count_printed;
    
    if (!format)
        return (-1);
    va_start(vargs, format);
    count_printed = ft_choose_format(format, vargs);
    va_end(vargs);
    return (count_printed);
}
```

**Key Features**:
- `va_start()` initializes the argument pointer from the format parameter
- Format string is passed to processing function with `va_list`
- `va_end()` properly cleans up the variadic list
- NULL format string returns -1 (error)

**Justification**:
- **Standard variadic protocol**: Follows C standard for variadic functions
- **Proper initialization/cleanup**: Prevents undefined behavior in argument access
- **Separation of concerns**: Main function handles setup; processing function handles logic

#### 4. **Type-Specific Conversion Functions**

The implementation includes specialized functions for each data type:

- **`ft_putchar()`**: Outputs a single character via `write()`
- **`ft_putstr()`**: Outputs a null-terminated string character by character
- **`ft_putnbr()`**: Converts signed integers to decimal and outputs
- **`ft_putnbr_unsigned()`**: Handles unsigned integer conversion
- **`ft_putnbr_base()`**: Converts unsigned integers to hexadecimal (base 16)
- **`ft_putnbr_long_base()`**: Converts pointers to hexadecimal with `0x` prefix

**Justification**:
- **Single responsibility**: Each function handles one data type
- **Code reusability**: Functions can be tested independently
- **Efficient output**: Direct `write()` calls minimize buffering overhead

### Why This Algorithm?

1. **Format String Parsing**: Character-by-character parsing provides exact control and enables accurate character counting
2. **Variadic Dispatch**: Type-specific functions ensure correct data interpretation and conversion
3. **Modularity**: Separate functions for each data type make the code maintainable and extensible
4. **Accuracy**: Cumulative character counting ensures the return value matches actual output
5. **Standard Compliance**: Follows standard `printf` behavior and conventions
6. **Robustness**: Handles edge cases:
   - NULL format strings
   - NULL string pointers in `%s`
   - Trailing `%` without specifier
   - Invalid conversion specifiers
   - Pointer addresses on various architectures

### Complexity Analysis

- **Time Complexity**: O(n + m) where:
  - n = length of format string (parsed once)
  - m = sum of lengths of all output data (converted and printed)
  - Each character is processed exactly once
  
- **Space Complexity**: O(1)
  - Only uses a fixed number of variables regardless of input size
  - No recursive calls or dynamic allocation during formatting
  - Variadic list storage is handled by the compiler

### Format Specifier Processing Chain

```
ft_printf()
    ↓
ft_choose_format()
    ↓ (for each %)
ft_print_vargs()
    ↓ (dispatch based on specifier)
ft_putchar() / ft_putstr() / ft_putnbr() / ft_putnbr_base() / etc.
    ↓
write() system call
```

---

## Resources

### Official Documentation
- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) - Standard printf documentation
- [man 3 stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html) - Variadic function macros
- [man 2 write](https://man7.org/linux/man-pages/man2/write.2.html) - System call for output
- [C Standard Library Reference](https://en.cppreference.com/w/c/io/fprintf) - Format string specifications

### Learning Resources
- [Variadic Functions in C](https://www.tutorialspoint.com/cprogramming/c_variable_arguments.htm) - Understanding va_list and va_arg
- [Format String Exploitation](https://owasp.org/www-community/attacks/Format_string_attack) - Security considerations
- [Printf Implementation Guide](https://www.geeksforgeeks.org/how-printf-works-in-c/) - Internal workings of printf
- [Hexadecimal Number Systems](https://www.khanacademy.org/math/algebra-home/alg-intro-to-algebra/algebra-alternate-number-bases/v/hexadecimal-number-system) - Understanding base conversion

### AI Usage

**AI was not used in the development of the code** for this project. The implementation was developed from scratch following the 42 curriculum requirements and deep understanding of C variadic functions and format string processing.

However, **AI was used for documentation purposes**:
- Generating comprehensive algorithm explanations and justifications
- Creating detailed format specifier tables and examples
- Structuring technical documentation sections
- Formatting code examples and output samples
- Organizing resources and references

---

## Features

- ✅ Supports all basic format specifiers (%c, %s, %d, %i, %u, %x, %X, %p, %%)
- ✅ Handles variadic function arguments correctly
- ✅ Accurate character counting matching standard printf
- ✅ Proper error handling for invalid inputs
- ✅ Handles edge cases (NULL strings, NULL pointers, invalid specifiers)
- ✅ Uses efficient direct write() system calls
- ✅ Follows 42 school coding standards (Norminette)
- ✅ Modular design with type-specific conversion functions

---

## Technical Decisions

### 1. Character-by-Character Processing
Rather than using complex regex or state machines, we parse the format string sequentially. This keeps the code simple, efficient, and easier to debug while maintaining accuracy.

### 2. Type-Specific Conversion Functions
Each data type has its own conversion function (`ft_putnbr`, `ft_putnbr_unsigned`, `ft_putnbr_base`, etc.). This approach provides:
- Clear separation of concerns
- Easier testing and debugging
- Better code reusability
- Optimized handling for each type

### 3. Variadic Argument Extraction
We use standard C `va_start()`, `va_arg()`, and `va_end()` macros. This ensures:
- Portability across different architectures
- Compliance with C standards
- Proper stack management
- Safe argument extraction

### 4. Direct write() System Calls
Instead of buffering output, we call `write()` directly for each converted value. This approach:
- Simplifies code complexity
- Matches standard printf behavior
- Reduces memory overhead
- Provides direct control over output

### 5. Single-Pass Format Parsing
The algorithm doesn't preprocess the format string; instead, it parses and outputs in a single pass. Benefits include:
- O(1) space complexity
- Lower memory overhead
- Real-time output without buffering
- Simpler error handling

---

## Examples

### Basic Formatting

```c
ft_printf("Hello, %s!\n", "World");
// Output: Hello, World!

ft_printf("The answer is %d\n", 42);
// Output: The answer is 42
```

### Multiple Specifiers

```c
ft_printf("%s is %d years old and weighs %u kg\n", "Alice", 25, 65);
// Output: Alice is 25 years old and weighs 65 kg
```

### Hexadecimal and Pointers

```c
int var = 42;
ft_printf("Variable at %p contains %x in hex\n", &var, 255);
// Output: Variable at 0x7ffc6d40 contains ff in hex
```

### Character and Percent

```c
ft_printf("Grade: %c, Accuracy: %%d\n", 'A');
// Output: Grade: A, Accuracy: %d
```

---

## Author

**Pau Narváez Roy**

42 Madrid Student | [GitHub Profile](https://github.com/Pau-Narvaez-Roy)

---

## License

This project is part of the 42 school curriculum.

---

**Last Updated**: July 16, 2026
