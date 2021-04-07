from distutils.core import setup, Extension

extension = Extension(
    name='aclib',
    sources=[
        'source/python/ACLIB_plugin.cpp',
        'source/python/Physics.cpp',
        'source/python/Graphics.cpp',
        'source/python/Statics.cpp',
        'source/Memory.cpp'
    ],
    include_dirs=[
        'source',
        'source/python'
    ])

setup(name='aclib',
      version='1.0',
      ext_modules=[extension])
