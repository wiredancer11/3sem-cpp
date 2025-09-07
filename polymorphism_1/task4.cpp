class TerminalBuffer {
    protected:
    char buffer[25][80];
    int cursorX;
    int cursorY;
    public:
    TerminalBuffer() {
        clear();
    }
    void setCursor(int x, int y) {
        if ((x >= 0 && x <80) && (y >=0 && y < 25)) {
            cursorX = x;
            cursorY = y;
        }
    }

    void printChar(char c) {
        buffer[cursorY][cursorX] = c;
        next();
    }

    void clear() {
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                buffer[i][j] = '\0';
            }
        } 
        setCursor(0, 0);

    }

    void next() {
        if (cursorX != 79) setCursor(cursorX+1, cursorY);
        else setCursor(0, cursorY+1);
    }
};

class TerminalBufferColored : TerminalBuffer {
   int symbolsColor[25][80];
   int backgroundColor[25][80];

   int currentSymbolColor;
   int currentBackgroundColor;

   TerminalBufferColored() {
    currentSymbolColor = 0xffffff;
    currentBackgroundColor = 0;
   }

   void printChar(char c) {
    buffer[cursorY][cursorX] = c;
    symbolsColor[cursorY][cursorX] = currentSymbolColor;
    symbolsColor[cursorY][cursorX] = currentBackgroundColor;
    next();
   }

   void clear() {

        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 80; j++) {
                buffer[i][j] = '\0';
                symbolsColor[i][j] = currentSymbolColor;
                backgroundColor[i][j] = currentBackgroundColor;
            }
        } 
        setCursor(0, 0);
   }

   void setBackgroundColor(int color) {
    currentBackgroundColor = color;
   }

   void setSymbolColor(int color) {
    currentBackgroundColor = color;
   }
};