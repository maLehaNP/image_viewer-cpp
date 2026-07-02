#ifndef BUTTON_HANDLER_H
#define BUTTON_HANDLER_H
 
#include <QObject>
 
class ButtonHandler: public QObject
{
  Q_OBJECT
public:
  ButtonHandler(QObject *parent = nullptr){}
public slots:
  Q_INVOKABLE void handleClick();
};
 
#endif // BUTTON_HANDLER_H

