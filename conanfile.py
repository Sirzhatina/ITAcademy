from conan import ConanFile
from conan.tools.cmake.layout import cmake_layout

class ITAcadDeps(ConanFile):
	settings = "os", "arch", "build_type", "compiler"

	generators = "CMakeDeps", "CMakeToolchain"

	def requirements(self):
		self.requires("qt/6.7.1", options={"shared": True})

	def layout(self):
		cmake_layout(self)