[![Build Status](https://travis-ci.org/amirnyy/Matrix.svg?branch=master)](https://travis-ci.org/amirnyy/Matrix)
```ShellSession
$ cmake -H. -B_build -DCMAKE_INSTALL_PREFIX=_install
$ cmake --build _build
$ cmake --build _build --target install
```

OR

```ShellSession
$ git clone https://github.com/amirnyy/Matrix
$ cd matrix/include
$ g++ main.cpp -I. -std=c++11 -o matrix-example
$ ./matrix-example
```
