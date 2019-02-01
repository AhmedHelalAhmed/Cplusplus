#ifndef MARK_H
#define MARK_H


class Mark
{
    public:
        Mark(int arabic, int math, int english);
        Mark();
        int getMath();
        int getArabic();
        int getEnglish();
        bool isPass();


    private:
        int arabic,math,english;

};

#endif // MARK_H
