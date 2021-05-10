# cpp-compile-time-register-machine

**As of Monday May 10th 2021 this repo is defunct: It will remain here in its current v1.0 release candidate form
for one month until Monday June 7th, 2021, at which point it will be deleted. Otherwise, v1.0 also well as ongoing
releases will be held in my cpp-compile-time-library repo, which consolidates this code with my near linear
function space module.**

A C++17 compile time register machine based off the Scheme (LISP) register machine grammar,
as discussed in *Structure and Interpretation of Computer Programs* (SICP).

This module is self-contained, in the sense that it does not use the standard namespace (*std::*).

Much effort has been put into privileging performance in this machine's design: There are several meta
programming styles possible when implementing---struct template, alias template, constexpr function---and
although they are equivalent to each other in potential, they can vary greatly in performance. 
It is for this reason a hybrid approach (though leaning toward *constexpr* style) was largely favored.

Thanks.
