# What Is It?
*nodejs_http_parser_mxxru* is an mxxru wrapper for
[nodejs http-parser](https://github.com/nodejs/http-parser) library.

# How To Use

## Prerequisites

To use *nodejs_http_parser_mxxru* it is necessary to have:

* Reasonably modern C compiler (these are doing well: VC14.0, GCC 5.1 or above, clang 3.6 or above);
* [nodejs/http-parser](https://github.com/nodejs/http-parser) 2.7.1 or above.
* [Mxx_ru](https://sourceforge.net/projects/mxxru/) 1.6.11 or above.

## Obtaining

### Cloning of Git Repository

```sh
git clone https://github.com/stiffstream/nodejs_http_parser_mxxru
```

And then:
```sh
cd nodejs_http_parser_mxxru
mxxruexternals
```
to download and extract *nodejs_http_parser_mxxru*'s dependencies.

### MxxRu::externals recipe

For *nodejs_http_parser_mxxru* itself:
```ruby
MxxRu::arch_externals :nodejs_http_parser_mxxru do |e|
  e.url 'https://github.com/Stiffstream/nodejs_http_parser_mxxru/archive/v.0.2.1.tar.gz'

  e.map_dir 'dev/nodejs/http_parser_mxxru' => 'dev/nodejs'
end
```

For [nodejs/http-parser](https://github.com/nodejs/http-parser) dependency:
```ruby
MxxRu::arch_externals :nodejs_http_parser do |e|
  e.url 'https://github.com/nodejs/http-parser/archive/v2.9.2.tar.gz'

  e.map_dir 'contrib' => 'dev/nodejs/http_parser'
  e.map_file 'http_parser.h' => 'dev/nodejs/http_parser/*'
  e.map_file 'http_parser.c' => 'dev/nodejs/http_parser/*'
end
~~~~~

## Compilation

Compilation must be performed via Mxx_ru:
```sh
git clone https://github.com/stiffstream/nodejs_http_parser_mxxru
cd nodejs_http_parser_mxxru
mxxruexternals
cd dev
ruby build.rb
```
*NOTE.* It may be necessary to set up `MXX_RU_CPP_TOOLSET` environment variable.

# License

*nodejs_http_parser_mxxru* is distributed under
[BSD-3-Clause](http://spdx.org/licenses/BSD-3-Clause.html) license. See LICENSE
file for more information.

For the license of *nodejs/http-parser* library see LICENSE file in *nodejs/http-parser* distributive.

