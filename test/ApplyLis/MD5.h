#ifndef MD5_H
#define MD5_H
#include "HashMethod.h"
#include <string>
//#include <rpcndr.h>
#define _HAS_STD_BYTE 0
using namespace std;
/* MD5 declaration. */
class MD5 : public CHashMethod
{
public:
	MD5();
	MD5(const void* input, size_t length);
	MD5(const std::string& str);
	MD5(std::ifstream& in);
	MD5(const char *file);
	void update(const void* input, size_t length);
	void update(const std::string& str);
	void update(std::ifstream& in);
	void update(const char *file);
	const byte* digest();
	std::string toString();
	void reset();
	std::string ToMD5(const std::string& str);    //如此，只需调用该函数便完成加密过程
	string ToMD5(const void* input, size_t length);
	string ToMD5(ifstream& in);

	int getHashLength();
	char *getHashMetod();

private:
	void update(const byte* input, size_t length);
	void final();
	void transform(const byte block[64]);
	void encode(const uint32* input, byte* output, size_t length);
	void decode(const byte* input, uint32* output, size_t length);
	string bytesToHexString(const byte* input, size_t length);

	/* class uncopyable */
	MD5(const MD5&);
	MD5& operator=(const MD5&);

private:
	uint32 _state[4];   /* state (ABCD) */
	uint32 _count[2];   /* number of bits, modulo 2^64 (low-order word first) */
	byte _buffer[64];   /* input buffer */
	byte _digest[16];   /* message digest */
	bool _finished;     /* calculate finished ? */

	static const byte PADDING[64];  /* padding for calculate */
	static const char HEX[16];
	enum { BUFFER_SIZE = 1024 };
};

#endif /*MD5_H*/