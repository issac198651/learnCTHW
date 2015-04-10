#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/SOCK_Connector.h"

int ACE_MAIN(int, ACE_TCHAR*[])
{
	int ret = 0;
	const char *ip = "127.0.0.1";
	short port = 60000;
	ACE_INET_Addr srvr(port, ip);
	ACE_SOCK_Connector connector;
	ACE_SOCK_Stream peer;

	//ACE_Time_Value time(0, 500);
	//ret = connector.connect(peer, srvr, &time);
	ret = connector.connect(peer, srvr);
	if(ret == -1)
	{
		ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("%p\n"), ACE_TEXT("connect")), -1);
	}
	peer.send_n("hello world!", 12);
	peer.close();
	return(0);
}