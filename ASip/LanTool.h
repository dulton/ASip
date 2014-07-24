#ifndef LANTOOL
#define LANTOOL


#ifndef EXPORTING_DLL
#define EXPORTING_DLL
#endif 


struct TOOLDATA{
	char call[8192];      /* member contains call details including individual parameters */
	char summary[4096];   /* summary of jitter etc. for numbers of calls */
	char error[1024];     /* contains error message */ 

} ;

extern "C" __declspec(dllexport) void *WINAPI startSIPSessionint (char *argv[]);
extern "C" __declspec(dllexport) void WINAPI StopSIPSIPSession();
extern "C" __declspec(dllexport) void WINAPI hangup(int n);
extern "C" __declspec(dllexport) unsigned long WINAPI  toolmain(LPVOID lrtpinet);
extern "C" __declspec(dllexport) int WINAPI checkConnectivity(char *fqdn, int port);
extern "C" __declspec(dllexport) int WINAPI startAudioCapture(char *fqdn, int port); /* to be implemented */
extern "C" __declspec(dllexport) struct TOOLDATA *WINAPI getStat();

struct TOOLDATA * (*callback) ();
/* Please note return from the function "void *WINAPI startSIPSessionint (char *argv[])" 
should be casted type struct TOOLDATA (*callback) () which is basically getStat. 
This struction contains members as explained above. GetStat can be directly used.

*/

#endif