#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <string.h> /* strcmp */
#include "cbuff.h" 


void CBuffCreateAndDestroyTest();
void CBuffWriteTest();
void CBuffReadTest();
void CBuffCapacityTest();
void CBuffFreeSpaceTest();
void CBuffIsEmptyTest();


int main(void)
{
	CBuffCreateAndDestroyTest();
	CBuffWriteTest();
	CBuffReadTest();
	CBuffCapacityTest();
	CBuffFreeSpaceTest();
	CBuffIsEmptyTest();

	printf("\n->->->->->-> success!! <-<-<-<-<-<-\n\n");
	
	return 0;
}


void CBuffCreateAndDestroyTest()
{
	cbuff_ty *cbuff1 = CBuffCreate(10);
	cbuff_ty *cbuff2 = CBuffCreate(0);
	CBuffDestroy(cbuff1);
	CBuffDestroy(cbuff2);	
}


void CBuffWriteTest()
{
	cbuff_ty *cbuff1 = CBuffCreate(10);
	cbuff_ty *cbuff2 = CBuffCreate(200);
	char src[70] = "This answer is technically irrelevant, as it does something different"; 
	assert(CBuffWrite(cbuff1 , src , 15) == 10);
	assert(CBuffWrite(cbuff2 , src , 20) == 20);
	assert(CBuffFreeSpace(cbuff1) == 0);
	assert(CBuffFreeSpace(cbuff2) == 180);
	CBuffDestroy(cbuff1);
	CBuffDestroy(cbuff2);		

}

void CBuffReadTest()
{
	cbuff_ty *cbuff = CBuffCreate(10);
	char src[70] = "This answer is technically irrelevant, as it does something different"; 
	char dest[50];
	int i = 0;
	for (i = 0 ; i < 50 ; ++i)
	{
		dest[i] = 0;
	}
	CBuffWrite(cbuff , src , 10);
	CBuffRead(cbuff , dest , 10);
	assert(strcmp(dest ,"This answe") == 0);
	CBuffWrite(cbuff , src , 5);
	for (i = 0 ; i < 50 ; ++i)
	{
		dest[i] = 0;
	}
	CBuffRead(cbuff , dest , 2);
	assert(strcmp(dest , "Th") == 0);
	CBuffWrite(cbuff , src , 7);
	for (i = 0 ; i < 50 ; ++i)
	{
		dest[i] = 0;
	}
	CBuffRead(cbuff , dest , 7);
	assert(strcmp(dest , "is This") == 0);
	CBuffDestroy(cbuff);			
}


void CBuffCapacityTest()
{
	cbuff_ty *cbuff1 = CBuffCreate(10);
	cbuff_ty *cbuff2 = CBuffCreate(0);
	assert(CBuffCapacity(cbuff1) == 10);
	assert(CBuffCapacity(cbuff2) == 0);
	CBuffDestroy(cbuff1);
	CBuffDestroy(cbuff2);		
}

void CBuffFreeSpaceTest()
{
	cbuff_ty *cbuff = CBuffCreate(10);
	char src[70] = "This answer is technically irrelevant, as it does something different"; 
	char dest[50];
	int i = 0;
	for (i = 0 ; i < 50 ; ++i)
	{
		dest[i] = 0;
	}
	assert(CBuffFreeSpace(cbuff) == 10);
	CBuffWrite(cbuff , src , 20);
	assert(CBuffFreeSpace(cbuff) == 0);
	CBuffRead(cbuff , dest , 5);
	assert(CBuffFreeSpace(cbuff) == 5);
	CBuffDestroy(cbuff);
}


void CBuffIsEmptyTest()
{
	cbuff_ty *cbuff = CBuffCreate(10);
	char src[70] = "This answer is technically irrelevant, as it does something different"; 
	char dest[50];
	int i = 0;
	for (i = 0 ; i < 50 ; ++i)
	{
		dest[i] = 0;
	}
	assert(CBuffIsEmpty(cbuff) == 1);
	CBuffWrite(cbuff , src , 20);
	assert(CBuffIsEmpty(cbuff) == 0);
	CBuffRead(cbuff , dest , 10);
	assert(CBuffIsEmpty(cbuff) == 1);
	CBuffDestroy(cbuff);	
}


























