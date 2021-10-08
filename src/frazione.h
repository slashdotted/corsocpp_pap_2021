#ifndef FRAZIONE_H
#define FRAZIONE_H

struct Frazione {
        friend void duplica(const Frazione& f, Frazione& g);
        friend class Serializer;
        //friend void MySerializer::apply(const Frazione&);
    public:
        Frazione();
        Frazione(int n, int d = 1);
        const int& numeratore() const;
        const int& denominatore() const;
        void numeratore(int num);
        void denominatore(int den);

        static unsigned int istanze() {
            return m_istanze;
        }

    protected:

    private:
        int m_num{0}, m_den{1};
        static unsigned int m_istanze; // dichiarazione
};

#endif