from distutils.core import setup, Extension

extension = Extension(
    name='aclib_plugin',
    sources=[
        'source/EventLoop.cpp',
        'source/python/ACLIB_plugin.cpp',
        'source/python/PyEventLoop.cpp',
        'source/python/PyPhysics.cpp',
        'source/python/PyGraphics.cpp',
        'source/python/PyStatics.cpp',
        'source/util/Thread.cpp'
    ],
    include_dirs=['source'])

setup(name='aclib_plugin',
      version='1.0',
      ext_modules=[extension])
