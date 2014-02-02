various
=======

**Project directory structure:**

    /
      src — Source files written by myself
      ext — Contains third-party libraries
        libname-1.2.8
          include — Headers
          lib — Compiled lib files
          Donwload.txt — Contains link to download the version used
      ide — I store project files in here
        vc10 — I arrange project files depending on the IDE
      bin — Compiled exe goes here
      build — The compiler's build files
      test — All test code files
      doc — Documentation of any kind
      README
      INSTALL
      COPYING

If I'm writing a library (and I'm using C/C++) I'm going to organize my source files first in two folders called "include" and "src" and then by module. If it's an application, then I'm going to organize them just by module (headers and sources will go in the same folder).
