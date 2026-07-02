#include <buttonHandler.h>
#include <iostream>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>


void ButtonHandler::handleClick() {
  //std::cout << "aboba" << '\n';

  //QMessageBox msgBox;     // диалоговое окно
  //msgBox.setText("Button Clicked!"); // устанавливаем текст
  //msgBox.exec();  // отображаем диалоговое окно

  bool ok{};
  QString text = QInputDialog::getText(nullptr,
    tr("Выбор папки"), tr("Адрес папки:"),
    QLineEdit::Normal, QDir::currentPath(), &ok);
  
  std::cout << ok << ' ' << text.toStdString() << '\n';
  //printf("%d %s\n", ok, text.toStdString());

  //if (ok && !text.isEmpty())
  //  textLabel->setText(text);
}

