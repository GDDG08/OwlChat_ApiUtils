#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <QObject>

class DataStorage : public QObject
{
    Q_OBJECT
public:
    explicit DataStorage(QObject *parent = 0);

signals:

public slots:
};

#endif // DATA_STORAGE_H