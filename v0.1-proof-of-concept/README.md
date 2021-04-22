# cpp-compile-time-register-machine

A C++17 compile time register machine based off the Scheme (LISP) register machine grammar,
as discussed in *Structure and Interpretation of Computer Programs* (SICP).

This module is self-contained, in the sense that it does not use the standard namespace (*std::*).

Much effort has been put into privileging performance in this machine's design: There are several meta
programming styles possible when implementing---struct template, alias template, constexpr function---and
although they are equivalent to each other in potential, they can vary greatly in performance. 
It is for this reason *constexpr* was largely favored.

Finally, although this machine is extensible to an arbitrary number of registers (represented by a variadic pack),
it is currently designed with a limit of **sixteen**. Such a limit only exists due to optimization techniques,
which can themselves be extended.

Thanks.
