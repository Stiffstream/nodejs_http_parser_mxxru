MxxRu::arch_externals :nodejs_http_parser do |e|
  e.url 'https://github.com/nodejs/http-parser/archive/v2.9.2.tar.gz'

  e.map_dir 'contrib' => 'dev/nodejs/http_parser'
  e.map_file 'http_parser.h' => 'dev/nodejs/http_parser/*'
  e.map_file 'http_parser.c' => 'dev/nodejs/http_parser/*'

  # For testing purposes:
  e.map_file 'test.c' => 'dev/test/original_test/main.c'
end
