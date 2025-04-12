#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void DrawRuler(HDC hdc, RECT rect);

// wykorzystanie natywnego win api
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const wchar_t CLASS_NAME[] = L"TransparentRuler";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); // brak tła

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        WS_EX_LAYERED | WS_EX_TOPMOST | WS_EX_TOOLWINDOW,
        CLASS_NAME, L"Ruler",
        WS_POPUP,
        100, 100, 800, 60,
        nullptr, nullptr, hInstance, nullptr
    );

    // Ustawienie przezroczystości z alfą
    SetLayeredWindowAttributes(hwnd, 0, 255, LWA_ALPHA);

    ShowWindow(hwnd, nCmdShow);

    // Pętla komunikatów
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

// Zmienna globalna do przeciągania okna
POINT ptDragStart;
bool dragging = false;

// Procedura okna
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_LBUTTONDOWN:
            dragging = true;
            SetCapture(hwnd);
            GetCursorPos(&ptDragStart);
            return 0;

        case WM_MOUSEMOVE:
            if (dragging) {
                POINT pt;
                GetCursorPos(&pt);
                int dx = pt.x - ptDragStart.x;
                int dy = pt.y - ptDragStart.y;

                RECT rect;
                GetWindowRect(hwnd, &rect);
                MoveWindow(hwnd, rect.left + dx, rect.top + dy, rect.right - rect.left, rect.bottom - rect.top, TRUE);

                ptDragStart = pt;
            }
            return 0;

        case WM_LBUTTONUP:
            dragging = false;
            ReleaseCapture();
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            RECT rect;
            GetClientRect(hwnd, &rect);

            // rysowanie linijki
            DrawRuler(hdc, rect);

            EndPaint(hwnd, &ps);
            return 0;
        }

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

// Rysowanie linijki z podziałką
void DrawRuler(HDC hdc, RECT rect) {
    HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, pen);

    int unit = 10; // co 10 pikseli (można zamienić na dpi-calce)
    for (int i = 0; i < rect.right; i += unit) {
        int height = (i % 50 == 0) ? 20 : (i % 10 == 0) ? 10 : 5;
        MoveToEx(hdc, i, 0, NULL);
        LineTo(hdc, i, height);
    }

    DeleteObject(pen);
}
