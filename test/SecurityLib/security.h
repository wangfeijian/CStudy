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

const void checkSecurity();

const char * readRegValue(char * subKey, char * name, char * data);

const void setRegValue(char *subKey, char * valueName, char * data);

const void setUser(int num);
#endif