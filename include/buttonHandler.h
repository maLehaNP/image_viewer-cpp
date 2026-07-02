#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H
 
#include <QObject>

enum MyEnum {
  FOLDER_BTN
};
 
class ButtonHandler: public QObject {
  Q_OBJECT

public:
  ButtonHandler(QObject *parent = nullptr) : QObject{parent} {}

public slots:
  Q_INVOKABLE void handleClick(int);
};
 
#endif // BUTTON_HANDLER_H

