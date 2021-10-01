#ifndef FRAZIONE_H
#define FRAZIONE_H

struct Frazione {
    public:
        Frazione();
        Frazione(int n, int d = 1);
        const int& numeratore() const;
        const int& denominatore() const;
        void numeratore(int num);
        void denominatore(int den);

    protected:

    private:
        int m_num{0}, m_den{1};
};

#endif