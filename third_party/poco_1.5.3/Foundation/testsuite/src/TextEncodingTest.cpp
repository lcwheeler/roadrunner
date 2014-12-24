//
// TextEncodingTest.cpp
//
// $Id: //poco/1.4/Foundation/testsuite/src/TextEncodingTest.cpp#1 $
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#include "TextEncodingTest.h"
#include "CppUnit/TestCaller.h"
#include "CppUnit/TestSuite.h"
#include "Poco/TextEncoding.h"
#include "Poco/Latin1Encoding.h"
#include "Poco/Latin2Encoding.h"
#include "Poco/Latin9Encoding.h"
#include "Poco/Windows1250Encoding.h"
#include "Poco/Windows1251Encoding.h"
#include "Poco/Windows1252Encoding.h"
#include "Poco/UTF8Encoding.h"


using namespace Poco;


TextEncodingTest::TextEncodingTest(const std::string& name): CppUnit::TestCase(name)
{
}


TextEncodingTest::~TextEncodingTest()
{
}


void TextEncodingTest::testTextEncoding()
{
	TextEncoding& utf8 = TextEncoding::byName("utf8");
	assert (std::string("UTF-8") == utf8.canonicalName());
	
	TextEncoding& latin1 = TextEncoding::byName("latin1");
	assert (std::string("ISO-8859-1") == latin1.canonicalName());
	
	TextEncoding& latin2 = TextEncoding::byName("latin2");
	assert (std::string("ISO-8859-2") == latin2.canonicalName());

	TextEncoding& latin9 = TextEncoding::byName("latin9");
	assert (std::string("ISO-8859-15") == latin9.canonicalName());

	TextEncoding& cp1250 = TextEncoding::byName("CP1250");
	assert (std::string("Windows-1250") == cp1250.canonicalName());

	TextEncoding& cp1251 = TextEncoding::byName("CP1251");
	assert (std::string("Windows-1251") == cp1251.canonicalName());

	TextEncoding& cp1252 = TextEncoding::byName("CP1252");
	assert (std::string("Windows-1252") == cp1252.canonicalName());


	TextEncoding& glob = TextEncoding::global();
	assert (std::string("UTF-8") == glob.canonicalName());
	
	TextEncoding::global(new Latin1Encoding);
	TextEncoding& glob2 = TextEncoding::global();
	assert (std::string("ISO-8859-1") == glob2.canonicalName());

	TextEncoding::global(new Latin2Encoding);
	TextEncoding& glob3 = TextEncoding::global();
	assert (std::string("ISO-8859-2") == glob3.canonicalName());

	TextEncoding::global(new Latin9Encoding);
	TextEncoding& glob4 = TextEncoding::global();
	assert (std::string("ISO-8859-15") == glob4.canonicalName());

	TextEncoding::global(new Windows1250Encoding);
	TextEncoding& glob5 = TextEncoding::global();
	assert (std::string("Windows-1250") == glob5.canonicalName());

	TextEncoding::global(new Windows1251Encoding);
	TextEncoding& glob6 = TextEncoding::global();
	assert (std::string("Windows-1251") == glob6.canonicalName());

	TextEncoding::global(new Windows1252Encoding);
	TextEncoding& glob7 = TextEncoding::global();
	assert (std::string("Windows-1252") == glob7.canonicalName());

	TextEncoding::global(new UTF8Encoding);
	TextEncoding& glob8 = TextEncoding::global();
	assert (std::string("UTF-8") == glob8.canonicalName());
}


void TextEncodingTest::setUp()
{
}


void TextEncodingTest::tearDown()
{
}


CppUnit::Test* TextEncodingTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("TextEncodingTest");

	CppUnit_addTest(pSuite, TextEncodingTest, testTextEncoding);

	return pSuite;
}