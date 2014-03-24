minimal boost memoryview
========================

Copyright © 2014 Pierre de Buyl

This repository provides a minimal example of a
[Boost.Python](http://www.boost.org/doc/libs/release/libs/python/) module that
gives access to C++ level data as a
[Memoryview](http://docs.python.org/2.7/c-api/buffer.html#memoryview-objects). The
data is stored in a
[Py_buffer](http://docs.python.org/2.7/c-api/buffer.html#the-new-style-py-buffer-struct).

This code is written by Pierre de Buyl and is released under the modified BSD
license that can be found in the file LICENSE.

Usage
-----

    make
	make test
