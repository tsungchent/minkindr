// #include <numpy_eigen/boost_python_headers.hpp>
// #include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <pybind11/pybind11.h>

void exportRotationQuaternion(pybind11::module& m);
void exportTransformation(pybind11::module& m);

PYBIND11_MODULE(minkindr_python, m)
{
  exportRotationQuaternion(m);
  exportTransformation(m);
}
