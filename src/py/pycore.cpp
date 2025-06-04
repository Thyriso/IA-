#include <pybind11/pybind11.h>
#include "core/geometry/Kernel.h"
#include "core/toolpath/ToolpathPlanner.h"

namespace py = pybind11;

PYBIND11_MODULE(pycamcore, m) {
    m.doc() = "Python bindings for the CAM core";

    py::class_<Geometry::Kernel::BoundingBox>(m, "BoundingBox")
        .def_readonly("minX", &Geometry::Kernel::BoundingBox::minX)
        .def_readonly("minY", &Geometry::Kernel::BoundingBox::minY)
        .def_readonly("minZ", &Geometry::Kernel::BoundingBox::minZ)
        .def_readonly("maxX", &Geometry::Kernel::BoundingBox::maxX)
        .def_readonly("maxY", &Geometry::Kernel::BoundingBox::maxY)
        .def_readonly("maxZ", &Geometry::Kernel::BoundingBox::maxZ);

    py::class_<Geometry::Kernel>(m, "Kernel")
        .def(py::init<>())
        .def("load_model", &Geometry::Kernel::loadModel)
        .def("bounding_box", &Geometry::Kernel::getBoundingBox);

    py::class_<Toolpath::ToolpathPlanner>(m, "ToolpathPlanner")
        .def(py::init<>())
        .def("generate_contour", &Toolpath::ToolpathPlanner::generateContour2D)
        .def("export_gcode", &Toolpath::ToolpathPlanner::exportGCode);
}
