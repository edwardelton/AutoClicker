#include <Windows.h>
#include <stdio.h>

typedef char bool;
#define true 1
#define false 0

int main(void) {
	printf("AutoClicker has started\n");
	bool isOn = false;
	
	while (true) {
		if (isOn) {
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		}

		if (GetAsyncKeyState(VK_INSERT) & 1) {
			if (isOn) {
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				isOn = false;
				printf("Toggle off.\n");
			} else {
				isOn = true;
				printf("Toggle on.\n");
			}
		}
		Sleep(1); // Edit to make it more legit
	}
	return 0;
}