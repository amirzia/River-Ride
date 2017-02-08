#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
private:
    int score;
public:
    Score();
    void addScore(int sc);
};

#endif // SCORE_H
