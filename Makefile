
all: mymv_ext

mymv_ext: mymv.cpp
	@bjam

test:
	PYTHONPATH=$(PWD)/_build python test_mymv.py
