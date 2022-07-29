# 42-cpp08
The ninth and last day of the learning pool for C++ language.

## How to use it

There is a Makefile for compiling (`make`) cleaning the project (`make clean`, `make fclean`) and rebuild it (`make re`).

## Tasks

As the previous exercise, we go deeper in `templates` by adding other concepts such as `containers` and `iterators`.

First by using the function `std::find` to find an `int` in a collection, or by using the `std::map` container.

Then by the manipulation of the `std::vector` container to create a collection under the class `Span` and perform modifications or get the longest/shortest span.

Finally by creating a new container called `mutantstack`, based on the `std::stack` container. It simply use the underlying container and define it's own operator (`=`) and iterators (`begin()` and `end()` functions).
