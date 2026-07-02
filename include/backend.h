#ifndef BACKEND_H
#define BACKEND_H
 
#include <string>
#include <QObject>
#include <QDir>

enum MyEnum {
  FOLDER_BTN = 0,
  FIRST_BTN = 1,
  PREV_BTN = 2,
  NEXT_BTN = 4,
  LAST_BTN = 5
};
 
class Backend: public QObject {
  Q_OBJECT
  //Q_PROPERTY(url file READ getValue WRITE setValue
  //                 NOTIFY valueChanged)

public:
  Backend(QObject *parent = nullptr);

public slots:
  Q_INVOKABLE void handleClick(int);

private:
  QDir dir;
  QStringList imList;
  int listIdx = 0;
  int listLen = 0;
  //QObject* image;
  
  void setDir(QString path);
  void changeImage();
  void checkButtonsState();
};
 
#endif // BACKEND_H

