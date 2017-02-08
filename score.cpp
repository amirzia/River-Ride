#include "score.h"
#include <QFont>

Score::Score() {
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
    score = 0;
    addScore(0);
}

void Score::addScore(int sc) {
    score += sc;
    setPlainText(QString("Score: " + QString::number(score)));
}
