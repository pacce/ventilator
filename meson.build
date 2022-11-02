project('gui', 'cpp', version : '0.1.0', default_options : ['warning_level=3', 'cpp_std=c++20'])

qt  = import('qt6')

dependencies  = [
  dependency('qt6', modules: ['Charts', 'Core', 'Gui', 'Widgets'])
  ]
includes      = include_directories('source')
sources       = [
      'source/main.cpp'
    , 'source/main-window.cpp'
  ]
processed     = qt.preprocess(
    moc_headers         :  'source/main-window.hpp'
  , include_directories : includes
  )

executable(
  meson.project_name()
  , sources
  , processed
  , include_directories : includes
  , dependencies        : dependencies
  , install             : true
  )
