# PLI

This is a fork of the [gccpl1](https://pl1gcc.sourceforge.net/) project. The goal is to preserve the historical role PL/I had in language development and offer an open source version that runs on Linux.
The goal is to bring it to parity with the IBM PL/I Enterprise compiler.

Additionally, to avoid combinatorial complexity, some features of the standard won't be implemeneted by default but can be toggled on/off with compiler flags.

These are features which have proven to be too complex to implement in production compilers, such as the one available by IBM. They are features which were experimental when originally written, never implemented before,
thus the need for backwards compatibility never existed. Additionally, since every aspect of the standard was meant to be implemented at once, introducing these obscurer aspects of the standard introduces combinatorial complexity in their implementation.

By making it possible to toggle these features on and off, they can be implemented in a limited fashion to avoid the problem of having a compiler too complex to maintain.

By allowing these obscure features a chance to be implemented, people interested in retro computing and the history of compilers can get a feel for the vision and ambition the initial designers had for PL/I.

To deal with the complexity of implementing a language with no reserved words and context sensitive syntax, a custom lexer and parser will be implemented in Haskell with a C intermediary to act as a bridge for the gcc backend.

This won't be intended for production code but will serve as a living record of an important period in computing hisotry.
