#ifndef SYSTEMINFO
#define SYSTEMINFO

#ifdef DLLAPI
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

void getHardDiskNumber(char * hardDiskNum);

int getMAC(char *mac);
#endif
