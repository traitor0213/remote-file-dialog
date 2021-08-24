#include <stdio.h>
#include <Windows.h>

int main(int argc, char **argv)
{
    HWND FileDialogHandle = FindWindowA("#32770", NULL);

    HWND ComboBoxEx32 = FindWindowExA(FileDialogHandle, 0, "ComboBoxEx32", NULL);
    if (ComboBoxEx32 == NULL)
    {
        FileDialogHandle = FindWindowW(NULL, L"열기");
        ComboBoxEx32 = FindWindowExA(FileDialogHandle, 0, "ComboBoxEx32", NULL);
    }

    if (ComboBoxEx32 == NULL)
    {
        return 0;
    }

    printf("file dialog handle = %x\n", FileDialogHandle);
    printf("combo box 32 handle = %x\n", ComboBoxEx32);

    HWND ComboBox = FindWindowExA(ComboBoxEx32, 0, "ComboBox", NULL);
    printf("%x\n", ComboBox);

    HWND Edit = FindWindowExA(ComboBox, 0, "Edit", NULL);
    printf("%x\n", Edit);

    HWND button = FindWindowExA(FileDialogHandle, 0, "Button", NULL);
    printf("%x\n", button);

    SendMessageA(Edit, WM_SETTEXT, NULL, (LPARAM)argv[1]);
    Sleep(100);
    SendMessageA(FileDialogHandle, WM_COMMAND, 1, (LPARAM)button);
    Sleep(100);
 
	return 0;
}

