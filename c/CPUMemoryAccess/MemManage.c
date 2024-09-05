#include <stddef.h> /*size_t*/
#include <stdint.h> /*uintptr_t*/
#include "MemManage.h"

void* MemSet(void* dest, int c, size_t n)
{
	unsigned char* byte_runner = (unsigned char*)dest;
	unsigned long* word_runner = (unsigned long*)dest;
	size_t size_word = sizeof(unsigned long);
	size_t i = 0;
	unsigned long word_data = 0;
	unsigned char byte_data = (unsigned char)c;

	for(i = 0; i < size_word; ++i)
	{
		word_data |= (unsigned long)byte_data << (i * 8);
	}

    while(n > 0 && ((uintptr_t)byte_runner % size_word) != 0)
	{
		*byte_runner = byte_data;
		++byte_runner;
		--n;
	}

	word_runner = (unsigned long*)byte_runner;

	while(n >= size_word)
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

	return dest;
}

void* MemCpy(void* dest_str, const void* src_str, size_t n)
{
	unsigned char* byte_runner_dest = (unsigned char*)dest_str;
	unsigned long* word_runner_dest = (unsigned long*)dest_str;
	const unsigned char* byte_runner_src = (const unsigned char*)src_str;
	const unsigned long* word_runner_src = (const unsigned long*)src_str;
	
	size_t size_word = sizeof(unsigned long);

    while(n > 0 && ((uintptr_t)byte_runner_dest % size_word != 0 || (uintptr_t)byte_runner_src % size_word != 0))
	{
		*byte_runner_dest = *byte_runner_src;
		++byte_runner_dest;
		++byte_runner_src;
		--n;
	}

	word_runner_dest = (unsigned long*)byte_runner_dest;
	word_runner_src = (const unsigned long*)byte_runner_src;

	while(n >= size_word)
	{
		*word_runner_dest = *word_runner_src;
		++word_runner_dest;
		++word_runner_src;
		n -= size_word;
	}
	
	

	
	byte_runner_dest = (unsigned char*)word_runner_dest;
	byte_runner_src = (unsigned char*)word_runner_src;

	while(n > 0)
	{
		*byte_runner_dest = *byte_runner_src;
		++byte_runner_src;
		++byte_runner_dest;
		--n;
	}

	return dest_str;
}

void *MemMove(void *dest_str, const void *src_str, size_t num_bytes)
{
	unsigned char* byte_runner_dest = (unsigned char*)dest_str;
	unsigned long* word_runner_dest = (unsigned long*)dest_str;
	const unsigned char* byte_runner_src = (const unsigned char*)src_str;
	const unsigned long* word_runner_src = (const unsigned long*)src_str;

	size_t size_word = sizeof(unsigned long);

	if(IsOverlap(dest_str,src_str) > 0)
	{
		while(num_bytes > 0 && ((uintptr_t)byte_runner_dest % size_word != 0 || (uintptr_t)byte_runner_src % size_word != 0))
		{
			*byte_runner_dest = *byte_runner_src;
			++byte_runner_dest;
			++byte_runner_src;
			--num_bytes;
		}

		if(num_bytes >= size_word)
		{
			word_runner_dest = (unsigned long*)byte_runner_dest;
			word_runner_src = (const unsigned long*)byte_runner_src;

			while(num_bytes >= size_word)
			{
				*word_runner_dest = *word_runner_src;
				++word_runner_dest;
				++word_runner_src;
				num_bytes -= size_word;
			}
		
		}

		
		byte_runner_dest = (unsigned char*)word_runner_dest;
		byte_runner_src = (unsigned char*)word_runner_src;

		while(num_bytes > 0)
		{
			*byte_runner_dest = *byte_runner_src;
			++byte_runner_src;
			++byte_runner_dest;
			--num_bytes;
		}
	}
	else if(IsOverlap(dest_str,src_str) < 0)
	{
		byte_runner_dest = byte_runner_dest + num_bytes - 1;
		byte_runner_src = byte_runner_src + num_bytes - 1;

		while(num_bytes > 0 && ((uintptr_t)byte_runner_dest % size_word != 0 || (uintptr_t)byte_runner_src % size_word != 0))
		{
			*byte_runner_dest = *byte_runner_src;
			--byte_runner_dest;
			--byte_runner_src;
			--num_bytes;
		}

		
		word_runner_dest = (unsigned long*)byte_runner_dest;
		word_runner_src = (const unsigned long*)byte_runner_src;

		while(num_bytes >= size_word)
		{
			*word_runner_dest = *word_runner_src;
			--word_runner_dest;
			--word_runner_src;
			num_bytes -= size_word;
		}

		
		byte_runner_dest = (unsigned char*)word_runner_dest;
		byte_runner_src = (const unsigned char*)word_runner_src;

		while(num_bytes > 0)
		{
			*byte_runner_dest = *byte_runner_src;
			--byte_runner_src;
			--byte_runner_dest;
			--num_bytes;
		}

	}

	return dest_str;
}

int IsOverlap(const void* dst,const void* src)
{
	return (const char*)src - (const char*)dst;
}