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
  , 'source/sidebar'
  , 'source/spinbox'
  , 'source/ventilator'
  )
sources       = [
    'source/main.cpp'
  , 'source/main-window.cpp'
  
  , 'source/charts/chart.cpp'
  , 'source/charts/charts-widget.cpp'

  , 'source/lung/lung-widget.cpp'

  , 'source/sidebar/sidebar-widget.cpp'

  , 'source/spinbox/spinbox-compliance.cpp'
  , 'source/spinbox/spinbox-frequency.cpp'
  , 'source/spinbox/spinbox-peep.cpp'
  , 'source/spinbox/spinbox-pressure-peak.cpp'
  , 'source/spinbox/spinbox-ratio.cpp'
  , 'source/spinbox/spinbox-resistance.cpp'

  , 'source/ventilator/ventilator-engine.cpp'
  , 'source/ventilator/ventilator-widget.cpp'
  , 'source/ventilator/ventilator-modes/ventilator-pcv.cpp'
  , 'source/ventilator/ventilator-modes/ventilator-vcv.cpp'
  ]
processed     = qt.preprocess(
    moc_headers         : [
        'source/main-window.hpp'
  
      , 'source/charts/chart.hpp'
      , 'source/charts/charts-widget.hpp'

      , 'source/lung/lung-widget.hpp'

      , 'source/sidebar/sidebar-widget.hpp'

      , 'source/spinbox/spinbox-compliance.hpp'
      , 'source/spinbox/spinbox-frequency.hpp'
      , 'source/spinbox/spinbox-peep.hpp'
      , 'source/spinbox/spinbox-pressure-peak.hpp'
      , 'source/spinbox/spinbox-ratio.hpp'
      , 'source/spinbox/spinbox-resistance.hpp'

      , 'source/ventilator/ventilator-engine.hpp'
      , 'source/ventilator/ventilator-widget.hpp'
      , 'source/ventilator/ventilator-modes/ventilator-pcv.hpp'
      , 'source/ventilator/ventilator-modes/ventilator-vcv.hpp'
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
