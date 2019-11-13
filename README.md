Console Script
======

Parses and evaluates single line expressions.

`Console Script` is a library written in C++. Originally was made to simply add console input into games.

Features
------------

Supported types:
* boolean
* integer
* floating point
* string

Supported lexems:
* constants
* variables
* functions
* class functions
* build-in operators
* type conversions

Examples of constants:
* boolean: `true`, `false`
* integer: `-1`, `256`
* float: `-4.23`, `15.1666`
* string: `"Test string"`, `"@BetterCallSoul"`

Build-in additive operators:
* `+`
* `-`

Build-in assignment operators:
* `=`
* `+=`
* `-=`
* `*=`
* `/=`
* `|=`
* `&=`
* `^=`
* `%=`
* `<<=`
* `>>=`

Build-in bitwise operators:
* `&`
* `|`
* `^`

Build-in logical operators:
* `&&`
* `||`

Build-in multiplicative operators:
* `*`
* `/`
* `%`

Build-in relational and equality operators:
* `==`
* `!=`
* `<`
* `>`
* `<=`
* `>=`

Build-in shift operators:
* `<<`
* `>>`

Build-in unary operators:
* `!`
* `~`
* `++`
* `--`

Build-in cast operators:
* `(bool)`
* `(int)`
* `(float)`
* `(string)`

Build-in precedence operators:
* `(`
* `)`

The precedence and associativity of operators is based on C++ one.
Take a look into [this page](http://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/language/operator_precedence.html) for details.
Anyway you can always use parentheses to do not care about precedence.

How to get
------------

```bash
git clone https://github.com/Shtille/ConsoleScript.git .
```

Building
--------

On Unix-based platforms simply call `make`
On the rest platforms building is up to you.
Just have in mind that library requires C++14 standard to compile.

Dependencies
-------------------

Project has no dependencies.

Usage
-----

Just include header `script.h` into your module.

Possible options:
* Define `CS_WIDE_STRING` before including the header to use wide characters.
* Define `CS_HIGHP_FLOAT` before including the header to use double precision floating point values.

`Parser` is the main class that holds everything you need.

The simpliest program:
```C++
#include <iostream>
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2FShtille%2FConsoleScript.svg?type=shield)](https://app.fossa.io/projects/git%2Bgithub.com%2FShtille%2FConsoleScript?ref=badge_shield)

#include <string>
#include "script.h"

int main()
{
	console_script::Parser parser;
	int x;
	if (!parser.Evaluate("1+2*(5 % 3)", &x))
		std::cout << parser.error() << std::endl; // this won't happen, BTW
	std::cout << x << std::endl;
}
```

For more details of usage take a look into `tests/main.cpp` and the library header `script.h`.

License
-------

[zlib/libpng](https://opensource.org/licenses/zlib-license.php)

Copyright (c) 2014-2018 Sviridov Vladimir


## License
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2FShtille%2FConsoleScript.svg?type=large)](https://app.fossa.io/projects/git%2Bgithub.com%2FShtille%2FConsoleScript?ref=badge_large)