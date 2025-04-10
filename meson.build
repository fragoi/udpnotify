project('udpnotify', 'cpp',
  version: files('version'))

prefix = get_option('prefix')
datadir = prefix / get_option('datadir')

headers = [
  'src/arguments.h',
  'src/exceptions.h',
  'src/gexception.h',
  'src/gobjectmm.h',
  'src/logger.h',
  'src/notifications.h',
  'src/parsenotify.h',
  'src/udpserver.h',
]

sources = [
  'src/arguments.cpp',
  'src/exceptions.cpp',
  'src/gexception.cpp',
  'src/logger.cpp',
  'src/notifications.cpp',
  'src/parsenotify.cpp',
  'src/udpserver.cpp',
]

dependencies = [
  dependency('gio-unix-2.0')
]

tests = {
  'arguments_test': 'test/arguments_test.cpp',
  'logger_test': 'test/logger_test.cpp',
  'parsenotify_test': 'test/parsenotify_test.cpp',
}

manual_tests = {
  'notifications_test': 'test/manual/notifications_test.cpp',
  'udpserver_test': 'test/manual/udpserver_test.cpp',
}

lib = static_library(meson.project_name(),
  sources: headers + sources,
  dependencies: dependencies)

dep = declare_dependency(
  link_with: lib,
  dependencies: dependencies)

executable(meson.project_name(),
  sources: 'src/main.cpp',
  dependencies: dep,
  install: true)

foreach name, source : tests
  test_exe = executable(name,
    sources: source,
    dependencies: dep,
    link_args: ['-lpthread'])
  test(name, test_exe)
endforeach

foreach name, source : manual_tests
  executable(name,
    sources: source,
    dependencies: dep,
    link_args: ['-lpthread'])
endforeach

subdir('data' / 'systemd')
subdir('data' / 'icons')
