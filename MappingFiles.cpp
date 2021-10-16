#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

int main(int argc , char *argv[]){
	HANDLE hfile , hMapFile ;
	LPVOID lpMapAddress;

	hfile = CreateFile("TestMap.txt", /* file name */
						GENERIC_READ | GENERIC_WRITE , /* read/write access */
						0 , /* no sharing of the file */
						NULL , /* default security */
						OPEN_ALWAYS ,/* open new or existing file */
						FILE_ATTRIBUTE_NORMAL , /* routine file attributes */
						NULL ) ; /* file template */
	hMapFile = CreateFileMapping(hfile ,/* file handle*/
								 NULL , /* default security*/
								 PAGE_READWRITE , /* read/write access to mapped pages*/
								 0 , /* map entire file*/
								 0 ,
								 TEXT("SharedObject") ); /* named shared memory object*/
	lpMapAddress =  MapViewOfFile(hMapFile , /* mapped object hndle */
								FILE_MAP_ALL_ACCESS , /* read / write access*/
								0 , /* mapped view of entire file */
								0 ,
								0);
	   /* Write to shared memory */
	   //sprintf(lpMapAddress , "Shared memory message");
	   printf("Read message %s ", lpMapAddress );
	   UnmapViewOfFile(lpMapAddress);
	   CloseHandle(hfile);
	   CloseHandle(hMapFile);
									


}
