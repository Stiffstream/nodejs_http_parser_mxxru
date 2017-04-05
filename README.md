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

### Cloning of Hg Repository

```
hg clone https://bitbucket.org/sobjectizerteam/nodejs_http_parser_mxxru-0.1
```

And then:
```
cd nodejs_http_parser_mxxru-0.1
mxxruexternals
```
to download and extract *nodejs_http_parser_mxxru*'s dependencies.

### MxxRu::externals recipe

For *nodejs_http_parser_mxxru* itself:
~~~~~
::ruby
MxxRu::arch_externals :nodejs_http_parser_mxxru do |e|
  e.url 'https://bitbucket.org/sobjectizerteam/nodejs_http_parser_mxxru-0.1/get/v.0.1.0.tar.bz2'

  e.map_dir 'dev/nodejs/http_parser_mxxru' => 'dev/nodejs'
end
~~~~~

For [nodejs/http-parser](https://github.com/nodejs/http-parser) dependency:
~~~~~
MxxRu::arch_externals :nodejs_http_parser do |e|
  e.url 'https://github.com/nodejs/http-parser/archive/v2.7.1.tar.gz'

  e.map_dir 'contrib' => 'dev/nodejs/http_parser'
  e.map_file 'http_parser.h' => 'dev/nodejs/http_parser/*'
  e.map_file 'http_parser.c' => 'dev/nodejs/http_parser/*'
end
~~~~~

## Compilation

Compilation must be performed via Mxx_ru:
```
hg https://bitbucket.org/sobjectizerteam/nodejs_http_parser_mxxru-0.1
cd nodejs_http_parser_mxxru-0.1
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
