require 'mxx_ru/cpp'

MxxRu::Cpp::exe_target {

  target '_test.cpp_usage_test'

  required_prj 'nodejs/http_parser_mxxru/prj.rb'

  cpp_source 'main.cpp'
}

