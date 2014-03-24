#include <Python.h>
#include <object.h>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

Py_buffer mypb;

const char *get_format(double x) {
  return "d";
}

const char *get_format(float x) {
  return "f";
}

const char *get_format(int x) {
  return "i";
}

/** Initializes a Py_buffer for datatype T and shape (n,d).
 */
template <class T>
void init_pb(Py_buffer *pb, int n, int d) {
  T dum=0;
  //const char* format = "d";

  // Setting basic variable of the Py_buffer
  pb->suboffsets = NULL;
  pb->internal = NULL;
  pb->obj = NULL;

  pb->readonly = 1;
  pb->ndim = 2;

  // The format is computed as a function of the template type T
  pb->format = (char*)malloc(2*sizeof(const char));
  strcpy(pb->format, get_format(dum));

  // Allocation and setting of the shape, stride and len
  pb->shape = (Py_ssize_t *)malloc(pb->ndim*sizeof(Py_ssize_t));
  pb->strides = NULL; //(Py_ssize_t *)malloc(pb->ndim*sizeof(Py_ssize_t));

  pb->shape[0] = n;
  pb->shape[1] = d;
  pb->itemsize = sizeof(T);
  // if (d==1) {
  //   pb->strides[1] = pb->itemsize;
  //   pb->strides[0] = pb->strides[1]*pb->shape[1];
  // } else {
  //   pb->strides[0] = pb->itemsize;
  // }

  pb->len = pb->itemsize;
  for (int i=0; i<d; i++) {
    pb->len *= pb->shape[i];
  }

  pb->buf = malloc(pb->len);

}

PyObject* mymv() {
  init_pb<int>(&mypb, 12, 2);
  return PyMemoryView_FromBuffer(&mypb);
}

BOOST_PYTHON_MODULE(mymv_ext)
{
    using namespace boost::python;
    def("mymv", mymv);
}
