#include <backend.h>
#include <iostream>
#include <QInputDialog>

extern QObject* window;

Backend::Backend(QObject *parent) : QObject{parent} {
  QStringList filters;
  filters << "*.jpg";
  dir.setNameFilters(filters);
  //setDir(QDir::currentPath());
}

void Backend::handleClick(int sender) {
  //std::cout << sender << '\n';
  switch (sender) {
    case FOLDER_BTN:
    {
      bool ok{};
      QString path = QInputDialog::getText(nullptr,
        tr("Выбор папки"), tr("Адрес папки:"),
        QLineEdit::Normal, QDir::currentPath(), &ok
      );
      std::cout << ok << ' ' << path.toStdString() << '\n';

      if (ok && !path.isEmpty()) {
        setDir(path);
      }
      break;
    }
    case FIRST_BTN:
    {
      listIdx = 0;
      changeImage();
      break;
    }
    case NEXT_BTN:
    {
      listIdx++;
      changeImage();
      break;
    }
    case PREV_BTN:
    {
      listIdx--;
      changeImage();
      break;
    }
    case LAST_BTN:
    {
      listIdx = listLen - 1;
      changeImage();
      break;
    }
    default:
      break;
  }
}

void Backend::setDir(QString path) {
  dir.setPath(path);
  window->setProperty("path", path);
  imList = dir.entryList();
  listLen = imList.size();
  printf("listLen=%d\n", listLen);

  //image->setProperty("source", QUrl::fromLocalFile(dir.path() + '/' + imList[0]));
  listIdx = 0;
  if (listLen != 0)
    changeImage();
}

void Backend::changeImage() {
  window->setProperty("imageName", imList[listIdx]);
  window->setProperty("imageUrl", QUrl::fromLocalFile(dir.path() + '/' + imList[listIdx]));
  checkButtonsState();
}

void Backend::checkButtonsState() {
  if (listIdx == 0)
    window->setProperty("isFirst", true);
  else
    window->setProperty("isFirst", false);
  if (listIdx == listLen - 1)
    window->setProperty("isLast", true);
  else {
    window->setProperty("isLast", false);
  }
}

