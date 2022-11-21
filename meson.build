project('ventilator', 'cpp', version : '0.1.0', default_options : ['warning_level=3', 'cpp_std=c++20'])

qt  = import('qt5')

dependencies  = [
    dependency('qt5', modules: ['Charts', 'Core', 'Gui', 'Widgets'])
  , dependency('ventilation')
  ]
includes      = include_directories(
    'source'
  , 'source/charts'
  , 'source/lung'
  , 'source/ventilator'
  )
sources       = [
    'source/main.cpp'
  , 'source/main-window.cpp'
  
  , 'source/charts/chart.cpp'
  , 'source/charts/charts-widget.cpp'

  , 'source/lung/lung-compliance.cpp'
  , 'source/lung/lung-resistance.cpp'
  , 'source/lung/lung-widget.cpp'

  , 'source/ventilator/ventilator-engine.cpp'
  , 'source/ventilator/ventilator-peep.cpp'
  , 'source/ventilator/ventilator-widget.cpp'
  ]
processed     = qt.preprocess(
    moc_headers         : [
        'source/main-window.hpp'
  
      , 'source/charts/chart.hpp'
      , 'source/charts/charts-widget.hpp'

      , 'source/lung/lung-compliance.hpp'
      , 'source/lung/lung-resistance.hpp'
      , 'source/lung/lung-widget.hpp'

      , 'source/ventilator/ventilator-engine.hpp'
      , 'source/ventilator/ventilator-peep.hpp'
      , 'source/ventilator/ventilator-widget.hpp'
      ]
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
