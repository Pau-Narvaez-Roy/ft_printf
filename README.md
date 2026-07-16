# ft_printf

*This project has been created as part of the 42 curriculum by [pnarvaez](https://github.com/Pau-Narvaez-Roy).*

---

## Description

**ft_printf** implements a custom version of the standard C library's `printf` function. This project teaches essential concepts about variadic functions, string formatting, type conversion, and the inner workings of one of the most commonly used functions in C programming.

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

int	main(void)
{
	int	count;
	int	num;

	count = ft_printf("Hello, %s!\n", "World");
	ft_printf("Number of characters printed: %d\n", count);
	ft_printf("Integer: %d, Hex: %x, Unsigned: %u\n", 42, 255, 100);
	num = 123;
	ft_printf("Pointer address: %p\n", &num);
	return (0);
}
```

### Requirements

- **Standard C library**: Uses `stdarg.h` for variadic function support, `unistd.h` for `write()`, and `stdlib.h` for memory allocation
- **Variadic Arguments**: Format string must be NULL-terminated
- **Return Value**: Must accurately count all characters printed
- **Error Handling**: Returns -1 for invalid format strings

---

## Resources

### Official Documentation
- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html) - Standard printf documentation
- [man 3 stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html) - Variadic function macros
- [man 2 write](https://man7.org/linux/man-pages/man2/write.2.html) - System call for output
- [C Standard Library Reference](https://en.cppreference.com/w/c/io/fprintf) - Format string specifications

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

## Author

**Pau Narváez Roy**

42 Madrid Student | [GitHub Profile](https://github.com/Pau-Narvaez-Roy)

---

## License

This project is part of the 42 school curriculum.

---

**Last Updated**: July 16, 2026
