/*****************************************************   
 * Author : Avia Avikasis                            *
 * Reviewer: Ester                                   *
 * 15/06/2022                                        *
 * Description : imlementation of doubly             *
 * linkedlist                                        *
 *                                                   *
 *****************************************************/

#ifndef __ILRD_OL_127_128_CIRC_BUFF_H__
#define __ILRD_OL_127_128_CIRC_BUFF_H__

#include <stddef.h>  /* size_t */
#include <unistd.h>  /* ssize */

typedef struct circular_buff cbuff_ty;

/*
Description : the CBuffCreate() function create new circular buffer.
Param : capacity of the new buffer
return value : pointer to the new buffer
time cpmlexity : O(1)
space complexity : capacity + sizeof(cbuffer)
*/
cbuff_ty *CBuffCreate(size_t capacity);

/*
Description : the CBuffDestroy() function destroy exist circular buffer.
Param : cbuffer
return value : void
time cpmlexity : O(1)
space complexity : 0
*/
void CBuffDestroy(cbuff_ty *cbuff);

/*
Description : the CBuffWrite() function write data from some source to cbuffer.
Param : cbuffer , sorce , count = num of bytes to write
return value : the num of bytes that copy in fact
time cpmlexity : O(n)
space complexity : 0
*/
ssize_t CBuffWrite(cbuff_ty *cbuff, const char *src, size_t count);

/*
Description : the CBuffRead() function read data from buffr and write it to some dest.
Param : cbuffer , dest , count = num of bytes to read
return value : the num of bytes that copy in fact
time cpmlexity : O(n)
space complexity : 0
*/
ssize_t CBuffRead(cbuff_ty *cbuff, char *dest, size_t count);

/*
Description : the CBuffCapacity() function return the capacity of circular buffer.
Param : cbuffer
return value : capacity of cbuff
time cpmlexity : O(1)
space complexity : 0
*/
size_t CBuffCapacity(const cbuff_ty *cbuff);

/*
Description : the CBuffFreeSpace() function return the free space of circular buffer.
Param : cbuffer
return value : free space in cbuff , in bytes
time cpmlexity : O(1)
space complexity : 0
*/
size_t CBuffFreeSpace(const cbuff_ty *cbuff);

/*
Description : the CBuffIsEmpty() function check if circular buffer is empty.
Param : cbuffer
return value : 1 if is empty , otherwise 0
time cpmlexity : O(1)
space complexity : 0
*/
int CBuffIsEmpty(const cbuff_ty *cbuff);


#endif /* __ILRD_OL_127_128_CIRC_BUFF_H__ */
