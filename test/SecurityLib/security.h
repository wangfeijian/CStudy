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

DLLAPI char GetBit(int index);

DLLAPI void SetBit(int index, char value);

DLLAPI int GetInt(int index);

DLLAPI void SetInt(int index, int value);

DLLAPI double GetDouble(int index);

DLLAPI void SetDouble(int index, double value);

DLLAPI char * GetString(int index, char * value);

DLLAPI void SetString(int index, char * str);

void checkSecurity();

void readRegValue(char * subKey, char * name, char * data);

void setRegValue(char *subKey, char * valueName, char * data);

void setUser(int num);

void getHardAndMac(unsigned char * registerStr);

void getMd5(char * decrypt, unsigned char * registerStr);
#endif