require 'mxx_ru/cpp'

MxxRu::Cpp::exe_target {

  target '_test.original'

  required_prj 'nodejs/http_parser_mxxru/prj.rb'

  # For including "http_parser.h" to work.
  include_path 'nodejs/http_parser'

  c_source 'main.c'
}

