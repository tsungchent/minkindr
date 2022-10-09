#include <kindr/minimal/quat-transformation.h>
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/operators.h>

using Transformation = kindr::minimal::QuatTransformationTemplate<double>;

Eigen::Vector3d getPosition(const Transformation& transformation) {
	return transformation.getPosition();
}

Transformation::Rotation getRotation(const Transformation& transformation) {
	return transformation.getRotation();
}

void exportTransformation(pybind11::module& m) {
	using namespace pybind11;
	class_< Transformation, std::shared_ptr<Transformation>>(m, "Transformation")
		.def(init<>())
		.def(init<const Eigen::Matrix4d&>())
		.def(init<const Transformation::Rotation&, const Transformation::Position&>())
		.def("getTransformationMatrix", &Transformation::getTransformationMatrix)
		.def("getRotation", getRotation)
		.def("getRotationMatrix", &Transformation::getRotationMatrix)
		.def("getPosition", getPosition)
		.def("inverse", &Transformation::inverse)
		.def(self * self)
		;

	m.def("interpolateLinearly", &kindr::minimal::interpolateComponentwise<double>);
}
