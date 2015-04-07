// http://www.tutorialspoint.com/python/python_further_extensions.htm
#include <Python.h> 

static PyObject *helloworld(PyObject *self) {

  return Py_BuildValue("s", "Hello, Python extension, extending python with c/c++ is very easy... "); 
}

static char helloworld_docs[] = "helloworld(): This is hello world.";

static PyMethodDef helloworld_funcs[] = {
  {"helloworld", (PyCFunction)helloworld, 
   METH_NOARGS, helloworld_docs},
  {NULL}
}; 

void inithelloworld(void) {

  Py_InitModule3("helloworld", helloworld_funcs, 
		 "Extension hello world example." ); 

}


