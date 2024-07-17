# FT_PRINTF

The purpose of this project is to replicate the behavior of the printf function, excluding the buffer management aspect present in the original implementation. This project introduces the concept of variadic functions, which are declared using an ellipsis (...), allowing them to accept a variable number of arguments.

## Supported Conversions

| Conversion | Short Description                                     |
|------------|--------------------------------------------------------|
| `%c`       | Outputs a single character.                            |
| `%s`       | Prints a sequence of characters.                       |
| `%p`       | Prints the hexadecimal representation of a `void *` pointer. |
| `%d`       | Displays a decimal (base 10) number.                   |
| `%i`       | Prints an integer in base 10.                          |
| `%u`       | Outputs an unsigned decimal (base 10) number.          |
| `%x`       | Prints a number in hexadecimal (base 16), in lowercase.|
| `%X`       | Prints a number in hexadecimal (base 16), in uppercase.|
| `%%`       | Prints a percent sign.                                 |

Feel free to reach out if you have any questions / improvement hints or need further clarification regarding the FT_PRINTF project :D
