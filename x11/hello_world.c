#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main() {
    Display* display = XOpenDisplay(NULL);
    int screen = DefaultScreen(display);

    Window window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 200, 200, 1, BlackPixel(display, screen), WhitePixel(display, screen));
    XSelectInput(display, window, ExposureMask | KeyPressMask);
    XMapWindow(display, window);

    GC gc = XCreateGC(display, window, 0, 0);
    XSetForeground(display, gc, BlackPixel(display, screen));

    XEvent event;
    while (1) {
        XNextEvent(display, &event);
        if (event.type == Expose) {
            XDrawString(display, window, gc, 50, 50, "Hvala Vitalisu", 14);
        }
        if (event.type == KeyPress)
            break;
    }

    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);
    return 0;
}

