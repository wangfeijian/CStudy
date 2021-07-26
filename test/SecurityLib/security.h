#ifndef SECURITY
#define SECURITY

#ifdef DLLAPI
#define DLLAPI __declspec(dllexport)
#else
#define DLLAPI __declspec(dllimport)
#endif

DLLAPI int GetCurUser();

DLLAPI int ChangeUser(int nNewUser, char * szPassword);

DLLAPI int ChangePassword(int nUser, char * szPassword, char * szNewPassword);

void checkSecurity();

void readRegValue(char * subKey, char * name, char * data);

void setRegValue(char *subKey, char * valueName, char * data);

void setUser(int num);

void getHardAndMac(unsigned char * registerStr);

void getMd5(char * decrypt, unsigned char * registerStr);
#endif