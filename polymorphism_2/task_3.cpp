#include <vector>
#include <algorithm>
#include <iostream>

class Box {
    protected:
    int height;
    int width;

    int posX;
    int posY;
    public:
    void place(int x, int y) {
        posX = x;
        posY = y;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }

    virtual void layout() = 0;

    virtual Box* clone() = 0;

    virtual void print(int posX, int posY, char (&screen)[25][80]) = 0;

    virtual ~Box() {};
};

class CharBox : public Box {
    private:
    char c;
    public:
    CharBox(char c) : c(c) {
        height = 1;
        width = 1;
    }
    void layout() {
        width = 1;
        height = 1;
    }

    void print(int abs_x, int abs_y, char (&screen)[25][80]) {
        screen[abs_y + this->posY][abs_x + this->posX] = c;
    }

    Box* clone() {
        return new CharBox(c);
    }

};

class TableBox : public Box {
    std::vector<std::vector<Box*>> boxes;
    int rows;
    int cols;
    public:
    TableBox(int rows, int cols) : rows(rows), cols(cols) {
       std::vector<Box*> row = std::vector<Box*>(cols, nullptr); 
       boxes = std::vector<std::vector<Box*>>(rows, row);
    }
    void add(Box* box, int row, int col) {
        if (boxes[row][col] == nullptr) boxes[row][col] = box->clone();
    }
    void layout() {
        posX = posY = 0;
        int nextX = 0;
        int nextY = 0;
        int curY = 0;
        int maxWidth = 0;
        int maxHeight   = 0;
        int currentWidth = maxWidth;
        int currentHeight = maxHeight;
        for (auto row: boxes) {
            for (auto box: row) {
                if (box == nullptr) continue;
                box->layout();
                currentWidth += box->getWidth();
                currentHeight = std::max(currentHeight, box->getHeight());
                box->place(nextX, curY);
                nextX += box->getWidth();
                nextY = std::max(nextY, curY + box->getHeight());
            }
        nextX = 0;
        curY = nextY;
        maxWidth = std::max(maxWidth, currentWidth);
        currentWidth = 0;
        maxHeight += currentHeight;
        currentHeight = 0;
        }
        this->width = maxWidth;
        this->height = maxHeight;
    }

    void print(int abs_x, int abs_y, char (&screen)[25][80]) {
        for (auto row : boxes) {
            for (auto box: row) {
                if (box != nullptr)
                box->print(abs_x + posX, abs_y + posY, screen);
            }
        }
    }

    Box* clone() {
        TableBox* newTable = new TableBox(rows, cols);
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (boxes[row][col] == nullptr) continue;
                newTable->add(boxes[row][col]->clone(), row, col);
            }
        }
        return newTable;
    }

};

class FrameBox : public Box {
    Box* innerBox;
    public:
    FrameBox(Box* box) : innerBox(box) {}

    void layout() {
        innerBox->layout();
        innerBox->place(1, 1);
        this->width = innerBox->getWidth() + 2;
        this->height = innerBox -> getHeight() + 2;
    }

    void print(int abs_x, int abs_y, char (&screen)[25][80]) {
        int current_abs_x = abs_x + posX;
        int current_abs_y = abs_y + posY;
        innerBox->print(current_abs_x, current_abs_y, screen);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (y == 0 && x == 0 || y == 0 && x == width -1 || y == height - 1 && x == 0 || y == height - 1 && x == width - 1) {
                    screen[current_abs_y+y][current_abs_x+x] = '+';
                } else if (y == 0 || y == height - 1) {
                    screen[current_abs_y+y][current_abs_x+x] = '-';
                } else if (x == 0 || x == width -1) {
                    screen[current_abs_y+y][current_abs_x+x] = '|';
                }
            }
        }
    }

    Box* clone() {
        return new FrameBox(this->innerBox);
    }
};

void showScreen(char (&screen)[25][80]) {
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            if (screen[i][j] == '\0') std::cout << " "; 
            std::cout << screen[i][j];
        }
        std::cout << std::endl;
    }

}

int main() {
   std::vector<Box*> row1, row2;
   char screen[25][80] = {' '};
   TableBox* globalBox = new TableBox(2, 2);

   TableBox* innerBox1 = new TableBox(2, 2);
   innerBox1->add(new CharBox('a'), 0, 0);
   innerBox1->add(new CharBox('b'), 0, 1);
   innerBox1->add(new CharBox('c'), 1, 0);
   innerBox1->add(new CharBox('d'), 1, 1);
   FrameBox* frameBox = new FrameBox(innerBox1);
   TableBox* innerBox2 = new TableBox(1, 5);
   innerBox2->add(new CharBox('f'), 0, 0);
   innerBox2->add(new CharBox('g'), 0, 1);
   innerBox2->add(new CharBox('h'), 0, 2);
   innerBox2->add(new CharBox('i'), 0, 3);
   innerBox2->add(new CharBox('j'), 0, 4);

   TableBox* innerBox3 = new TableBox(1, 5);
   innerBox3->add(new CharBox('a'), 0, 0);
   innerBox3->add(new CharBox('b'), 0, 1);
   innerBox3->add(new CharBox('c'), 0, 2);
   innerBox3->add(new CharBox('d'), 0, 3);
   innerBox3->add(new CharBox('e'), 0, 4);
   TableBox* innerBox4 = new TableBox(2, 7);
   innerBox4->add(new CharBox('a'), 0, 0);
   innerBox4->add(new CharBox('b'), 0, 1);
   innerBox4->add(new CharBox('c'), 0, 2);
   innerBox4->add(new CharBox('d'), 0, 3);
   innerBox4->add(new CharBox('e'), 0, 4);
   innerBox4->add(new CharBox('f'), 1, 0);
   innerBox4->add(new CharBox('g'), 1, 1);
   innerBox4->add(new CharBox('h'), 1, 2);
   innerBox4->add(new CharBox('i'), 1, 3);
   innerBox4->add(new CharBox('j'), 1, 4);
   innerBox4->add(new CharBox('k'), 1, 5);
   innerBox4->add(new CharBox('l'), 1, 6);

    globalBox->add(frameBox, 0, 0);
    globalBox->add(innerBox2, 0, 1);
    globalBox->add(innerBox3, 1, 0);
    globalBox->add(innerBox4, 1, 1);

    globalBox->layout();
    globalBox->print(0, 0, screen);
    showScreen(screen);

}