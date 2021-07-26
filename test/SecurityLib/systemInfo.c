#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <httpext.h>   
#include <windef.h>   
#include <Nb30.h>

void getHardDiskNumber(char * hardDiskNum)
{
	char * cmd = "wmic path win32_physicalmedia get SerialNumber";
	char buffer[128] = { 0 };
	FILE *pipe = _popen(cmd, "r");
	if (!pipe)
	{
		printf("_popen() failed!");
		return;
	}
	while (!feof(pipe))
	{
		if (fgets(buffer, 128, pipe) != NULL)
			for (unsigned i = 0; i < 128; i++)
			{
				if (buffer[i] == '\r')
				{
					break;
				}
				//printf("%c", buffer[i]);
				memcpy(hardDiskNum + i, buffer + i, 1);
			}
		//result += 128;
	}
	_pclose(pipe);

	//printf(hardDiskNum);
}

int getMAC(char * mac)
{
	NCB ncb;
	typedef struct _ASTAT_
	{
		ADAPTER_STATUS   adapt;
		NAME_BUFFER   NameBuff[30];
	}ASTAT, *PASTAT;

	ASTAT Adapter;
	typedef struct _LANA_ENUM
	{
		UCHAR length;
		UCHAR lana[MAX_LANA];
	}LANA_ENUM;
	LANA_ENUM lana_enum;
	UCHAR uRetCode;
	memset(&ncb, 0, sizeof(ncb));
	memset(&lana_enum, 0, sizeof(lana_enum));

	ncb.ncb_command = NCBENUM;
	ncb.ncb_buffer = (unsigned char *)&lana_enum;
	ncb.ncb_length = sizeof(LANA_ENUM);
	uRetCode = Netbios(&ncb);
	if (uRetCode != NRC_GOODRET)
		return uRetCode;

	int index = 0;
	for (int lana = 0; lana < lana_enum.length; lana++)
	{
		index = lana;
		ncb.ncb_command = NCBRESET;
		ncb.ncb_lana_num = lana_enum.lana[lana];
		uRetCode = Netbios(&ncb);
		if (uRetCode == NRC_GOODRET)
			break;
	}
	if (uRetCode != NRC_GOODRET)
		return uRetCode;

	memset(&ncb, 0, sizeof(ncb));
	memset(&Adapter, 0, sizeof(Adapter));
	ncb.ncb_command = NCBASTAT;
	ncb.ncb_lana_num = lana_enum.lana[index];
	strcpy_s((char*)ncb.ncb_callname, 5, "*");
	ncb.ncb_buffer = (unsigned char *)&Adapter;
	ncb.ncb_length = sizeof(Adapter);
	uRetCode = Netbios(&ncb);
	if (uRetCode != NRC_GOODRET)
		return uRetCode;
	sprintf_s(mac, 18, "%02X%02X%02X%02X%02X%02X",
		Adapter.adapt.adapter_address[0],
		Adapter.adapt.adapter_address[1],
		Adapter.adapt.adapter_address[2],
		Adapter.adapt.adapter_address[3],
		Adapter.adapt.adapter_address[4],
		Adapter.adapt.adapter_address[5]
	);
	return 0;
}
