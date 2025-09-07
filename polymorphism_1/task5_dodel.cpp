#include <cstddef>
#include <string>

class Stream {
    protected:
    std::string data;
    std::size_t pos;
    public:
    void writeChar(char c) {
        
        if (!isEnd()) data.at(pos++) = c;
        else {
            data.push_back(c);
            pos++;
        }
    }

    char readChar() {
        if (!isEnd()) return data.at(pos++);
    }

    void setPos(size_t pos) {
        if (pos <= data.length()) this->pos = pos;
    }

    bool isEnd() {
        return pos == data.length();
    }
};

class Stream1 : public Stream {
    char to_add;
    Stream1() {
        to_add = '\0';
    }

    void put_back(char c) {
        to_add = c;
    }

    char readChar() {
        if (to_add != '\0') {
            char c = to_add;
            to_add = '\0';
            return c;
        } else {
            return Stream::readChar();
        }
    }

    void setPos(size_t pos) {
        if (pos <= data.length()) {
            to_add= '\0';
            this->pos = pos;
        }
    }

};

class StreamWithInts : public Stream1 {
    void writeInt(int n) {
        std::string nStr = std::to_string(n);
        for (char c : nStr) {
            writeChar(c);
        }
    }

    int readInt() {
        
    }
}