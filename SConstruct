import os
import sys

taget_dir = "build"

# build mode (debug/release; default to release)
build_mode = ARGUMENTS.get('mode', 'release')

if build_mode not in ['debug', 'release']:
    sys.stderr.write('Oh noes: only "debug" and "release" build modes are supported\n')
    Exit(1)

# C++ flags and defines
ccflags = [
    '-std=c++11',
    '-Wall',
    '-pedantic-errors',
]

cppdefines = []

if build_mode == 'debug':
    ccflags += ['-g', '-O0']
    cppdefines += ['_DEBUG']
elif build_mode == 'release':
    ccflags += ['-O2']
    cppdefines += ['NDEBUG']

# this is to allow colorgcc
custom_env = {
    'PATH': os.environ['PATH'],
    'TERM': os.environ['TERM'],
    'HOME': os.environ['HOME'],
}

# create root environment
env = Environment(CCFLAGS=ccflags,
                       CPPDEFINES=cppdefines,
                       ENV=custom_env,
                       CPPPATH=['#/include'])

# custom C++ compiler
if 'CXX' in os.environ:
    env['CXX'] = os.environ['CXX']

Export('env', 'build_mode')

# library and tests
lib = SConscript(os.path.join('src', 'SConscript'))
# tests = SConscript(os.path.join('tests', 'SConscript'))
# Depends(tests, lib)

libs = [
    'cppunit'
]

env.Program(target=os.path.join(taget_dir, 'main'), source=['src/core/main.cpp'], LIBS=libs)
env.Program(target=os.path.join(taget_dir, 'money_test'), source=['src/core/money_test.cpp'], LIBS=libs)
env.Program(target=os.path.join(taget_dir, 'bimap_test'), source=['src/core/bimap_test.cpp'], LIBS=libs)
