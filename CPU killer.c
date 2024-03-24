#include <stdio.h>

void infinite() {
	while (1) {

	}
}

#if defined(__linux__)

int main() {
  return 0;
}
#endif


#if defined(__APPLE__)
int main() {
  return 0;
}
#endif


#ifdef _WIN32 
#include <windows.h>
int main() {
  SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);

  SYSTEM_INFO sys_info;
  GetSystemInfo(&sys_info);


  printf("processors count: %d\n", sys_info.dwNumberOfProcessors);


  for (size_t i = 0; i < sys_info.dwNumberOfProcessors - 1; i++) {
    CreateThread(NULL, 0, infinite, NULL, 0, NULL);
  }

  infinite(NULL);

  return 0;
}
#endif

