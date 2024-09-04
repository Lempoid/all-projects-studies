#include "MemManage.h"
#include <stddef.h>
#include <errno.h>

void* MemSet(void *dest, int c, size_t n)
{
	/*
		get size of word
		define pointer for bytesize allocation

		put data in word size memory for word size data put

		isMemory alligned
			yes
				put in words size
			no
				put how much can, and then in words size

		put remaining bytes.
	*/

	unsigned char* byte_runner = (unsigned char*)dest;
	unsigned long* word_runner = (unsigned long*)dest;
	size_t size_word = sizeof(size_t);
	size_t i = 0;
	unsigned long word_data = 0;
	unsigned char byte_data = (unsigned char)c;

	for(i = 0; i < size_word; ++i)
	{
		word_data |= (unsigned long)byte_data << (i * 8);
	}

	while(((unsigned long)byte_runner % size_word != 0) && (n > 0))
	{
		*byte_runner = byte_data;
		++byte_runner;
		--n;
	}

	word_runner = (unsigned long*)byte_runner;

	while(size_word < n)
	{
		*word_runner = word_data;
		++word_runner;
		n -= size_word;
	}

	byte_runner = (unsigned char*)word_runner;

	while(0 < n)
	{
		*byte_runner = byte_data;
		++byte_runner;
		--n;
	}
}