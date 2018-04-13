#include <string>
#include <map>
#include <iostream>
#include <cstring>

#include <http_parser.h>

struct tyny_header_t
{
	std::string m_url;
	std::map< std::string, std::string > m_fields;
	std::string m_current_feld;
};

int
my_url_callback( http_parser * parser, const char *at, size_t length )
{
	tyny_header_t * header = reinterpret_cast< tyny_header_t * >( parser->data );

	header->m_url.assign( at, length );

	return 0;
}

int
my_header_field( http_parser * parser, const char *at, size_t length )
{
	tyny_header_t * header = reinterpret_cast< tyny_header_t * >( parser->data );

	header->m_current_feld.assign( at, length );

	return 0;
}

int
my_header_value( http_parser * parser, const char *at, size_t length )
{
	tyny_header_t * header = reinterpret_cast< tyny_header_t * >( parser->data );

	header->m_fields[ header->m_current_feld ] = std::string{ at, length };

	return 0;
}

int
my_message_complete( http_parser * parser )
{
	http_parser_pause( parser, 1 );
	return 0;
}

int
main( int , char **  )
{
	try
	{
		const auto version = http_parser_version();
		unsigned int major = (version >> 16) & 255;
		unsigned int minor = (version >> 8) & 255;
		unsigned int patch = version & 255;

		std::cout
			<< "http_parser v"
			<< major << "."
			<< minor << "."
			<< patch << std::endl;

		tyny_header_t header;

		http_parser parser;
		http_parser_init( &parser, HTTP_REQUEST);
		parser.data = &header;

		http_parser_settings settings;
		http_parser_settings_init( &settings );

		settings.on_url = my_url_callback;
		settings.on_header_field = my_header_field;
		settings.on_header_value = my_header_value;
		settings.on_message_complete = my_message_complete;

		const std::string req_str{
			"GET / HTTP/1.1\r\n"
			"Host: www.example.com\r\n"
			"Connection: Keep-Alive\r\n"
			"Accept-Encoding: gzip\r\n"
			"Content-Length: 42\r\n"
			"\r\n"
			"0123456789"
			"0123456789"
			"0123456789"
			"0123456789"
			"01"
			// Should not be taken into consideration:
			"GET /MUST/NOT/BE/PARSED!!! HTTP/1.1\r\n" };

		std::cout << "Parse message:\n" << req_str << "\n" << std::endl;

		const auto nparsed =
			http_parser_execute(
				&parser,
				&settings,
				req_str.c_str(),
				req_str.size() );

		std::cout << "Parse finished, parsed bytes: " << nparsed << std::endl;

		if( HPE_OK != parser.http_errno && HPE_PAUSED != parser.http_errno )
		{
			enum http_errno err = HTTP_PARSER_ERRNO( &parser );
			throw std::runtime_error{
				std::string{ "parse failed: " } + http_errno_name( err ) };
		}
		else
		{
			std::cout
				<< "Header params:\n"
				"url: " << header.m_url << "\n"
				"http_major: " << parser.http_major  << "\n"
				"http_minor: " << parser.http_minor  << "\n"
				"content-length: " << parser.content_length;

			for( const auto & p: header.m_fields )
			{
				std::cout << "\n" << p.first << ": " << p.second;
			}

			std::cout << std::endl;
		}

	}
	catch( const std::exception & ex )
	{
		std::cerr << "Error: " << ex.what() << std::endl;
	}

	return 0;
}
