/*****************************************************   
 * Author : Avia Avikasis                            *
 * Reviewer: Ester                                   *
 * 15/06/2022                                        *
 * Description : imlementation of doubly             *
 * linkedlist                                        *
 *                                                   *
 *****************************************************/

#include <stdlib.h> /* malloc */ 
#include <stdio.h>  /* printf */
#include <string.h> /* memcpy */
#include "cbuff.h"

/* calculte the offset of specific member in struct */
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))

struct circular_buff
{
	int head;
	int rear;
	size_t capacity;
	size_t size;
	char buffer[1]; /* flexibility array */
};


static void ReadFromBuffer(int index , size_t capacity ,const char *src , char *dest, size_t count);
static void WriteToBuffer(int index , size_t capacity ,const char *src , char *dest, size_t count);


cbuff_ty *CBuffCreate(size_t capacity)
{
	cbuff_ty *cbuff = malloc(sizeof(cbuff_ty) + capacity * sizeof(char));
	size_t i = 0; 
	cbuff -> head = 0;
	cbuff -> rear = 0;
	cbuff -> capacity = capacity;
	cbuff -> size = 0;
	for(i = 0 ; i < capacity ; ++i)
	{
		(cbuff -> buffer)[i] = 0;
	}
	return cbuff;
}


void CBuffDestroy(cbuff_ty *cbuff)
{
	free(cbuff);
	cbuff = NULL;	
}


ssize_t CBuffWrite(cbuff_ty *buff, const char *src, size_t count)
{

	count = (count >= CBuffFreeSpace(buff)) ? CBuffFreeSpace(buff) : count;

	if ((buff->rear >= buff->head) && (count > (buff->capacity - buff->rear)))
	{
		WriteToBuffer(buff->rear , buff->capacity ,src , buff->buffer , count);
		buff -> rear += count;
		buff -> rear %= buff -> capacity;
		buff -> size += count;
		return count;
	}
	
	else 
	{
		memcpy(buff -> buffer + buff -> rear , src , count);
		buff -> rear += count;
		buff -> rear %= buff -> capacity;
		buff -> size += count;
		return count;
	}
	
}


ssize_t CBuffRead(cbuff_ty *buff, char *dest, size_t count)
{
	
	count = (count >= buff->size) ? buff->size : count;
	
	if ( (buff->head >= buff->rear)  &&  (count > (buff->capacity - buff->head)))
	{
		ReadFromBuffer(buff->head , buff->capacity , buff->buffer , dest , count);
		buff -> head += count;
		buff -> head %= buff -> capacity;
		buff -> size -= count;
		return count;
	}
	
	else
	{
		memcpy(dest , buff -> buffer + buff -> head, count);
		buff -> head = count;
		buff -> head %= buff -> capacity;
		buff -> size -= count;
		return count;
	}	
	
}


size_t CBuffCapacity(const cbuff_ty *cbuff)
{
	return cbuff -> capacity;
}

size_t CBuffFreeSpace(const cbuff_ty *cbuff)
{
	return cbuff -> capacity - cbuff -> size;	
}


int CBuffIsEmpty(const cbuff_ty *cbuff)
{
	return (0 == cbuff -> size);
}


static void ReadFromBuffer(int index , size_t capacity ,const char *src , char *dest, size_t count)
{
	size_t first_segment = capacity - index;
	size_t second_segment = count - first_segment;
	memcpy(dest , src + index , first_segment);
	memcpy(dest + first_segment , src , second_segment);
}

static void WriteToBuffer(int index , size_t capacity ,const char *src , char *dest, size_t count)
{
	size_t first_segment = capacity - index;
	size_t second_segment = count - first_segment;
	memcpy(dest + index , src , first_segment);
	memcpy(dest , src + first_segment , second_segment);
}







